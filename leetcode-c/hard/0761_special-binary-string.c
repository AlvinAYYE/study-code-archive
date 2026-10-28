/*
 * LeetCode 761. Special Binary String
 * 題意（繁體中文）：特殊二進位字串中，1 和 0 數量相同，且每個前綴的 1
 * 都不少於 0。可以交換相鄰的特殊子字串，求能得到的字典序最大字串。
 *
 * 範例："11011000" -> "11100100"；"10" -> "10"。
 * 限制：長度 1 到 50；字元為 0 或 1；輸入保證是特殊字串。
 * 解法：每個最外層原子區塊都長得像「1 + 內層特殊字串 + 0」。
 *       遞迴把各區塊的內層字串變大，再將每個完整區塊依字典序由大到小排序，
 *       最後串接。最外層的 1、0 不能拆開交換，因此排序區塊即可取得最大結果。
 * 複雜度：O(n^2 log n) 時間上界、O(n^2) 暫存空間上界，n 為字串長度。
 * LeetCode C API：char* makeLargestSpecial(char* s)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *makeLargestRange(const char *s, int length);

static int compareBlocksDescending(const void *left, const void *right) {
    const char *a = *(char * const *)left;
    const char *b = *(char * const *)right;
    return -strcmp(a, b);
}

static char *makeLargestRange(const char *s, int length) {
    char *blocks[26];
    int blockCount = 0;
    int start = 0, balance = 0;
    for (int i = 0; i < length; ++i) {
        balance += s[i] == '1' ? 1 : -1;
        if (balance != 0) continue;

        int innerLength = i - start - 1;
        char *inner = makeLargestRange(s + start + 1, innerLength);
        if (inner == NULL) {
            for (int j = 0; j < blockCount; ++j) free(blocks[j]);
            return NULL;
        }
        blocks[blockCount] = (char *)malloc((size_t)i - start + 2);
        if (blocks[blockCount] == NULL) {
            free(inner);
            for (int j = 0; j < blockCount; ++j) free(blocks[j]);
            return NULL;
        }
        blocks[blockCount][0] = '1';
        memcpy(blocks[blockCount] + 1, inner, (size_t)innerLength);
        blocks[blockCount][innerLength + 1] = '0';
        blocks[blockCount][innerLength + 2] = '\0';
        free(inner);
        ++blockCount;
        start = i + 1;
    }

    qsort(blocks, (size_t)blockCount, sizeof *blocks, compareBlocksDescending);
    char *result = (char *)malloc((size_t)length + 1);
    if (result == NULL) {
        for (int i = 0; i < blockCount; ++i) free(blocks[i]);
        return NULL;
    }
    int at = 0;
    for (int i = 0; i < blockCount; ++i) {
        int blockLength = (int)strlen(blocks[i]);
        memcpy(result + at, blocks[i], (size_t)blockLength);
        at += blockLength;
        free(blocks[i]);
    }
    result[at] = '\0';
    return result;
}

char* makeLargestSpecial(char* s) {
    return makeLargestRange(s, (int)strlen(s));
}

int main(void) {
    char first[] = "11011000";
    char second[] = "10";
    char *answer1 = makeLargestSpecial(first);
    char *answer2 = makeLargestSpecial(second);
    int passed = answer1 != NULL && answer2 != NULL &&
                 strcmp(answer1, "11100100") == 0 && strcmp(answer2, "10") == 0;
    free(answer1);
    free(answer2);
    puts(passed ? "PASS: 761 special-binary-string"
                : "FAIL: 761 special-binary-string");
    return passed ? 0 : 1;
}
