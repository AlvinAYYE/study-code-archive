# cnd_destroy

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<threads.h>`
|   |  |   |  |

```c
void cnd_destroy( cnd_t* cond );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Destroys the condition variable pointed to by `cond`.
銷燬 cond 所指向的條件變數。
If there are threads waiting on `cond`, the behavior is undefined.
如果有執行緒正在 cond 上等待，則屬於未定義行為。

### Parameters

| cond  |   | -  |   | pointer to the condition variable to destroy  |

### Return value

(none)

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.26.3.2 The cnd_destroy function (p: 276)
7.26.3.2 cnd_destroy 函式（頁：276）
7.26.3.2 cnd_destroy 函式（頁：276）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.26.3.2 The cnd_destroy function (p: 378-379)
7.26.3.2 cnd_destroy 函式（頁：378-379）
7.26.3.2 cnd_destroy 函式（頁：378-379）

### See also

C++ documentation for ~condition_variable

C++ documentation for ~condition_variable_any

---
來源頁路徑：`en.cppreference.com/c/thread/cnd_destroy.html`
