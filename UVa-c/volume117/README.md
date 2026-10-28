# UVa Volume 117

本卷共收錄 4 題 C 題目檔，以下依題號排序。

<a id="uva-11727_cost-cutting"></a>
### UVa 11727 — Cost Cutting／削減成本

- 原始碼：[11727_cost-cutting.c](11727_cost-cutting.c)
- 演算法：中位數（Sorting, Math）

**English description:**

Each case supplies the salaries of three employees. To remove the highest and lowest salaries, find the middle value and output it with the case number.

**中文詳細描述：**

每組輸入三名員工的薪資，為了裁掉最高與最低薪資者，需要找出三數中的中位數。可排序或排除最大、最小值，最後以指定的案例格式輸出中間薪資。

<a id="uva-11729_commando-war"></a>
### UVa 11729 — Commando War／突擊隊作戰

- 原始碼：[11729_commando-war.c](11729_commando-war.c)
- 演算法：貪心排序、排程（Greedy, Scheduling）

**English description:**

Each soldier requires a briefing time before independently carrying out a job that takes an execution time. Briefings occur one at a time; order the soldiers to minimize when all jobs finish, and output that minimum completion time.

**中文詳細描述：**

每位士兵有簡報時間 `B` 與任務執行時間 `J`。指揮官一次只能為一人簡報，但士兵聽完後可獨立執行任務；將 `J` 較長者優先簡報，可最小化所有任務完成的時刻，最後輸出該最短總時間。

<a id="uva-11764_jumping-mario"></a>
### UVa 11764 — Jumping Mario／瑪利歐跳躍

- 原始碼：[11764_jumping-mario.c](11764_jumping-mario.c)
- 演算法：相鄰比較（Array, Simulation）

**English description:**

Given the heights of consecutive walls, count how many transitions go to a higher wall and how many go to a lower wall. Equal adjacent heights count as neither; output both counts for each case.

**中文詳細描述：**

每組輸入依序給出瑪利歐遇到的牆高。逐一比較相鄰兩面牆，後者較高時計為一次 high jump，較低時計為一次 low jump，相等則不計，最後依案例格式輸出兩種次數。

<a id="uva-11799_horror-dash"></a>
### UVa 11799 — Horror Dash／恐怖衝刺

- 原始碼：[11799_horror-dash.c](11799_horror-dash.c)
- 演算法：最大值搜尋（Linear Scan）

**English description:**

Each case lists the running speeds of all students chased by a clown. The clown must match the fastest student, so find and output the maximum speed with the case number.

**中文詳細描述：**

每組輸入列出所有學生的奔跑速度。小丑若要追上所有人，速度至少要等於其中最大值；以一次線性掃描找出最快速度，再連同案例編號輸出。
