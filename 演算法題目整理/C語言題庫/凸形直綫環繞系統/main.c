/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】原介面畫出多個矩形並呈現外框；這版讓使用者輸入矩形，計算所有矩形角點的凸包，並產生
 * hull.svg 離線圖。 【輸入】矩形數量 n，之後每個矩形輸入左下角
 * x、y、寬、高。程式最多接受 1000 個矩形。 【閱讀順序】1.
 * 每個矩形轉成四個角點。2. qsort 依 x、y 排序角點。3. cross
 * 計算三點轉向；若新點讓外框向內凹，就移除上一個邊界點。4.
 * 分別建立下半部與上半部，合起來形成凸包。5. 印出頂點座標並寫 SVG 多邊形。 【C 語法】P 是含
 * x、y 的結構；qsort 是標準函式庫排序函式，必須提供 cmp
 * 比較函式；h[] 用來依序存凸包點。SVG 是文字格式圖檔，可離線用瀏覽器開啟。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 命令列替代繪圖介面。輸入 n 個矩形 x y 寬
 * 高；列出四角的凸包並輸出 hull.svg。 */
#include <stdio.h>
#include <stdlib.h>
#define N 4000
typedef struct {
    double x_coordinate, y_coordinate;
} Point;
int cmp(const void *first_point, const void *second_point) {
    Point *points = (Point *)first_point, *right_point = (Point *)second_point;
    if (points->x_coordinate < right_point->x_coordinate)
        return -1;
    if (points->x_coordinate > right_point->x_coordinate)
        return 1;
    return (points->y_coordinate > right_point->y_coordinate) -
           (points->y_coordinate < right_point->y_coordinate);
}
double cross(Point first_point, Point second_point, Point third_point) {
    return (second_point.x_coordinate - first_point.x_coordinate) *
               (third_point.y_coordinate - first_point.y_coordinate) -
           (second_point.y_coordinate - first_point.y_coordinate) *
               (third_point.x_coordinate - first_point.x_coordinate);
}
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    int rectangle_count;
    Point points[N], hull_points[2 * N];
    if (scanf("%d", &rectangle_count) != 1 || rectangle_count < 1 || rectangle_count > 1000)
        return 1;
    for (int index = 0; index < rectangle_count; index++) {
        double x_coordinate, y_coordinate, rectangle_width, rectangle_height;
        if (scanf("%lf%lf%lf%lf",
                  &x_coordinate,
                  &y_coordinate,
                  &rectangle_width,
                  &rectangle_height) != 4)
            return 1;
        points[4 * index] = (Point){x_coordinate, y_coordinate};
        points[4 * index + 1] = (Point){x_coordinate + rectangle_width, y_coordinate};
        points[4 * index + 2] =
            (Point){x_coordinate + rectangle_width, y_coordinate + rectangle_height};
        points[4 * index + 3] = (Point){x_coordinate, y_coordinate + rectangle_height};
    }
    int point_count = 4 * rectangle_count;
    qsort(points, point_count, sizeof(Point), cmp);
    int hull_vertex_count = 0;
    for (int index = 0; index < point_count; index++) {
        while (hull_vertex_count >= 2 && cross(hull_points[hull_vertex_count - 2],
                                               hull_points[hull_vertex_count - 1],
                                               points[index]) <= 0)
            hull_vertex_count--;
        hull_points[hull_vertex_count++] = points[index];
    }
    int lower_hull_size = hull_vertex_count;
    for (int index = point_count - 2; index >= 0; index--) {
        while (hull_vertex_count > lower_hull_size && cross(hull_points[hull_vertex_count - 2],
                                                            hull_points[hull_vertex_count - 1],
                                                            points[index]) <= 0)
            hull_vertex_count--;
        hull_points[hull_vertex_count++] = points[index];
    }
    if (hull_vertex_count > 1)
        hull_vertex_count--;
    puts("凸包頂點（逆時針）:");
    for (int index = 0; index < hull_vertex_count; index++)
        printf("%.3f %.3f\n", hull_points[index].x_coordinate, hull_points[index].y_coordinate);
    FILE *svg_file = fopen("hull.svg", "w");
    if (svg_file) {
        fprintf(svg_file,
                "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"800\" height=\"600\"><rect "
                "width=\"100%%\" height=\"100%%\" fill=\"white\"/><polygon fill=\"#eaf4ff\" "
                "stroke=\"#d22\" stroke-width=\"3\" points=\"");
        double xmin = hull_points[0].x_coordinate, xmax = xmin, ymin = hull_points[0].y_coordinate,
               ymax = ymin;
        for (int index = 1; index < hull_vertex_count; index++) {
            if (hull_points[index].x_coordinate < xmin)
                xmin = hull_points[index].x_coordinate;
            if (hull_points[index].x_coordinate > xmax)
                xmax = hull_points[index].x_coordinate;
            if (hull_points[index].y_coordinate < ymin)
                ymin = hull_points[index].y_coordinate;
            if (hull_points[index].y_coordinate > ymax)
                ymax = hull_points[index].y_coordinate;
        }
        for (int index = 0; index < hull_vertex_count; index++)
            fprintf(svg_file,
                    "%.1f,%.1f ",
                    20 + (hull_points[index].x_coordinate - xmin) * 740 / (xmax - xmin + 1e-9),
                    580 - (hull_points[index].y_coordinate - ymin) * 560 / (ymax - ymin + 1e-9));
        fprintf(svg_file, "\"/></svg>\n");
        fclose(svg_file);
        puts("另存凸包圖：hull.svg");
    }
    return 0;
}
