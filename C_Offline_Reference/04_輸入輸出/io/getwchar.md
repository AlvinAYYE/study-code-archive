# getwchar

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
wint_t getwchar(void);
```
|   |   |   |  (since C95)  |

|  |  |  |  |

Reads the next wide character from stdin.
從 stdin 讀取下一個寬字元。

### Parameters

(none)

### Return value

the obtained wide character or `WEOF` if an error has occurred or the end of file reached
所獲得的寬字元，或在發生錯誤或到達檔案末尾時為 WEOF

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.3.7 The getwchar function (p: 424)
7.29.3.7 getwchar 函式（頁：424）
7.29.3.7 getwchar 函式（頁：424）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.3.7 The getwchar function (p: 369-370)
7.24.3.7 getwchar 函式（頁：369-370）
7.24.3.7 getwchar 函式（頁：369-370）

### See also

getchar
|   | reads a character from stdin
(function)   |

fgetwcgetwc
(C95)
|   | gets a wide character from a file stream
(function)   |

C++ documentation for getwchar

---
來源頁路徑：`en.cppreference.com/c/io/getwchar.html`
