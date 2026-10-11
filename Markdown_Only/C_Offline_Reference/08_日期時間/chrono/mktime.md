# mktime

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<time.h>`
|   |  |   |  |

```c
time_t mktime( struct tm* arg );
```
|   |   |   |   |

|  |  |  |  |

Renormalizes local calendar time expressed as a struct tm object and also converts it to time since epoch as a time_t object. `arg->tm_wday` and `arg->tm_yday` are ignored. The values in `arg` are not checked for being out of range.
重新正規化由 struct tm 物件表示的本地日曆時間，並將其轉換為自紀元起算的 time_t 時間。arg->tm_wday 和 arg->tm_yday 會被忽略，也不會檢查 arg 中的值是否超出範圍。
A negative value of `arg->tm_isdst` causes `mktime` to attempt to determine if Daylight Saving Time was in effect in the specified time.
arg -> tm_isdst 為負值時，mktime 會嘗試判斷指定時間是否處於夏令時。
If the conversion to `time_t` is successful, the `arg` object is modified. All fields of `arg` are updated to fit their proper ranges. `arg->tm_wday` and `arg->tm_yday` are recalculated using information available in other fields.
如果到 time_t 的轉換成功，則修改 arg 物件。arg 的所有欄位都會更新以適合其正常範圍。arg -> tm_wday 和 arg -> tm_yday 使用其他欄位中可用的資訊重新計算。

### Parameters

| arg  |   | -  |   | pointer to a tm object specifying local calendar time to convert  |

### Return value

time since epoch as a time_t object on success, or `-1` if `arg` cannot be represented as a time_t object (POSIX also requires `EOVERFLOW` to be stored in errno in this case).
成功時傳回自紀元以來的時間作為 time_t 物件；如果 arg 無法表示為 time_t 物件，則傳回 -1（POSIX 還要求在這種情況下將 EOVERFLOW 存入 errno）。

### Notes

If the `struct tm` object was obtained from POSIX `strptime` or equivalent function, the value of `tm_isdst` is indeterminate, and needs to be set explicitly before calling `mktime`.
如果 struct tm 物件是從 POSIX strptime 或等效函式獲得的，則 tm_isdst 的值不確定，需要在呼叫 mktime 之前顯式設定。

### Example

Run this code

```c
#define _POSIX_C_SOURCE 200112L // for setenv on gcc #include <stdio.h> #include <stdlib.h> #include <time.h> int main(void) {  setenv("TZ", "/usr/share/zoneinfo/America/New_York", 1); // POSIX-specific  struct tm tm = *localtime(&(time_t){time(NULL)});  printf("Today is %s", asctime(&tm));  printf("(DST is %s)\n", tm.tm_isdst ? "in effect" : "not in effect");  tm.tm_mon -= 100; // tm_mon is now outside its normal range  mktime(&tm); // tm_isdst is not set to -1; today's DST status is used  printf("100 months ago was %s", asctime(&tm));  printf("(DST was %s)\n", tm.tm_isdst ? "in effect" : "not in effect"); }
```

Possible output:
可能的輸出：

```c
Today is Fri Apr 22 11:53:36 2016 (DST is in effect) 100 months ago was Sat Dec 22 10:53:36 2007 (DST was not in effect)
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.27.2.3 The mktime function (p: TBD)
7.27.2.3 mktime 函式（頁碼：待定）
7.27.2.3 mktime 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.27.2.3 The mktime function (p: 285-286)
7.27.2.3 mktime 函式（頁碼：285-286）
7.27.2.3 mktime 函式（頁碼：285-286）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.27.2.3 The mktime function (p: 390-391)
7.27.2.3 mktime 函式（頁碼：390-391）
7.27.2.3 mktime 函式（頁碼：390-391）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.23.2.3 The mktime function (p: 340-341)
7.23.2.3 mktime 函式（頁碼：340-341）
7.23.2.3 mktime 函式（頁碼：340-341）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.12.2.3 The mktime function
4.12.2.3 mktime 函式
4.12.2.3 mktime 函式

### See also

localtimelocaltime_rlocaltime_s
(C23)(C11)
|   | converts time since epoch to calendar time expressed as local time
(function)   |

C++ documentation for mktime

---
來源頁路徑：`en.cppreference.com/c/chrono/mktime.html`
