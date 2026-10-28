/*
 * Title-CN: 尋找重複檔案
 * LeetCode 609. Find Duplicate File in System
 *
 * 題意翻譯：給定多個目錄描述，每個描述包含目錄路徑及多個「檔名(檔案內容)」。
 * 請將內容完全相同的檔案分組，回傳所有至少有兩個檔案的群組；每個檔案以完整路徑表示。
 *
 * 範例："root/a 1.txt(abcd)" 與 "root/c 3.txt(abcd)" 內容相同，
 * 應放在同一組，路徑分別為 "root/a/1.txt" 和 "root/c/3.txt"。
 *
 * 限制：目錄描述數量不超過 2*10^4；所有描述的總長度不超過 5*10^4；
 * 檔名與內容不含空白。
 *
 * 解題思路：逐字解析每個描述，分出目錄、檔名與括號中的內容。用雜湊表以內容
 * 尋找群組；相同內容的完整路徑加入同一組。最後只回傳包含至少兩個路徑的群組。
 *
 * 複雜度：令 L 為所有輸入字元數，雜湊平均 O(L)，空間 O(L)。
 * LeetCode 介面：保留 findDuplicate；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *content;
    char **paths;
    int count;
    int capacity;
    int next;
} ContentGroup;

static char *copyRange(const char *start, size_t length) {
    char *copy = malloc(length + 1);
    if (copy == NULL) return NULL;
    memcpy(copy, start, length);
    copy[length] = '\0';
    return copy;
}

static uint64_t hashText(const char *text) {
    uint64_t hash = UINT64_C(1469598103934665603);
    while (*text != '\0') {
        hash ^= (unsigned char)*text++;
        hash *= UINT64_C(1099511628211);
    }
    return hash;
}

static void freeGroups(ContentGroup *groups, int groupCount) {
    for (int i = 0; i < groupCount; ++i) {
        free(groups[i].content);
        if (groups[i].paths != NULL) {
            for (int j = 0; j < groups[i].count; ++j) free(groups[i].paths[j]);
            free(groups[i].paths);
        }
    }
    free(groups);
}

char ***findDuplicate(char **paths, int pathsSize, int *returnSize,
                      int **returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = NULL;
    size_t totalLength = 1;
    for (int i = 0; i < pathsSize; ++i) totalLength += strlen(paths[i]);
    size_t bucketCount = totalLength + 1;
    int *heads = malloc(bucketCount * sizeof(*heads));
    if (heads == NULL) return NULL;
    for (size_t i = 0; i < bucketCount; ++i) heads[i] = -1;

    int groupCount = 0;
    int groupCapacity = 8;
    ContentGroup *groups = malloc((size_t)groupCapacity * sizeof(*groups));
    if (groups == NULL) {
        free(heads);
        return NULL;
    }

    for (int row = 0; row < pathsSize; ++row) {
        char *copy = copyRange(paths[row], strlen(paths[row]));
        if (copy == NULL) goto fail;
        char *directory = strtok(copy, " ");
        size_t directoryLength = directory == NULL ? 0 : strlen(directory);
        char *file = strtok(NULL, " ");
        while (file != NULL) {
            char *opening = strchr(file, '(');
            char *closing = strrchr(file, ')');
            if (opening == NULL || closing == NULL || closing < opening) {
                file = strtok(NULL, " ");
                continue;
            }

            size_t nameLength = (size_t)(opening - file);
            size_t contentLength = (size_t)(closing - opening - 1);
            char *fullPath = malloc(directoryLength + 1 + nameLength + 1);
            char *content = copyRange(opening + 1, contentLength);
            if (fullPath == NULL || content == NULL) {
                free(fullPath);
                free(content);
                free(copy);
                goto fail;
            }
            memcpy(fullPath, directory, directoryLength);
            fullPath[directoryLength] = '/';
            memcpy(fullPath + directoryLength + 1, file, nameLength);
            fullPath[directoryLength + 1 + nameLength] = '\0';

            uint64_t hash = hashText(content);
            size_t bucket = (size_t)(hash % bucketCount);
            int group = heads[bucket];
            while (group != -1 && strcmp(groups[group].content, content) != 0) {
                group = groups[group].next;
            }

            if (group == -1) {
                if (groupCount == groupCapacity) {
                    int newCapacity = groupCapacity * 2;
                    ContentGroup *grown = realloc(groups, (size_t)newCapacity * sizeof(*groups));
                    if (grown == NULL) {
                        free(fullPath);
                        free(content);
                        free(copy);
                        goto fail;
                    }
                    groups = grown;
                    groupCapacity = newCapacity;
                }
                group = groupCount++;
                groups[group].content = content;
                groups[group].paths = NULL;
                groups[group].count = 0;
                groups[group].capacity = 0;
                groups[group].next = heads[bucket];
                heads[bucket] = group;
            } else {
                free(content);
            }

            if (groups[group].count == groups[group].capacity) {
                int newCapacity = groups[group].capacity == 0 ? 2 : groups[group].capacity * 2;
                char **grown = realloc(groups[group].paths,
                                       (size_t)newCapacity * sizeof(*groups[group].paths));
                if (grown == NULL) {
                    free(fullPath);
                    free(copy);
                    goto fail;
                }
                groups[group].paths = grown;
                groups[group].capacity = newCapacity;
            }
            groups[group].paths[groups[group].count++] = fullPath;
            file = strtok(NULL, " ");
        }
        free(copy);
    }

    int duplicateGroups = 0;
    for (int i = 0; i < groupCount; ++i) {
        if (groups[i].count >= 2) ++duplicateGroups;
    }
    if (duplicateGroups == 0) {
        free(heads);
        freeGroups(groups, groupCount);
        return NULL;
    }

    char ***answer = malloc((size_t)duplicateGroups * sizeof(*answer));
    int *columnSizes = malloc((size_t)duplicateGroups * sizeof(*columnSizes));
    if (answer == NULL || columnSizes == NULL) {
        free(answer);
        free(columnSizes);
        goto fail;
    }
    int output = 0;
    for (int i = 0; i < groupCount; ++i) {
        if (groups[i].count >= 2) {
            answer[output] = groups[i].paths;
            columnSizes[output] = groups[i].count;
            groups[i].paths = NULL; /* 路徑陣列的所有權交給回傳值。 */
            ++output;
        }
    }
    free(heads);
    freeGroups(groups, groupCount);
    *returnSize = duplicateGroups;
    *returnColumnSizes = columnSizes;
    return answer;

fail:
    free(heads);
    freeGroups(groups, groupCount);
    return NULL;
}

int main(void) {
    char row0[] = "root/a 1.txt(abcd) 2.txt(efgh)";
    char row1[] = "root/c 3.txt(abcd)";
    char row2[] = "root/c 4.txt(efgh)";
    char *input[] = {row0, row1, row2};
    int rows = 0;
    int *columns = NULL;
    char ***groups = findDuplicate(input, 3, &rows, &columns);
    assert(rows == 2 && groups != NULL);
    for (int i = 0; i < rows; ++i) assert(columns[i] == 2);
    int foundAbcd = 0;
    int foundEfgh = 0;
    for (int i = 0; i < rows; ++i) {
        if (strcmp(groups[i][0], "root/a/1.txt") == 0
            || strcmp(groups[i][1], "root/a/1.txt") == 0) foundAbcd = 1;
        if (strcmp(groups[i][0], "root/a/2.txt") == 0
            || strcmp(groups[i][1], "root/a/2.txt") == 0) foundEfgh = 1;
        for (int j = 0; j < columns[i]; ++j) free(groups[i][j]);
        free(groups[i]);
    }
    assert(foundAbcd && foundEfgh);
    free(groups);
    free(columns);

    char single[] = "root/a 1.txt(unique)";
    char *oneInput[] = {single};
    groups = findDuplicate(oneInput, 1, &rows, &columns);
    assert(groups == NULL && rows == 0 && columns == NULL);
    return 0;
}
