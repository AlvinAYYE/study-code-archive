/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】模擬 Conway 生命遊戲。每格不是活著就是死亡；每一代依周圍 8
 * 格的活細胞數，同時更新全盤。 【輸入】列數、欄數、演化代數，接著輸入以 #（活）和
 * .（死）表示的初始格。邊界外視為死亡。【輸出】每一代文字盤面，並把最後一代存成 life.svg。
 * 【規則】死格周圍恰有 3 個活格時復活；活格周圍有 2 或 3 個活格時存活；其他情況死亡。
 * 【閱讀順序】先讀入 a。每一代先依 a 計算所有格子的下一代並放入
 * b，不能直接改 a，否則後算的格子會讀到新一代資料。整盤算完後才把 b
 * 複製回 a。 【C 語法】a、b 是兩個二維字元陣列；dx、dy
 * 枚舉鄰居的水平、垂直偏移；輸出 SVG 時用矩形代表每個活格。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 輸入 rows cols g，再輸入以 . 和 # 表示的格子；輸出各代文字盤面及最後的 life.svg。 */
#include <stdio.h>
#define M 200
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    int height, width, generations;
    char current_grid[M][M], next_grid[M][M];
    if (scanf("%d%d%d", &height, &width, &generations) != 3 || height < 1 || width < 1 ||
        height > M || width > M || generations < 0)
        return 1;
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++) {
            char cell_character;
            do {
                if (scanf(" %c", &cell_character) != 1)
                    return 1;
            } while (cell_character != '.' && cell_character != '#');
            current_grid[y][x] = cell_character;
        }
    for (int step = 0; step <= generations; step++) {
        printf("Generation %d\n", step);
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++)
                putchar(current_grid[y][x]);
            putchar('\n');
        }
        if (step == generations)
            break;
        for (int y = 0; y < height; y++)
            for (int x = 0; x < width; x++) {
                int neighbor_count = 0;
                for (int dy = -1; dy <= 1; dy++)
                    for (int dx = -1; dx <= 1; dx++)
                        if ((dx || dy) && y + dy >= 0 && y + dy < height && x + dx >= 0 &&
                            x + dx < width && current_grid[y + dy][x + dx] == '#')
                            neighbor_count++;
                next_grid[y][x] =
                    (neighbor_count == 3 || (current_grid[y][x] == '#' && neighbor_count == 2))
                        ? '#'
                        : '.';
            }
        for (int y = 0; y < height; y++)
            for (int x = 0; x < width; x++)
                current_grid[y][x] = next_grid[y][x];
    }
    FILE *svg_file = fopen("life.svg", "w");
    if (svg_file) {
        int cell_size = 12;
        fprintf(svg_file,
                "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%d\" height=\"%d\"><rect "
                "w=\"100%%\" h=\"100%%\" fill=\"white\"/>",
                width * cell_size,
                height * cell_size);
        for (int y = 0; y < height; y++)
            for (int x = 0; x < width; x++)
                if (current_grid[y][x] == '#')
                    fprintf(svg_file,
                            "<rect x=\"%d\" y=\"%d\" w=\"%d\" h=\"%d\" fill=\"#222\"/>",
                            x * cell_size,
                            y * cell_size,
                            cell_size - 1,
                            cell_size - 1);
        fprintf(svg_file, "</svg>");
        fclose(svg_file);
        puts("另存最後一代：life.svg");
    }
    return 0;
}
