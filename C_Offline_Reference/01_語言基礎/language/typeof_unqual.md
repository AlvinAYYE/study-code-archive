# typeof operators (since C23)

> 來源：cppreference C 語言參考文件（離線轉換版）。

Determines the type of an object.
確定物件的型別。

### Syntax

|   |

| `**typeof(**` type `**)**`  |   | (1)  |   |   |

|   |

| `**typeof(**` expression `**)**`  |   | (2)  |   |   |

|   |

| `**typeof_unqual(**` type `**)**`  |   | (3)  |   |   |

|   |

| `**typeof_unqual(**` expression `**)**`  |   | (4)  |   |   |

|   |

### Explanation

1) produces the type-name with any nested typeof-specifier evaluated

2) yields the type-name representing the type of its operand. No implicit conversions are applied to expression.

3,4) the same as (1) and (2) respectively but remove qualifiers

### Notes

`typeof` and `typeof_unqual` are collectively called the *typeof operators*. The `typeof` operators cannot be applied to bit-field members. If the type of the operand is a variably modified type, the operand is evaluated; otherwise, the operand is not evaluated. The result of the `typeof_unqual` operator is the non-atomic unqualified type that would result from the `typeof` operator. The `typeof` operator preserves all qualifiers.
typeof 和 typeof_unqual 統稱為 typeof 運運算元。typeof 運運算元不能應用於位域成員。如果運算元的型別是可變修改型別，則對運算元求值；否則不對運算元求值。typeof_unqual 運運算元的結果是 typeof 運運算元本會產生的非原子非限定型別。typeof 運運算元保留所有限定符。

### Example

|  | This section is incomplete
Reason: no example  |

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.7.2.5 The typeof specifiers (p: 115-118)
6.7.2.5 typeof 說明符（p: 115-118）
6.7.2.5 typeof 說明符（p: 115-118）

### See also

C++ documentation for decltype

---
來源頁路徑：`en.cppreference.com/c/language/typeof_unqual.html`
