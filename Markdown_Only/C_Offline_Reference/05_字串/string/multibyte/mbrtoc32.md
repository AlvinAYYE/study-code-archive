# mbrtoc32

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<uchar.h>`
|   |  |   |  |

```c
size_t mbrtoc32( char32_t restrict* pc32, const char* restrict s,  size_t n, mbstate_t* restrict ps );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Converts a single code point from its narrow multibyte character representation to its variable-length 32-bit wide character representation (but typically, UTF-32).
將單個碼點從其窄多位元組字元表示轉換為其可變長度的 32 位寬字元表示（但通常為 UTF-32）。
If `s` is not a null pointer, inspects at most `n` bytes of the multibyte character string, beginning with the byte pointed to by `s` to determine the number of bytes necessary to complete the next multibyte character (including any shift sequences, and taking into account the current multibyte conversion state `*ps`). If the function determines that the next multibyte character in `s` is complete and valid, converts it to the corresponding 32-bit wide character and stores it in `*pc32` (if `pc32` is not null).
如果 s 不是空指標，則從 s 所指向的位元組開始檢查多位元組字串的至多 n 個位元組，以確定完成下一個多位元組字元所需的位元組數（包括任何移位序列，並考慮目前多位元組轉換狀態 * ps）。如果函式確定 s 中的下一個多位元組字元完整且有效，則將其轉換為對應的 32 位寬字元並儲存到 * pc32（如果 pc32 不是空指標）。
If the multibyte character in `*s` corresponds to a multi-`char32_t` sequence (not possible with UTF-32), then after the first call to this function, `*ps` is updated in such a way that the next calls to `mbrtoc32` will write out the additional `char32_t`, without considering `*s`.
如果 * s 中的多位元組字元對應於一個多 char32_t 序列（UTF-32 不可能出現這種情況），則在第一次呼叫此函式後，* ps 會被更新，使得後續對 mbrtoc32 的呼叫無需考慮 * s 即可寫出額外的 char32_t。
If `s` is a null pointer, the values of `n` and `pc32` are ignored and the call is equivalent to `mbrtoc32(NULL, "", 1, ps)`.
如果 s 是空指標，則忽略 n 和 pc32 的值，本次呼叫等價於 mbrtoc32 ( NULL , "" , 1 , ps )。
If the wide character produced is the null character, the conversion state `*ps` represents the initial shift state.
如果生成的寬字元是空字元，則轉換狀態 * ps 表示初始移位狀態。
If the macro `__STDC_UTF_32__` is defined, the 32-bit encoding used by this function is UTF-32; otherwise, it is implementation-defined. The macro is always defined and the encoding is always UTF-32.(since C23) In any case, the multibyte character encoding used by this function is specified by the currently active C locale.
如果宏 __STDC_UTF_32__ 已定義，則此函式使用的 32 位編碼為 UTF-32；否則由實現定義。該宏始終被定義，且編碼始終為 UTF-32。（自 C23 起）無論哪種情況，此函式使用的多位元組字元編碼均由目前活動的 C locale 指定。

### Parameters

| pc32  |   | -  |   | pointer to the location where the resulting 32-bit wide character will be written  |

| s  |   | -  |   | pointer to the multibyte character string used as input  |

| n  |   | -  |   | limit on the number of bytes in s that can be examined  |

| ps  |   | -  |   | pointer to the conversion state object used when interpreting the multibyte string  |

### Return value

The first of the following that applies:
以下第一個適用的條件：

- `0` if the character converted from `s` (and stored in `*pc32` if non-null) was the null character.
如果從 s 轉換的字元（非空時儲存於 * pc32）是空字元，則傳回 0。

- The number of bytes `[``1``, ``n``]` of the multibyte character successfully converted from `s`.
從 s 成功轉換的多位元組字元的位元組數 [ 1 , n ]。

- `(size_t)-3` if the next `char32_t` from a multi-`char32_t` character has now been written to `*pc32`. No bytes are processed from the input in this case.
如果來自多 char32_t 字元的下一個 char32_t 現已寫入 * pc32，則傳回 ( size_t ) -3。此情況下不處理輸入的任何位元組。

- `(size_t)-2` if the next `n` bytes constitute an incomplete, but so far valid, multibyte character. Nothing is written to `*pc32`.
如果接下來的 n 個位元組構成一個不完整但目前有效的多位元組字元，則傳回 ( size_t ) -2。不會向 * pc32 寫入任何內容。

- `(size_t)-1` if encoding error occurs. Nothing is written to `*pc32`, the value EILSEQ is stored in errno and the value of `*ps` is unspecified.
如果發生編碼錯誤則傳回 ( size_t ) -1。不會向 * pc32 寫入任何內容，EILSEQ 被寫入 errno，* ps 的值未指定。

### Example

On MSVC you will need the `/utf-8` compiler flag for UTF_8 to work properly.
在 MSVC 上，你需要 /utf-8 編譯器選項才能使 UTF_8 正常工作。
Run this code

```c
#include <assert.h> #include <locale.h> #include <stdio.h> #include <uchar.h> int main(void) {  setlocale(LC_ALL, "en_US.utf8");  char in[] = u8"zß水🍌"; // or "z\u00df\u6c34\U0001F34C"  enum { in_size = sizeof in / sizeof *in };  printf("Processing %d UTF-8 code units: [", in_size);  for (int i = 0; i < in_size; ++i)  printf("%s%02X", i ? " " : "", (unsigned char)in[i]);  puts("]");  char32_t out[in_size];  char32_t* p_out = out;  char* p_in = in;  char* end = in + in_size;  mbstate_t state = {0};  size_t rc;  while ((rc = mbrtoc32(p_out, p_in, end - p_in, &state)))  {  assert(rc != (size_t)-3); // no surrogate pairs in UTF-32  if (rc == (size_t)-1) break; // invalid input  if (rc == (size_t)-2) break; // truncated input  p_in += rc;  ++p_out;  }  size_t out_size = p_out+1 - out;  printf("into %zu UTF-32 code units: [", out_size);  for (size_t i = 0; i < out_size; ++i)  printf("%s%08X", i ? " " : "", out[i]);  puts("]"); }
```

Output:

```c
Processing 11 UTF-8 code units: [7A C3 9F E6 B0 B4 F0 9F 8D 8C 00] into 5 UTF-32 code units: [0000007A 000000DF 00006C34 0001F34C 00000000]
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.30.1.5 The mbrtoc32 function (p: 410)
7.30.1.5 mbrtoc32 函式（p: 410）
7.30.1.5 mbrtoc32 函式（p: 410）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.28.1.3 The mbrtoc32 function (p: 293-294)
7.28.1.3 mbrtoc32 函式（p: 293-294）
7.28.1.3 mbrtoc32 函式（p: 293-294）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.28.1.3 The mbrtoc32 function (p: 400-401)
7.28.1.3 mbrtoc32 函式（p: 400-401）
7.28.1.3 mbrtoc32 函式（p: 400-401）

### See also

c32rtomb
(C11)
|   | converts a UTF-32 character to narrow multibyte encoding
(function)   |

C++ documentation for mbrtoc32

---
來源頁路徑：`en.cppreference.com/c/string/multibyte/mbrtoc32.html`
