# mtx_init

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<threads.h>`
|   |  |   |  |

```c
int mtx_init( mtx_t* mutex, int type );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Creates a new mutex object with `type`. The object pointed to by `mutex` is set to an identifier of the newly created mutex.
建立 type 指定型別的新互斥鎖，並將新互斥鎖的識別資訊存入 mutex 指向的物件。
`type` must have one of the following values:
type 必須具有以下值之一：

- mtx_plain - a simple, non-recursive mutex is created.
mtx_plain - 建立簡單的非遞迴互斥量。

- mtx_timed - a non-recursive mutex, that supports timeout, is created.
mtx_timed - 建立支援超時的非遞迴互斥量。

- `mtx_plain | mtx_recursive` - a recursive mutex is created.
mtx_plain | mtx_recursive - 建立遞迴互斥量。

- `mtx_timed | mtx_recursive` - a recursive mutex, that supports timeout, is created.
mtx_timed | mtx_recursive - 建立支援超時的遞迴互斥量。

### Parameters

| mutex  |   | -  |   | pointer to the mutex to initialize  |

| type  |   | -  |   | the type of the mutex  |

### Return value

thrd_success if successful, thrd_error otherwise.
成功則傳回 thrd_success ，否則傳回 thrd_error 。

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.26.4.2 The mtx_init function (p: 277-278)
7.26.4.2 mtx_init 函式（頁：277-278）
7.26.4.2 mtx_init 函式（頁：277-278）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.26.4.2 The mtx_init function (p: 381)
7.26.4.2 mtx_init 函式（頁：381）
7.26.4.2 mtx_init 函式（頁：381）

### See also

C++ documentation for mutex

C++ documentation for timed_mutex

C++ documentation for recursive_mutex

C++ documentation for recursive_timed_mutex

---
來源頁路徑：`en.cppreference.com/c/thread/mtx_init.html`
