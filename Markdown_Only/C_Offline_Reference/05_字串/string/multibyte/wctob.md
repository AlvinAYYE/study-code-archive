# wctob

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
int wctob( wint_t c );
```
|   |   |   |  (since C95)  |

|  |  |  |  |

Narrows a wide character `c` if its multibyte character equivalent in the initial shift state is a single byte.
如果寬字元 c 在初始移位狀態下的多位元組字元等價形式是單位元組的，則將其收窄。
This is typically possible for the characters from the ASCII character set, since most multibyte encodings (such as UTF-8) use single bytes to encode those characters.
對於 ASCII 字符集中的字元，這通常是可行的，因為大多數多位元組編碼（如 UTF-8）使用單位元組來編碼這些字元。

### Parameters

| c  |   | -  |   | wide character to narrow  |

### Return value

EOF if `c` does not represent a multibyte character with length `1` in initial shift state.
如果 c 在初始移位狀態下不表示長度為 1 的多位元組字元，則傳回 EOF 。
otherwise, the single-byte representation of `c` as `unsigned char` converted to `int`
否則傳回 c 的 unsigned char 單位元組表示轉換為 int 的值

### Example

Run this code

```c
#include <locale.h> #include <wchar.h> #include <stdio.h> #include <assert.h> void try_narrowing(wchar_t c) {  int cn = wctob(c);  if(cn != EOF)  printf("%#x narrowed to %#x\n", c, cn);  else  printf("%#x could not be narrowed\n", c); } int main(void) {  char* utf_locale_present = setlocale(LC_ALL, "th_TH.utf8");  assert(utf_locale_present);  puts("In Thai UTF-8 locale:");  try_narrowing(L'a');  try_narrowing(L'๛');  char* tis_locale_present = setlocale(LC_ALL, "th_TH.tis620");  assert(tis_locale_present);  puts("In Thai TIS-620 locale:");  try_narrowing(L'a');  try_narrowing(L'๛'); }
```

Possible output:
可能的輸出：

```c
In Thai UTF-8 locale: 0x61 narrowed to 0x61 0xe5b could not be narrowed In Thai TIS-620 locale: 0x61 narrowed to 0x61 0xe5b narrowed to 0xfb
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.6.1.2 The wctob function (p: 441)
7.29.6.1.2 wctob 函式（p: 441）
7.29.6.1.2 wctob 函式（p: 441）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.6.1.2 The wctob function (p: 387)
7.24.6.1.2 wctob 函式（p: 387）
7.24.6.1.2 wctob 函式（p: 387）

### See also

btowc
(C95)
|   | widens a single-byte narrow character to wide character, if possible
(function)   |

C++ documentation for wctob

---
來源頁路徑：`en.cppreference.com/c/string/multibyte/wctob.html`
