/* Problem C115MID01Q02: Maximum Nesting Depth
 *
 * Input:
 * The input is a single line containing the string. Its length is between $2$ and $200$ characters, it contains only `(` and `)`, and it is balanced. There are no spaces in the line.
 *
 * Output:
 * Print the maximum nesting depth of the string on a single line.
 *
 * **Do not print a newline (`\n`) after the last line of output.** An extra newline at the end is judged as a Presentation Error (PE).
 */
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>

int main() {
    char line[65536];
    while (fgets(line, sizeof line, stdin) != NULL) {
        int unmatched_open = 0;
        int matched_length = 0;
        int max = 0;
        size_t len = strcspn(line, "\r\n");
        for (size_t i = 0; i < len; ++i) {
            if (line[i] == '(') {
                ++unmatched_open;
            }
            else if (line[i] == ')' && unmatched_open > 0) {
                if (max < unmatched_open)
                {
                    max = unmatched_open;
                }
                --unmatched_open;
                matched_length += 2;
            }
        }
        if (max < unmatched_open)
        {
            max = unmatched_open;
        }
        printf("%d", max);
    }
    return 0;
}
