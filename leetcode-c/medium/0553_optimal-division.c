/*
 * Title-CN: 最佳除法
 * LeetCode 553. Optimal Division
 *
 * 題意翻譯：給定一串正整數，可依照原順序在相鄰數字間放除號，並加入括號，
 * 請產生能得到最大結果的表示式。答案以字串回傳。
 *
 * 範例：[1000,100,10,2] 回傳 "1000/(100/10/2)"。
 * 說明：把後面所有數字放進同一個分母，可讓分母變小，因此整體商變大。
 *
 * 限制：數字個數為 1 到 10；每個數字介於 2 到 1000。
 *
 * 解題思路：數字都大於 1。只有兩個數時結果固定為 a/b；三個以上時，
 * 最佳形式是 a/(b/c/d/...)。因為括號內依序相除會讓分母逐漸變小，
 * 而把第一個最大化的數放在最外層分子。
 *
 * 複雜度：時間 O(n)，輸出空間 O(n)。
 * LeetCode 介面：保留 optimalDivision；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

char *optimalDivision(int *nums, int numsSize) {
    size_t capacity = (size_t)numsSize * 16 + 16;
    char *answer = malloc(capacity);
    if (answer == NULL) return NULL;

    if (numsSize == 1) {
        snprintf(answer, capacity, "%d", nums[0]);
    } else if (numsSize == 2) {
        snprintf(answer, capacity, "%d/%d", nums[0], nums[1]);
    } else {
        int used = snprintf(answer, capacity, "%d/(", nums[0]);
        for (int i = 1; i < numsSize; ++i) {
            used += snprintf(answer + used, capacity - (size_t)used,
                             "%s%d", i == 1 ? "" : "/", nums[i]);
        }
        snprintf(answer + used, capacity - (size_t)used, ")");
    }
    return answer;
}

int main(void) {
    int one[] = {7};
    int two[] = {7, 3};
    int many[] = {1000, 100, 10, 2};
    char *answer = optimalDivision(one, 1);
    assert(answer != NULL && answer[0] == '7' && answer[1] == '\0');
    free(answer);
    answer = optimalDivision(two, 2);
    assert(answer != NULL && answer[0] == '7' && answer[1] == '/' && answer[2] == '3');
    free(answer);
    answer = optimalDivision(many, 4);
    assert(answer != NULL && answer[0] == '1' && answer[1] == '0'
           && answer[2] == '0' && answer[3] == '0' && answer[4] == '/'
           && answer[5] == '(' && answer[6] == '1');
    free(answer);
    return 0;
}
