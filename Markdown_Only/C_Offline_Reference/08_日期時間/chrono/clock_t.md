# clock_t

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<time.h>`
|   |  |   |  |

```c
typedef /* unspecified */ clock_t;
```
|   |   |   |   |

|  |  |  |  |

Arithmetic(until C11)Real(since C11) type capable of representing the processor time used by a process. It has implementation-defined range and precision.
算術（直至 C11）實數（自 C11 起）型別，能夠表示程式使用的處理器時間。其範圍和精度由實現定義。

### Example

Run this code

```c
#include <stdio.h> #include <time.h> #include <math.h> volatile double sink; int main (void) {  clock_t start = clock();  for(size_t i=0; i<3141592; ++i)  sink+=sin(i);  clock_t end = clock();  double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;  printf("for loop took %f seconds to execute \n", cpu_time_used); }
```

Possible output:
可能的輸出：

```c
for loop took 0.271828 seconds to execute
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.27.1/3 Components of time (p: 284)
7.27.1/3 時間的組成部分 (p: 284)
7.27.1/3 時間的組成部分 (p: 284)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.27.1/3 Components of time (p: 388)
7.27.1/3 時間的組成部分 (p: 388)
7.27.1/3 時間的組成部分 (p: 388)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.23.1/3 Components of time (p: 338)
7.23.1/3 時間的組成部分 (p: 338)
7.23.1/3 時間的組成部分 (p: 338)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.12.1 Components of time
4.12.1 時間的組成部分
4.12.1 時間的組成部分

### See also

clock
|   | returns raw processor clock time since the program is started
(function)   |

CLOCKS_PER_SEC
|   | number of processor clock ticks per second
(macro constant)   |

C++ documentation for clock_t

---
來源頁路徑：`en.cppreference.com/c/chrono/clock_t.html`
