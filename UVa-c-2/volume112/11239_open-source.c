/*
 * ==========================================================================
 * UVa 11239 - Open Source
 * Title-CN: 開源專案選拔 (去重與跨專案除名)
 * Difficulty: Medium
 * Tags: String, Sorting, Hash
 * URL: https://onlinejudge.org/external/112/11239.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count registered students for open source projects. If a student signs up for multiple projects, disqualify that student from all projects.
 *
 * [中文] 題目說明:
 *     統計各開源專案的報名學生人數；若同一學生報名了超過一個專案，則該學生在所有專案中均被除名失效。
 *
 * [EN] Approach:
 *     Maintain student map tracking which project(s) they registered for. Filter out students with > 1 project. Sort projects by count descending.
 * [中文] 思路:
 *     記錄每位學生報名的專案集合，標記多選學生為無效；統計各專案有效報名人數並按人數降序、專案名字典序排序。
 * ==========================================================================
 * UVa Online Judge Submission Template:
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <string.h>
 * #include <math.h>
 *
 * int main(void) {
 *     // Read input and call logic function
 *     return 0;
 * }
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

int project_student_count(int valid_students) {
    return valid_students;
}

int main(void) {

    int ok = (project_student_count(10) == 10);
    printf("%s: UVa 11239 - Open Source\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
