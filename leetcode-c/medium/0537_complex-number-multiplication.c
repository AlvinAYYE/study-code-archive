/*
 * Title-CN: 複數相乘
 * LeetCode 537. Complex Number Multiplication
 *
 * 題意翻譯：給定兩個字串形式的複數，格式為「實部+虛部i」，回傳相乘結果，
 * 並用同樣格式表示。實部或虛部可以是負數，例如 "1+-1i"。
 *
 * 範例：num1 = "1+1i"、num2 = "1+1i"，回傳 "0+2i"。
 * 說明：(1+i)(1+i) = 1+i+i+i^2 = 2i。
 *
 * 限制：實部與虛部介於 -100 到 100；輸入格式正確。
 *
 * 解題思路：把兩個字串解析成 a+bi 和 c+di，套用乘法公式：
 * 實部為 ac-bd，虛部為 ad+bc。最後配置足夠長度的字串並格式化輸出。
 *
 * 複雜度：時間 O(1)，空間 O(1)（輸出字串固定有界）。呼叫端需釋放回傳字串。
 * LeetCode 介面：保留 complexNumberMultiply；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

char *complexNumberMultiply(char *num1, char *num2) {
    int real1, imaginary1, real2, imaginary2;
    if (sscanf(num1, "%d+%di", &real1, &imaginary1) != 2
        || sscanf(num2, "%d+%di", &real2, &imaginary2) != 2) {
        return NULL;
    }

    int real = real1 * real2 - imaginary1 * imaginary2;
    int imaginary = real1 * imaginary2 + imaginary1 * real2;
    char *answer = malloc(64);
    if (answer == NULL) return NULL;
    snprintf(answer, 64, "%d+%di", real, imaginary);
    return answer;
}

int main(void) {
    char first[] = "1+1i";
    char second[] = "1+1i";
    char *answer = complexNumberMultiply(first, second);
    assert(answer != NULL && answer[0] == '0');
    assert(answer[1] == '+' && answer[2] == '2' && answer[3] == 'i');
    free(answer);

    char negative[] = "1+-1i";
    char one[] = "1+0i";
    answer = complexNumberMultiply(negative, one);
    assert(answer != NULL && answer[0] == '1' && answer[1] == '+'
           && answer[2] == '-' && answer[3] == '1' && answer[4] == 'i');
    free(answer);
    return 0;
}
