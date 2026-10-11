# Diagnostic directives

> 來源：cppreference C 語言參考文件（離線轉換版）。

Shows the given error message and renders the program ill-formed, or given warning message without affect the validity of the program(since C23).
`#error` 會顯示指定的錯誤訊息，並使程式不符合語法規則，編譯通常因此停止。C23 起，`#warning` 可顯示警告訊息，但不會使程式失效，編譯也會繼續。

### Syntax

|   |

| `**#error**` diagnostic-message  |   | (1)  |   |   |

|   |

| `**#warning**` diagnostic-message  |   | (2)  |   | (since C23)  |

|   |

### Explanation

1) 遇到 `#error` 時，實作會顯示 `diagnostic-message`，並將程式視為格式錯誤；編譯會停止。

2) `#warning` 的處理方式與 (1) 類似，但不影響程式是否有效，編譯會繼續。

diagnostic-message can consist of several words not necessarily in quotes.
`diagnostic-message` 可以包含多個字，也不一定要用引號括起來。

### Notes

Before its standardization in C23, `#warning` has been provided by many compilers in all modes as a conforming extension.
C23 將 `#warning` 納入標準之前，許多編譯器早已在各種語言模式中以擴充功能提供它。

### Example

Run this code

```c
#if __STDC__ != 1 # error "Not a standard compliant compiler" #endif #if __STDC_VERSION__ >= 202311L # warning "Using #warning as a standard feature" #endif #include <stdio.h> int main (void) {  printf("The compiler used conforms to the ISO C Standard !!"); }
```

Possible output:
輸出範例：

```c
The compiler used conforms to the ISO C Standard !!
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.10.5 Error directive (p: TBD)
6.10.5 Error 指令 (p: TBD)
6.10.5 Error 指令 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.10.5 Error directive (p: 126-127)
6.10.5 Error 指令 (p: 126-127)
6.10.5 Error 指令 (p: 126-127)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.10.5 Error directive (p: 174)
6.10.5 Error 指令 (p: 174)
6.10.5 Error 指令 (p: 174)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.10.5 Error directive (p: 159)
6.10.5 Error 指令 (p: 159)
6.10.5 Error 指令 (p: 159)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.8.5 Error directive
3.8.5 Error 指令
3.8.5 Error 指令

### See also

C++ documentation for Diagnostic directives

---
來源頁路徑：`en.cppreference.com/c/preprocessor/error.html`
