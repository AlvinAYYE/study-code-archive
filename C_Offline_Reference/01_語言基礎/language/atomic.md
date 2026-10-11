# Atomic types

> 來源：cppreference C 語言參考文件（離線轉換版）。

### Syntax

|   |

| `**_Atomic**` `**(**` type-name `**)**`  |   | (1)  |   | (since C11)  |

|   |

| `**_Atomic**` type-name  |   | (2)  |   | (since C11)  |

|   |

1) Use as a type specifier; this designates a new atomic type

2) Use as a type qualifier; this designates the atomic version of type-name. In this role, it may be mixed with const, volatile, and restrict, although unlike other qualifiers, the atomic version of type-name may have a different size, alignment, and object representation.

| type-name  |   | -  |   | any type other than array or function. For (1), type-name also cannot be atomic or cvr-qualified  |

The header <stdatomic.h> defines many convenience type aliases, from atomic_bool to atomic_uintmax_t, which simplify the use of this keyword with built-in and library types.
標頭檔 <stdatomic.h> 定義了許多便捷型別別名，從 atomic_bool 到 atomic_uintmax_t，簡化了此關鍵字與內建型別和庫型別的使用。

```c
_Atomic const int* p1; // p is a pointer to an atomic const int const atomic_int* p2; // same const _Atomic(int)* p3; // same
```

If the macro constant `__STDC_NO_ATOMICS__` is defined by the compiler, the keyword `_Atomic` is not provided.
如果編譯器定義了宏常量 __STDC_NO_ATOMICS__，則不提供關鍵字 _Atomic。

### Explanation

Objects of atomic types are the only objects that are free from data races; that is, they may be modified by two threads concurrently or modified by one and read by another.
原子型別的物件是唯一不受資料競爭影響的物件；也就是說，它們可以被兩個執行緒併發修改，或被一個執行緒修改、被另一個執行緒讀取。
Each atomic object has its own associated *modification order*, which is a total order of modifications made to that object. If, from some thread's point of view, modification `A` of some atomic `M` happens-before modification `B` of the same atomic `M`, then in the modification order of `M`, `A` occurs before `B`.
每個原子物件都有自己的相關修改順序，即對該物件所做的修改的全序。如果從某個執行緒的角度看，對某個原子 M 的修改 A happens-before 同一原子 M 的修改 B，則在 M 的修改順序中，A 出現在 B 之前。
Note that although each atomic object has its own modification order, there is no single total order; different threads may observe modifications to different atomic objects in different orders.
注意，儘管每個原子物件都有自己的修改順序，但不存在單一的全序；不同的執行緒可能以不同的順序觀察對不同原子物件的修改。
There are four coherence kinds that are guaranteed for all atomic operations:
對所有原子操作保證以下四種一致性：

- **write-write coherence**: If an operation `A` that modifies an atomic object `M` *happens-before* an operation `B` that modifies `M`, then `A` appears earlier than `B` in the modification order of `M`.
寫-寫一致性：如果修改原子物件 M 的操作 A happens-before 修改 M 的操作 B，則 A 在 M 的修改順序中出現在 B 之前。

- **read-read coherence**: If a value computation `A` of an atomic object `M` happens before a value computation `B` of `M`, and `A` takes its value from a side effect `X` on `M`, then the value computed by `B` is either the value stored by `X` or is the value stored by a side effect `Y` on `M`, where `Y` appears later than `X` in the modification order of `M`.
讀-讀一致性：如果原子物件 M 的值計算 A happens-before M 的值計算 B，並且 A 的值取自 M 上的副作用 X，則 B 計算的值要麼是 X 儲存的值，要麼是 M 上的副作用 Y 儲存的值，其中 Y 在 M 的修改順序中出現在 X 之後。

- **read-write coherence**: If a value computation `A` of an atomic object `M` *happens-before* an operation `B` on `M`, then `A` takes its value from a side effect `X` on `M`, where `X` appears before `B` in the modification order of `M`.
讀-寫一致性：如果原子物件 M 的值計算 A happens-before M 上的操作 B，則 A 的值取自 M 上的副作用 X，其中 X 在 M 的修改順序中出現在 B 之前。

- **write-read coherence**: If a side effect `X` on an atomic object `M` *happens-before* a value computation `B` of `M`, then the evaluation `B` takes its value from `X` or from a side effect `Y` that appears after `X` in the modification order of `M`.
寫-讀一致性：如果原子物件 M 上的副作用 X happens-before M 的值計算 B，則求值 B 的值取自 X，或取自在 M 的修改順序中出現在 X 之後的副作用 Y。

Some atomic operations are also synchronization operations; they may have additional release semantics, acquire semantics, or sequentially-consistent semantics. See memory_order.
某些原子操作也是同步操作；它們可能具有額外的釋放語意、獲取語意或順序一致性語意。參見 memory_order。
Built-in increment and decrement operators and compound assignment are read-modify-write atomic operations with total sequentially consistent ordering (as if using memory_order_seq_cst). If less strict synchronization semantics are desired, the standard library functions may be used instead.
內建遞增和遞減運運算元以及複合賦值是讀-修改-寫原子操作，具有完全順序一致的順序（如同使用 memory_order_seq_cst）。如果需要較不嚴格的同步語意，可以使用標準函式庫函式。
Atomic properties are only meaningful for lvalue expressions. Lvalue-to-rvalue conversion (which models a memory read from an atomic location to a CPU register) strips atomicity along with other qualifiers.
原子屬性僅對左值表示式有意義。左值到右值轉換（將原子位置的記憶體讀取建模為到 CPU 暫存器的讀取）會剝離原子性以及其他限定符。

|  | This section is incomplete
Reason: more, review interaction with memory_order and atomic library pages  |

### Notes

Accessing a member of an atomic struct/union is undefined behavior.
訪問原子結構體/聯合體的成員是未定義行為。
The library type `sig_atomic_t` does not provide inter-thread synchronization or memory ordering, only atomicity.
庫型別 sig_atomic_t 不提供執行緒間同步或記憶體順序，僅提供原子性。
The volatile types do not provide inter-thread synchronization, memory ordering, or atomicity.
易變型別不提供執行緒間同步、記憶體順序或原子性。
Implementations are recommended to ensure that the representation of `_Atomic(T)` in C is same as that of `std::atomic<T>` in C++ for every possible type `T`. The mechanisms used to ensure atomicity and memory ordering should be compatible.
建議實現確保 C 中 _Atomic(T) 的表示與 C++ 中 std::atomic<T> 對每個可能的型別 T 相同。用於確保原子性和記憶體順序的機制應該是相容的。

### Keywords

_Atomic

### Example

Run this code

```c
#include <stdatomic.h> #include <stdio.h> #include <threads.h> atomic_int acnt; int cnt; int f(void* thr_data) {  for (int n = 0; n < 1000; ++n)  {  ++cnt;  ++acnt;  // for this example, relaxed memory order is sufficient, e.g.  // atomic_fetch_add_explicit(&acnt, 1, memory_order_relaxed);  }  return 0; } int main(void) {  thrd_t thr[10];  for (int n = 0; n < 10; ++n)  thrd_create(&thr[n], f, NULL);  for (int n = 0; n < 10; ++n)  thrd_join(thr[n], NULL);  printf("The atomic counter is %u\n", acnt);  printf("The non-atomic counter is %u\n", cnt); }
```

Possible output:
可能的輸出：

```c
The atomic counter is 10000 The non-atomic counter is 8644
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.7.2.4 Atomic type specifiers (p: TBD)
6.7.2.4 原子型別說明符 (p: TBD)
6.7.2.4 原子型別說明符 (p: TBD)

- 7.17 Atomics <stdatomic.h> (p: TBD)
7.17 原子操作 <stdatomic.h> (p: TBD)
7.17 原子操作 <stdatomic.h> (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.7.2.4 Atomic type specifiers (p: 87)
6.7.2.4 原子型別說明符 (p: 87)
6.7.2.4 原子型別說明符 (p: 87)

- 7.17 Atomics <stdatomic.h> (p: 200-209)
7.17 原子操作 <stdatomic.h> (p: 200-209)
7.17 原子操作 <stdatomic.h> (p: 200-209)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.7.2.4 Atomic type specifiers (p: 121)
6.7.2.4 原子型別說明符 (p: 121)
6.7.2.4 原子型別說明符 (p: 121)

- 7.17 Atomics <stdatomic.h> (p: 273-286)
7.17 原子操作 <stdatomic.h> (p: 273-286)
7.17 原子操作 <stdatomic.h> (p: 273-286)

### See also

| **Concurrency support library**  |

C++ documentation for atomic

---
來源頁路徑：`en.cppreference.com/c/language/atomic.html`
