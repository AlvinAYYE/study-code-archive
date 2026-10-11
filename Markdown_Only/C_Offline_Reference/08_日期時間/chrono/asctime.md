# asctime, asctime_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<time.h>`
|   |  |   |  |

```c
char* asctime( const struct tm* time_ptr );
```
|   |  (1) |   | (until C23) |

```c
[[deprecated]] char* asctime( const struct tm* time_ptr );
```
|   |   |   | (since C23) |

```c
errno_t asctime_s( char* buf, rsize_t bufsz, const struct tm* time_ptr );
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

1) Converts given calendar time tm to a textual representation of the following fixed 25-character form: `Www Mmm dd hh:mm:ss yyyy\n`
- `Www` - three-letter English abbreviated day of the week from `time_ptr->tm_wday`, one of `Mon`, `Tue`, `Wed`, `Thu`, `Fri`, `Sat`, `Sun`.
Www —— 來自 time_ptr -> tm_wday 的三個字母英文縮寫星期名，為 Mon 、 Tue 、 Wed 、 Thu 、 Fri 、 Sat 、 Sun 之一。

- `Mmm` - three-letter English abbreviated month name from `time_ptr->tm_mon`, one of `Jan`, `Feb`, `Mar`, `Apr`, `May`, `Jun`, `Jul`, `Aug`, `Sep`, `Oct`, `Nov`, `Dec`.
Mmm —— 來自 time_ptr -> tm_mon 的三個字母英文縮寫月份名，為 Jan 、 Feb 、 Mar 、 Apr 、 May 、 Jun 、 Jul 、 Aug 、 Sep 、 Oct 、 Nov 、 Dec 之一。

- `dd` - 2-digit day of the month from `timeptr->tm_mday` as if printed by sprintf using `%2d`.
dd —— 來自 timeptr -> tm_mday 的兩位數日期，如同用 sprintf 以 % 2 d 列印。

- `hh` - 2-digit hour from `timeptr->tm_hour` as if printed by sprintf using `%.2d`.
hh —— 來自 timeptr -> tm_hour 的兩位數小時，如同用 sprintf 以 % .2 d 列印。

- `mm` - 2-digit minute from `timeptr->tm_min` as if printed by sprintf using `%.2d`.
mm —— 來自 timeptr -> tm_min 的兩位數分鐘，如同用 sprintf 以 % .2 d 列印。

- `ss` - 2-digit second from `timeptr->tm_sec` as if printed by sprintf using `%.2d`.
ss —— 來自 timeptr -> tm_sec 的兩位數秒，如同用 sprintf 以 % .2 d 列印。

- `yyyy` - 4-digit year from `timeptr->tm_year + 1900` as if printed by sprintf using `%4d`.
yyyy —— 來自 timeptr -> tm_year + 1900 的四位數年份，如同用 sprintf 以 % 4 d 列印。

The behavior is undefined if any member of `*time_ptr` is outside its normal range.

The behavior is undefined if the calendar year indicated by `time_ptr->tm_year` has more than 4 digits or is less than the year 1000.

The function does not support localization, and the newline character cannot be removed.

The function modifies static storage and is not thread-safe.

This function is deprecated and should not be used in new code.
|   | (since C23) |

2) Same as (1), except that the message is written into user-provided storage `buf`, which is guaranteed to be null-terminated, and the following errors are detected at runtime and call the currently installed constraint handler function:
- `buf` or `time_ptr` is a null pointer
buf 或 time_ptr 是空指標

- `bufsz` is less than 26 or greater than RSIZE_MAX
bufsz 小於 26 或大於 RSIZE_MAX

- not all members of `*time_ptr` are within their normal ranges
* time_ptr 並非所有成員都在其正常範圍內

- the year indicated by `time_ptr->tm_year` is less than 0 or greater than 9999.
time_ptr -> tm_year 指定的年份小於 0 或大於 9999。
buf 或 time_ptr 是空指標；bufsz 小於 26 或大於 RSIZE_MAX；* time_ptr 並非所有成員都在其正常範圍內；time_ptr -> tm_year 指定的年份小於 0 或大於 9999。
As with all bounds-checked functions, `asctime_s` is only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <time.h>.
與所有邊界檢查函式一樣，只有當實現定義了 __STDC_LIB_EXT1__ 並且使用者在包含 <time.h> 之前將 __STDC_WANT_LIB_EXT1__ 定義為整數常量 1 時，才保證 asctime_s 可用。

### Parameters

| time_ptr  |   | -  |   | pointer to a tm object specifying the time to print  |

| buf  |   | -  |   | pointer to a user-supplied buffer at least 26 bytes in length  |

| bufsz  |   | -  |   | size of the user-supplied buffer  |

### Return value

1) pointer to a static null-terminated character string holding the textual representation of date and time as described above. The string may be shared between `asctime` and ctime, and may be overwritten on each invocation of any of those functions.

2) zero on success, non-zero on failure, in which case `buf[0]` is set to zero (unless `buf` is a null pointer or `bufsz` is zero or greater than RSIZE_MAX).

### Notes

`asctime` returns a pointer to static data and is not thread-safe. POSIX marks this function obsolete and recommends strftime instead. The C standard also recommends strftime instead of `asctime` and `asctime_s` because `strftime` is more flexible and locale-sensitive.
asctime 傳回指向靜態資料的指標，且不是執行緒安全的。POSIX 將此函式標記為過時並推薦改用 strftime。C 標準也推薦使用 strftime 而非 asctime 和 asctime_s，因為 strftime 更靈活且與本地化相關。
POSIX limits undefined behaviors only to when the output string would be longer than 25 characters, when `timeptr->tm_wday` or `timeptr->tm_mon` are not within the expected ranges, or when `timeptr->tm_year` exceeds `INT_MAX - 1990`.
POSIX 僅在以下情況下發生未定義行為：輸出字串長度超過 25 個字元時、timeptr -> tm_wday 或 timeptr -> tm_mon 不在預期範圍內時、或 timeptr -> tm_year 超過 INT_MAX - 1990 時。
Some implementations handle `timeptr->tm_mday == 0` as meaning the last day of the preceding month.
某些實現將 timeptr -> tm_mday == 0 處理為上個月的最後一天。

### Example

Run this code

```c
#define __STDC_WANT_LIB_EXT1__ 1 #include <stdio.h> #include <time.h> int main(void) {  struct tm tm = *localtime(&(time_t){time(NULL)});  printf("%s", asctime(&tm)); // note implicit trailing '\n' #ifdef __STDC_LIB_EXT1__  char str[26];  asctime_s(str, sizeof str, &tm);  printf("%s", str); #endif }
```

Possible output:
可能的輸出：

```c
Tue May 26 21:51:50 2015 Tue May 26 21:51:50 2015
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.27.2.1 The asctime function (p: 287)
7.27.2.1 asctime 函式（頁碼：287）
7.27.2.1 asctime 函式（頁碼：287）

- K.3.8.2.1 The asctime_s function (p: 453-454)
K.3.8.2.1 asctime_s 函式（頁碼：453-454）
K.3.8.2.1 asctime_s 函式（頁碼：453-454）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.27.2.1 The asctime function (p: 392-393)
7.27.2.1 asctime 函式（頁碼：392-393）
7.27.2.1 asctime 函式（頁碼：392-393）

- K.3.8.2.1 The asctime_s function (p: 624-625)
K.3.8.2.1 asctime_s 函式（頁碼：624-625）
K.3.8.2.1 asctime_s 函式（頁碼：624-625）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.23.3.1 The asctime function (p: 341-342)
7.23.3.1 asctime 函式（頁碼：341-342）
7.23.3.1 asctime 函式（頁碼：341-342）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.12.3.1 The asctime function
4.12.3.1 asctime 函式
4.12.3.1 asctime 函式

### See also

ctimectime_s
(deprecated in C23)(C11)
|   | converts a time_t object to a textual representation
(function)   |

strftime
|   | converts a tm object to custom textual representation
(function)   |

C++ documentation for asctime

---
來源頁路徑：`en.cppreference.com/c/chrono/asctime.html`
