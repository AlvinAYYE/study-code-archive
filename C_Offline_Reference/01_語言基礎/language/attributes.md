# Attribute specifier sequence(since C23)

> 來源：cppreference C 語言參考文件（離線轉換版）。

Introduces implementation-defined attributes for types, objects, expressions, etc.
引入用於型別、物件、表示式等的實現定義屬性。

### Syntax

`**[[**`attr ﻿`**]]**` `**[[**`attr1, attr2, attr3`**(**`args`**)**``**]]**` `**[[**`attribute-prefix`**::**`attr ﻿`**(**`args`**)**``**]]**`
[[ attr ﻿ ]] [[ attr1 , attr2 , attr3 ( args ) ]] [[ attribute-prefix :: attr ﻿ ( args ) ]]

Formally, the syntax is
形式上，語法為

|   |

| `**[[**` attribute-list `**]]**`  |   |   |   | (since C23)  |

|   |

where attribute-list is a comma-separated sequence of zero or more attribute-token ﻿s
其中 attribute-list 是由零個或多個 attribute-token ﻿ 組成的以逗號分隔的序列

|   |

| standard-attribute  |   | (1)  |   |   |

|   |

| attribute-prefix `**::**` identifier  |   | (2)  |   |   |

|   |

| standard-attribute `**(**` argument-list ﻿(optional) `**)**`  |   | (3)  |   |   |

|   |

| attribute-prefix `**::**` identifier `**(**` argument-list ﻿(optional) `**)**`  |   | (4)  |   |   |

|   |

where attribute-prefix is an identifier and argument-list is a sequence of tokens where parentheses, brackets and braces are balanced (balanced-token-sequence).
其中 attribute-prefix 是一個識別符號，argument-list 是一個令牌序列，其中圓括號、方括號和花括號是配對的（balanced-token-sequence）。

1) standard attribute, such as `[[fallthrough]]`

2) attribute with a namespace, such as `[[gnu::unused]]`

3) standard attribute with arguments, such as `[[deprecated("reason")]]`

4) attribute with both a namespace and an argument list, such as `[[gnu::nonnull(1)]]`

### Explanation

Attributes provide the unified standard syntax for implementation-defined language extensions, such as the GNU and IBM language extensions `__attribute__((...))`, Microsoft extension `__declspec()`, etc.
屬性為實現定義的語言擴充套件提供了統一的標準語法，例如 GNU 和 IBM 語言擴充套件 __attribute__((...))、Microsoft 擴充套件 __declspec() 等。
An attribute can be used almost everywhere in the C program, and can be applied to almost everything: to types, to variables, to functions, to names, to code blocks, to entire translation units, although each particular attribute is only valid where it is permitted by the implementation: `[[expect_true]]` could be an attribute that can only be used with an `if`, and not with a class declaration. `[[omp::parallel()]]` could be an attribute that applies to a code block or to a `for` loop, but not to the type `int`, etc. (note these two attributes are fictional examples, see below for the standard and some non-standard attributes)
屬性幾乎可以在 C 程式中的任何地方使用，並且幾乎可以應用於任何東西：型別、變數、函式、名稱、程式碼塊、整個翻譯單元，儘管每個特定屬性只在實現允許的地方有效：[[expect_true]] 可能是隻能與 if 一起使用、而不能與類宣告一起使用的屬性。[[omp::parallel()]] 可能是應用於程式碼塊或 for 迴圈、而不是型別 int 的屬性，等等（注意這兩個屬性是虛構的示例，有關標準屬性和一些非標準屬性見下文）
In declarations, attributes may appear both before the whole declaration and directly after the name of the entity that is declared, in which case they are combined. In most other situations, attributes apply to the directly preceding entity.
在宣告中，屬性既可以出現在整個宣告之前，也可以直接出現在被宣告實體的名稱之後，在這種情況下它們會被合併。在大多數其他情況下，屬性應用於緊鄰的前一個實體。
Two consecutive left square bracket tokens (`[[`) may only appear when introducing an attribute-specifier or inside an attribute argument.
兩個連續的左方括號令牌（[[）只能在引入 attribute-specifier 或在屬性參數內部時出現。
Besides the standard attributes listed below, implementations may support arbitrary non-standard attributes with implementation-defined behavior. All attributes unknown to an implementation are ignored without causing an error.
除了下面列出的標準屬性外，實現可以支援具有實現定義行為的任意非標準屬性。實現未知的所有屬性都會被忽略，不會引發錯誤。
Every standard-attribute is reserved for standardization. That is, every non-standard attribute is prefixed by a attribute-prefix provided by the implementation, e.g. `[[gnu::may_alias]]` and `[[clang::no_sanitize]]`.
每個 standard-attribute 都保留用於標準化。也就是說，每個非標準屬性都帶有實現提供的 attribute-prefix 字首，例如 [[gnu::may_alias]] 和 [[clang::no_sanitize]]。

### Standard attributes
標準屬性

Only the following attributes are defined by the C standard. Every standard attribute whose name is of form `attr` can be also spelled as `__attr__` and its meaning is not changed.
只有以下屬性由 C 標準定義。名稱為 attr 形式的每個標準屬性也可以寫成 __attr__，其含義不變。

`[[deprecated]]`(C23)`[[deprecated("*reason*")]]`(C23)
{{{notes}}}
|   | indicates that the use of the name or entity declared with this attribute is allowed, but discouraged for some reason
(attribute specifier)  |

`[[fallthrough]]`
(C23)
|   | indicates that the fall through from the previous case label is intentional and should not be diagnosed by a compiler that warns on fall-through
(attribute specifier)  |

`[[nodiscard]]`(C23)`[[nodiscard("*reason*")]]`(C23)
{{{notes}}}
|   | encourages the compiler to issue a warning if the return value is discarded
(attribute specifier)  |

`[[maybe_unused]]`
(C23)
|   | suppresses compiler warnings on unused entities, if any
(attribute specifier)  |

`[[noreturn]]`(C23)`[[_Noreturn]]`(C23)(deprecated)
{{{notes}}}
|   | indicates that the function does not return
(attribute specifier)  |

`[[unsequenced]]`
(C23)
|   | indicates that a function is stateless, effectless, idempotent and independent
(attribute specifier)  |

`[[reproducible]]`
(C23)
|   | indicates that a function is effectless and idempotent
(attribute specifier)  |

### Attribute testing
屬性測試

|   |

| `**__has_c_attribute(**` attribute-token `**)**`  |   |   |   |   |

|   |

Checks for the presence of an attribute token named by attribute-token.
檢查是否存在名為 attribute-token 的屬性令牌。
For standard attributes, it will expand to the year and month in which the attribute was added to the working draft (see table below), the presence of vendor-specific attributes is determined by a non-zero integer constant.
對於標準屬性，它將展開為該屬性被加入工作草案的年份和月份（見下表）；供應商特定屬性的存在由一個非零整數常量決定。
`__has_c_attribute` can be expanded in the expression of  #if and  #elif. It is treated as a defined macro by  #ifdef,  #ifndef and defined but cannot be used anywhere else.
__has_c_attribute 可以在 #if 和 #elif 的表示式中展開。 它被 #ifdef、#ifndef 和 defined 視為已定義的宏，但不能在其他任何地方使用。

| attribute-token  |   | Attribute  |   | Value  |   | Standard  |

| `deprecated`  |   | `[[deprecated]]`  |   | `201904L`  |   | (C23)  |

| `fallthrough`  |   | `[[fallthrough]]`  |   | `201904L`  |   | (C23)  |

| `maybe_unused`  |   | `[[maybe_unused]]`  |   | `201904L`  |   | (C23)  |

| `nodiscard`  |   | `[[nodiscard]]`  |   | `202003L`  |   | (C23)  |

| `noreturn`
`_Noreturn`  |   | `[[noreturn]]`
`[[_Noreturn]]`  |   | `202202L`  |   | (C23)  |

| `unsequenced`  |   | `[[unsequenced]]`  |   | `202207L`  |   | (C23)  |

| `reproducible`  |   | `[[reproducible]]`  |   | `202207L`  |   | (C23)  |

### Example

Run this code

```c
[[gnu::hot]] [[gnu::const]] [[nodiscard]] int f(void); // declare f with three attributes [[gnu::const, gnu::hot, nodiscard]] int f(void); // the same as above, but uses a single attr  // specifier that contains three attributes int f(void) { return 0; } int main(void) { }
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.7.12 Attributes (p: TBD)
6.7.12 屬性 (p: TBD)
6.7.12 屬性 (p: TBD)

### See also

C++ documentation for Attribute specifier sequence

### External links

| 1.  |   | Attributes in GCC  |

| 2.  |   | Attributes in Clang  |

---
來源頁路徑：`en.cppreference.com/c/language/attributes.html`
