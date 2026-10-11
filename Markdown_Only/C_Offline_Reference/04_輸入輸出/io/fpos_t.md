# fpos_t

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
typedef /* implementation-defined */ fpos_t;
```
|   |   |   |   |

|  |  |  |  |

`fpos_t` is a non-array complete object type, can be used to store (by fgetpos) and restore (by fsetpos) the position and multibyte parser state (if any) for a C stream.
fpos_t 是一個非陣列的完整物件型別，可用於儲存（透過 fgetpos ）和恢復（透過 fsetpos ）C 流的目前位置和多位元組解析器狀態（如果有）。

The multibyte parser state of a wide-oriented C stream is represented by a mbstate_t object, whose value is stored as part of the value of a `fpos_t` object by fgetpos.
|   | (since C95) |

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.21.1 Introduction (p: 217-218)
7.21.1 引言（頁碼：217-218）
7.21.1 引言（頁碼：217-218）

- 7.21.2 Streams (p: 218-219)
7.21.2 流（頁碼：218-219）
7.21.2 流（頁碼：218-219）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21.1 Introduction (p: 296-298)
7.21.1 引言（頁碼：296-298）
7.21.1 引言（頁碼：296-298）

- 7.21.2 Streams (p: 298-299)
7.21.2 流（頁碼：298-299）
7.21.2 流（頁碼：298-299）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19.1 Introduction (p: 262-264)
7.19.1 引言（頁碼：262-264）
7.19.1 引言（頁碼：262-264）

- 7.19.2 Streams (p: 264-265)
7.19.2 流（頁碼：264-265）
7.19.2 流（頁碼：264-265）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9.1 Introduction
4.9.1 引言
4.9.1 引言

- 4.9.2 Streams

### See also

fgetpos
|   | gets the file position indicator
(function)   |

fsetpos
|   | moves the file position indicator to a specific location in a file
(function)   |

mbstate_t
(C95)
|   | conversion state information necessary to iterate multibyte character strings
(class)   |

C++ documentation for fpos_t

---
來源頁路徑：`en.cppreference.com/c/io/fpos_t.html`
