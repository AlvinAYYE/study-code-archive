# ctime, ctime_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<time.h>`
|   |  |   |  |

```c
char* ctime( const time_t* timer );
```
|   |  (1) |   | (until C23) |

```c
[[deprecated]] char* ctime( const time_t* timer );
```
|   |   |   | (since C23) |

```c
errno_t ctime_s( char *buf, rsize_t bufsz, const time_t* timer );
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

1) Converts given time since epoch to a calendar local time and then to a textual representation, as if by calling `asctime(localtime(timer))` or `asctime(localtime_r(timer, &(struct tm){0}))`(since C23). This function is deprecated and should not be used in new code.(since C23)

2) Same as (1), except that the function is equivalent to `asctime_s(buf, bufsz, localtime_s(timer, &(struct tm){0}))`, and the following errors are detected at runtime and call the currently installed constraint handler function:
- `buf` or `timer` is a null pointer
buf 或 timer 是空指標

- `bufsz` is less than `26` or greater than RSIZE_MAX
bufsz 小於 26 或大於 RSIZE_MAX
buf 或 timer 是空指標 bufsz 小於 26 或大於 RSIZE_MAX
As with all bounds-checked functions, `ctime_s` is only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <time.h>.
與所有邊界檢查函式一樣，只有當實現定義了 __STDC_LIB_EXT1__，並且使用者在包含 <time.h> 之前將 __STDC_WANT_LIB_EXT1__ 定義為整數常量 1 時，才能保證 ctime_s 可用。

The resulting string has the following format:
得到的字串具有以下格式：

```c
Www Mmm dd hh:mm:ss yyyy\n
```

- `Www` - the day of the week (one of `Mon`, `Tue`, `Wed`, `Thu`, `Fri`, `Sat`, `Sun`).
Www - 星期幾（Mon、Tue、Wed、Thu、Fri、Sat、Sun 之一）。

- `Mmm` - the month (one of `Jan`, `Feb`, `Mar`, `Apr`, `May`, `Jun`, `Jul`, `Aug`, `Sep`, `Oct`, `Nov`, `Dec`).
Mmm - 月份（Jan、Feb、Mar、Apr、May、Jun、Jul、Aug、Sep、Oct、Nov、Dec 之一）。

- `dd` - the day of the month
dd - 月中的日期

- `hh` - hours

- `mm` - minutes

- `ss` - seconds

- `yyyy` - years

The function does not support localization.
該函式不支援本地化。

### Parameters

| timer  |   | -  |   | pointer to a time_t object specifying the time to print  |

| buf  |   | -  |   | pointer to the first element of a char array of size at least `bufsz`  |

| bufsz  |   | -  |   | max number of bytes to output, typically the size of the buffer pointed to by `buf`  |

### Return value

1) pointer to a static null-terminated character string holding the textual representation of date and time. The string may be shared between asctime and `ctime`, and may be overwritten on each invocation of any of those functions.

2) zero on success (in which case the string representation of time has been written out to the array pointed to by `buf`), or non-zero on failure (in which case, the terminating null character is always written to `buf[0]` unless `buf` is a null pointer or `bufsz` is zero or greater than RSIZE_MAX.

### Notes

`ctime` returns a pointer to static data and is not thread-safe. In addition, it modifies the static tm object which may be shared with gmtime and localtime. POSIX marks this function obsolete and recommends strftime instead. The C standard also recommends strftime instead of `ctime` and `ctime_s` because `strftime` is more flexible and locale-sensitive.
ctime 傳回指向靜態資料的指標，因此不是執行緒安全的。此外，它會修改可能與 gmtime 和 localtime 共享的靜態 tm 物件。POSIX 將此函式標記為已過時，並建議改用 strftime。C 標準也建議用 strftime 代替 ctime 和 ctime_s，因為 strftime 更靈活且對區域設定敏感。
The behavior of `ctime` is undefined for the values of time_t that result in the string longer than 25 characters (e.g. year 10000).
對於會使字串長度超過 25 個字元的 time_t 值（例如 10000 年），ctime 的行為是未定義的。

### Example

Run this code

```c
#define __STDC_WANT_LIB_EXT1__ 1 #include <time.h> #include <stdio.h> int main(void) {  time_t result = time(NULL);  printf("%s", ctime(&result)); #ifdef __STDC_LIB_EXT1__  char str[26];  ctime_s(str,sizeof str,&result);  printf("%s", str); #endif }
```

Possible output:
可能的輸出：

```c
Tue May 26 21:51:03 2015 Tue May 26 21:51:03 2015
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.27.3.2 The ctime function (p: 287-288)
7.27.3.2 ctime 函式 (p: 287-288)
7.27.3.2 ctime 函式 (p: 287-288)

- K.3.8.2.2 The ctime_s function (p: 454)
K.3.8.2.2 ctime_s 函式 (p: 454)
K.3.8.2.2 ctime_s 函式 (p: 454)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.27.3.2 The ctime function (p: 393)
7.27.3.2 ctime 函式 (p: 393)
7.27.3.2 ctime 函式 (p: 393)

- K.3.8.2.2 The ctime_s function (p: 626)
K.3.8.2.2 ctime_s 函式 (p: 626)
K.3.8.2.2 ctime_s 函式 (p: 626)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.23.3.2 The ctime function (p: 342)
7.23.3.2 ctime 函式 (p: 342)
7.23.3.2 ctime 函式 (p: 342)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.12.3.2 The ctime function
4.12.3.2 ctime 函式
4.12.3.2 ctime 函式

### See also

asctimeasctime_s
(deprecated in C23)(C11)
|   | converts a tm object to a textual representation
(function)   |

strftime
|   | converts a tm object to custom textual representation
(function)   |

C++ documentation for ctime

---
來源頁路徑：`en.cppreference.com/c/chrono/ctime.html`
