/* Problem C1150928Q01: Bubble Sort
 *
 * Input:
 * The first line of input is an integer `N (N <= 100)` that indicates the size of the sequence. Then, the next line will be followed by a sequence of integers separated by spaces.
 *
 * Output:
 * The output should show the sorted integer sequence.
 */
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Write your solution here
	int array_count = 0, numbers[100] = {0};
	if (scanf("%d",&array_count) == -1 || array_count > 100)
	{
		return 0;
	}
	for (int i = 0; i < array_count; i++)
	{
		if (scanf("%d", &numbers[i]) != 1)
		{
			return 0;
		}
	}
	for (int i = 0; i < array_count - 1; i++)
	{
		for (int e = 0; e < array_count - 1 - i; e++)
		{
			if (numbers[e] > numbers[e + 1])
			{
				int temp = numbers[e];
				numbers[e] = numbers[e + 1];
				numbers[e + 1] = temp;
			}
		}
	}
	for (int e = 0; e < array_count; e++)
	{
		printf("%d", numbers[e]);
		if (e + 1 < array_count)
		{
			printf(" ");
		}
	}
	return 0;
}
