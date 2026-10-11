# fgetws

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
wchar_t* fgetws( wchar_t* str, int count, FILE* stream );
```
|   |   |   | (since C95)
(until C99) |

```c
wchar_t* fgetws( wchar_t* restrict str, int count, FILE* restrict stream );
```
|   |   |   | (since C99) |

|  |  |  |  |

Reads at most `count - 1` wide characters from the given file stream and stores them in `str`. The produced wide string is always null-terminated. Parsing stops if end-of-file occurs or a newline wide character is found, in which case `str` will contain that wide newline character.
從給定的檔案流中讀取最多 count - 1 個寬字元並儲存在 str 中。生成的寬字串總是以空字元結尾。如果到達檔案末尾或找到換行寬字元，則解析停止，在這種情況下 str 將包含該換行寬字元。

### Parameters

| str  |   | -  |   | wide string to read the characters to  |

| count  |   | -  |   | the length of `str`  |

| stream  |   | -  |   | file stream to read the data from  |

### Return value

`str` on success, a null pointer on an error
成功時傳回 str，出錯時傳回空指標

### Example

|  | This section is incomplete
Reason: no example  |

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.29.3.2 The fgetws function (p: TBD)
7.29.3.2 fgetws 函式（頁：TBD）
7.29.3.2 fgetws 函式（頁：TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.29.3.2 The fgetws function (p: TBD)
7.29.3.2 fgetws 函式（頁：TBD）
7.29.3.2 fgetws 函式（頁：TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.3.2 The fgetws function (p: 422)
7.29.3.2 fgetws 函式（頁：422）
7.29.3.2 fgetws 函式（頁：422）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.3.2 The fgetws function (p: 367-368)
7.24.3.2 fgetws 函式（頁：367-368）
7.24.3.2 fgetws 函式（頁：367-368）

### See also

wscanffwscanfswscanfwscanf_sfwscanf_sswscanf_s
(C95)(C95)(C95)(C11)(C11)(C11)
|   | reads formatted wide character input from stdin, a file stream or a buffer
(function)   |

fgetwcgetwc
(C95)
|   | gets a wide character from a file stream
(function)   |

fputws
(C95)
|   | writes a wide string to a file stream
(function)   |

getlinegetwlinegetdelimgetwdelim
(dynamic memory TR)
|   | read from a stream into an automatically resized buffer until delimiter/end of line
(function)   |

C++ documentation for fgetws

---
來源頁路徑：`en.cppreference.com/c/io/fgetws.html`
