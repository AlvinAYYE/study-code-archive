# call_once, once_flag, ONCE_FLAG_INIT

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<threads.h>`
|   |  |   |  |

```c
void call_once( once_flag* flag, void (*func)(void) );
```
|   |  (1)  |   |  (since C11)  |

```c
typedef /* unspecified */ once_flag
```
|   |  (2)  |   |  (since C11)  |

```c
#define ONCE_FLAG_INIT /* unspecified */
```
|   |  (3)  |   |  (since C11)  |

|  |  |  |  |

1) Calls function `func` exactly once, even if invoked from several threads. The completion of the function `func` synchronizes with all previous or subsequent calls to `call_once` with the same `flag` variable.

2) Complete object type capable of holding a flag used by `call_once`.

3) Expands to a value that can be used to initialize an object of type `once_flag`.

### Parameters

| flag  |   | -  |   | pointer to an object of type `call_once` that is used to ensure `func` is called only once  |

| func  |   | -  |   | the function to execute only once  |

### Return value

(none)

### Notes

The POSIX equivalent of this function is `pthread_once`.
此函式在 POSIX 中的等價物是 pthread_once 。

### Example

Run this code

```c
#include <stdio.h> #include <threads.h> void do_once(void) {  puts("called once"); } static once_flag flag = ONCE_FLAG_INIT; int func(void* data) {  call_once(&flag, do_once); } int main(void) {  thrd_t t1, t2, t3, t4;  thrd_create(&t1, func, NULL);  thrd_create(&t2, func, NULL);  thrd_create(&t3, func, NULL);  thrd_create(&t4, func, NULL);  thrd_join(t1, NULL);  thrd_join(t2, NULL);  thrd_join(t3, NULL);  thrd_join(t4, NULL); }
```

Output:

```c
called once
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.26.2.1 The call_once function (p: 275)
7.26.2.1 call_once 函式（頁：275）
7.26.2.1 call_once 函式（頁：275）

- 7.26.1/3 ONCE_FLAG_INIT (p: 274)
7.26.1/3 ONCE_FLAG_INIT（頁：274）
7.26.1/3 ONCE_FLAG_INIT（頁：274）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.26.2.1 The call_once function (p: 378)
7.26.2.1 call_once 函式（頁：378）
7.26.2.1 call_once 函式（頁：378）

- 7.26.1/3 ONCE_FLAG_INIT (p: 376)
7.26.1/3 ONCE_FLAG_INIT（頁：376）
7.26.1/3 ONCE_FLAG_INIT（頁：376）

### See also

C++ documentation for call_once

---
來源頁路徑：`en.cppreference.com/c/thread/call_once.html`
