# 以空字元結尾的寬字串

> 來源：cppreference C 語言參考文件（離線轉換版）。

A null-terminated wide string is a sequence of valid wide characters, ending with a null-character.
以空字元結尾的寬字串，是由有效寬字元組成、並以空寬字元結尾的序列。它和一般以 `char` 儲存的字串不同，元素型別是 `wchar_t`。

### Functions

#####  Character classification

Defined in header `<wctype.h>`

iswalnum
(C95)
|   | 檢查寬字元是否為字母或數字
(function)   |

iswalpha
(C95)
|   | 檢查寬字元是否為字母
(function)   |

iswlower
(C95)
|   | 檢查寬字元是否為小寫字母
(function)   |

iswupper
(C95)
|   | 檢查寬字元是否為大寫字母
(function)   |

iswdigit
(C95)
|   | 檢查寬字元是否為十進位數字
(function)   |

iswxdigit
(C95)
|   | 檢查寬字元是否為十六進位數字
(function)   |

iswcntrl
(C95)
|   | 檢查寬字元是否為控制字元
(function)   |

iswgraph
(C95)
|   | 檢查寬字元是否為可見字元（空格除外）
(function)   |

iswspace
(C95)
|   | 檢查寬字元是否為空白字元
(function)   |

iswblank
(C99)
|   | 檢查寬字元是否為空格或水平定位字元
(function)   |

iswprint
(C95)
|   | 檢查寬字元是否可列印
(function)   |

iswpunct
(C95)
|   | 檢查寬字元是否為標點符號
(function)   |

iswctype
(C95)
|   | 依指定的 `LC_CTYPE` 分類類別判斷寬字元
(function)   |

wctype
(C95)
|   | 在目前 C 地區設定中查詢字元分類類別
(function)   |

#####  Character manipulation

Defined in header `<wctype.h>`

towlower
(C95)
|   | 將寬字元轉成小寫
(function)   |

towupper
(C95)
|   | 將寬字元轉成大寫
(function)   |

towctrans
(C95)
|   | 依指定的 `LC_CTYPE` 對映類別轉換寬字元
(function)   |

wctrans
(C95)
|   | 在目前 C 地區設定中查詢字元對映類別
(function)   |

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

#####  Conversions to numeric formats

Defined in header `<wchar.h>`

wcstolwcstoll
(C95)(C99)
|   | 將寬字串轉成整數
(function)   |

wcstoulwcstoull
(C95)(C99)
|   | 將寬字串轉成無號整數
(function)   |

wcstofwcstodwcstold
(C99)(C95)(C99)
|   | 將寬字串轉成浮點數
(function)   |

Defined in header `<inttypes.h>`

wcstoimaxwcstoumax
(C99)(C99)
|   | 將寬字串轉成 `intmax_t` 或 `uintmax_t`
(function)   |

#####  String manipulation

Defined in header `<wchar.h>`

wcscpywcscpy_s
(C95)(C11)
|   | 將寬字串複製到另一個寬字串
(function)   |

wcsncpywcsncpy_s
(C95)(C11)
|   | 將指定數量的寬字元複製到另一個寬字串
(function)   |

wcscatwcscat_s
(C95)(C11)
|   | 將一個寬字串接到另一個寬字串末尾
(function)   |

wcsncatwcsncat_s
(C95)(C11)
|   | 將來源寬字串中指定數量的字元接到目標寬字串末尾
(function)   |

wcsxfrm
(C95)
|   | 轉換寬字串，讓 `wcscmp` 的比較結果與 `wcscoll` 相同
(function)   |

#####  String examination

Defined in header `<wchar.h>`

wcslenwcsnlen_s
(C95)(C11)
|   | 傳回寬字串長度（不含結尾空字元）
(function)   |

wcscmp
(C95)
|   | 比較兩個寬字串
(function)   |

wcsncmp
(C95)
|   | 比較兩個寬字串的前指定數量字元
(function)   |

wcscoll
(C95)
|   | 依目前的地區設定比較兩個寬字串
(function)   |

wcschr
(C95)
|   | 尋找寬字元在寬字串中第一次出現的位置
(function)   |

wcsrchr
(C95)
|   | 尋找寬字元在寬字串中最後一次出現的位置
(function)   |

wcsspn
(C95)
|   | 傳回寬字串開頭連續符合條件的寬字元數
of only the wide characters found in another wide string
(function)   |

wcscspn
(C95)
|   | returns the length of the maximum initial segment that consists
of only the wide chars *not* found in another wide string
(function)   |

wcspbrk
(C95)
|   | 尋找來源寬字串中任一字元在目標寬字串第一次出現的位置
(function)   |

wcsstr
(C95)
|   | 尋找子寬字串第一次出現的位置
(function)   |

wcstokwcstok_s
(C95)(C11)
|   | 尋找寬字串中的下一個 token（片段）
(function)   |

#####  Wide character array manipulation

Defined in header `<wchar.h>`

wmemcpywmemcpy_s
(C95)(C11)
|   | 在兩個不重疊的陣列之間複製指定數量的寬字元
(function)   |

wmemmovewmemmove_s
(C95)(C11)
|   | 在兩個可能重疊的陣列之間移動指定數量的寬字元
(function)   |

wmemcmp
(C95)
|   | 比較兩個陣列中的指定數量寬字元
(function)   |

wmemchr
(C95)
|   | 在寬字元陣列中尋找指定寬字元第一次出現的位置
(function)   |

wmemset
(C95)
|   | 將指定寬字元填入寬字元陣列的每個位置
(function)   |

### Types

Defined in header `<stddef.h>`

Defined in header `<stdlib.h>`

Defined in header `<wchar.h>`

wchar_t
|   | 可表示任何有效寬字元的整數型別
(typedef)  |

Defined in header `<wchar.h>`

Defined in header `<wctype.h>`

wint_t
(C95)
|   | 可表示任何有效寬字元及至少一個額外值的整數型別
(typedef)  |

Defined in header `<wctype.h>`

wctrans_t
(C95)
|   | 保存地區設定字元對映資訊的純量型別
(typedef)  |

wctype_t
(C95)
|   | 保存地區設定字元分類資訊的純量型別
(typedef)  |

### Macros

Defined in header `<wchar.h>`

Defined in header `<wctype.h>`

WEOF
(C95)
|   | `wint_t` 型別的非字元值，用來表示錯誤
(macro constant)  |

Defined in header `<wchar.h>`

Defined in header `<stdint.h>`

WCHAR_MIN
(C95)
|   | `wchar_t` 可表示的最小有效值
(macro constant)  |

WCHAR_MAX
(C95)
|   | `wchar_t` 可表示的最大有效值
(macro constant)  |

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.19 Common definitions <stddef.h> (p: TBD)
7.19 通用定義 <stddef.h>（頁碼：待定）
7.19 通用定義 <stddef.h>（頁碼：待定）

- 7.29 Extended multibyte and wide character utilities <wchar.h> (p: TBD)
7.29 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：待定）
7.29 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：待定）

- 7.30 Wide character classification and mapping utilities <wctype.h> (p: TBD)
7.30 寬字元分類和對映工具 <wctype.h> （頁碼：待定）
7.30 寬字元分類和對映工具 <wctype.h> （頁碼：待定）

- 7.31.16 Extended multibyte and wide character utilities <wchar.h> (p: TBD)
7.31.16 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：待定）
7.31.16 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：待定）

- 7.31.17 Wide character classification and mapping utilities <wctype.h> (p: TBD)
7.31.17 寬字元分類和對映工具 <wctype.h> （頁碼：待定）
7.31.17 寬字元分類和對映工具 <wctype.h> （頁碼：待定）

- K.3.3 Common definitions <stddef.h> (p: TBD)
K.3.3 通用定義 <stddef.h> （頁碼：待定）
K.3.3 通用定義 <stddef.h> （頁碼：待定）

- K.3.9 Extended multibyte and wide character utilities <wchar.h> (p: TBD)
K.3.9 擴充套件多位元組和寬字元工具 <wchar.h> （頁碼：待定）
K.3.9 擴充套件多位元組和寬字元工具 <wchar.h> （頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.19 Common definitions <stddef.h> (p: TBD)
7.19 通用定義 <stddef.h>（頁碼：待定）
7.19 通用定義 <stddef.h>（頁碼：待定）

- 7.29 Extended multibyte and wide character utilities <wchar.h> (p: TBD)
7.29 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：待定）
7.29 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：待定）

- 7.30 Wide character classification and mapping utilities <wctype.h> (p: TBD)
7.30 寬字元分類和對映工具 <wctype.h> （頁碼：待定）
7.30 寬字元分類和對映工具 <wctype.h> （頁碼：待定）

- 7.31.16 Extended multibyte and wide character utilities <wchar.h> (p: TBD)
7.31.16 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：待定）
7.31.16 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：待定）

- 7.31.17 Wide character classification and mapping utilities <wctype.h> (p: TBD)
7.31.17 寬字元分類和對映工具 <wctype.h> （頁碼：待定）
7.31.17 寬字元分類和對映工具 <wctype.h> （頁碼：待定）

- K.3.3 Common definitions <stddef.h> (p: TBD)
K.3.3 通用定義 <stddef.h> （頁碼：待定）
K.3.3 通用定義 <stddef.h> （頁碼：待定）

- K.3.9 Extended multibyte and wide character utilities <wchar.h> (p: TBD)
K.3.9 擴充套件多位元組和寬字元工具 <wchar.h> （頁碼：待定）
K.3.9 擴充套件多位元組和寬字元工具 <wchar.h> （頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.19 Common definitions <stddef.h> (p: 288)
7.19 通用定義 <stddef.h>（頁碼：288）
7.19 通用定義 <stddef.h>（頁碼：288）

- 7.29 Extended multibyte and wide character utilities <wchar.h> (p: 402-446)
7.29 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：402-446）
7.29 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：402-446）

- 7.30 Wide character classification and mapping utilities <wctype.h> (p: 447-454)
7.30 寬字元分類和對映工具 <wctype.h> （頁碼：447-454）
7.30 寬字元分類和對映工具 <wctype.h> （頁碼：447-454）

- 7.31.16 Extended multibyte and wide character utilities <wchar.h> (p: 456)
7.31.16 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：456）
7.31.16 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：456）

- 7.31.17 Wide character classification and mapping utilities <wctype.h> (p: 457)
7.31.17 寬字元分類和對映工具 <wctype.h> （頁碼：457）
7.31.17 寬字元分類和對映工具 <wctype.h> （頁碼：457）

- K.3.3 Common definitions <stddef.h> (p: 585)
K.3.3 通用定義 <stddef.h> （頁碼：585）
K.3.3 通用定義 <stddef.h> （頁碼：585）

- K.3.9 Extended multibyte and wide character utilities <wchar.h> (p: 627-651)
K.3.9 擴充套件多位元組和寬字元工具 <wchar.h> （頁碼：627-651）
K.3.9 擴充套件多位元組和寬字元工具 <wchar.h> （頁碼：627-651）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.17 Common definitions <stddef.h> (p: 254)
7.17 通用定義 <stddef.h> （頁碼：254）
7.17 通用定義 <stddef.h> （頁碼：254）

- 7.24 Extended multibyte and wide character utilities <wchar.h> (p: 348-392)
7.24 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：348-392）
7.24 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：348-392）

- 7.25 Wide character classification and mapping utilities <wctype.h> (p: 393-400)
7.25 寬字元分類和對映工具 <wctype.h> （頁碼：393-400）
7.25 寬字元分類和對映工具 <wctype.h> （頁碼：393-400）

- 7.26.12 Extended multibyte and wide character utilities <wchar.h> (p: 402)
7.26.12 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：402）
7.26.12 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：402）

- 7.26.13 Wide character classification and mapping utilities <wctype.h> (p: 402)
7.26.13 寬字元分類和對映工具 <wctype.h> （頁碼：402）
7.26.13 寬字元分類和對映工具 <wctype.h> （頁碼：402）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.1.5 Common definitions <stddef.h>
4.1.5 通用定義 <stddef.h>
4.1.5 通用定義 <stddef.h>

### See also

C++ documentation for `Null`-terminated wide strings

---
來源頁路徑：`en.cppreference.com/c/string/wide.html`
