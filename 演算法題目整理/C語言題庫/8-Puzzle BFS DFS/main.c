/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】解 3×3 數字滑塊。0 代表空格；每次把相鄰數字移入空格。程式使用 BFS
 * 找到最少步數的解。 【輸入】初始狀態的 9 個數字，範圍 0 到 8，各出現一次。【目標】0 1 2 / 3 4 5 /
 * 6 7 8。【輸出】最少步數和每一步的棋盤。
 * 【閱讀順序】先統計逆序數；奇數寬度棋盤只有偶數逆序狀態可解。rankp 把一個排列轉成
 * 0..362879 的唯一索引，用 seen 防止重複搜尋。BFS
 * 從初始盤面開始，試空格上下左右移動；每個新盤面記錄 parent。抵達目標後沿 parent 倒回去輸出。 【C
 * 語法】State 結構保存盤面、父節點索引和移動方向；queue 是 BFS 佇列；memcpy 複製 9 格盤面；static
 * 大型陣列避免堆疊空間不足。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 輸入初始狀態 9 個數字（0 表示空格），求至 0 1 2 / 3 4 5 / 6 7 8 的最短步數及每一步盤面。 */
#include <stdio.h>
#include <string.h>
#define P 362880
typedef struct {
    unsigned char tiles[9];
    int parent;
    char move;
} State;
static State states[P];
static int visited[P], state_queue[P];
static int factorials[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int rank_permutation(const unsigned char *tiles) {
    int rank = 0;
    for (int index = 0; index < 9; index++) {
        int smaller_tiles = 0;
        for (int inner_index = index + 1; inner_index < 9; inner_index++)
            if (tiles[inner_index] < tiles[index])
                smaller_tiles++;
        rank += smaller_tiles * factorials[8 - index];
    }
    return rank;
}
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    unsigned char start[9], goal[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    for (int index = 0; index < 9; index++) {
        int tile_value;
        if (scanf("%d", &tile_value) != 1 || tile_value < 0 || tile_value > 8)
            return 1;
        start[index] = (unsigned char)tile_value;
    }
    int inversion_count = 0;
    for (int index = 0; index < 9; index++)
        for (int inner_index = index + 1; inner_index < 9; inner_index++)
            if (start[index] && start[inner_index] && start[index] > start[inner_index])
                inversion_count++;
    if (inversion_count % 2)
        return puts("此狀態無解"), 0;
    int start_rank = rank_permutation(start), goal_rank = rank_permutation(goal), queue_head = 0,
        queue_tail = 0;
    memcpy(states[0].tiles, start, 9);
    states[0].parent = -1;
    visited[start_rank] = 1;
    state_queue[queue_tail++] = 0;
    int goal_state = -1;
    int row_delta[4] = {-1, 1, 0, 0}, column_delta[4] = {0, 0, -1, 1};
    char move_directions[4] = {'U', 'D', 'L', 'R'};
    while (queue_head < queue_tail) {
        int state_index = state_queue[queue_head++],
            state_rank = rank_permutation(states[state_index].tiles);
        if (state_rank == goal_rank) {
            goal_state = state_index;
            break;
        }
        int blank_index = 0;
        while (states[state_index].tiles[blank_index])
            blank_index++;
        for (int direction_index = 0; direction_index < 4; direction_index++) {
            int next_row = blank_index / 3 + row_delta[direction_index],
                next_column = blank_index % 3 + column_delta[direction_index];
            if (next_row < 0 || next_row >= 3 || next_column < 0 || next_column >= 3)
                continue;
            unsigned char next_tiles[9];
            memcpy(next_tiles, states[state_index].tiles, 9);
            int next_blank_index = next_row * 3 + next_column;
            next_tiles[blank_index] = next_tiles[next_blank_index];
            next_tiles[next_blank_index] = 0;
            int next_rank = rank_permutation(next_tiles);
            if (!visited[next_rank]) {
                visited[next_rank] = 1;
                memcpy(states[queue_tail].tiles, next_tiles, 9);
                states[queue_tail].parent = state_index;
                states[queue_tail].move = move_directions[direction_index];
                state_queue[queue_tail] = queue_tail;
                queue_tail++;
            }
        }
    }
    if (goal_state < 0)
        return puts("找不到解"), 0;
    static int solution_path[P];
    int path_length = 0;
    for (int current_state = goal_state; current_state >= 0;
         current_state = states[current_state].parent)
        solution_path[path_length++] = current_state;
    printf("最少步數：%d\n", path_length - 1);
    for (int index = path_length - 1; index >= 0; index--) {
        printf("Step %d%s\n", path_length - 1 - index, index == path_length - 1 ? " (start)" : "");
        for (int inner_index = 0; inner_index < 9; inner_index++)
            printf("%d%c",
                   states[solution_path[index]].tiles[inner_index],
                   inner_index % 3 == 2 ? '\n' : ' ');
    }
    return 0;
}
