# jmp_buf

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<setjmp.h>`
|   |  |   |  |

```c
typedef /* unspecified */ jmp_buf;
```
|   |   |   |   |

|  |  |  |  |

The `jmp_buf` type is an array type suitable for storing information to restore a calling environment. The stored information is sufficient to restore execution at the correct block of the program and invocation of that block. The state of floating-point status flags, or open files, or any other data is not stored in an object of type `jmp_buf`.
jmp_buf 型別是一種陣列型別，適合儲存用於恢復呼叫環境的資訊。儲存的資訊足以在程式的正確塊中恢復執行及該塊的呼叫。浮點狀態標誌的狀態、開啟的檔案或任何其他資料都不儲存在 jmp_buf 型別的物件中。

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.13/2 Nonlocal jumps <setjmp.h> (p: TBD)
7.13/2 非區域性跳轉 <setjmp.h> （頁碼：待定）
7.13/2 非區域性跳轉 <setjmp.h> （頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.13/2 Nonlocal jumps <setjmp.h> (p: 191)
7.13/2 非區域性跳轉 <setjmp.h> （頁碼：191）
7.13/2 非區域性跳轉 <setjmp.h> （頁碼：191）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.13/2 Nonlocal jumps <setjmp.h> (p: 262)
7.13/2 非區域性跳轉 <setjmp.h> （頁碼：262）
7.13/2 非區域性跳轉 <setjmp.h> （頁碼：262）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.13/2 Nonlocal jumps <setjmp.h> (p: 243)
7.13/2 非區域性跳轉 <setjmp.h> （頁碼：243）
7.13/2 非區域性跳轉 <setjmp.h> （頁碼：243）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.6 NON-LOCAL JUMPS <setjmp.h>
4.6 非區域性跳轉 <setjmp.h>
4.6 非區域性跳轉 <setjmp.h>

### See also

setjmp
|   | saves the context
(function macro)   |

longjmp
|   | jumps to specified location
(function)   |

C++ documentation for jmp_buf

---
來源頁路徑：`en.cppreference.com/c/program/jmp_buf.html`
