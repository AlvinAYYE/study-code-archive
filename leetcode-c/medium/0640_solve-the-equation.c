/*
 * Title-CN: 求解方程
 * LeetCode 640. Solve the Equation
 *
 * 題意翻譯：給定一個只有整數、變數 x、加減號和等號的一元一次方程，
 * 回傳解的字串。若有唯一解，格式為 "x=數字"；若無解或有無限多解，回傳指定文字。
 *
 * 範例："x+5-3+x=6+x-2" 回傳 "x=2"。
 *
 * 限制：方程長度不超過 1000；係數與常數絕對值不超過 1000；輸入格式正確。
 *
 * 解題思路：分別掃描等號左右兩邊，把每一項累加成「x 的係數」和「常數」。
 * 移項後得到 (左係數-右係數)*x = 右常數-左常數。係數為 0 時依常數判斷
 * 無解或無限多解；否則用右側常數除以係數得到唯一解。
 *
 * 複雜度：時間 O(n)，額外空間 O(1)（輸出字串除外）。
 * LeetCode 介面：保留 solveEquation；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void parseSide(const char *equation, int *position, int stopAtEquals,
                      int *coefficient, int *constant) {
    while (equation[*position] != '\0'
           && !(stopAtEquals && equation[*position] == '=')) {
        int sign = 1;
        if (equation[*position] == '+' || equation[*position] == '-') {
            if (equation[*position] == '-') sign = -1;
            ++*position;
        }

        int value = 0;
        int hasDigits = 0;
        while (equation[*position] >= '0' && equation[*position] <= '9') {
            value = value * 10 + equation[*position] - '0';
            ++*position;
            hasDigits = 1;
        }
        if (equation[*position] == 'x') {
            *coefficient += sign * (hasDigits ? value : 1);
            ++*position;
        } else {
            *constant += sign * value;
        }
    }
}

char *solveEquation(char *equation) {
    int position = 0;
    int leftCoefficient = 0;
    int leftConstant = 0;
    int rightCoefficient = 0;
    int rightConstant = 0;
    parseSide(equation, &position, 1, &leftCoefficient, &leftConstant);
    if (equation[position] == '=') ++position;
    parseSide(equation, &position, 0, &rightCoefficient, &rightConstant);

    int coefficient = leftCoefficient - rightCoefficient;
    int value = rightConstant - leftConstant;
    char *answer = malloc(64);
    if (answer == NULL) return NULL;
    if (coefficient == 0) {
        snprintf(answer, 64, "%s", value == 0 ? "Infinite solutions" : "No solution");
    } else {
        snprintf(answer, 64, "x=%d", value / coefficient);
    }
    return answer;
}

int main(void) {
    char unique[] = "x+5-3+x=6+x-2";
    char infinite[] = "x=x";
    char noSolution[] = "x=x+2";
    char zero[] = "2x=x";
    char *answer = solveEquation(unique);
    assert(answer != NULL && strcmp(answer, "x=2") == 0);
    free(answer);
    answer = solveEquation(infinite);
    assert(answer != NULL && strcmp(answer, "Infinite solutions") == 0);
    free(answer);
    answer = solveEquation(noSolution);
    assert(answer != NULL && strcmp(answer, "No solution") == 0);
    free(answer);
    answer = solveEquation(zero);
    assert(answer != NULL && strcmp(answer, "x=0") == 0);
    free(answer);
    return 0;
}
