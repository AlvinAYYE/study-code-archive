/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】把一個小矩陣（卷積核心）逐格放到輸入影像上，相乘後加總，得到新的影像矩陣。這是
 * GUI 版的命令列替代呈現。 【輸入】先輸入高度 H、寬度 W，再輸入 H×W 個像素；接著輸入奇數核心大小
 * K，再輸入 K×K 個核心值。核心不能比影像大。 【閱讀順序】1. 讀進影像和核心。2. 每次選一個 K×K
 * 視窗，把核心上下左右翻轉後逐格相乘、累加。3. 輸出有效範圍內的結果矩陣。4. 另寫出
 * convolution.pgm；PGM 是簡單的灰階影像格式，數值會限制在 0 到 255。 【C 語法】二維陣列
 * image_pixels[row][column] 用列、欄記錄像素；巢狀 for 迴圈就是「每一列中再逐欄處理」。fopen
 * 開檔，fprintf 寫入檔案，fclose 關檔。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 輸入 H W、H*W 個像素、奇數 K、K*K 核心；輸出 valid convolution 矩陣及 convolution.pgm。 */
#include <stdio.h>
#include <stdlib.h>
#define LIM 512

static int image_pixels[LIM][LIM];
static int kernel[31][31];
static long long result_pixels[LIM][LIM];

int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    int height, width, kernel_size;
    if (scanf("%d%d", &height, &width) != 2 || height < 1 || width < 1 || height > LIM ||
        width > LIM)
        return 1;

    for (int row = 0; row < height; row++)
        for (int column = 0; column < width; column++)
            if (scanf("%d", &image_pixels[row][column]) != 1)
                return 1;

    if (scanf("%d", &kernel_size) != 1 || kernel_size < 1 || kernel_size > 31 ||
        kernel_size % 2 == 0 || kernel_size > height || kernel_size > width)
        return 1;

    for (int row = 0; row < kernel_size; row++)
        for (int column = 0; column < kernel_size; column++)
            if (scanf("%d", &kernel[row][column]) != 1)
                return 1;

    int output_height = height - kernel_size + 1;
    int output_width = width - kernel_size + 1;
    for (int row = 0; row < output_height; row++) {
        for (int column = 0; column < output_width; column++) {
            long long pixel_sum = 0;
            for (int kernel_row = 0; kernel_row < kernel_size; kernel_row++)
                for (int kernel_column = 0; kernel_column < kernel_size; kernel_column++)
                    pixel_sum +=
                        (long long)image_pixels[row + kernel_row][column + kernel_column] *
                        kernel[kernel_size - 1 - kernel_row][kernel_size - 1 - kernel_column];
            result_pixels[row][column] = pixel_sum;
        }
    }

    puts("卷積結果矩陣:");
    for (int row = 0; row < output_height; row++) {
        for (int column = 0; column < output_width; column++)
            printf("%lld%c", result_pixels[row][column], column + 1 == output_width ? '\n' : ' ');
    }

    FILE *output_file = fopen("convolution.pgm", "w");
    if (output_file) {
        fprintf(output_file, "P2\n%d %d\n255\n", output_width, output_height);
        for (int row = 0; row < output_height; row++) {
            for (int column = 0; column < output_width; column++) {
                long long pixel_value = result_pixels[row][column];
                if (pixel_value < 0)
                    pixel_value = 0;
                if (pixel_value > 255)
                    pixel_value = 255;
                fprintf(
                    output_file, "%lld%c", pixel_value, column + 1 == output_width ? '\n' : ' ');
            }
        }
        fclose(output_file);
        puts("另存灰階影像：convolution.pgm");
    }
    return 0;
}
