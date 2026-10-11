# As-if rule

> 來源：cppreference C 語言參考文件（離線轉換版）。

Allows any and all code transformations that do not change the observable behavior of the program.
允許任何和所有不改變程式可觀察行為的程式碼變換。

### Explanation

The C compiler is permitted to perform any changes to the program as long as the following remains true:
只要以下條件仍然成立，C 編譯器可以對程式執行任何更改：

1) At every sequence point, the values of all volatile objects are stable (previous evaluations are complete, new evaluations not started).
|   | (until C11) |

1) Accesses (reads and writes) to volatile objects occur strictly according to the semantics of the expressions in which they occur. In particular, they are not reordered with respect to other volatile accesses on the same thread.
|   | (since C11) |

2) At program termination, data written to files is exactly as if the program was executed as written.

3) Prompting text which is sent to interactive devices will be shown before the program waits for input.

4) If the pragma  #pragma STDC FENV_ACCESS is supported and is set to `ON`, the changes to the floating-point environment (floating-point exceptions and rounding modes) are guaranteed to be observed by the floating-point arithmetic operators and function calls as if executed as written, except that
- the result of any floating-point expression other than cast and assignment may have range and precision of a floating-point type different from the type of the expression (see FLT_EVAL_METHOD),

- notwithstanding the above, intermediate results of any floating-point expression may be calculated as if to infinite range and precision (unless  #pragma STDC FP_CONTRACT is `OFF`).
|   | (since C99) |

### Notes

|  | This section is incomplete
Reason: fill out similar to cpp/language/as_if  |

### See also

- Order of evaluation
求值順序

C++ documentation for as-if rule

---
來源頁路徑：`en.cppreference.com/c/language/as_if.html`
