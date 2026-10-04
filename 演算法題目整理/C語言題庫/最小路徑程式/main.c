/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】在有數字成本的格子地圖中，從左上走到右下，找總成本最低路徑。由於舊題目規格不完整，本版採用「只能向右或向下」的常見網格路徑定義。
 * 【輸入】高度 H、寬度 W，接著 H×W 個格子的成本。【輸出】用 * 標出最佳路徑，並印出路徑成本總和。
 * 【閱讀順序】dp[i][j] 是走到格子 (i,j)
 * 的最低累計成本。起點成本就是自己的格子值；其他格子只能從上方或左方進入，因此取兩者較小者再加目前格子成本。from
 * 記錄是從哪個方向來，最後從終點倒走回起點並標記路徑。 【C 語法】a[][]、dp[][]、from[][]
 * 是二維陣列；兩層 for 逐格計算；pr、pc 暫存回溯路徑的列、欄座標。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 命令列版：輸入 H W 與權重矩陣，從左上走到右下，只能向右或向下。 */
#include <stdio.h>
#define M 500
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    int height, width;
    static int cost_grid[M][M], previous_step[M][M];
    static long long minimum_cost[M][M];
    if (scanf("%d%d", &height, &width) != 2 || height < 1 || width < 1 || height > M || width > M)
        return 1;
    for (int index = 0; index < height; index++)
        for (int inner_index = 0; inner_index < width; inner_index++)
            if (scanf("%d", &cost_grid[index][inner_index]) != 1)
                return 1;
    for (int index = 0; index < height; index++)
        for (int inner_index = 0; inner_index < width; inner_index++) {
            if (index == 0 && inner_index == 0) {
                minimum_cost[index][inner_index] = cost_grid[index][inner_index];
                previous_step[index][inner_index] = 0;
            } else if (index == 0 ||
                       (inner_index > 0 && minimum_cost[index][inner_index - 1] <=
                                               minimum_cost[index - 1][inner_index])) {
                minimum_cost[index][inner_index] =
                    minimum_cost[index][inner_index - 1] + cost_grid[index][inner_index];
                previous_step[index][inner_index] = 1;
            } else {
                minimum_cost[index][inner_index] =
                    minimum_cost[index - 1][inner_index] + cost_grid[index][inner_index];
                previous_step[index][inner_index] = 2;
            }
        }
    int row = height - 1, column = width - 1, previous_row[M + M], previous_column[M + M],
        path_length = 0;
    while (1) {
        previous_row[path_length] = row;
        previous_column[path_length++] = column;
        if (row == 0 && column == 0)
            break;
        if (previous_step[row][column] == 1)
            column--;
        else
            row--;
    }
    puts("最小路徑（* 標示）:");
    for (int index = 0; index < height; index++) {
        for (int inner_index = 0; inner_index < width; inner_index++) {
            int is_path_cell = 0;
            for (int cell_cost = 0; cell_cost < path_length; cell_cost++)
                if (previous_row[cell_cost] == index && previous_column[cell_cost] == inner_index)
                    is_path_cell = 1;
            printf("%c%4d", is_path_cell ? '*' : ' ', cost_grid[index][inner_index]);
        }
        putchar('\n');
    }
    printf("最小路徑和：%lld\n", minimum_cost[height - 1][width - 1]);
    return 0;
}
