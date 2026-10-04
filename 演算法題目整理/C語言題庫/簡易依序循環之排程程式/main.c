/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】模擬作業系統的 Round Robin（循環）排程。每個行程輪流執行最多 quantum 個時間單位。
 * 【輸入】行程數 n；n 個執行時間 burst time；最後輸入時間配額
 * quantum。執行時間可為 0，配額必須大於 0。 【閱讀順序】1. rem[i] 保存第 i
 * 個行程尚未執行的時間。2. 依 P1、P2⋯順序掃描；尚未完成的行程執行 min(rem, quantum)。3.
 * 對其他仍未完成的行程累計等待時間。4. 執行時間扣到 0 就標記完成；所有行程完成後印出等待時間。 【C
 * 語法】陣列 b[i]、rem[i] 用編號 i 保存多個行程的值；i 從 0
 * 開始，所以程式印行程名稱時使用 i+1。for 迴圈逐一巡訪行程，while 迴圈反覆排程直到完成。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 輸入行程數 n、各行程 burst time、時間配額 quantum；輸出 Round Robin
 * 執行片段和等待時間。 */
#include <stdio.h>
#define MAXP 100
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    int process_count, time_quantum, burst_time[MAXP], remaining_time[MAXP],
        waiting_time[MAXP] = {0}, finish_time[MAXP] = {0}, elapsed_time = 0, completed_count = 0;
    if (scanf("%d", &process_count) != 1 || process_count < 1 || process_count > MAXP)
        return 1;
    for (int index = 0; index < process_count; index++) {
        if (scanf("%d", &burst_time[index]) != 1 || burst_time[index] < 0)
            return 1;
        remaining_time[index] = burst_time[index];
    }
    if (scanf("%d", &time_quantum) != 1 || time_quantum < 1)
        return 1;
    for (int index = 0; index < process_count; index++)
        if (remaining_time[index] == 0)
            completed_count++;
    puts("時間區間  行程");
    while (completed_count < process_count) {
        for (int index = 0; index < process_count; index++)
            if (remaining_time[index] > 0) {
                int run_duration =
                    remaining_time[index] < time_quantum ? remaining_time[index] : time_quantum;
                printf("%d-%d       P%d\n", elapsed_time, elapsed_time + run_duration, index + 1);
                for (int inner_index = 0; inner_index < process_count; inner_index++)
                    if (inner_index != index && remaining_time[inner_index] > 0)
                        waiting_time[inner_index] += run_duration;
                remaining_time[index] -= run_duration;
                elapsed_time += run_duration;
                if (remaining_time[index] == 0) {
                    finish_time[index] = elapsed_time;
                    completed_count++;
                }
            }
    }
    for (int index = 0; index < process_count; index++)
        printf("P%d waiting time = %d\n", index + 1, waiting_time[index]);
    return 0;
}
