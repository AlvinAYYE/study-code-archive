# setbuf

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
void setbuf( FILE* stream, char* buffer );
```
|   |   |   | (until C99) |

```c
void setbuf( FILE* restrict stream, char* restrict buffer );
```
|   |   |   | (since C99) |

```c
#define BUFSIZ /* unspecified */
```
|   |   |   |  |

|  |  |  |  |

Sets the internal buffer to use for stream operations. It should be at least `BUFSIZ` characters long.
設定用於流操作的內部緩衝區。其長度應至少為 BUFSIZ 個字元。
If `buffer` is not null, equivalent to `setvbuf(stream, buffer, _IOFBF, BUFSIZ)`.
如果 buffer 不是空指標，則等價於 setvbuf ( stream , buffer , _IOFBF , BUFSIZ ) 。
If `buffer` is null, equivalent to `setvbuf(stream, NULL, _IONBF, 0)`, which turns off buffering.
如果 buffer 是空指標，則等價於 setvbuf ( stream , NULL , _IONBF , 0 ) ，即關閉緩衝。

### Parameters

| stream  |   | -  |   | the file stream to set the buffer to  |

| buffer  |   | -  |   | pointer to a buffer for the stream to use. If a null pointer is supplied, the buffering is turned off. If not null, the range `[``buffer``, ``buffer + BUFSIZ``)` must be valid  |

### Notes

If BUFSIZ is not the appropriate buffer size, setvbuf can be used to change it.
如果 BUFSIZ 不是合適的緩衝區大小，可以使用 setvbuf 來更改它。
setvbuf should also be used to detect errors, since `setbuf` does not indicate success or failure.
還應使用 setvbuf 來檢測錯誤，因為 setbuf 不指示成功或失敗。
This function may only be used after `stream` has been associated with an open file, but before any other operation (other than a failed call to setbuf/`setvbuf`).
此函式只能在 stream 已與開啟的檔案關聯之後、任何其他操作（setbuf / setvbuf 的失敗呼叫除外）之前使用。
A common error is setting the buffer of `stdin` or `stdout` to an array whose lifetime ends before the program terminates:
一個常見錯誤是將 stdin 或 stdout 的緩衝區設定為一個其生命期在程式終止之前結束的陣列：

```c
int main(void) {  char buf[BUFSIZ];  setbuf(stdin, buf); } // lifetime of buf ends, undefined behavior
```

### Example

`setbuf` may be used to disable buffering on streams that require immediate output.
setbuf 可用於在需要立即輸出的流上禁用緩衝。
Run this code

```c
#include <stdio.h> #include <threads.h> int main(void) {  setbuf(stdout, NULL); // unbuffered stdout  putchar('a'); // 'a' appears immediately if stdout is unbuffered  thrd_sleep(&(struct timespec){ .tv_sec = 1 }, NULL); // sleep 1 sec  putchar('b'); }
```

Output:

```c
ab
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.23.5.5 The setbuf function (p: 329)
7.23.5.5 setbuf 函式（p: 329）
7.23.5.5 setbuf 函式（p: 329）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.21.5.5 The setbuf function (p: 225)
7.21.5.5 setbuf 函式（p: 225）
7.21.5.5 setbuf 函式（p: 225）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21.5.5 The setbuf function (p: 307-308)
7.21.5.5 setbuf 函式（p: 307-308）
7.21.5.5 setbuf 函式（p: 307-308）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19.5.5 The setbuf function (p: 273)
7.19.5.5 setbuf 函式（p: 273）
7.19.5.5 setbuf 函式（p: 273）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9.5.5 The setbuf function
4.9.5.5 setbuf 函式
4.9.5.5 setbuf 函式

### See also

setvbuf
|   | sets the buffer and its size for a file stream
(function)   |

C++ documentation for setbuf

---
來源頁路徑：`en.cppreference.com/c/io/setbuf.html`
