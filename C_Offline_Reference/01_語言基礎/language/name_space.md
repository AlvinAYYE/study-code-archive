# Lookup and name spaces

> 來源：cppreference C 語言參考文件（離線轉換版）。

When an identifier is encountered in a C program, a lookup is performed to locate the declaration that introduced that identifier and that is currently in scope. C allows more than one declaration for the same identifier to be in scope simultaneously if these identifiers belong to different categories, called *name spaces*:
在 C 程式中遇到識別符號時，會執行查詢以定位引入該識別符號且目前處於作用域中的宣告。如果同一識別符號屬於不同的類別（稱為名字空間），C 允許同一識別符號的多個宣告同時處於作用域中：

1) Label name space: all identifiers declared as labels.

2) Tag names: all identifiers declared as names of structs, unions and enumerated types. Note that all three kinds of tags share one name space.

3) Member names: all identifiers declared as members of any one struct or union. Every struct and union introduces its own name space of this kind.

4) Global attribute name space: attribute tokens defined by the standard or implementation-defined attribute prefixes.

5) Non-standard attribute names: attribute names following attribute prefixes. Each attribute prefix has a separate name space for the implementation-defined attributes it introduces.
|   | (since C23) |

6) All other identifiers, called *ordinary identifiers* to distinguish from (1-5) (function names, object names, typedef names, enumeration constants).

At the point of lookup, the name space of an identifier is determined by the manner in which it is used:
在查詢時，識別符號的名字空間由其使用方式決定：

1) identifier appearing as the operand of a goto statement is looked up in the label name space.

2) identifier that follows the keyword `struct`, `union`, or `enum` is looked up in the tag name space.

3) identifier that follows the member access or member access through pointer operator is looked up in the name space of members of the type determined by the left-hand operand of the member access operator.

4) identifier that directly appears in an attribute specifier (`[[...]]`) is looked up in the global attribute name space.

5) identifier that follows the `::` token following an attribute prefix is looked in the name space introduced by the attribute prefix.
|   | (since C23) |

6) all other identifiers are looked up in the name space of ordinary identifiers.

### Notes

The names of macros are not part of any name space because they are replaced by the preprocessor prior to semantic analysis.
宏名不屬於任何名字空間，因為它們在語意分析之前就被前處理器替換了。
It is common practice to inject struct/union/enum names into the name space of the ordinary identifiers using a typedef declaration:
通常的做法是使用 typedef 宣告將 struct/union/enum 名注入普通識別符號的名字空間：

```c
struct A { }; // introduces the name A in tag name space typedef struct A A; // first, lookup for A after "struct" finds one in tag name space  // then introduces the name A in the ordinary name space struct A* p; // OK, this A is looked up in the tag name space A* q; // OK, this A is looked up in the ordinary name space
```

A well-known example of the same identifier being used across two name spaces is the identifier `stat` from the POSIX header `sys/stat.h`. It names a function when used as an ordinary identifier and indicates a struct when used as a tag.
同一識別符號在兩個名字空間中使用的著名例子是 POSIX 標頭檔 sys/stat.h 中的識別符號 stat 。作為普通識別符號使用時它命名一個函式，作為標籤使用時它表示一個 struct 。
Unlike in C++, enumeration constants are not struct members, and their name space is the name space of ordinary identifiers, and since there is no struct scope in C, their scope is the scope in which the struct declaration appears:
與 C++ 不同，列舉常量不是 struct 成員，它們的名字空間是普通識別符號的名字空間，並且由於 C 中沒有 struct 作用域，它們的作用域是 struct 宣告出現的作用域：

```c
struct tagged_union {  enum {INT, FLOAT, STRING} type;  union {  int integer;  float floating_point;  char *string;  }; } tu; tu.type = INT; // OK in C, error in C++
```

If a standard attribute, an attribute prefix, or a non-standard attribute name is not supported, the invalid attribute itself is ignored without causing an error.
|   | (since C23) |

### Example

Run this code

```c
void foo (void) { return; } // ordinary name space, file scope struct foo { // tag name space, file scope  int foo; // member name space for this struct foo, file scope  enum bar { // tag name space, file scope  RED // ordinary name space, file scope  } bar; // member name space for this struct foo, file scope  struct foo* p; // OK: uses tag/file scope name "foo" }; enum bar x; // OK: uses tag/file-scope bar // int foo; // Error: ordinary name space foo already in scope  //union foo { int a, b; }; // Error: tag name space foo in scope int main(void) {  goto foo; // OK uses "foo" from label name space/function scope  struct foo { // tag name space, block scope (hides file scope)  enum bar x; // OK, uses "bar" from tag name space/file scope  };  typedef struct foo foo; // OK: uses foo from tag name space/block scope  // defines block-scope ordinary foo (hides file scope)  (foo){.x=RED}; // uses ordinary/block-scope foo and ordinary/file-scope RED foo:; // label name space, function scope }
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.2.3 Name spaces of identifiers (p: 29-30)
6.2.3 識別符號的名字空間 (p: 29-30)
6.2.3 識別符號的名字空間 (p: 29-30)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.2.3 Name spaces of identifiers (p: 37)
6.2.3 識別符號的名字空間 (p: 37)
6.2.3 識別符號的名字空間 (p: 37)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.2.3 Name spaces of identifiers (p: 31)
6.2.3 識別符號的名字空間 (p: 31)
6.2.3 識別符號的名字空間 (p: 31)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.1.2.3 Name spaces of identifiers
3.1.2.3 識別符號的名字空間
3.1.2.3 識別符號的名字空間

### See also

C++ documentation for Name lookup

---
來源頁路徑：`en.cppreference.com/c/language/name_space.html`
