# RAND_MAX

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
#define RAND_MAX /*implementation defined*/
```
|   |   |   |   |

|  |  |  |  |

Expands to an integer constant expression equal to the maximum value returned by the function rand(). This value is implementation dependent. It's guaranteed that this value is at least `32767`.
展開後是整數常數運算式，其值等於 rand() 可回傳的最大值。此值由實作決定，但保證至少為 32767。

### Example

Run this code

```c
#include <limits.h> #include <stdio.h> #include <stdlib.h> #include <time.h> int main(void) {  srand(time(NULL)); // use current time as seed for random generator  printf("RAND_MAX: %i\n", RAND_MAX);  printf("INT_MAX: %i\n", INT_MAX);  printf("Random value on [0,1]: %f\n", (double)rand() / RAND_MAX); }
```

Possible output:
可能的輸出：

```c
RAND_MAX: 2147483647 INT_MAX: 2147483647 Random value on [0,1]: 0.362509
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.22/3 General utilities <stdlib.h> (p: 248)
7.22/3 通用工具 <stdlib.h>（p: 248）
7.22/3 通用工具 <stdlib.h>（p: 248）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.22/3 General utilities <stdlib.h> (p: 340)
7.22/3 通用工具 <stdlib.h>（p: 340）
7.22/3 通用工具 <stdlib.h>（p: 340）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.20/3 General utilities <stdlib.h> (p: 306)
7.20/3 通用工具 <stdlib.h>（p: 306）
7.20/3 通用工具 <stdlib.h>（p: 306）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.10 GENERAL UTILITIES <stdlib.h>
4.10 通用工具 <stdlib.h>
4.10 通用工具 <stdlib.h>

### See also

rand
|   | generates a pseudo-random number
(function)   |

srand
|   | seeds pseudo-random number generator
(function)   |

C++ documentation for RAND_MAX

---
來源頁路徑：`en.cppreference.com/c/numeric/random/RAND_MAX.html`
