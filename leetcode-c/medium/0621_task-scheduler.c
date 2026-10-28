/*
 * Title-CN: 任務排程器
 * LeetCode 621. Task Scheduler
 *
 * 題意翻譯：給定一組任務代號和冷卻時間 n。每個時間單位可執行一個任務或休息；
 * 同一種任務執行後，至少要隔 n 個時間單位才能再次執行。請回傳完成所有任務
 * 所需的最少時間。
 *
 * 範例：tasks = [A,A,A,B,B,B]、n = 2，回傳 8。一種排法是 A B idle A B idle A B。
 *
 * 限制：任務數量為 1 到 10^4；任務代號為大寫英文字母；n 為 0 到 100。
 *
 * 解題思路：先數每種任務的出現次數。設最多次的任務出現 max 次，這些任務之間
 * 形成 max-1 個間隔，每個間隔至少要有 n 個位置；若有多種任務同樣最多，最後一組
 * 間隔也要放入它們。公式為 (max-1)*(n+1)+最多次數的任務種類數。若其他任務已填滿
 * 空格，就不需休息，因此答案再與任務總數取較大值。
 *
 * 複雜度：時間 O(tasksSize)，空間 O(1)（固定 26 種字母）。
 * LeetCode 介面：保留 leastInterval；main() 僅供本機測試。
 */

#include <assert.h>

int leastInterval(char *tasks, int tasksSize, int n) {
    int frequency[26] = {0};
    for (int i = 0; i < tasksSize; ++i) ++frequency[tasks[i] - 'A'];

    int maximum = 0;
    for (int i = 0; i < 26; ++i) {
        if (frequency[i] > maximum) maximum = frequency[i];
    }
    int tiedForMaximum = 0;
    for (int i = 0; i < 26; ++i) {
        if (frequency[i] == maximum) ++tiedForMaximum;
    }
    int arrangedByCooldown = (maximum - 1) * (n + 1) + tiedForMaximum;
    return arrangedByCooldown > tasksSize ? arrangedByCooldown : tasksSize;
}

int main(void) {
    char tasks[] = "AAABBB";
    char noCooldown[] = "AAABBB";
    assert(leastInterval(tasks, 6, 2) == 8);
    assert(leastInterval(noCooldown, 6, 0) == 6);
    char tied[] = "AAAAAABCDEFG";
    assert(leastInterval(tied, 12, 2) == 16);
    return 0;
}
