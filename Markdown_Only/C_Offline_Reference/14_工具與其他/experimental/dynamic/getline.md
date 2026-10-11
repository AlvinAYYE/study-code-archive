# getline, getwline, getdelim, getwdelim

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
```
|   |  (1)  |   |  (dynamic memory TR)  |

```c
ssize_t getwline(wchar_t **lineptr, size_t *n, FILE *stream);
```
|   |  (2)  |   |  (dynamic memory TR)  |

```c
ssize_t getdelim(char ** restrict lineptr, size_t * restrict n,  int delimiter, FILE *stream);
```
|   |  (3)  |   |  (dynamic memory TR)  |

```c
ssize_t getwdelim(wchar_t ** restrict lineptr, size_t * restrict n,  wint_t delimiter, FILE * stream);
```
|   |  (4)  |   |  (dynamic memory TR)  |

|  |  |  |  |

1) Behaves like `getdelim(lineptr, n, '\n', stream)`

2) Behaves like `getwdelim(lineptr, n, L'\n', stream)`

3) Reads from the stream `stream` as if by fgetc, until `delimiter` is encountered, storing the characters in the buffer of size `*n` pointed to by `*lineptr`, automatically increasing its size as if by realloc to fit the entire input, including the delimiter, and adding a null terminator. `*lineptr` may be null, in which case `*n` is ignored and `getline` allocates a new buffer as if by malloc. The behavior is undefined if `delimiter` has a value that is outside the range of `unsigned char` or EOF.

4) Same as (3), except the characters are read as if by fgetwc and that `delimiter` must be a valid `wchar_t` or WEOF.

If `*lineptr` is not null, the behavior is undefined if `*lineptr` is not a pointer that can be passed to free or if `*n` is less than the size of the allocated memory pointed to by `*lineptr`
如果 *lineptr 不為空，則當 *lineptr 不是可以傳遞給 free 的指標，或 *n 小於 *lineptr 所指向已分配記憶體的大小時，行為未定義
As all functions from Dynamic Memory TR, `getline` is only guaranteed to be available if `__STDC_ALLOC_LIB__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT2__` to the integer constant `1` before including `stdio.h`.
與 Dynamic Memory TR 中的所有函式一樣，getline 僅在實現定義了 __STDC_ALLOC_LIB__ 且使用者在包含 stdio.h 之前將 __STDC_WANT_LIB_EXT2__ 定義為整數常量 1 時才保證可用。

### Parameters

| lineptr  |   | -  |   | pointer to a pointer to the initial buffer or to a null pointer  |

| n  |   | -  |   | pointer to the size of the initial buffer  |

| delimiter  |   | -  |   | the delimiter character  |

| stream  |   | -  |   | valid input stream, opened by fopen  |

### Return value

The number of characters stored in the buffer, including the delimiter, but excluding the null terminator.
儲存在緩衝區中的字元數，包括分隔符，但不包括空終止符。
On error, returns `-1` and sets feof or ferror on `stream`.
出錯時，傳回 -1 並在 stream 上設定 feof 或 ferror。

### Notes

These functions are identical to their POSIX versions except that it is allowed, but not required to set errno on error.
這些函式與其 POSIX 版本相同，不同之處在於允許但不要求在出錯時設定 errno。

### Example

Run this code

```c
#ifdef __STDC_ALLOC_LIB__ #define __STDC_WANT_LIB_EXT2__ 1 #else #define _POSIX_C_SOURCE 200809L #endif #include <stdio.h> #include <stdlib.h> void get_y_or_n(void) {  char *response = NULL;  size_t len;  printf("Continue? [y] n: ");  if((getline(&response, &len, stdin) < 0) || (len && response[0] == 'n')) {  free(response);  exit(0);  }  free(response);  return; } int main(void)  {  get_y_or_n(); }
```

Output:

```c
Continue? [y] n:
```

### See also

fgets
|   | gets a character string from a file stream
(function)   |

getsgets_s
(removed in C11)(C11)
|   | reads a character string from stdin
(function)   |

fgetws
(C95)
|   | gets a wide string from a file stream
(function)   |

malloc
|   | allocates memory
(function)   |

---
來源頁路徑：`en.cppreference.com/c/experimental/dynamic/getline.html`
