/*
 * LeetCode 488. Zuma Game／祖瑪遊戲
 *
 * 題目（繁體中文）
 *   棋盤是一排彩球，顏色為 R、Y、B、G、W；手上也有一些球。每回合可把手上
 *   一顆球插入棋盤任意位置。只要連續三顆以上同色球相鄰，就會消除；消除後
 *   兩側可能接在一起並繼續消除。請回傳清空棋盤所需的最少插球數；無法清空
 *   時回傳 -1。
 *
 * 範例 1：board="WRRBBW"、hand="RB"，無法清空，輸出 -1。
 * 範例 2：board="WWRRBBWW"、hand="WRBRW"，最少插 2 顆可清空，輸出 2。
 * 範例 3：board="G"、hand="GGGGG"，再插 2 顆 G 即可消除，輸出 2。
 * 限制：board 長度 1..16；hand 長度 1..5；只含 R、Y、B、G、W；
 *   初始棋盤不含連續三顆以上同色球。
 *
 * 解題步驟：
 *   1. 對棋盤每一段同色連續球，計算還差幾顆才達到三顆；只有手牌數量足夠時
 *      才嘗試這個選擇。
 *   2. 插入需要的同色球，讓該段立即消除，再把剩餘棋盤接合並反覆消除新形成
 *      的三顆以上同色段。
 *   3. 對每種剩餘棋盤與手牌顏色數量做記憶化搜尋，回傳最少後續插球數。
 *   4. 每次遞迴至少消耗一顆手牌，深度最多 5；以 S 表示搜尋到的不同狀態數，
 *      時間 O(S×L×C)，L<=16、C=5；記憶化空間 O(S)。
 *
 * LeetCode C API：int findMinStep(char* board, char* hand)。
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define ZUMA_COLORS 5
#define ZUMA_MAX_BOARD 16
#define ZUMA_MEMO_BUCKETS 65537
#define ZUMA_IMPOSSIBLE 1000000

typedef struct MemoEntry MemoEntry;
typedef struct {
    MemoEntry **buckets;
} ZumaMemo;

struct MemoEntry {
    uint64_t boardCode;
    uint16_t handCode;
    unsigned char boardLength;
    int result;
    MemoEntry *next;
};

static int colorIndex(char color) {
    switch (color) {
        case 'R': return 0;
        case 'Y': return 1;
        case 'B': return 2;
        case 'G': return 3;
        default: return 4; /* W */
    }
}

static void reduceBoard(char *board, int *length) {
    int changed = 1;
    while (changed) {
        int read = 0, write = 0;
        changed = 0;
        while (read < *length) {
            int end = read + 1;
            while (end < *length && board[end] == board[read]) ++end;
            if (end - read >= 3) {
                changed = 1;
            } else {
                while (read < end) board[write++] = board[read++];
                continue;
            }
            read = end;
        }
        *length = write;
        board[write] = '\0';
    }
}

static void encodeState(const char *board, int length,
                        const unsigned char *hand,
                        uint64_t *boardCode, uint16_t *handCode) {
    uint64_t encodedBoard = 0;
    uint16_t encodedHand = 0;
    for (int i = 0; i < length; ++i)
        encodedBoard |= (uint64_t)colorIndex(board[i]) << (3 * i);
    for (int color = 0; color < ZUMA_COLORS; ++color)
        encodedHand |= (uint16_t)(hand[color] & 7u) << (3 * color);
    *boardCode = encodedBoard;
    *handCode = encodedHand;
}

static size_t stateHash(uint64_t boardCode, uint16_t handCode, int boardLength) {
    uint64_t hash = boardCode + UINT64_C(0x9e3779b97f4a7c15);
    hash ^= (uint64_t)handCode + (hash << 6) + (hash >> 2);
    hash ^= (uint64_t)boardLength * UINT64_C(0xbf58476d1ce4e5b9);
    hash ^= hash >> 30;
    hash *= UINT64_C(0xbf58476d1ce4e5b9);
    hash ^= hash >> 27;
    hash *= UINT64_C(0x94d049bb133111eb);
    hash ^= hash >> 31;
    return (size_t)(hash % ZUMA_MEMO_BUCKETS);
}

static MemoEntry *findMemoEntry(ZumaMemo *memo, uint64_t boardCode,
                                uint16_t handCode, int boardLength) {
    if (memo->buckets == NULL) return NULL;
    size_t slot = stateHash(boardCode, handCode, boardLength);
    for (MemoEntry *entry = memo->buckets[slot]; entry != NULL;
         entry = entry->next) {
        if (entry->boardCode == boardCode && entry->handCode == handCode &&
            entry->boardLength == boardLength) return entry;
    }
    return NULL;
}

static void saveMemoEntry(ZumaMemo *memo, uint64_t boardCode,
                          uint16_t handCode, int boardLength, int result) {
    if (memo->buckets == NULL) return;
    size_t slot = stateHash(boardCode, handCode, boardLength);
    MemoEntry *entry = (MemoEntry *)malloc(sizeof *entry);
    if (entry == NULL) return; /* 記憶化失敗不影響答案正確性。 */
    entry->boardCode = boardCode;
    entry->handCode = handCode;
    entry->boardLength = (unsigned char)boardLength;
    entry->result = result;
    entry->next = memo->buckets[slot];
    memo->buckets[slot] = entry;
}

static int solveZuma(char *board, int boardLength, unsigned char *hand,
                     ZumaMemo *memo) {
    if (boardLength == 0) return 0;
    uint64_t boardCode;
    uint16_t handCode;
    encodeState(board, boardLength, hand, &boardCode, &handCode);
    MemoEntry *cached = findMemoEntry(memo, boardCode, handCode, boardLength);
    if (cached != NULL) return cached->result;

    int best = ZUMA_IMPOSSIBLE;
    for (int start = 0; start < boardLength;) {
        int end = start + 1;
        while (end < boardLength && board[end] == board[start]) ++end;
        int runLength = end - start;
        int color = colorIndex(board[start]);
        int needed = 3 - runLength;

        if (needed > 0 && hand[color] >= needed) {
            char nextBoard[ZUMA_MAX_BOARD + 1];
            int nextLength = 0;
            memcpy(nextBoard, board, (size_t)start);
            nextLength = start;
            memcpy(nextBoard + nextLength, board + end,
                   (size_t)(boardLength - end));
            nextLength += boardLength - end;
            nextBoard[nextLength] = '\0';
            reduceBoard(nextBoard, &nextLength);

            hand[color] = (unsigned char)(hand[color] - needed);
            int remaining = solveZuma(nextBoard, nextLength, hand, memo);
            hand[color] = (unsigned char)(hand[color] + needed);
            if (remaining < ZUMA_IMPOSSIBLE && needed + remaining < best)
                best = needed + remaining;
        }
        start = end;
    }

    saveMemoEntry(memo, boardCode, handCode, boardLength, best);
    return best;
}

static void freeMemo(ZumaMemo *memo) {
    if (memo->buckets == NULL) return;
    for (size_t i = 0; i < ZUMA_MEMO_BUCKETS; ++i) {
        MemoEntry *entry = memo->buckets[i];
        while (entry != NULL) {
            MemoEntry *next = entry->next;
            free(entry);
            entry = next;
        }
    }
    free(memo->buckets);
    memo->buckets = NULL;
}

/* ---------- LeetCode submission / 提交區 ---------- */
int findMinStep(char *board, char *hand) {
    if (board == NULL || hand == NULL) return -1;
    int boardLength = (int)strlen(board);
    unsigned char handCounts[ZUMA_COLORS] = {0};
    for (const char *p = hand; *p != '\0'; ++p)
        ++handCounts[colorIndex(*p)];

    char reducedBoard[ZUMA_MAX_BOARD + 1];
    memcpy(reducedBoard, board, (size_t)boardLength + 1);
    reduceBoard(reducedBoard, &boardLength);

    ZumaMemo memo;
    memo.buckets = (MemoEntry **)calloc(ZUMA_MEMO_BUCKETS,
                                        sizeof *memo.buckets);
    int result = solveZuma(reducedBoard, boardLength, handCounts, &memo);
    freeMemo(&memo);
    return result >= ZUMA_IMPOSSIBLE ? -1 : result;
}
/* ---------- end submission ---------- */

int main(void) {
    char board1[] = "WRRBBW", hand1[] = "RB";
    char board2[] = "WWRRBBWW", hand2[] = "WRBRW";
    char board3[] = "G", hand3[] = "GGGGG";
    int passed = findMinStep(board1, hand1) == -1 &&
                 findMinStep(board2, hand2) == 2 &&
                 findMinStep(board3, hand3) == 2;

    puts(passed ? "PASS: 488 zuma-game" : "FAIL: 488 zuma-game");
    return passed ? 0 : 1;
}
