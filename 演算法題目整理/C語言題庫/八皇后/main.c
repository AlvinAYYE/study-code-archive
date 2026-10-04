/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】在 8×8 棋盤放 8
 * 個皇后，使任兩個皇后不在同一列、同一欄或同一斜線。程式列舉全部解法，顯示第一個棋盤並輸出
 * queens.svg。 【輸入】不需要輸入。【輸出】解法總數和棋盤。 【閱讀順序】solve(r) 正在安排第 r
 * 列。每次嘗試一個欄
 * c，檢查它與之前各列皇后的欄位和斜線是否衝突。若安全就暫放並遞迴處理下一列；排到第 8
 * 列代表找到一組解。回到上一層後再試其他欄位。 【C 語法】q[r] 保存第 r
 * 列皇后所在欄位；遞迴是函式呼叫自己；count 統計解的數量；first
 * 複製第一組解，供文字與 SVG 顯示。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 回溯列舉 8 皇后全部解法，顯示解法總數、第一個棋盤，並輸出 queens.svg。 */
#include <stdio.h>
int queen_column[8], solution_count = 0, first_solution[8];
void solve(int row) {
    if (row == 8) {
        if (!solution_count)
            for (int index = 0; index < 8; index++)
                first_solution[index] = queen_column[index];
        solution_count++;
        return;
    }
    for (int column = 0; column < 8; column++) {
        int is_safe = 1;
        for (int index = 0; index < row; index++)
            if (queen_column[index] == column || row - index == column - queen_column[index] ||
                row - index == queen_column[index] - column)
                is_safe = 0;
        if (is_safe) {
            queen_column[row] = column;
            solve(row + 1);
        }
    }
}
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    solve(0);
    printf("解法總數：%d\n", solution_count);
    for (int row = 0; row < 8; row++) {
        for (int column = 0; column < 8; column++)
            printf("%c ", first_solution[row] == column ? 'Q' : '.');
        putchar('\n');
    }
    FILE *svg_file = fopen("queens.svg", "w");
    if (svg_file) {
        fprintf(svg_file,
                "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"400\" height=\"400\">");
        for (int row = 0; row < 8; row++)
            for (int column = 0; column < 8; column++) {
                fprintf(svg_file,
                        "<rect x=\"%d\" y=\"%d\" width=\"50\" height=\"50\" fill=\"%s\"/>",
                        column * 50,
                        row * 50,
                        (row + column) % 2 ? "#ddd" : "#fff");
                if (first_solution[row] == column)
                    fprintf(svg_file,
                            "<text x=\"%d\" y=\"%d\" text-anchor=\"middle\" font-size=\"36\" "
                            "fill=\"#b22\">Q</text>",
                            column * 50 + 25,
                            row * 50 + 39);
            }
        fprintf(svg_file, "</svg>");
        fclose(svg_file);
        puts("另存棋盤圖：queens.svg");
    }
    return 0;
}
