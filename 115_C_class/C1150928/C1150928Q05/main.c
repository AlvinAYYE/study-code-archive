/* Problem C1150928Q05: Valid Palindrome
 *
 * Input:
 * The only input is a string with length $L (1 < L < 10000)$ that contains uppercase letters, lowercase letters and non-alphanumeric characters.
 *
 * Output:
 * According to the given string, print `true` if it is a **palindrome**, or `false` otherwise.
 */
 /* Problem C1150928Q05: Valid Palindrome */

#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char input[10001];

    if (fgets(input, sizeof(input), stdin) == NULL)
    {
        return 0;
    }

    int left = 0;
    int right = (int)strlen(input) - 1;

    while (left < right)
    {
        // 左邊跳過非英數字元
        while (left < right &&
            !isalnum((unsigned char)input[left]))
        {
            left++;
        }

        // 右邊跳過非英數字元
        while (left < right &&
            !isalnum((unsigned char)input[right]))
        {
            right--;
        }

        // 統一轉成小寫再比較
        if (tolower((unsigned char)input[left]) !=
            tolower((unsigned char)input[right]))
        {
            printf("false");
            return 0;
        }

        left++;
        right--;
    }

    printf("true");

    return 0;
}
