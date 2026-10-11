# mtx_plain, mtx_recursive, mtx_timed

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<threads.h>`
|   |  |   |  |

```c
enum {  mtx_plain = /* unspecified */,  mtx_recursive = /* unspecified */,  mtx_timed = /* unspecified */ };
```
|   |   |   |  (since C11)  |

|  |  |  |  |

When passed to mtx_init, identifies the type of a mutex to create.
當傳遞給 mtx_init 時，用於標識要建立的互斥量型別。

| Constant  |   | Explanation  |

| `mtx_plain`  |   | plain mutex  |

| `mtx_recursive`  |   | recursive mutex  |

| `mtx_timed`  |   | timed mutex  |

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.26.1/5 mtx_plain, mtx_recursive, mtx_timed (p: 274-275)
7.26.1/5 mtx_plain、mtx_recursive、mtx_timed（頁：274-275）
7.26.1/5 mtx_plain、mtx_recursive、mtx_timed（頁：274-275）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.26.1/5 mtx_plain, mtx_recursive, mtx_timed (p: 377)
7.26.1/5 mtx_plain、mtx_recursive、mtx_timed（頁：377）
7.26.1/5 mtx_plain、mtx_recursive、mtx_timed（頁：377）

### See also

mtx_init
(C11)
|   | creates a mutex
(function)   |

---
來源頁路徑：`en.cppreference.com/c/thread/mtx_types.html`
