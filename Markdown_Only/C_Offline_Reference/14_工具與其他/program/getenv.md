# getenv, getenv_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
char *getenv( const char *name );
```
|   |  (1)  |   |   |

```c
errno_t getenv_s( size_t *restrict len, char *restrict value,  rsize_t valuesz, const char *restrict name );
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

1) Searches for an environmental variable with name `name` in the host-specified environment list and returns a pointer to the string that is associated with the matched environment variable. The set of environmental variables and methods of altering it are implementation-defined.

This function is not required to be thread-safe. Another call to `getenv`, as well as a call to the POSIX functions `setenv()`, `unsetenv()`, and `putenv()` may invalidate the pointer returned by a previous call or modify the string obtained from a previous call.

Modifying the string returned by `getenv` invokes undefined behavior.

2) Same as (1), except that the values of the environment variable is written to the user-provided buffer `value` (unless null) and the number of bytes written is stored in the user-provided location `*len` (unless null). If the environment variable is not set in the environment, zero is written to `*len` (unless null) and `'\0'` is written to `value[0]` (unless null). In addition, the following errors are detected at runtime and call the currently installed constraint handler function:
- `name` is a null pointer
name 為空指標

- `valuesz` is greater than RSIZE_MAX
valuesz 大於 RSIZE_MAX

- `value` is a null pointer and `valuesz` is not zero
value 為空指標且 valuesz 不為零
name 為空指標 valuesz 大於 RSIZE_MAX value 為空指標且 valuesz 不為零
As with all bounds-checked functions, `getenv_s` is only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <stdlib.h>.
與所有邊界檢查函式一樣，僅當實現定義了 __STDC_LIB_EXT1__ 且使用者在包含 <stdlib.h> 之前將 __STDC_WANT_LIB_EXT1__ 定義為整數常量 1 時，才保證 getenv_s 可用。

### Parameters

| name  |   | -  |   | null-terminated character string identifying the name of the environmental variable to look for  |

| len  |   | -  |   | pointer to a user-provided location where `getenv_s` will store the length of the environment variable  |

| value  |   | -  |   | pointer to a user-provided character array where `getenv_s` will store the contents of the environment variable  |

| valuesz  |   | -  |   | maximum number of characters that `getenv_s` is allowed to write to `dest` (size of the buffer)  |

### Return value

1) character string identifying the value of the environmental variable or null pointer if such variable is not found.

2) zero if the environment variable was found, non-zero if it was not found or if a runtime constraint violation occurred. On any error, writes zero to `*len` (unless `len` is a null pointer).

### Notes

On POSIX systems, the environment variables are also accessible through the global variable `environ`, declared as `extern char **environ;` in <unistd.h>, and through the optional third argument, `envp`, of the main function.
在 POSIX 系統上，也可透過全域變數 environ（在 <unistd.h> 中宣告為 extern char ** environ），或 main 函式選用的第三個引數 envp，存取環境變數。
The call to `getenv_s` with a null pointer for `value` and zero for `valuesz` is used to determine the size of the buffer required to hold the entire result.
以空指標作為 value 、零作為 valuesz 呼叫 getenv_s ，用於確定儲存整個結果所需的緩衝區大小。

### Example

Run this code

```c
#include <stdio.h> #include <stdlib.h>   int main(void) {  const char *name = "PATH";  const char *env_p = getenv(name);  if (env_p)  printf("Your %s is %s\n", name, env_p); }
```

Possible output:
可能的輸出：

```c
Your PATH is /home/gamer/.local/bin:/usr/local/bin:/usr/bin:/bin:/usr/share/games
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.22.4.6 The getenv function (p: TBD)
7.22.4.6 getenv 函式（頁碼：待定）
7.22.4.6 getenv 函式（頁碼：待定）

- K.3.6.2.1 The getenv_s function (p: TBD)
K.3.6.2.1 getenv_s 函式（頁碼：待定）
K.3.6.2.1 getenv_s 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.22.4.6 The getenv function (p: 256-257)
7.22.4.6 getenv 函式（頁碼：256-257）
7.22.4.6 getenv 函式（頁碼：256-257）

- K.3.6.2.1 The getenv_s function (p: 440-441)
K.3.6.2.1 getenv_s 函式（頁碼：440-441）
K.3.6.2.1 getenv_s 函式（頁碼：440-441）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.22.4.6 The getenv function (p: 352-353)
7.22.4.6 getenv 函式（頁碼：352-353）
7.22.4.6 getenv 函式（頁碼：352-353）

- K.3.6.2.1 The getenv_s function (p: 606-607)
K.3.6.2.1 getenv_s 函式（頁碼：606-607）
K.3.6.2.1 getenv_s 函式（頁碼：606-607）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.20.4.5 The getenv function (p: 317)
7.20.4.5 getenv 函式（頁碼：317）
7.20.4.5 getenv 函式（頁碼：317）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.10.4.4 The getenv function
4.10.4.4 getenv 函式
4.10.4.4 getenv 函式

### See also

C++ documentation for getenv

---
來源頁路徑：`en.cppreference.com/c/program/getenv.html`
