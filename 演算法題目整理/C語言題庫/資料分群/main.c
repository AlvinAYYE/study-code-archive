/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】用 K-means 把平面上的點分成 K
 * 群。原解答有圖形介面；這版改為輸入座標、列出群組，並輸出散佈圖 clusters.svg。 【輸入】先輸入點數
 * N 和群數 K，再輸入 N 組 x、y 座標。限制是 1≤K≤N≤1000。 【閱讀順序】1. 前 K
 * 個點作為初始群中心。2. 對每個點計算它到各中心的平方距離，標記最近中心的群號。3. 將每群點的
 * x、y 分別平均，更新中心。4. 重複分群與更新，直到群號不再改變或做滿 100
 * 輪。5. 印出每點的群號，並寫出 SVG 圖。 【C 語法】Pt 是自訂結構，讓一個變數同時保存
 * x、y；lab[i] 保存第 i 點的群號；雙層大括號初始化陣列為
 * 0。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 命令列 K-means 版本。輸入 N K，再輸入 N 筆 x y；輸出分群並寫 clusters.svg。
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define NMAX 1000
#define KMAX 50
typedef struct {
    double x_coordinate, y_coordinate;
} Pt;
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    int point_count, cluster_count, cluster_labels[NMAX];
    Pt points[NMAX], centers[KMAX];
    if (scanf("%d%d", &point_count, &cluster_count) != 2 || point_count < 1 || point_count > NMAX ||
        cluster_count < 1 || cluster_count > KMAX || cluster_count > point_count)
        return 1;
    for (int index = 0; index < point_count; index++)
        if (scanf("%lf%lf", &points[index].x_coordinate, &points[index].y_coordinate) != 2)
            return 1;
    for (int inner_index = 0; inner_index < cluster_count; inner_index++)
        centers[inner_index] = points[inner_index];
    for (int iteration = 0; iteration < 100; iteration++) {
        int labels_changed = 0;
        double sum_x[KMAX] = {0}, sum_y[KMAX] = {0};
        int cluster_sizes[KMAX] = {0};
        for (int index = 0; index < point_count; index++) {
            int nearest_cluster = 0;
            double nearest_distance = 1e300;
            for (int inner_index = 0; inner_index < cluster_count; inner_index++) {
                double distance_x = points[index].x_coordinate - centers[inner_index].x_coordinate,
                       distance_y = points[index].y_coordinate - centers[inner_index].y_coordinate,
                       squared_distance = distance_x * distance_x + distance_y * distance_y;
                if (squared_distance < nearest_distance) {
                    nearest_distance = squared_distance;
                    nearest_cluster = inner_index;
                }
            }
            if (iteration == 0 || cluster_labels[index] != nearest_cluster) {
                cluster_labels[index] = nearest_cluster;
                labels_changed = 1;
            }
            sum_x[nearest_cluster] += points[index].x_coordinate;
            sum_y[nearest_cluster] += points[index].y_coordinate;
            cluster_sizes[nearest_cluster]++;
        }
        for (int inner_index = 0; inner_index < cluster_count; inner_index++)
            if (cluster_sizes[inner_index]) {
                centers[inner_index].x_coordinate = sum_x[inner_index] / cluster_sizes[inner_index];
                centers[inner_index].y_coordinate = sum_y[inner_index] / cluster_sizes[inner_index];
            }
        if (!labels_changed && iteration > 0)
            break;
    }
    puts("資料點 x y 群組:");
    for (int index = 0; index < point_count; index++)
        printf("%.3f %.3f %d\n",
               points[index].x_coordinate,
               points[index].y_coordinate,
               cluster_labels[index] + 1);
    FILE *svg_file = fopen("clusters.svg", "w");
    if (svg_file) {
        double xmin = points[0].x_coordinate, xmax = xmin, ymin = points[0].y_coordinate,
               ymax = ymin;
        for (int index = 1; index < point_count; index++) {
            if (points[index].x_coordinate < xmin)
                xmin = points[index].x_coordinate;
            if (points[index].x_coordinate > xmax)
                xmax = points[index].x_coordinate;
            if (points[index].y_coordinate < ymin)
                ymin = points[index].y_coordinate;
            if (points[index].y_coordinate > ymax)
                ymax = points[index].y_coordinate;
        }
        double scale_x = 540.0 / (xmax - xmin + 1e-9);
        double scale_y = 540.0 / (ymax - ymin + 1e-9);
        const char *cluster_colors[] = {
            "#e4572e", "#17bebb", "#ffc914", "#2e282a", "#76b041", "#7b2cbf", "#4361ee", "#f72585"};
        fprintf(svg_file,
                "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"600\" height=\"600\"><rect "
                "width=\"100%%\" height=\"100%%\" fill=\"white\"/>\n");
        for (int index = 0; index < point_count; index++)
            fprintf(svg_file,
                    "<circle cx=\"%.1f\" cy=\"%.1f\" r=\"5\" fill=\"%s\"/>\n",
                    30 + (points[index].x_coordinate - xmin) * scale_x,
                    570 - (points[index].y_coordinate - ymin) * scale_y,
                    cluster_colors[cluster_labels[index] % 8]);
        fprintf(svg_file, "</svg>\n");
        fclose(svg_file);
        puts("另存散佈圖：clusters.svg");
    }
    return 0;
}
