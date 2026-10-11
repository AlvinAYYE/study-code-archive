# Binary resource inclusion (since C23)

> 來源：cppreference C 語言參考文件（離線轉換版）。

`#embed` is a preprocessor directive to include (binary) resources in the build, where a resource is defined as a source of data accessible from the translation environment.
#embed 是前處理器指令，可在建置程式時納入（二進位）資源。此處的資源是指翻譯環境可存取的資料來源。

### Syntax

|   |

| `**#embed <**` h-char-sequence `**>**` embed-parameter-sequence ﻿(optional) new-line  |   | (1)  |   |   |

|   |

| `**#embed "**` q-char-sequence `**"**` embed-parameter-sequence ﻿(optional) new-line  |   | (2)  |   |   |

|   |

| `**#embed**` pp-tokens new-line  |   | (3)  |   |   |

|   |

| `**__has_embed**` `**(**` `**"**` q-char-sequence `**"**` embed-parameter-sequence ﻿(optional) `**)**`
`**__has_embed**` `**(**` `**<**` h-char-sequence `**>**` embed-parameter-sequence ﻿(optional) `**)**`  |   | (4)  |   |   |

|   |

| `**__has_embed**` `**(**` string-literal pp-balanced-token-sequence ﻿(optional) `**)**`
`**__has_embed**` `**(**` `**<**` h-pp-tokens `**>**` pp-balanced-token-sequence ﻿(optional) `**)**`  |   | (5)  |   |   |

|   |

1) Searches for a resource identified uniquely by h-char-sequence and replaces the directive by a comma separated list of integers corresponding to the data of the resource.

2) Searches for a resource identified by q-char-sequence and replaces the directive by a list of integers corresponding to the data of the resource. It may fallback to (1).

3) If neither (1) nor (2) is matched, pp-tokens will undergo macro replacement. The directive after replacement will be tried to match with (1) or (2) again.

4) Checks whether a resource is available for embedding, whether it is empty or not and whether the parameters passed are supported by the implementation.

5) If (4) is not matched, h-pp-tokens and pp-balanced-token-sequence will undergo macro replacement. The directive after replacement will be tried to match with (4) again.

| new-line  |   | -  |   | The new-line character  |

| h-char-sequence  |   | -  |   | A sequence of one or more h-chars, where the appearance of any of the following causes undefined behavior:
- the character `'`

- the character `"`

- the character `\`

- the character sequence `//`

- the character sequence `/*`

| h-char  |   | -  |   | Any member of the source character set except new-line and `>`  |

| q-char-sequence  |   | -  |   | A sequence of one or more q-chars, where the appearance of any of the following causes undefined behavior:
- the character `'`

- the character `\`

- the character sequence `//`

- the character sequence `/*`

| q-char  |   | -  |   | Any member of the source character set except new-line and `"`  |

| pp-tokens  |   | -  |   | A sequence of one or more preprocessing tokens  |

| string-literal  |   | -  |   | A string literal  |

| h-pp-tokens  |   | -  |   | A sequence of one or more preprocessing tokens except `>`  |

| embed-parameter-sequence  |   | -  |   | A sequence of one or more pp-parameter ﻿s. Note that unlike an attribute-list, this sequence is not comma separated.  |

| pp-parameter  |   | -  |   | An attribute-token (see: attributes) but comprised of preprocessing tokens instead of tokens.  |

| pp-balanced-token-sequence  |   | -  |   | A balanced-token-sequence (see: attributes) but comprised of preprocessing tokens instead of tokens  |

### Explanation

1) Searches for the resource identified by h-char-sequence in implementation-defined manner.

2) Searches for the resource identified by q-char-sequence in implementation-defined manner. For (1,2), the implementations typically use a mechanism similar to, but distinct from, the implementation-defined search paths used for source file inclusion. The construct `__has_embed(__FILE__ ...` appears in one of the examples in the standard, suggesting, in case (2) at least, that the directory where the current file resides is expected to be searched.

3) The preprocessing tokens after `**embed**` in the directive are processed just as in normal text (i.e., each identifier currently defined as a macro name is replaced by its replacement list of preprocessing tokens). The directive resulting after all replacements shall match one of the two previous forms. The method by which a sequence of preprocessing tokens between `<` and `>` preprocessing token pair or a pair of `"` characters is combined into a single header name preprocessing token is implementation-defined.

4) The resource identified by h-char-sequence or q-char-sequence is searched for as if that preprocessing token sequence were the pp-tokens in syntax (3), except that no further macro expansion is performed. If such a directive would not satisfy the syntactic requirements of an `#embed` directive, the program is ill-formed. The `__has_embed` expression evaluates to `__STDC_EMBED_FOUND__` if the search for the resource succeeds, the resource is non empty and all the parameters are supported, to `__STDC_EMBED_EMPTY__` if the resource is empty and all the parameters are supported, and to `__STDC_EMBED_NOT_FOUND__` if the search fails or one of the parameters passed is not supported by the implementation.

5) This form is considered only if syntax (4) does not match, in which case the preprocessing tokens are processed just as in normal text.

In the case the resource is not found or one of the parameters is not supported by the implementation, the program is ill-formed.
若找不到資源，或實作不支援其中某個參數，程式即為格式錯誤。
`__has_embed` can be expanded in the expression of  #if and  #elif. It is treated as a defined macro by  #ifdef,  #ifndef,  #elifdef,  #elifndef and defined but cannot be used anywhere else.
__has_embed 可以在 #if 和 #elif 的表示式中展開。 #ifdef 、 #ifndef 、 #elifdef 、 #elifndef 和 defined 將其視為已定義的宏，但它不能在其他任何地方使用。
A resource has an *implementation resource width* which is the implementation-defined size in bits of the located resource. Its *resource width* is the implementation resource width unless modified by a `limit` parameter. If the resource width is 0, the resource is considered empty. The *embed element width* is equal to `CHAR_BIT` unless modified by an implementation defined parameter. The resource width must be divisible by the embed element width.
資源有一個實作定義的資源寬度，以位元為單位表示所指定資源的大小；除非 limit 參數另行設定，資源寬度就是此值。寬度為 0 時，資源視為空。除非實作定義的參數另有指定，embed 元素寬度等於 CHAR_BIT。資源寬度必須可被 embed 元素寬度整除。
The expansion of a `#embed` directive is a token sequence formed from the list of integer constant expressions described below. The group of tokens for each integer constant expression in the list is separated in the token sequence from the group of tokens for the previous integer constant expression in the list by a comma. The sequence neither begins nor ends in a comma. If the list of integer constant expressions is empty, the token sequence is empty. The directive is replaced by its expansion and, with the presence of certain embed parameters, additional or replacement token sequences.
#embed 指令的展開是由下述整數常量表示式列表構成的記號序列。列表中每個整數常量表示式的記號組，在記號序列中由一個逗號與列表中前一個整數常量表示式的記號組分隔開。該序列既不以逗號開始，也不以逗號結束。如果整數常量表示式列表為空，則記號序列為空。該指令被其展開所替換，並且在存在某些 embed 參數時，還會附加或替換記號序列。
The values of the integer constant expressions in the expanded sequence are determined by an implementation-defined mapping of the resource’s data. Each integer constant expression’s value is in the range `[`0`, `2`)`. If:
展開序列中各整數常量表示式的值由資源資料的一種實現定義對映決定。每個整數常量表示式的值都在範圍 [ 0 , 2 embed element width ) 內。如果：

- The list of integer constant expressions is used to initialize an array of a type compatible with `unsigned char`, or compatible with `char` if `char` cannot hold negative values, and
整數常量表示式列表用於初始化一個與 unsigned char 相容的型別的陣列，或在 char 不能儲存負值時初始化一個與 char 相容的型別的陣列，並且

- The embed element width is equal to `CHAR_BIT`,
embed 元素寬度等於 CHAR_BIT ，

then the contents of the initialized elements of the array are as-if the resource’s binary data is fread into the array at translation time.
則該陣列已初始化元素的內容，就如同資源的二進位制資料在翻譯時被 fread 到該陣列中一樣。
Implementations are encouraged to take into account translation-time bit and byte orders as well as execution-time bit and byte orders to more appropriately represent the resource’s binary data from the directive. This maximizes the chance that, if the resource referenced at translation time through the `#embed` directive is the same one accessed through execution-time means, the data that is e.g. fread or similar into contiguous storage will compare bit-for-bit equal to an array of character type initialized from an `#embed` directive’s expanded contents.
鼓勵實現同時考慮翻譯時的位序和位元組序以及執行時的位序和位元組序，以便更恰當地表示來自該指令的資源二進位制資料。這樣可以最大化如下可能性：如果翻譯時透過 #embed 指令引用的資源與透過執行時手段訪問的是同一個資源，則例如被 fread 或類似方式寫入連續儲存的資料，將與由 #embed 指令展開內容初始化的字元型別陣列逐位相等。

### Parameters

The standard defines the parameters `limit`, `prefix`, `suffix` and `if_empty`. Any other parameter that appears in the directive must be implementation-defined, or the program is ill-formed. Implementation-defined embed parameters may change the semantics of the directive.
標準定義了 limit、prefix、suffix 和 if_empty 參數。指令中的其他參數都必須由實作定義，否則程式格式錯誤。實作定義的 embed 參數可能改變指令的語意。

#### limit

|   |

| `**limit(**` constant-expression `**)**`  |   | (1)  |   |   |

|   |

| `**__limit__(**` constant-expression `**)**`  |   | (2)  |   |   |

|   |

The `limit` embed parameter can appear at most once in the embed parameter sequence. It must have an argument, which must be an integer (preprocessor) constant expression that evaluates to a non negative number and does not contain the token defined. The resource width is set to the minimum of the integer constant expression multiplied by the embed element width and the implementation resource width.
limit embed 參數在 embed 參數序列中最多出現一次。它必須有一個實參，該實參必須是一個求值為非負數且不包含記號 defined 的整數（預處理）常量表示式。資源寬度被設定為該整數常量表示式乘以 embed 元素寬度與實現資源寬度兩者中的較小值。

#### suffix

|   |

| `**suffix(**` pp-balanced-token-sequence ﻿(optional) `**)**`  |   | (1)  |   |   |

|   |

| `**__suffix__(**` pp-balanced-token-sequence ﻿(optional) `**)**`  |   | (2)  |   |   |

|   |

The `suffix` embed parameter can appear at most once in the embed parameter sequence. It must have a (possibly empty) preprocessor argument clause. If the resource is non empty, the contents of the parameter clause are placed immediately after the expansion of the directive. Otherwise, it has no effect.
suffix embed 參數在 embed 參數序列中最多出現一次。它必須有一個（可為空的）預處理實參子句。如果資源非空，則該實參子句的內容被放置在指令展開之後。否則，它沒有任何作用。

#### prefix

|   |

| `**prefix(**` pp-balanced-token-sequence ﻿(optional) `**)**`  |   | (1)  |   |   |

|   |

| `**__prefix__(**` pp-balanced-token-sequence ﻿(optional) `**)**`  |   | (2)  |   |   |

|   |

The `prefix` embed parameter can appear at most once in the embed parameter sequence. It must have a (possibly empty) preprocessor argument clause. If the resource is non empty, the contents of the parameter clause are placed immediately before the expansion of the directive. Otherwise, it has no effect.
prefix embed 參數在 embed 參數序列中最多出現一次。它必須有一個（可為空的）預處理實參子句。如果資源非空，則該實參子句的內容被放置在指令展開之前。否則，它沒有任何作用。

#### if_empty

|   |

| `**if_empty(**` pp-balanced-token-sequence ﻿(optional) `**)**`  |   | (1)  |   |   |

|   |

| `**__if_empty__(**` pp-balanced-token-sequence ﻿(optional) `**)**`  |   | (2)  |   |   |

|   |

The `if_empty` embed parameter can appear at most once in the embed parameter sequence. It must have a (possibly empty) preprocessor argument clause. If the resource is empty, the contents of the parameter clause replace the directive. Otherwise, it has no effect.
if_empty embed 參數在 embed 參數序列中最多出現一次。它必須有一個（可為空的）預處理實參子句。如果資源為空，則該實參子句的內容替換該指令。否則，它沒有任何作用。

### Example

Run this code

```c
#include <stdint.h> #include <stdio.h> const uint8_t image_data[] = { #embed "image.png" };   const char message[] = { #embed "message.txt" if_empty('M', 'i', 's', 's', 'i', 'n', 'g', '\n') ,'\0' // null terminator }; void dump(const uint8_t arr[], size_t size) {  for (size_t i = 0; i != size; ++i)  printf("%02X%c", arr[i], (i + 1) % 16 ? ' ' : '\n');  puts(""); } int main() {  puts("image_data[]:");  dump(image_data, sizeof image_data);  puts("message[]:");  dump((const uint8_t*)message, sizeof message); }
```

Possible output:
輸出範例：

```c
image_data[]: 89 50 4E 47 0D 0A 1A 0A 00 00 00 0D 49 48 44 52 00 00 00 01 00 00 00 01 01 03 00 00 00 25 DB 56 ... message[]: 4D 69 73 73 69 6E 67 0A 00
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.4.7 Header names (p: 69)
6.4.7 標頭檔名 (p: 69)
6.4.7 標頭檔名 (p: 69)

- 6.10.1 Conditional inclusion (p: 165-169)
6.10.1 條件包含 (p: 165-169)
6.10.1 條件包含 (p: 165-169)

- 6.10.2 Binary resource inclusion (p: 170-177)
6.10.2 二進位制資源包含 (p: 170-177)
6.10.2 二進位制資源包含 (p: 170-177)

### See also

C++ documentation for Resource inclusion (since C++26)

---
來源頁路徑：`en.cppreference.com/c/preprocessor/embed.html`
