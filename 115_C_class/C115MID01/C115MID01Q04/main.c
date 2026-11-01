/* Problem C115MID01Q04: f91
 *
 * Input:
 * The input tests will consist of a series of positive integers, each integer is at most $1\text{,}000\text{,}000$. There will be at most $100$ test cases.
 *
 * Each number is on a line on its own. The end of the input is reached when the number $0$ is met. The number $0$ shall not be considered as part of the test set.
 *
 * Output:
 * For each input number $N$, print one line in the format `f91(N) = M`, where $M$ is the value of $\mathrm{f91}(N)$, as in the sample output.
 *
 * **Do not print a newline (`\n`) after the last line of output.** An extra newline at the end is judged as a Presentation Error (PE).
 */
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>

int f91(int number) {
	if (number <= 100)
	{
		return f91( f91(number + 11));
	}
	else if(number >= 101){
		return number - 10;
	}
}

int main() {
	int input = 0;
	int input_arr[101] = {0};
	int f = 1;
	while (scanf("%d", &input) != -1) {

		if (input == 0 || input >= 1000000)
		{
			return 0;
		}
		if (f != 1)
		{
			printf("\n");
		}
		f = 0;

		printf("f91(%d) = %d", input, f91(input));

	}
	//f91(500) = 490

    
}
