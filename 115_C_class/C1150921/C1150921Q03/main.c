/* Problem C1150921Q03: Bitwise Operators
 *
 * Input:
 * The input is an integer number.
 *
 * Output:
 * Show the result of each operations.
 */
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int main() {
    int32_t input;
    if (scanf("%d", &input) != 1) return 0;
    uint32_t input_32 = (uint32_t)input;
    int count_one = 0, count_zero = 0;
    for (int i = 31; i >= 0; i--)
    {
        int temp = (input_32 >> i) & 1;
        printf("%u", temp);
        if (temp == 1) count_one++;
        else count_zero++;
    }
    printf("\n");
    printf("Zeros: %d\n", count_zero);
    printf("Ones: %d\n", count_one);
    uint32_t reversd = NULL;
    for (int i = 0; i < 32; i++)
    {
        int temp = (input_32 >> i) & 1;
        reversd <<= 1;
        reversd |= temp;
        printf("%u", temp);
    }
    printf("\n");
    printf("%d", reversd);
    //printf("%u\n", input_32);
    // Write your solution here
    return 0;
}
