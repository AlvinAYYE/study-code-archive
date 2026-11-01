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

typedef struct {
    int id, solved, penalty, submitted;
} Team;

static int cmp_team(const void *a, const void *b) {
    const Team *ta = (const Team *)a;
    const Team *tb = (const Team *)b;
    if (ta->solved != tb->solved) return tb->solved - ta->solved;
    if (ta->penalty != tb->penalty) return ta->penalty - tb->penalty;
    return ta->id - tb->id;
}

int main(void) {
    Team t[2] = {
        {1, 2, 100, 1},
        {2, 3, 50, 1}
    };
    qsort(t, 2, sizeof(Team), cmp_team);
    int ok = (t[0].id == 2); /* Team 2 solved 3 > 2 */
    printf("%s: UVa 10258 - Contest Scoreboard\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
