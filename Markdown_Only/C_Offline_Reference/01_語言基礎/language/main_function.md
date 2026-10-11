# Main function

> 來源：cppreference C 語言參考文件（離線轉換版）。

Every C program coded to run in a hosted execution environment contains the definition (not the prototype) of a function named `**main**`, which is the designated start of the program.
每個為在託管執行環境中執行而編寫的 C 程式都包含一個名為 main 的函式的定義（而非原型），它是程式的指定起點。

|   |

| `int` `**main**` `**(void)**` `**{**` body `**}**`  |   | (1)  |   |   |

|   |

| `int` `**main**` `**(**``int` argc`**,**` `char` `*`argv`[]``**)**` `**{**` body `**}**`  |   | (2)  |   |   |

|   |

| `/* another implementation-defined signature */` (since C99)  |   | (3)  |   |   |

|   |

### Parameters

| argc  |   | -  |   | Non-negative value representing the number of arguments passed to the program from the environment in which the program is run.  |

| argv  |   | -  |   | Pointer to the first element of an array of `argc + 1` pointers, of which the last one is null and the previous ones, if any, point to strings that represent the arguments passed to the program from the host environment. If `argv[0]` is not a null pointer (or, equivalently, if `argc` > 0), it points to a string that represents the program name, which is empty if the program name is not available from the host environment.  |

The names `argc` and `argv` stand for "argument count" and "argument vector", and are traditionally used, but other names may be chosen for the parameters, as well as different but equivalent declarations of their type: `int main(int ac, char** av)` is equally valid.
名稱 argc 和 argv 代表 "argument count"（參數個數）和 "argument vector"（參數向量），是傳統用法，但參數可以選擇其他名稱，也可以使用不同但等價的型別宣告：int main ( int ac , char ** av ) 同樣有效。
A common implementation-defined form of main is `int main(int argc, char *argv[], char *envp[])`, where a third argument, of type `char**`, pointing at an array of pointers to the *execution environment variables*, is added.
main 的一個常見實現定義形式是 int main ( int argc , char * argv [], char * envp []) ，其中新增了第三個型別為 char ** 的參數，指向指向執行環境變數的指標陣列。

### Return value

If the return statement is used, the return value is used as the argument to the implicit call to exit() (see below for details). The values zero and EXIT_SUCCESS indicate successful termination, the value EXIT_FAILURE indicates unsuccessful termination.
如果使用 return 陳述式，傳回值用作對 exit() 的隱式呼叫的參數（詳見下文）。值 zero 和 EXIT_SUCCESS 表示成功終止，值 EXIT_FAILURE 表示不成功終止。

### Explanation

The `main` function is called at program startup, after all objects with static storage duration are initialized. It is the designated entry point to a program that is executed in a *hosted* environment (that is, with an operating system). The name and type of the entry point to any *freestanding* program (boot loaders, OS kernels, etc) are implementation-defined.
main 函式在程式啟動時呼叫，在所有具有靜態儲存期的物件初始化之後。它是託管環境（即有作業系統）中執行的程式的指定入口點。任何獨立程式（引導載入程式、作業系統核心等）的入口點的名稱和型別是實現定義的。
The parameters of the two-parameter form of the main function allow arbitrary multibyte character strings to be passed from the execution environment (these are typically known as *command line arguments*). The pointers `argv[1] .. argv[argc-1]` point at the first characters in each of these strings. `argv[0]` (if non-null) is the pointer to the initial character of a null-terminated multibyte string that represents the name used to invoke the program itself (or, if this is not supported by the host environment, `argv[0][0]` is guaranteed to be zero).
main 函式雙參數形式的參數允許從執行環境傳遞任意多位元組字串（這些通常稱為命令列參數）。指標 argv [ 1 ] .. argv [ argc -1 ] 指向這些字串中的第一個字元。argv [ 0 ]（如果非空）是指向以空字元結尾的多位元組字串首字元的指標，該字串表示用於呼叫程式本身的名稱（或者，如果宿主環境不支援此功能，則保證 argv [ 0 ][ 0 ] 為零）。
If the host environment cannot supply both lowercase and uppercase letters, the command line arguments are converted to lowercase.
如果宿主環境不能同時提供小寫和大寫字母，則命令列參數被轉換為小寫。
The strings are modifiable, and any modifications made persist until program termination, although these modifications do not propagate back to the host environment: they can be used, for example, with strtok.
這些字串是可修改的，所做的任何修改都會持續到程式終止，儘管這些修改不會傳播回宿主環境：例如，它們可以與 strtok 一起使用。
The size of the array pointed to by `argv` is at least `argc+1`, and the last element, `argv[argc]`, is guaranteed to be a null pointer.
argv 指向的陣列大小至少為 argc+1 ，最後一個元素 argv[argc] 保證是空指標。
The `main` function has several special properties:
main 函式有幾個特殊屬性：

1) A prototype for this function cannot be supplied by the program.

2) If the return type of the main function is compatible with `int`, then the return from the initial call to main (but not the return from any subsequent, recursive, call) is equivalent to executing the exit function, with the value that the main function is returning passed as the argument (which then calls the functions registered with atexit, flushes and closes all streams, and deletes the files created with tmpfile, and returns control to the execution environment).

3)

If the main function executes a `return` that specifies no value or, which is the same, reaches the terminating `}` without executing a `return`, the termination status returned to the host environment is undefined.
|   | (until C99) |

If the return type of the main function is not compatible with `int` (e.g. `void main(void)`), the value returned to the host environment is unspecified. If the return type is compatible with `int` and control reaches the terminating `}`, the value returned to the environment is the same as if executing `return 0;`.
|   | (since C99) |

### Example

Demonstrates how to inform a program about where to find its input and where to write its results. Invocation: ./a.out indatafile outdatafile
演示如何告知程式在哪裡找到其輸入以及在哪裡寫入其結果。 呼叫方式：./a.out indatafile outdatafile
Run this code

```c
#include <stdio.h> int main(int argc, char *argv[]) {  printf("argc = %d\n", argc);  for (int ndx = 0; ndx != argc; ++ndx)  printf("argv[%d] --> %s\n", ndx, argv[ndx]);  printf("argv[argc] = %p\n", (void*)argv[argc]); }
```

Possible output:
可能的輸出：

```c
argc = 3 argv[0] --> ./a.out argv[1] --> indatafile argv[2] --> outdatafile argv[argc] = (nil)
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 5.1.2.2.1 Program startup (p: TBD)
5.1.2.2.1 程式啟動（第 TBD 頁）
5.1.2.2.1 程式啟動（第 TBD 頁）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 5.1.2.2.1 Program startup (p: 10-11)
5.1.2.2.1 程式啟動（第 10-11 頁）
5.1.2.2.1 程式啟動（第 10-11 頁）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 5.1.2.2.1 Program startup (p: 13)
5.1.2.2.1 程式啟動（第 13 頁）
5.1.2.2.1 程式啟動（第 13 頁）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 5.1.2.2.1 Program startup (p: 12)
5.1.2.2.1 程式啟動（第 12 頁）
5.1.2.2.1 程式啟動（第 12 頁）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 5.1.2.2 Hosted environment
5.1.2.2 託管環境
5.1.2.2 託管環境

### See also

C++ documentation for `main` function

---
來源頁路徑：`en.cppreference.com/c/language/main_function.html`
