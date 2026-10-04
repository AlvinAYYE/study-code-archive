/* Problem C1150921Q06: Digit Frequency
 *
 * Input:
 * The input file consists of several data sets. The first line of the input file contains the number of data sets which is a positive integer and is not bigger than 20. The following lines describe the data sets. For each test case, there is one single line containing the number `N`.
 *
 * Output:
 * For each test case, write sequentially in one line the number of digit `0`, `1`, ... `9` separated by a space.
 */
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
    int test_cases;
    scanf("%d", &test_cases);

    while (test_cases--)
    {
        int number;
        int digit_count[10] = {0};

        scanf("%d", &number);

        for (int current_number = 1; current_number <= number; current_number++)
        {
            int value = current_number;

            while (value > 0)
            {
                int digit = value % 10;
                digit_count[digit]++;
                value /= 10;
            }
        }

        for (int digit = 0; digit < 10; digit++)
        {
            if (digit > 0)
                printf(" ");

            printf("%d", digit_count[digit]);
        }

        if (test_cases >= 1)
        {
            printf("\n");
        } 
    }

    return 0;
}