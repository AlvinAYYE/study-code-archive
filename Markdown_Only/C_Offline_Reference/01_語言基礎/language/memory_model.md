# Memory model

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defines the semantics of computer memory storage for the purpose of the C abstract machine.
定義計算機記憶體儲存的語意，以用於 C 抽象機。
The data storage (memory) available to a C program is one or more contiguous sequences of *bytes*. Each byte in memory has a unique *address*.
C 程式可用的資料儲存（記憶體）是一個或多個連續的位元組序列。記憶體中的每個位元組都有唯一的位址。

### Byte

A *byte* is the smallest addressable unit of memory. It is defined as a contiguous sequence of bits, large enough to hold any member of the *basic execution character set* (the 96 characters that are required to be single-byte). C supports bytes of sizes 8 bits and greater.
位元組是記憶體中可定址的最小單位。它被定義為連續的位序列，足夠大以容納基本執行字符集中的任何成員（必須為單位元組的 96 個字元）。C 支援 8 位及以上的位元組。
The types `char`, `unsigned char`, and `signed char` use one byte for both storage and value representation. The number of bits in a byte is accessible as CHAR_BIT.
型別 char 、unsigned char 和 signed char 的儲存和值表示都使用一個位元組。位元組中的位數可透過 CHAR_BIT 獲取。
For use of bytes to representation values of other fundamental types (including big-endian and little-endian memory layouts), see object representation
關於位元組用於表示其他基本型別值（包括大端和小端記憶體佈局），請參閱 object representation。

### Memory location
記憶體位置

A *memory location* is
記憶體位置是

- an object of scalar type (arithmetic type, pointer type, enumeration type)
一個標量型別（算術型別、指標型別、列舉型別）的物件

- or the largest contiguous sequence of bit-fields of non-zero length
或非零長度的最大連續位域序列

```c
struct S {  char a; // memory location #1  int b : 5; // memory location #2  int c : 11, // memory location #2 (continued)  : 0,  d : 8; // memory location #3  struct  {  int ee : 8; // memory location #4  } e; } obj; // The object 'obj' consists of 4 separate memory locations
```

### Threads and data races

A thread of execution is a flow of control within a program that begins with the invocation of a top-level function by thrd_create or other means.
Any thread can potentially access any object in the program (objects with automatic and thread-local storage duration may still be accessed by another thread through a pointer).
Different threads of execution are always allowed to access (read and modify) different *memory locations* concurrently, with no interference and no synchronization requirements. (note that it is not safe to concurrently update two non-atomic bit-fields in the same structure if all members declared between them are also (non-zero-length) bit-fields, no matter what the sizes of those intervening bit-fields happen to be)
When an evaluation of an expression writes to a memory location and another evaluation reads or modifies the same memory location, the expressions are said to *conflict*. A program that has two conflicting evaluations has a *data race* unless either

- both conflicting evaluations are atomic operations

- one of the conflicting evaluations *happens-before* another (see memory_order)

If a data race occurs, the behavior of the program is undefined.
(in particular, mtx_unlock is *synchronized-with*, and therefore, *happens-before* mtx_lock of the same mutex by another thread, which makes it possible to use mutex locks to guard against data races)
|  | This section is incomplete
Reason: small example or two  |

### Memory order

When a thread reads a value from a memory location, it may see the initial value, the value written in the same thread, or the value written in another thread. See memory_order for details on the order in which writes made from threads become visible to other threads.
|   | (since C11) |

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 3.6 byte (p: TBD)
3.6 位元組（第 TBD 頁）
3.6 位元組（第 TBD 頁）

- 3.14 memory location (p: TBD)
3.14 記憶體位置（第 TBD 頁）
3.14 記憶體位置（第 TBD 頁）

- 5.1.2.4 Multi-threaded executions and data races (p: TBD)
5.1.2.4 多執行緒執行與資料競爭（第 TBD 頁）
5.1.2.4 多執行緒執行與資料競爭（第 TBD 頁）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 3.6 byte (p: TBD)
3.6 位元組（第 TBD 頁）
3.6 位元組（第 TBD 頁）

- 3.14 memory location (p: TBD)
3.14 記憶體位置（第 TBD 頁）
3.14 記憶體位置（第 TBD 頁）

- 5.1.2.4 Multi-threaded executions and data races (p: TBD)
5.1.2.4 多執行緒執行與資料競爭（第 TBD 頁）
5.1.2.4 多執行緒執行與資料競爭（第 TBD 頁）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 3.6 byte (p: 4)
3.6 位元組（第 4 頁）
3.6 位元組（第 4 頁）

- 3.14 memory location (p: 5)
3.14 記憶體位置（第 5 頁）
3.14 記憶體位置（第 5 頁）

- 5.1.2.4 Multi-threaded executions and data races (p: 17-21)
5.1.2.4 多執行緒執行與資料競爭（第 17-21 頁）
5.1.2.4 多執行緒執行與資料競爭（第 17-21 頁）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 3.6 byte (p: 4)
3.6 位元組（第 4 頁）
3.6 位元組（第 4 頁）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 1.6 DEFINITIONS OF TERMS
1.6 術語定義
1.6 術語定義

### See also

C++ documentation for Memory model

---
來源頁路徑：`en.cppreference.com/c/language/memory_model.html`
