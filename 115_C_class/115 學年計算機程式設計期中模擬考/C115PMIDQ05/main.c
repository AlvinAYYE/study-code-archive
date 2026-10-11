/* Problem C115PMIDQ05: Encoding
 *
 * Input:
 * The first line of input is an integer `T (T < 50)` that indicates the number of test cases. Each case is a line consisting of a decoded string. The string will contain only letters `[A-Z]`. Every inputted string will be valid. That is, every letter will be followed by another same or different letter. You may assume the decoded string won't have a length greater than 200 and it will only consist of upper-case alphabets.
 *
 * Output:
 * For each case, output the case number followed by the encoded string. In each encoded string, every letter will be followed by 1 or more digits as the number of repeated letters. Adhere to the sample for exact format.
 */
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Write your solution here
    int input_count = 0;
    if (scanf("%d", &input_count) == -1 )
    {
        return 0;
    }
    for (int i = 0; i < input_count; i++)
    {
        char string[300];
        if (scanf("%200s", &string) != 1)
        {
            return 0;
        } 
        printf("Case %i: ",i + 1);
        int index , window;
        for (index = 0; index < strlen(string); index += window)
        {
            char temp_char = string[index];
            window = 1;
            while (index + window < strlen(string)) {
                if (string[index + window] != temp_char)
                {
                    break;
                }
                window++;
            }
            printf("%c%i", string[index], window);

        }
        if (i + 1 < input_count)
        {
            printf("\n");
        }
    }
    return 0;
}
