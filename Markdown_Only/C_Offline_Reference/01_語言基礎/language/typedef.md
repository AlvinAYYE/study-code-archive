# Typedef declaration

> 來源：cppreference C 語言參考文件（離線轉換版）。

The *typedef declaration* provides a way to declare an identifier as a type alias, to be used to replace a possibly complex type name
typedef 宣告提供了一種將識別符號宣告為型別別名的方法，可用於替換可能複雜的型別名
The keyword `typedef` is used in a declaration, in the grammatical position of a storage-class specifier, except that it does not affect storage or linkage:
關鍵字 typedef 用於宣告中，位於儲存類說明符的語法位置，但它不影響儲存或連結：

```c
typedef int int_t; // declares int_t to be an alias for the type int typedef char char_t, *char_p, (*fp)(void); // declares char_t to be an alias for char  // char_p to be an alias for char*  // fp to be an alias for char(*)(void)
```

### Explanation

If a declaration uses `typedef` as storage-class specifier, every declarator in it defines an identifier as an alias to the type specified. Since only one storage-class specifier is permitted in a declaration, typedef declaration cannot be static or extern.
如果宣告使用 typedef 作為儲存類說明符，則其中的每個宣告器都將一個識別符號定義為所指定型別的別名。由於一個宣告中只允許有一個儲存類說明符，typedef 宣告不能是 static 或 extern。
typedef declaration does not introduce a distinct type, it only establishes a synonym for an existing type, thus typedef names are compatible with the types they alias. Typedef names share the name space with ordinary identifiers such as enumerators, variables and function.
typedef 宣告不會引入一個不同的型別，它只是為現有型別建立起一個同義詞，因此 typedef 名與它們所別名的型別相容。typedef 名與列舉常量、變數和函式等普通識別符號共享名稱空間。

A typedef for a VLA can only appear at block scope. The length of the array is evaluated each time the flow of control passes over the typedef declaration, as opposed to the declaration of the array itself:

```c
void copyt(int n) {  typedef int B[n]; // B is a VLA, its size is n, evaluated now  n += 1;  B a; // size of a is n from before +=1  int b[n]; // a and b are different sizes  for (int i = 1; i < n; i++)  a[i-1] = b[i]; }
```
|   | (since C99) |

### Notes

typedef name may be an incomplete type, which may be completed as usual:
typedef 名可以是不完整型別，它可以像往常一樣被補全：

```c
typedef int A[]; // A is int[] A a = {1, 2}, b = {3,4,5}; // type of a is int[2], type of b is int[3]
```

typedef declarations are often used to inject names from the tag name space into the ordinary name space:
typedef 宣告常用於把名稱從標籤名稱空間注入到普通名稱空間中：

```c
typedef struct tnode tnode; // tnode in ordinary name space  // is an alias to tnode in tag name space struct tnode {  int count;  tnode *left, *right; // same as struct tnode *left, *right; }; // now tnode is also a complete type tnode s, *sp; // same as struct tnode s, *sp;
```

They can even avoid using the tag name space at all:
它們甚至可以完全避免使用標籤名稱空間：

```c
typedef struct { double hi, lo; } range; range z, *zp;
```

Typedef names are also commonly used to simplify the syntax of complex declarations:
typedef 名也常用於簡化複雜宣告的語法：

```c
// array of 5 pointers to functions returning pointers to arrays of 3 ints int (*(*callbacks[5])(void))[3]; // same with typedefs typedef int arr_t[3]; // arr_t is array of 3 int typedef arr_t* (*fp)(void); // pointer to function returning arr_t* fp callbacks[5];
```

Libraries often expose system-dependent or configuration-dependent types as typedef names, to present a consistent interface to the users or to other library components:
庫經常把依賴系統或依賴配置的型別暴露為 typedef 名，以便向使用者或其他庫元件提供一致的介面：

```c
#if defined(_LP64) typedef int wchar_t; #else typedef long wchar_t; #endif
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.7.8 Type definitions (p: TBD)
6.7.8 型別定義（p: TBD）
6.7.8 型別定義（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.7.8 Type definitions (p: TBD)
6.7.8 型別定義（p: TBD）
6.7.8 型別定義（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.7.8 Type definitions (p: 137-138)
6.7.8 型別定義（p: 137-138）
6.7.8 型別定義（p: 137-138）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.7.7 Type definitions (p: 123-124)
6.7.7 型別定義（p: 123-124）
6.7.7 型別定義（p: 123-124）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.5.6 Type definitions
3.5.6 型別定義
3.5.6 型別定義

### Keywords

typedef

### See also

C++ documentation for `typedef` declaration

---
來源頁路徑：`en.cppreference.com/c/language/typedef.html`
