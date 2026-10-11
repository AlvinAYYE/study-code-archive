# c32rtomb

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<uchar.h>`
|   |  |   |  |

```c
size_t c32rtomb( char* restrict s, char32_t c32, mbstate_t* restrict ps );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Converts a single code point from its variable-length 32-bit wide character representation (but typically, UTF-32) to its narrow multibyte character representation.
將單個碼點從其可變長度的 32 位寬字元表示（通常為 UTF-32）轉換為窄多位元組字元表示。
If `s` is not a null pointer, the function determines the number of bytes necessary to store the multibyte character representation of `c32` (including any shift sequences, and taking into account the current multibyte conversion state `*ps`), and stores the multibyte character representation in the character array whose first element is pointed to by `s`, updating `*ps` as necessary. At most `MB_CUR_MAX` bytes can be written by this function.
如果 s 不是空指標，則函式確定儲存 c32 的多位元組字元表示所需的位元組數（包括任何移位序列，並考慮目前多位元組轉換狀態 * ps ），將該多位元組字元表示儲存到首元素由 s 指向的字元陣列中，並按需更新 * ps 。此函式最多可寫入 MB_CUR_MAX 個位元組。
If `s` is a null pointer, the call is equivalent to `c32rtomb(buf, U'\0', ps)` for some internal buffer `buf`.
如果 s 是空指標，則該呼叫等價於對某個內部緩衝區 buf 執行 c32rtomb ( buf , U '\0' , ps ) 。
If `c32` is the null wide character `U'\0'`, a null byte is stored, preceded by any shift sequence necessary to restore the initial shift state and the conversion state parameter `*ps` is updated to represent the initial shift state.
如果 c32 是空寬字元 U '\0' ，則儲存一個空位元組，其前面帶有恢復初始移位狀態所必需的任何移位序列，且轉換狀態參數 * ps 被更新為表示初始移位狀態。
If the macro `__STDC_UTF_32__` is defined, the 32-bit encoding used by this function is UTF-32; otherwise, it is implementation-defined. The macro is always defined and the encoding is always UTF-32.(since C23) In any case, the multibyte character encoding used by this function is specified by the currently active C locale.
如果宏 __STDC_UTF_32__ 已定義，則此函式使用的 32 位編碼為 UTF-32；否則由實現定義。該宏始終被定義，且編碼始終為 UTF-32。（自 C23 起）無論哪種情況，此函式使用的多位元組字元編碼均由目前活動的 C locale 指定。

### Parameters

| s  |   | -  |   | pointer to narrow character array where the multibyte character will be stored  |

| c32  |   | -  |   | the 32-bit wide character to convert  |

| ps  |   | -  |   | pointer to the conversion state object used when interpreting the multibyte string  |

### Return value

On success, returns the number of bytes (including any shift sequences) written to the character array whose first element is pointed to by `s`. This value may be `0`, e.g. when processing the leading `char32_t` units in a multi-`char32_t`-unit sequence (does not occur in UTF-32).
成功時，傳回寫入到首元素由 s 指向的字元陣列中的位元組數（包括任何移位序列）。該值可能為 0 ，例如在處理多 char32_t 碼元序列中的前導 char32_t 碼元時（這在 UTF-32 中不會發生）。
On failure (if `c32` is not a valid 32-bit wide character), returns `-1`, stores EILSEQ in errno, and leaves `*ps` in unspecified state.
失敗時（若 c32 不是有效的 32 位寬字元），傳回 -1 ，將 EILSEQ 存入 errno ，並使 * ps 處於未指定狀態。

### Example

On MSVC you will need the `/utf-8` compiler flag for UTF_8 to work properly.
在 MSVC 上，你需要 /utf-8 編譯器選項才能使 UTF_8 正常工作。
Run this code

```c
#include <locale.h> #include <stdio.h> #include <stdlib.h> #include <uchar.h> int main(void) {  setlocale(LC_ALL, "en_US.utf8");  const char32_t in[] = U"zß水🍌"; // or "z\u00df\u6c34\U0001F34C"  size_t in_sz = sizeof in / sizeof *in;  printf("Processing %zu UTF-32 code units: [", in_sz);  for (size_t n = 0; n < in_sz; ++n)  printf("%s%08X", n ? " " : "", in[n]);  puts("]");  char* out = malloc(MB_CUR_MAX * in_sz);  char* p = out;  mbstate_t state = {0};  for (size_t n = 0; n < in_sz; ++n)  {  size_t rc = c32rtomb(p, in[n], &state);  if(rc == (size_t)-1) break;  p += rc;  }  size_t out_sz = p - out;  printf("into %zu UTF-8 code units: [", out_sz);  for (size_t x = 0; x < out_sz; ++x)  printf("%s%02X", x ? " " : "", +(unsigned char)out[x]);  puts("]");  free(out); }
```

Output:

```c
Processing 5 UTF-32 code units: [0000007A 000000DF 00006C34 0001F34C 00000000] into 11 UTF-8 code units: [7A C3 9F E6 B0 B4 F0 9F 8D 8C 00]
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.30.1.6 The c32rtomb function (p: 411)
7.30.1.6 c32rtomb 函式（p: 411）
7.30.1.6 c32rtomb 函式（p: 411）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.28.1.4 The c32rtomb function (p: 401)
7.28.1.4 c32rtomb 函式（p: 401）
7.28.1.4 c32rtomb 函式（p: 401）

### See also

mbrtoc32
(C11)
|   | converts a narrow multibyte character to UTF-32 encoding
(function)   |

C++ documentation for c32rtomb

---
來源頁路徑：`en.cppreference.com/c/string/multibyte/c32rtomb.html`
