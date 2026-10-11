# Undefined behavior

> 來源：cppreference C 語言參考文件（離線轉換版）。

The C language standard precisely specifies the observable behavior of C language programs, except for the ones in the following categories:
C 語言標準精確地規定了 C 語言程式的可觀察行為，但以下類別除外：

- *undefined behavior* - there are no restrictions on the behavior of the program. Examples of undefined behavior are memory accesses outside of array bounds, signed integer overflow, null pointer dereference, modification of the same scalar more than once in an expression without sequence points, access to an object through a pointer of a different type, etc. Compilers are not required to diagnose undefined behavior (although many simple situations are diagnosed), and the compiled program is not required to do anything meaningful.
未定義行為：標準不限制程式會如何運作。例如，存取陣列範圍之外的記憶體、有號整數溢位、解參考空指標、在沒有順序點的運算式中多次修改同一純量，或透過不同型別的指標存取物件。編譯器不一定要診斷未定義行為（簡單情況通常仍會提示），編譯後的程式也不保證有任何有意義的結果。

- *unspecified behavior* - two or more behaviors are permitted and the implementation is not required to document the effects of each behavior. For example, order of evaluation, whether identical string literals are distinct, etc. Each unspecified behavior results in one of a set of valid results and may produce a different result when repeated in the same program.
未指定行為：允許有兩種或更多種結果，實作不必記錄實際採用哪一種。例如運算式的求值順序，以及內容相同的字串常值是否共用同一儲存空間。每次發生時都會從允許的結果中選出一種，同一程式重複執行也可能得到不同結果。

- *implementation-defined behavior* - unspecified behavior where each implementation documents how the choice is made. For example, number of bits in a byte, or whether signed integer right shift is arithmetic or logical.
實現定義行為 - 每種實現記錄如何選擇該行為的未指定行為。例如，一個位元組中的位數，或者有符號整數右移是算術移位還是邏輯移位。

- *locale-specific behavior* - implementation-defined behavior that depends on the currently chosen locale. For example, whether islower returns true for any character other than the 26 lowercase Latin letters.
語系相關行為：由實作定義，且會依目前選用的語系而變。例如 islower 對 26 個小寫拉丁字母以外的字元是否回傳 true。

(Note: Strictly conforming programs do not depend on any unspecified, undefined, or implementation-defined behavior)
（注意：嚴格符合標準的程式不依賴任何未指定、未定義或實現定義的行為）
The compilers are required to issue diagnostic messages (either errors or warnings) for any programs that violates any C syntax rule or semantic constraint, even if its behavior is specified as undefined or implementation-defined or if the compiler provides a language extension that allows it to accept such program. Diagnostics for undefined behavior are not otherwise required.
程式若違反 C 的語法規則或語意限制，編譯器必須發出診斷訊息（錯誤或警告），即使該情況的行為已定義為未定義或由實作決定，或編譯器透過語言擴充功能接受了該程式。除此之外，標準不要求編譯器診斷未定義行為。

### UB and optimization
UB 與最佳化

Because correct C programs are free of undefined behavior, compilers may produce unexpected results when a program that actually has UB is compiled with optimization enabled:
由於正確的 C 程式不存在未定義行為，當實際存在 UB 的程式在啟用最佳化的情況下編譯時，編譯器可能產生意外的結果：
For example,

#### Signed overflow

```c
int foo(int x) {  return x + 1 > x; // either true or UB due to signed overflow }
```

may be compiled as (demo)
可能被編譯為 ( demo )

```c
foo:  mov eax, 1  ret
```

#### Access out of bounds

```c
int table[4] = {0}; int exists_in_table(int v) {  // return 1 in one of the first 4 iterations or UB due to out-of-bounds access  for (int i = 0; i <= 4; i++)  if (table[i] == v)  return 1;  return 0; }
```

May be compiled as (demo)
可能被編譯為 ( demo )

```c
exists_in_table:  mov eax, 1  ret
```

#### Uninitialized scalar

```c
_Bool p; // uninitialized local variable if (p) // UB access to uninitialized scalar  puts("p is true"); if (!p) // UB access to uninitialized scalar  puts("p is false");
```

May produce the following output (observed with an older version of gcc):
可能產生以下輸出（在舊版本 gcc 中觀察到）：

```c
p is true p is false
```

```c
size_t f(int x) {  size_t a;  if (x) // either x nonzero or UB  a = 42;  return a; }
```

May be compiled as (demo)
可能被編譯為 ( demo )

```c
f:  mov eax, 42  ret
```

#### Invalid scalar

```c
int f(void) {  _Bool b = 0;  unsigned char* p = (unsigned char*)&b;  *p = 10;  // reading from b is now UB  return b == 0; }
```

May be compiled as (demo)
可能被編譯為 ( demo )

```c
f:  mov eax, 11  ret
```

#### Null pointer dereference

```c
int foo(int* p) {  int x = *p;  if (!p)  return x; // Either UB above or this branch is never taken  else  return 0; } int bar() {  int* p = NULL;  return *p; // Unconditional UB }
```

may be compiled as (demo)
可能被編譯為 ( demo )

```c
foo:  xor eax, eax  ret bar:  ret
```

#### Access to pointer passed to realloc

Choose clang to observe the output shown
選擇 clang 以觀察所示輸出
Run this code

```c
#include <stdio.h> #include <stdlib.h> int main(void) {  int *p = (int*)malloc(sizeof(int));  int *q = (int*)realloc(p, sizeof(int));  *p = 1; // UB access to a pointer that was passed to realloc  *q = 2;  if (p == q) // UB access to a pointer that was passed to realloc  printf("%d%d\n", *p, *q); }
```

Possible output:
可能的輸出：

```c
12
```

#### Infinite loop without side-effects

Choose clang to observe the output shown
選擇 clang 以觀察所示輸出
Run this code

```c
#include <stdio.h> int fermat() {  const int MAX = 1000;  // Endless loop with no side effects is UB  for (int a = 1, b = 1, c = 1; 1;)  {  if (((a * a * a) == ((b * b * b) + (c * c * c))))  return 1;  ++a;  if (a > MAX)  {  a = 1;  ++b;  }  if (b > MAX)  {  b = 1;  ++c;  }  if (c > MAX)  c = 1;  }  return 0; } int main(void) {  if (fermat())  puts("Fermat's Last Theorem has been disproved.");  else  puts("Fermat's Last Theorem has not been disproved."); }
```

Possible output:
可能的輸出：

```c
Fermat's Last Theorem has been disproved.
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 3.4 Behavior (p: TBD)
3.4 行為（p: TBD）
3.4 行為（p: TBD）

- 4 Conformance (p: TBD)
4 一致性（p: TBD）
4 一致性（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 3.4 Behavior (p: 3-4)
3.4 行為（p: 3-4）
3.4 行為（p: 3-4）

- 4 Conformance (p: 8)
4 一致性（p: 8）
4 一致性（p: 8）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 3.4 Behavior (p: 3-4)
3.4 行為（p: 3-4）
3.4 行為（p: 3-4）

- 4/2 Undefined behavior (p: 8)
4/2 未定義行為（p: 8）
4/2 未定義行為（p: 8）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 3.4 Behavior (p: 3-4)
3.4 行為（p: 3-4）
3.4 行為（p: 3-4）

- 4/2 Undefined behavior (p: 7)
4/2 未定義行為（p: 7）
4/2 未定義行為（p: 7）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 1.6 DEFINITIONS OF TERMS
1.6 術語定義
1.6 術語定義

### See also

C++ documentation for Undefined behavior

### External links

| 1.  |   | What Every C Programmer Should Know About Undefined Behavior #1/3  |

| 2.  |   | What Every C Programmer Should Know About Undefined Behavior #2/3  |

| 3.  |   | What Every C Programmer Should Know About Undefined Behavior #3/3  |

| 4.  |   | Undefined behavior can result in time travel (among other things, but time travel is the funkiest)  |

| 5.  |   | Understanding Integer Overflow in C/C++  |

| 6.  |   | Undefined Behavior and Fermat’s Last Theorem  |

| 7.  |   | Fun with NULL pointers, part 1 (local exploit in Linux 2.6.30 caused by UB due to null pointer dereference)  |

---
來源頁路徑：`en.cppreference.com/c/language/behavior.html`
