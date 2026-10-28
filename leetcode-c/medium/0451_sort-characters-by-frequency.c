/*
 * Title-CN: 依字元出現頻率排序
 * LeetCode 451. Sort Characters By Frequency
 *
 * 題目翻譯：給定字串 s，依字元出現次數由多到少排列。相同字元必須放在一起；
 * 若次數相同，任意順序皆可。回傳任一個符合條件的新字串。
 *
 * 例子：s="tree" 可以回傳 "eetr" 或 "eert"，因為 e 出現兩次，其餘字元各一次。
 *
 * 限制：字串長度最多 500000，只含英文字母與數字。
 *
 * 解題步驟：先用固定大小的 ASCII 計數表統計每個字元。找出最大次數後，
 * 從最大次數往 1 掃描所有字元；每遇到某個次數的字元，就在答案中連續放入該字元。
 *
 * 複雜度：時間 O(n + 128 * f)，f 是最高出現次數；字元表大小固定，因此為 O(n)；
 * 額外空間 O(n) 用來存放回傳字串。
 *
 * LeetCode 提交區：保留 frequencySort 函式；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdlib.h>
#include <string.h>

char *frequencySort(char *s) {
    int counts[128] = {0};
    int length = (int)strlen(s);
    int maxCount = 0;
    for (int i = 0; i < length; ++i) {
        int count = ++counts[(unsigned char)s[i]];
        if (count > maxCount) {
            maxCount = count;
        }
    }

    char *result = malloc((size_t)length + 1);
    if (result == NULL) {
        return NULL;
    }
    int write = 0;
    for (int frequency = maxCount; frequency >= 1; --frequency) {
        for (int ch = 0; ch < 128; ++ch) {
            for (int copy = 0; copy < counts[ch] && counts[ch] == frequency; ++copy) {
                result[write++] = (char)ch;
            }
        }
    }
    result[write] = '\0';
    return result;
}

int main(void) {
    char word[] = "tree";
    char *sorted = frequencySort(word);
    assert(sorted != NULL && strlen(sorted) == 4);
    assert(sorted[0] == 'e' && sorted[1] == 'e');
    free(sorted);

    char digits[] = "cccaaa";
    sorted = frequencySort(digits);
    assert(sorted != NULL && strlen(sorted) == 6);
    assert(sorted[0] == sorted[1] && sorted[1] == sorted[2]);
    assert(sorted[3] == sorted[4] && sorted[4] == sorted[5]);
    assert(sorted[0] != sorted[3]);
    free(sorted);
    return 0;
}
