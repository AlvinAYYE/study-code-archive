# EXIT_SUCCESS, EXIT_FAILURE

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
#define EXIT_SUCCESS /*implementation defined*/
```
|   |   |   |   |

```c
#define EXIT_FAILURE /*implementation defined*/
```
|   |   |   |   |

|  |  |  |  |

The `EXIT_SUCCESS` and `EXIT_FAILURE` macros expand into integral constant expressions that can be used as arguments to the exit function (and, therefore, as the values to return from the main function), and indicate program execution status.
EXIT_SUCCESS 和 EXIT_FAILURE 宏展開為整數常量表示式，可用作 exit 函式的參數（因此也可作為從 main 函式傳回的值），並指示程式執行狀態。

| Constant  |   | Description  |

| `EXIT_SUCCESS`  |   | successful execution of a program  |

| `EXIT_FAILURE`  |   | unsuccessful execution of a program  |

### Notes

Both `EXIT_SUCCESS` and the value zero indicate successful program execution status (see exit), although it is not required that `EXIT_SUCCESS` equals zero.
EXIT_SUCCESS 和零值都表示成功的程式執行狀態（見 exit ），儘管不要求 EXIT_SUCCESS 等於零。

### Example

Run this code

```c
#include <stdio.h> #include <stdlib.h> int main(void) {  FILE* fp = fopen("data.txt", "r");  if (fp == NULL)  {  fprintf(stderr, "fopen() failed in file %s at line #%d", __FILE__, __LINE__);  exit(EXIT_FAILURE);  }  /* Normal processing continues here. */  fclose(fp);  printf("Normal Return\n");  return EXIT_SUCCESS; }
```

Output:

```c
fopen() failed in file main.cpp at line #9
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.22/3 General utilities <stdlib.h> (p: TBD)
7.22/3 通用工具 <stdlib.h> （頁碼：待定）
7.22/3 通用工具 <stdlib.h> （頁碼：待定）

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

- 4.10 General utilities <stdlib.h>
4.10 通用工具 <stdlib.h>
4.10 通用工具 <stdlib.h>

### See also

C++ documentation for EXIT_SUCCESS, EXIT_FAILURE

---
來源頁路徑：`en.cppreference.com/c/program/EXIT_status.html`
