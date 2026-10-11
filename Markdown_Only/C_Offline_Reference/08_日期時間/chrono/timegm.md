# timegm

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<time.h>`
|   |  |   |  |

```c
time_t timegm( struct tm* timeptr );
```
|   |   |   |  (since C23)  |

|  |  |  |  |

Converts the broken-down UTC time in `timeptr` into a calendar time with the same encoding as the values returned by the `time()`. The original values of the `tm_wday` and `tm_yday` of the `timeptr` are ignored, and the original values of the other components are not restricted to the ranges indicated previously.
將 timeptr 中分解表示的 UTC 時間轉換為日曆時間，其編碼方式與 time() 傳回的值相同。timeptr 的 tm_wday 和 tm_yday 的原始值被忽略，其他組成部分的原始值不受先前所述範圍的限制。
On success, the `tm_wday` and `tm_yday` are set appropriately, and the other components are set to represent the specified calendar time, but with their values set to the ranges indicated previously. The final value of `tm_mday` is not set until `tm_mon` and `tm_year` are determined.
成功時，tm_wday 和 tm_yday 會被適當設定，其他組成部分被設定為表示指定的日曆時間，但其值被設定在先前所述的範圍內。tm_mday 的最終值要到 tm_mon 和 tm_year 確定之後才設定。

### Parameters

| timeptr  |   | -  |   | a pointer to an object of type `struct tm`  |

### Return value

The specified calendar time encoded as a value of type `time_t`.
以 time_t 型別值編碼的指定日曆時間。
Returns `(time_t)(-1)` and does not change the value of the `tm_wday`, if the calendar time cannot be represented in the `time_t` encoding or the value in the `tm_year` cannot be represented as an `int`.
如果日曆時間無法用 time_t 編碼表示，或者 tm_year 中的值無法表示為 int，則傳回 ( time_t )( -1 ) 且不改變 tm_wday 的值。

### Example

Run this code

```c
#define _POSIX_C_SOURCE 200809L #include <stdio.h> #include <time.h> int main() {  struct tm tm_utc =  {  .tm_year = 2024 - 1900, // years since 1900  .tm_mon = 2 - 1, // months since January (0‑11)  .tm_mday = 15, // day of the month  .tm_hour = 12,  .tm_min = 30,  .tm_sec = 45,  .tm_isdst = 0 // DST flag not used for UTC  };  // Convert the broken‑down UTC time to a time_t value.  // timegm() assumes the struct tm describes UTC, avoiding any  // timezone or DST adjustments that localtime() would apply.  time_t utc_seconds = timegm(&tm_utc);  if (utc_seconds == (time_t)-1)  {  perror("timegm");  return 1;  }  printf("UTC time: %04d-%02d-%02d %02d:%02d:%02d → %ld seconds since the epoch\n",  tm_utc.tm_year + 1900,  tm_utc.tm_mon + 1,  tm_utc.tm_mday,  tm_utc.tm_hour,  tm_utc.tm_min,  tm_utc.tm_sec,  (long)utc_seconds);  struct tm check;  gmtime_r(&utc_seconds, &check);  printf("Back‑converted: %04d-%02d-%02d %02d:%02d:%02d UTC\n",  check.tm_year + 1900,  check.tm_mon + 1,  check.tm_mday,  check.tm_hour,  check.tm_min,  check.tm_sec); }
```

Possible output:
可能的輸出：

```c
UTC time: 2024-02-15 12:30:45 → 1708000245 seconds since the epoch Back‑converted: 2024-02-15 12:30:45 UTC
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.29.2.4 The timegm function (p: 402-403)
7.29.2.4 timegm 函式 (p: 402-403)
7.29.2.4 timegm 函式 (p: 402-403)

### See also

gmtimegmtime_rgmtime_s
(C23)(C11)
|   | converts time since epoch to calendar time expressed as Coordinated Universal Time (UTC)
(function)   |

time
|   | returns the current calendar time of the system as time since epoch
(function)   |

C++ documentation for timegm

---
來源頁路徑：`en.cppreference.com/c/chrono/timegm.html`
