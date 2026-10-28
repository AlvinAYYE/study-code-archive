/*
 * LeetCode 726. Number of Atoms（原子數量）
 *
 * 題意（繁體中文）：
 *   給定合法的化學式字串，回傳每種元素出現的總數。元素符號以一個大寫字母
 *   開始，後面可接零個以上的小寫字母；元素或括號群組後可以接數字作為數量，
 *   沒寫數量代表 1。多個化學式片段可直接相連，括號內的整組也可乘上後方數字。
 *   輸出時依元素名稱字典順序排列，數量為 1 時省略數字。
 *
 * 範例：
 *   1. formula="H2O"，回傳 "H2O"。
 *   2. formula="Mg(OH)2"，回傳 "H2MgO2"。
 *   3. formula="K4(ON(SO3)2)2"，回傳 "K4N2O14S4"。
 *
 * 限制：1 <= formula.length <= 1000；只含英文字母、數字、(、)；公式合法；
 *   輸出中每個元素的總數都能放進 32 位元整數。
 *
 * 解題步驟：
 *   1. 遞迴解析一段公式。遇到元素名稱就讀取後方數量，乘上目前累積的群組
 *      倍數，加入該元素的總數。
 *   2. 遇到左括號時，先找到與它配對的右括號，再讀取括號後的倍數；遞迴解析
 *      括號內文字時，把目前倍數乘上這個群組倍數。
 *   3. 把元素名稱與計數集中保存，最後依名稱排序；逐一輸出名稱與大於 1 的
 *      計數，組成答案字串。
 *
 * 複雜度：令 L 為公式長度、U 為不同元素數；簡單線性查找與配對括號掃描的
 *   最壞時間為 O(L^2+U^2)，額外空間 O(L)。L <= 1000。
 * LeetCode C API：char* countOfAtoms(char* formula)
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ATOMS 1000

typedef struct {
    char *name;
    long long count;
} AtomCount;

typedef struct {
    AtomCount atoms[MAX_ATOMS];
    int size;
} FormulaContext;

static int findAtom(const FormulaContext *context, const char *name, int length) {
    for (int i = 0; i < context->size; ++i) {
        if ((int)strlen(context->atoms[i].name) == length &&
            strncmp(context->atoms[i].name, name, (size_t)length) == 0)
            return i;
    }
    return -1;
}

static int addAtom(FormulaContext *context, const char *name, int length,
                   long long count) {
    int index = findAtom(context, name, length);
    if (index < 0) {
        if (context->size == MAX_ATOMS) return 0;
        char *copy = (char *)malloc((size_t)length + 1);
        if (copy == NULL) return 0;
        memcpy(copy, name, (size_t)length);
        copy[length] = '\0';
        index = context->size++;
        context->atoms[index].name = copy;
        context->atoms[index].count = 0;
    }
    context->atoms[index].count += count;
    return 1;
}

static int matchingClose(const char *formula, int open, int end) {
    int depth = 0;
    for (int i = open; i < end; ++i) {
        if (formula[i] == '(') ++depth;
        else if (formula[i] == ')' && --depth == 0) return i;
    }
    return -1;
}

static long long readMultiplier(const char *formula, int *position, int end) {
    if (*position >= end || !isdigit((unsigned char)formula[*position])) return 1;
    long long value = 0;
    while (*position < end && isdigit((unsigned char)formula[*position])) {
        value = value * 10 + (formula[*position] - '0');
        ++*position;
    }
    return value;
}

static int parseRange(FormulaContext *context, const char *formula,
                      int start, int end, long long multiplier) {
    int position = start;
    while (position < end) {
        if (formula[position] == '(') {
            int close = matchingClose(formula, position, end);
            if (close < 0) return 0;
            int afterGroup = close + 1;
            long long groupMultiplier =
                readMultiplier(formula, &afterGroup, end);
            if (!parseRange(context, formula, position + 1, close,
                            multiplier * groupMultiplier))
                return 0;
            position = afterGroup;
        } else if (formula[position] >= 'A' && formula[position] <= 'Z') {
            int nameStart = position++;
            while (position < end && formula[position] >= 'a' &&
                   formula[position] <= 'z')
                ++position;
            int nameLength = position - nameStart;
            long long atomMultiplier = readMultiplier(formula, &position, end);
            if (!addAtom(context, formula + nameStart, nameLength,
                         multiplier * atomMultiplier))
                return 0;
        } else {
            return 0; /* 輸入依題意保證合法；此分支保護解析器。 */
        }
    }
    return 1;
}

static int compareAtoms(const void *left, const void *right) {
    const AtomCount *a = (const AtomCount *)left;
    const AtomCount *b = (const AtomCount *)right;
    return strcmp(a->name, b->name);
}

static void freeAtoms(FormulaContext *context) {
    for (int i = 0; i < context->size; ++i) free(context->atoms[i].name);
}

char *countOfAtoms(char *formula) {
    if (formula == NULL) return NULL;
    FormulaContext context = {{{0}}, 0};
    int length = (int)strlen(formula);
    if (!parseRange(&context, formula, 0, length, 1)) {
        freeAtoms(&context);
        return NULL;
    }
    qsort(context.atoms, (size_t)context.size, sizeof context.atoms[0], compareAtoms);

    size_t capacity = 1;
    for (int i = 0; i < context.size; ++i)
        capacity += strlen(context.atoms[i].name) + 12;
    char *answer = (char *)malloc(capacity);
    if (answer == NULL) {
        freeAtoms(&context);
        return NULL;
    }

    char *output = answer;
    for (int i = 0; i < context.size; ++i) {
        size_t nameLength = strlen(context.atoms[i].name);
        memcpy(output, context.atoms[i].name, nameLength);
        output += nameLength;
        if (context.atoms[i].count > 1) {
            int written = sprintf(output, "%lld", context.atoms[i].count);
            output += written;
        }
    }
    *output = '\0';
    freeAtoms(&context);
    return answer;
}

int main(void) {
    char formula1[] = "H2O";
    char formula2[] = "Mg(OH)2";
    char formula3[] = "K4(ON(SO3)2)2";
    char formula4[] = "((H)2O)3";
    char *answer1 = countOfAtoms(formula1);
    char *answer2 = countOfAtoms(formula2);
    char *answer3 = countOfAtoms(formula3);
    char *answer4 = countOfAtoms(formula4);
    int passed = answer1 != NULL && strcmp(answer1, "H2O") == 0 &&
                 answer2 != NULL && strcmp(answer2, "H2MgO2") == 0 &&
                 answer3 != NULL && strcmp(answer3, "K4N2O14S4") == 0 &&
                 answer4 != NULL && strcmp(answer4, "H6O3") == 0;
    free(answer1);
    free(answer2);
    free(answer3);
    free(answer4);
    puts(passed ? "PASS: 726 number-of-atoms" : "FAIL: 726 number-of-atoms");
    return passed ? 0 : 1;
}
