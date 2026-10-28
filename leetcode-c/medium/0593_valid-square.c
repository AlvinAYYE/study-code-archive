/*
 * Title-CN: 判斷正方形
 * LeetCode 593. Valid Square
 *
 * 題目翻譯：給定平面上的四個點，判斷它們能否形成一個面積大於 0 的正方形。
 * 點的輸入順序任意。
 *
 * 例子：(0,0)、(1,1)、(1,0)、(0,1) 可以形成正方形，回傳 true。
 * 若四點重合或只是長方形，回傳 false。
 *
 * 限制：四個點各有 x、y 座標，座標絕對值不超過 10000。
 *
 * 解題步驟：計算四點兩兩之間共六個平方距離並排序。正方形應有四條相等且大於 0
 * 的邊，以及兩條相等的對角線；對角線平方長度必須是邊長平方的兩倍。
 *
 * 複雜度：計算六個距離並排序固定六個數，時間與額外空間皆為 O(1)。
 *
 * LeetCode 提交區：保留 validSquare 函式；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdbool.h>

static long long squaredDistance(const int *a, const int *b) {
    long long dx = (long long)a[0] - b[0];
    long long dy = (long long)a[1] - b[1];
    return dx * dx + dy * dy;
}

static void sortSix(long long values[6]) {
    for (int i = 1; i < 6; ++i) {
        long long value = values[i];
        int j = i;
        while (j > 0 && values[j - 1] > value) {
            values[j] = values[j - 1];
            --j;
        }
        values[j] = value;
    }
}

bool validSquare(int *p1, int p1Size, int *p2, int p2Size,
                 int *p3, int p3Size, int *p4, int p4Size) {
    (void)p1Size;
    (void)p2Size;
    (void)p3Size;
    (void)p4Size;
    int *points[] = {p1, p2, p3, p4};
    long long distances[6];
    int count = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            distances[count++] = squaredDistance(points[i], points[j]);
        }
    }
    sortSix(distances);
    return distances[0] > 0
           && distances[0] == distances[1]
           && distances[1] == distances[2]
           && distances[2] == distances[3]
           && distances[4] == distances[5]
           && distances[4] == 2 * distances[0];
}

int main(void) {
    int p1[] = {0, 0};
    int p2[] = {1, 1};
    int p3[] = {1, 0};
    int p4[] = {0, 1};
    int rectangle[] = {2, 0};
    int same[] = {0, 0};
    assert(validSquare(p1, 2, p2, 2, p3, 2, p4, 2));
    assert(!validSquare(p1, 2, p2, 2, rectangle, 2, p4, 2));
    assert(!validSquare(p1, 2, same, 2, same, 2, same, 2));
    return 0;
}
