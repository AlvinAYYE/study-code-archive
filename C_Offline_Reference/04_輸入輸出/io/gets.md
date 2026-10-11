# gets, gets_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
char* gets( char* str );
```
|   |  (1)  |   |  (removed in C11)  |

```c
char* gets_s( char* str, rsize_t n );
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

1) Reads stdin into the character array pointed to by `str` until a newline character is found or end-of-file occurs. A null character is written immediately after the last character read into the array. The newline character is discarded but not stored in the buffer.
1) 從 `stdin` 讀取字元並存入 `str` 指向的陣列，直到遇到換行或檔案結尾。讀入的字元後會補上空字元 `\0`；換行字元會被丟棄，不會存進陣列。

2) Reads characters from stdin until a newline is found or end-of-file occurs. Writes only at most `n - 1` characters into the array pointed to by `str`, and always writes the terminating null character (unless `str` is a null pointer). The newline character, if found, is discarded and does not count toward the number of characters written to the buffer.
2) 從 `stdin` 讀取字元，直到遇到換行或檔案結尾；最多將 `n - 1` 個字元寫入 `str` 指向的陣列，並在結尾補上空字元（`str` 是空指標時除外）。如果讀到換行，會將它丟棄，而且不計入寫入字元數。

The following errors are detected at runtime and call the currently installed constraint handler function:
- `n` is zero;

- `n` is greater than `RSIZE_MAX`;
n 大於 RSIZE_MAX ；

- `str` is a null pointer;
str 是空指標；

- *endline* or *eof* not encountered after storing `n - 1` characters to the buffer.
向緩衝區儲存 n - 1 個字元後未遇到 endline 或 eof。

In any case, `gets_s` first finishes reading and discarding the characters from stdin until new-line character, end-of-file condition, or read error before calling the constraint handler.
無論發生哪種錯誤，`gets_s` 都會先繼續讀取並丟棄 `stdin` 的字元，直到遇到換行、檔案結尾或讀取錯誤，之後才呼叫約束處理函式。

As with all bounds-checked functions, `gets_s` is only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <stdio.h>.
和其他有界限檢查的函式一樣，只有實作定義了 `__STDC_LIB_EXT1__`，而且程式在引入 `<stdio.h>` 前將 `__STDC_WANT_LIB_EXT1__` 設為整數常數 `1`，才能保證可以使用 `gets_s`。

### Parameters

| str  |   | -  |   | a character array the characters from stdin to be written to  |

| n  |   | -  |   | maximum number of characters that can be written to the array pointed to by `str`  |

### Return value

`str` on success, a null pointer on failure.
成功時傳回 str ，失敗時傳回空指標。
If the failure has been caused by end of file condition, additionally sets the *eof* indicator (see feof()) on stdin. If the failure has been caused by some other error, sets the *error* indicator (see ferror()) on stdin.
如果失敗由檔案結束條件引起，還會在 stdin 上設定 eof 指示器（參見 feof() ）。如果失敗由其他錯誤引起，則在 stdin 上設定錯誤指示器（參見 ferror() ）。

### Notes

The `gets()` function does not perform bounds checking, therefore this function is extremely vulnerable to buffer-overflow attacks. It cannot be used safely (unless the program runs in an environment which restricts what can appear on `stdin`). For this reason, the function has been deprecated in the third corrigendum to the C99 standard and removed altogether in the C11 standard. fgets() and `gets_s()` are the recommended replacements.
gets() 函式不執行邊界檢查，因此該函式極易受到緩衝區溢位攻擊。它無法安全使用（除非程式執行在限制 stdin 上可出現內容的環境中）。因此，該函式在 C99 標準的第三號技術勘誤中被棄用，並在 C11 標準中被徹底移除。fgets() 和 gets_s() 是推薦的替代函式。
**WARNING: Never use `gets()`**.
警告：絕不要使用 gets() 。

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- K.3.5.4.1 The gets_s function (p: TBD)
K.3.5.4.1 gets_s 函式（頁碼：待定）
K.3.5.4.1 gets_s 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- K.3.5.4.1 The gets_s function (p: TBD)
K.3.5.4.1 gets_s 函式（頁碼：待定）
K.3.5.4.1 gets_s 函式（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- K.3.5.4.1 The gets_s function (p: 602-603)
K.3.5.4.1 gets_s 函式（頁碼：602-603）
K.3.5.4.1 gets_s 函式（頁碼：602-603）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19.7.7 The gets function (p: 298)
7.19.7.7 gets 函式（頁碼：298）
7.19.7.7 gets 函式（頁碼：298）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9.7.7 The gets function
4.9.7.7 gets 函式
4.9.7.7 gets 函式

### See also

scanffscanfsscanfscanf_sfscanf_ssscanf_s
(C11)(C11)(C11)
|   | reads formatted input from stdin, a file stream or a buffer
(function)   |

fgets
|   | gets a character string from a file stream
(function)   |

fputs
|   | writes a character string to a file stream
(function)   |

getlinegetwlinegetdelimgetwdelim
(dynamic memory TR)
|   | read from a stream into an automatically resized buffer until delimiter/end of line
(function)   |

C++ documentation for gets

---
來源頁路徑：`en.cppreference.com/c/io/gets.html`
