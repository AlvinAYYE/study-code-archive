# Inline assembly

> 來源：cppreference C 語言參考文件（離線轉換版）。

Inline assembly (typically introduced by the `asm` keyword) gives the ability to embed assembly language source code within a C program.
內聯彙編（通常由 asm 關鍵字引入）提供了在 C 程式中嵌入組合語言原始碼的能力。
Unlike in C++, inline assembly is treated as an extension in C. It is conditionally supported and implementation defined, meaning that it may not be present and, even when provided by the implementation, it does not have a fixed meaning.
與 C++ 不同，在 C 中內聯彙編被視為擴充套件。它是有條件支援的且為實現定義的，這意味著它可能不存在，即使由實現提供，也沒有固定的含義。

### Syntax

|   |

| `**asm (**` string_literal `**)**` `**;**`  |   |   |   |   |

|   |

|  | This section is incomplete
Reason: write a note on GCC extended assembly syntax, since it is now supported by Intel, IBM, Sun (as of v12), etc  |

### Explanation

This kind of inline assembly syntax is accepted by the C++ standard and called *asm-declaration* in C++. The string_literal is typically a short program written in assembly language, which is executed whenever this declaration is executed. Different C compilers have wildly varying rules for asm-declarations, and different conventions for the interaction with the surrounding C code.
這種內聯彙編語法被 C++ 標準接受，在 C++ 中稱為 asm-declaration。string_literal 通常是用組合語言編寫的短程式，每當執行該宣告時就會執行。不同的 C 編譯器對 asm-declaration 有截然不同的規則，以及與周圍 C 程式碼互動的不同約定。
asm-declaration can appear inside a block (a function body or another compound statement), and, as all other declarations, this declaration can also appear outside a block.
asm-declaration 可以出現在塊內（函式體或其他複合陳述式），並且，與所有其他宣告一樣，該宣告也可以出現在塊外。

### Notes

MSVC does not support inline assembly on the ARM and x64 processors, and only support the form introduced by `__asm` on x86 processors.
MSVC 不支援在 ARM 和 x64 處理器上的內聯彙編，僅支援在 x86 處理器上由 __asm 引入的形式。
When compiling in ISO C mode by GCC or Clang (e.g. with option `-std=c11`), `__asm__` must be used instead of `asm`.
當使用 GCC 或 Clang 以 ISO C 模式編譯時（例如使用選項 - std = c11），必須使用 __asm__ 而不是 asm。

### Examples

Demonstrates two kinds of inline assembly syntax offered by the GCC compiler. This program will only work correctly on x86-64 platform under Linux. Note that the "standard inline assembly" is also treated as an extension in the C standard.
演示 GCC 編譯器提供的兩種內聯彙編語法。該程式僅在 Linux 下的 x86-64 平臺上才能正確執行。注意，"standard inline assembly" 在 C 標準中也被視為擴充套件。
Run this code

```c
#include <stdio.h> extern int func(void); // the definition of func is written in assembly language __asm__(".globl func\n\t"  ".type func, @function\n\t"  "func:\n\t"  ".cfi_startproc\n\t"  "movl $7, %eax\n\t"  "ret\n\t"  ".cfi_endproc"); int main(void) {  int n = func();  // gcc's extended inline assembly  __asm__ ("leal (%0,%0,4),%0"  : "=r" (n)  : "0" (n));  printf("7*5 = %d\n", n);  fflush(stdout); // flush is intentional  // standard inline assembly in C++  __asm__ ("movq $60, %rax\n\t" // the exit syscall number on Linux  "movq $2, %rdi\n\t" // this program returns 2  "syscall"); }
```

Output:

```c
7*5 = 35
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- J.5.10 The asm keyword (p: TBD)
J.5.10 asm 關鍵字 (p: TBD)
J.5.10 asm 關鍵字 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- J.5.10 The asm keyword (p: 422)
J.5.10 asm 關鍵字 (p: 422)
J.5.10 asm 關鍵字 (p: 422)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- J.5.10 The asm keyword (p: 580)
J.5.10 asm 關鍵字 (p: 580)
J.5.10 asm 關鍵字 (p: 580)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- J.5.10 The asm keyword (p: 512)
J.5.10 asm 關鍵字 (p: 512)
J.5.10 asm 關鍵字 (p: 512)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- G.5.10 The asm keyword
G.5.10 asm 關鍵字
G.5.10 asm 關鍵字

### See also

C++ documentation for `asm` declaration

### External links

| 1.  |   | GCC Inline Assembly HOWTO  |

| 2.  |   | IBM XL C/C++ Inline Assembly  |

| 3.  |   | Intel C++ Inline Assembly  |

| 4.  |   | Visual Studio Inline Assembler  |

| 5.  |   | Sun Studio 12 Asm Statements  |

| 6.  |   | Inline assembly for Itanium-based HP-UX  |

---
來源頁路徑：`en.cppreference.com/c/language/asm.html`
