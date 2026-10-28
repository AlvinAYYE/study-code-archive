/*
 * Title-CN: 最長絕對檔案路徑
 * LeetCode 388. Longest Absolute File Path
 *
 * 題目翻譯：輸入用換行分隔檔案系統項目，開頭的 Tab 數量代表目錄深度。
 * 每個檔案或資料夾名稱長度至少為 1；名稱含有點號代表檔案。請回傳最長檔案
 * 絕對路徑的字元數，路徑中的斜線也要計入；若沒有檔案，回傳 0。
 *
 * 例子："dir\\n\\tsubdir1\\n\\tsubdir2\\n\\t\\tfile.ext" 的答案是 20，
 * 因為最長路徑是 "dir/subdir2/file.ext"。
 *
 * 限制：輸入長度最多 10000，只含英數字、空格、點號、換行與 Tab。
 *
 * 解題步驟：逐行讀取名稱，數開頭 Tab 得到深度。用 pathLength[d] 記錄目前深度 d
 * 的父路徑長度；目前路徑長度等於父路徑長度 + 名稱長度 +（非根層的一個斜線）。
 * 若名稱含點號，就用目前長度更新最長檔案路徑。
 *
 * 複雜度：每個輸入字元掃描一次，時間 O(n)；深度表最多 O(n) 空間。
 *
 * LeetCode 提交區：保留 lengthLongestPath 函式；main() 僅供本機測試。
 */

#include <assert.h>
#include <string.h>

int lengthLongestPath(char *input) {
    int pathLength[10001] = {0};
    int longest = 0;
    int position = 0;

    while (input[position] != '\0') {
        int depth = 0;
        while (input[position] == '\t') {
            ++depth;
            ++position;
        }

        int start = position;
        while (input[position] != '\n' && input[position] != '\0') {
            ++position;
        }
        int nameLength = position - start;
        int currentLength = pathLength[depth] + nameLength + (depth > 0 ? 1 : 0);
        pathLength[depth + 1] = currentLength;

        if (memchr(input + start, '.', (size_t)nameLength) != NULL && currentLength > longest) {
            longest = currentLength;
        }
        if (input[position] == '\n') {
            ++position;
        }
    }
    return longest;
}

int main(void) {
    char example1[] = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    char example2[] = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    char noFile[] = "a";
    char rootFile[] = "file.txt";
    assert(lengthLongestPath(example1) == 20);
    assert(lengthLongestPath(example2) == 32);
    assert(lengthLongestPath(noFile) == 0);
    assert(lengthLongestPath(rootFile) == 8);
    return 0;
}
