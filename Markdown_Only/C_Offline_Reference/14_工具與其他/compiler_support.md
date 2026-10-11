# C compiler support

> 來源：cppreference C 語言參考文件（離線轉換版）。

|   |   |  This page is maintained as best-effort and may lag behind most recent compiler releases. If you see something is out-of-date, please help us by updating it!  |

## C23 features

Note that this list may change, as the draft C23/2x standard evolves.
注意，此列表可能隨 C23/2x 標準草案的演進而變化。

### C23 core language features
C23 核心語言特性

|  | This section is incomplete
Reason: status for Apple Clang and other compilers supporting C2x  |

| C23 feature
   |   | Paper(s)
   |   |
GCC
|   |
Clang
|   |
MSVC
|   |
Apple Clang
|   |
EDG eccp
|   |
Intel C++
|   |
Nvidia HPC C++ (ex PGI)*
|   |
Nvidia nvcc
|   |
Cray
|   |   |

| static_assert with no message  |   | N2265  |   | 9  |   | 9  |   | Yes  |   | Yes  |   | 6.5  |   | 2021.1.2 (clang based)  |   |   |   |   |   |   |

| `[[nodiscard]]`  |   | N2267  |   | 10  |   | 9  |   |   |   | Yes  |   | 6.4  |   | 2021.1.2 (clang based)  |   |   |   |   |   |   |

| `[[maybe_unused]]`  |   | N2270  |   | 10  |   | 9  |   |   |   | Yes  |   | 6.4  |   | 2021.1.2 (clang based)  |   |   |   |   |   |   |

| `[[deprecated]]`  |   | N2334  |   | 10  |   | 9  |   |   |   | Yes  |   | 6.4  |   | 2021.1.2 (clang based)  |   |   |   |   |   |   |

| Attributes  |   | N2335
N2554  |   | 10  |   | 9  |   |   |   | Yes  |   | 6.4  |   | 2021.1.2 (clang based)  |   |   |   |   |   |   |

| IEEE 754 decimal floating-point types  |   | N2341  |   | 4.2 (partial)*
12  |   |   |   |   |   |   |   |   |   | 13.0 (partial)*  |   |   |   |   |   |   |

| `[[fallthrough]]`  |   | N2408  |   | 10  |   | 9  |   |   |   | Yes  |   | 6.4  |   | 2021.1.2 (clang based)  |   |   |   |   |   |   |

| `u8` character constants  |   | N2418  |   | 10  |   | 15  |   |   |   |   |   | 6.5  |   | 2022.2  |   |   |   |   |   |   |

| Removal of function definitions without prototype  |   | N2432  |   | 10  |   | 15  |   |   |   |   |   | 6.9  |   | 2022.2  |   |   |   |   |   |   |

| `[[nodiscard]]` with message  |   | N2448  |   | 11  |   | 10  |   |   |   | Yes  |   | 6.4  |   | 2021.1.2 (clang based)  |   |   |   |   |   |   |

| Unnamed parameters in function definitions  |   | N2480  |   | 11  |   | 11  |   |   |   | Yes  |   | 6.4  |   | 2021.1.2 (clang based)  |   |   |   |   |   |   |

| Labels before declarations and end of blocks  |   | N2508  |   | 11  |   | 16  |   | Partial*  |   |   |   | 6.5  |   | 17.0*  |   |   |   |   |   |   |

| Binary integer constants  |   | N2549  |   | 4.3*
11  |   | 2.9*
9  |   | 19.0 (2015)**  |   | Yes  |   | 6.5  |   | 11.0*  |   |   |   |   |   |   |

| __has_c_attribute in preprocessor conditionals  |   | N2553  |   | 11  |   | 9  |   |   |   | Yes  |   | 6.5  |   | 2021.1.2 (clang based)  |   |   |   |   |   |   |

| Allow duplicate attributes  |   | N2557  |   | 11  |   | 13  |   |   |   | Yes  |   | 6.5  |   | 2021.4 (clang-based  |   |   |   |   |   |   |

| IEEE 754 interchange and extended types  |   | N2601  |   | 7 (partial)*
14  |   | 6 (partial)*  |   |   |   | Partial*  |   |   |   |   |   |   |   |   |   |   |

| Digit separators  |   | N2626  |   | 12  |   | 13  |   | 19.0 (2015)**  |   | Yes  |   | 6.5  |   | 18.0*  |   |   |   |   |   |   |

| `#elifdef` and `#elifndef`  |   | N2645  |   | 12  |   | 13  |   | 19.40*  |   | 13.1.6*  |   | 6.5  |   | 2021.4  |   |   |   |   |   |   |

| Type change of `u8` string literals  |   | N2653  |   | 13  |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |

| `[[maybe_unused]]` for labels  |   | N2662  |   | 11  |   | 16  |   |   |   |   |   | 6.5  |   | 2022.2  |   |   |   |   |   |   |

|  #warning  |   | N2686  |   | Yes  |   | Yes  |   |   |   | Yes  |   | 6.5  |   | Yes  |   |   |   |   |   |   |

| Bit-precise integer types (`_BitInt`)  |   | N2763  |   | 14 (partial)*  |   | 15  |   |   |   |   |   | 6.5  |   | 2022.2  |   |   |   |   |   |   |

| `[[noreturn]]`  |   | N2764  |   | 13  |   | 15  |   |   |   |   |   | 6.5  |   | 2022.2  |   |   |   |   |   |   |

| Suffixes for bit-precise integer constants  |   | N2775  |   | 14  |   | 15  |   |   |   |   |   |   |   | 2022.2  |   |   |   |   |   |   |

| __has_include in preprocessor conditionals  |   | N2799  |   | 5  |   | Yes  |   | 19.11*  |   | Yes  |   | 6.5  |   | 18.0  |   |   |   |   |   |   |

| Identifier Syntax using Unicode Standard Annex 31  |   | N2836  |   | 13  |   | 15  |   |   |   |   |   | 6.5  |   | 2022.2  |   |   |   |   |   |   |

| Removal of function declarations without prototype  |   | N2841  |   | 13  |   | 15  |   |   |   |   |   | 6.9  |   | 2022.2  |   |   |   |   |   |   |

| Empty initializers  |   | N2900  |   | Partial*
13  |   | Partial*  |   |   |   | Partial*  |   | Partial*  |   | Partial*  |   |   |   |   |   |   |

| typeof and typeof_unqual  |   | N2927
N2930  |   | Partial*
13  |   | Partial*
16  |   | 19.39*  |   | Partial*  |   | Partial*  |   | Partial*  |   |   |   |   |   | Partial*  |

| New spelling of keywords  |   | N2934  |   | 13  |   | 16  |   |   |   |   |   | 6.5  |   |   |   |   |   |   |   |   |

| Predefined `true` and `false`  |   | N2935  |   | 13  |   | 15  |   |   |   |   |   | 6.8  |   | 2022.2  |   |   |   |   |   |   |

| `[[unsequenced]]` and `[[reproducible]]`  |   | N2956  |   | 15  |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |

| Relax requirements for variadic parameter list  |   | N2975  |   | 13  |   | 16  |   |   |   |   |   | 6.5  |   | 2023.1  |   |   |   |   |   |   |

| Type inference in object definitions  |   | N3007  |   | 13  |   | 18  |   |   |   |   |   |   |   |   |   |   |   |   |   |   |

|  #embed  |   | N3017  |   | 15  |   | 19  |   |   |   |   |   | 6.8  |   |   |   |   |   |   |   |   |

| constexpr objects  |   | N3018  |   | 13  |   | 19  |   |   |   |   |   |   |   |   |   |   |   |   |   |   |

| Improved Normal Enumerations  |   | N3029  |   | 13  |   | 20*  |   |   |   |   |   |   |   |   |   |   |   |   |   |   |

| Enumerations with fixed underlying types  |   | N3030  |   | 13  |   | 20*  |   |   |   |   |   | 6.8  |   |   |   |   |   |   |   |   |

| `__VA_OPT__`  |   | N3033  |   | 8
13  |   | 12  |   | 19.39*  |   |   |   | 6.5  |   |   |   |   |   |   |   |   |

| Storage-class specifiers for compound literals  |   | N3038  |   | 13  |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |

| nullptr  |   | N3042  |   | 13  |   | 16  |   |   |   |   |   | 6.7  |   |   |   |   |   |   |   |   |

C23 feature  |   |  
Paper(s)  |   |
GCC
|   |
Clang
|   |
MSVC
|   |
Apple Clang
|   |
EDG eccp
|   |
Intel C++
|   |
Nvidia HPC C++ (ex PGI)*
|   |
Nvidia nvcc
|   |
Cray

### C23 library features
C23 庫特性

|  | This section is incomplete
Reason: a different list for C standard libraries  |

## C99 features

### C99 core language features
C99 核心語言特性

|  | This section is incomplete
Reason: needs to list C compilers, verification  |

| C99 feature
   |   | Paper(s)
   |   |
GCC
|   |
Clang
|   |
MSVC
|   |
Apple Clang
|   |
EDG eccp
|   |
Intel C++
|   |
Nvidia HPC C++ (ex PGI)*
|   |
Nvidia nvcc
|   |
Cray
|   |   |

| Universal-character-names in identifiers  |   |   |   | 3.1  |   | Yes  |   | Yes  |   |   |   |   |   |   |   |   |   |   |   |   |

| Increased translation limits  |   | N590  |   | 0.9  |   | N/A  |   |   |   |   |   |   |   |   |   |   |   |   |   |   |

| `//` comments  |   | N644  |   | 2.7  |   | Yes  |   | Yes  |   |   |   |   |   |   |   |   |   |   |   |   |

| restrict pointers  |   | N448  |   | 2.95  |   | Yes  |   | partial*  |   |   |   |   |   |   |   |   |   |   |   |   |

| Enhanced arithmetic types  |   | N815
N601
N620
N638
N657
N694
N809  |   | Yes  |   | partial  |   | Maybe  |   |   |   |   |   |   |   |   |   |   |   |   |

| Flexible array members  |   |   |   | 3.0  |   | Yes  |   | Yes  |   |   |   |   |   |   |   |   |   |   |   |   |

| Variable-length array (VLA) types  |   | N683  |   | 0.9  |   | Yes  |   |   |   |   |   |   |   |   |   |   |   |   |   |   |

| Variably-modified (VM) types  |   | N2778  |   | N/A  |   | Yes  |   |   |   |   |   |   |   |   |   |   |   |   |   |   |

| Designated initializers  |   | N494  |   | 3.0  |   | Yes  |   | Yes  |   |   |   |   |   |   |   |   |   |   |   |   |

| Non-constant initializers  |   |   |   | 1.21  |   | N/A  |   |   |   |   |   |   |   |   |   |   |   |   |   |   |

| Idempotent cvr-qualifiers  |   | N505  |   | 3.0  |   | N/A  |   |   |   |   |   |   |   |   |   |   |   |   |   |   |

| Trailing comma in enumerator-list  |   |   |   | 0.9  |   | Yes  |   | Yes  |   |   |   |   |   |   |   |   |   |   |   |   |

| Hexadecimal floating constants  |   | N308  |   | 2.8  |   | Yes  |   | Yes  |   |   |   |   |   |   |   |   |   |   |   |   |

| Compound literals  |   | N716  |   | 3.1  |   | Yes  |   | Yes  |   |   |   |   |   |   |   |   |   |   |   |   |

| Floating-point environment  |   |   |   | partial  |   | partial  |   |   |   |   |   |   |   |   |   |   |   |   |   |   |

| Requiring truncation for divisions of signed integer types  |   | N617  |   | 0.9  |   | N/A  |   |   |   |   |   |   |   |   |   |   |   |   |   |   |

| Implicit `return 0;` in the `main()` function  |   |   |   | Yes  |   | Yes  |   | Yes  |   |   |   |   |   |   |   |   |   |   |   |   |

| Declarations and statements in mixed order  |   | N740  |   | 3.0  |   | Yes  |   | Yes  |   |   |   |   |   |   |   |   |   |   |   |   |

| init-statement in for loops  |   |   |   | Yes  |   | Yes  |   | Yes  |   |   |   |   |   |   |   |   |   |   |   |   |

| inline functions  |   | N741  |   | 4.3  |   | Yes  |   | Yes  |   |   |   |   |   |   |   |   |   |   |   |   |

| Predefined variable __func__  |   | N611  |   | 2.95  |   | Yes  |   | Yes  |   |   |   |   |   |   |   |   |   |   |   |   |

| Cvr-qualifiers and `static` in `[]` within function declarations  |   |   |   | 3.1  |   | Yes  |   |   |   |   |   |   |   |   |   |   |   |   |   |   |

| Variadic macros  |   | N707  |   | 2.95  |   | Yes  |   | Yes  |   |   |   |   |   |   |   |   |   |   |   |   |

| _Pragma preprocessor operator  |   | N634  |   | 3.0  |   | Yes  |   | partial*  |   |   |   |   |   |   |   |   |   |   |   |   |

| Standard pragmas for floating-point evaluation  |   | N631
N696  |   | No  |   | No  |   |   |   |   |   |   |   |   |   |   |   |   |   |   |

C99 feature  |   |  
Paper(s)  |   |
GCC
|   |
Clang
|   |
MSVC
|   |
Apple Clang
|   |
EDG eccp
|   |
Intel C++
|   |
Nvidia HPC C++ (ex PGI)*
|   |
Nvidia nvcc
|   |
Cray

### See also

C++ documentation for compiler support

---
來源頁路徑：`en.cppreference.com/c/compiler_support.html`
