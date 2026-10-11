# signal

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<signal.h>`
|   |  |   |  |

```c
void (*signal( int sig, void (*handler) (int))) (int);
```
|   |   |   |   |

|  |  |  |  |

Changes handling of the signal `sig`. Depending on the value of `handler`, the signal can be ignored, set to default, or handled by a user-defined function invoked as `(*handler)(sig)`.
變更訊號 sig 的處理方式。依據 handler 的值，訊號可以被忽略、恢復預設處理方式，或交由使用者定義的函式處理；呼叫形式為 ( * handler )( sig )。
When signal handler is set to a function and a signal occurs, it is implementation defined whether `signal(sig, SIG_DFL)` will be executed immediately before the start of signal handler. Also, the implementation can prevent some implementation-defined set of signals from occurring while the signal handler runs.
當訊號處理程式設定為函式且訊號發生時， signal ( sig , SIG_DFL ) 是否會在訊號處理程式開始之前立即執行由實現定義。此外，實現可以阻止某些實現定義的訊號集在訊號處理程式執行期間發生。

### Parameters

| sig  |   | -  |   | the signal to set the signal handler to. It can be an implementation-defined value or one of the following values:

SIGABRTSIGFPESIGILLSIGINTSIGSEGVSIGTERM
|   | defines signal types
(macro constant)   |

| handler  |   | -  |   | the signal handler. This must be one of the following:
- SIG_DFL macro. The signal handler is set to default signal handler.

- SIG_IGN macro. The signal is ignored.

- pointer to a function. The signature of the function must be equivalent to the following:

```c
void fun(int sig);
```
|   |   |   |   |

|  |  |  |  |

### Return value

Previous signal handler on success or SIG_ERR on failure (setting a signal handler can be disabled on some implementations).
成功時傳回先前的訊號處理程式，失敗時傳回 SIG_ERR （在某些實現上可以禁用設定訊號處理程式）。

### Signal handler

The following limitations are imposed on the user-defined function that is installed as a signal handler.
對安裝為訊號處理程式的使用者定義函式施加以下限制。
If the user defined function returns when handling SIGFPE, SIGILL or SIGSEGV, the behavior is undefined.
如果使用者定義函式在處理 SIGFPE 、 SIGILL 或 SIGSEGV 時傳回，則行為未定義。
If the signal handler is called as a result of abort or raise, the behavior is undefined if the signal handler calls raise.
如果訊號處理程式是因 abort 或 raise 而被呼叫的，則當訊號處理程式呼叫 raise 時行為未定義。
If the signal handler is called NOT as a result of abort or raise (in other words, the signal handler is *asynchronous*), the behavior is undefined if
如果訊號處理程式不是因 abort 或 raise 而被呼叫的（換句話說，訊號處理程式是非同步的），則在以下情況下行為未定義：

- the signal handler calls any function within the standard library, except
訊號處理程式呼叫標準函式庫中的任何函式，除了

- abort

- _Exit

- quick_exit

- `signal` with the first argument being the number of the signal currently handled (async handler can re-register itself, but not other signals).
signal （其第一個參數為目前處理的訊號編號；非同步處理程式可以重新註冊自身，但不能註冊其他訊號）。

- atomic functions from `<stdatomic.h>` if the atomic arguments are lock-free
如果原子參數是無鎖的，則為 <stdatomic.h> 中的原子函式

- atomic_is_lock_free (with any kind of atomic arguments)
atomic_is_lock_free （可以是任何型別的原子參數）
abort 、 _Exit 、 quick_exit 、 signal （其第一個參數為目前處理的訊號編號；非同步處理程式可以重新註冊自身，但不能註冊其他訊號）。如果原子參數是無鎖的，則為 <stdatomic.h> 中的原子函式； atomic_is_lock_free （可以是任何型別的原子參數）

- the signal handler refers to any object with static or thread-local(since C11) storage duration that is not a lock-free atomic(since C11) other than by assigning to a static `volatile sig_atomic_t`.
訊號處理程式引用任何具有靜態或執行緒局域（自 C11 起）儲存持續時間的物件，該物件不是無鎖原子（自 C11 起），但透過賦值給 static volatile sig_atomic_t 的情況除外。

On entry to the signal handler, the state of the floating-point environment and the values of all objects is unspecified, except for
進入訊號處理程式時，浮點環境的狀態和所有物件的值未指定，除了

- objects of type `volatile sig_atomic_t`
volatile sig_atomic_t 型別的物件

- objects of lock-free atomic types (since C11)
無鎖原子型別的物件（自 C11 起）

- side effects made visible through atomic_signal_fence (since C11)
透過 atomic_signal_fence （自 C11 起）可見的副作用

On return from a signal handler, the value of any object modified by the signal handler that is not `volatile sig_atomic_t` or lock-free atomic(since C11) is undefined.
從訊號處理程式傳回時，訊號處理程式修改的任何不是 volatile sig_atomic_t 或無鎖原子（自 C11 起）的物件的值是未定義的。
The behavior is undefined if `signal` is used in a multithreaded program. It is not required to be thread-safe.
如果在多執行緒程式中使用 signal ，則行為未定義。不要求它是執行緒安全的。

### Notes

POSIX requires that `signal` is thread-safe, and specifies a list of async-signal-safe library functions that may be called from any signal handler.
POSIX 要求 signal 是執行緒安全的，並規定了可從任何訊號處理程式呼叫的非同步訊號安全庫函式列表。
Besides `abort` and `raise`, POSIX specifies that `kill`, `pthread_kill`, and `sigqueue` generate synchronous signals.
除了 abort 和 raise ， POSIX 規定 kill 、 pthread_kill 和 sigqueue 產生同步訊號。
POSIX recommends `sigaction` instead of `signal`, due to its underspecified behavior and significant implementation variations, regarding signal delivery while a signal handler is executed.
POSIX 建議使用 sigaction，而不要使用 signal，因為 signal 對處理常式執行期間如何遞送訊號規範不足，而且各實作差異很大。

### Example

Run this code

```c
#include <signal.h> #include <stdio.h> volatile sig_atomic_t gSignalStatus; void signal_handler(int signal) {  gSignalStatus = signal; } int main(void) {  signal(SIGINT, signal_handler);  printf("SignalValue: %d\n", gSignalStatus);  printf("Sending signal: %d\n", SIGINT);  raise(SIGINT);  printf("SignalValue: %d\n", gSignalStatus); }
```

Output:

```c
SignalValue: 0 Sending signal: 2 SignalValue: 2
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.14.1.1 The signal function (p: 285-286)
7.14.1.1 signal 函式（頁碼：285-286）
7.14.1.1 signal 函式（頁碼：285-286）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.14.1.1 The signal function (p: 193-194)
7.14.1.1 signal 函式（頁碼：193-194）
7.14.1.1 signal 函式（頁碼：193-194）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.14.1.1 The signal function (p: 266-267)
7.14.1.1 signal 函式（頁碼：266-267）
7.14.1.1 signal 函式（頁碼：266-267）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.14.1.1 The signal function (p: 247-248)
7.14.1.1 signal 函式（頁碼：247-248）
7.14.1.1 signal 函式（頁碼：247-248）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.7.1.1 The signal function
4.7.1.1 signal 函式
4.7.1.1 signal 函式

### See also

raise
|   | runs the signal handler for particular signal
(function)   |

C++ documentation for signal

---
來源頁路徑：`en.cppreference.com/c/program/signal.html`
