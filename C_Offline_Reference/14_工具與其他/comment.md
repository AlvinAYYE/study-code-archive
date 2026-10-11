# Comments

> 來源：cppreference C 語言參考文件（離線轉換版）。

Comments serve as a sort of in-code documentation. When inserted into a program, they are effectively ignored by the compiler; they are solely intended to be used as notes by the humans that read source code.
註釋充當一種程式碼內檔案。插入程式後，編譯器實際上會忽略它們；它們僅供閱讀原始碼的人用作筆記。

### Syntax

|   |

| `**/***` comment `***/**`  |   | (1)  |   |   |

|   |

| `**//**` comment  |   | (2)  |   | (since C99)  |

|   |

1) Often known as "C-style" or "multi-line" comments.

2) Often known as "C++-style" or "single-line" comments.

All comments are removed from the program at translation phase 3 by replacing each comment with a single whitespace character.
在翻譯階段 3 中，所有註釋都會從程式中移除，方法是將每個註釋替換為單個空白字元。

### C-style

C-style comments are usually used to comment large blocks of text or small fragments of code; however, they can be used to comment single lines. To insert text as a C-style comment, simply surround the text with `/*` and `*/`. C-style comments tell the compiler to ignore all content between `/*` and `*/`. Although it is not part of the C standard, `/**` and `**/` are often used to indicate documentation blocks; this is legal because the second asterisk is simply treated as part of the comment.
C 風格註釋通常用於註釋大段文字或小段程式碼；但也可用於註釋單行。要將文字插入為 C 風格註釋，只需用 /* 和 */ 將文字包圍起來。C 風格註釋告訴編譯器忽略 /* 和 */ 之間的所有內容。雖然這不是 C 標準的一部分，但 /** 和 **/ 常用於表示檔案塊；這是合法的，因為第二個星號僅被視為註釋的一部分。
Except within a character constant, a string literal, or a comment, the characters `/*` introduce a comment. The contents of such a comment are examined only to identify multibyte characters and to find the characters `*/` that terminate the comment. C-style comments cannot be nested.
除非在字元常量、字串字面量或註釋內，字元 /* 引入一個註釋。此類註釋的內容僅用於識別多位元組字元和查詢終止註釋的字元 */ 。C 風格註釋不能巢狀。

### C++-style

C++-style comments are usually used to comment single lines of text or code; however, they can be placed together to form multi-line comments. To insert text as a C++-style comment, simply precede the text with `//` and follow the text with the new line character. C++-style comments tell the compiler to ignore all content between `//` and a new line.
Except within a character constant, a string literal, or a comment, the characters `//` introduce a comment that includes all multibyte characters up to, but not including, the next new-line character. The contents of such a comment are examined only to identify multibyte characters and to find the new-line character that terminates the comment. C++-style comments can be nested:

```c
// y = f(x); // invoke algorithm
```

A C-style comment may appear within a C++-style comment:

```c
// y = f(x); /* invoke algorithm */
```

A C++-style comment may appear within a C-style comment; this is a mechanism for excluding a small block of source code:

```c
/*  y = f(x); // invoke algorithms  z = g(x); */
```
|   | (since C99) |

### Notes

Because comments are removed before the preprocessor stage, a macro cannot be used to form a comment and an unterminated C-style comment doesn't spill over from an #include'd file.
由於註釋在預處理階段之前就被移除，宏不能用於構成註釋，且未結束的 C 風格註釋不會從 #include 包含的檔案蔓延過來。

```c
/* An attempt to use a macro to form a comment. */ /* But, a space replaces characters "//". */ #ifndef DEBUG  #define PRINTF // #else  #define PRINTF printf #endif ...  PRINTF("Error in file %s at line %i\n", __FILE__, __LINE__);
```

Besides commenting out, other mechanisms used for source code exclusion are:
除了註釋掉之外，用於排除原始碼的其他機制有：

```c
#if 0  puts("this will not be compiled");  /* no conflict with C-style comments */  // no conflict with C++-style comments #endif
```

and

```c
if(0) {  puts("this will be compiled but not be executed");  /* no conflict with C-style comments */  // no conflict with C++-style comments }
```

The introduction of // comments in C99 was a breaking change in some rare circumstances:
C99 中引入 // 註釋在極少數情況下是一個破壞性變更：

```c
a = b //*divisor:*/ c + d; /* C89 compiles a = b / c + d;  C99 compiles a = b + d; */
```

### Example

Run this code

```c
#include <stdio.h> /* C-style comments can contain multiple lines. */   /* Or, just one line. */   // C++-style comments can comment one line.   // Or, they can // be strung together.   int main(void) {  // The below code won't be run  // puts("Hello");    // The below code will be run  puts("World");  // A note regarding backslash + newline.  // Despite belonging to translation phase 2 (vs phase 3 for comments),  // '\' still determines which portion of the source code is considered  // as 'comments':  // This comment will be promoted to the next line \  puts("Won't be run"); // may issue a warning "multi-line comment"  puts("Hello, again"); }
```

Output:

```c
World Hello, again
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.4.9 Comments (p: 54)
6.4.9 註釋（頁碼：54）
6.4.9 註釋（頁碼：54）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.4.9 Comments (p: 75)
6.4.9 註釋（頁碼：75）
6.4.9 註釋（頁碼：75）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.4.9 Comments (p: 66)
6.4.9 註釋（頁碼：66）
6.4.9 註釋（頁碼：66）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.1.9 Comments

### See also

C++ documentation for Comments

---
來源頁路徑：`en.cppreference.com/c/comment.html`
