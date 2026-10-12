/*
 * ==========================================================================
 * UVa 10033 - Interpreter
 * Title-CN: 虛擬計算機解譯器模擬
 * Difficulty: UVa Star 1
 * Tags: simulation
 * ==========================================================================
 * [EN] Problem: Simulate virtual machine execution and count executed instructions.
 * [中文] 題目說明: 模擬 10 暫存器計算機指令執行並統計步數。
 * [EN] Approach: Fetch-decode-execute cycle with array registers and memory.
 * [中文] 思路: 陣列模擬暫存器與記憶體，迴圈解碼各指令（1~9 與 0）。
 * ==========================================================================
 */
#include <stdio.h>

int solve_uva10033(int mem[1000]) {
    int reg[10] = {0};
    int pc = 0, steps = 0;
    while (1) {
        steps++;
        int inst = mem[pc++];
        int op = inst / 100;
        int d = (inst / 10) % 10;
        int s = inst % 10;
        if (inst == 100) break;
        switch (op) {
            case 2: reg[d] = s; break;
            case 3: reg[d] = (reg[d] + s) % 1000; break;
            case 4: reg[d] = (reg[d] * s) % 1000; break;
            case 5: reg[d] = reg[s]; break;
            case 6: reg[d] = (reg[d] + reg[s]) % 1000; break;
            case 7: reg[d] = (reg[d] * reg[s]) % 1000; break;
            case 8: reg[d] = mem[reg[s]]; break;
            case 9: mem[reg[s]] = reg[d]; break;
            case 0: if (reg[s] != 0) pc = reg[d]; break;
        }
    }
    return steps;
}

int main(void) {
    int mem[1000] = {0};
    mem[0] = 299; /* set reg 9 to 9 */
    mem[1] = 100; /* halt */
    int steps = solve_uva10033(mem);
    int ok = (steps == 2);
    printf("%s: UVa 10033 - Interpreter\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
