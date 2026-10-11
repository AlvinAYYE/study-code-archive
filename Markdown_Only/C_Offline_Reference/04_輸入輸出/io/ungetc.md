# ungetc

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
int ungetc( int ch, FILE* stream );
```
|   |   |   |   |

|  |  |  |  |

If `ch` does not equal EOF, pushes the character `ch` (reinterpreted as `unsigned char`) into the input buffer associated with the stream `stream` in such a manner that subsequent read operation from `stream` will retrieve that character. The external device associated with the stream is not modified.
如果 ch 不等於 EOF，則將字元 ch（重新解釋為 unsigned char）壓入與流 stream 關聯的輸入緩衝區，使得後續從 stream 的讀取操作將取回該字元。與流關聯的外部裝置不會被修改。
Stream repositioning operations fseek, fsetpos, and rewind discard the effects of `ungetc`.
流重定位操作 fseek、fsetpos 和 rewind 會丟棄 ungetc 的效果。
If `ungetc` is called more than once without an intervening read or repositioning, it may fail (in other words, a pushback buffer of size 1 is guaranteed, but any larger buffer is implementation-defined). If multiple successful `ungetc` were performed, read operations retrieve the pushed-back characters in reverse order of `ungetc`.
如果在沒有間隔的讀取或重定位操作的情況下多次呼叫 ungetc，它可能會失敗（換句話說，保證大小為 1 的回退緩衝區，但任何更大的緩衝區是實現定義的）。如果執行了多次成功的 ungetc，讀取操作按 ungetc 的相反順序取回被壓回的字元。
If `ch` equals EOF, the operation fails and the stream is not affected.
如果 ch 等於 EOF，操作失敗且流不受影響。
A successful call to `ungetc` clears the end of file status flag feof.
成功的 ungetc 呼叫會清除檔案結束狀態標誌 feof。
A successful call to `ungetc` on a binary stream decrements the stream position indicator by one (the behavior is indeterminate if the stream position indicator was zero).
在二進位制流上成功的 ungetc 呼叫會將流位置指示器減一（如果流位置指示器為零，則行為不確定）。
A successful call to `ungetc` on a text stream modifies the stream position indicator in unspecified manner but guarantees that after all pushed-back characters are retrieved with a read operation, the stream position indicator is equal to its value before `ungetc`.
在文字流上成功的 ungetc 呼叫以未指定的方式修改流位置指示器，但保證在所有被壓回的字元透過讀取操作取回後，流位置指示器等於 ungetc 之前的值。

### Parameters

| ch  |   | -  |   | character to be pushed into the input stream buffer  |

| stream  |   | -  |   | file stream to put the character back to  |

### Return value

On success `ch` is returned.
成功時傳回 ch。
On failure EOF is returned and the given stream remains unchanged.
失敗時傳回 EOF，給定的流保持不變。

### Notes

The size of the pushback buffer varies in practice from 4k (Linux, MacOS) to as little as 4 (Solaris) or the guaranteed minimum 1 (HPUX, AIX).
回退緩衝區的大小在實踐中從 4k（Linux、MacOS）到最小的 4（Solaris）或保證的最小值 1（HPUX、AIX）不等。
The apparent size of the pushback buffer may be larger if the character that is pushed back equals the character existing at that location in the external character sequence (the implementation may simply decrement the read file position indicator and avoid maintaining a pushback buffer).
如果被壓回的字元等於外部字元序列中該位置存在的字元，回退緩衝區的表觀大小可能會更大（實現可以僅遞減讀取檔案位置指示器並避免維護回退緩衝區）。

### Example

Demonstrates the original purpose of `ungetc`: implementation of scanf
演示 ungetc 的原始用途：實現 scanf
Run this code

```c
#include <ctype.h> #include <stdio.h> void demo_scanf(const char* fmt, FILE* s) {  while (*fmt != '\0')  {  if (*fmt == '%')  {  int c;  switch (*++fmt)  {  case 'u':  while (isspace(c=getc(s))) {}  unsigned int num = 0;  while (isdigit(c))  {  num = num*10 + c-'0';  c = getc(s);  }  printf("%%u scanned %u\n", num);  ungetc(c, s);  break;  case 'c':  c = getc(s);  printf("%%c scanned '%c'\n", c);  break;  }  }  else  ++fmt;  } } int main(void) {  FILE* f = fopen("input.txt", "w+");  if (f != NULL)  {  fputs("123x", f);  rewind(f);  demo_scanf("%u%c", f);  fclose(f);  }  return 0; }
```

Output:

```c
%u scanned 123 %c scanned 'x'
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.21.7.10 The ungetc function (p: TBD)
7.21.7.10 ungetc 函式（頁：TBD）
7.21.7.10 ungetc 函式（頁：TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.21.7.10 The ungetc function (p: 243)
7.21.7.10 ungetc 函式（頁：243）
7.21.7.10 ungetc 函式（頁：243）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21.7.10 The ungetc function (p: 334)
7.21.7.10 ungetc 函式（頁：334）
7.21.7.10 ungetc 函式（頁：334）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19.7.11 The ungetc function (p: 300)
7.19.7.11 ungetc 函式（頁：300）
7.19.7.11 ungetc 函式（頁：300）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9.7.11 The ungetc function
4.9.7.11 ungetc 函式
4.9.7.11 ungetc 函式

### See also

fgetcgetc
|   | gets a character from a file stream
(function)   |

C++ documentation for ungetc

---
來源頁路徑：`en.cppreference.com/c/io/ungetc.html`
