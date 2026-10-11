# TSS_DTOR_ITERATIONS

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<threads.h>`
|   |  |   |  |

```c
#define TSS_DTOR_ITERATIONS /* unspecified */
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Expands to a positive integral constant expression defining the maximum number of times a destructor for thread-local storage pointer will be called by thrd_exit.
展開為一個正的整數常量表示式，定義 thrd_exit 呼叫執行緒區域性儲存指標解構函式的最大次數。
This constant is equivalent to the POSIX `PTHREAD_DESTRUCTOR_ITERATIONS`.
此常量等價於 POSIX 的 PTHREAD_DESTRUCTOR_ITERATIONS 。

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.26.1/3 TSS_DTOR_ITERATIONS (p: 274)
7.26.1/3 TSS_DTOR_ITERATIONS（頁：274）
7.26.1/3 TSS_DTOR_ITERATIONS（頁：274）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.26.1/3 TSS_DTOR_ITERATIONS (p: 376)
7.26.1/3 TSS_DTOR_ITERATIONS（頁：376）
7.26.1/3 TSS_DTOR_ITERATIONS（頁：376）

---
來源頁路徑：`en.cppreference.com/c/thread/TSS_DTOR_ITERATIONS.html`
