# mtx_destroy

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<threads.h>`
|   |  |   |  |

```c
void mtx_destroy( mtx_t *mutex );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Destroys the mutex pointed to by `mutex`.
銷燬 mutex 所指向的互斥量。
If there are threads waiting on `mutex`, the behavior is undefined.
如果有執行緒正在 mutex 上等待，則屬於未定義行為。

### Parameters

| mutex  |   | -  |   | pointer to the mutex to destroy  |

### Return value

(none)

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.26.4.1 The mtx_destroy function (p: 277)
7.26.4.1 mtx_destroy 函式（頁：277）
7.26.4.1 mtx_destroy 函式（頁：277）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.26.4.1 The mtx_destroy function (p: 380)
7.26.4.1 mtx_destroy 函式（頁：380）
7.26.4.1 mtx_destroy 函式（頁：380）

### See also

C++ documentation for ~mutex

C++ documentation for ~timed_mutex

C++ documentation for ~recursive_mutex

C++ documentation for ~recursive_timed_mutex

---
來源頁路徑：`en.cppreference.com/c/thread/mtx_destroy.html`
