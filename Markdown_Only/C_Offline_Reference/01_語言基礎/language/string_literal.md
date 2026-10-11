# String literals

> 來源：cppreference C 語言參考文件（離線轉換版）。

Constructs an unnamed object of specified character array type in-place, used when a character string needs to be embedded in source code.
就地構造指定字元陣列型別的匿名物件，用於需要把字串嵌入原始碼的場合。

### Syntax

|   |

| `**"**` s-char-sequence `**"**`  |   | (1)  |   |   |

|   |

| `**u8"**` s-char-sequence `**"**`  |   | (2)  |   | (since C11)  |

|   |

| `**u"**` s-char-sequence `**"**`  |   | (3)  |   | (since C11)  |

|   |

| `**U"**` s-char-sequence `**"**`  |   | (4)  |   | (since C11)  |

|   |

| `**L"**` s-char-sequence `**"**`  |   | (5)  |   |   |

|   |

where

| s-char-sequence  |   | -  |   | zero or more characters, each of which is either a multibyte character from the source character set (excluding (`**"**`), `**\**`, and newline), or character escape, hex escape, octal escape, or universal character name(since C99) as defined in escape sequences.  |

1) *character string literal*: The type of the literal is `char[N]`, where `N` is the size of the string in code units of the execution narrow encoding, including the null terminator. Each `char` element in the array is initialized from the next character in s-char-sequence using the execution character set.

2) *UTF-8 string literal*: The type of the literal is `char[N]`(until C23)`char8_t[N]`(since C23), where `N` is the size of the string in UTF-8 code units including the null terminator. Each `char`(until C23)`char8_t`(since C23) element in the array is initialized from the next multibyte character in s-char-sequence using UTF-8 encoding.

3) 16-bit wide string literal: The type of the literal is `char16_t[N]`, where `N` is the size of the string in code units of implementation-defined 16-bit encoding (typically UTF-16), including the null terminator. Each `char16_t` element in the array is initialized as if by executing mbrtoc16 in implementation-defined locale.

4) 32-bit wide string literal: The type of the literal is `char32_t[N]`, where `N` is the size of the string in code units of implementation-defined 32-bit encoding (typically UTF-32), including the null terminator. Each `char32_t` element in the array is initialized as if by executing mbrtoc32 in implementation-defined locale.
|   | (until C23) |

3) *UTF-16 string literal*: The type of the literal is `char16_t[N]`, where `N` is the size of the string in UTF-16 code units including the null terminator. Each `char16_t` element in the array is initialized from the next multibyte character in s-char-sequence using UTF-16 encoding.

4) *UTF-32 string literal*: The type of the literal is `char32_t[N]`, where `N` is the size of the string in UTF-32 code units including the null terminator. Each `char32_t` element in the array is initialized from the next multibyte character in s-char-sequence using UTF-32 encoding.
|   | (since C23) |

5) wide string literal: The type of the literal is `wchar_t[N]`, where `N` is the size of the string in code units of the execution wide encoding, including the null terminator. Each `wchar_t` element in the array is initialized as if by executing mbstowcs in implementation-defined locale.

### Explanation

First, at translation phase 6 (after macro expansion), the adjacent string literals (that is, string literals separated by whitespace only) are concatenated.
首先，在翻譯階段 6（宏展開之後），相鄰的字串字面量（即僅由空白字元分隔的字串字面量）被拼接起來。

Only two narrow or two wide string literals may be concatenated.
|   | (until C99) |

If one literal is unprefixed, the resulting string literal has the width/encoding specified by the prefixed literal.

```c
L"Δx = %" PRId16 // at phase 4, PRId16 expands to "d"  // at phase 6, L"Δx = %" and "d" form L"Δx = %d"
```
|   | (since C99) |

If the two string literals have different encoding prefixes, concatenation is implementation-defined, except that a UTF-8 string literal and a wide string literal cannot be concatenated.
|   | (since C11)
(until C23) |

If the two string literals have different encoding prefixes, concatenation is ill-formed.
|   | (since C23) |

Secondly, at translation phase 7, a terminating null character is added to each string literal, and then each literal initializes an unnamed array with static storage duration and length just enough to contain the contents of the string literal plus one for the null terminator.
其次，在翻譯階段 7，為每個字串字面量新增一個終止空字元，然後每個字面量初始化一個具有靜態儲存期的匿名陣列，其長度恰好足以容納該字串字面量的內容，再加上一個空終止符。

```c
char* p = "\x12" "3"; // creates a static char[3] array holding {'\x12', '3', '\0'}  // sets p to point to the first element of the array
```

String literals are **not modifiable** (and in fact may be placed in read-only memory such as `.rodata`). If a program attempts to modify the static array formed by a string literal, the behavior is undefined.
字串字面量是不可修改的（事實上可能被放置在只讀記憶體中，例如 .rodata）。如果程式試圖修改由字串字面量所形成的靜態陣列，則行為是未定義行為。

```c
char* p = "Hello"; p[1] = 'M'; // Undefined behavior char a[] = "Hello"; a[1] = 'M'; // OK: a is not a string literal
```

It is neither required nor forbidden for identical string literals to refer to the same location in memory. Moreover, overlapping string literals or string literals that are substrings of other string literals may be combined.
相同的字串字面量是否引用記憶體中的同一位置，標準既不要求也不禁止。此外，相互重疊的字串字面量，或是其他字串字面量之子串的字串字面量，可能會被合併。

```c
"def" == 3+"abcdef"; // may be 1 or 0, implementation-defined
```

### Notes

A string literal is not necessarily a string; if a string literal has embedded null characters, it represents an array which contains more than one string:
字串字面量不一定是字串；如果字串字面量中嵌入了空字元，它所表示的陣列包含多個字串：

```c
char* p = "abc\0def"; // strlen(p) == 3, but the array has size 8
```

If a valid hex digit follows a hex escape in a string literal, it would fail to compile as an invalid escape sequence, but string concatenation can be used as a workaround:
如果字串字面量中十六進位制轉義之後跟有一個有效的十六進位制數字，則會因為是無效的轉義序列而編譯失敗，但可以使用字串拼接作為變通方法：

```c
//char* p = "\xfff"; // error: hex escape sequence out of range char* p = "\xff""f"; // okay, the literal is char[3] holding {'\xff', 'f', '\0'}
```

String literals can be used to initialize arrays, and if the size of the array is one less the size of the string literal, the null terminator is ignored:
字串字面量可用於初始化陣列，如果陣列的大小比字串字面量的大小小一，則空終止符被忽略：

```c
char a1[] = "abc"; // a1 is char[4] holding {'a', 'b', 'c', '\0'} char a2[4] = "abc"; // a2 is char[4] holding {'a', 'b', 'c', '\0'} char a3[3] = "abc"; // a3 is char[3] holding {'a', 'b', 'c'}
```

The encoding of character string literals (1) and wide string literals (5) is implementation-defined. For example, gcc selects them with the commandline options `-fexec-charset` and `-fwide-exec-charset`.
字元字串字面量 (1) 和寬字串字面量 (5) 的編碼是由實現定義的。例如，gcc 使用命令列選項 - fexec - charset 和 - fwide - exec - charset 來選擇它們。
Although mixed wide string literal concatenation is allowed in C11, almost all compilers reject such concatenation (the only known exception is SDCC), and its usage experience is unknown. As a result, allowance of mixed wide string literal concatenation is removed in C23.
雖然 C11 允許混合寬字串字面量的拼接，但幾乎所有的編譯器都拒絕這種拼接（已知的唯一例外是 SDCC），其使用經驗尚不清楚。因此，C23 中移除了對混合寬字串字面量拼接的允許。

### Example

Run this code

```c
#include <inttypes.h> #include <locale.h> #include <stddef.h> #include <stdio.h> #include <stdlib.h> #include <uchar.h> int main(void) {  char s1[] = "a猫🍌"; // or "a\u732B\U0001F34C" #if __STDC_VERSION__ >= 202311L  char8_t #else  char #endif  s2[] = u8"a猫🍌";  char16_t s3[] = u"a猫🍌";  char32_t s4[] = U"a猫🍌";  wchar_t s5[] = L"a猫🍌";    setlocale(LC_ALL, "en_US.utf8");  printf(" \"%s\" is a char[%zu] holding { ", s1, sizeof s1 / sizeof *s1);  for(size_t n = 0; n < sizeof s1 / sizeof *s1; ++n)  printf("0x%02X ", +(unsigned char)s1[n]);  puts("}");  printf( #if __STDC_VERSION__ >= 202311L  "u8\"%s\" is a char8_t[%zu] holding { " #else  "u8\"%s\" is a char[%zu] holding { " #endif , s2, sizeof s2 / sizeof *s2);  for(size_t n = 0; n < sizeof s2 / sizeof *s2; ++n) #if __STDC_VERSION__ >= 202311L  printf("0x%02X ", s2[n]); #else  printf("0x%02X ", +(unsigned char)s2[n]); #endif  puts("}");  printf(" u\"a猫🍌\" is a char16_t[%zu] holding { ", sizeof s3 / sizeof *s3);  for(size_t n = 0; n < sizeof s3 / sizeof *s3; ++n)  printf("0x%04" PRIXLEAST16" ", s3[n]);  puts("}");  printf(" U\"a猫🍌\" is a char32_t[%zu] holding { ", sizeof s4 / sizeof *s4);  for(size_t n = 0; n < sizeof s4 / sizeof *s4; ++n)  printf("0x%08" PRIXLEAST32" ", s4[n]);  puts("}");  printf(" L\"%ls\" is a wchar_t[%zu] holding { ", s5, sizeof s5 / sizeof *s5);  for(size_t n = 0; n < sizeof s5 / sizeof *s5; ++n)  printf("0x%08X ", (unsigned)s5[n]);  puts("}"); }
```

Possible output:
可能的輸出：

```c
"a猫🍌" is a char[9] holding { 0x61 0xE7 0x8C 0xAB 0xF0 0x9F 0x8D 0x8C 0x00 } u8"a猫🍌" is a char[9] holding { 0x61 0xE7 0x8C 0xAB 0xF0 0x9F 0x8D 0x8C 0x00 } u"a猫🍌" is a char16_t[5] holding { 0x0061 0x732B 0xD83C 0xDF4C 0x0000 } U"a猫🍌" is a char32_t[4] holding { 0x00000061 0x0000732B 0x0001F34C 0x00000000 } L"a猫🍌" is a wchar_t[4] holding { 0x00000061 0x0000732B 0x0001F34C 0x00000000 }
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.4.5 String literals (p: TBD)
6.4.5 字串字面量（p: TBD）
6.4.5 字串字面量（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.4.5 String literals (p: 50-52)
6.4.5 字串字面量（p: 50-52）
6.4.5 字串字面量（p: 50-52）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.4.5 String literals (p: 70-72)
6.4.5 字串字面量（p: 70-72）
6.4.5 字串字面量（p: 70-72）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.4.5 String literals (p: 62-63)
6.4.5 字串字面量（p: 62-63）
6.4.5 字串字面量（p: 62-63）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.1.4 String literals
3.1.4 字串字面量
3.1.4 字串字面量

### See also

C++ documentation for string literal

---
來源頁路徑：`en.cppreference.com/c/language/string_literal.html`
