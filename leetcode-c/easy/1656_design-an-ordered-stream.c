/*
 * Title-CN: 設計有序串流
 * LeetCode 1656. Design an Ordered Stream
 *
 * 題意完整翻譯：
 *   設計容量為 n 的有序串流，接收 idKey 從 1 到 n 的 (idKey, value) 配對；每個 id 只會插入一次，插入順序任意。每次
 *   insert 後，從目前指標開始，回傳所有連續已插入的 value，直到第一個尚未插入的 id 為止。把每次回傳的片段接起來，結果會依 id 遞增排序。
 *
 * 範例：
 *   1. n = 5，依序插入 (3,ccccc)、(1,aaaaa)、(2,bbbbb)、(5,eeeee)、(4,ddddd)，回傳片段依序為
 *      []、[aaaaa]、[bbbbb,ccccc]、[]、[ddddd,eeeee]。
 *
 * 限制：
 *   - 1 <= n <= 1000
 *   - 1 <= id <= n
 *   - value 長度恰為 5，且只含小寫英文字母
 *   - 每次 insert 的 id 唯一，總共恰好呼叫 n 次
 *
 * 解題步驟：
 *   1. 建立長度 n + 1 的位置陣列，索引直接代表 id；指標從 1 開始。
 *   2. insert(idKey,value) 時，把 value 複製到對應位置。
 *   3. 只要指標位置已有 value，就把它加入本次回傳片段並將指標往後移。
 *   4. 遇到空位置就停止；未來插入前面的缺口時，指標可以一次輸出新補齊的整段內容。
 *
 * 複雜度：
 *   時間：每個 value 最多被指標掃過一次，總掃描 O(n)；每次另需 O(k) 複製回傳片段指標。
 *   空間：O(n)，保存各 id 的字串與本次輸出指標陣列。
 *
 * LeetCode C API：
 *   OrderedStream* orderedStreamCreate(int n); char**
 *   orderedStreamInsert(OrderedStream* obj, int idKey, char* value, int*
 *   retSize); void orderedStreamFree(OrderedStream* obj);
 */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int size;
    int pointer;
    char** values;
} OrderedStream;

OrderedStream* orderedStreamCreate(int n) {
    OrderedStream* obj = (OrderedStream*)malloc(sizeof(OrderedStream));
    obj->size = n;
    obj->pointer = 1;
    obj->values = (char**)calloc((size_t)n + 1, sizeof(char*));
    return obj;
}

char** orderedStreamInsert(OrderedStream* obj, int idKey,
                           char* value, int* retSize) {
    int start = obj->pointer;
    int count;
    int i;
    char** chunk;

    obj->values[idKey] = (char*)malloc(6);
    memcpy(obj->values[idKey], value, 6);

    while (obj->pointer <= obj->size && obj->values[obj->pointer] != NULL) {
        ++obj->pointer;
    }

    count = obj->pointer - start;
    *retSize = count;
    if (count == 0) {
        return NULL;
    }

    chunk = (char**)malloc(sizeof(char*) * (size_t)count);
    for (i = 0; i < count; ++i) {
        chunk[i] = obj->values[start + i];
    }
    return chunk;
}

void orderedStreamFree(OrderedStream* obj) {
    int i;
    if (obj == NULL) return;

    for (i = 1; i <= obj->size; ++i) {
        free(obj->values[i]);
    }
    free(obj->values);
    free(obj);
}

int main(void) {
    OrderedStream* stream = orderedStreamCreate(5);
    int size;
    {
        char value[] = "ccccc";
        char** result = orderedStreamInsert(stream, 3, value, &size);
        assert(size == 0 && result == NULL);
    }
    {
        char value[] = "aaaaa";
        char** result = orderedStreamInsert(stream, 1, value, &size);
        assert(size == 1 && strcmp(result[0], "aaaaa") == 0);
        free(result);
    }
    {
        char value[] = "bbbbb";
        char** result = orderedStreamInsert(stream, 2, value, &size);
        assert(size == 2 && strcmp(result[0], "bbbbb") == 0);
        assert(strcmp(result[1], "ccccc") == 0);
        free(result);
    }
    {
        char value[] = "eeeee";
        char** result = orderedStreamInsert(stream, 5, value, &size);
        assert(size == 0 && result == NULL);
    }
    {
        char value[] = "ddddd";
        char** result = orderedStreamInsert(stream, 4, value, &size);
        assert(size == 2 && strcmp(result[0], "ddddd") == 0);
        assert(strcmp(result[1], "eeeee") == 0);
        free(result);
    }

    orderedStreamFree(stream);
    puts("PASS 1656 OrderedStream");
    return 0;
}
