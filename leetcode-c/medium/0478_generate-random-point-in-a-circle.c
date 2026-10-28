/*
 * Title-CN: 在圓內隨機生成點
 * LeetCode 478. Generate Random Point in a Circle
 *
 * 題意翻譯：設計一個隨機點產生器。建立時給定圓的半徑與圓心座標；每次呼叫
 * 時，回傳圓內（包含圓周上）均勻隨機的一個點 [x, y]。
 *
 * 範例：半徑 1、圓心 (0,0) 時，可能回傳 [0.2,-0.3]；每個圓內等面積區域
 * 被抽中的機率相同。
 *
 * 限制：0 < radius <= 10^8；圓心座標絕對值不超過 10^7；呼叫次數不超過 3*10^4。
 *
 * 解題思路：在正方形 [-1,1] x [-1,1] 中均勻抽一點，若它到原點距離平方大於 1，
 * 就重抽；接受後將座標乘上半徑並平移到圓心。均勻抽正方形再條件式保留圓內點，
 * 圓內各處仍均勻，而且不會像「先均勻抽半徑」那樣讓中心過度密集。
 *
 * 複雜度：每次抽樣平均 O(1)（接受率為 π/4）；額外空間 O(1)。
 * LeetCode 介面：保留 solutionCreate、solutionRandPoint、solutionFree；main() 僅供本機測試。
 */

#include <assert.h>
#include <math.h>
#include <stdlib.h>

struct Solution {
    double radius;
    double centerX;
    double centerY;
};

struct Solution *solutionCreate(double radius, double x_center, double y_center) {
    struct Solution *solution = malloc(sizeof(*solution));
    if (solution == NULL) return NULL;
    solution->radius = radius;
    solution->centerX = x_center;
    solution->centerY = y_center;
    return solution;
}

double *solutionRandPoint(struct Solution *solution) {
    double x;
    double y;
    do {
        x = 2.0 * rand() / ((double)RAND_MAX + 1.0) - 1.0;
        y = 2.0 * rand() / ((double)RAND_MAX + 1.0) - 1.0;
    } while (x * x + y * y > 1.0);

    double *point = malloc(2 * sizeof(*point));
    if (point == NULL) return NULL;
    point[0] = solution->centerX + solution->radius * x;
    point[1] = solution->centerY + solution->radius * y;
    return point;
}

void solutionFree(struct Solution *solution) {
    free(solution);
}

int main(void) {
    srand(7);
    struct Solution *solution = solutionCreate(3.0, -2.0, 5.0);
    assert(solution != NULL);
    for (int i = 0; i < 1000; ++i) {
        double *point = solutionRandPoint(solution);
        assert(point != NULL);
        double dx = point[0] + 2.0;
        double dy = point[1] - 5.0;
        assert(dx * dx + dy * dy <= 9.0 + 1e-12);
        free(point);
    }
    solutionFree(solution);
    return 0;
}
