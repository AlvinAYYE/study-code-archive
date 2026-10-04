#include <stdio.h>
#include <string.h>

/* Count the total length of greedily matched parentheses in each input line.
 * This is the behavior of the PHP solution; it is not a longest-substring DP.
 */
int main(void)
{
    char line[65536];
    while (fgets(line, sizeof line, stdin) != NULL) {
        int unmatched_open = 0;
        int matched_length = 0;
        size_t len = strcspn(line, "\r\n");
        for (size_t i = 0; i < len; ++i) {
            if (line[i] == '(') {
                ++unmatched_open;
            } else if (line[i] == ')' && unmatched_open > 0) {
                --unmatched_open;
                matched_length += 2;
            }
        }
        printf("%d\n", matched_length);
    }
    return 0;
}
