# fflush

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
int fflush( FILE* stream );
```
|   |   |   |   |

|  |  |  |  |

For output streams (and for update streams on which the last operation was output), writes any unwritten data from the `stream`'s buffer to the associated output device.
對輸出串流（以及上一次操作為輸出的更新串流），會將緩衝區中尚未寫出的資料送到相關輸出裝置。
For input streams (and for update streams on which the last operation was input), the behavior is undefined.
對輸入串流（以及上一次操作為輸入的更新串流）呼叫時，行為未定義。
If `stream` is a null pointer, all open output streams are flushed, including the ones manipulated within library packages or otherwise not directly accessible to the program.
若 stream 是空指標，會重新整理所有已開啟的輸出串流，包括程式無法直接存取的串流。

### Parameters

| stream  |   | -  |   | the file stream to write out  |

### Return value

Returns zero on success. Otherwise EOF is returned and the error indicator of the file stream is set.
成功時傳回零。否則傳回 EOF 並置位檔案流的錯誤指示器。

### Notes

POSIX extends the specification of fflush by defining its effects on an input stream, as long as that stream represents a file or another seekable device: in that case the POSIX file pointer is repositioned to match the C stream pointer (which effectively undoes any read buffering) and the effects of any ungetc or ungetwc that weren't yet read back from the stream are discarded.
POSIX 透過定義 fflush 對輸入流的效果來擴充套件其規範，只要該流表示一個檔案或其他可定址裝置：在這種情況下，POSIX 檔案指標會被重新定位以匹配 C 流指標（這實際上會撤銷任何讀取緩衝），並且那些尚未從流中讀回的 ungetc 或 ungetwc 的效果會被丟棄。
Microsoft also extends the specification of fflush by defining its effects on an input stream: in Visual Studio 2013 and prior, it discarded the input buffer, in Visual Studio 2015 and newer, it has no effect, buffers are retained.
Microsoft 也透過定義 fflush 對輸入流的效果來擴充套件其規範：在 Visual Studio 2013 及更早版本中，它會丟棄輸入緩衝區；在 Visual Studio 2015 及更新版本中，它沒有效果，緩衝區會被保留。

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.21.5.2 The fflush function (p: TBD)
7.21.5.2 fflush 函式（p: TBD）
7.21.5.2 fflush 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.21.5.2 The fflush function (p: TBD)
7.21.5.2 fflush 函式（p: TBD）
7.21.5.2 fflush 函式（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21.5.2 The fflush function (p: 305)
7.21.5.2 fflush 函式（p: 305）
7.21.5.2 fflush 函式（p: 305）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19.5.2 The fflush function (p: 270-271)
7.19.5.2 fflush 函式（p: 270-271）
7.19.5.2 fflush 函式（p: 270-271）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9.5.2 The fflush function
4.9.5.2 fflush 函式
4.9.5.2 fflush 函式

### See also

fopenfopen_s
(C11)
|   | opens a file
(function)   |

fclose
|   | closes a file
(function)   |

C++ documentation for fflush

---
來源頁路徑：`en.cppreference.com/c/io/fflush.html`
