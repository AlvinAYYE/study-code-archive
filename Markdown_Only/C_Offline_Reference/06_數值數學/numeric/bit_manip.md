# Bit manipulation (since C23)

> 來源：cppreference C 語言參考文件（離線轉換版）。

### Functions

Defined in header `<stdbit.h>`

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

Defined in header `<stdbit.h>`

__STDC_ENDIAN_LITTLE____STDC_ENDIAN_BIG__ __STDC_ENDIAN_NATIVE__
(C23)
|   | indicates the endianness of scalar types
(macro constant)   |

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.18 Bit and byte utilities <stdbit.h>
7.18 位與位元組工具 <stdbit.h>
7.18 位與位元組工具 <stdbit.h>

### See also

C++ documentation for Bit manipulation

---
來源頁路徑：`en.cppreference.com/c/numeric/bit_manip.html`
