# atomic_signal_fence

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdatomic.h>`
|   |  |   |  |

```c
void atomic_signal_fence( memory_order order );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Establishes memory synchronization ordering of non-atomic and relaxed atomic accesses, as instructed by `order`, between a thread and a signal handler executed on the same thread. This is equivalent to atomic_thread_fence, except no CPU instructions for memory ordering are issued. Only reordering of the instructions by the compiler is suppressed as `order` instructs. For example, a fence with release semantics prevents reads or writes from being moved past subsequent writes and a fence with acquire semantics prevents reads or writes from being moved ahead of preceding reads.
依照 order 指定的順序，在執行緒與同一執行緒中的訊號處理常式之間，為非原子及 relaxed 原子存取建立記憶體同步順序。它的作用類似 atomic_thread_fence，但不會發出用來排序記憶體存取的 CPU 指令，只會依 order 限制編譯器重新排列指令。例如，release 屏障會阻止讀取或寫入移到後續寫入之後；acquire 屏障則會阻止讀取或寫入移到先前讀取之前。

### Parameters

| order  |   | -  |   | the memory ordering executed by this fence  |

### Return value

(none)

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.17.4.2 The atomic_signal_fence function (p: 204-205)
7.17.4.2 atomic_signal_fence 函式（頁：204-205）
7.17.4.2 atomic_signal_fence 函式（頁：204-205）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.17.4.2 The atomic_signal_fence function (p: 279)
7.17.4.2 atomic_signal_fence 函式（頁：279）
7.17.4.2 atomic_signal_fence 函式（頁：279）

### See also

atomic_thread_fence
(C11)
|   | generic memory order-dependent fence synchronization primitive
(function)   |

C++ documentation for atomic_signal_fence

---
來源頁路徑：`en.cppreference.com/c/atomic/atomic_signal_fence.html`
