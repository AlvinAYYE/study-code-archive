/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】依輸入列數印出巴斯卡三角形，並另存可離線開啟的 pascal.svg。
 * 【輸入】列數 n，範圍 1 到 60。【輸出】終端文字三角形和 SVG 圖檔。
 * 【閱讀順序】三角形最左、最右的值都是 1；中間值等於左上方兩個值相加。a[i][j]
 * 表示第 i 列、第 j 個位置。先填完整個二維陣列，再用空白排版輸出，接著用 fprintf
 * 把每個數字包在 SVG 的 text 標籤中。 【C 語法】unsigned long long 用於較大的係數；巢狀 for
 * 建立每列資料；FILE * 是檔案控制指標；fopen、fprintf、fclose 依序開檔、寫檔、關檔。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 輸入列數 n；終端輸出文字三角形，並將可直接離線瀏覽的圖存成 pascal.svg。 */
#include <stdio.h>
#define R 60
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    int row_count;
    unsigned long long pascal_triangle[R][R] = {0};
    if (scanf("%d", &row_count) != 1 || row_count < 1 || row_count > R)
        return 1;
    for (int row = 0; row < row_count; row++)
        for (int column = 0; column <= row; column++)
            pascal_triangle[row][column] =
                (column == 0 || column == row)
                    ? 1
                    : pascal_triangle[row - 1][column - 1] + pascal_triangle[row - 1][column];
    for (int row = 0; row < row_count; row++) {
        for (int s = 0; s < row_count - row - 1; s++)
            putchar(' ');
        for (int column = 0; column <= row; column++)
            printf("%llu ", pascal_triangle[row][column]);
        putchar('\n');
    }
    FILE *svg_file = fopen("pascal.svg", "w");
    if (svg_file) {
        int width = row_count * 70 + 40, height = row_count * 32 + 40;
        fprintf(svg_file,
                "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%d\" height=\"%d\"><rect "
                "width=\"100%%\" height=\"100%%\" fill=\"white\"/><g font-family=\"monospace\" "
                "font-size=\"16\" text-anchor=\"middle\" fill=\"#143\">",
                width,
                height);
        for (int row = 0; row < row_count; row++)
            for (int column = 0; column <= row; column++)
                fprintf(svg_file,
                        "<text x=\"%d\" y=\"%d\">%llu</text>",
                        width / 2 + (2 * column - row) * 30,
                        28 + row * 30,
                        pascal_triangle[row][column]);
        fprintf(svg_file, "</g></svg>\n");
        fclose(svg_file);
        puts("另存三角形圖片：pascal.svg");
    }
    return 0;
}
