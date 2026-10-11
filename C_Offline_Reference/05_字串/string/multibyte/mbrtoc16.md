# mbrtoc16

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<uchar.h>`
|   |  |   |  |

```c
size_t mbrtoc16( char16_t* restrict pc16, const char* restrict s,  size_t n, mbstate_t* restrict ps );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Converts a single code point from its narrow multibyte character representation to its variable-length 16-bit wide character representation (typically, UTF-16).
將單個碼點從其窄多位元組字元表示轉換為可變長度的 16 位寬字元表示（通常為 UTF-16）。
If `s` is not a null pointer, inspects at most `n` bytes of the multibyte character string, beginning with the byte pointed to by `s` to determine the number of bytes necessary to complete the next multibyte character (including any shift sequences, and taking into account the current multibyte conversion state `*ps`). If the function determines that the next multibyte character in `s` is complete and valid, converts it to the corresponding 16-bit wide character and stores it in `*pc16` (if `pc16` is not null).
如果 s 不是空指標，則檢查多位元組字串的至多 n 個位元組（從 s 指向的位元組開始），以確定完成下一個多位元組字元所需的位元組數（包括任何移位序列，並考慮目前多位元組轉換狀態 * ps ）。如果函式確定 s 中的下一個多位元組字元已完整且有效，則將其轉換為對應的 16 位寬字元，並儲存到 * pc16 （如果 pc16 不為空）。
If the multibyte character in `*s` corresponds to a multi-`char16_t` sequence (e.g. a surrogate pair in UTF-16), then after the first call to this function, `*ps` is updated in such a way that the next call to `mbrtoc16` will write out the additional `char16_t`, without considering `*s`.
如果 * s 中的多位元組字元對應於多 char16_t 序列（例如 UTF-16 中的代理對），則在第一次呼叫本函式後，* ps 會被更新，使得下一次呼叫 mbrtoc16 會寫出額外的 char16_t ，而無需考慮 * s 。
If `s` is a null pointer, the values of `n` and `pc16` are ignored and the call is equivalent to `mbrtoc16(NULL, "", 1, ps)`.
如果 s 是空指標，則忽略 n 和 pc16 的值，該呼叫等價於 mbrtoc16 ( NULL , "" , 1 , ps ) 。
If the wide character produced is the null character, the conversion state `*ps` represents the initial shift state.
如果生成的寬字元是空字元，則轉換狀態 * ps 表示初始移位狀態。
If the macro `__STDC_UTF_16__` is defined, the 16-bit encoding used by this function is UTF-16; otherwise, it is implementation-defined. The macro is always defined and the encoding is always UTF-16.(since C23) In any case, the multibyte character encoding used by this function is specified by the currently active C locale.
如果宏 __STDC_UTF_16__ 已定義，則此函式使用的 16 位編碼為 UTF-16；否則由實現定義。該宏始終被定義，且編碼始終為 UTF-16。（自 C23 起）無論哪種情況，此函式使用的多位元組字元編碼均由目前活動的 C locale 指定。

### Parameters

| pc16  |   | -  |   | pointer to the location where the resulting 16-bit wide character will be written  |

| s  |   | -  |   | pointer to the multibyte character string used as input  |

| n  |   | -  |   | limit on the number of bytes in s that can be examined  |

| ps  |   | -  |   | pointer to the conversion state object used when interpreting the multibyte string  |

### Return value

The first of the following that applies:
以下第一個適用的條件：

- `0` if the character converted from `s` (and stored in `*pc16` if non-null) was the null character.
如果從 s 轉換的字元（若非空則儲存於 * pc16 ）是空字元，則傳回 0 。

- The number of bytes `[``1``, ``n``]` of the multibyte character successfully converted from `s`.
從 s 成功轉換的多位元組字元的位元組數 [ 1 , n ]。

- `(size_t)-3` if the next `char16_t` from a multi-`char16_t` character (e.g. a surrogate pair) has now been written to `*pc16`. No bytes are processed from the input in this case.
如果來自某個多 char16_t 字元（例如代理對）的下一個 char16_t 現已寫入 * pc16 ，則傳回 ( size_t ) -3 。此種情況下不處理輸入的任何位元組。

- `(size_t)-2` if the next `n` bytes constitute an incomplete, but so far valid, multibyte character. Nothing is written to `*pc16`.
如果接下來的 n 個位元組構成一個尚不完整但目前有效的多位元組字元，則傳回 ( size_t ) -2 。不會向 * pc16 寫入任何內容。

- `(size_t)-1` if encoding error occurs. Nothing is written to `*pc16`, the value EILSEQ is stored in errno and the value of `*ps` is unspecified.
如果發生編碼錯誤，則傳回 ( size_t ) -1 。不會向 * pc16 寫入任何內容，EILSEQ 的值存入 errno ，且 * ps 的值未指定。

### Example

On MSVC you may need the `/utf-8` compiler flag for UTF_8 to work properly.
在 MSVC 上，你可能需要 /utf-8 編譯器標誌才能使 UTF_8 正常工作。
Run this code

```c
#include <locale.h> #include <stdio.h> #include <uchar.h> int main(void) {  setlocale(LC_ALL, "en_US.utf8");  const char in[] = u8"zß水🍌"; // or "z\u00df\u6c34\U0001F34C"  enum { in_sz = sizeof in / sizeof *in };  printf("Processing %d UTF-8 code units: [", in_sz);  for (int n = 0; n < in_sz; ++n)  printf("%s%02X", n ? " " : "", (unsigned char)in[n]);  puts("]");  char16_t out[in_sz];  const char* p_in = in;  const char* end = in + in_sz;  char16_t* p_out = out;  mbstate_t state = {0};  for (size_t rc; (rc = mbrtoc16(p_out, p_in, end - p_in, &state));)  {  if (rc == (size_t)-1) // invalid input  break;  else if(rc == (size_t)-2) // truncated input  break;  else if(rc == (size_t)-3) // UTF-16 high surrogate  p_out += 1;  else  {  p_in += rc;  p_out += 1;  };  }  const size_t out_sz = p_out - out + 1;  printf("into %zu UTF-16 code units: [", out_sz);  for (size_t x = 0; x < out_sz; ++x)  printf("%s%04X", x ? " " : "", out[x]);  puts("]"); }
```

Output:

```c
Processing 11 UTF-8 code units: [7A C3 9F E6 B0 B4 F0 9F 8D 8C 00] into 6 UTF-16 code units: [007A 00DF 6C34 D83C DF4C 0000]
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.30.1.3 The mbrtoc16 function (p: 408-409)
7.30.1.3 mbrtoc16 函式（p: 408-409）
7.30.1.3 mbrtoc16 函式（p: 408-409）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.28.1.1 The mbrtoc16 function (p: 398-399)
7.28.1.1 mbrtoc16 函式（p: 398-399）
7.28.1.1 mbrtoc16 函式（p: 398-399）

### See also

c16rtomb
(C11)
|   | converts a UTF-16 character to narrow multibyte encoding
(function)   |

C++ documentation for mbrtoc16

---
來源頁路徑：`en.cppreference.com/c/string/multibyte/mbrtoc16.html`
