# Implementing String Methods Using C

This repository contains implementations of various string manipulation functions in C, replicating standard library functions from `<string.h>`. These functions provide fundamental operations for handling C-style strings.

## Implemented Functions

### 1. `strlen` - Calculate String Length
Calculates the length of a given string (excluding the null terminator `\0`).

### 2. `strcpy` - Copy a String
Copies the source string (including the null terminator) to the destination buffer.

### 3. `strncpy` - Copy a String with Size Limit
Copies up to `n` characters from the source string to the destination buffer. If the source is shorter than `n`, the remaining characters are filled with null characters.

### 4. `strcat` - Concatenate Strings
Appends the source string to the end of the destination string, assuming enough space is available.

### 5. `strncat` - Concatenate Strings with Size Limit
Appends up to `n` characters from the source string to the destination string.

### 6. `strcmp` - Compare Two Strings
Compares two strings lexicographically and returns an integer indicating their relative order.

### 7. `strncmp` - Compare Two Strings with Size Limit
Compares up to `n` characters of two strings lexicographically.

### 8. `strchr` - Find First Occurrence of a Character
Finds the first occurrence of a specified character in a string and returns a pointer to it.

### 9. `strrchr` - Find Last Occurrence of a Character
Finds the last occurrence of a specified character in a string and returns a pointer to it.

### 10. `strstr` - Find a Substring (Brute Force)
Searches for the first occurrence of a substring within a string using a brute-force approach.

### 11. `strstr_KMP` - Find a Substring (Optimized with KMP Algorithm)
A more efficient implementation of `strstr` using the Knuth-Morris-Pratt (KMP) algorithm to improve performance.

### 12. `strcspn` - Span Until a Character Match
Returns the length of the initial segment of a string that does not contain any characters from a given set.

### 13. `strspn` - Span While Characters Match
Returns the length of the initial segment of a string that consists only of characters from a given set.

### 14. `strpbrk` - Find First Matching Character
Searches a string for the first occurrence of any character from a given set and returns a pointer to it.

### 15. `strtok` - Tokenize a String
Splits a string into tokens based on a given set of delimiters. Uses internal state to keep track of successive calls.

### 16. `strcoll` - Locale-Aware String Comparison
Compares two strings based on locale-specific ordering instead of raw ASCII values.

### 17. `memset` - Fill Memory with a Constant Byte
Fills a block of memory with a specified byte value.

### 18. `memcpy` - Copy Memory Block
Copies `n` bytes from the source memory area to the destination memory area.

### 19. `memmove` - Copy Memory Block (Handling Overlaps)
Copies `n` bytes from the source memory area to the destination memory area, ensuring safe handling of overlapping regions.

### 20. `memcmp` - Compare Memory Blocks
Compares two memory blocks byte by byte and returns an integer indicating their relative order.

### 21. `memchr` - Search Memory for a Byte
Scans a memory block for the first occurrence of a specified byte and returns a pointer to it.

## How to Use
Each function is implemented separately in C. To test the implementations, compile and run the corresponding test files.

```bash
gcc -o app.exe  mystring.c main.c
./app
```

## Contribution
Feel free to contribute by improving implementations, adding optimizations, or providing additional test cases.

