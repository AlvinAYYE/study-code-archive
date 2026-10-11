# Standard library header <ctype.h>

> 來源：cppreference C 語言參考文件（離線轉換版）。

This header is part of the null-terminated byte strings library.
該標頭檔是以空字元結尾的位元組字串庫的一部分。

### Functions

isalnum
|   | checks if a character is alphanumeric
(function)   |

isalpha
|   | checks if a character is alphabetic
(function)   |

islower
|   | checks if a character is lowercase
(function)   |

isupper
|   | checks if a character is an uppercase character
(function)   |

isdigit
|   | checks if a character is a digit
(function)   |

isxdigit
|   | checks if a character is a hexadecimal character
(function)   |

iscntrl
|   | checks if a character is a control character
(function)   |

isgraph
|   | checks if a character is a graphical character
(function)   |

isspace
|   | checks if a character is a space character
(function)   |

isblank
(C99)
|   | checks if a character is a blank character
(function)   |

isprint
|   | checks if a character is a printing character
(function)   |

ispunct
|   | checks if a character is a punctuation character
(function)   |

tolower
|   | converts a character to lowercase
(function)   |

toupper
|   | converts a character to uppercase
(function)   |

### Synopsis

```c
int isalnum(int c); int isalpha(int c); int isblank(int c); int iscntrl(int c); int isdigit(int c); int isgraph(int c); int islower(int c); int isprint(int c); int ispunct(int c); int isspace(int c); int isupper(int c); int isxdigit(int c); int tolower(int c); int toupper(int c);
```

---
來源頁路徑：`en.cppreference.com/c/header/ctype.html`
