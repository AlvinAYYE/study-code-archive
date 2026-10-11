# atomic_thread_fence

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdatomic.h>`
|   |  |   |  |

```c
void atomic_thread_fence( memory_order order );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Establishes memory synchronization ordering of non-atomic and relaxed atomic accesses, as instructed by `order`, without an associated atomic operation. Note however, that at least one atomic operation is required to set up the synchronization, as described below.
依照 order 指定的順序，為非原子存取與 relaxed 原子存取建立記憶體同步順序，但不執行原子操作。請注意，仍須搭配至少一個原子操作才能建立同步，詳見下文。

#### Fence-atomic synchronization

A release fence F in thread A synchronizes-with atomic acquire operation Y in thread B, if
執行緒 A 中的 release 柵欄 F 在以下情況下與執行緒 B 中的原子 acquire 操作 Y 同步：

- there exists an atomic store X (with any memory order),
存在一個原子儲存 X（具有任意記憶體順序），

- Y reads the value written by X (or the value would be written by release sequence headed by X if X were a release operation),
Y 讀取 X 寫入的值（或者，如果 X 是 release 操作，則讀取以 X 為首的 release 序列將寫入的值），

- F is sequenced-before X in thread A.
F 線上程 A 中先於 X 順序執行。

In this case, all non-atomic and relaxed atomic stores that are sequenced-before F in thread A will happen-before all non-atomic and relaxed atomic loads from the same locations made in thread B after Y.
在這種情況下，執行緒 A 中先於 F 順序執行的所有非原子和鬆弛原子儲存，將 happen-before 執行緒 B 中在 Y 之後從相同位置進行的所有非原子和鬆弛原子載入。

#### Atomic-fence synchronization

An atomic release operation X in thread A synchronizes-with an acquire fence F in thread B, if
執行緒 A 中的原子 release 操作 X 在以下情況下與執行緒 B 中的 acquire 柵欄 F 同步：

- there exists an atomic read Y (with any memory order),
存在一個原子讀取 Y（具有任意記憶體順序），

- Y reads the value written by X (or by the release sequence headed by X),
Y 讀取 X 寫入的值（或由以 X 為首的 release 序列寫入的值），

- Y is sequenced-before F in thread B.
Y 線上程 B 中先於 F 順序執行。

In this case, all non-atomic and relaxed atomic stores that are sequenced-before X in thread A will happen-before all non-atomic and relaxed atomic loads from the same locations made in thread B after F.
在這種情況下，執行緒 A 中先於 X 順序執行的所有非原子和鬆弛原子儲存，將 happen-before 執行緒 B 中在 F 之後從相同位置進行的所有非原子和鬆弛原子載入。

#### Fence-fence synchronization

A release fence FA in thread A synchronizes-with an acquire fence FB in thread B, if
執行緒 A 中的 release 柵欄 FA 在以下情況下與執行緒 B 中的 acquire 柵欄 FB 同步：

- there exists an atomic object M,
存在一個原子物件 M，

- there exists an atomic write X (with any memory order) that modifies M in thread A,
存在一個原子寫入 X（具有任意記憶體順序）線上程 A 中修改 M，

- FA is sequenced-before X in thread A,
FA 線上程 A 中先於 X 順序執行，

- there exists an atomic read Y (with any memory order) in thread B,
執行緒 B 中存在一個原子讀取 Y（具有任意記憶體順序），

- Y reads the value written by X (or the value would be written by release sequence headed by X if X were a release operation),
Y 讀取 X 寫入的值（或者，如果 X 是 release 操作，則讀取以 X 為首的 release 序列將寫入的值），

- Y is sequenced-before FB in thread B.
Y 線上程 B 中先於 FB 順序執行。

In this case, all non-atomic and relaxed atomic stores that are sequenced-before FA in thread A will happen-before all non-atomic and relaxed atomic loads from the same locations made in thread B after FB.
在這種情況下，執行緒 A 中先於 FA 順序執行的所有非原子和鬆弛原子儲存，將 happen-before 執行緒 B 中在 FB 之後從相同位置進行的所有非原子和鬆弛原子載入。
Depending on the `order`, this operation
根據 order 的不同，該操作

- has no effects, if `order == memory_order_relaxed`
如果 order == memory_order_relaxed，則沒有效果

- is an acquire fence, if `order == memory_order_acquire || order == memory_order_consume`
如果 order == memory_order_acquire || order == memory_order_consume，則是一個 acquire 柵欄

- is a release fence, if `order == memory_order_release`
如果 order == memory_order_release，則是一個 release 柵欄

- is both an acquire fence and a release fence, if `order == memory_order_acq_rel`
如果 order == memory_order_acq_rel，則既是 acquire 柵欄又是 release 柵欄

- is a sequentially consistent acquire and release fence, if `order == memory_order_seq_cst`
如果 order == memory_order_seq_cst，則是一個順序一致的 acquire 和 release 柵欄

### Parameters

| order  |   | -  |   | the memory ordering executed by this fence  |

### Return value

(none)

### Notes

On x86 (including x86-64), `atomic_thread_fence` functions issue no CPU instructions and only affect compile-time code motion, except for `atomic_thread_fence(memory_order_seq_cst)`.
在 x86（包括 x86-64）上，atomic_thread_fence 函式不發出 CPU 指令，僅影響編譯時程式碼移動，atomic_thread_fence ( memory_order_seq_cst ) 除外。
`atomic_thread_fence` imposes stronger synchronization constraints than an atomic store operation with the same memory_order. While an atomic store-release operation prevents all preceding reads and writes from moving past the store-release, an `atomic_thread_fence` with `memory_order_release` ordering prevents all preceding reads and writes from moving past all subsequent stores.
atomic_thread_fence 比具有相同 memory_order 的原子儲存操作施加更強的同步約束。原子儲存 release 操作阻止所有前面的讀寫越過該儲存 release，而具有 memory_order_release 排序的 atomic_thread_fence 阻止所有前面的讀寫越過所有後續的儲存。

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.17.4.1 The atomic_thread_fence function (p: 204)
7.17.4.1 atomic_thread_fence 函式 (p: 204)
7.17.4.1 atomic_thread_fence 函式 (p: 204)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.17.4.1 The atomic_thread_fence function (p: 278-279)
7.17.4.1 atomic_thread_fence 函式 (p: 278-279)
7.17.4.1 atomic_thread_fence 函式 (p: 278-279)

### See also

atomic_signal_fence
(C11)
|   | fence between a thread and a signal handler executed in the same thread
(function)   |

C++ documentation for atomic_thread_fence

---
來源頁路徑：`en.cppreference.com/c/atomic/atomic_thread_fence.html`
