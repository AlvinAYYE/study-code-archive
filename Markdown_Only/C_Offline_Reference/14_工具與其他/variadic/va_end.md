# va_end

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdarg.h>`
|   |  |   |  |

```c
void va_end( va_list ap );
```
|   |   |   |   |

|  |  |  |  |

The `va_end` macro performs cleanup for an `ap` object initialized by a call to va_start or va_copy. `va_end` may modify `ap` so that it is no longer usable.
va_end 巨集會清理經 va_start 或 va_copy 初始化的 ap 物件。va_end 可能會修改 ap，使它無法再使用。
If there is no corresponding call to va_start or va_copy, or if `va_end` is not called before a function that calls va_start or va_copy returns, the behavior is undefined.
如果沒有對 va_start 或 va_copy 的相應呼叫，或者在呼叫 va_start 或 va_copy 的函式傳回之前沒有呼叫 va_end ，則行為未定義。

### Parameters

| ap  |   | -  |   | an instance of the va_list type to clean up  |

### Expanded value

(none)

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.16.1.3 The va_end macro (p: TBD)
7.16.1.3 va_end 宏（頁碼：待定）
7.16.1.3 va_end 宏（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.16.1.3 The va_end macro (p: TBD)
7.16.1.3 va_end 宏（頁碼：待定）
7.16.1.3 va_end 宏（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.16.1.3 The va_end macro (p: 270-271)
7.16.1.3 va_end 宏（頁碼：270-271）
7.16.1.3 va_end 宏（頁碼：270-271）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.15.1.3 The va_end macro (p: 250-251)
7.15.1.3 va_end 宏（頁碼：250-251）
7.15.1.3 va_end 宏（頁碼：250-251）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.8.1.3 The va_end macro
4.8.1.3 va_end 宏
4.8.1.3 va_end 宏

### See also

va_arg
|   | accesses the next variadic function argument
(function macro)   |

va_copy
(C99)
|   | makes a copy of the variadic function arguments
(function macro)   |

va_list
|   | holds the information needed by va_start, va_arg, va_end, and va_copy
(typedef)   |

va_start
|   | enables access to variadic function arguments
(function macro)   |

C++ documentation for va_end

---
來源頁路徑：`en.cppreference.com/c/variadic/va_end.html`
