# va_list

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdarg.h>`
|   |  |   |  |

```c
/* unspecified */ va_list;
```
|   |   |   |   |

|  |  |  |  |

`va_list` is a complete object type suitable for holding the information needed by the macros va_start, va_copy, va_arg, and va_end.
va_list 是完整的物件型別，適合儲存 va_start、va_copy、va_arg 和 va_end 巨集所需的資訊。
If a `va_list` instance is created, passed to another function, and used via va_arg in that function, then any subsequent use in the calling function should be preceded by a call to va_end.
如果建立了 va_list 例項、將其傳遞給另一個函式並在該函式中透過 va_arg 使用，則在呼叫函式中的任何後續使用之前都應呼叫 va_end 。
It is legal to pass a pointer to a `va_list` object to another function and then use that object after the function returns.
將指向 va_list 物件的指標傳遞給另一個函式，然後在該函式傳回後使用該物件是合法的。

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.16/3 Variable arguments <stdarg.h> (p: TBD)
7.16/3 可變參數 <stdarg.h>（頁碼：待定）
7.16/3 可變參數 <stdarg.h>（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.16/3 Variable arguments <stdarg.h> (p: TBD)
7.16/3 可變參數 <stdarg.h>（頁碼：待定）
7.16/3 可變參數 <stdarg.h>（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.16/3 Variable arguments <stdarg.h> (p: 269)
7.16/3 可變參數 <stdarg.h>（頁碼：269）
7.16/3 可變參數 <stdarg.h>（頁碼：269）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.15/3 Variable arguments <stdarg.h> (p: 249)
7.15/3 可變參數 <stdarg.h>（頁碼：249）
7.15/3 可變參數 <stdarg.h>（頁碼：249）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.8 VARIABLE ARGUMENTS <stdarg.h>
4.8 可變參數 <stdarg.h>
4.8 可變參數 <stdarg.h>

### See also

va_arg
|   | accesses the next variadic function argument
(function macro)   |

va_copy
(C99)
|   | makes a copy of the variadic function arguments
(function macro)   |

va_end
|   | ends traversal of the variadic function arguments
(function macro)   |

va_start
|   | enables access to variadic function arguments
(function macro)   |

C++ documentation for va_list

---
來源頁路徑：`en.cppreference.com/c/variadic/va_list.html`
