# cnd_init

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<threads.h>`
|   |  |   |  |

```c
int cnd_init( cnd_t* cond );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Initializes new condition variable. The object pointed to by `cond` will be set to value that identifies the condition variable.
初始化新的條件變數。cond 所指向的物件會被設定為標識該條件變數的值。

### Parameters

| cond  |   | -  |   | pointer to a variable to store identifier of the condition variable to  |

### Return value

thrd_success if the condition variable was successfully created. Otherwise returns thrd_nomem if there was insufficient amount of memory or `thrd_error` if another error occurred.
如果條件變數建立成功則傳回 thrd_success 。否則，如果記憶體不足則傳回 thrd_nomem ，如果發生其他錯誤則傳回 thrd_error 。

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.26.3.3 The cnd_init function (p: 276)
7.26.3.3 cnd_init 函式（頁：276）
7.26.3.3 cnd_init 函式（頁：276）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.26.3.3 The cnd_init function (p: 379)
7.26.3.3 cnd_init 函式（頁：379）
7.26.3.3 cnd_init 函式（頁：379）

### See also

C++ documentation for condition_variable

C++ documentation for condition_variable_any

---
來源頁路徑：`en.cppreference.com/c/thread/cnd_init.html`
