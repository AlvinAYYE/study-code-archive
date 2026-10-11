# memory_order

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdatomic.h>`
|   |  |   |  |

```c
enum memory_order {  memory_order_relaxed,  memory_order_consume,  memory_order_acquire,  memory_order_release,  memory_order_acq_rel,  memory_order_seq_cst };
```
|   |   |   |  (since C11)  |

|  |  |  |  |

`memory_order` specifies how memory accesses, including regular, non-atomic memory accesses, are to be ordered around an atomic operation. Absent any constraints on a multi-core system, when multiple threads simultaneously read and write to several variables, one thread can observe the values change in an order different from the order another thread wrote them. Indeed, the apparent order of changes can even differ among multiple reader threads. Some similar effects can occur even on uniprocessor systems due to compiler transformations allowed by the memory model.
memory_order 指定包括常規非原子記憶體在內的記憶體訪問如何圍繞原子操作排序。在多核系統上沒有任何約束時，當多個執行緒同時讀寫多個變數時，一個執行緒觀察到的值變化順序可能與另一個執行緒寫入它們的順序不同。實際上，變化的表觀順序甚至可能在多個讀取執行緒之間不同。即使在單處理器系統上，由於記憶體模型允許的編譯器變換，也可能出現一些類似的效果。
The default behavior of all atomic operations in the language and the library provides for *sequentially consistent ordering* (see discussion below). That default can hurt performance, but the library's atomic operations can be given an additional `memory_order` argument to specify the exact constraints, beyond atomicity, that the compiler and processor must enforce for that operation.
語言和庫中所有原子操作的預設行為提供順序一致排序（見下文討論）。該預設行為可能損害效能，但庫的原子操作可以額外傳入 memory_order 參數，以指定編譯器和處理器必須為該操作強制執行的、超出原子性的確切約束。

### Constants

Defined in header `<stdatomic.h>`

| Value  |   | Explanation  |

| `memory_order_relaxed`  |   | Relaxed operation: there are no synchronization or ordering constraints imposed on other reads or writes, only this operation's atomicity is guaranteed (see Relaxed ordering below).  |

| `memory_order_consume`
(deprecated in C++26)  |   | A load operation with this memory order performs a *consume operation* on the affected memory location: no reads or writes in the current thread dependent on the value currently loaded can be reordered before this load. Writes to data-dependent variables in other threads that release the same atomic variable are visible in the current thread. On most platforms, this affects compiler optimizations only (see Release-Consume ordering below).  |

| `memory_order_acquire`  |   | A load operation with this memory order performs the *acquire operation* on the affected memory location: no reads or writes in the current thread can be reordered before this load. All writes in other threads that release the same atomic variable are visible in the current thread (see Release-Acquire ordering below).  |

| `memory_order_release`  |   | A store operation with this memory order performs the *release operation*: no reads or writes in the current thread can be reordered after this store. All writes in the current thread are visible in other threads that acquire the same atomic variable (see Release-Acquire ordering below) and writes that carry a dependency into the atomic variable become visible in other threads that consume the same atomic (see Release-Consume ordering below).  |

| `memory_order_acq_rel`  |   | A read-modify-write operation with this memory order is both an *acquire operation* and a *release operation*. No memory reads or writes in the current thread can be reordered before the load, nor after the store. All writes in other threads that release the same atomic variable are visible before the modification and the modification is visible in other threads that acquire the same atomic variable.  |

| `memory_order_seq_cst`  |   | A load operation with this memory order performs an *acquire operation*, a store performs a *release operation*, and read-modify-write performs both an *acquire operation* and a *release operation*, plus a single total order exists in which all threads observe all modifications in the same order (see Sequentially-consistent ordering below).  |

|  | This section is incomplete
Reason: happens-before and other concepts, as in C++, but keep modification orders and the four consistencies in c/language/atomic  |

|  | This section is incomplete
Reason: when doing above, don't forget that although happens-before wasn't acyclic in C11 as published, this was updated to match C++11 via DR 401  |

#### Relaxed ordering

Atomic operations tagged `memory_order_relaxed` are not synchronization operations; they do not impose an order among concurrent memory accesses. They only guarantee atomicity and modification order consistency.
標記為 memory_order_relaxed 的原子操作不是同步操作；它們不對併發記憶體訪問施加順序。它們僅保證原子性和修改順序一致性。
For example, with `x` and `y` initially zero,
例如，x 和 y 初始為零時，
`// Thread 1: r1 = atomic_load_explicit(y, memory_order_relaxed); // A atomic_store_explicit(x, r1, memory_order_relaxed); // B // Thread 2: r2 = atomic_load_explicit(x, memory_order_relaxed); // C atomic_store_explicit(y, 42, memory_order_relaxed); // D` is allowed to produce `r1 == r2 && r2 == 42` because, although A is *sequenced-before* B within thread 1 and C is *sequenced before* D within thread 2, nothing prevents D from appearing before A in the modification order of `y`, and B from appearing before C in the modification order of `x`. The side-effect of D on `y` could be visible to the load A in thread 1 while the side effect of B on `x` could be visible to the load C in thread 2. In particular, this may occur if D is completed before C in thread 2, either due to compiler reordering or at runtime.
// 執行緒 1：r1 = atomic_load_explicit ( y , memory_order_relaxed ); // A atomic_store_explicit ( x , r1 , memory_order_relaxed ); // B // 執行緒 2：r2 = atomic_load_explicit ( x , memory_order_relaxed ); // C atomic_store_explicit ( y , 42 , memory_order_relaxed ); // D 被允許產生 r1 == r2 && r2 == 42，因為儘管 A 線上程 1 中先於 B 順序執行，C 線上程 2 中先於 D 順序執行，但沒有任何東西阻止 D 在 y 的修改順序中出現在 A 之前，以及 B 在 x 的修改順序中出現在 C 之前。D 對 y 的副作用可能對執行緒 1 中的載入 A 可見，而 B 對 x 的副作用可能對執行緒 2 中的載入 C 可見。特別是，如果 D 線上程 2 中在 C 之前完成（無論是由於編譯器重排序還是在執行時），就可能出現這種情況。
Typical use for relaxed memory ordering is incrementing counters, such as the reference counters , since this only requires atomicity, but not ordering or synchronization .
鬆弛記憶體順序的典型用途是遞增計數器，例如引用計數器，因為這僅需要原子性，而不需要順序或同步。

#### Release-Consume ordering

If an atomic store in thread A is tagged `memory_order_release`, an atomic load in thread B from the same variable is tagged `memory_order_consume`, and the load in thread B reads a value written by the store in thread A, then the store in thread A is *dependency-ordered before* the load in thread B.
如果執行緒 A 中的原子儲存標記為 memory_order_release，執行緒 B 中對同一變數的原子載入標記為 memory_order_consume，並且執行緒 B 中的載入讀取了執行緒 A 中的儲存寫入的值，則執行緒 A 中的儲存按依賴序先於（dependency-ordered before）執行緒 B 中的載入。
All memory writes (non-atomic and relaxed atomic) that *happened-before* the atomic store from the point of view of thread A, become *visible side-effects* within those operations in thread B into which the load operation *carries dependency*, that is, once the atomic load is completed, those operators and functions in thread B that use the value obtained from the load are guaranteed to see what thread A wrote to memory.
所有從執行緒 A 的角度看發生在該原子儲存之前的記憶體寫入（非原子和 relaxed 原子），成為執行緒 B 中那些承載該載入操作所攜帶依賴的操作內的可見副作用，也就是說，一旦原子載入完成，執行緒 B 中那些使用從載入獲得的值的運運算元和函式保證能看到執行緒 A 寫入記憶體的內容。
The synchronization is established only between the threads *releasing* and *consuming* the same atomic variable. Other threads can see different order of memory accesses than either or both of the synchronized threads.
同步僅在釋放和消費同一原子變數的執行緒之間建立。其他執行緒可能觀察到與任一或全部已同步執行緒不同的記憶體訪問順序。
On all mainstream CPUs other than DEC Alpha, dependency ordering is automatic, no additional CPU instructions are issued for this synchronization mode, only certain compiler optimizations are affected (e.g. the compiler is prohibited from performing speculative loads on the objects that are involved in the dependency chain).
在除 DEC Alpha 之外的所有主流 CPU 上，依賴排序是自動的，此同步模式不會發出額外的 CPU 指令，僅影響某些編譯器最佳化（例如，禁止編譯器對依賴鏈中涉及的物件執行推測性載入）。
Typical use cases for this ordering involve read access to rarely written concurrent data structures (routing tables, configuration, security policies, firewall rules, etc) and publisher-subscriber situations with pointer-mediated publication, that is, when the producer publishes a pointer through which the consumer can access information: there is no need to make everything else the producer wrote to memory visible to the consumer (which may be an expensive operation on weakly-ordered architectures). An example of such scenario is `rcu_dereference`.
此排序的典型用例涉及對很少寫入的併發資料結構的讀取訪問（路由表、配置、安全策略、防火牆規則等），以及透過指標媒介釋出的釋出者-訂閱者場景，即生產者釋出一個指標，消費者透過該指標可以訪問資訊：無需將生產者寫入記憶體的其他所有內容對消費者可見（在弱排序架構上這可能是開銷很大的操作）。此類場景的一個例子是 rcu_dereference。
Note that currently (2/2015) no known production compilers track dependency chains: consume operations are lifted to acquire operations.
注意，目前（2/2015）沒有已知的生產級編譯器會跟蹤依賴鏈：consume 操作被提升為 acquire 操作。

#### Release sequence

If some atomic is store-released and several other threads perform read-modify-write operations on that atomic, a "release sequence" is formed: all threads that perform the read-modify-writes to the same atomic synchronize with the first thread and each other even if they have no `memory_order_release` semantics. This makes single producer - multiple consumers situations possible without imposing unnecessary synchronization between individual consumer threads.
如果某個原子變數被 store-release，而其他若干執行緒對該原子變數執行讀-改-寫操作，則形成一個「釋放序列」：所有對該同一原子變數執行讀-改-寫的執行緒與第一個執行緒以及彼此同步，即使它們不具有 memory_order_release 語意。這使得單生產者-多消費者場景成為可能，而無需在各個消費者執行緒之間施加不必要的同步。

#### Release-Acquire ordering

If an atomic store in thread A is tagged `memory_order_release`, an atomic load in thread B from the same variable is tagged `memory_order_acquire`, and the load in thread B reads a value written by the store in thread A, then the store in thread A *synchronizes-with* the load in thread B.
如果執行緒 A 中的原子儲存標記為 memory_order_release，執行緒 B 中對同一變數的原子載入標記為 memory_order_acquire，並且執行緒 B 中的載入讀取了執行緒 A 中的儲存寫入的值，則執行緒 A 中的儲存與執行緒 B 中的載入同步（synchronizes-with）。
All memory writes (including non-atomic and relaxed atomic) that *happened-before* the atomic store from the point of view of thread A, become *visible side-effects* in thread B. That is, once the atomic load is completed, thread B is guaranteed to see everything thread A wrote to memory. This promise only holds if B actually returns the value that A stored, or a value from later in the release sequence.
所有從執行緒 A 的角度看發生在該原子儲存之前的記憶體寫入（包括非原子和 relaxed 原子），成為執行緒 B 中的可見副作用。也就是說，一旦原子載入完成，執行緒 B 保證能看到執行緒 A 寫入記憶體的所有內容。此保證僅在 B 實際傳回 A 儲存的值，或釋放序列中較後位置的值時才成立。
The synchronization is established only between the threads *releasing* and *acquiring* the same atomic variable. Other threads can see different order of memory accesses than either or both of the synchronized threads.
同步僅在釋放和獲取同一原子變數的執行緒之間建立。其他執行緒可能觀察到與任一或全部已同步執行緒不同的記憶體訪問順序。
On strongly-ordered systems — x86, SPARC TSO, IBM mainframe, etc. — release-acquire ordering is automatic for the majority of operations. No additional CPU instructions are issued for this synchronization mode; only certain compiler optimizations are affected (e.g., the compiler is prohibited from moving non-atomic stores past the atomic store-release or performing non-atomic loads earlier than the atomic load-acquire). On weakly-ordered systems (ARM, Itanium, PowerPC), special CPU load or memory fence instructions are used.
在強排序系統上——如 x86、SPARC TSO、IBM 大型機等——release-acquire 排序對大多數操作是自動的。此同步模式不會發出額外的 CPU 指令；僅影響某些編譯器最佳化（例如，禁止編譯器將非原子儲存移動到原子 store-release 之後，或在原子 load-acquire 之前執行非原子載入）。在弱排序系統（ARM、Itanium、PowerPC）上，使用特殊的 CPU 載入或記憶體屏障指令。
Mutual exclusion locks, such as mutexes or atomic spinlocks, are an example of release-acquire synchronization: when the lock is released by thread A and acquired by thread B, everything that took place in the critical section (before the release) in the context of thread A has to be visible to thread B (after the acquire) which is executing the same critical section.
互斥鎖，如 mutex 或原子 spinlock，是 release-acquire 同步的一個例子：當鎖被執行緒 A 釋放並被執行緒 B 獲取時，在臨界區（釋放之前）內線上程 A 上下文中發生的一切，必須對執行同一臨界區的執行緒 B（獲取之後）可見。

#### Sequentially-consistent ordering

Atomic operations tagged `memory_order_seq_cst` not only order memory the same way as release/acquire ordering (everything that *happened-before* a store in one thread becomes a *visible side effect* in the thread that did a load), but also establish a *single total modification order* of all atomic operations that are so tagged.
標記為 memory_order_seq_cst 的原子操作不僅以與 release/acquire 排序相同的方式排序記憶體（一個執行緒中發生在某儲存之前的一切，成為執行載入的執行緒中的可見副作用），還建立一個針對所有如此標記的原子操作的單一全序修改順序。
Formally,
each `memory_order_seq_cst` operation B that loads from atomic variable M, observes one of the following:
每個從原子變數 M 載入的 memory_order_seq_cst 操作 B，觀察到以下之一：

- the result of the last operation A that modified M, which appears before B in the single total order,
在單一全序中出現在 B 之前的最後一次修改 M 的操作 A 的結果，

- OR, if there was such an A, B may observe the result of some modification on M that is not `memory_order_seq_cst` and does not *happen-before* A,
或者，如果存在這樣的 A，B 可能觀察到 M 的某個並非 memory_order_seq_cst 且不 happen-before A 的修改的結果，

- OR, if there wasn't such an A, B may observe the result of some unrelated modification of M that is not `memory_order_seq_cst`.
或者，如果不存在這樣的 A，B 可能觀察到 M 的某個並非 memory_order_seq_cst 的無關修改的結果。

If there was a `memory_order_seq_cst` atomic_thread_fence operation X *sequenced-before* B, then B observes one of the following:
如果存在一個 sequenced-before B 的 memory_order_seq_cst atomic_thread_fence 操作 X，則 B 觀察到以下之一：

- the last `memory_order_seq_cst` modification of M that appears before X in the single total order,
在單一全序中出現在 X 之前的最後一次 M 的 memory_order_seq_cst 修改，

- some unrelated modification of M that appears later in M's modification order.
在 M 的修改順序中較後出現的 M 的某個無關修改。

For a pair of atomic operations on M called A and B, where A writes and B reads M's value, if there are two `memory_order_seq_cst` atomic_thread_fences X and Y, and if A is *sequenced-before* X, Y is *sequenced-before* B, and X appears before Y in the Single Total Order, then B observes either:
對於 M 上的一對原子操作 A 和 B，其中 A 寫入而 B 讀取 M 的值，如果存在兩個 memory_order_seq_cst atomic_thread_fence X 和 Y，並且 A sequenced-before X、Y sequenced-before B，且 X 在單一全序中出現在 Y 之前，則 B 觀察到以下之一：

- the effect of A,
A 的效果，

- some unrelated modification of M that appears after A in M's modification order.
在 M 的修改順序中出現在 A 之後的 M 的某個無關修改。

For a pair of atomic modifications of M called A and B, B occurs after A in M's modification order if
對於 M 的一對原子修改 A 和 B，B 在 M 的修改順序中出現在 A 之後，如果

- there is a `memory_order_seq_cst` atomic_thread_fence X such that A is *sequenced-before* X and X appears before B in the Single Total Order,
存在一個 memory_order_seq_cst atomic_thread_fence X，使得 A sequenced-before X 且 X 在單一全序中出現在 B 之前，

- or, there is a `memory_order_seq_cst` atomic_thread_fence Y such that Y is *sequenced-before* B and A appears before Y in the Single Total Order,
或者，存在一個 memory_order_seq_cst atomic_thread_fence Y，使得 Y sequenced-before B 且 A 在單一全序中出現在 Y 之前，

- or, there are `memory_order_seq_cst` atomic_thread_fences X and Y such that A is *sequenced-before* X, Y is *sequenced-before* B, and X appears before Y in the Single Total Order.
或者，存在 memory_order_seq_cst atomic_thread_fence X 和 Y，使得 A sequenced-before X、Y sequenced-before B，且 X 在單一全序中出現在 Y 之前。

Note that this means that:
注意，這意味著：

1) as soon as atomic operations that are not tagged `memory_order_seq_cst` enter the picture, the sequential consistency is lost,

2) the sequentially-consistent fences are only establishing total ordering for the fences themselves, not for the atomic operations in the general case (*sequenced-before* is not a cross-thread relationship, unlike *happens-before*).

Sequential ordering may be necessary for multiple producer-multiple consumer situations where all consumers must observe the actions of all producers occurring in the same order.
在多生產者-多消費者場景中，如果所有消費者必須以相同順序觀察所有生產者的操作，則可能需要順序一致性排序。
Total sequential ordering requires a full memory fence CPU instruction on all multi-core systems. This may become a performance bottleneck since it forces the affected memory accesses to propagate to every core.
全順序一致性排序在所有多核系統上需要完整的記憶體屏障 CPU 指令。這可能成為效能瓶頸，因為它強制受影響的記憶體訪問傳播到每個核心。

### Relationship with volatile
與 volatile 的關係

Within a thread of execution, accesses (reads and writes) through volatile lvalues cannot be reordered past observable side-effects (including other volatile accesses) that are separated by a sequence point within the same thread, but this order is not guaranteed to be observed by another thread, since volatile access does not establish inter-thread synchronization.
在執行執行緒內，透過 volatile 左值進行的訪問（讀取和寫入）不能被重排越過由同一執行緒內序列點分隔的可觀察副作用（包括其他 volatile 訪問），但不保證另一執行緒能觀察到此順序，因為 volatile 訪問不建立執行緒間同步。
In addition, volatile accesses are not atomic (concurrent read and write is a data race) and do not order memory (non-volatile memory accesses may be freely reordered around the volatile access).
此外，volatile 訪問不是原子的（併發讀寫構成資料競爭），也不對記憶體排序（非 volatile 記憶體訪問可以在 volatile 訪問周圍自由重排）。
One notable exception is Visual Studio, where, with default settings, every volatile write has release semantics and every volatile read has acquire semantics (Microsoft Docs), and thus volatiles may be used for inter-thread synchronization. Standard `volatile` semantics are not applicable to multi-threaded programming, although they are sufficient for e.g. communication with a signal handler that runs in the same thread when applied to `sig_atomic_t` variables. The compiler option `/volatile:iso` can be used to restore behavior consistent with the standard, which is the default setting when the target platform is ARM.
一個顯著的例外是 Visual Studio，在預設設定下，每個 volatile 寫入具有 release 語意，每個 volatile 讀取具有 acquire 語意（Microsoft Docs），因此 volatile 可用於執行緒間同步。標準 volatile 語意不適用於多執行緒程式設計，儘管應用於 sig_atomic_t 變數時，它們足以用於與在同一執行緒中執行的訊號處理器的通訊。編譯器選項 /volatile:iso 可用於恢復與標準一致的行為，這也是目標平臺為 ARM 時的預設設定。

### Examples

|  | This section is incomplete
Reason: no example  |

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.17.1/4 memory_order (p: TBD)
7.17.1/4 memory_order（頁：待定）
7.17.1/4 memory_order（頁：待定）

- 7.17.3 Order and consistency (p: TBD)
7.17.3 順序與一致性（頁：待定）
7.17.3 順序與一致性（頁：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.17.1/4 memory_order (p: 200)
7.17.1/4 memory_order（頁：200）
7.17.1/4 memory_order（頁：200）

- 7.17.3 Order and consistency (p: 201-203)
7.17.3 順序與一致性（頁：201-203）
7.17.3 順序與一致性（頁：201-203）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.17.1/4 memory_order (p: 273)
7.17.1/4 memory_order（頁：273）
7.17.1/4 memory_order（頁：273）

- 7.17.3 Order and consistency (p: 275-277)
7.17.3 順序與一致性（頁：275-277）
7.17.3 順序與一致性（頁：275-277）

### See also

C++ documentation for memory order

### External links

| 1.  |   | MOESI protocol  |

| 2.  |   | x86-TSO: A Rigorous and Usable Programmer’s Model for x86 Multiprocessors P. Sewell et. al., 2010  |

| 3.  |   | A Tutorial Introduction to the ARM and POWER Relaxed Memory Models P. Sewell et al, 2012  |

| 4.  |   | MESIF: A Two-Hop Cache Coherency Protocol for Point-to-Point Interconnects J.R. Goodman, H.H.J. Hum, 2009  |

| 5.  |   | Memory Models Russ Cox, 2021  |

|  | This section is incomplete
Reason: Let's find good refs on QPI, MOESI, and maybe Dragon.  |

---
來源頁路徑：`en.cppreference.com/c/atomic/memory_order.html`
