# 檔案輸入／輸出

> 來源：cppreference C 語言參考文件（離線轉換版）。

The <stdio.h> header provides generic file operation support and supplies functions with narrow character input/output capabilities.
`<stdio.h>` 標頭檔提供一般檔案操作功能，以及可處理窄字元輸入／輸出的函式。
The <wchar.h> header supplies functions with wide character input/output capabilities.
`<wchar.h>` 標頭檔提供可處理寬字元輸入／輸出的函式。
I/O streams are denoted by objects of type FILE that can only be accessed and manipulated through pointers of type `FILE*`. Each stream is associated with an external physical device (file, standard input stream, printer, serial port, etc).
I/O 串流由 `FILE` 型別的物件表示，只能透過 `FILE*` 指標存取和操作。每個串流都連接到外部裝置，例如檔案、標準輸入、印表機或序列埠。

### Types

Defined in header `<stdio.h>`

FILE
|   | 保存控制 C I/O 串流所需資訊的物件型別
(typedef)   |

fpos_t
|   | 非陣列的完整物件型別，可唯一表示檔案位置及多位元組字元轉換狀態
(typedef)   |

### Predefined standard streams
預定義的標準流

Defined in header `<stdio.h>`

stdinstdoutstderr
|   | 型別為 `FILE*`、連接到標準輸入串流的運算式
expression of type `FILE*` associated with the output stream
expression of type `FILE*` associated with the error output stream
(macro constant)   |

### Functions

#####  File access

Defined in header `<stdio.h>`

fopenfopen_s
(C11)
|   | 開啟檔案
(function)   |

freopenfreopen_s
(C11)
|   | 以不同檔名重新開啟既有串流
(function)   |

fclose
|   | 關閉檔案
(function)   |

fflush
|   | 將輸出串流中的資料同步到檔案
(function)   |

setbuf
|   | 設定檔案串流使用的緩衝區
(function)   |

setvbuf
|   | 設定檔案串流的緩衝區及其大小
(function)   |

Defined in header `<wchar.h>`

fwide
(C95)
|   | 切換檔案串流的寬字元或窄字元 I/O 模式
(function)   |

#####  Direct input/output

Defined in header `<stdio.h>`

fread
|   | 從檔案讀取資料
(function)   |

fwrite
|   | 將資料寫入檔案
(function)   |

#####  Unformatted input/output

###### Narrow character

Defined in header `<stdio.h>`

fgetcgetc
|   | 從檔案串流讀取一個字元
(function)   |

fgets
|   | 從檔案串流讀取一行字元
(function)   |

fputcputc
|   | 將一個字元寫入檔案串流
(function)   |

fputs
|   | 將字串寫入檔案串流
(function)   |

getchar
|   | 從 `stdin` 讀取一個字元
(function)   |

getsgets_s
(removed in C11)(C11)
|   | 從 `stdin` 讀取一行字元
(function)   |

putchar
|   | 將一個字元寫到 `stdout`
(function)   |

puts
|   | 將字串寫到 `stdout`
(function)   |

ungetc
|   | 將一個字元放回檔案串流，供下次讀取
(function)   |

###### Wide character

Defined in header `<wchar.h>`

fgetwcgetwc
(C95)
|   | 從檔案串流讀取一個寬字元
(function)   |

fgetws
(C95)
|   | 從檔案串流讀取一行寬字元
(function)   |

fputwcputwc
(C95)
|   | 將一個寬字元寫入檔案串流
(function)   |

fputws
(C95)
|   | 將寬字串寫入檔案串流
(function)   |

getwchar
(C95)
|   | 從 `stdin` 讀取一個寬字元
(function)   |

putwchar
(C95)
|   | 將一個寬字元寫到 `stdout`
(function)   |

ungetwc
(C95)
|   | 將一個寬字元放回檔案串流，供下次讀取
(function)   |

#####  Formatted input/output

###### Narrow character

Defined in header `<stdio.h>`

scanffscanfsscanfscanf_sfscanf_ssscanf_s
(C11)(C11)(C11)
|   | 從 `stdin`、檔案串流或字串讀取格式化資料
(function)   |

vscanfvfscanfvsscanfvscanf_svfscanf_svsscanf_s
(C99)(C99)(C99)(C11)(C11)(C11)
|   | 從 `stdin`、檔案串流或字串讀取格式化資料
using variable argument list
(function)   |

printffprintfsprintfsnprintfprintf_sfprintf_ssprintf_ssnprintf_s
(C99)(C11)(C11)(C11)(C11)
|   | 將格式化資料輸出至 `stdout`、檔案串流或字串
(function)   |

vprintfvfprintfvsprintfvsnprintfvprintf_svfprintf_svsprintf_svsnprintf_s
(C99)(C11)(C11)(C11)(C11)
|   | 將格式化資料輸出至 `stdout`、檔案串流或字串
using variable argument list
(function)   |

###### Wide character

Defined in header `<wchar.h>`

wscanffwscanfswscanfwscanf_sfwscanf_sswscanf_s
(C95)(C95)(C95)(C11)(C11)(C11)
|   | 從 `stdin`、檔案串流或字串讀取格式化寬字元資料
(function)   |

vwscanfvfwscanfvswscanfvwscanf_svfwscanf_svswscanf_s
(C99)(C99)(C99)(C11)(C11)(C11)
|   | 使用可變參數清單，從 `stdin`、檔案串流或字串讀取格式化寬字元資料
(function)   |

wprintffwprintfswprintfwprintf_sfwprintf_sswprintf_ssnwprintf_s
(C95)(C95)(C95)(C11)(C11)(C11)(C11)
|   | 將格式化寬字元資料輸出至 `stdout`、檔案串流或字串
(function)   |

vwprintfvfwprintfvswprintfvwprintf_svfwprintf_svswprintf_svsnwprintf_s
(C95)(C95)(C95)(C11)(C11)(C11)(C11)
|   | 使用可變參數清單，將格式化寬字元資料輸出至 `stdout`、檔案串流或字串
(function)   |

#####  File positioning

Defined in header `<stdio.h>`

ftell
|   | 傳回目前的檔案位置
(function)   |

fgetpos
|   | 取得檔案位置
(function)   |

fseek
|   | 將檔案位置移到指定位置
(function)   |

fsetpos
|   | moves the file position indicator to a specific location in a file
(function)   |

rewind
|   | 將檔案位置移到檔案開頭
(function)   |

#####  Error handling

Defined in header `<stdio.h>`

clearerr
|   | 清除錯誤狀態
(function)   |

feof
|   | 檢查是否已到達檔案結尾
(function)   |

ferror
|   | 檢查串流是否發生錯誤
(function)   |

perror
|   | 將目前錯誤碼對應的文字說明輸出至 `stderr`
(function)   |

#####  Operations on files

Defined in header `<stdio.h>`

remove
|   | 刪除檔案
(function)   |

rename
|   | 重新命名檔案
(function)   |

tmpfiletmpfile_s
(C11)
|   | 傳回暫存檔案的指標
(function)   |

tmpnamtmpnam_s
(C11)
|   | 傳回唯一的檔名
(function)   |

### Macro constants
宏常量

Defined in header `<stdio.h>`

EOF
|   | 值為負數的 `int` 整數常數運算式
(macro constant)  |

FOPEN_MAX
|   | 可同時開啟的檔案數上限
(macro constant)  |

FILENAME_MAX
|   | 儲存最長支援檔名所需的 `char` 陣列大小
(macro constant)  |

_PRINTF_NAN_LEN_MAX
(C23)
|   | 輸出 NaN（可能帶負號）時最多會用到的字元數
(macro constant)  |

BUFSIZ
|   | `setbuf` 使用的緩衝區大小
(macro constant)  |

_IOFBF_IOLBF_IONBF
|   | 指定 `setvbuf` 要設定的緩衝模式：全緩衝、行緩衝或無緩衝
(macro constant)  |

SEEK_SETSEEK_CURSEEK_END
|   | 指定 `fseek` 計算位移時的起點：檔案開頭、目前位置或檔案結尾
(macro constant)  |

TMP_MAXTMP_MAX_S
(C11)
|   | `tmpnam`／`tmpnam_s` 可產生的唯一檔名數量上限
(macro constant)  |

L_tmpnamL_tmpnam_s
(C11)
|   | 儲存 `tmpnam`／`tmpnam_s` 結果所需的 `char` 陣列大小
(macro constant)  |

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.21 Input/output <stdio.h> (p: TBD)
7.21 輸入/輸出 <stdio.h>（頁碼：待定）
7.21 輸入/輸出 <stdio.h>（頁碼：待定）

- 7.29 Extended multibyte and wide character utilities <wchar.h> (p: TBD)
7.29 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：待定）
7.29 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：待定）

- 7.31.11 Input/output <stdio.h> (p: TBD)
7.31.11 輸入/輸出 <stdio.h>（頁碼：待定）
7.31.11 輸入/輸出 <stdio.h>（頁碼：待定）

- 7.31.16 Extended multibyte and wide character utilities <wchar.h> (p: TBD)
7.31.16 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：待定）
7.31.16 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：待定）

- K.3.5 Input/output <stdio.h> (p: TBD)
K.3.5 輸入/輸出 <stdio.h>（頁碼：待定）
K.3.5 輸入/輸出 <stdio.h>（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.21 Input/output <stdio.h> (p: TBD)
7.21 輸入/輸出 <stdio.h>（頁碼：待定）
7.21 輸入/輸出 <stdio.h>（頁碼：待定）

- 7.29 Extended multibyte and wide character utilities <wchar.h> (p: TBD)
7.29 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：待定）
7.29 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：待定）

- 7.31.11 Input/output <stdio.h> (p: TBD)
7.31.11 輸入/輸出 <stdio.h>（頁碼：待定）
7.31.11 輸入/輸出 <stdio.h>（頁碼：待定）

- 7.31.16 Extended multibyte and wide character utilities <wchar.h> (p: TBD)
7.31.16 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：待定）
7.31.16 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：待定）

- K.3.5 Input/output <stdio.h> (p: TBD)
K.3.5 輸入/輸出 <stdio.h>（頁碼：待定）
K.3.5 輸入/輸出 <stdio.h>（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21 Input/output <stdio.h> (p: 296-339)
7.21 輸入/輸出 <stdio.h>（頁碼：296-339）
7.21 輸入/輸出 <stdio.h>（頁碼：296-339）

- 7.29 Extended multibyte and wide character utilities <wchar.h> (p: 402-446)
7.29 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：402-446）
7.29 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：402-446）

- 7.31.11 Input/output <stdio.h> (p: 456)
7.31.11 輸入/輸出 <stdio.h>（頁碼：456）
7.31.11 輸入/輸出 <stdio.h>（頁碼：456）

- 7.31.16 Extended multibyte and wide character utilities <wchar.h> (p: 456)
7.31.16 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：456）
7.31.16 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：456）

- K.3.5 Input/output <stdio.h> (p: 586-603)
K.3.5 輸入/輸出 <stdio.h>（頁碼：586-603）
K.3.5 輸入/輸出 <stdio.h>（頁碼：586-603）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19 Input/output <stdio.h> (p: 262-305)
7.19 輸入/輸出 <stdio.h>（頁碼：262-305）
7.19 輸入/輸出 <stdio.h>（頁碼：262-305）

- 7.24 Extended multibyte and wide character utilities <wchar.h> (p: 348-392)
7.24 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：348-392）
7.24 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：348-392）

- 7.26.9 Input/output <stdio.h> (p: 402)
7.26.9 輸入/輸出 <stdio.h>（頁碼：402）
7.26.9 輸入/輸出 <stdio.h>（頁碼：402）

- 7.26.12 Extended multibyte and wide character utilities <wchar.h> (p: 402)
7.26.12 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：402）
7.26.12 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：402）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9 INPUT/OUTPUT <stdio.h>
4.9 輸入/輸出 <stdio.h>
4.9 輸入/輸出 <stdio.h>

- 4.13.6 Input/output <stdio.h>
4.13.6 輸入/輸出 <stdio.h>
4.13.6 輸入/輸出 <stdio.h>

### See also

C++ documentation for C-style file input/output

---
來源頁路徑：`en.cppreference.com/c/io.html`
