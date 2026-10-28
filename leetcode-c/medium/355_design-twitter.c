/*
 * LeetCode 355. Design Twitter／設計推特
 *
 * 題目（繁體中文）
 *   設計簡化版 Twitter，支援發文、追蹤、取消追蹤，以及讀取動態消息。
 *   動態消息最多回傳 10 則，內容來自使用者自己和他追蹤的使用者，並依
 *   發文時間由新到舊排列。
 *
 * 範例：依序執行 postTweet(1,5)、getNewsFeed(1)、follow(1,2)、
 *   postTweet(2,6)、getNewsFeed(1)、unfollow(1,2)、getNewsFeed(1)，
 *   動態消息依序為 [5]、[6,5]、[5]。
 * 限制：使用者 ID 為 1..500；推文 ID 為 0..10^4 且不重複；
 *   發文、讀取、追蹤與取消追蹤合計最多呼叫 3×10^4 次；使用者不追蹤自己。
 *
 * 解題步驟：
 *   1. 每位使用者各自維護一條由新到舊的推文索引鏈結串列。
 *   2. 用布林矩陣記錄追蹤關係，追蹤與取消追蹤都只需 O(1)。
 *   3. 讀取動態消息時，將自己與所有追蹤對象最新的推文放入最大堆。
 *   4. 每次取出最新推文後，再把該使用者的下一則舊推文放入堆，最多取 10 次。
 *   發文平均 O(1)；讀取為 O(U + 10 log U)，U=500；空間 O(T + U^2)，T 是發文數。
 *
 * LeetCode C API：Twitter* twitterCreate(void)、twitterPostTweet、
 * twitterGetNewsFeed、twitterFollow、twitterUnfollow、twitterFree。
 * 動態消息陣列由呼叫端釋放；本機測試中的 main 僅供驗證。
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define TWITTER_MAX_USERS 500
#define TWITTER_FEED_LIMIT 10

typedef struct {
    int tweetId;
    int userId;
    int previous; /* 同一作者上一則較舊推文的索引；-1 表示沒有。 */
} Tweet;

typedef struct {
    Tweet *tweets;
    int tweetCount;
    int tweetCapacity;
    int latest[TWITTER_MAX_USERS + 1];
    unsigned char follows[TWITTER_MAX_USERS + 1][TWITTER_MAX_USERS + 1];
} Twitter;

static void pushMaxHeap(int *heap, int *size, int tweetIndex) {
    int position = (*size)++;
    while (position > 0) {
        int parent = (position - 1) / 2;
        if (heap[parent] >= tweetIndex) break;
        heap[position] = heap[parent];
        position = parent;
    }
    heap[position] = tweetIndex;
}

static int popMaxHeap(int *heap, int *size) {
    int result = heap[0];
    int last = heap[--(*size)];
    int position = 0;
    while (position * 2 + 1 < *size) {
        int child = position * 2 + 1;
        if (child + 1 < *size && heap[child + 1] > heap[child]) ++child;
        if (heap[child] <= last) break;
        heap[position] = heap[child];
        position = child;
    }
    if (*size > 0) heap[position] = last;
    return result;
}

/* ---------- LeetCode submission / 提交區 ---------- */
Twitter *twitterCreate(void) {
    Twitter *twitter = (Twitter *)calloc(1, sizeof *twitter);
    if (twitter == NULL) return NULL;
    for (int user = 0; user <= TWITTER_MAX_USERS; ++user)
        twitter->latest[user] = -1;
    return twitter;
}

void twitterPostTweet(Twitter *obj, int userId, int tweetId) {
    if (obj == NULL || userId < 1 || userId > TWITTER_MAX_USERS) return;
    if (obj->tweetCount == obj->tweetCapacity) {
        int newCapacity = obj->tweetCapacity == 0 ? 16 : obj->tweetCapacity * 2;
        if (newCapacity < obj->tweetCapacity ||
            (size_t)newCapacity > SIZE_MAX / sizeof *obj->tweets) return;
        Tweet *grown = (Tweet *)realloc(
            obj->tweets, (size_t)newCapacity * sizeof *obj->tweets);
        if (grown == NULL) return;
        obj->tweets = grown;
        obj->tweetCapacity = newCapacity;
    }
    int index = obj->tweetCount++;
    obj->tweets[index].tweetId = tweetId;
    obj->tweets[index].userId = userId;
    obj->tweets[index].previous = obj->latest[userId];
    obj->latest[userId] = index;
}

int *twitterGetNewsFeed(Twitter *obj, int userId, int *retSize) {
    if (retSize == NULL) return NULL;
    *retSize = 0;
    if (obj == NULL || userId < 1 || userId > TWITTER_MAX_USERS) return NULL;

    int *feed = (int *)malloc(TWITTER_FEED_LIMIT * sizeof *feed);
    if (feed == NULL) return NULL;
    int heap[TWITTER_MAX_USERS + 1];
    int heapSize = 0;

    /* 每位可見作者只放入目前最新的一則，堆中索引越大代表發文越新。 */
    for (int author = 1; author <= TWITTER_MAX_USERS; ++author) {
        if ((author == userId || obj->follows[userId][author]) &&
            obj->latest[author] >= 0) {
            pushMaxHeap(heap, &heapSize, obj->latest[author]);
        }
    }
    while (heapSize > 0 && *retSize < TWITTER_FEED_LIMIT) {
        int index = popMaxHeap(heap, &heapSize);
        feed[(*retSize)++] = obj->tweets[index].tweetId;
        int older = obj->tweets[index].previous;
        if (older >= 0) pushMaxHeap(heap, &heapSize, older);
    }
    return feed;
}

void twitterFollow(Twitter *obj, int followerId, int followeeId) {
    if (obj == NULL || followerId < 1 || followerId > TWITTER_MAX_USERS ||
        followeeId < 1 || followeeId > TWITTER_MAX_USERS ||
        followerId == followeeId) return;
    obj->follows[followerId][followeeId] = 1;
}

void twitterUnfollow(Twitter *obj, int followerId, int followeeId) {
    if (obj == NULL || followerId < 1 || followerId > TWITTER_MAX_USERS ||
        followeeId < 1 || followeeId > TWITTER_MAX_USERS ||
        followerId == followeeId) return;
    obj->follows[followerId][followeeId] = 0;
}

void twitterFree(Twitter *obj) {
    if (obj == NULL) return;
    free(obj->tweets);
    free(obj);
}
/* ---------- end submission ---------- */

static int feedEquals(int *feed, int size, const int *expected, int expectedSize) {
    if (size != expectedSize) return 0;
    for (int i = 0; i < size; ++i) {
        if (feed[i] != expected[i]) return 0;
    }
    return 1;
}

int main(void) {
    Twitter *twitter = twitterCreate();
    const int first[] = {5};
    const int followed[] = {6, 5};
    int size = 0;
    int *feed;
    int passed = twitter != NULL;

    if (twitter != NULL) {
        twitterPostTweet(twitter, 1, 5);
        feed = twitterGetNewsFeed(twitter, 1, &size);
        passed = passed && feedEquals(feed, size, first, 1);
        free(feed);

        twitterFollow(twitter, 1, 2);
        twitterPostTweet(twitter, 2, 6);
        feed = twitterGetNewsFeed(twitter, 1, &size);
        passed = passed && feedEquals(feed, size, followed, 2);
        free(feed);

        twitterUnfollow(twitter, 1, 2);
        feed = twitterGetNewsFeed(twitter, 1, &size);
        passed = passed && feedEquals(feed, size, first, 1);
        free(feed);
        twitterFree(twitter);
    }

    puts(passed ? "PASS: 355 design-twitter" : "FAIL: 355 design-twitter");
    return passed ? 0 : 1;
}
