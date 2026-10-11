# mbrtowc

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
size_t mbrtowc( wchar_t* pwc, const char* s, size_t n, mbstate_t* ps );
```
|   |   |   |  (since C95)  |

```c
size_t mbrtowc( wchar_t *restrict pwc, const char *restrict s, size_t n,  mbstate_t *restrict ps );
```
|   |   |   |  (since C99)  |

|  |  |  |  |

Converts a narrow multibyte character to its wide character representation.
將窄多位元組字元轉換為其寬字元表示。
If `s` is not a null pointer, inspects at most `n` bytes of the multibyte character string, beginning with the byte pointed to by `s` to determine the number of bytes necessary to complete the next multibyte character (including any shift sequences, and taking into account the current multibyte conversion state `*ps`). If the function determines that the next multibyte character in `s` is complete and valid, converts it to the corresponding wide character and stores it in `*pwc` (if `pwc` is not null).
如果 s 不是空指標，則從 s 所指向的位元組開始檢查多位元組字串的至多 n 個位元組，以確定完成下一個多位元組字元所需的位元組數（包括任何移位序列，並考慮目前多位元組轉換狀態 * ps）。如果函式確定 s 中的下一個多位元組字元完整且有效，則將其轉換為對應的寬字元並儲存到 * pwc（如果 pwc 不是空指標）。
If `s` is a null pointer, the values of `n` and `pwc` are ignored and call is equivalent to `mbrtowc(NULL, "", 1, ps)`.
如果 s 是空指標，則忽略 n 和 pwc 的值，本次呼叫等價於 mbrtowc ( NULL , "" , 1 , ps )。
If the wide character produced is the null character, the conversion state stored in `*ps` is the initial shift state.
如果生成的寬字元是空字元，則儲存在 * ps 中的轉換狀態為初始移位狀態。
If the environment macro `__STDC_ISO_10646__` is defined, the values of type `wchar_t` are the same as the short identifiers of the characters in the Unicode required set (typically UTF-32 encoding); otherwise, it is implementation-defined. In any case, the multibyte character encoding used by this function is specified by the currently active C locale.
如果環境宏 __STDC_ISO_10646__ 已定義，則 wchar_t 型別的值與 Unicode 必需集中字元的短識別符號相同（通常為 UTF-32 編碼）；否則由實現定義。無論哪種情況，此函式使用的多位元組字元編碼均由目前活動的 C locale 指定。

### Parameters

| pwc  |   | -  |   | pointer to the location where the resulting wide character will be written  |

| s  |   | -  |   | pointer to the multibyte character string used as input  |

| n  |   | -  |   | limit on the number of bytes in s that can be examined  |

| ps  |   | -  |   | pointer to the conversion state used when interpreting the multibyte character string  |

### Return value

The first of the following that applies:
以下第一個適用的條件：

- `0` if the character converted from `s` (and stored in `pwc` if non-null) was the null character
如果從 s 轉換的字元（非空時儲存於 pwc）是空字元，則傳回 0

- the number of bytes `[1...n]` of the multibyte character successfully converted from `s`
從 s 成功轉換的多位元組字元的位元組數 [ 1. .. n ]

- `(size_t)-2` if the next `n` bytes constitute an incomplete, but so far valid, multibyte character. Nothing is written to `*pwc`.
如果接下來的 n 個位元組構成一個不完整但目前有效的多位元組字元，則傳回 ( size_t ) -2。不會向 * pwc 寫入任何內容。

- `(size_t)-1` if encoding error occurs. Nothing is written to `*pwc`, the value EILSEQ is stored in errno and the value of `*ps` is left unspecified.
如果發生編碼錯誤則傳回 ( size_t ) -1。不會向 *pwc 寫入任何內容，EILSEQ 被寫入 errno，* ps 的值保持未指定。

### Example

Run this code

```c
#include <stdio.h> #include <locale.h> #include <string.h> #include <wchar.h>   int main(void) {  setlocale(LC_ALL, "en_US.utf8");  mbstate_t state;  memset(&state, 0, sizeof state);  char in[] = u8"z\u00df\u6c34\U0001F34C"; // or u8"zß水🍌"  size_t in_sz = sizeof in / sizeof *in;  printf("Processing %zu UTF-8 code units: [ ", in_sz);  for(size_t n = 0; n < in_sz; ++n) printf("%#x ", (unsigned char)in[n]);  puts("]");  wchar_t out[in_sz];  char *p_in = in, *end = in + in_sz;  wchar_t *p_out = out;  int rc;  while((rc = mbrtowc(p_out, p_in, end - p_in, &state)) > 0)  {  p_in += rc;  p_out += 1;  }  size_t out_sz = p_out - out + 1;  printf("into %zu wchar_t units: [ ", out_sz);  for(size_t x = 0; x < out_sz; ++x) printf("%#x ", out[x]);  puts("]"); }
```

Output:

```c
Processing 11 UTF-8 code units: [ 0x7a 0xc3 0x9f 0xe6 0xb0 0xb4 0xf0 0x9f 0x8d 0x8c 0 ] into 5 wchar_t units: [ 0x7a 0xdf 0x6c34 0x1f34c 0 ]
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.6.3.2 The mbrtowc function (p: 443)
7.29.6.3.2 mbrtowc 函式（p: 443）
7.29.6.3.2 mbrtowc 函式（p: 443）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.6.3.2 The mbrtowc function (p: 389)
7.24.6.3.2 mbrtowc 函式（p: 389）
7.24.6.3.2 mbrtowc 函式（p: 389）

### See also

mbtowc
|   | converts the next multibyte character to wide character
(function)   |

wcrtombwcrtomb_s
(C95)(C11)
|   | converts a wide character to its multibyte representation, given state
(function)   |

C++ documentation for mbrtowc

---
來源頁路徑：`en.cppreference.com/c/string/multibyte/mbrtowc.html`
