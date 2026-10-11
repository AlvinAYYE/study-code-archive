# Conditional inclusion

> 來源：cppreference C 語言參考文件（離線轉換版）。

The preprocessor supports conditional compilation of parts of source file. This behavior is controlled by `#if`, `#else`, `#elif`, `#ifdef`, `#ifndef`, `#elifdef`, `#elifndef`(since C23), and `#endif` directives.
前處理器支援依條件編譯原始碼中的不同部分。這項功能由 #if、#else、#elif、#ifdef、#ifndef、#elifdef、#elifndef（C23 起）及 #endif 指令控制。

### Syntax

|   |

| `**#if**` expression  |   |   |   |   |

|   |

| `**#ifdef**` identifier  |   |   |   |   |

|   |

| `**#ifndef**` identifier  |   |   |   |   |

|   |

| `**#elif**` expression  |   |   |   |   |

|   |

| `**#elifdef**` identifier  |   |   |   | (since C23)  |

|   |

| `**#elifndef**` identifier  |   |   |   | (since C23)  |

|   |

| `**#else**`  |   |   |   |   |

|   |

| `**#endif**`  |   |   |   |   |

|   |

### Explanation

The conditional preprocessing block starts with `#if`, `#ifdef` or `#ifndef` directive, then optionally includes any number of `#elif`, `#elifdef`, or `#elifndef`(since C23) directives, then optionally includes at most one `#else` directive and is terminated with `#endif` directive. Any inner conditional preprocessing blocks are processed separately.
條件預處理區塊以 #if、#ifdef 或 #ifndef 指令開頭，接著可有任意數量的 #elif、#elifdef 或 #elifndef（C23 起），再選擇性地加入一個 #else，最後以 #endif 結束。巢狀的條件預處理區塊會各自獨立處理。
Each of `#if`, `#ifdef`, `#ifndef`, `#elif`, `#elifdef`, `#elifndef`(since C23), and `#else` directives control code block until first `#elif`, `#elifdef`, `#elifndef`(since C23), `#else`, `#endif` directive not belonging to any inner conditional preprocessing blocks.
#if 、 #ifdef 、 #ifndef 、 #elif 、 #elifdef 、 #elifndef （自 C23 起）和 #else 指令中的每一個都控制程式碼塊，直到第一個不屬於任何內部條件預處理塊的 #elif 、 #elifdef 、 #elifndef （自 C23 起）、 #else 或 #endif 指令為止。
`#if`, `#ifdef` and `#ifndef` directives test the specified condition (see below) and if it evaluates to true, compiles the controlled code block. In that case subsequent `#else`, `#elifdef`, `#elifndef`,(since C23) and `#elif` directives are ignored. Otherwise, if the specified condition evaluates false, the controlled code block is skipped and the subsequent `#else`, `#elifdef`, `#elifndef`,(since C23) or `#elif` directive (if any) is processed. If the subsequent directive is `#else`, the code block controlled by the `#else` directive is unconditionally compiled. Otherwise, the `#elif`, `#elifdef`, or `#elifndef`(since C23) directive acts as if it was `#if` directive: checks for condition, compiles or skips the controlled code block based on the result, and in the latter case processes subsequent `#elif`, `#elifdef`, `#elifndef`,(since C23) and `#else` directives. The conditional preprocessing block is terminated by `#endif` directive.
#if 、 #ifdef 和 #ifndef 指令測試指定的條件（見下文），如果求值為真，則編譯受控的程式碼塊。在這種情況下，後續的 #else 、 #elifdef 、 #elifndef （自 C23 起）和 #elif 指令被忽略。否則，如果指定的條件求值為假，則跳過受控的程式碼塊，並處理後續的 #else 、 #elifdef 、 #elifndef （自 C23 起）或 #elif 指令（如有）。如果後續指令是 #else ，則 #else 指令控制的程式碼塊被無條件編譯。否則， #elif 、 #elifdef 或 #elifndef （自 C23 起）指令的表現就如同 #if 指令：檢查條件，並根據結果編譯或跳過受控的程式碼塊，在後一種情況下處理後續的 #elif 、 #elifdef 、 #elifndef （自 C23 起）和 #else 指令。條件預處理塊由 #endif 指令結束。

### Conditional evaluation
條件判斷

#### `#if, #elif`

The expression is a constant expression, using only constants and identifiers, defined using  #define directive. Any identifier, which is not literal, non defined using  #define directive, evaluates to `0` except `true` which evaluates to `1`(since C23).
該表示式是常量表示式，只使用以 #define 指令定義的常量和識別符號。任何不是字面量、未以 #define 指令定義的識別符號都求值為 0 ，但求值為 1 的 true 除外（自 C23 起）。
The expression may contain unary operators in form `defined` identifier or `defined (`identifier`)` which return `1` if the identifier was defined using  #define directive and `0` otherwise. In this context, `__has_include`, `__has_embed` and `__has_c_attribute` are treated as if they were the name of defined macros.(since C23) If the expression evaluates to nonzero value, the controlled code block is included and skipped otherwise. If any used identifier is not a constant, it is replaced with `0`.
該表示式可以包含形式為 defined identifier 或 defined ( identifier ) 的一元運運算元：如果該識別符號是以 #define 指令定義的，則傳回 1 ，否則傳回 0 。在此上下文中， __has_include 、 __has_embed 和 __has_c_attribute 被視為已定義宏的名稱。（自 C23 起）如果表示式求值為非零值，則包含受控的程式碼塊，否則跳過它。如果使用的任何識別符號不是常量，則它被替換為 0 。

In context of a preprocessor directive, a `__has_c_attribute` expression detects whether a given attribute token is supported and its supported version. See Attribute testing.
|   | (since C23) |

Note: Until DR 412, `#if *cond1*` ... `#elif *cond2*` is different from `#if *cond1*` ... `#else` followed by `#if *cond3*` because if `*cond1*` is true, the second `#if` is skipped and `*cond3*` does not need to be well-formed, while `#elif`'s `*cond2*` must be a valid expression. As of DR 412, `#elif` that leads the skipped code block is also skipped.
注意：在 DR 412 之前， #if cond1 ... #elif cond2 不同於 #if cond1 ... #else 後跟 #if cond3 ，因為如果 cond1 為真，第二個 #if 會被跳過，cond3 不必是良構的，而 #elif 的 cond2 必須是有效表示式。自 DR 412 起，引導被跳過程式碼塊的 #elif 也會被跳過。

#### Combined directives

Checks if the identifier was defined as a macro name.
檢查該識別字是否已定義為巨集名稱。
`#ifdef` identifier is essentially equivalent to `#if defined` identifier.
#ifdef identifier 本質上等價於 #if defined identifier 。
`#ifndef` identifier is essentially equivalent to `#if !defined` identifier.
#ifndef identifier 本質上等價於 #if !defined identifier 。

`#elifdef` identifier is essentially equivalent to `#elif defined` identifier.
`#elifndef` identifier is essentially equivalent to `#elif !defined` identifier.
|   | (since C23) |

### Notes

While `#elifdef` and `#elifndef` directives target C23, implementations may backport them to the older language modes as conforming extensions.
雖然 #elifdef 和 #elifndef 指令面向 C23，但實現可以將它們作為符合性擴充套件回移植到較舊的語言模式。

### Example

Run this code

```c
#define ABCD 2 #include <stdio.h> int main(void) { #ifdef ABCD  printf("1: yes\n"); #else  printf("1: no\n"); #endif #ifndef ABCD  printf("2: no1\n"); #elif ABCD == 2  printf("2: yes\n"); #else  printf("2: no2\n"); #endif #if !defined(DCBA) && (ABCD < 2 * 4 - 3)  printf("3: yes\n"); #endif // C23 directives #elifdef/#elifndef #ifdef CPU  printf("4: no1\n"); #elifdef GPU  printf("4: no2\n"); #elifndef RAM  printf("4: yes\n"); // selected in C23 mode, may be selected in pre-C23 mode #else  printf("4: no3\n"); // may be selected in pre-C23 mode #endif }
```

Possible output:
可能的輸出：

```c
1: yes 2: yes 3: yes 4: yes
```

### Defect reports

The following behavior-changing defect reports were applied retroactively to previously published C standards.
下列缺陷報告所作的行為變更，已追溯套用至先前發布的 C 標準。

| DR  |   | Applied to  |   | Behavior as published  |   | Correct behavior  |

| DR 412  |   | C89  |   | failed `#elif`'s expression was required to be valid  |   | failed `#elif` is skipped  |

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.10.1 Conditional inclusion (p: TBD)
6.10.1 條件包含 (p: TBD)
6.10.1 條件包含 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.10.1 Conditional inclusion (p: 118-119)
6.10.1 條件包含 (p: 118-119)
6.10.1 條件包含 (p: 118-119)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.10.1 Conditional inclusion (p: 162-164)
6.10.1 條件包含 (p: 162-164)
6.10.1 條件包含 (p: 162-164)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.10.1 Conditional inclusion (p: 147-149)
6.10.1 條件包含 (p: 147-149)
6.10.1 條件包含 (p: 147-149)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.8.1 Conditional inclusion
3.8.1 條件包含
3.8.1 條件包含

### See also

C++ documentation for Conditional inclusion

---
來源頁路徑：`en.cppreference.com/c/preprocessor/conditional.html`
