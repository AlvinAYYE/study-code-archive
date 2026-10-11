# stdc_leading_zeros

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdbit.h>`
|   |  |   |  |

```c
unsigned int stdc_leading_zeros_uc( unsigned char value ) [[unsequenced]];
```
|   |  (1)  |   |  (since C23)  |

```c
unsigned int stdc_leading_zeros_us( unsigned short value ) [[unsequenced]];
```
|   |  (2)  |   |  (since C23)  |

```c
unsigned int stdc_leading_zeros_ui( unsigned int value ) [[unsequenced]];
```
|   |  (3)  |   |  (since C23)  |

```c
unsigned int stdc_leading_zeros_ul( unsigned long int value ) [[unsequenced]];
```
|   |  (4)  |   |  (since C23)  |

```c
unsigned int stdc_leading_zeros_ull( unsigned long long int value ) [[unsequenced]];
```
|   |  (5)  |   |  (since C23)  |

```c
#define stdc_leading_zeros( value ) // exposed interface: generic_return_type stdc_leading_zeros( generic_value_type value ) [[unsequenced]];
```
|   |  (6)  |   |  (since C23)  |

|  |  |  |  |

1-5) Returns the number of consecutive `0` bits in the `value`, starting from the most significant bit.

6) The type-generic function (marked by its `generic_value_type` argument) returns the appropriate value based on the type of the input value, so long as it is a:
- standard unsigned integer type, excluding `bool`;
標準無符號整數型別，不包括 bool；

- extended unsigned integer type;
擴充套件無符號整數型別；

- or, bit-precise unsigned integer type whose width matches a standard or extended integer type, excluding `bool`.
或，寬度與標準或擴充套件整數型別匹配的位精確無符號整數型別，不包括 bool。
The `generic_return_type` shall be a suitable large unsigned integer type capable of representing the computed result.

### Parameters

| value  |   | -  |   | value of unsigned integer type  |

### Return value

The number of consecutive `0` bits in the `value`, starting from the most significant bit.
從最高有效位開始，值中連續 0 位的數量。

### Example

Run this code

```c
#include <limits.h> #include <stdbit.h> #include <stdint.h> #include <stdio.h> #define bits_num(value) (sizeof(value) * CHAR_BIT) #define bin_impl(T, suffix) \ const char* bin_##suffix(T x) \ { \  static char buf[bits_num(x) * CHAR_BIT + 1]; \  for (T i = 0, mask = ((T)1 << (bits_num(x) - 1)); mask; mask >>= 1) \  buf[i++] = x & mask ? '1' : '0'; \  buf[bits_num(x)] = '\0'; \  return buf; \ } bin_impl(uint8_t, u8) bin_impl(uint16_t, u16) bin_impl(uint32_t, u32) bin_impl(uint64_t, u64) #define bin(x) _Generic((x), \  uint8_t: bin_u8, uint16_t: bin_u16, uint32_t: bin_u32, default: bin_u64)(x) int main() {  puts("uint8_t:");  for (uint8_t x = 0b11000000; ; x >>= 1)  {  printf("x = [%s], leading zeros: %d\n", bin(x), stdc_leading_zeros(x));  if (!x)  break;  }  puts("uint16_t:");  for (uint16_t x = 0b11000000; ; x >>= 1)  {  printf("x = [%s], leading zeros: %d\n", bin(x), stdc_leading_zeros(x));  if (!x)  break;  } }
```

Output:

```c
uint8_t: x = [11000000], leading zeros: 0 x = [01100000], leading zeros: 1 x = [00110000], leading zeros: 2 x = [00011000], leading zeros: 3 x = [00001100], leading zeros: 4 x = [00000110], leading zeros: 5 x = [00000011], leading zeros: 6 x = [00000001], leading zeros: 7 x = [00000000], leading zeros: 8 uint16_t: x = [0000000011000000], leading zeros: 8 x = [0000000001100000], leading zeros: 9 x = [0000000000110000], leading zeros: 10 x = [0000000000011000], leading zeros: 11 x = [0000000000001100], leading zeros: 12 x = [0000000000000110], leading zeros: 13 x = [0000000000000011], leading zeros: 14 x = [0000000000000001], leading zeros: 15 x = [0000000000000000], leading zeros: 16
```

### See also

stdc_first_leading_zero
(C23)
|   | finds the first position of `0` bit, starting from the most significant bit
(type-generic function macro)  |

stdc_count_zeros
(C23)
|   | counts the number of `0` bits in an unsigned integer
(type-generic function macro)  |

stdc_leading_ones
(C23)
|   | counts the number of consecutive `1` bits, starting from the most significant bit
(type-generic function macro)  |

C++ documentation for countl_zero

---
來源頁路徑：`en.cppreference.com/c/numeric/bit/stdc_leading_zeros.html`
