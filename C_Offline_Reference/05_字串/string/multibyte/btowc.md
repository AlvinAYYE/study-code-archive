# btowc

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
wint_t btowc( int c );
```
|   |   |   |  (since C95)  |

|  |  |  |  |

Widens a single-byte character `c` (reinterpreted as `unsigned char`) to its wide character equivalent.
將單位元組字元 c（重新解釋為 unsigned char）轉換為等價的寬字元。
Most multibyte character encodings use single-byte codes to represent the characters from the ASCII character set. This function may be used to convert such characters to `wchar_t`.
大多數多位元組字元編碼使用單位元組編碼表示 ASCII 字符集中的字元。此函式可用於將這類字元轉換為 wchar_t。

### Parameters

| c  |   | -  |   | single-byte character to widen  |

### Return value

`WEOF` if `c` is EOF
如果 c 是 EOF 則傳回 WEOF
wide character representation of `c` if `(unsigned char)c` is a valid single-byte character in the initial shift state, `WEOF` otherwise.
如果 ( unsigned char ) c 是初始移位狀態下的有效單位元組字元，則傳回 c 的寬字元表示，否則傳回 WEOF。

### Example

Run this code

```c
#include <stdio.h> #include <wchar.h> #include <locale.h> #include <assert.h> void try_widen(unsigned char c) {  wint_t w = btowc(c);  if(w != WEOF)  printf("The single-byte character %#x widens to %#x\n", c, w);  else  printf("The single-byte character %#x failed to widen\n", c); } int main(void) {  char *loc = setlocale(LC_ALL, "lt_LT.iso88594");  assert(loc);  printf("In Lithuanian ISO-8859-4 locale:\n");  try_widen('A');  try_widen('\xdf'); // German letter ß (U+00df) in ISO-8859-4  try_widen('\xf9'); // Lithuanian letter ų (U+0173) in ISO-8859-4  setlocale(LC_ALL, "lt_LT.utf8");  printf("In Lithuanian UTF-8 locale:\n");  try_widen('A');  try_widen('\xdf');  try_widen('\xf9'); }
```

Possible output:
可能的輸出：

```c
In Lithuanian ISO-8859-4 locale: The single-byte character 0x41 widens to 0x41 The single-byte character 0xdf widens to 0xdf The single-byte character 0xf9 widens to 0x173 In Lithuanian UTF-8 locale: The single-byte character 0x41 widens to 0x41 The single-byte character 0xdf failed to widen The single-byte character 0xf9 failed to widen
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.6.1.1 The btowc function (p: 441)
7.29.6.1.1 btowc 函式（p: 441）
7.29.6.1.1 btowc 函式（p: 441）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.6.1.1 The btowc function (p: 387)
7.24.6.1.1 btowc 函式（p: 387）
7.24.6.1.1 btowc 函式（p: 387）

### See also

wctob
(C95)
|   | narrows a wide character to a single-byte narrow character, if possible
(function)   |

C++ documentation for btowc

---
來源頁路徑：`en.cppreference.com/c/string/multibyte/btowc.html`
