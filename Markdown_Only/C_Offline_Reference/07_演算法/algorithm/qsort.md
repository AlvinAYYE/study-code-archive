# qsort, qsort_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
void qsort( void* ptr, size_t count, size_t size,  int (*comp)(const void*, const void*) );
```
|   |  (1)  |   |   |

```c
errno_t qsort_s( void* ptr, rsize_t count, rsize_t size,  int (*comp)(const void*, const void*, void*),  void* context );
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

1) Sorts the given array pointed to by `ptr` in ascending order. The array contains `count` elements of `size` bytes. Function pointed to by `comp` is used for object comparison.

2) Same as (1), except that the additional context parameter `context` is passed to `comp` and that the following errors are detected at runtime and call the currently installed constraint handler function:
- `count` or `size` is greater than RSIZE_MAX
count 或 size 大於 RSIZE_MAX

- `ptr` or `comp` is a null pointer (unless `count` is zero)
ptr 或 comp 是空指標（除非 count 為零）
count 或 size 大於 RSIZE_MAX，ptr 或 comp 是空指標（除非 count 為零）
As with all bounds-checked functions, `qsort_s` is only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <stdlib.h>.
與所有邊界檢查函式一樣，qsort_s 僅在實現定義了 __STDC_LIB_EXT1__ 且使用者在包含 <stdlib.h> 之前將 __STDC_WANT_LIB_EXT1__ 定義為整數常量 1 時才保證可用。

If `comp` indicates two elements as equivalent, their order in the resulting sorted array is unspecified.
如果 comp 指示兩個元素等價，則它們在結果排序陣列中的順序是未指定的。

### Parameters

| ptr  |   | -  |   | pointer to the array to sort  |

| count  |   | -  |   | number of elements in the array  |

| size  |   | -  |   | size of each element in the array in bytes  |

| comp  |   | -  |   | comparison function which returns ​a negative integer value if the first argument is *less* than the second, a positive integer value if the first argument is *greater* than the second and zero if the arguments are equivalent.

The signature of the comparison function should be equivalent to the following:
`int cmp(const void *a, const void *b);`
The function must not modify the objects passed to it and must return consistent results when called for the same objects, regardless of their positions in the array.
​

| context  |   | -  |   | additional information (e.g., collating sequence), passed to `comp` as the third argument  |

### Return value

1) (none)

2) zero on success, non-zero if a runtime constraints violation was detected

### Notes

Despite the name, neither C nor POSIX standards require this function to be implemented using quicksort or make any complexity or stability guarantees.
儘管名稱如此，C 和 POSIX 標準都不要求該函式使用快速排序實現，也不做任何複雜度或穩定性保證。
Unlike other bounds-checked functions, `qsort_s` does not treat arrays of zero size as a runtime constraint violation and instead returns successfully without altering the array (the other function that accepts arrays of zero size is bsearch_s).
與其他邊界檢查函式不同，qsort_s 不將零大小陣列視為執行時約束違規，而是成功傳回而不修改陣列（另一個接受零大小陣列的函式是 bsearch_s）。
The implementation of `qsort_s` in the Windows CRT is incompatible with the C standard. The Microsoft's version is declared as: `void qsort_s(void *base, size_t num, size_t width,  int (*compare )(void *, const void *, const void *), void * context);`. It does not return a value, and the comparison function has a reversed parameter order with regard to the standard: the `context` is passed first.
Windows CRT 中 qsort_s 的實現與 C 標準不相容。Microsoft 的版本 宣告為：void qsort_s ( void * base , size_t num , size_t width , int ( * compare )( void * , const void * , const void * ), void * context ); . 它不傳回值，並且比較函式的參數順序與標準相反：context 首先傳遞。

### Example

Run this code

```c
#include <limits.h> #include <stdio.h> #include <stdlib.h>   int compare_ints(const void* a, const void* b) {  int arg1 = *(const int*)a;  int arg2 = *(const int*)b;  if (arg1 < arg2) return -1;  if (arg1 > arg2) return 1;  return 0;  // return (arg1 > arg2) - (arg1 < arg2); // possible shortcut  // return arg1 - arg2; // erroneous shortcut: undefined behavior in case of  // integer overflow, such as with INT_MIN here }   int main(void) {  int ints[] = {-2, 99, 0, -743, 2, INT_MIN, 4};  int size = sizeof ints / sizeof *ints;    qsort(ints, size, sizeof(int), compare_ints);    for (int i = 0; i < size; i++)  printf("%d ", ints[i]);  printf("\n"); }
```

Output:

```c
-2147483648 -743 -2 0 2 4 99
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.22.5.2 The qsort function (p: TBD)
7.22.5.2 qsort 函式 (p: TBD)
7.22.5.2 qsort 函式 (p: TBD)

- K.3.6.3.2 The qsort_s function (p: TBD)
K.3.6.3.2 qsort_s 函式 (p: TBD)
K.3.6.3.2 qsort_s 函式 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.22.5.2 The qsort function (p: 258-259)
7.22.5.2 qsort 函式 (p: 258-259)
7.22.5.2 qsort 函式 (p: 258-259)

- K.3.6.3.2 The qsort_s function (p: 442-443)
K.3.6.3.2 qsort_s 函式 (p: 442-443)
K.3.6.3.2 qsort_s 函式 (p: 442-443)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.22.5.2 The qsort function (p: 355-356)
7.22.5.2 qsort 函式 (p: 355-356)
7.22.5.2 qsort 函式 (p: 355-356)

- K.3.6.3.2 The qsort_s function (p: 609)
K.3.6.3.2 qsort_s 函式 (p: 609)
K.3.6.3.2 qsort_s 函式 (p: 609)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.20.5.2 The qsort function (p: 319)
7.20.5.2 qsort 函式 (p: 319)
7.20.5.2 qsort 函式 (p: 319)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.10.5.2 The qsort function
4.10.5.2 qsort 函式
4.10.5.2 qsort 函式

### See also

bsearchbsearch_s
(C11)
|   | searches an array for an element of unspecified type
(function)   |

C++ documentation for qsort

---
來源頁路徑：`en.cppreference.com/c/algorithm/qsort.html`
