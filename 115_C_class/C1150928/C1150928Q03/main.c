/* Problem C1150928Q03: Maze Traversal - Right Hand - Simple Output */
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    char map[15][16] = { 0 };

    int map_enter = -1;
    int map_had_exit_flag = 0;

    // 讀取 15 x 15 迷宮
    for (int y = 0; y < 15; y++)
    {
        scanf("%15s", map[y]);

        // 找左側入口
        if (map[y][0] == 'X')
        {
            map_enter = y;
        }

        // 看右側是否存在出口
        if (map[y][14] == 'X')
        {
            map_had_exit_flag = 1;
        }
    }

    // 沒有入口或右側根本沒有出口
    if (map_enter == -1 || map_had_exit_flag == 0)
    {
        printf("This maze has no solution");
        return 0;
    }

    /*
        dir:
        0 = 上
        1 = 右
        2 = 下
        3 = 左
    */

    int dir = 1;

    // 現在的位置
    int y = map_enter;
    int x = 0;

    // 四個方向對座標造成的變化
    int dy[4] = {
        -1,     // 上
         0,     // 右
         1,     // 下
         0      // 左
    };

    int dx[4] = {
         0,     // 上
         1,     // 右
         0,     // 下
        -1      // 左
    };

    while (1)
    {
        // 已經走到最右側
        if (x == 14)
        {
            printf("This maze has a solution");
            return 0;
        }

        /*
            右手法則的嘗試順序：

            1. 右
            2. 前
            3. 左
            4. 後
        */

        int try_dir[4] = {
            (dir + 1) % 4,     // 右轉
            dir,               // 直走
            (dir + 3) % 4,     // 左轉
            (dir + 2) % 4      // 回頭
        };

        int moved = 0;

        for (int i = 0; i < 4; i++)
        {
            int next_dir = try_dir[i];

            int next_y = y + dy[next_dir];
            int next_x = x + dx[next_dir];

            // 不可以超出迷宮
            if (next_y < 0 || next_y >= 15 ||
                next_x < 0 || next_x >= 15)
            {
                continue;
            }

            // X 才能走
            if (map[next_y][next_x] == 'X')
            {
                y = next_y;
                x = next_x;
                dir = next_dir;

                moved = 1;
                break;
            }
        }

        // 四個方向都不能走
        if (moved == 0)
        {
            printf("This maze has no solution");
            return 0;
        }

        // 題目的 Hint：
        // 如果再次回到起點，就代表沒有解
        if (y == map_enter && x == 0)
        {
            printf("This maze has no solution");
            return 0;
        }
    }
}