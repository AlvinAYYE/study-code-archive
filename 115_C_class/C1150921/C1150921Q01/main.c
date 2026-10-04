/* Problem C1150921Q01: Draw a Diamond
 *
 * Input:
 * The only input is an integer `L (2 < L < 50)` that indicates how many top layers (half of the diamond) there are.
 *
 * Output:
 * With the given number of top layers, print the top and bottom parts to complete a full diamond with '`*`' symbols. Note that no additional spaces should be added after the last '`*`' symbol.
 */
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//int main() {
//	int input;
//	if (!scanf("%d",&input)) return 0;
//	for (int i = 1; i < input; i++)
//	{
//		char string[999] = "*";
//		char string_right[999] = "";
//		for (int e = 1; e < i; e++)
//		{
//			strcat(string, "*");
//			strcat(string_right, "*");
//		}
//		printf("%*s%s%s\n",input - i,"", string, string_right);
//	}
//	for (int i = input; i > 0; i--)
//	{
//		char string[999] = "*";
//		char string_right[999] = "";
//		for (int e = 1; e < i; e++)
//		{
//			strcat(string, "*");
//			strcat(string_right, "*");
//		}
//		if (i < input)
//		{
//			printf("\n");
//		}
//		printf("%*s%s%s", input - i, "", string, string_right);
//		
//	}
//	return 0;
//}
int main() {
	int input;
	if (scanf("%d", &input) != 1) return 0;
	for (int i = 1; i <= input * 2 - 1; i++)
	{	
		int length = input - abs(input - i);
		printf("%*s", input - i,"");
		for (int e = 0; e <2 * length - 1; e++)
		{
			printf("*");
		}
		if (i < input * 2 - 1)
		{
			printf("\n");
		} 
	}
}
