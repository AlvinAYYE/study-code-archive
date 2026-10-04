/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】讀取一行文字，依字元出現頻率建立 Huffman
 * 樹，產生每個字元的變長編碼，並把編碼結果寫入 huffman.txt。
 * 【輸入】一行文字（此範例以單位元組字元處理）。【輸出】終端顯示碼表與位元串；檔案另存碼表及
 * encoded 位元串。
 * 【閱讀順序】先統計每個字元的頻率，每個不同字元是樹葉。每一輪挑兩個頻率最小、尚未合併的節點，建立一個父節點，其頻率為兩者相加。樹建好後，從葉節點沿
 * parent 回到根；左邊加 0、右邊加 1，反向後得到該字元的碼。最後依原文逐字串接碼字。 【C 語法】Node
 * 保存頻率、左右子節點、父節點與字元；-1 表示不存在；code[字元值] 保存該字元的位元字串；unsigned
 * char 用來安全索引 0 到 255 的字元表。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 輸入一行文字；輸出 Huffman 碼表與編碼字串，另寫 huffman.txt。 */
#include <stdio.h>
#include <string.h>
#define N 512
typedef struct {
    int weight, left_child, right_child, parent_index, character;
} Node;
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    char source_text[10000], codes[256][256] = {{0}};
    if (!fgets(source_text, sizeof source_text, stdin))
        return 1;
    int frequencies[256] = {0}, text_length = (int)strcspn(source_text, "\r\n");
    source_text[text_length] = 0;
    for (int index = 0; index < text_length; index++)
        frequencies[(unsigned char)source_text[index]]++;
    Node tree_nodes[N] = {0};
    int leaf_count = 0;
    for (int c = 0; c < 256; c++)
        if (frequencies[c])
            tree_nodes[leaf_count++] = (Node){frequencies[c], -1, -1, -1, c};
    if (!leaf_count)
        return 0;
    if (leaf_count == 1)
        strcpy(codes[tree_nodes[0].character], "0");
    else {
        int node_count = leaf_count;
        while (1) {
            int first_minimum = -1, second_minimum = -1;
            for (int index = 0; index < node_count; index++)
                if (tree_nodes[index].parent_index < 0) {
                    if (first_minimum < 0 ||
                        tree_nodes[index].weight < tree_nodes[first_minimum].weight)
                        first_minimum = index;
                }
            if (first_minimum < 0)
                break;
            for (int index = 0; index < node_count; index++)
                if (index != first_minimum && tree_nodes[index].parent_index < 0 &&
                    (second_minimum < 0 ||
                     tree_nodes[index].weight < tree_nodes[second_minimum].weight))
                    second_minimum = index;
            if (second_minimum < 0)
                break;
            tree_nodes[first_minimum].parent_index = node_count;
            tree_nodes[second_minimum].parent_index = node_count;
            tree_nodes[node_count] =
                (Node){tree_nodes[first_minimum].weight + tree_nodes[second_minimum].weight,
                       first_minimum,
                       second_minimum,
                       -1,
                       -1};
            node_count++;
        }
        int code_bits[256], code_length = 0;
        for (int c = 0; c < 256; c++)
            if (frequencies[c]) {
                int node_index = -1;
                for (int index = 0; index < leaf_count; index++)
                    if (tree_nodes[index].character == c)
                        node_index = index;
                code_length = 0;
                while (tree_nodes[node_index].parent_index >= 0) {
                    int parent_index = tree_nodes[node_index].parent_index;
                    code_bits[code_length++] =
                        (tree_nodes[parent_index].left_child == node_index) ? 0 : 1;
                    node_index = parent_index;
                }
                for (int inner_index = 0; inner_index < code_length; inner_index++)
                    codes[c][inner_index] = (char)('0' + code_bits[code_length - 1 - inner_index]);
                codes[c][code_length] = 0;
            }
    }
    FILE *output_file = fopen("huffman.txt", "w");
    for (int c = 0; c < 256; c++)
        if (frequencies[c]) {
            printf("%c : %s\n", c >= 32 && c < 127 ? c : '?', codes[c]);
            if (output_file)
                fprintf(output_file, "%c : %s\n", c, codes[c]);
        }
    printf("編碼：");
    for (int index = 0; index < text_length; index++)
        printf("%s", codes[(unsigned char)source_text[index]]);
    putchar('\n');
    if (output_file) {
        fprintf(output_file, "\nencoded: ");
        for (int index = 0; index < text_length; index++)
            fprintf(output_file, "%s", codes[(unsigned char)source_text[index]]);
        fclose(output_file);
    }
    return 0;
}
