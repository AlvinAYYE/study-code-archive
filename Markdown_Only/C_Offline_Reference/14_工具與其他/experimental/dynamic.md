# Dynamic memory extensions

> 來源：cppreference C 語言參考文件（離線轉換版）。

Extensions to the C Library Part II: Dynamic Allocation Functions, ISO/IEC TR 24731-2:2010, defines the following new components for the C standard library:
《C 函式庫擴充第 II 部分：動態配置函式》（ISO/IEC TR 24731-2:2010）為 C 標準函式庫定義了以下新功能：

__STDC_ALLOC_LIB__
|   | integer constant of type `long` indicating conformance level
(macro constant)  |

Defined in header `<stdio.h>`

fmemopen
(dynamic memory TR)
|   | opens a fixed-size memory buffer as an I/O stream
(function)   |

open_memstreamopen_wmemstream
(dynamic memory TR)
|   | opens a dynamically resized memory buffer as an I/O stream
(function)   |

asprintfaswprintfvasprintfvaswprintf
(dynamic memory TR)
|   | variants of sprintf etc that write to automatically-allocated buffer and return a pointer to it
(function)   |

getlinegetwlinegetdelimgetwdelim
(dynamic memory TR)
|   | read from a stream into an automatically resized buffer until delimiter/end of line
(function)   |

Defined in header `<string.h>`

strdup
(dynamic memory TR)
|   | allocate a copy of a string
(function)   |

strndup
(dynamic memory TR)
|   | allocate a copy of a string up to specified size
(function)   |

This library extension also introduces assignment-allocation character `**m**` for use with `**%s**`, `**%[**`, and `**%c**` conversion specifiers in fscanf and fwscanf family of functions.
此擴充也新增配置指定字元 m，可用於 fscanf 和 fwscanf 函式族的 %s、%[ 和 %c 轉換規格。

### Notes

The functions `fmemopen`, `open_memstream`, `open_wmemstream`, `getdelim`, `getline`, `strdup`, `strndup`, and the extensions to `fscanf` are available in POSIX (ISO/IEC 9945:2003).
函式 fmemopen、open_memstream、open_wmemstream、getdelim、getline、strdup、strndup 以及對 fscanf 的擴充套件在 POSIX（ISO/IEC 9945:2003）中可用。
The functions `asprintf` and `vasprintf` are available in Linux Standard Base (ISO/IEC IS 23360:2006)
函式 asprintf 和 vasprintf 在 Linux Standard Base（ISO/IEC IS 23360:2006）中可用

---
來源頁路徑：`en.cppreference.com/c/experimental/dynamic.html`
