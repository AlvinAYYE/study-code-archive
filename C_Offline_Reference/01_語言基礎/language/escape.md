# Escape sequences

> 來源：cppreference C 語言參考文件（離線轉換版）。

Escape sequences are used to represent certain special characters within string literals and character constants.
轉義序列用於在字串字面量和字元常量 中表示某些特殊字元。
The following escape sequences are available. ISO C requires a diagnostic if the backslash is followed by any character not listed here:
以下轉義序列可用。如果反斜槓後跟此處未列出的任何字元，ISO C 要求發出診斷：

| Escape
sequence  |   | Description  |   | Representation  |

| Simple escape sequences  |

| `**\'**`  |   | single quote  |   | byte `0x27` in ASCII encoding  |

| `**\"**`  |   | double quote  |   | byte `0x22` in ASCII encoding  |

| `**\?**`  |   | question mark  |   | byte `0x3f` in ASCII encoding  |

| `**\\**`  |   | backslash  |   | byte `0x5c` in ASCII encoding  |

| `**\a**`  |   | audible bell  |   | byte `0x07` in ASCII encoding  |

| `**\b**`  |   | backspace  |   | byte `0x08` in ASCII encoding  |

| `**\f**`  |   | form feed - new page  |   | byte `0x0c` in ASCII encoding  |

| `**\n**`  |   | line feed - new line  |   | byte `0x0a` in ASCII encoding  |

| `**\r**`  |   | carriage return  |   | byte `0x0d` in ASCII encoding  |

| `**\t**`  |   | horizontal tab  |   | byte `0x09` in ASCII encoding  |

| `**\v**`  |   | vertical tab  |   | byte `0x0b` in ASCII encoding  |

| Numeric escape sequences  |

| `**\*nnn***`  |   | arbitrary octal value  |   | code unit `*nnn*`  |

| `**\x*n...***`  |   | arbitrary hexadecimal value  |   | code unit `*n...*` (arbitrary number of hexadecimal digits)  |

| Universal character names  |

| `**\u*nnnn***` (since C99)  |   |  Unicode value in allowed range;
may result in several code units  |   | code point `U+*nnnn*`  |

| `**\U*nnnnnnnn***` (since C99)  |   |  Unicode value in allowed range;
may result in several code units  |   | code point `U+*nnnnnnnn*`  |

### Range of universal character names

If a universal character name corresponds to a code point that is not `0x24` (`'$'`), `0x40` (`'@'`), nor `0x60` (`'`'`) and less than `0xA0`, or a surrogate code point (the range `0xD800-0xDFFF`, inclusive), or greater than `0x10FFFF`, i.e. not a Unicode code point(since C23), the program is ill-formed. In other words, members of basic source character set and control characters (in ranges `0x0-0x1F` and `0x7F-0x9F`) cannot be expressed in universal character names.
|   | (since C99) |

### Notes

`\0` is the most commonly used octal escape sequence, because it represents the terminating null character in null-terminated strings.
\ 0 是最常用的八進位制轉義序列，因為它表示以空字元結尾的字串中的終止空字元。
The new-line character `\n` has special meaning when used in text mode I/O: it is converted to the OS-specific newline byte or byte sequence.
換行字元 \ n 在文字模式 I/O 中具有特殊含義：它會被轉換為特定於作業系統平臺的換行位元組或位元組序列。
Octal escape sequences have a length limit of three octal digits but terminate at the first character that is not a valid octal digit if encountered sooner.
八進位制轉義序列的長度限制為三個八進位制數字，但如果更早遇到第一個不是有效八進位制數字的字元，則會在該處終止。
Hexadecimal escape sequences have no length limit and terminate at the first character that is not a valid hexadecimal digit. If the value represented by a single hexadecimal escape sequence does not fit the range of values represented by the character type used in this string literal or character constant (`char`, `char8_t`(since C23), `char16_t`, `char32_t`(since C11), or `wchar_t`), the result is unspecified.
十六進位制轉義序列沒有長度限制，並在遇到第一個不是有效十六進位制數字的字元處終止。如果單個十六進位制轉義序列表示的值不適合該字串字面量或字元常量中所用字元型別（char 、char8_t（C23 起）、char16_t 、char32_t（C11 起）或 wchar_t ）所表示的值範圍，則結果是未指定的。

A universal character name in a narrow string literal or a 16-bit string literal(since C11) may map to more than one code unit, e.g. `\U0001f34c` is 4 `char` code units in UTF-8 (`\xF0\x9F\x8D\x8C`) and 2 `char16_t` code units in UTF-16 (`\xD83C\xDF4C`)(since C11).
|   | (since C99) |

A universal character name corresponding to a code pointer greater than `0x10FFFF` (which is undefined in ISO/ISC 10646) can be used in character constants and string literals. Such usage is not allowed in C++20.
|   | (since C99)
(until C23) |

The question mark escape sequence `\?` is used to prevent trigraphs from being interpreted inside string literals: a string such as `"??/"` is compiled as `"\"`, but if the second question mark is escaped, as in `"?\?/"`, it becomes `"??/"`
|   | (until C23) |

### Example

Run this code

```c
#include <stdio.h> int main(void) {  printf("This\nis\na\ntest\n\nShe said, \"How are you?\"\n"); }
```

Output:

```c
This is a test She said, "How are you?"
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 5.2.2 Character display semantics (p: 18-19)
5.2.2 字元顯示語意（p: 18-19）
5.2.2 字元顯示語意（p: 18-19）

- 6.4.3 Universal Character names (p: 44)
6.4.3 通用字元名（p: 44）
6.4.3 通用字元名（p: 44）

- 6.4.4.4 Character constants (p: 48-50)
6.4.4.4 字元常量（第 48-50 頁）
6.4.4.4 字元常量（第 48-50 頁）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 5.2.2 Character display semantics (p: 24-25)
5.2.2 字元顯示語意（p: 24-25）
5.2.2 字元顯示語意（p: 24-25）

- 6.4.3 Universal Character names (p: 61)
6.4.3 通用字元名（p: 61）
6.4.3 通用字元名（p: 61）

- 6.4.4.4 Character constants (p: 67-70)
6.4.4.4 字元常量（第 67-70 頁）
6.4.4.4 字元常量（第 67-70 頁）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 5.2.2 Character display semantics (p: 19-20)
5.2.2 字元顯示語意（p: 19-20）
5.2.2 字元顯示語意（p: 19-20）

- 6.4.3 Universal Character names (p: 53)
6.4.3 通用字元名（p: 53）
6.4.3 通用字元名（p: 53）

- 6.4.4.4 Character constants (p: 59-61)
6.4.4.4 字元常量（第 59-61 頁）
6.4.4.4 字元常量（第 59-61 頁）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 2.2.2 Character display semantics
2.2.2 字元顯示語意
2.2.2 字元顯示語意

- 3.1.3.4 Character constants
3.1.3.4 字元常量
3.1.3.4 字元常量

### See also

- ASCII chart

C++ documentation for Escape sequences

---
來源頁路徑：`en.cppreference.com/c/language/escape.html`
