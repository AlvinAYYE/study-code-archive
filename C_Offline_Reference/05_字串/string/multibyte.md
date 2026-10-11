# 以空字元結尾的多位元組字串

> 來源：cppreference C 語言參考文件（離線轉換版）。

A null-terminated multibyte string (NTMBS), or "multibyte string", is a sequence of nonzero bytes followed by a byte with value zero (the terminating null character).
以空字元結尾的多位元組字串（NTMBS）由一串非零位元組和最後的零值位元組組成；最後這個零值位元組就是結尾空字元。
Each character stored in the string may occupy more than one byte. The encoding used to represent characters in a multibyte character string is locale-specific: it may be UTF-8, GB18030, EUC-JP, Shift-JIS, etc. For example, the char array `{'\xe4','\xbd','\xa0','\xe5','\xa5','\xbd','\0'}` is an NTMBS holding the string `"你好"` in UTF-8 multibyte encoding: the first three bytes encode the character 你, the next three bytes encode the character 好. The same string encoded in GB18030 is the char array `{'\xc4', '\xe3', '\xba', '\xc3', '\0'}`, where each of the two characters is encoded as a two-byte sequence.
字串中的一個字元可能佔用多個位元組。使用哪種編碼由目前的地區設定決定，例如 UTF-8、GB18030、EUC-JP 或 Shift-JIS。以 UTF-8 為例，`"你好"` 的「你」和「好」各用三個位元組表示；在 GB18030 中，這兩個字各用兩個位元組表示。這些編碼方式不同，但都能用 `char` 陣列儲存成多位元組字串。
In some multibyte encodings, any given multibyte character sequence may represent different characters depending on the previous byte sequences, known as "shift sequences". Such encodings are known as state-dependent: knowledge of the current shift state is required to interpret each character. An NTMBS is only valid if it begins and ends in the initial shift state: if a shift sequence was used, the corresponding unshift sequence has to be present before the terminating null character. Examples of such encodings are BOCU-1 and SCSU.
某些編碼會使用「移位序列」切換解讀方式，因此同一組位元組可能因前文不同而代表不同字元。這種編碼稱為有狀態編碼，解讀字元時必須知道目前狀態。有效的 NTMBS 必須從初始狀態開始，並在結尾空字元前切回初始狀態；例如 BOCU-1 和 SCSU 就屬於這類編碼。
A multibyte character string is layout-compatible with null-terminated byte string (NTBS), that is, can be stored, copied, and examined using the same facilities, except for calculating the number of characters. If the correct locale is in effect, I/O functions also handle multibyte strings. Multibyte strings can be converted to and from wide strings using the following locale-dependent conversion functions:
多位元組字串和以空字元結尾的位元組字串（NTBS）在記憶體排列方式相同，因此可以使用相同函式儲存、複製和檢查；但計算字元數時不能把位元組數當成字元數。I/O 函式會依目前的地區設定處理多位元組字串。以下函式可在多位元組字串與寬字串之間轉換：

### Functions

#####  Multibyte/wide character conversions

Defined in header `<stdlib.h>`

mblen
|   | 傳回下一個多位元組字元所佔的位元組數
(function)   |

mbtowc
|   | 將下一個多位元組字元轉成寬字元
(function)   |

wctombwctomb_s
(C11)
|   | 將寬字元轉成多位元組表示法
(function)   |

mbstowcsmbstowcs_s
(C11)
|   | 將多位元組字串轉成寬字串
(function)   |

wcstombswcstombs_s
(C11)
|   | 將寬字串轉成多位元組字串
(function)   |

Defined in header `<wchar.h>`

mbsinit
(C95)
|   | 檢查 `mbstate_t` 物件是否處於初始轉換狀態
(function)   |

btowc
(C95)
|   | 若可行，將單位元組字元轉成寬字元
(function)   |

wctob
(C95)
|   | 若可行，將寬字元轉成單位元組字元
(function)   |

mbrlen
(C95)
|   | 根據轉換狀態，傳回下一個多位元組字元所佔的位元組數
(function)   |

mbrtowc
(C95)
|   | 根據轉換狀態，將下一個多位元組字元轉成寬字元
(function)   |

wcrtombwcrtomb_s
(C95)(C11)
|   | 根據轉換狀態，將寬字元轉成多位元組表示法
(function)   |

mbsrtowcsmbsrtowcs_s
(C95)(C11)
|   | 根據轉換狀態，將多位元組字串轉成寬字串
(function)   |

wcsrtombswcsrtombs_s
(C95)(C11)
|   | 根據轉換狀態，將寬字串轉成多位元組字串
(function)   |

Defined in header `<uchar.h>`

mbrtoc8
(C23)
|   | 將多位元組字元轉成 UTF-8
(function)   |

c8rtomb
(C23)
|   | 將 UTF-8 字元轉成目前地區設定使用的多位元組表示法
(function)   |

mbrtoc16
(C11)
|   | 將多位元組字元轉成 UTF-16
(function)   |

c16rtomb
(C11)
|   | 將 UTF-16 字元轉成目前地區設定使用的多位元組表示法
(function)   |

mbrtoc32
(C11)
|   | 將多位元組字元轉成 UTF-32
(function)   |

c32rtomb
(C11)
|   | 將 UTF-32 字元轉成目前地區設定使用的多位元組表示法
(function)   |

### Types

Defined in header `<uchar.h>`

Defined in header `<wchar.h>`

mbstate_t
(C95)
|   | 記錄逐步轉換多位元組字串所需的狀態資訊
(class)   |

Defined in header `<uchar.h>`

char8_t
(C23)
|   | 8-bit character type
(typedef)   |

char16_t
(C11)
|   | 16-bit character type
(typedef)   |

char32_t
(C11)
|   | 32-bit character type
(typedef)   |

### Macros

Defined in header `<limits.h>`

MB_LEN_MAX
|   | 所有支援的地區設定中，一個多位元組字元最多可佔用的位元組數
(macro constant)   |

Defined in header `<stdlib.h>`

MB_CUR_MAX
|   | 目前地區設定中，一個多位元組字元最多可佔用的位元組數
(macro variable)   |

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.10 Sizes of integer types <limits.h> (p: TBD)
7.10 整數型別的大小 <limits.h>（p: TBD）
7.10 整數型別的大小 <limits.h>（p: TBD）

- 7.22 General utilities <stdlib.h> (p: TBD)
7.22 通用工具 <stdlib.h>（p: TBD）
7.22 通用工具 <stdlib.h>（p: TBD）

- 7.28 Unicode utilities <uchar.h> (p: TBD)
7.28 Unicode 工具 <uchar.h>（p: TBD）
7.28 Unicode 工具 <uchar.h>（p: TBD）

- 7.29 Extended multibyte and wide character utilities <wchar.h> (p: TBD)
7.29 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：待定）
7.29 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：待定）

- 7.31.12 General utilities <stdlib.h> (p: TBD)
7.31.12 通用工具 <stdlib.h> （頁碼：待定）
7.31.12 通用工具 <stdlib.h> （頁碼：待定）

- 7.31.16 Extended multibyte and wide character utilities <wchar.h> (p: TBD)
7.31.16 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：待定）
7.31.16 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：待定）

- K.3.6 General utilities <stdlib.h> (p: TBD)
K.3.6 通用工具 <stdlib.h>（p: TBD）
K.3.6 通用工具 <stdlib.h>（p: TBD）

- K.3.9 Extended multibyte and wide character utilities <wchar.h> (p: TBD)
K.3.9 擴充套件多位元組和寬字元工具 <wchar.h> （頁碼：待定）
K.3.9 擴充套件多位元組和寬字元工具 <wchar.h> （頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.10 Sizes of integer types <limits.h> (p: TBD)
7.10 整數型別的大小 <limits.h>（p: TBD）
7.10 整數型別的大小 <limits.h>（p: TBD）

- 7.22 General utilities <stdlib.h> (p: TBD)
7.22 通用工具 <stdlib.h>（p: TBD）
7.22 通用工具 <stdlib.h>（p: TBD）

- 7.28 Unicode utilities <uchar.h> (p: TBD)
7.28 Unicode 工具 <uchar.h>（p: TBD）
7.28 Unicode 工具 <uchar.h>（p: TBD）

- 7.29 Extended multibyte and wide character utilities <wchar.h> (p: TBD)
7.29 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：待定）
7.29 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：待定）

- 7.31.12 General utilities <stdlib.h> (p: TBD)
7.31.12 通用工具 <stdlib.h> （頁碼：待定）
7.31.12 通用工具 <stdlib.h> （頁碼：待定）

- 7.31.16 Extended multibyte and wide character utilities <wchar.h> (p: TBD)
7.31.16 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：待定）
7.31.16 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：待定）

- K.3.6 General utilities <stdlib.h> (p: TBD)
K.3.6 通用工具 <stdlib.h>（p: TBD）
K.3.6 通用工具 <stdlib.h>（p: TBD）

- K.3.9 Extended multibyte and wide character utilities <wchar.h> (p: TBD)
K.3.9 擴充套件多位元組和寬字元工具 <wchar.h> （頁碼：待定）
K.3.9 擴充套件多位元組和寬字元工具 <wchar.h> （頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.10 Sizes of integer types <limits.h> (p: 222)
7.10 整數型別的大小 <limits.h>（p: 222）
7.10 整數型別的大小 <limits.h>（p: 222）

- 7.22 General utilities <stdlib.h> (p: 340-360)
7.22 通用工具 <stdlib.h> （頁碼：340-360）
7.22 通用工具 <stdlib.h> （頁碼：340-360）

- 7.28 Unicode utilities <uchar.h> (p: 398-401)
7.28 Unicode 工具 <uchar.h>（p: 398-401）
7.28 Unicode 工具 <uchar.h>（p: 398-401）

- 7.29 Extended multibyte and wide character utilities <wchar.h> (p: 402-446)
7.29 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：402-446）
7.29 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：402-446）

- 7.31.12 General utilities <stdlib.h> (p: 456)
7.31.12 通用工具 <stdlib.h> （頁碼：456）
7.31.12 通用工具 <stdlib.h> （頁碼：456）

- 7.31.16 Extended multibyte and wide character utilities <wchar.h> (p: 456)
7.31.16 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：456）
7.31.16 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：456）

- K.3.6 General utilities <stdlib.h> (p: 604-614)
K.3.6 通用工具 <stdlib.h>（p: 604-614）
K.3.6 通用工具 <stdlib.h>（p: 604-614）

- K.3.9 Extended multibyte and wide character utilities <wchar.h> (p: 627-651)
K.3.9 擴充套件多位元組和寬字元工具 <wchar.h> （頁碼：627-651）
K.3.9 擴充套件多位元組和寬字元工具 <wchar.h> （頁碼：627-651）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.10 Sizes of integer types <limits.h> (p: 203)
7.10 整數型別的大小 <limits.h>（p: 203）
7.10 整數型別的大小 <limits.h>（p: 203）

- 7.20 General utilities <stdlib.h> (p: 306-324)
7.20 通用工具 <stdlib.h> （頁碼：306-324）
7.20 通用工具 <stdlib.h> （頁碼：306-324）

- 7.24 Extended multibyte and wide character utilities <wchar.h> (p: 348-392)
7.24 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：348-392）
7.24 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：348-392）

- 7.26.10 General utilities <stdlib.h> (p: 402)
7.26.10 通用工具 <stdlib.h> （頁碼：402）
7.26.10 通用工具 <stdlib.h> （頁碼：402）

- 7.26.12 Extended multibyte and wide character utilities <wchar.h> (p: 402)
7.26.12 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：402）
7.26.12 擴充套件多位元組與寬字元工具 <wchar.h>（頁碼：402）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.1.4 Limits <float.h> and <limits.h>
4.1.4 限制 <float.h> 與 <limits.h>
4.1.4 限制 <float.h> 與 <limits.h>

- 4.10 GENERAL UTILITIES <stdlib.h>
4.10 通用工具 <stdlib.h>
4.10 通用工具 <stdlib.h>

- 4.13.7 General utilities <stdlib.h>
4.13.7 通用工具 <stdlib.h>
4.13.7 通用工具 <stdlib.h>

### See also

C++ documentation for Null-terminated multibyte strings

---
來源頁路徑：`en.cppreference.com/c/string/multibyte.html`
