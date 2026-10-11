# c16rtomb

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<uchar.h>`
|   |  |   |  |

```c
size_t c16rtomb( char* restrict s, char16_t c16, mbstate_t* restrict ps );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Converts a single code point from its variable-length 16-bit wide character representation (typically, UTF-16) to its narrow multibyte character representation.
將單個碼點從其可變長度的 16 位寬字元表示（通常為 UTF-16）轉換為其窄多位元組字元表示。
If `s` is not a null pointer and `c16` is the last 16-bit code unit in a valid variable-length encoding of a code point, the function determines the number of bytes necessary to store the multibyte character representation of that code point (including any shift sequences, and taking into account the current multibyte conversion state `*ps`), and stores the multibyte character representation in the character array whose first element is pointed to by `s`, updating `*ps` as necessary. At most `MB_CUR_MAX` bytes can be written by this function.
如果 s 不是空指標且 c16 是某個碼點的有效可變長度編碼中的最後一個 16 位碼元，則函式確定儲存該碼點多位元組字元表示所需的位元組數（包括任何移位序列，並考慮目前多位元組轉換狀態 * ps），並將該多位元組字元表示儲存到首元素由 s 指向的字元陣列中，並在必要時更新 * ps。此函式至多可寫入 MB_CUR_MAX 個位元組。
If `s` is a null pointer, the call is equivalent to `c16rtomb(buf, u'\0', ps)` for some internal buffer `buf`.
如果 s 是空指標，則本次呼叫等價於對某個內部緩衝區 buf 執行 c16rtomb ( buf , u '\0' , ps )。
If `c16` is the null wide character `u'\0'`, a null byte is stored, preceded by any shift sequence necessary to restore the initial shift state and the conversion state parameter `*ps` is updated to represent the initial shift state.
如果 c16 是空寬字元 u '\0'，則儲存一個空位元組，其前面帶有恢復初始移位狀態所需的所有移位序列，並且轉換狀態參數 * ps 被更新為表示初始移位狀態。
If `c16` is not the final code unit in a 16-bit representation of a wide character, it does not write to the array pointed to by `s`, only `*ps` is updated.
如果 c16 不是寬字元的 16 位表示中的最後一個碼元，則不會寫入 s 指向的陣列，只會更新 * ps。
If the macro `__STDC_UTF_16__` is defined, the 16-bit encoding used by this function is UTF-16; otherwise, it is implementation-defined. The macro is always defined and the encoding is always UTF-16.(since C23) In any case, the multibyte character encoding used by this function is specified by the currently active C locale.
如果宏 __STDC_UTF_16__ 已定義，則此函式使用的 16 位編碼為 UTF-16；否則由實現定義。該宏始終被定義，且編碼始終為 UTF-16。（自 C23 起）無論哪種情況，此函式使用的多位元組字元編碼均由目前活動的 C locale 指定。

### Parameters

| s  |   | -  |   | pointer to narrow character array where the multibyte character will be stored  |

| c16  |   | -  |   | the 16-bit wide character to convert  |

| ps  |   | -  |   | pointer to the conversion state object used when interpreting the multibyte string  |

### Return value

On success, returns the number of bytes (including any shift sequences) written to the character array whose first element is pointed to by `s`. This value may be `0`, e.g. when processing the leading `char16_t` units in a multi-`char16_t`-unit sequence (occurs when processing the leading surrogate in a surrogate pair of UTF-16).
成功時，傳回寫入到首元素由 s 指向的字元陣列中的位元組數（包括任何移位序列）。該值可能為 0，例如在處理多 char16_t 碼元序列中的前導 char16_t 碼元時（在處理 UTF-16 代理對中的前導代理項時會出現這種情況）。
On failure (if `c16` is not a valid 16-bit code unit), returns `-1`, stores EILSEQ in errno, and leaves `*ps` in unspecified state.
失敗時（如果 c16 不是有效的 16 位碼元），傳回 -1 ，將 EILSEQ 寫入 errno，並使 * ps 處於未指定狀態。

### Notes

In C11 as published, unlike mbrtoc16, which converts variable-width multibyte (such as UTF-8) to variable-width 16-bit (such as UTF-16) encoding, this function can only convert single-unit 16-bit encoding, meaning it cannot convert UTF-16 to UTF-8 despite that being the original intent of this function. This was corrected by the post-C11 defect report DR488.
在正式釋出的 C11 中，與將可變寬度多位元組（如 UTF-8）轉換為可變寬度 16 位（如 UTF-16）編碼的 mbrtoc16 不同，此函式只能轉換單碼元的 16 位編碼，這意味著它無法將 UTF-16 轉換為 UTF-8，儘管這才是該函式的初衷。此問題已由 C11 之後的缺陷報告 DR488 修正。

### Example

Note: this example assumes the fix for the defect report DR488 is applied.
On MSVC you may need the `/utf-8` compiler flag for UTF_8 to work properly.
注意：本示例假設缺陷報告 DR488 的修復已被應用。在 MSVC 上，你可能需要 /utf-8 編譯器選項才能使 UTF_8 正常工作。
Run this code

```c
#include <locale.h> #include <stdio.h> #include <stdlib.h> #include <uchar.h> int main(void) {  setlocale(LC_ALL, "en_US.utf8");  const char16_t in[] = u"zß水🍌"; // or "z\u00df\u6c34\U0001F34C"  const size_t in_sz = sizeof in / sizeof *in;  printf("Processing %zu UTF-16 code units: [", in_sz);  for (size_t n = 0; n < in_sz; ++n)  printf("%s%04X", n ? " " : "", in[n]);  puts("]");  char* out = malloc(MB_CUR_MAX * in_sz);  char* p = out;  mbstate_t state = {0};  for (size_t n = 0; n < in_sz; ++n)  {  size_t rc = c16rtomb(p, in[n], &state);  if (rc == (size_t)-1)  break;  p += rc;  }  size_t out_sz = p - out;  printf("into %zu UTF-8 code units: [", out_sz);  for (size_t x = 0; x < out_sz; ++x)  printf("%s%02X", x ? " " : "", +(unsigned char)out[x]);  puts("]");  free(out); }
```

Output:

```c
Processing 6 UTF-16 code units: [007A 00DF 6C34 D83C DF4C 0000] into 13 UTF-8 code units: [7A C3 9F E6 B0 B4 ED A0 BC ED BD 8C 00]
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.28.1.2 The c16rtomb function (p: TBD)
7.28.1.2 c16rtomb 函式（p: TBD）
7.28.1.2 c16rtomb 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.28.1.2 The c16rtomb function (p: TBD)
7.28.1.2 c16rtomb 函式（p: TBD）
7.28.1.2 c16rtomb 函式（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.28.1.2 The c16rtomb function (p: 399-400)
7.28.1.2 c16rtomb 函式（p: 399-400）
7.28.1.2 c16rtomb 函式（p: 399-400）

### See also

mbrtoc16
(C11)
|   | converts a narrow multibyte character to UTF-16 encoding
(function)   |

C++ documentation for c16rtomb

---
來源頁路徑：`en.cppreference.com/c/string/multibyte/c16rtomb.html`
