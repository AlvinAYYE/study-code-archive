/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】把灰階影像中值為 0 的黑色像素向周圍擴張一圈。原題用視窗載入圖片；本版用簡單的
 * ASCII PGM 檔案輸入，另輸出 dilated.pgm。 【輸入】一個 PGM P2
 * 格式影像檔；可以把檔名當命令列第一個參數，否則從標準輸入讀。PGM 內容依序是
 * P2、寬、高、最大灰階值和像素值。 【閱讀順序】t 函式跳過空白與 #
 * 註解並讀出下一個欄位。讀入像素後，對每個位置檢查自己及周圍 8
 * 格，只要有一格黑色，輸出位置就設黑色，否則設白色。最後輸出文字格和新的 PGM 檔。 【C
 * 語法】argc、argv 是命令列參數；FILE * 可代表檔案或 stdin；calloc
 * 配置影像記憶體；邊界座標要先檢查，避免讀出陣列外。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* PGM P2 灰階圖命令列版。讀入 ASCII PGM，將黑色像素向 8 鄰域膨脹，輸出 dilated.pgm。 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 2000
static int read_next_token(FILE *image_file, char *token_buffer) {
    int c;
    do {
        c = fgetc(image_file);
        if (c == '#')
            while (c != '\n' && c != EOF)
                c = fgetc(image_file);
    } while (c != EOF && c <= 32);
    if (c == EOF)
        return 0;
    int index = 0;
    do {
        token_buffer[index++] = (char)c;
        c = fgetc(image_file);
    } while (c != EOF && c > 32 && index < 63);
    token_buffer[index] = 0;
    return 1;
}
int main(int argument_count, char **argument_values) {
    char token_buffer[64];
    FILE *image_file = argument_count > 1 ? fopen(argument_values[1], "r") : stdin;
    if (!image_file)
        return 1;
    if (!read_next_token(image_file, token_buffer) || strcmp(token_buffer, "P2"))
        return puts("只支援 ASCII PGM (P2)"), 1;
    read_next_token(image_file, token_buffer);
    int width = atoi(token_buffer);
    read_next_token(image_file, token_buffer);
    int height = atoi(token_buffer);
    read_next_token(image_file, token_buffer);
    int maximum_pixel_value = atoi(token_buffer);
    if (width < 1 || height < 1 || width > M || height > M || maximum_pixel_value < 1)
        return 1;
    int (*source_pixels)[M] = calloc(height, sizeof *source_pixels),
        (*result_pixels)[M] = calloc(height, sizeof *result_pixels);
    if (!source_pixels || !result_pixels)
        return 1;
    for (int row = 0; row < height; row++)
        for (int column = 0; column < width; column++) {
            if (!read_next_token(image_file, token_buffer))
                return 1;
            source_pixels[row][column] = atoi(token_buffer);
        }
    if (image_file != stdin)
        fclose(image_file);
    for (int row = 0; row < height; row++)
        for (int column = 0; column < width; column++) {
            int has_black_neighbor = 0;
            for (int dy = -1; dy <= 1; dy++)
                for (int dx = -1; dx <= 1; dx++) {
                    int neighbor_row = row + dy, neighbor_column = column + dx;
                    if (neighbor_row >= 0 && neighbor_row < height && neighbor_column >= 0 &&
                        neighbor_column < width &&
                        source_pixels[neighbor_row][neighbor_column] == 0)
                        has_black_neighbor = 1;
                }
            result_pixels[row][column] = has_black_neighbor ? 0 : maximum_pixel_value;
        }
    puts("膨脹結果（#=黑，.=白）:");
    for (int row = 0; row < height; row++) {
        for (int column = 0; column < width; column++)
            putchar(result_pixels[row][column] ? '.' : '#');
        putchar('\n');
    }
    image_file = fopen("dilated.pgm", "w");
    if (image_file) {
        fprintf(image_file, "P2\n%d %d\n%d\n", width, height, maximum_pixel_value);
        for (int row = 0; row < height; row++) {
            for (int column = 0; column < width; column++)
                fprintf(image_file,
                        "%d%c",
                        result_pixels[row][column],
                        column + 1 == width ? '\n' : ' ');
        }
        fclose(image_file);
        puts("另存處理後影像：dilated.pgm");
    }
    free(source_pixels);
    free(result_pixels);
    return 0;
}
