# strftime

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<time.h>`
|   |  |   |  |

```c
size_t strftime( char* str, size_t count,  const char* format, const struct tm* tp );
```
|   |   |   | (until C99) |

```c
size_t strftime( char* restrict str, size_t count,  const char* restrict format, const struct tm* restrict tp );
```
|   |   |   | (since C99) |

|  |  |  |  |

Converts the date and time information from a given calendar time `tp` to a null-terminated multibyte character string `str` according to format string `format`. Up to `count` bytes are written.
依照格式字串 format，將 tp 所表示日曆時間中的日期與時間資訊轉換為以空字元結尾的多位元組字串 str。最多寫入 count 個位元組。

### Parameters

| str  |   | -  |   | pointer to the first element of the char array for output  |

| count  |   | -  |   | maximum number of bytes to write  |

| format  |   | -  |   | pointer to a null-terminated multibyte character string specifying the format of conversion  |

| tp  |   | -  |   | pointer to a `struct tm` object specifying the time to format  |

### Format string

The format string consists of zero or more conversion specifiers and ordinary characters (except `%`). All ordinary characters, including the terminating null character, are copied to the output string without modification. Each conversion specification begins with `%` character, optionally followed by `E` or `O` modifier (ignored if unsupported by the locale), followed by the character that determines the behavior of the specifier. The following format specifiers are available:
格式字串由零個或多個轉換說明符和普通字元（% 除外）組成。所有普通字元（包括終止空字元）都會原樣複製到輸出字串中。每個轉換規範以 % 字元開頭，其後可跟 E 或 O 修飾符（如果區域設定不支援則忽略），再跟一個決定該說明符行為的字元。可用的格式說明符如下：

| Conversion
specifier  |   | Explanation  |   | Used fields  |

| `%`  |   | writes literal `%`. The full conversion specification must be `%%`.  |   |   |

| `n`
(C99)  |   | writes newline character  |   |   |

| `t`
(C99)  |   | writes horizontal tab character  |   |   |

| Year  |

| `Y`  |   | writes **year** as a decimal number, e.g. 2017  |   | `**tm_year**`  |

| `EY`
(C99)  |   | writes **year** in the alternative representation, e.g.平成23年 (year Heisei 23) instead of 2011年 (year 2011) in ja_JP locale  |   | `**tm_year**`  |

| `y`  |   | writes last 2 digits of **year** as a decimal number (range `[00,99]`)  |   | `**tm_year**`  |

| `Oy`
(C99)  |   | writes last 2 digits of **year** using the alternative numeric system, e.g. 十一 instead of 11 in ja_JP locale  |   | `**tm_year**`  |

| `Ey`
(C99)  |   | writes **year** as offset from locale's alternative calendar period `%EC` (locale-dependent)  |   | `**tm_year**`  |

| `C`
(C99)  |   | writes first 2 digits of **year** as a decimal number (range `[00,99]`)  |   | `**tm_year**`  |

| `EC`
(C99)  |   | writes name of the **base year (period)** in the locale's alternative representation, e.g. 平成 (Heisei era) in ja_JP  |   | `**tm_year**`  |

| `G`
(C99)  |   | writes **ISO 8601 week-based year**, i.e. the year that contains the specified week.
In ISO 8601 weeks begin with Monday and the first week of the year must satisfy the following requirements:

- Includes January 4

- Includes first Thursday of the year
|   | `**tm_year**`, `**tm_wday**`, `**tm_yday**`  |

| `g`
(C99)  |   | writes last 2 digits of **ISO 8601 week-based year**, i.e. the year that contains the specified week (range `[00,99]`).
In ISO 8601 weeks begin with Monday and the first week of the year must satisfy the following requirements:

- Includes January 4

- Includes first Thursday of the year
|   | `**tm_year**`, `**tm_wday**`, `**tm_yday**`  |

| Month  |

| `b`  |   | writes **abbreviated month** name, e.g. `Oct` (locale dependent)  |   | `**tm_mon**`  |

| `Ob`
(C23)  |   | writes **abbreviated month** name in the locale's alternative representation  |   | `**tm_mon**`  |

| `h`
(C99)  |   | synonym of `b`  |   | `**tm_mon**`  |

| `B`  |   | writes **full month** name, e.g. `October` (locale dependent)  |   | `**tm_mon**`  |

| `OB`
(C23)  |   | writes appropriate **full month** name in the locale's alternative representation  |   | `**tm_mon**`  |

| `m`  |   | writes **month** as a decimal number (range `[01,12]`)  |   | `**tm_mon**`  |

| `Om`
(C99)  |   | writes **month** using the alternative numeric system, e.g. 十二 instead of 12 in ja_JP locale  |   | `**tm_mon**`  |

| Week  |

| `U`  |   | writes **week of the year** as a decimal number (Sunday is the first day of the week) (range `[00,53]`)  |   | `**tm_year**`, `**tm_wday**`, `**tm_yday**`  |

| `OU`
(C99)  |   | writes **week of the year**, as by `%U`, using the alternative numeric system, e.g. 五十二 instead of 52 in ja_JP locale  |   | `**tm_year**`, `**tm_wday**`, `**tm_yday**`  |

| `W`  |   | writes **week of the year** as a decimal number (Monday is the first day of the week) (range `[00,53]`)  |   | `**tm_year**`, `**tm_wday**`, `**tm_yday**`  |

| `OW`
(C99)  |   | writes **week of the year**, as by `%W`, using the alternative numeric system, e.g. 五十二 instead of 52 in ja_JP locale  |   | `**tm_year**`, `**tm_wday**`, `**tm_yday**`  |

| `V`
(C99)  |   | writes **ISO 8601 week of the year** (range `[01,53]`).
In ISO 8601 weeks begin with Monday and the first week of the year must satisfy the following requirements:

- Includes January 4

- Includes first Thursday of the year
|   | `**tm_year**`, `**tm_wday**`, `**tm_yday**`  |

| `OV`
(C99)  |   | writes **week of the year**, as by `%V`, using the alternative numeric system, e.g. 五十二 instead of 52 in ja_JP locale  |   | `**tm_year**`, `**tm_wday**`, `**tm_yday**`  |

| Day of the year/month  |

| `j`  |   | writes **day of the year** as a decimal number (range `[001,366]`)  |   | `**tm_yday**`  |

| `d`  |   | writes **day of the month** as a decimal number (range `[01,31]`)  |   | `**tm_mday**`  |

| `Od`
(C99)  |   | writes zero-based **day of the month** using the alternative numeric system, e.g. 二十七 instead of 27 in ja_JP locale
Single character is preceded by a space.
|   | `**tm_mday**`  |

| `e`
(C99)  |   | writes **day of the month** as a decimal number (range `[1,31]`).
Single digit is preceded by a space.
|   | `**tm_mday**`  |

| `Oe`
(C99)  |   | writes one-based **day of the month** using the alternative numeric system, e.g. 二十七 instead of 27 in ja_JP locale
Single character is preceded by a space.
|   | `**tm_mday**`  |

| Day of the week  |

| `a`  |   | writes **abbreviated weekday** name, e.g. `Fri` (locale dependent)  |   | `**tm_wday**`  |

| `A`  |   | writes **full weekday** name, e.g. `Friday` (locale dependent)  |   | `**tm_wday**`  |

| `w`  |   | writes **weekday** as a decimal number, where Sunday is `0` (range `[0-6]`)  |   | `**tm_wday**`  |

| `Ow`
(C99)  |   | writes **weekday**, where Sunday is `0`, using the alternative numeric system, e.g. 二 instead of 2 in ja_JP locale  |   | `**tm_wday**`  |

| `u`
(C99)  |   | writes **weekday** as a decimal number, where Monday is `1` (ISO 8601 format) (range `[1-7]`)  |   | `**tm_wday**`  |

| `Ou`
(C99)  |   | writes **weekday**, where Monday is `1`, using the alternative numeric system, e.g. 二 instead of 2 in ja_JP locale  |   | `**tm_wday**`  |

| Hour, minute, second  |

| `H`  |   | writes **hour** as a decimal number, 24 hour clock (range `[00-23]`)  |   | `**tm_hour**`  |

| `OH`
(C99)  |   | writes **hour** from 24-hour clock using the alternative numeric system, e.g. 十八 instead of 18 in ja_JP locale  |   | `**tm_hour**`  |

| `I`  |   | writes **hour** as a decimal number, 12 hour clock (range `[01,12]`)  |   | `**tm_hour**`  |

| `OI`
(C99)  |   | writes **hour** from 12-hour clock using the alternative numeric system, e.g. 六 instead of 06 in ja_JP locale  |   | `**tm_hour**`  |

| `M`  |   | writes **minute** as a decimal number (range `[00,59]`)  |   | `**tm_min**`  |

| `OM`
(C99)  |   | writes **minute** using the alternative numeric system, e.g. 二十五 instead of 25 in ja_JP locale  |   | `**tm_min**`  |

| `S`  |   | writes **second** as a decimal number (range `[00,60]`)  |   | `**tm_sec**`  |

| `OS`
(C99)  |   | writes **second** using the alternative numeric system, e.g. 二十四 instead of 24 in ja_JP locale  |   | `**tm_sec**`  |

| Other  |

| `c`  |   | writes **standard date and time string**, e.g. `Sun Oct 17 04:41:13 2010` (locale dependent)  |   | all  |

| `Ec`
(C99)  |   | writes **alternative date and time string**, e.g. using 平成23年 (year Heisei 23) instead of 2011年 (year 2011) in ja_JP locale  |   | all  |

| `x`  |   | writes localized **date representation** (locale dependent)  |   | all  |

| `Ex`
(C99)  |   | writes **alternative date representation**, e.g. using 平成23年 (year Heisei 23) instead of 2011年 (year 2011) in ja_JP locale  |   | all  |

| `X`  |   | writes localized **time representation**, e.g. 18:40:20 or 6:40:20 PM (locale dependent)  |   | all  |

| `EX`
(C99)  |   | writes **alternative time representation** (locale dependent)  |   | all  |

| `D`
(C99)  |   | equivalent to **"%m/%d/%y"**  |   | `**tm_mon**`, `**tm_mday**`, `**tm_year**`  |

| `F`
(C99)  |   | equivalent to **"%Y-%m-%d"** (the ISO 8601 date format)  |   | `**tm_mon**`, `**tm_mday**`, `**tm_year**`  |

| `r`
(C99)  |   | writes localized **12-hour clock** time (locale dependent)  |   | `**tm_hour**`, `**tm_min**`, `**tm_sec**`  |

| `R`
(C99)  |   | equivalent to **"%H:%M"**  |   | `**tm_hour**`, `**tm_min**`  |

| `T`
(C99)  |   | equivalent to **"%H:%M:%S"** (the ISO 8601 time format)  |   | `**tm_hour**`, `**tm_min**`, `**tm_sec**`  |

| `p`  |   | writes localized **a.m. or p.m.** (locale dependent)  |   | `**tm_hour**`  |

| `z`
(C99)  |   | writes **offset from UTC** in the ISO 8601 format (e.g. `-0430`), or no characters if the time zone information is not available  |   | `**tm_isdst**`  |

| `Z`  |   | writes locale-dependent **time zone name or abbreviation**, or no characters if the time zone information is not available  |   | `**tm_isdst**`  |

### Return value

The number of bytes written into the character array pointed to by `str` not including the terminating `'\0'` on success. If `count` was reached before the entire string could be stored, `0` is returned and the contents are indeterminate.
成功時，寫入 str 所指向的字元陣列中的位元組數，不包括終止的 '\0'。如果在完整字串能夠儲存之前達到了 count，則傳回 0，且內容不確定。

### Example

Run this code

```c
#include <locale.h> #include <stdio.h> #include <time.h> int main(void) {  char buff[70];  struct tm my_time =  {  .tm_year = 112, // = year 2012  .tm_mon = 9, // = 10th month  .tm_mday = 9, // = 9th day  .tm_hour = 8, // = 8 hours  .tm_min = 10, // = 10 minutes  .tm_sec = 20 // = 20 secs  };  if (strftime(buff, sizeof buff, "%A %c", &my_time))  puts(buff);  else  puts("strftime failed");  setlocale(LC_TIME, "el_GR.utf8");  if (strftime(buff, sizeof buff, "%A %c", &my_time))  puts(buff);  else  puts("strftime failed"); }
```

Possible output:
可能的輸出：

```c
Sunday Sun Oct 9 08:10:20 2012 Κυριακή Κυρ 09 Οκτ 2012 08:10:20 πμ EST
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.27.3.5 The strftime function (p: TBD)
7.27.3.5 strftime 函式 (p: 待定)
7.27.3.5 strftime 函式 (p: 待定)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.27.3.5 The strftime function (p: 288-291)
7.27.3.5 strftime 函式 (p: 288-291)
7.27.3.5 strftime 函式 (p: 288-291)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.27.3.5 The strftime function (p: 394-397)
7.27.3.5 strftime 函式 (p: 394-397)
7.27.3.5 strftime 函式 (p: 394-397)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.23.3.5 The strftime function (p: 343-347)
7.23.3.5 strftime 函式 (p: 343-347)
7.23.3.5 strftime 函式 (p: 343-347)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.12.3.5 The strftime function
4.12.3.5 strftime 函式
4.12.3.5 strftime 函式

### See also

asctimeasctime_s
(deprecated in C23)(C11)
|   | converts a tm object to a textual representation
(function)   |

ctimectime_s
(deprecated in C23)(C11)
|   | converts a time_t object to a textual representation
(function)   |

wcsftime
(C95)
|   | converts a tm object to custom wide string textual representation
(function)   |

C++ documentation for strftime

---
來源頁路徑：`en.cppreference.com/c/chrono/strftime.html`
