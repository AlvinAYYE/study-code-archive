# Standard library header <stdbit.h> (C23)

> 來源：cppreference C 語言參考文件（離線轉換版）。

This header is part of the numeric library, in particular, it provides macros and functions to work with the byte ordering and byte and bit representation of C objects.
這個標頭檔屬於數值函式庫，提供巨集與函式，用來處理 C 物件的位元組順序，以及位元組和位元表示方式。

### Functions

stdc_leading_zeros
(C23)
|   | counts the number of consecutive `0` bits, starting from the most significant bit
(type-generic function macro)  |

stdc_leading_ones
(C23)
|   | counts the number of consecutive `1` bits, starting from the most significant bit
(type-generic function macro)  |

stdc_trailing_zeros
(C23)
|   | counts the number of consecutive `0` bits, starting from the least significant bit
(type-generic function macro)  |

stdc_trailing_ones
(C23)
|   | counts the number of consecutive `1` bits, starting from the least significant bit
(type-generic function macro)  |

stdc_first_leading_zero
(C23)
|   | finds the first position of `0` bit, starting from the most significant bit
(type-generic function macro)  |

stdc_first_leading_one
(C23)
|   | finds the first position of `1` bit, starting from the most significant bit
(type-generic function macro)  |

stdc_first_trailing_zero
(C23)
|   | finds the first position of `0` bit, starting from the least significant bit
(type-generic function macro)  |

stdc_first_trailing_one
(C23)
|   | finds the first position of `1` bit, starting from the least significant bit
(type-generic function macro)  |

stdc_count_zeros
(C23)
|   | counts the number of `0` bits in an unsigned integer
(type-generic function macro)  |

stdc_count_ones
(C23)
|   | counts the number of `1` bits in an unsigned integer
(type-generic function macro)  |

stdc_has_single_bit
(C23)
|   | checks if a number is an integral power of 2
(type-generic function macro)  |

stdc_bit_width
(C23)
|   | finds the smallest number of bits needed to represent the given value
(type-generic function macro)  |

stdc_bit_floor
(C23)
|   | finds the largest integral power of 2 not greater than the given value
(type-generic function macro)  |

stdc_bit_ceil
(C23)
|   | finds the smallest integral power of 2 not less than the given value
(type-generic function macro)  |

### Macro constants

__STDC_ENDIAN_LITTLE____STDC_ENDIAN_BIG__ __STDC_ENDIAN_NATIVE__
(C23)
|   | indicates the endianness of scalar types
(macro constant)   |

### Synopsis

```c
#define __STDC_VERSION_STDBIT_H__ 202311L #define __STDC_ENDIAN_LITTLE__ /* implementation-defined */ #define __STDC_ENDIAN_BIG__ /* implementation-defined */ #define __STDC_ENDIAN_NATIVE__ /* implementation-defined */ unsigned int stdc_leading_zeros_uc(unsigned char value) [[unsequenced]]; unsigned int stdc_leading_zeros_us(unsigned short value) [[unsequenced]]; unsigned int stdc_leading_zeros_ui(unsigned int value) [[unsequenced]]; unsigned int stdc_leading_zeros_ul(unsigned long int value) [[unsequenced]]; unsigned int stdc_leading_zeros_ull(unsigned long long int value) [[unsequenced]]; /*generic_return_type*/ stdc_leading_zeros(/*generic_value_type*/ value) [[unsequenced]]; unsigned int stdc_leading_ones_uc(unsigned char value) [[unsequenced]]; unsigned int stdc_leading_ones_us(unsigned short value) [[unsequenced]]; unsigned int stdc_leading_ones_ui(unsigned int value) [[unsequenced]]; unsigned int stdc_leading_ones_ul(unsigned long int value) [[unsequenced]]; unsigned int stdc_leading_ones_ull(unsigned long long int value) [[unsequenced]]; /*generic_return_type*/ stdc_leading_ones(/*generic_value_type*/ value) [[unsequenced]]; unsigned int stdc_trailing_zeros_uc(unsigned char value) [[unsequenced]]; unsigned int stdc_trailing_zeros_us(unsigned short value) [[unsequenced]]; unsigned int stdc_trailing_zeros_ui(unsigned int value) [[unsequenced]]; unsigned int stdc_trailing_zeros_ul(unsigned long int value) [[unsequenced]]; unsigned int stdc_trailing_zeros_ull(unsigned long long int value) [[unsequenced]]; /*generic_return_type*/ stdc_trailing_zeros(/*generic_value_type*/ value) [[unsequenced]]; unsigned int stdc_trailing_ones_uc(unsigned char value) [[unsequenced]]; unsigned int stdc_trailing_ones_us(unsigned short value) [[unsequenced]]; unsigned int stdc_trailing_ones_ui(unsigned int value) [[unsequenced]]; unsigned int stdc_trailing_ones_ul(unsigned long int value) [[unsequenced]]; unsigned int stdc_trailing_ones_ull(unsigned long long int value) [[unsequenced]]; /*generic_return_type*/ stdc_trailing_ones(/*generic_value_type*/ value) [[unsequenced]]; unsigned int stdc_first_leading_zero_uc(unsigned char value) [[unsequenced]]; unsigned int stdc_first_leading_zero_us(unsigned short value) [[unsequenced]]; unsigned int stdc_first_leading_zero_ui(unsigned int value) [[unsequenced]]; unsigned int stdc_first_leading_zero_ul(unsigned long int value) [[unsequenced]]; unsigned int stdc_first_leading_zero_ull(unsigned long long int value) [[unsequenced]]; /*generic_return_type*/ stdc_first_leading_zero(/*generic_value_type*/ value) [[unsequenced]]; unsigned int stdc_first_leading_one_uc(unsigned char value) [[unsequenced]]; unsigned int stdc_first_leading_one_us(unsigned short value) [[unsequenced]]; unsigned int stdc_first_leading_one_ui(unsigned int value) [[unsequenced]]; unsigned int stdc_first_leading_one_ul(unsigned long int value) [[unsequenced]]; unsigned int stdc_first_leading_one_ull(unsigned long long int value) [[unsequenced]]; /*generic_return_type*/ stdc_first_leading_one(/*generic_value_type*/ value) [[unsequenced]]; unsigned int stdc_first_trailing_zero_uc(unsigned char value) [[unsequenced]]; unsigned int stdc_first_trailing_zero_us(unsigned short value) [[unsequenced]]; unsigned int stdc_first_trailing_zero_ui(unsigned int value) [[unsequenced]]; unsigned int stdc_first_trailing_zero_ul(unsigned long int value) [[unsequenced]]; unsigned int stdc_first_trailing_zero_ull(unsigned long long int value) [[unsequenced]]; /*generic_return_type*/ stdc_first_trailing_zero(/*generic_value_type*/ value) [[unsequenced]]; unsigned int stdc_first_trailing_one_uc(unsigned char value) [[unsequenced]]; unsigned int stdc_first_trailing_one_us(unsigned short value) [[unsequenced]]; unsigned int stdc_first_trailing_one_ui(unsigned int value) [[unsequenced]]; unsigned int stdc_first_trailing_one_ul(unsigned long int value) [[unsequenced]]; unsigned int stdc_first_trailing_one_ull(unsigned long long int value) [[unsequenced]]; /*generic_return_type*/ stdc_first_trailing_one(/*generic_value_type*/ value) [[unsequenced]]; unsigned int stdc_count_zeros_uc(unsigned char value) [[unsequenced]]; unsigned int stdc_count_zeros_us(unsigned short value) [[unsequenced]]; unsigned int stdc_count_zeros_ui(unsigned int value) [[unsequenced]]; unsigned int stdc_count_zeros_ul(unsigned long int value) [[unsequenced]]; unsigned int stdc_count_zeros_ull(unsigned long long int value) [[unsequenced]]; /*generic_return_type*/ stdc_count_zeros(/*generic_value_type*/ value) [[unsequenced]]; unsigned int stdc_count_ones_uc(unsigned char value) [[unsequenced]]; unsigned int stdc_count_ones_us(unsigned short value) [[unsequenced]]; unsigned int stdc_count_ones_ui(unsigned int value) [[unsequenced]]; unsigned int stdc_count_ones_ul(unsigned long int value) [[unsequenced]]; unsigned int stdc_count_ones_ull(unsigned long long int value) [[unsequenced]]; /*generic_return_type*/ stdc_count_ones(/*generic_value_type*/ value) [[unsequenced]]; bool stdc_has_single_bit_uc(unsigned char value) [[unsequenced]]; bool stdc_has_single_bit_us(unsigned short value) [[unsequenced]]; bool stdc_has_single_bit_ui(unsigned int value) [[unsequenced]]; bool stdc_has_single_bit_ul(unsigned long int value) [[unsequenced]]; bool stdc_has_single_bit_ull(unsigned long long int value) [[unsequenced]]; bool stdc_has_single_bit(/*generic_value_type*/ value) [[unsequenced]]; unsigned int stdc_bit_width_uc(unsigned char value) [[unsequenced]]; unsigned int stdc_bit_width_us(unsigned short value) [[unsequenced]]; unsigned int stdc_bit_width_ui(unsigned int value) [[unsequenced]]; unsigned int stdc_bit_width_ul(unsigned long int value) [[unsequenced]]; unsigned int stdc_bit_width_ull(unsigned long long int value) [[unsequenced]]; /*generic_return_type*/ stdc_bit_width(/*generic_value_type*/ value) [[unsequenced]]; unsigned char stdc_bit_floor_uc(unsigned char value) [[unsequenced]]; unsigned short stdc_bit_floor_us(unsigned short value) [[unsequenced]]; unsigned int stdc_bit_floor_ui(unsigned int value) [[unsequenced]]; unsigned long int stdc_bit_floor_ul(unsigned long int value) [[unsequenced]]; unsigned long long int stdc_bit_floor_ull(unsigned long long int value) [[unsequenced]]; /*generic_value_type*/ stdc_bit_floor(/*generic_value_type*/ value) [[unsequenced]]; unsigned char stdc_bit_ceil_uc(unsigned char value) [[unsequenced]]; unsigned short stdc_bit_ceil_us(unsigned short value) [[unsequenced]]; unsigned int stdc_bit_ceil_ui(unsigned int value) [[unsequenced]]; unsigned long int stdc_bit_ceil_ul(unsigned long int value) [[unsequenced]]; unsigned long long int stdc_bit_ceil_ull(unsigned long long int value) [[unsequenced]]; /*generic_value_type*/ stdc_bit_ceil(/*generic_value_type*/ value) [[unsequenced]]; unsigned char stdc_rotate_left_uc(unsigned char value, unsigned int count); unsigned short stdc_rotate_left_us(unsigned short value, unsigned int count); unsigned int stdc_rotate_left_ui(unsigned int value, unsigned int count); unsigned long stdc_rotate_left_ul(unsigned long value, unsigned int count); unsigned long long stdc_rotate_left_ull(unsigned long long value, unsigned int count); /*generic_value_type*/ stdc_rotate_left(/*generic_value_type*/ value, generic_count_type count); unsigned char stdc_rotate_right_uc(unsigned char value, unsigned int count); unsigned short stdc_rotate_right_us(unsigned short value, unsigned int count); unsigned int stdc_rotate_right_ui(unsigned int value, unsigned int count); unsigned long stdc_rotate_right_ul(unsigned long value, unsigned int count); unsigned long long stdc_rotate_right_ull(unsigned long long value, unsigned int count); /*generic_value_type*/ stdc_rotate_right(/*generic_value_type*/ value, generic_count_type count);
```

---
來源頁路徑：`en.cppreference.com/c/header/stdbit.html`
