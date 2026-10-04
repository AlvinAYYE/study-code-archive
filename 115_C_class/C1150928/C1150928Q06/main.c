/* Problem C1150928Q06: CSV Parser
 *
 * Input:
 * The input consists of at most 200 lines. The first line contains a number `N`, indicating that there will be `N` more lines. Each following line, with at most 75 characters, contains student score records consist of 3 fields, name of a student and 2 scores of English and Math. The maximum length of name is 50, and the scores are all integers.
 *
 * Output:
 * List the name and scores (English and Math) of all students in the following format.
 *
 * ```
 * {name0}: {English0}, {Math0}
 * {name1}: {English1}, {Math1}
 * ...
 * ```
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    char name[51];
    int english;
    int math;
    struct Student* next;
} Student;

int main()
{
    int n;
    scanf("%d", &n);

    Student* head = NULL;
    Student* tail = NULL;

    for (int i = 0; i < n; i++)
    {
        Student* node = malloc(sizeof(Student));

        scanf(" %50[^,],%d,%d",
            node->name,
            &node->english,
            &node->math);

        node->next = NULL;

        if (head == NULL)
            head = node;
        else
            tail->next = node;

        tail = node;
    }

    Student* current = head;

    while (current != NULL)
    {
        printf("%s: %d, %d",
            current->name,
            current->english,
            current->math);

        if (current->next != NULL)
            printf("\n");

        current = current->next;
    }

    return 0;
}