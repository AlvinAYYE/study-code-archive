# memccpy

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<string.h>`
|   |  |   |  |

```c
void* memccpy( void* restrict dest, const void* restrict src, int c, size_t count );
```
|   |   |   |  (since C23)  |

|  |  |  |  |

Copies bytes from the object pointed to by `src` to the object pointed to by `dest`, stopping after *any* of the next two conditions are satisfied:
將位元組從 src 指向的物件複製到 dest 指向的物件，在滿足以下兩個條件之一後停止：

- `count` bytes are copied
已複製 count 個位元組

- the byte `(unsigned char)c` is found (and copied).
找到（並複製）位元組 ( unsigned char ) c 。
已複製 count 個位元組 找到（並複製）位元組 ( unsigned char ) c 。

The `src` and `dest` objects are interpreted as arrays of `unsigned char`.
src 和 dest 物件被解釋為 unsigned char 陣列。
The behavior is undefined if *any* condition is met:
如果滿足以下任一條件，則行為未定義：

- access occurs beyond the end of the `dest` array;
訪問超出 dest 陣列的末尾；

- the objects overlap (which is a violation of the restrict contract)
物件重疊（違反 restrict 約定）

- either `dest` or `src` is an invalid or null pointer
dest 或 src 是無效或空指標
訪問超出 dest 陣列的末尾；物件重疊（違反 restrict 約定） dest 或 src 是無效或空指標

### Parameters

| dest  |   | -  |   | pointer to the object to copy to  |

| src  |   | -  |   | pointer to the object to copy from  |

| c  |   | -  |   | terminating byte, converted to `unsigned char` at first  |

| count  |   | -  |   | number of bytes to copy  |

### Return value

If the byte `(unsigned char)c` was found, `memccpy` returns a pointer to the next byte in `dest` after `(unsigned char)c`. Otherwise it returns a null pointer.
如果找到位元組 ( unsigned char ) c ， memccpy 傳回指向 dest 中 ( unsigned char ) c 之後下一個位元組的指標。否則傳回空指標。

### Notes

The function is identical to the POSIX `memccpy`.
此函式與 POSIX memccpy 相同。
`memccpy(dest, src, 0, count)` behaves similar to `strncpy(dest, src, count)`, except that the former returns a pointer to the *end* of the buffer written, and does not zero-pad the destination array. Thus, `memccpy` is useful for efficiently concatenating multiple strings.
memccpy ( dest , src , 0 , count ) 的行為類似於 strncpy ( dest , src , count ) ，除了前者傳回指向已寫入緩衝區末尾的指標，並且不對目標陣列進行零填充。因此， memccpy 對於高效連線多個字串很有用。

```c
char bigString[1000]; char* end = bigString + sizeof bigString;   char* p = memccpy(bigString, "John, ", '\0', sizeof bigString - 1); if (p)  p = memccpy(p - 1, "Paul, ", '\0', end - p); if (p)  p = memccpy(p - 1, "George, ", '\0', end - p); if (p)  p = memccpy(p - 1, "Joel ", '\0', end - p); if (!p)  end[-1] = '\0';   puts(bigString); // John, Paul, George, Joel
```

### Example

Run this code

```c
#include <ctype.h> #include <stdio.h> #include <string.h> int main(void) {  const char src[] = "Stars: Altair, Sun, Vega.";  const char terminal[] = {':', ' ', ',', '.', '!'};  char dest[sizeof src];  const char alt = '@';  for (size_t i = 0; i != sizeof terminal; ++i)  {  void* to = memccpy(dest, src, terminal[i], sizeof dest);  printf("Terminal '%c' (%s):\t\"", terminal[i], to ? "found" : "absent");  // if `terminal` character was not found - print the whole `dest`  to = to ? to : dest + sizeof dest;  for (char* from = dest; from != to; ++from)  putchar(isprint(*from) ? *from : alt);  puts("\"");  }  puts("\n" "Separate star names from distances (ly):");  const char *star_distance[] = {  "Arcturus : 37", "Vega : 25", "Capella : 43", "Rigel : 860", "Procyon : 11"  };  char names_only[64];  char *first = names_only;  char *last = names_only + sizeof names_only;  for (size_t t = 0; t != (sizeof star_distance) / (sizeof star_distance[0]); ++t)  {  if (first)  first = memccpy(first, star_distance[t], ' ', last - first);  else  break;  }  if (first)  {  *first = '\0';  puts(names_only);  }  else  puts("Buffer is too small."); }
```

Output:

```c
Terminal ':' (found): "Stars:" Terminal ' ' (found): "Stars: " Terminal ',' (found): "Stars: Altair," Terminal '.' (found): "Stars: Altair, Sun, Vega." Terminal '!' (absent): "Stars: Altair, Sun, Vega.@" Separate star names from distances (ly): Arcturus Vega Capella Rigel Procyon
```

### See also

memcpymemcpy_s
(C11)
|   | copies one buffer to another
(function)   |

wmemcpywmemcpy_s
(C95)(C11)
|   | copies a certain amount of wide characters between two non-overlapping arrays
(function)   |

memmovememmove_s
(C11)
|   | moves one buffer to another
(function)   |

strcpystrcpy_s
(C11)
|   | copies one string to another
(function)   |

strcatstrcat_s
(C11)
|   | concatenates two strings
(function)   |

---
來源頁路徑：`en.cppreference.com/c/string/byte/memccpy.html`
