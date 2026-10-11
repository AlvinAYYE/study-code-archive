# FILE

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
typedef /* unspecified */ FILE;
```
|   |   |   |   |

|  |  |  |  |

Each `FILE` object denotes a C stream.
每個 FILE 物件表示一個 C 流。
C standard does not specify whether `FILE` is a complete object type. While it may be possible to copy a valid `FILE`, using a pointer to such a copy as an argument for an I/O function invokes unspecified behavior. In other words, `FILE` may be semantically non-copyable.
C 標準未指定 FILE 是否為完整物件型別。雖然可以複製一個有效的 FILE，但將指向此類副本的指標用作 I/O 函式的參數會引發未指定行為。換句話說，FILE 在語意上可能是不可複製的。
I/O 串流可用於一般（未格式化）或格式化的輸入與輸出。部分 I/O 函式也會依目前的地區設定，在寬字元與多位元組字元之間進行必要的轉換。

### Stream state

Besides the system-specific information necessary to access the device (*e.g.,* a POSIX file descriptor), each `FILE` object directly or indirectly holds the following:
除了存取裝置所需的系統資訊（例如 POSIX 檔案描述符）之外，每個 `FILE` 物件也會直接或間接保存以下狀態：

- (C95) Character width: unset, narrow, or wide.
（C95）字元寬度：未設定、窄或寬。

- (C95) Parse state for conversions between multibyte and wide characters (an object of type mbstate_t)
（C95）多位元組與寬字元之間轉換的解析狀態（mbstate_t 型別的物件）

- Buffering state: unbuffered, line-buffered, fully buffered.
緩衝狀態：無緩衝、行緩衝、全緩衝。

- The buffer, which may be replaced by an external, user-provided buffer.
緩衝區；程式也可以改用自行提供的緩衝區。

- I/O mode: input, output, or update (both input and output).
I/O 模式：輸入、輸出或更新（輸入和輸出）。

- Binary/text mode indicator.
二進位制/文字模式指示器。

- End-of-file status indicator.
檔案結束狀態指示器。

- Error status indicator.
錯誤狀態指示器。

- File position indicator, accessible as an object of type fpos_t, which, for wide streams, includes parse state.
檔案位置指示器，可透過 `fpos_t` 物件取得；對寬字元串流而言，其中也包含字元轉換狀態。

- (C11) Reentrant lock used to prevent data races when multiple threads read, write, position, or query the position of a stream.
（C11）可重入鎖，用於在多個執行緒讀取、寫入、定位或查詢流位置時防止資料競爭。

For a stream in update I/O mode:
對於處於更新 I/O 模式的流：

- If switching from an output operation to an input operation, there must be an intervening call to `fflush` or a file positioning function (one of `fseek`, `fsetpos`, or `rewind`).
如果從輸出操作切換到輸入操作，其間必須呼叫 fflush 或檔案定位函式（fseek、fsetpos 或 rewind 之一）。

- If switching from an input operation to an output operation, if the input operation didn't encounter EOF, there must be an intervening call to a file positioning function.
若要從輸入切換到輸出，且先前的輸入沒有遇到 `EOF`，兩者之間必須呼叫檔案定位函式。

#### Narrow and wide orientation

A newly opened stream has no orientation. The first call to fwide or to any I/O function establishes the orientation: a wide I/O function makes the stream wide-oriented; a narrow I/O function makes the stream narrow-oriented. Once set, the orientation can be changed with only freopen. Narrow I/O functions cannot be called on a wide-oriented stream; wide I/O functions cannot be called on a narrow-oriented stream. Wide I/O functions convert between wide and multibyte characters as if by calling mbrtowc or wcrtomb with the conversion state as described by the stream. Unlike the multibyte character strings that are valid in a program, multibyte character sequences in the file may contain embedded nulls and do not have to begin or end in the initial shift state.
新開啟的流沒有定向。第一次呼叫 fwide 或任何 I/O 函式會建立定向：寬 I/O 函式使流成為寬定向；窄 I/O 函式使流成為窄定向。一旦設定，定向只能用 freopen 更改。窄 I/O 函式不能在寬定向流上呼叫；寬 I/O 函式不能在窄定向流上呼叫。寬 I/O 函式按照流所描述的轉換狀態，如同呼叫 mbrtowc 或 wcrtomb 一樣在寬字元與多位元組字元之間轉換。與程式中有效的多位元組字串不同，檔案中的多位元組字元序列可能包含嵌入的空字元，且不必以初始移位狀態開始或結束。
The conversion state of a stream with wide orientation is established by the C locale that is installed at the time the stream's orientation is set.
寬定向流的轉換狀態由設定流定向時已安裝的 C 本地環境確定。

#### Binary and text modes

A *text stream* is an ordered sequence of characters that can be composed into lines; a line can be decomposed into zero or more characters plus a terminating `'\n'` (“newline”) character. Whether the last line requires a terminating `'\n'` is implementation-defined. Furthermore, characters may have to be added, altered, or deleted on input and output to conform to the conventions for representing text in the OS (in particular, C streams on Windows OS convert `'\n'` to `'\r\n'` on output, and convert `'\r\n'` to `'\n'` on input).
文字流是可以組成行的有序字元序列；一行可以分解為零個或多個字元加上一個終止的 '\n'（"換行"）字元。最後一行是否需要終止的 '\n' 是實現定義的。此外，在輸入和輸出時可能需要新增、修改或刪除字元，以符合作業系統中表示文字的約定（特別是，Windows OS 上的 C 流在輸出時將 '\n' 轉換為 '\ r \ n '，在輸入時將 '\ r \ n ' 轉換為 '\n'）。
Data read in from a text stream is guaranteed to compare equal to the data that were earlier written out to that stream only if each of the following is true:
僅當以下各項均為真時，從文字流讀入的資料才保證與先前寫入該流的資料相等：

- The data consist of only printing characters and/or the control characters `'\t'` and `'\n'` (in particular, on Windows OS, the character `'\0x1A'` terminates input).
資料僅由可列印字元和/或控制字元 '\t' 和 '\n' 組成（特別是在 Windows OS 上，字元 '\ 0x1A ' 終止輸入）。

- No `'\n'` character is immediately preceded by space characters (such space characters may disappear when such output is later read as input).
沒有 '\n' 字元緊接在空格字元之前（當此類輸出稍後作為輸入讀取時，這些空格字元可能會消失）。

- The last character is `'\n'`.
最後一個字元是 '\n'。

A *binary stream* is an ordered sequence of characters that can transparently record internal data. Data read in from a binary stream always equal the data that were earlier written out to that stream, except that an implementation is allowed to append an indeterminate number of null characters to the end of the stream. A wide binary stream doesn't need to end in the initial shift state.
二進位制流是可以透明記錄內部資料的有序字元序列。從二進位制流讀入的資料總是等於先前寫入該流的資料，但允許實現向流的末尾追加數量不確定的空字元。寬二進位制流不需要以初始移位狀態結束。

### Notes

POSIX explicitly requires that the `LC_CTYPE` facet of the currently installed C locale be stored within the `FILE` object the moment the stream's orientation becomes wide; POSIX requires that this `LC_CTYPE` facet be used for all future I/O on this stream until the orientation is changed, regardless of any subsequent call to setlocale.
POSIX 明確要求，在流的定向變為寬定向的那一刻，目前安裝的 C 本地環境的 LC_CTYPE 側面應儲存在 FILE 物件內；POSIX 要求在定向被更改之前，該 LC_CTYPE 側面用於此流上的所有後續 I/O，無論後續如何呼叫 setlocale。
It is intended that each line of text be composed of data that are essentially human-readable. POSIX implementations do not distinguish between text and binary streams (there is no special mapping for `'\n'` or any other characters).
其意圖是每行文字由本質上人類可讀的資料組成。POSIX 實現不區分文字流和二進位制流（對 '\n' 或任何其他字元沒有特殊對映）。

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.24 Input/output <stdio.h> (p: 321-355)
7.24 輸入/輸出 <stdio.h>（頁：321-355）
7.24 輸入/輸出 <stdio.h>（頁：321-355）

- 7.31 Extended multibyte and wide character utilities <wchar.h> (p: 415-450)
7.31 擴充套件多位元組與寬字元工具 <wchar.h>（頁：415-450）
7.31 擴充套件多位元組與寬字元工具 <wchar.h>（頁：415-450）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.21 Input/output <stdio.h> (p: 217-247)
7.21 輸入/輸出 <stdio.h>（頁：217-247）
7.21 輸入/輸出 <stdio.h>（頁：217-247）

- 7.29 Extended multibyte and wide character utilities <wchar.h> (p: 295-325)
7.29 擴充套件多位元組與寬字元工具 <wchar.h>（頁：295-325）
7.29 擴充套件多位元組與寬字元工具 <wchar.h>（頁：295-325）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21 Input/output <stdio.h> (p: 296-339)
7.21 輸入/輸出 <stdio.h>（頁碼：296-339）
7.21 輸入/輸出 <stdio.h>（頁碼：296-339）

- 7.29 Extended multibyte and wide character utilities <wchar.h> (p: 402-446)
7.29 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：402-446）
7.29 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：402-446）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19 Input/output <stdio.h> (p: 262-305)
7.19 輸入/輸出 <stdio.h>（頁碼：262-305）
7.19 輸入/輸出 <stdio.h>（頁碼：262-305）

- 7.24 Extended multibyte and wide character utilities <wchar.h> (p: 348-392)
7.24 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：348-392）
7.24 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：348-392）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9 INPUT/OUTPUT <stdio.h>
4.9 輸入/輸出 <stdio.h>
4.9 輸入/輸出 <stdio.h>

### See also

stdinstdoutstderr
|   | expression of type `FILE*` associated with the input stream
expression of type `FILE*` associated with the output stream
expression of type `FILE*` associated with the error output stream
(macro constant)   |

C++ documentation for FILE

---
來源頁路徑：`en.cppreference.com/c/io/FILE.html`
