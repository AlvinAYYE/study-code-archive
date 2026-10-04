/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】計算後序（逆波蘭）算式，例如「12 3 4 * +」代表 12+(3×4)。
 * 【輸入】一行以空白分隔的數字和 + - * /
 * 運算子。【輸出】最後計算值；格式或運算元數量錯誤時印出錯誤。 【閱讀順序】strtok 把一行切成一個個
 * tok。遇到數字就用 strtod 轉成數值並放進 st
 * 堆疊；遇到運算子就取出最上面的兩個數，計算後把結果放回堆疊。全部讀完後，堆疊必須只剩一個答案。
 * 【C 語法】堆疊用陣列 st[] 加上 n 表示目前元素數；st[--n]
 * 表示先把 n 減一，再取出該位置；strtok 會修改原字串來切詞；除法前檢查除數不是 0。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 輸入以空白分隔的後序運算式，如：12 3 4 * +。 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    char expression[10000], *token;
    double value_stack[5000];
    int stack_size = 0;
    if (!fgets(expression, sizeof expression, stdin))
        return 1;
    for (token = strtok(expression, " \t\r\n"); token; token = strtok(NULL, " \t\r\n")) {
        if (strlen(token) == 1 && strchr("+-*/", token[0])) {
            if (stack_size < 2)
                return puts("表示式錯誤"), 1;
            double right_operand = value_stack[--stack_size],
                   left_operand = value_stack[--stack_size];
            if (token[0] == '+')
                value_stack[stack_size++] = left_operand + right_operand;
            else if (token[0] == '-')
                value_stack[stack_size++] = left_operand - right_operand;
            else if (token[0] == '*')
                value_stack[stack_size++] = left_operand * right_operand;
            else {
                if (right_operand == 0)
                    return puts("除數不可為 0"), 1;
                value_stack[stack_size++] = left_operand / right_operand;
            }
        } else {
            char *parse_end;
            double number = strtod(token, &parse_end);
            if (*parse_end || stack_size == 5000)
                return puts("表示式錯誤"), 1;
            value_stack[stack_size++] = number;
        }
    }
    if (stack_size != 1)
        return puts("表示式錯誤"), 1;
    printf("%.10g\n", value_stack[0]);
    return 0;
}
