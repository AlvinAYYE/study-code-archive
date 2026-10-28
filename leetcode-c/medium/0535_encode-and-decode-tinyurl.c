/*
 * Title-CN: TinyURL 的編碼與解碼
 * LeetCode 535. Encode and Decode TinyURL
 *
 * 題意翻譯：設計一個短網址服務。encode 把長網址轉成短網址；decode 必須能
 * 將該短網址還原成原始長網址。題目不限制短網址格式，只要求編碼與解碼互相對應。
 *
 * 範例：encode("https://example.com/article") 回傳短網址；把它交給 decode，
 * 就會取回 "https://example.com/article"。
 *
 * 限制：長網址是非空字串；encode 與 decode 呼叫次數不超過 10^5。
 *
 * 解題思路：每次編碼時把原網址複製到動態陣列，並用遞增整數 ID 當作短碼。
 * 將 ID 轉成 36 進位附在固定網址前綴後。解碼時讀回短碼 ID，再從陣列取回原網址。
 *
 * 複雜度：編碼/解碼的 ID 處理為 O(log id)，儲存長網址需要 O(L)；總空間 O(所有網址長度)。
 * LeetCode 介面：保留 solutionCreate、encode、decode、solutionFree；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Solution {
    char **urls;
    size_t count;
    size_t capacity;
};

struct Solution *solutionCreate(void) {
    struct Solution *solution = calloc(1, sizeof(*solution));
    return solution;
}

static void toBase36(size_t value, char *buffer) {
    static const char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    char reverse[32];
    int length = 0;
    do {
        reverse[length++] = digits[value % 36];
        value /= 36;
    } while (value > 0);
    for (int i = 0; i < length; ++i) buffer[i] = reverse[length - i - 1];
    buffer[length] = '\0';
}

char *encode(struct Solution *solution, char *longUrl) {
    if (solution->count == solution->capacity) {
        size_t newCapacity = solution->capacity == 0 ? 16 : solution->capacity * 2;
        char **grown = realloc(solution->urls, newCapacity * sizeof(*solution->urls));
        if (grown == NULL) return NULL;
        solution->urls = grown;
        solution->capacity = newCapacity;
    }

    char *savedUrl = malloc(strlen(longUrl) + 1);
    if (savedUrl == NULL) return NULL;
    strcpy(savedUrl, longUrl);
    size_t id = solution->count;
    solution->urls[solution->count++] = savedUrl;

    char code[32];
    toBase36(id, code);
    static const char prefix[] = "https://tinyurl.com/";
    size_t resultLength = sizeof(prefix) - 1 + strlen(code) + 1;
    char *shortUrl = malloc(resultLength);
    if (shortUrl == NULL) return NULL;
    snprintf(shortUrl, resultLength, "%s%s", prefix, code);
    return shortUrl;
}

char *decode(struct Solution *solution, char *shortUrl) {
    const char *slash = strrchr(shortUrl, '/');
    if (slash == NULL || slash[1] == '\0') return NULL;

    size_t id = 0;
    for (const char *p = slash + 1; *p != '\0'; ++p) {
        unsigned int digit;
        if (*p >= '0' && *p <= '9') digit = (unsigned int)(*p - '0');
        else if (*p >= 'a' && *p <= 'z') digit = (unsigned int)(*p - 'a') + 10;
        else return NULL;
        if (id > (SIZE_MAX - digit) / 36) return NULL;
        id = id * 36 + digit;
    }
    if (id >= solution->count) return NULL;
    size_t length = strlen(solution->urls[id]);
    char *decoded = malloc(length + 1);
    if (decoded == NULL) return NULL;
    memcpy(decoded, solution->urls[id], length + 1);
    return decoded;
}

void solutionFree(struct Solution *solution) {
    if (solution == NULL) return;
    for (size_t i = 0; i < solution->count; ++i) free(solution->urls[i]);
    free(solution->urls);
    free(solution);
}

int main(void) {
    struct Solution *solution = solutionCreate();
    assert(solution != NULL);
    char first[] = "https://example.com/article";
    char second[] = "https://example.com/another-page";
    char *shortFirst = encode(solution, first);
    char *shortSecond = encode(solution, second);
    assert(shortFirst != NULL && shortSecond != NULL);
    char *decodedFirst = decode(solution, shortFirst);
    char *decodedSecond = decode(solution, shortSecond);
    assert(decodedFirst != NULL && strcmp(decodedFirst, first) == 0);
    assert(decodedSecond != NULL && strcmp(decodedSecond, second) == 0);
    free(decodedFirst);
    free(decodedSecond);
    free(shortFirst);
    free(shortSecond);
    solutionFree(solution);
    return 0;
}
