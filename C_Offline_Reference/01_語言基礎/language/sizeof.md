# sizeof operator

> 來源：cppreference C 語言參考文件（離線轉換版）。

Queries size of the object or type.
查詢物件或型別的大小。
Used when actual size of the object must be known.
當必須知道物件的實際大小時使用。

### Syntax

|   |

| `**sizeof(**` type `**)**`  |   | (1)  |   |   |

|   |

| `**sizeof**` expression `****`  |   | (2)  |   |   |

|   |

Both versions return a value of type size_t.
兩個版本都傳回型別為 size_t 的值。

### Explanation

1) Returns the size, in bytes, of the object representation of type

2) Returns the size, in bytes, of the object representation of the type of expression. No implicit conversions are applied to expression.

### Notes

Depending on the computer architecture, a byte may consist of 8 or more bits, the exact number provided as CHAR_BIT.
根據計算機體系結構，一個位元組可以由 8 位或更多位組成，確切數字由 CHAR_BIT 提供。
`sizeof(char)`, `sizeof(signed char)`, and `sizeof(unsigned char)` always return `1`.
sizeof(char)、sizeof(signed char) 和 sizeof(unsigned char) 始終傳回 1。
sizeof cannot be used with function types, incomplete types (including `void`), or bit-field lvalues.
sizeof 不能用於函式型別、不完整型別（包括 void）或位域左值。
When applied to an operand that has structure or union type, the result is the total number of bytes in such an object, including internal and trailing padding. The trailing padding is such that if the object were an element of an array, the alignment requirement of the next element of this array would be satisfied, in other words, `sizeof(T)` returns the size of an element of a `T[]` array.
當應用於具有結構體或聯合體型別的運算物件時，結果是該物件中的總位元組數，包括內部和尾部填充。尾部填充使得：如果該物件是陣列的元素，則該陣列下一個元素的對齊要求將得到滿足，換句話說，sizeof(T) 傳回 T[] 陣列元素的大小。

If type is a VLA type and changing the value of its size expression would not affect the result of `sizeof`, it is unspecified whether or not the size expression is evaluated.
|   | (since C99) |

Except if the type of expression is a VLA,(since C99)expression is not evaluated and the `sizeof` operator may be used in an integer constant expression.
除非表示式的型別是 VLA（自 C99 起），否則表示式不被求值，sizeof 運運算元可以用於整數常量表示式中。

If the type of expression is a variable-length array type, expression is evaluated and the size of the array it evaluates to is calculated at run time.
|   | (since C99) |

Number of elements in any array `a` including VLA(since C99) may be determined with the expression `sizeof a / sizeof a[0]`. Note that if `a` has pointer type (such as after array-to-pointer conversion of function parameter type adjustment), this expression would simply divide the number of bytes in a pointer type by the number of bytes in the pointed type.
任何陣列 a（包括 VLA（自 C99 起））的元素數量可以用表示式 sizeof a / sizeof a[0] 確定。注意，如果 a 具有指標型別（例如函式參數型別調整時的陣列到指標轉換），該表示式只是將指標型別的位元組數除以所指型別的位元組數。

### Keywords

sizeof

### Example

Sample output corresponds to a platform with 64-bit pointers and 32-bit int
示例輸出對應於具有 64 位指標和 32 位 int 的平臺
Run this code

```c
#include <stdio.h> int main(void) {  short x;  // type argument:  printf("sizeof(float) = %zu\n", sizeof(float));  printf("sizeof(void(*)(void)) = %zu\n", sizeof(void(*)(void)));  printf("sizeof(char[10]) = %zu\n", sizeof(char[10])); // printf("sizeof(void(void)) = %zu\n", sizeof(void(void))); // Error: function type // printf("sizeof(char[]) = %zu\n", sizeof(char[])); // Error: incomplete type  // expression argument:  printf("sizeof 'a' = %zu\n", sizeof 'a'); // type of 'a' is int // printf("sizeof main = %zu\n", sizeof main); // Error: Function type  printf("sizeof &main = %zu\n", sizeof &main);  printf("sizeof \"hello\" = %zu\n", sizeof "hello"); // type is char[6]  printf("sizeof x = %zu\n", sizeof x); // type of x is short  printf("sizeof (x+1) = %zu\n", sizeof(x + 1)); // type of x+1 is int }
```

Possible output:
可能的輸出：

```c
sizeof(float) = 4 sizeof(void(*)(void)) = 8 sizeof(char[10]) = 10 sizeof 'a' = 4 sizeof &main = 8 sizeof "hello" = 6 sizeof x = 2 sizeof (x+1) = 4
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.5.3.4 The sizeof and alignof operators (p: TBD)
6.5.3.4 sizeof 和 alignof 運運算元 (p: TBD)
6.5.3.4 sizeof 和 alignof 運運算元 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.5.3.4 The sizeof and _Alignof operators (p: TBD)
6.5.3.4 sizeof 和 _Alignof 運運算元 (p: TBD)
6.5.3.4 sizeof 和 _Alignof 運運算元 (p: TBD)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.5.3.4 The sizeof and _Alignof operators (p: 90-91)
6.5.3.4 sizeof 和 _Alignof 運運算元 (p: 90-91)
6.5.3.4 sizeof 和 _Alignof 運運算元 (p: 90-91)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.5.3.4 The sizeof operator (p: 80-81)
6.5.3.4 sizeof 運運算元 (p: 80-81)
6.5.3.4 sizeof 運運算元 (p: 80-81)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.3.3.4 The sizeof operator
3.3.3.4 sizeof 運運算元
3.3.3.4 sizeof 運運算元

### See also

C++ documentation for `sizeof` operator

---
來源頁路徑：`en.cppreference.com/c/language/sizeof.html`
