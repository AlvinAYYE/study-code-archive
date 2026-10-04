#include <stdio.h>
#include <string.h>

/* Convert one Roman numeral per input line using the next-symbol rule. */
static int value(char c)
{
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int main(void)
{
    char line[4096];
    while (fgets(line, sizeof line, stdin) != NULL) {
        size_t len = strcspn(line, "\r\n");
        int total = 0;
        for (size_t i = 0; i < len; ++i) {
            int current = value(line[i]);
            int next = (i + 1 < len) ? value(line[i + 1]) : 0;
            total += current < next ? -current : current;
        }
        printf("%d\n", total);
    }
    return 0;
}
