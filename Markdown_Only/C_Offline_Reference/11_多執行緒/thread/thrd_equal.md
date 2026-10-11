# thrd_equal

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<threads.h>`
|   |  |   |  |

```c
int thrd_equal( thrd_t lhs, thrd_t rhs );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Checks whether `lhs` and `rhs` refer to the same thread.
檢查 lhs 和 rhs 是否引用同一個執行緒。

### Parameters

| lhs, rhs  |   | -  |   | threads to compare  |

### Return value

Non-zero value if `lhs` and `rhs` refer to the same value, `0` otherwise.
如果 lhs 和 rhs 引用相同的值則傳回非零值，否則傳回 0。

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.26.5.4 The thrd_equal function (p: 280)
7.26.5.4 thrd_equal 函式（頁：280）
7.26.5.4 thrd_equal 函式（頁：280）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.26.5.4 The thrd_equal function (p: 384)
7.26.5.4 thrd_equal 函式（頁：384）
7.26.5.4 thrd_equal 函式（頁：384）

### See also

C++ documentation for operator_cmp

---
來源頁路徑：`en.cppreference.com/c/thread/thrd_equal.html`
