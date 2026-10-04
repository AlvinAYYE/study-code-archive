/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】在 8×8 迷宮中從左上走到右下；0 是可走格、1
 * 是牆。這版允許上下左右及四個斜向共八個方向，並找最少步數路徑。 【輸入】64 個 0 或 1，可分成 8
 * 行輸入。【輸出】座標路徑、以 * 標示的文字迷宮，以及 maze.svg 圖檔。
 * 【閱讀順序】BFS（廣度優先搜尋）用佇列一層一層擴展格子，所以第一次到達終點就是最少步數。d[y][x]
 * 記錄起點到格子的步數；pr、pc
 * 記錄前一格。找到終點後沿前一格回溯並標記路徑。 【C 語法】qr、qc
 * 是佇列的列和欄陣列；head 是下一個要取出的佇列位置，tail
 * 是新增位置；dr、dc 用成對位移表示八個方向。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 輸入 8x8 迷宮（0 可走、1 牆），起點左上、終點右下；輸出最短路徑並存 maze.svg。 */
#include <stdio.h>
#include <stdlib.h>
#define S 8
int maze[S][S], distance[S][S], previous_row[S][S], previous_column[S][S];
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    for (int index = 0; index < S; index++)
        for (int inner_index = 0; inner_index < S; inner_index++)
            if (scanf("%d", &maze[index][inner_index]) != 1)
                return 1;
    if (maze[0][0] || maze[7][7])
        return puts("起點或終點被牆擋住"), 1;
    int queue_rows[100], queue_columns[100], queue_head = 0, queue_tail = 0,
                                             row_delta[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
                                             column_delta[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    for (int index = 0; index < S; index++)
        for (int inner_index = 0; inner_index < S; inner_index++)
            distance[index][inner_index] = -1;
    queue_rows[queue_tail] = 0;
    queue_columns[queue_tail++] = 0;
    distance[0][0] = 0;
    while (queue_head < queue_tail && distance[7][7] < 0) {
        int row = queue_rows[queue_head], column = queue_columns[queue_head++];
        for (int direction_index = 0; direction_index < 8; direction_index++) {
            int next_row = row + row_delta[direction_index],
                next_column = column + column_delta[direction_index];
            if (next_row >= 0 && next_row < S && next_column >= 0 && next_column < S &&
                !maze[next_row][next_column] && distance[next_row][next_column] < 0) {
                distance[next_row][next_column] = distance[row][column] + 1;
                previous_row[next_row][next_column] = row;
                previous_column[next_row][next_column] = column;
                queue_rows[queue_tail] = next_row;
                queue_columns[queue_tail++] = next_column;
            }
        }
    }
    if (distance[7][7] < 0)
        return puts("找不到路徑"), 0;
    int path_rows[64], path_columns[64], path_length = 0;
    for (int row = 7, column = 7;;
         row = previous_row[row][column], column = previous_column[row][column]) {
        path_rows[path_length] = row;
        path_columns[path_length++] = column;
        if (!row && !column)
            break;
    }
    puts("路徑座標（row,col，從 0 起）:");
    for (int index = path_length - 1; index >= 0; index--)
        printf("(%d,%d)%s", path_rows[index], path_columns[index], index ? " -> " : "\n");
    for (int index = 0; index < path_length; index++)
        maze[path_rows[index]][path_columns[index]] = 2;
    for (int index = 0; index < S; index++) {
        for (int inner_index = 0; inner_index < S; inner_index++)
            putchar(maze[index][inner_index] == 1   ? '#'
                    : maze[index][inner_index] == 2 ? '*'
                                                    : '.');
        putchar('\n');
    }
    FILE *svg_file = fopen("maze.svg", "w");
    if (svg_file) {
        fprintf(svg_file,
                "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"400\" height=\"400\"><rect "
                "width=\"400\" height=\"400\" fill=\"white\"/>");
        for (int index = 0; index < S; index++)
            for (int inner_index = 0; inner_index < S; inner_index++)
                if (maze[index][inner_index] == 1)
                    fprintf(svg_file,
                            "<rect x=\"%d\" y=\"%d\" width=\"50\" "
                            "height=\"50\" fill=\"#333\"/>",
                            inner_index * 50,
                            index * 50);
        for (int index = 0; index < path_length; index++)
            fprintf(svg_file,
                    "<circle cx=\"%d\" cy=\"%d\" r=\"12\" fill=\"#e33\"/>",
                    path_columns[index] * 50 + 25,
                    path_rows[index] * 50 + 25);
        for (int index = 0; index <= S; index++)
            fprintf(svg_file,
                    "<path d=\"M0 %dH400 M%d 0V400\" stroke=\"#aaa\"/>",
                    index * 50,
                    index * 50);
        fprintf(svg_file, "</svg>");
        fclose(svg_file);
        puts("另存路徑圖：maze.svg");
    }
    return 0;
}
