# 以空字元結尾的位元組字串

> 來源：cppreference C 語言參考文件（離線轉換版）。

A null-terminated byte string (NTBS) is a sequence of nonzero bytes followed by a byte with value zero (the terminating null character). Each byte in a byte string encodes one character of some character set. For example, the character array `{'\x63','\x61','\x74','\0'}` is an NTBS holding the string `"cat"` in ASCII encoding.
以空字元結尾的位元組字串（NTBS）由一串非零位元組和最後的零值位元組組成；最後這個零值位元組就是結尾空字元。每個位元組代表某個字元集中的一個字元。例如，字元陣列 `{'\x63','\x61','\x74','\0'}` 以 ASCII 編碼儲存字串 `"cat"`，因此是 NTBS。

### Functions

#####  Character classification

Defined in header `<ctype.h>`

isalnum
|   | 檢查字元是否為英文字母或數字
(function)   |

isalpha
|   | 檢查字元是否為字母
(function)   |

islower
|   | 檢查字元是否為小寫字母
(function)   |

isupper
|   | 檢查字元是否為大寫字母
(function)   |

isdigit
|   | 檢查字元是否為十進位數字
(function)   |

isxdigit
|   | 檢查字元是否為十六進位數字
(function)   |

iscntrl
|   | 檢查字元是否為控制字元
(function)   |

isgraph
|   | 檢查字元是否為可見字元（空格除外）
(function)   |

isspace
|   | 檢查字元是否為空白字元
(function)   |

isblank
(C99)
|   | 檢查字元是否為空格或水平定位字元
(function)   |

isprint
|   | 檢查字元是否為可列印字元
(function)   |

ispunct
|   | 檢查字元是否為標點符號
(function)   |

#####  Character manipulation

tolower
|   | 將字元轉成小寫
(function)   |

toupper
|   | 將字元轉成大寫
(function)   |

Note: additional functions whose names begin with either `**to**` or `**is**`, followed by a lowercase letter, may be added to the header <ctype.h> in future and should not be defined by programs that include that header.
注意：未來可能會在 `<ctype.h>` 新增名稱以 `to` 或 `is` 開頭、接著是小寫字母的函式。因此，包含此標頭檔的程式不要自行定義符合這種命名形式的函式。

| ASCII values  |   | characters  |   |
iscntrl
iswcntrl
|   |
isprint
iswprint
|   |
isspace
iswspace
|   |
isblank
iswblank
|   |
isgraph
iswgraph
|   |
ispunct
iswpunct
|   |
isalnum
iswalnum
|   |
isalpha
iswalpha
|   |
isupper
iswupper
|   |
islower
iswlower
|   |
isdigit
iswdigit
|   |
isxdigit
iswxdigit

| decimal  |   | hexadecimal  |   | octal  |

| 0–8  |   | `\x0`–`\x8`  |   | `\0`–`\10`  |   | control codes (`NUL`, etc.)  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |

| 9  |   | `\x9`  |   | `\11`  |   | tab (`\t`)  |   | **`≠0`**  |   | **`0`**  |   | **`≠0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |

| 10–13  |   | `\xA`–`\xD`  |   | `\12`–`\15`  |   | whitespaces (`\n`, `\v`, `\f`, `\r`)  |   | **`≠0`**  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |

| 14–31  |   | `\xE`–`\x1F`  |   | `\16`–`\37`  |   | control codes  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |

| 32  |   | `\x20`  |   | `\40`  |   | space  |   | **`0`**  |   | **`≠0`**  |   | **`≠0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |

| 33–47  |   | `\x21`–`\x2F`  |   | `\41`–`\57`  |   | `!"#$%&'()*+,-./`  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`≠0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |

| 48–57  |   | `\x30`–`\x39`  |   | `\60`–`\71`  |   | `0123456789`  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`≠0`**  |   | **`≠0`**  |

| 58–64  |   | `\x3A`–`\x40`  |   | `\72`–`\100`  |   | `:;<=>?@`  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`≠0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |

| 65–70  |   | `\x41`–`\x46`  |   | `\101`–`\106`  |   | `ABCDEF`  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`≠0`**  |   | **`≠0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`≠0`**  |

| 71–90  |   | `\x47`–`\x5A`  |   | `\107`–`\132`  |   | `GHIJKLMNOP`
`QRSTUVWXYZ`  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`≠0`**  |   | **`≠0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |

| 91–96  |   | `\x5B`–`\x60`  |   | `\133`–`\140`  |   | `[\]^_``  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`≠0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |

| 97–102  |   | `\x61`–`\x66`  |   | `\141`–`\146`  |   | `abcdef`  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`≠0`**  |   | **`≠0`**  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`≠0`**  |

| 103–122  |   | `\x67`–`\x7A`  |   | `\147`–`\172`  |   | `ghijklmnop`
`qrstuvwxyz`  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`≠0`**  |   | **`≠0`**  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |

| 123–126  |   | `\x7B`–`\x7E`  |   | `\173`–`\176`  |   | `{|}~`  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`≠0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |

| 127  |   | `\x7F`  |   | `\177`  |   | backspace character (`DEL`)  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |

#####  Conversions to and from numeric formats

Defined in header `<stdlib.h>`

atof
|   | 將位元組字串轉成浮點數
(function)   |

atoiatolatoll
(C99)
|   | 將位元組字串轉成整數
(function)   |

strtolstrtoll
(C99)
|   | 將位元組字串轉成整數
(function)   |

strtoul strtoull
(C99)
|   | 將位元組字串轉成無號整數
(function)   |

strtofstrtodstrtold
(C99)(C99)
|   | 將位元組字串轉成浮點數
(function)   |

strfromfstrfromdstrfroml
(C23)(C23)(C23)
|   | 將浮點數格式化為位元組字串
(function)   |

Defined in header `<inttypes.h>`

strtoimaxstrtoumax
(C99)(C99)
|   | 將位元組字串轉成 `intmax_t` 或 `uintmax_t`
(function)   |

#####  String manipulation

Defined in header `<string.h>`

strcpystrcpy_s
(C11)
|   | 將字串複製到另一個字串
(function)   |

strncpystrncpy_s
(C11)
|   | 將指定數量的字元從一個字串複製到另一個字串
(function)   |

strcatstrcat_s
(C11)
|   | 將一個字串接到另一個字串末尾
(function)   |

strncatstrncat_s
(C11)
|   | 將來源字串指定數量的字元接到目標字串末尾
(function)   |

strxfrm
|   | 轉換字串，讓 `strcmp` 的比較結果與 `strcoll` 相同
(function)   |

strdup
(C23)
|   | 配置空間並複製字串
(function)   |

strndup
(C23)
|   | 配置空間並複製字串的指定長度
(function)   |

#####  String examination

Defined in header `<string.h>`

strlenstrnlen_s
(C11)
|   | 傳回字串長度（不含結尾空字元）
(function)   |

strcmp
|   | 比較兩個字串
(function)   |

strncmp
|   | 比較兩個字串的前指定數量字元
(function)   |

strcoll
|   | 依目前的地區設定比較兩個字串
(function)   |

strchr
|   | 尋找字元第一次出現的位置
(function)   |

strrchr
|   | 尋找字元最後一次出現的位置
(function)   |

strspn
|   | 傳回字串開頭連續符合條件的字元數
of only the characters found in another byte string
(function)   |

strcspn
|   | returns the length of the maximum initial segment that consists
of only the characters not found in another byte string
(function)   |

strpbrk
|   | 尋找來源字串中任一字元在目標字串第一次出現的位置
(function)   |

strstr
|   | 尋找子字串第一次出現的位置
(function)   |

strtokstrtok_s
(C11)
|   | 尋找位元組字串中的下一個 token（片段）
(function)   |

#####  Character array manipulation

Defined in header `<string.h>`

memchr
|   | 在記憶體區塊中尋找指定字元第一次出現的位置
(function)   |

memcmp
|   | 比較兩個記憶體區塊
(function)   |

memsetmemset_explicitmemset_s
(C23)(C11)
|   | 用指定字元填滿記憶體區塊
(function)   |

memcpymemcpy_s
(C11)
|   | 將一個記憶體區塊複製到另一個區塊
(function)   |

memmovememmove_s
(C11)
|   | 將一個記憶體區塊移到另一個區塊，可處理區域重疊
(function)   |

memccpy
(C23)
|   | 將資料複製到另一個區塊，遇到指定分隔字元後停止
(function)   |

#####  Miscellaneous

Defined in header `<string.h>`

strerrorstrerror_sstrerrorlen_s
(C11)(C11)
|   | 將錯誤碼轉成文字說明
(function)   |

### References

| Extended content  |

- C23 standard (ISO/IEC 9899:2024):

- 7.4 Character handling <ctype.h> (p: TBD)

- 7.8 Format conversion of integer types <inttypes.h> (p: TBD)

- 7.22 General utilities <stdlib.h> (p: TBD)

- 7.24 String handling <string.h> (p: TBD)

- 7.31.2 Character handling <ctype.h> (p: TBD)

- 7.31.5 Format conversion of integer types <inttypes.h> (p: TBD)

- 7.31.12 General utilities <stdlib.h> (p: TBD)

- 7.31.13 String handling <string.h> (p: TBD)

- K.3.6 General utilities <stdlib.h> (p: TBD)

- K.3.7 String handling <string.h> (p: TBD)

- C17 standard (ISO/IEC 9899:2018):

- 7.4 Character handling <ctype.h> (p: TBD)

- 7.8 Format conversion of integer types <inttypes.h> (p: TBD)

- 7.22 General utilities <stdlib.h> (p: TBD)

- 7.24 String handling <string.h> (p: TBD)

- 7.31.2 Character handling <ctype.h> (p: TBD)

- 7.31.5 Format conversion of integer types <inttypes.h> (p: TBD)

- 7.31.12 General utilities <stdlib.h> (p: TBD)

- 7.31.13 String handling <string.h> (p: TBD)

- K.3.6 General utilities <stdlib.h> (p: TBD)

- K.3.7 String handling <string.h> (p: TBD)

- C11 standard (ISO/IEC 9899:2011):

- 7.4 Character handling <ctype.h> (p: 200-204)

- 7.8 Format conversion of integer types <inttypes.h> (p: 217-220)

- 7.22 General utilities <stdlib.h> (p: 340-360)

- 7.24 String handling <string.h> (p: 362-372)

- 7.31.2 Character handling <ctype.h> (p: 455)

- 7.31.5 Format conversion of integer types <inttypes.h> (p: 455)

- 7.31.12 General utilities <stdlib.h> (p: 456)

- 7.31.13 String handling <string.h> (p: 456)

- K.3.6 General utilities <stdlib.h> (p: 604-613)

- K.3.7 String handling <string.h> (p: 614-623)

- C99 standard (ISO/IEC 9899:1999):

- 7.4 Character handling <ctype.h> (p: 181-185)

- 7.8 Format conversion of integer types <inttypes.h> (p: 198-201)

- 7.20 General utilities <stdlib.h> (p: 306-324)

- 7.21 String handling <string.h> (p: 325-334)

- 7.26.2 Character handling <ctype.h> (p: 401)

- 7.26.4 Format conversion of integer types <inttypes.h> (p: 401)

- 7.26.10 General utilities <stdlib.h> (p: 402)

- 7.26.11 String handling <string.h> (p: 402)

- C89/C90 standard (ISO/IEC 9899:1990):

- 4.3 CHARACTER HANDLING <ctype.h>

- 4.10 GENERAL UTILITIES <stdlib.h>

- 4.11 STRING HANDLING <string.h>

- 4.13.2 Character handling <ctype.h>

- 4.13.7 General utilities <stdlib.h>

- 4.13.8 String handling <string.h>

### See also

C++ documentation for `Null`-terminated byte strings

---
來源頁路徑：`en.cppreference.com/c/string/byte.html`
