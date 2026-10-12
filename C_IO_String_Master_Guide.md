# C 語言字元、字串與 I/O 深度實戰指南
> **涵蓋範圍**：`scanf`、`printf`、`getchar`、字元陣列 (`char[]`) 與 `<string.h>` 核心函式庫  
> **適用目標**：從零掌握底層記憶體行為、解構常見陷阱、精通解題競賽與工程級實務技巧。

---

## 目錄
1. [記憶體本質：字元 (char) 與字元陣列 (char[])](#1-記憶體本質字元-char-與字元陣列-char)
2. [標準輸出神器：printf 深度解析](#2-標準輸出神器-printf-深度解析)
3. [格式化輸入利器：scanf 詳解與地雷區](#3-格式化輸入利器-scanf-詳解與地雷區)
4. [單字元讀取之王：getchar 技巧與緩衝區清理](#4-單字元讀取之王-getchar-技巧與緩衝區清理)
5. [字串處理標準庫：string.h 實戰手冊](#5-字串處理標準庫-stringh-實戰手冊)
6. [五大經典死穴與除錯手冊 (Bug & Traps)](#6-五大經典死穴與除錯手冊-bug--traps)
7. [競賽/專案實戰模板與推薦寫法](#7-競賽專案實戰模板與推薦寫法)

---

## 1. 記憶體本質：字元 (char) 與字元陣列 (char[])

### 1.1 char 的真面目：就是 1 Byte 的整數
在 C 語言中，`char` 本質上是一個 **8-bit 整數**（範圍通常為 `-128 ~ 127` 或 `0 ~ 255`），它透過 **ASCII 編碼表** 對應字元符號。
```c
char c = 'A';
printf("%c\n", c); // 輸出字元: A
printf("%d\n", c); // 輸出 ASCII 碼數值: 65

// 字元可以做加減運算！
char lower = c + 32;       // 'A' + 32 = 'a'
int digit = '7' - '0';     // '7' - '0' = 7 (字元轉整數的最快方式)
```

### 1.2 字元陣列 vs C 字串（Null-Terminator `\0`）
C 語言**沒有原生 `string` 型別**！C 的字串就是「**以 `\0`（ASCII 0）結尾的字元陣列**」。

> [!CAUTION]
> **沒有結尾 `\0` 的字元陣列「不是字串」！**  
> 若傳入 `printf("%s")` 或 `strlen()`，程式會沿著記憶體一路往後讀取垃圾值，直到偶遇 `0`，這會導致**記憶體越界 (Buffer Over-read / Segmentation Fault)**。

```c
// 情況 1: 正確的字串 (自動補 \0)
char s1[] = "Hello";        // 長度為 5+1 = 6 位元組 (['H','e','l','l','o','\0'])

// 情況 2: 手動初始化，確保空間多留 1 格給 '\0'
char s2[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

// 情況 3: 危險！這只是單純的字元陣列，不是 C 字串！
char bad[5] = {'H', 'e', 'l', 'l', 'o'}; // 沒有空間放 '\0'，不能當字串用！
```

### 1.3 `char str[]` vs `char *str`（可修改 vs 唯讀）
```c
char str1[] = "Hello"; // 在 Stack 分配 6 bytes，內容可讀可寫
str1[0] = 'h';         // 合法！str1 變成 "hello"

char *str2 = "Hello";  // 指標指向唯讀的字串常數區 (.rodata)
str2[0] = 'h';         // 致命錯誤！Bus error / Segmentation Fault (未定義行為)
```

---

## 2. 標準輸出神器：printf 深度解析

### 2.1 格式化字元對照表
| 格式符 | 意義 | 典型範例 |
| :--- | :--- | :--- |
| `%d` / `%i` | 有號十進位整數 | `int a = -42; printf("%d", a);` |
| `%u` | 無號十進位整數 | `unsigned int u = 100; printf("%u", u);` |
| `%f` / `%lf` | 浮點數 / 雙精度浮點數 | `double pi = 3.14159; printf("%.2f", pi);` |
| `%c` | 單一字元 | `char ch = 'X'; printf("%c", ch);` |
| `%s` | 以 `\0` 結尾的字串 | `char s[] = "abc"; printf("%s", s);` |
| `%p` | 指標記憶體位址 (十六進位) | `int x; printf("%p", (void*)&x);` |
| `%lld` | 64-bit 長整數 (`long long`) | `long long big = 1LL << 40; printf("%lld", big);` |

### 2.2 進階格式修飾（寬度、對齊、補零、精確度）
格式修飾語法：`%[flags][width][.precision]specifier`

```c
int num = 42;
double val = 3.14159265;
char *str = "ACM";

// 1. 指定寬度與靠右對齊 (預設靠右)
printf("[%5d]\n", num);       // 輸出: [   42]

// 2. 指定靠左對齊 (加上負號 -)
printf("[%-5d]\n", num);      // 輸出: [42   ]

// 3. 前綴補零 (加上 0，常考：時間格式 hh:mm:ss)
printf("%02d:%02d:%02d\n", 9, 5, 2); // 輸出: 09:05:02

// 4. 浮點數精準度 (四捨五入到小數點後 n 位)
printf("%.2f\n", val);        // 輸出: 3.14
printf("%.4f\n", val);        // 輸出: 3.1416

// 5. 字串長度限制 (最多印出前 n 個字元)
printf("%.2s\n", str);        // 輸出: AC

// 6. 動態寬度與精度 (使用星號 *)
int width = 8, prec = 3;
printf("[%*.*f]\n", width, prec, val); // 輸出: [   3.142]
```

---

## 3. 格式化輸入利器：scanf 詳解與地雷區

### 3.1 核心機制：為什麼要加 `&`？
`scanf` 必須修改傳入變數的值，但 C 語言函式呼叫是一律「**傳值 (Call by Value)**」。因此 `scanf` 必須接收「**記憶體位址 (Pointer)**」，才能直接寫入該記憶體的內容：
```c
int x;
scanf("%d", &x); // 必須傳入 x 的位址 &x

char str[50];
scanf("%s", str); // str 本身就是陣列首位址 (等同 &str[0])，所以不必加 &
```

### 3.2 空白跳過規則（極度關鍵！）
- 絕大多數格式符號（如 `%d`、`%f`、`%s`）在讀取前，會**自動吃掉前面的所有空白字元**（空格 `' '`、換行 `'\n'`、定位點 `'\t'`）。
- **唯一例外**：%c。  
  `%c` **不會**自動跳過空白！如果前一次輸入按了 Enter，緩衝區殘留的 `\n` 會直接被 `%c` 當成下一個字元讀走！

> [!TIP]
> **如何讓 `%c` 自動吃掉空白？**  
> 在 `%c` 前面加上一個空格：`scanf(" %c", &ch);`  
> 這個空格代表「先消耗掉前面所有的空白字元（含換行符號），再讀入下一個有效字元」。

### 3.3 防止緩衝區溢位：指定寬度
永遠不要寫裸 `scanf("%s", buf)`！如果使用者輸入超過陣列容量，會導致 Buffer Overflow。
```c
char buf[10];
// 預留 1 格給 '\0'，故最多讀取 9 個字元
scanf("%9s", buf); 
```

### 3.4 正規表達式等級的進階用法：掃描集 (Scan Set `%[...]`)
`scanf` 的 `%[...]` 可以替代傳統容易造成安全問題的 `gets()`：

```c
char line[100];

// 1. 讀取一整行（直到遇到換行符號 \n 為止）
scanf("%[^\n]", line); 

// 2. 只允許輸入英文字母與空格
char alpha[50];
scanf("%[a-zA-Z ]", alpha);

// 3. 略過特定的欄位 (使用 %* 修飾符，只匹配但不賦值)
int year, month, day;
// 輸入 "2026/10/12"，自動丟棄分隔符號 '/'
scanf("%d%*c%d%*c%d", &year, &month, &day);
```

### 3.5 檢查返回值判定 EOF
`scanf` 會回傳**成功配對並指派的變數數量**。遇到輸入結束時回傳 `EOF`（通常為 `-1`）：
```c
int a, b;
// 競賽連續輸入寫法
while (scanf("%d %d", &a, &b) == 2) {
    printf("%d\n", a + b);
}

// 或是 UVa 常見的單純測資判定：
while (scanf("%d", &a) != EOF && a != 0) {
    // 處理直到 a 為 0 結束
}
```

---

## 4. 單字元讀取之王：getchar 技巧與緩衝區清理

### 4.1 核心機制：為什麼 `getchar()` 回傳 `int` 而非 `char`？
```c
int ch = getchar();
```
因為除了 256 種字元值外，`getchar()` 必須能回傳一個特殊的哨兵標記：**`EOF` (-1)**。如果用 `char` 來接，在某些系統上可能會與 ASCII 255 混淆或遺失負號！

### 4.2 經典緩衝區清除技法
當你用 `scanf("%d", &n);` 讀取整數後，使用者按下的 Enter 鍵產生的 `\n` 還留在 stdin 緩衝區中。若緊接著要讀取字元或整行字串，必須清理緩衝區：

```c
int n;
scanf("%d", &n);

// 清理 stdin 直到換行符號或 EOF
int c;
while ((c = getchar()) != '\n' && c != EOF) {
    /* 丟棄殘留字元 */
}

// 現在可以安心讀取下一行的內容了！
char line[100];
fgets(line, sizeof(line), stdin);
```

### 4.3 終極效能：快速 I/O (Fast I/O)
在 UVa / LeetCode 大量測資時，`getchar()` 是最快的輸入核心：
```c
// 超快速整數讀取
int fast_read_int(void) {
    int x = 0, f = 1;
    int c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x * f;
}
```

---

## 5. 字串處理標準庫：string.h 實戰手冊

使用 `<string.h>` 時，牢記核心原則：**操作的目標必須有合法空間，且結尾必須有 `\0`**。

### 5.1 字串長度：`strlen()`
- **功能**：計算字串長度（**不包含** 結尾的 `\0`）。
- **時間複雜度**：$O(N)$（從頭巡訪直到 `\0`）。

> [!WARNING]
> 切忌在迴圈條件式中重複呼叫 `strlen`！
> ```c
> // 極度低效！時間複雜度退化為 O(N^2)
> for (int i = 0; i < strlen(s); i++) { ... }
>
> // 正確且高效寫法：O(N)
> for (int i = 0, len = strlen(s); i < len; i++) { ... }
> // 或直接利用結尾為 0 的特性：
> for (int i = 0; s[i] != '\0'; i++) { ... }
> ```

### 5.2 字串拷貝：`strcpy()` 與 `strncpy()`
```c
char src[] = "Hello";
char dst[10];

// 1. strcpy: 將 src（含 \0）拷貝到 dst
strcpy(dst, src); 

// 2. strncpy: 指定上限拷貝（小心陷阱！）
// 如果 src 長度 >= n，strncpy 不會自動補 '\0'！
char safe_dst[6];
strncpy(safe_dst, "VeryLongString", sizeof(safe_dst) - 1);
safe_dst[sizeof(safe_dst) - 1] = '\0'; // 務必手動封底保證安全！
```

### 5.3 字串串接：`strcat()` 與 `strncat()`
```c
char buf[20] = "Hello, ";
strcat(buf, "World!"); // buf 變成 "Hello, World!"
```

### 5.4 字串比較：`strcmp()` 與 `strncmp()`
**絕不能用 `if (s1 == s2)` 比對字串內容**，這只會比對記憶體指標位址！
- `strcmp(s1, s2) == 0`：兩字串內容完全相同。
- `strcmp(s1, s2) < 0`：字典序 `s1 < s2`。
- `strcmp(s1, s2) > 0`：字典序 `s1 > s2`。

```c
if (strcmp(str, "exit") == 0) {
    printf("離開程式\n");
}
```

### 5.5 字串搜尋：`strchr()` 與 `strstr()`
- `strchr(s, ch)`：在字串 `s` 中搜尋字元 `ch`，回傳首個匹配位址的**指標**（找不到回傳 `NULL`）。
- `strstr(s, sub)`：在字串 `s` 中搜尋子字串 `sub`，回傳首個匹配位址的**指標**。

```c
char text[] = "apples and oranges";
char *p = strstr(text, "and");
if (p != NULL) {
    printf("找到子字串，起始位置索引: %ld\n", p - text); // 印出 7
}
```

### 5.6 字串切割：`strtok()`
`strtok` 會**直接修改原字串**（將分隔符換成 `\0`），第二次呼叫時第一個參數傳 `NULL`：
```c
char line[] = "apple,banana,orange,grape";
char *token = strtok(line, ",");
while (token != NULL) {
    printf("Token: %s\n", token);
    token = strtok(NULL, ","); // 繼續切割下一個
}
```

### 5.7 記憶體層級操作：`memset()`、`memcpy()`、`memmove()`
直接操作二進位 Byte，速度極快：
```c
// 1. memset: 常見於陣列或結構體清零
int arr[100];
memset(arr, 0, sizeof(arr)); // 陣列全部填 0
memset(arr, -1, sizeof(arr)); // 全部填 -1 (因為每個 byte 都是 0xFF)

// 2. memcpy: 記憶體塊複製 (來源與目標不可重疊)
char a[10] = "123456789";
char b[10];
memcpy(b, a, sizeof(a));

// 3. memmove: 支援重疊區塊安全複製 (例如字串向右平移)
char buf[20] = "abcdef";
memmove(buf + 2, buf, 6); // 安全處理重疊記憶體
```

---

## 6. 五大經典死穴與除錯手冊 (Bug & Traps)

### 死穴 1：讀取字串時造成 Buffer Overflow
- ❌ **錯誤**：`char s[5]; scanf("%s", s);`（輸入 `12345` 立即溢位崩潰，因為需要 6 bytes 容納 `\0`）。
-  **正解**：`char s[100]; scanf("%99s", s);` 或改用安全輸入：`fgets(s, sizeof(s), stdin);`。

### 死穴 2：`scanf("%d", &n)` 後立即讀取 `scanf("%c", &ch)`
- ❌ **錯誤**：輸入數字按下 Enter，`ch` 直接吃到了 `\n`。
-  **正解**：`scanf(" %c", &ch);`（在 `%c` 前面留一個空白）。

### 死穴 3：`fgets()` 尾端殘留換行符號 `\n`
- ❌ **現象**：`fgets(buf, 100, stdin);` 會把使用者輸入的 `\n` 一併存入字串中，導致後續 `strcmp` 或輸出多了不必要的換行。
-  **正解（去除換行標準手法）**：
  ```c
  char buf[100];
  if (fgets(buf, sizeof(buf), stdin)) {
      buf[strcspn(buf, "\r\n")] = '\0'; // 精準移除換行符號
  }
  ```

### 死穴 4：將指標常數字串傳入修改函式
- ❌ **錯誤**：
  ```c
  char *str = "hello";
  str[0] = 'H'; // SIGSEGV 崩潰！
  ```
-  **正解**：
  ```c
  char str[] = "hello"; // 宣告為陣列
  str[0] = 'H';
  ```

### 死穴 5：混淆 `sizeof` 與 `strlen`
```c
char arr[100] = "Hello";
char *ptr = arr;

printf("%zu\n", sizeof(arr));  // 100 (陣列佔用的總記憶體位元組數)
printf("%zu\n", strlen(arr));  // 5   (字串有效字元個數)
printf("%zu\n", sizeof(ptr));  // 8 或 4 (指標本身的位元組數，千萬別對指標用 sizeof 取陣列長度！)
```

---

## 7. 競賽/專案實戰模板與推薦寫法

### 模板 1：整行字串安全讀取模板
```c
#include <stdio.h>
#include <string.h>

int main(void) {
    char line[1024];
    // 安全逐行讀取直到檔案結尾
    while (fgets(line, sizeof(line), stdin) != NULL) {
        // 移除行末 \n 與 \r (跨平台 Windows/Linux 相容)
        line[strcspn(line, "\r\n")] = '\0';
        
        if (strlen(line) == 0) continue; // 略過空行
        printf("Read Line: [%s]\n", line);
    }
    return 0;
}
```

### 模板 2：混合型資料輸入模板（先讀整數再讀字串）
```c
#include <stdio.h>
#include <string.h>

int main(void) {
    int test_cases;
    if (scanf("%d", &test_cases) != 1) return 0;
    
    // 吃掉第一行殘留的換行
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
    
    char name[100];
    for (int t = 1; t <= test_cases; t++) {
        if (fgets(name, sizeof(name), stdin)) {
            name[strcspn(name, "\r\n")] = '\0';
            printf("Case %d: Welcome %s!\n", t, name);
        }
    }
    return 0;
}
```

---
*這份教學已儲存至本專案知識庫供隨時查閱。*
