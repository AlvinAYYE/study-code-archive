/*
 * Title-CN: 字串壓縮
 * LeetCode 443. String Compression
 *
 * 題目翻譯：把連續相同的字元壓縮成「字元 + 次數」。次數為 1 時只寫字元；
 * 次數大於 1 時，將次數的每一位數字依序寫入原陣列。必須原地修改並回傳新長度。
 *
 * 例子：['a','a','b','b','c','c','c'] 改成 ['a','2','b','2','c','3']，回傳 6。
 *
 * 限制：陣列至少有一個字元，最多 2000 個；字元可以是英文字母、數字或符號。
 *
 * 解題步驟：用 read 找出一段連續相同字元，用 write 把該字元與必要的次數寫回陣列。
 * 次數的數字先由個位數倒著寫，再把這幾位反轉，便會得到正確順序。read 只會往前，
 * write 不會超過 read，因此寫回資料不會蓋掉還沒讀取的字元。
 *
 * 複雜度：每個字元只讀寫常數次，時間 O(n)，額外空間 O(1)。
 *
 * LeetCode 提交區：保留 compress 函式；main() 僅供本機測試。
 */

#include <assert.h>

int compress(char *chars, int charsSize) {
    int read = 0;
    int write = 0;

    while (read < charsSize) {
        int runStart = read;
        char letter = chars[read];
        while (read < charsSize && chars[read] == letter) {
            ++read;
        }

        int count = read - runStart;
        chars[write++] = letter;
        if (count > 1) {
            int digitStart = write;
            while (count > 0) {
                chars[write++] = (char)('0' + count % 10);
                count /= 10;
            }
            for (int left = digitStart, right = write - 1; left < right; ++left, --right) {
                char temp = chars[left];
                chars[left] = chars[right];
                chars[right] = temp;
            }
        }
    }
    return write;
}

int main(void) {
    char example[] = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    const char expected[] = {'a', '2', 'b', '2', 'c', '3'};
    assert(compress(example, 7) == 6);
    for (int i = 0; i < 6; ++i) {
        assert(example[i] == expected[i]);
    }

    char oneRun[] = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'};
    const char expectedRun[] = {'a', '1', '2'};
    assert(compress(oneRun, 12) == 3);
    for (int i = 0; i < 3; ++i) {
        assert(oneRun[i] == expectedRun[i]);
    }

    char singles[] = {'x', 'y', 'z'};
    assert(compress(singles, 3) == 3);
    return 0;
}
