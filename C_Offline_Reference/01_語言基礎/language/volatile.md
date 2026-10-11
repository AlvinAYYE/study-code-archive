# volatile type qualifier

> 來源：cppreference C 語言參考文件（離線轉換版）。

Each individual type in the C type system has several *qualified* versions of that type, corresponding to one, two, or all three of the const, `volatile`, and, for pointers to object types, restrict qualifiers. This page describes the effects of the `volatile` qualifier.
C 型別系統中的每一個單獨型別都有該型別的多個限定版本，分別對應 const、volatile 以及（對指向物件型別的指標而言）restrict 限定符中的一個、兩個或全部三個。本頁描述 volatile 限定符的效果。
Every access (both read and write) made through an lvalue expression of volatile-qualified type is considered an observable side effect for the purpose of optimization and is evaluated strictly according to the rules of the abstract machine (that is, all writes are completed at some time before the next sequence point). This means that within a single thread of execution, a volatile access cannot be optimized out or reordered relative to another visible side effect that is separated by a sequence point from the volatile access.
透過具有 volatile 限定的左值表示式進行的每一次訪問（讀和寫）在最佳化時都被視為可觀察的副作用，並嚴格按照抽象機的規則求值（即所有寫入都在下一個序列點之前的某個時刻完成）。這意味著在單個執行執行緒內，volatile 訪問不能被最佳化掉，也不能相對於另一個由序列點與該 volatile 訪問隔開的可見副作用進行重排序。
A cast of a non-volatile value to a volatile type has no effect. To access a non-volatile object using volatile semantics, its address must be cast to a pointer-to-volatile and then the access must be made through that pointer.
將非 volatile 的值強制轉換為 volatile 型別沒有作用。要以 volatile 語意訪問非 volatile 物件，必須先將其位址強制轉換為指向 volatile 的指標，然後透過該指標進行訪問。
Any attempt to read or write to an object whose type is volatile-qualified through a non-volatile lvalue results in undefined behavior:
任何試圖透過非 volatile 左值讀寫型別帶 volatile 限定的物件的操作，都會導致未定義行為：

```c
volatile int n = 1; // object of volatile-qualified type int* p = (int*)&n; int val = *p; // undefined behavior
```

A member of a volatile-qualified structure or union type acquires the qualification of the type it belongs to (both when accessed using the `**.**` operator or the `**->**` operator):
帶 volatile 限定的結構體或聯合體型別的成員會獲得其所屬型別的限定（無論使用 . 運運算元還是 -> 運運算元訪問時都是如此）：

```c
struct s { int i; const int ci; } s; // the type of s.i is int, the type of s.ci is const int volatile struct s vs; // the types of vs.i and vs.ci are volatile int and const volatile int
```

If an array type is declared with the volatile type qualifier (through the use of typedef), the array type is not volatile-qualified, but its element type is.
|   | (until C23) |

An array type and its element type are always considered to be identically volatile-qualified.
|   | (since C23) |

```c
typedef int A[2][3]; volatile A a = {{4, 5, 6}, {7, 8, 9}}; // array of array of volatile int int* pi = a[0]; // Error: a[0] has type volatile int* void *unqual_ptr = a; // OK until C23; error since C23 // Notes: clang applies the rule in C++/C23 even in C89-C17 modes
```

If a function type is declared with the volatile type qualified (through the use of typedef), the behavior is undefined.
如果函式型別被宣告為帶 volatile 型別限定（透過使用 typedef），則行為是未定義行為。

In a function declaration, the keyword `volatile` may appear inside the square brackets that are used to declare an array type of a function parameter. It qualifies the pointer type to which the array type is transformed.
The following two declarations declare the same function:

```c
void f(double x[volatile], const double y[volatile]); void f(double * volatile x, const double * volatile y);
```
|   | (since C99) |

A pointer to a non-volatile type can be implicitly converted to a pointer to the volatile-qualified version of the same or compatible type. The reverse conversion requires a cast expression.
指向非 volatile 型別的指標可以隱式轉換為指向相同或相容型別的 volatile 限定版本的指標。反向轉換則需要強制轉換表示式。

```c
int* p = 0; volatile int* vp = p; // OK: adds qualifiers (int to volatile int) p = vp; // Error: discards qualifiers (volatile int to int) p = (int*)vp; // OK: cast
```

Note that pointer to pointer to `T` is not convertible to pointer to pointer to `volatile T`; for two types to be compatible, their qualifications must be identical:
注意，指向 T 的指標的指標不能轉換為指向 volatile T 的指標的指標；要使兩個型別相容，它們的限定必須完全相同：

```c
char *p = 0; volatile char **vpp = &p; // Error: char* and volatile char* are not compatible types char * volatile *pvp = &p; // OK, adds qualifiers (char* to char*volatile)
```

### Uses of volatile
volatile 的用途

1) static `volatile` objects model memory-mapped I/O ports, and `static` `const` `volatile` objects model memory-mapped input ports, such as a real-time clock:
```c
volatile short *ttyport = (volatile short*)TTYPORT_ADDR; for(int i = 0; i < N; ++i)  *ttyport = a[i]; // *ttyport is an lvalue of type volatile short
```

2) `static` `volatile` objects of type sig_atomic_t are used for communication with signal handlers.

3) `volatile` variables that are local to a function that contains an invocation of the setjmp macro are the only local variables guaranteed to retain their values after longjmp returns.

4) In addition, volatile variables can be used to disable certain forms of optimization, e.g. to disable dead store elimination or constant folding for micro-benchmarks.

Note that volatile variables are not suitable for communication between threads; they do not offer atomicity, synchronization, or memory ordering. A read from a volatile variable that is modified by another thread without synchronization or concurrent modification from two unsynchronized threads is undefined behavior due to a data race.
注意，volatile 變數不適合用於執行緒間通訊；它們不提供原子性、同步或記憶體排序。在沒有同步的情況下讀取被另一個執行緒修改的 volatile 變數，或者兩個未同步的執行緒對其併發修改，都會因資料競爭而構成未定義行為。

### Keywords

volatile

### Example

demonstrates the use of volatile to disable optimizations
演示了 volatile 用於禁用最佳化的用法
Run this code

```c
#include <stdio.h> #include <time.h> int main(void) {  clock_t t = clock();  double d = 0.0;  for (int n = 0; n < 10000; ++n)  for (int m = 0; m < 10000; ++m)  d += d * n * m; // reads from and writes to a non-volatile   printf("Modified a non-volatile variable 100m times. "  "Time used: %.2f seconds\n",  (double)(clock() - t)/CLOCKS_PER_SEC);  t = clock();  volatile double vd = 0.0;  for (int n = 0; n < 10000; ++n)  for (int m = 0; m < 10000; ++m) {  double prod = vd * n * m; // reads from a volatile  vd += prod; // reads from and writes to a volatile  }   printf("Modified a volatile variable 100m times. "  "Time used: %.2f seconds\n",  (double)(clock() - t)/CLOCKS_PER_SEC); }
```

Possible output:
可能的輸出：

```c
Modified a non-volatile variable 100m times. Time used: 0.00 seconds Modified a volatile variable 100m times. Time used: 0.79 seconds
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.7.3 Type qualifiers (p: 87-90)
6.7.3 型別限定符（p: 87-90）
6.7.3 型別限定符（p: 87-90）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.7.3 Type qualifiers (p: 121-123)
6.7.3 型別限定符（p: 121-123）
6.7.3 型別限定符（p: 121-123）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.7.3 Type qualifiers (p: 108-110)
6.7.3 型別限定符（p: 108-110）
6.7.3 型別限定符（p: 108-110）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 6.5.3 Type qualifiers
6.5.3 型別限定符
6.5.3 型別限定符

### See also

C++ documentation for cv (`const` and `volatile`) type qualifiers

---
來源頁路徑：`en.cppreference.com/c/language/volatile.html`
