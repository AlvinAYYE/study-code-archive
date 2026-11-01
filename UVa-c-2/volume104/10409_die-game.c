/*
 * ==========================================================================
 * UVa 10409 - Die Game
 * Title-CN: 擲骰子遊戲
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: simulation
 * URL: https://onlinejudge.org/external/104/10409.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate rolling a 6-sided die in 4 directions, output top face.
 *
 * [中文] 題目說明:
 *     模擬骰子往東西南北滾動，求最後頂面的點數。
 *
 * [EN] Approach: Maintain 6 faces, update on each direction roll.
 * [中文] 思路: 滾動時交換對應四個面的數值。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

typedef struct {
    int top, bottom, north, south, east, west;
} Die;

void roll_north(Die *d) {
    int t = d->top;
    d->top = d->south;
    d->south = d->bottom;
    d->bottom = d->north;
    d->north = t;
}

void roll_south(Die *d) {
    int t = d->top;
    d->top = d->north;
    d->north = d->bottom;
    d->bottom = d->south;
    d->south = t;
}

void roll_east(Die *d) {
    int t = d->top;
    d->top = d->west;
    d->west = d->bottom;
    d->bottom = d->east;
    d->east = t;
}

void roll_west(Die *d) {
    int t = d->top;
    d->top = d->east;
    d->east = d->bottom;
    d->bottom = d->west;
    d->west = t;
}

int main(void) {
    Die d = {1, 6, 2, 5, 4, 3};
    roll_north(&d);
    roll_south(&d);
    roll_east(&d);
    int ok = (d.top == 3);
    printf("%s: UVa 10409 - Die Game\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
