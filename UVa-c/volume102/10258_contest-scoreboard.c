/*
 * ==========================================================================
 * UVa 10258 - Contest Scoreboard
 * Title-CN: ACM 競賽計分板排序
 * Difficulty: UVa Star 1
 * Tags: sorting, simulation
 * URL: https://onlinejudge.org/external/102/10258.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate ACM-ICPC submission scoreboard. Sort by: problems solved desc, penalty asc, team ID asc.
 *
 * [中文] 題目說明:
 *     模擬 ACM-ICPC 競賽計分板：按解題數降序、罰時升序、隊伍編號升序排序。
 *
 * [EN] Approach:
 *     Track penalty and solved status per problem per team. Sort with custom qsort comparator.
 * [中文] 思路:
 *     維護每隊各題解題狀態與罰時，qsort 多欄位排序。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id, solved, penalty, submitted;
    int solved_problem[10];
    int incorrect[10];
} Team;

static int cmp_team(const void *a, const void *b) {
    const Team *ta = (const Team *)a;
    const Team *tb = (const Team *)b;
    if (ta->solved != tb->solved) return tb->solved - ta->solved;
    if (ta->penalty != tb->penalty) return ta->penalty - tb->penalty;
    return ta->id - tb->id;
}

static int is_blank(const char *line) {
    return line[0] == '\n' || line[0] == '\r' || line[0] == '\0';
}

int solve(FILE *in, FILE *out) {
    char line[256];
    int test_cases;
    int case_number;

    if (fgets(line, sizeof(line), in) == NULL) return 0;
    test_cases = atoi(line);

    for (case_number = 0; case_number < test_cases; ++case_number) {
        Team teams[101] = {{0}};
        Team ranking[100];
        int ranking_count = 0;
        int i;

        while (fgets(line, sizeof(line), in) != NULL && is_blank(line)) {
            /* Skip separators before this case. */
        }
        if (!is_blank(line)) {
            for (;;) {
                int contestant;
                int problem;
                int time;
                char status;
                if (sscanf(line, "%d %d %d %c", &contestant, &problem,
                           &time, &status) == 4) {
                    Team *team = &teams[contestant];
                    team->id = contestant;
                    team->submitted = 1;
                    if (status == 'C' && !team->solved_problem[problem]) {
                        team->solved_problem[problem] = 1;
                        ++team->solved;
                        team->penalty += time + 20 * team->incorrect[problem];
                    } else if (status == 'I' && !team->solved_problem[problem]) {
                        ++team->incorrect[problem];
                    }
                }
                if (fgets(line, sizeof(line), in) == NULL || is_blank(line)) break;
            }
        }

        for (i = 1; i <= 100; ++i) {
            if (teams[i].submitted) ranking[ranking_count++] = teams[i];
        }
        qsort(ranking, (size_t)ranking_count, sizeof(*ranking), cmp_team);
        for (i = 0; i < ranking_count; ++i) {
            fprintf(out, "%d %d %d\n", ranking[i].id,
                    ranking[i].solved, ranking[i].penalty);
        }
        if (case_number + 1 < test_cases) fputc('\n', out);
    }
    return 0;
}

int main(void) {
    return solve(stdin, stdout);
}
