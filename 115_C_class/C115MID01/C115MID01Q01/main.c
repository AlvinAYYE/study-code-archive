/* Problem C115MID01Q01: Clock Hands
 *
 * Input:
 * The input contains several times, one per line, in the format `H:M`, where $1 \le H \le 12$ and $0 \le M \le 59$. $H$ has one or two digits, and $M$ always has exactly two digits.
 *
 * The line `0:00` marks the end of the input and must not be processed.
 *
 * Output:
 * For each time, print the angle in degrees between the hour hand and the minute hand on its own line. The angle is between $0$ and $180$ inclusive and must be printed with exactly three digits after the decimal point.
 *
 * **Do not print a newline (`\n`) after the last line of output.** An extra newline at the end is judged as a Presentation Error (PE).
 */
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
int main() {
	double h_d = 0.0, min_d = 0.0;
	int h = 0, min = 0, h_to_six[6] = {0,5,4,3,2,1},f = 1;
	
	while (scanf("%d:%d", &h, &min) != -1) {

		if (h < 1 || h > 12)
		{
			return 0;
		}
		if ((h == 0 && min == 0) || min >= 60 || min < 0 )
		{
			return 0;
		}
		
		h_d = h * 30 + min * 0.5;
		min_d = min *  6;
		float ans = fabs(h_d - min_d);
		if (ans >= 180.0)
		{
			ans = fabs(360 - ans) ;
		}
		if (f != 1)
		{
			printf("\n");
		}
		f = 0;
		printf("%.3f", ans);
		//printf("\n%.3f", ((h - min) * 0.5) - 180.0);
		f = 0;
	}
    return 0;
}
