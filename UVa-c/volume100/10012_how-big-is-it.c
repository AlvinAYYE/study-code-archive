/*
 * ==========================================================================
 * UVa 10012 - How Big Is It?
 * Title-CN: 圓形排列最小外接矩形寬度
 * Difficulty: UVa Star 2
 * Tags: geometry, backtracking, math
 * ==========================================================================
 * [EN] Problem: Given n circles, order them on a line to minimize horizontal enclosing box width.
 * [中文] 題目說明: 將 n 個不同半徑的圓放在水平線上相切排列，求最小的外接矩形寬度。
 * [EN] Approach: Backtracking permutation (n <= 8). Position x_i = max(r_i, max_j(x_j + 2*sqrt(r_i * r_j))).
 * [中文] 思路: 回溯枚舉圓的排列，相切圓中心距離為 2*sqrt(r_i*r_j)。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>
#include <float.h>

static inline double max_d(double a, double b) { return a > b ? a : b; }

double calc_width(int n, const double *r) {
    double x[10];
    for (int i = 0; i < n; i++) {
        x[i] = 0.0;
        for (int j = 0; j < i; j++) {
            double cand = x[j] + 2.0 * sqrt(r[i] * r[j]);
            x[i] = max_d(x[i], cand);
        }
    }
    double min_x = 1e9, max_x = -1e9;
    for (int i = 0; i < n; i++) {
        min_x = fmin(min_x, x[i] - r[i]);
        max_x = max_d(max_x, x[i] + r[i]);
    }
    return max_x - min_x;
}

typedef struct {
    int n;
    double radius[8];
    double order[8];
    int used[8];
    double best;
} SearchState;

static void search_orders(SearchState *state, int depth) {
    if (depth == state->n) {
        double width = calc_width(state->n, state->order);
        if (width < state->best) {
            state->best = width;
        }
        return;
    }

    for (int i = 0; i < state->n; ++i) {
        int duplicate = 0;

        if (state->used[i]) {
            continue;
        }
        for (int j = 0; j < i; ++j) {
            if (!state->used[j] && fabs(state->radius[i] - state->radius[j]) < 1e-12) {
                duplicate = 1;
                break;
            }
        }
        if (duplicate) {
            continue;
        }

        state->used[i] = 1;
        state->order[depth] = state->radius[i];
        search_orders(state, depth + 1);
        state->used[i] = 0;
    }
}

double solve_uva10012(int n, const double *radii) {
    SearchState state = {0};

    state.n = n;
    state.best = DBL_MAX;
    for (int i = 0; i < n; ++i) {
        state.radius[i] = radii[i];
    }
    search_orders(&state, 0);
    return state.best;
}

int main(void) {
    int cases;

    if (scanf("%d", &cases) != 1) {
        return 0;
    }
    while (cases-- > 0) {
        int n;
        double radii[8];

        if (scanf("%d", &n) != 1) {
            return 0;
        }
        for (int i = 0; i < n; ++i) {
            (void)scanf("%lf", &radii[i]);
        }
        printf("%.3f\n", solve_uva10012(n, radii));
    }
    return 0;
}
