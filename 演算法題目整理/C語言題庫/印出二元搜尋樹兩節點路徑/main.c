/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】依序把整數插入二元搜尋樹，然後印出指定兩個節點之間的路徑。
 * 【輸入】節點數 n、n 個插入值、起點值 x、終點值 y。【輸出】從 x 走到 y
 * 經過的節點值；任一節點不存在會回報找不到。 【閱讀順序】insert
 * 從根節點開始：較小值往左，較大或相等值往右。path
 * 從根開始搜尋目標，並把走過的節點索引存進陣列。兩條「根到目標」路徑共同開頭的最後一個節點就是共同祖先；先從
 * x 倒走到共同祖先，再沿另一條路徑走到 y。 【C
 * 語法】l[u]、r[u] 保存左、右子節點的索引；-1
 * 表示沒有子節點；int *q 是指向子節點欄位的指標，讓程式能直接改左欄或右欄。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 輸入 n、n 個插入值、起點和終點；輸出 BST 中兩節點間路徑。 */
#include <stdio.h>
#define N 100000
int node_values[N], left_child[N], right_child[N], parent_node[N], node_count = 0;
int insert(int value) {
    if (!node_count) {
        node_values[node_count] = value;
        return node_count++;
    }
    int node_index = 0;
    while (1) {
        int *child_link =
            value < node_values[node_index] ? &left_child[node_index] : &right_child[node_index];
        if (*child_link == -1) {
            *child_link = node_count;
            node_values[node_count] = value;
            parent_node[node_count] = node_index;
            return node_count++;
        }
        node_index = *child_link;
    }
}
int find_path_to_value(int value, int *path_nodes) {
    int node_index = 0, path_length = 0;
    while (node_index >= 0) {
        path_nodes[path_length++] = node_index;
        if (node_values[node_index] == value)
            return path_length;
        node_index =
            value < node_values[node_index] ? left_child[node_index] : right_child[node_index];
    }
    return 0;
}
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    int node_count_input, first_path[N], second_path[N], start_value, target_value;
    if (scanf("%d", &node_count_input) != 1 || node_count_input < 1 || node_count_input >= N)
        return 1;
    for (int node_index = 0; node_index < N; node_index++)
        left_child[node_index] = right_child[node_index] = parent_node[node_index] = -1;
    for (int input_index = 0; input_index < node_count_input; input_index++) {
        int input_value;
        if (scanf("%d", &input_value) != 1)
            return 1;
        insert(input_value);
    }
    if (scanf("%d%d", &start_value, &target_value) != 2)
        return 1;
    int first_path_length = find_path_to_value(start_value, first_path);
    int second_path_length = find_path_to_value(target_value, second_path);
    if (!first_path_length || !second_path_length)
        return puts("找不到節點"), 1;
    int shared_prefix_length = 0;
    while (shared_prefix_length < first_path_length && shared_prefix_length < second_path_length &&
           first_path[shared_prefix_length] == second_path[shared_prefix_length])
        shared_prefix_length++;
    if (shared_prefix_length == 0)
        return 1;
    for (int inner_index = first_path_length - 1; inner_index >= shared_prefix_length - 1;
         inner_index--)
        printf(
            "%d%c",
            node_values[first_path[inner_index]],
            (inner_index == shared_prefix_length - 1 && shared_prefix_length == second_path_length)
                ? '\n'
                : ' ');
    for (int inner_index = shared_prefix_length; inner_index < second_path_length; inner_index++)
        printf("%d%c",
               node_values[second_path[inner_index]],
               inner_index + 1 == second_path_length ? '\n' : ' ');

    return 0;
}
