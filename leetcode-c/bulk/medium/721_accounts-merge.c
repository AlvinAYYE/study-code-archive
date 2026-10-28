/*
 * LeetCode 0721. Accounts Merge（合併帳戶）
 * 題意：帳戶的第一個字串是姓名，其餘是 email；共用 email 的帳戶屬於同一人，需合併並排序 email。
 * 範例：兩個 John 帳戶共用 johnsmith@mail.com，合併後 email 為 john00、john_newyork、johnsmith（字典序）。
 * 限制：帳戶數 1..1000；每帳戶 2..10 個字串；email 最長 30 字元；同一人的帳戶姓名相同。
 * 解法：用並查集合併共用 email 的帳戶。雜湊表將 email 對應到首次出現的帳戶；
 *       走訪雜湊表按並查集根節點分組 email，再排序並複製成回傳結果。
 * 複雜度：E 為輸入 email 總數；平均時間 O(E α(A) + E log E)，空間 O(E + A)。
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMAIL_HASH_CAPACITY 32768

typedef struct {
    const char *email;
    int account;
} EmailSlot;

static int findRoot(int *parent, int value) {
    if (parent[value] != value) {
        parent[value] = findRoot(parent, parent[value]);
    }
    return parent[value];
}

static void uniteAccounts(int *parent, int *rank, int first, int second) {
    int rootFirst = findRoot(parent, first);
    int rootSecond = findRoot(parent, second);
    if (rootFirst == rootSecond) {
        return;
    }
    if (rank[rootFirst] < rank[rootSecond]) {
        parent[rootFirst] = rootSecond;
    } else if (rank[rootFirst] > rank[rootSecond]) {
        parent[rootSecond] = rootFirst;
    } else {
        parent[rootSecond] = rootFirst;
        rank[rootFirst]++;
    }
}

static unsigned long hashEmail(const char *text) {
    unsigned long hash = 5381;
    while (*text != '\0') {
        hash = hash * 33u + (unsigned char)*text++;
    }
    return hash;
}

static char *copyText(const char *text) {
    size_t length = strlen(text);
    char *copy = (char *)malloc(length + 1);
    if (copy != NULL) {
        memcpy(copy, text, length + 1);
    }
    return copy;
}

static int compareEmailPointers(const void *first, const void *second) {
    const char *const *emailFirst = (const char *const *)first;
    const char *const *emailSecond = (const char *const *)second;
    return strcmp(*emailFirst, *emailSecond);
}

/* ---- community solution ---- */
char*** accountsMerge(char*** accounts, int accountsSize,
                      int* accountsColSize, int* returnSize,
                      int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = NULL;
    int *parent = (int *)malloc(sizeof(int) * (size_t)accountsSize);
    int *rank = (int *)calloc((size_t)accountsSize, sizeof(int));
    EmailSlot *table = (EmailSlot *)calloc(EMAIL_HASH_CAPACITY, sizeof(*table));
    int *emailCounts = (int *)calloc((size_t)accountsSize, sizeof(int));
    if (parent == NULL || rank == NULL || table == NULL || emailCounts == NULL) {
        free(parent);
        free(rank);
        free(table);
        free(emailCounts);
        return NULL;
    }
    for (int i = 0; i < accountsSize; i++) {
        parent[i] = i;
    }

    for (int account = 0; account < accountsSize; account++) {
        for (int column = 1; column < accountsColSize[account]; column++) {
            const char *email = accounts[account][column];
            unsigned long slot = hashEmail(email) % EMAIL_HASH_CAPACITY;
            while (table[slot].email != NULL &&
                   strcmp(table[slot].email, email) != 0) {
                slot = (slot + 1) % EMAIL_HASH_CAPACITY;
            }
            if (table[slot].email == NULL) {
                table[slot].email = email;
                table[slot].account = account;
            } else {
                uniteAccounts(parent, rank, account, table[slot].account);
            }
        }
    }

    for (int slot = 0; slot < EMAIL_HASH_CAPACITY; slot++) {
        if (table[slot].email != NULL) {
            emailCounts[findRoot(parent, table[slot].account)]++;
        }
    }

    char ***merged = (char ***)calloc((size_t)accountsSize, sizeof(*merged));
    int *columnSizes = (int *)calloc((size_t)accountsSize, sizeof(*columnSizes));
    int *groupRoots = (int *)calloc((size_t)accountsSize, sizeof(*groupRoots));
    int *fillPositions = (int *)calloc((size_t)accountsSize, sizeof(*fillPositions));
    if (merged == NULL || columnSizes == NULL || groupRoots == NULL ||
        fillPositions == NULL) {
        free(merged);
        free(columnSizes);
        free(groupRoots);
        free(fillPositions);
        free(parent);
        free(rank);
        free(table);
        free(emailCounts);
        return NULL;
    }

    int mergedCount = 0;
    for (int account = 0; account < accountsSize; account++) {
        if (findRoot(parent, account) != account) {
            continue;
        }
        int count = emailCounts[account];
        if (count == 0) {
            continue;
        }
        char **group = (char **)malloc(sizeof(char *) * (size_t)(count + 1));
        if (group == NULL) {
            continue;
        }
        group[0] = copyText(accounts[account][0]);
        if (group[0] == NULL) {
            free(group);
            continue;
        }
        merged[mergedCount] = group;
        columnSizes[mergedCount] = count + 1;
        groupRoots[mergedCount] = account;
        fillPositions[mergedCount] = 1;
        mergedCount++;
    }

    for (int slot = 0; slot < EMAIL_HASH_CAPACITY; slot++) {
        if (table[slot].email == NULL) {
            continue;
        }
        int root = findRoot(parent, table[slot].account);
        for (int groupIndex = 0; groupIndex < mergedCount; groupIndex++) {
            if (groupRoots[groupIndex] == root && merged[groupIndex] != NULL) {
                int position = fillPositions[groupIndex]++;
                merged[groupIndex][position] = copyText(table[slot].email);
                break;
            }
        }
    }

    for (int groupIndex = 0; groupIndex < mergedCount; groupIndex++) {
        if (merged[groupIndex] != NULL) {
            qsort(merged[groupIndex] + 1,
                  (size_t)(columnSizes[groupIndex] - 1),
                  sizeof(char *), compareEmailPointers);
        }
    }
    free(groupRoots);
    free(fillPositions);
    free(parent);
    free(rank);
    free(table);
    free(emailCounts);
    *returnSize = mergedCount;
    *returnColumnSizes = columnSizes;
    return merged;
}

static bool containsMergedAccount(char ***merged, int *columnSizes,
                                  int mergedSize, const char *name,
                                  const char **expectedEmails, int emailCount) {
    for (int i = 0; i < mergedSize; i++) {
        if (strcmp(merged[i][0], name) != 0 || columnSizes[i] != emailCount + 1) {
            continue;
        }
        bool same = true;
        for (int j = 0; j < emailCount; j++) {
            if (strcmp(merged[i][j + 1], expectedEmails[j]) != 0) {
                same = false;
            }
        }
        if (same) {
            return true;
        }
    }
    return false;
}

static void freeMergedAccounts(char ***merged, int *columnSizes, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < columnSizes[i]; j++) {
            free(merged[i][j]);
        }
        free(merged[i]);
    }
    free(merged);
    free(columnSizes);
}

/* ---- generated tests ---- */
int main(void) {
    char *johnOne[] = {"John", "johnsmith@mail.com", "john_newyork@mail.com"};
    char *johnTwo[] = {"John", "johnsmith@mail.com", "john00@mail.com"};
    char *mary[] = {"Mary", "mary@mail.com"};
    char *johnThree[] = {"John", "johnnybravo@mail.com"};
    char **accounts[] = {johnOne, johnTwo, mary, johnThree};
    int accountSizes[] = {3, 3, 2, 2};
    int resultSize = 0;
    int *resultColumns = NULL;
    char ***result = accountsMerge(accounts, 4, accountSizes,
                                   &resultSize, &resultColumns);
    const char *johnEmails[] = {
        "john00@mail.com", "john_newyork@mail.com", "johnsmith@mail.com"
    };
    const char *maryEmails[] = {"mary@mail.com"};
    const char *johnnyEmails[] = {"johnnybravo@mail.com"};
    bool passed = result != NULL && resultSize == 3 &&
        containsMergedAccount(result, resultColumns, resultSize,
                              "John", johnEmails, 3) &&
        containsMergedAccount(result, resultColumns, resultSize,
                              "Mary", maryEmails, 1) &&
        containsMergedAccount(result, resultColumns, resultSize,
                              "John", johnnyEmails, 1);
    if (result != NULL) {
        freeMergedAccounts(result, resultColumns, resultSize);
    }
    printf("%s: 0721 accountsMerge tests=1\n", passed ? "PASS" : "FAIL");
    return passed ? 0 : 1;
}
