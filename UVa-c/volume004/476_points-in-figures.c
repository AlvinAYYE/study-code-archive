/*
 * ==========================================================================
 * UVa 476 - Points in Figures: Rectangles
 * Title-CN: 點與圖形：矩形
 * Difficulty: UVa Star 1
 * Tags: geometry, point-in-rectangle
 * ==========================================================================
 * [EN] Problem: Report every input rectangle that strictly contains each query point.
 * [中文] 題目說明: 依輸入順序判斷每個查詢點位於哪些矩形內部；落在邊界上的點不算在內。
 * [EN] Approach: Test the strict inequalities left < x < right and bottom < y < top.
 * [中文] 思路: 對每個點逐一檢查所有矩形，使用四個嚴格不等式排除邊界上的點。
 * ==========================================================================
 */
#include <stdio.h>

#define MAX_RECTANGLES 10

typedef struct {
    double left;
    double top;
    double right;
    double bottom;
} Rectangle;

static int contains_point(const Rectangle *rectangle, double x, double y) {
    return x > rectangle->left && x < rectangle->right
        && y < rectangle->top && y > rectangle->bottom;
}

void solve_uva476(FILE *in, FILE *out) {
    Rectangle rectangles[MAX_RECTANGLES];
    int rectangle_count = 0;
    char figure_type;
    double x;
    double y;
    int point_number = 1;

    while (fscanf(in, " %c", &figure_type) == 1 && figure_type != '*') {
        Rectangle rectangle;
        if (fscanf(in, "%lf %lf %lf %lf", &rectangle.left, &rectangle.top,
                   &rectangle.right, &rectangle.bottom) != 4) {
            return;
        }
        if (figure_type == 'r' && rectangle_count < MAX_RECTANGLES) {
            rectangles[rectangle_count++] = rectangle;
        }
    }

    while (fscanf(in, "%lf %lf", &x, &y) == 2) {
        int contained = 0;
        int i;

        if (x == 9999.9 && y == 9999.9) {
            break;
        }
        for (i = 0; i < rectangle_count; i++) {
            if (contains_point(&rectangles[i], x, y)) {
                fprintf(out, "Point %d is contained in figure %d\n", point_number, i + 1);
                contained = 1;
            }
        }
        if (!contained) {
            fprintf(out, "Point %d is not contained in any figure\n", point_number);
        }
        point_number++;
    }
}

int main(void) {
    solve_uva476(stdin, stdout);
    return 0;
}
