/*
 * Title-CN: 分數加減運算
 * LeetCode 592. Fraction Addition and Subtraction
 *
 * 題意翻譯：給定只包含分數加法與減法的算式字串，例如 "-1/2+1/2+1/3"，
 * 計算結果並回傳最簡分數，格式固定為「分子/分母」。
 *
 * 範例："-1/2+1/2+1/3" 回傳 "1/3"；"1/3-1/2" 回傳 "-1/6"。
 *
 * 限制：算式長度不超過 1000；每個分子介於 -10 到 10；分母介於 1 到 10；
 * 算式保證格式正確。
 *
 * 解題思路：從左到右讀取每一個分數。若目前答案是 a/b，新分數是 c/d，
 * 相加後為 (a*d+c*b)/(b*d)。每次都用最大公因數約分，讓數字保持小，
 * 最後將分子和分母格式化成字串。
 *
 * 複雜度：時間 O(n)，n 為算式長度；額外空間 O(1)（輸出字串除外）。
 * LeetCode 介面：保留 fractionAddition；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static long long gcd(long long a, long long b) {
    if (a < 0) a = -a;
    while (b != 0) {
        long long remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

char *fractionAddition(char *expression) {
    long long numerator = 0;
    long long denominator = 1;
    char *cursor = expression;

    while (*cursor != '\0') {
        char *end;
        long long nextNumerator = strtoll(cursor, &end, 10);
        cursor = end;
        ++cursor; /* '/' */
        long long nextDenominator = strtoll(cursor, &end, 10);
        cursor = end;

        numerator = numerator * nextDenominator + nextNumerator * denominator;
        denominator *= nextDenominator;
        long long divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
    }

    char *answer = malloc(64);
    if (answer == NULL) return NULL;
    snprintf(answer, 64, "%lld/%lld", numerator, denominator);
    return answer;
}

int main(void) {
    char first[] = "-1/2+1/2+1/3";
    char second[] = "1/3-1/2";
    char third[] = "5/3+1/3";
    char *answer = fractionAddition(first);
    assert(answer != NULL && answer[0] == '1' && answer[1] == '/' && answer[2] == '3');
    free(answer);
    answer = fractionAddition(second);
    assert(answer != NULL && answer[0] == '-' && answer[1] == '1'
           && answer[2] == '/' && answer[3] == '6');
    free(answer);
    answer = fractionAddition(third);
    assert(answer != NULL && answer[0] == '2' && answer[1] == '/' && answer[2] == '1');
    free(answer);
    return 0;
}
