/*
 * ==========================================================================
 * UVa 10281 - Average Speed
 * Title-CN: 平均速度與總里程計算
 * Difficulty: UVa Star 1
 * Tags: simulation, math
 * ==========================================================================
 * [EN] Problem: Track accumulated distance under changing speeds.
 * [中文] 題目說明: 追蹤變速行駛下的累積總里程。
 * [EN] Approach: Dist += current_speed * (time_now - time_last).
 * [中文] 思路: 時間差乘上當前車速累積總里程。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

int solve(FILE *in, FILE *out) {
    char line[256];
    double distance = 0.0;
    double speed = 0.0;
    int previous_time = 0;

    while (fgets(line, sizeof(line), in) != NULL) {
        int hour;
        int minute;
        int second;
        int next_speed;
        int fields = sscanf(line, "%d:%d:%d %d", &hour, &minute, &second, &next_speed);
        int current_time;

        if (fields < 3) continue;
        current_time = hour * 3600 + minute * 60 + second;
        distance += speed * (double)(current_time - previous_time) / 3600.0;
        previous_time = current_time;

        if (fields == 4) {
            speed = (double)next_speed;
        } else {
            fprintf(out, "%02d:%02d:%02d %.2f km\n",
                    hour, minute, second, distance);
        }
    }
    return 0;
}

int main(void) {
    return solve(stdin, stdout);
}
