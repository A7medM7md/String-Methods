#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"

uint32 my_strlen(const char *str) /* O(n) */
{
    const char *ptrstr = str;
    uint32 length = 0;

    if (NULL == str)
    {
        printf("Error: NULL pointer!\n");
        length = -1;
    }
    else
    {
        while ('\0' != *ptrstr) /*strlen doesnot count NULL character '\0'*/
        {
            length++;
            ptrstr++;
        }
    }

    return length;
}

char *my_strcpy(char *dest, const char *src)
{
    char *RetVal = dest;
    const unsigned char *PtrSrc = (const unsigned char *)src;
    unsigned char *PtrDest = (unsigned char *)dest;
    if ((NULL == src) || (NULL == dest))
    {
        printf("Error: NULL pointer!\n");
        RetVal = NULL;
    }
    else if (dest == src)
    {
        RetVal = dest;
    }
    else
    {
        while ('\0' != *PtrSrc)
        {
            *PtrDest++ = *PtrSrc++;
        }
        *PtrDest = '\0';
    }

    return RetVal;
}

char *my_strncpy(char *dest, const char *src, int bytes)
{
    char *RetVal = dest;
    const unsigned char *PtrSrc = (const unsigned char *)src;
    unsigned char *PtrDest = (unsigned char *)dest;
    if ((NULL == src) || (NULL == dest))
    {
        printf("Error: NULL pointer!\n");
        RetVal = NULL;
    }
    else if (dest == src)
    {
        RetVal = dest;
    }
    else
    {
        while (bytes--)
        {
            if ('\0' == *PtrSrc)
            {
                *PtrDest++ = *PtrSrc;
            }
            else
            {
                *PtrDest++ = *PtrSrc++;
            }
        }
    }

    return RetVal;
}

char *my_strcat(char *dest_str, const char *src_str)
{
    char *destptr = dest_str;     // This should be large enough to contain the concatenated resulting string.
    const char *srcptr = src_str; // This should not overlap the destination.
    char *RetVal = dest_str;

    if (NULL == dest_str || NULL == src_str)
    {
        printf("Error: NULL pointer!\n");
        RetVal = NULL;
    }
    else
    {
        while ('\0' != *destptr)
        {
            destptr++;
        }

        while ('\0' != *srcptr)
        {
            *destptr++ = *srcptr++;
        }

        *destptr = '\0';
    }

    return RetVal;
}

char *my_strncat(char *dest_str, const char *src_str, int bytes)
{
    char *destptr = dest_str;
    const char *srcptr = src_str;
    char *RetVal = dest_str;

    if (NULL == dest_str || NULL == src_str)
    {
        printf("Error: NULL pointer!\n");
        RetVal = NULL;
    }
    else
    {
        while ('\0' != *destptr)
        {
            destptr++;
        }

        while (bytes--)
        {
            *destptr++ = *srcptr++;
        }

        *destptr = '\0';
    }

    return RetVal;
}

signed int my_strcmp(const void *str1, const void *str2)
{
    signed int RetVal = 0;
    const unsigned char *PtrStr1 = (const unsigned char *)str1;
    const unsigned char *PtrStr2 = (const unsigned char *)str2;

    if ((NULL == str1) || (NULL == str2))
    {
        printf("Error: NULL pointer!\n");
    }
    else
    {
        if (PtrStr1 == PtrStr2) // str1 and str2 points to the same memory location
        {
            RetVal = 0;
        }
        else // Comparing Process
        {
            while ((*PtrStr1 == *PtrStr2) && (('\0' != *PtrStr1) || ('\0' != *PtrStr2)))
            {
                PtrStr1++;
                PtrStr2++;
            }

            if (*PtrStr1 != *PtrStr2)
            {
                RetVal = (*PtrStr1 > *PtrStr2) ? (*PtrStr1 - *PtrStr2) : (*PtrStr1 - *PtrStr2);
            }
            else
            {
                RetVal = 0;
            }
        }
    }

    return RetVal;
}

signed int my_strncmp(const void *str1, const void *str2, int bytes)
{
    signed int RetVal = 0;
    const unsigned char *PtrStr1 = (const unsigned char *)str1;
    const unsigned char *PtrStr2 = (const unsigned char *)str2;

    if ((NULL == str1) || (NULL == str2))
    {
        printf("Error: NULL pointer!\n");
    }
    else
    {
        if (PtrStr1 == PtrStr2) // str1 and str2 points to the same memory location
        {
            RetVal = 0;
        }
        else // Comparing Process
        {
            while ((bytes--) && (*PtrStr1 == *PtrStr2) && (('\0' != *PtrStr1) || ('\0' != *PtrStr2)))
            {
                PtrStr1++;
                PtrStr2++;
            }

            if ((*PtrStr1 != *PtrStr2) && (-1 != bytes))
            {
                RetVal = (*PtrStr1 > *PtrStr2) ? (*PtrStr1 - *PtrStr2) : (*PtrStr1 - *PtrStr2);
            }
            else
            {
                RetVal = 0;
            }
        }
    }

    return RetVal;
}

char *my_strchr(const void *str, int ch)
{
    unsigned char *PtrStr = (unsigned char *)str;
    char *RetVal = NULL; /*charcter not found*/

    if (NULL == str)
    {
        printf("Error: NULL pointer!\n");
        RetVal = NULL;
    }
    else
    {
        while ('\0' != *PtrStr)
        {
            if ((unsigned char)ch == *PtrStr)
            {
                RetVal = PtrStr;
                break;
            }
            PtrStr++;
        }
    }

    return RetVal;
}

char *my_strrchr(char *str, int chr)
{
    unsigned char *PtrStr = (unsigned char *)str;
    char *RetVal = NULL; /*charcter not found*/

    if (NULL == str)
    {
        printf("Error: NULL pointer!\n");
        RetVal = NULL;
    }
    else
    {
        while ('\0' != *PtrStr)
        {
            if ((unsigned char)chr == *PtrStr)
            {
                RetVal = PtrStr;
            }
            PtrStr++;
        }
    }

    return RetVal;
}

char *my_strstr_brute_force(const char *str1, const char *str2)
{
    char *Pos = NULL;

    if (NULL == str1 || NULL == str2)
    {
        printf("Error: NULL pointer!\n");
        Pos = NULL;
    }
    else if (*str2 == '\0') // If str2 Is Empty String
    {
        Pos = (char *)str1;
    }
    else
    {
        while ('\0' != *str1)
        {
            const char *PtrStr1 = str1;
            const char *PtrStr2 = str2;
            while (('\0' != *PtrStr1) && ('\0' != *PtrStr2) && (*PtrStr1 == *PtrStr2))
            {
                PtrStr1++;
                PtrStr2++;
            }

            if ('\0' == *PtrStr2)
            {
                Pos = (char *)str1;
                break;
            }

            str1++;
        }
    }

    return (Pos);
}

/*
Time Complexity: O(n + m), where n is the size of s1 and m is the size of s2.
Auxiliary Space: O(m), where m is the size of s2.
*/
char *my_strstr_KMP(char *haystack, char *needle)
{
    int M = my_strlen(needle);
    int N = my_strlen(haystack);

    // Calculate LPS Array
    int *LPS = (int *)malloc(M * sizeof(int));
    if (LPS == NULL)
        return NULL; // Faild :(

    LPS[0] = 0;
    int prev = 0;
    int i = 1;

    while (i < M)
    {
        if (needle[i] == needle[prev])
        {
            prev++;
            LPS[i] = prev;
            i++;
        }
        else
        {
            if (prev == 0)
            {
                LPS[i] = 0;
                i++;
            }
            else
            {
                prev = LPS[prev - 1];
            }
        }
    }

    int k = 0;
    int j = 0;

    while (k < N)
    {
        if (needle[j] == haystack[k])
        {
            k++;
            j++;
        }

        if (j == M)
        {
            free(LPS);
            return &haystack[k - j];
        }
        else if (k < N && needle[j] != haystack[k])
        {
            if (j != 0)
            {
                j = LPS[j - 1];
            }
            else
            {
                k++;
            }
        }
    }
    free(LPS); // Free Memory

    return NULL; // No Match
}

int my_strcspn(const char *str1, const char *str2)
{
    const char *PtrStr1 = str1;
    const char *PtrStr2 = str2;
    int RetVal = 0;

    if (NULL == str1 || NULL == str2)
    {
        printf("Error: NULL pointer!\n");
        RetVal = 0;
    }
    else
    {
        while ('\0' != *PtrStr1)
        {
            PtrStr2 = str2;
            while ('\0' != *PtrStr2)
            {
                if (*PtrStr1 == *PtrStr2)
                {
                    break;
                }
                PtrStr2++;
            }

            if ('\0' != *PtrStr2)
            {
                break;
            }
            PtrStr1++;
        }

        RetVal = PtrStr1 - str1; /*This Cover Both match case and non-match case*/
    }

    return RetVal;
}

int my_strspn(const char *str1, const char *str2)
{
    const char *PtrStr1 = str1;
    const char *PtrStr2 = str2;
    // char isEqual = 0;
    int RetVal = 0;

    if (NULL == str1 || NULL == str2)
    {
        printf("Error: NULL pointer!\n");
        RetVal = 0;
    }
    else
    {
        while ('\0' != *PtrStr1)
        {
            PtrStr2 = str2;
            while ('\0' != *PtrStr2)
            {
                if (*PtrStr1 == *PtrStr2)
                {
                    break;
                }
                PtrStr2++;
            }

            if ('\0' == *PtrStr2)
            {
                break;
            }

            PtrStr1++;
        }

        RetVal = PtrStr1 - str1;
    }

    return RetVal;
}

char *my_strpbrk(const char *s1, const char *s2)
{
    const char *PtrStr1 = s1;
    const char *PtrStr2 = s2;
    char *RetVal = NULL;

    if (NULL == s1 || NULL == s2)
    {
        printf("Error: NULL pointer!\n");
        RetVal = NULL;
    }
    else
    {
        while ('\0' != *PtrStr1)
        {
            PtrStr2 = s2;
            while ('\0' != *PtrStr2)
            {
                if (*PtrStr1 == *PtrStr2)
                {
                    RetVal = (char *)PtrStr1;
                    break;
                }
                PtrStr2++;
            }

            if ('\0' != *PtrStr2)
            {
                break;
            }
            PtrStr1++;
        }
    }

    return RetVal;
}

char *my_strtok(char *str, const char *sep)
{
    char *PtrStr = str;
    const char *PtrSep = sep;
    int size = 0;
    while ('\0' != *PtrStr)
    {
        char *start = my_strstr_brute_force(PtrStr, PtrSep);
        if (NULL == start)
        {
            break;
        }
        while ('\0' != *PtrSep)
        {
            *start = '\0';
            start++;
            PtrSep++;
        }
        PtrSep = sep;
        PtrStr = start;
        size++;
    }

    char *substrings = (char *)malloc(size);

    if (NULL == str || NULL == sep)
    {
        return str;
    }
}

signed int my_strcoll(const char *str1, const char *str2)
{
    return my_strcmp(str1, str2);
    /*
    --> function performs the comparison based on the rules of the current locale’s LC_COLLATE category.
    Essential when dealing with strings in multiple languages or locales,
    as it respects the linguistic and cultural sorting rules of the locale.
    It’s useful for internationalization where accurate and culturally appropriate string comparison is needed.
    */
}

void *my_memset(void *const str, int value, int bytes)
{
    unsigned char *ptr = (unsigned char *)str; // No need to do Explicit Casting
    // Already Implicit Casting Done
    if (NULL == str)
    {
        printf("Error: NULL pointer!\n");
        return NULL;
    }

    while (bytes--)
    {
        *ptr++ = (unsigned char)value;
    }

    return str;
}

signed int my_memcmp(const void *str1, const void *str2, int bytes)
{
    signed int RetVal = 0;
    const unsigned char *PtrStr1 = (const unsigned char *)str1;
    const unsigned char *PtrStr2 = (const unsigned char *)str2;

    if ((NULL == str1) || (NULL == str2))
    {
        printf("Error: NULL pointer!\n");
    }
    else
    {
        if (PtrStr1 == PtrStr2) // str1 and str2 points to the same memory location
        {
            RetVal = 0;
        }
        else // Comparing Process
        {
            while (bytes--)
            {
                if (*PtrStr1 != *PtrStr2)
                {
                    RetVal = (*PtrStr1 > *PtrStr2) ? (*PtrStr1 - *PtrStr2) : (*PtrStr1 - *PtrStr2);
                    break;
                }
                PtrStr1++;
                PtrStr2++;
            }
        }
    }
    return RetVal;
}

// it's like char* strncpy(char* dest, const char* src, int bytes);
void *my_memcpy(void *dest, const void *src, int bytes)
{
    void *RetVal = dest;
    const unsigned char *PtrSrc = (const unsigned char *)src;
    unsigned char *PtrDest = (unsigned char *)dest;
    if ((NULL == src) || (NULL == dest))
    {
        printf("Error: NULL pointer!\n");
        RetVal = NULL;
    }
    else if (src == dest)
    {
        RetVal = dest;
    }
    else
    {
        while (bytes--)
        {
            *PtrDest++ = *PtrSrc++;
        }
    }

    return RetVal;
}

void *my_memmove(void *dest, const void *src, int bytes)
{
    int n = bytes;
    void *RetVal = dest;
    const unsigned char *PtrSrc = (const unsigned char *)src;
    unsigned char *PtrDest = (unsigned char *)dest;
    if ((NULL == src) || (NULL == dest))
    {
        printf("Error: NULL pointer!\n");
        RetVal = NULL;
    }
    else if (src == dest)
    {
        RetVal = dest;
    }
    else
    {
        if (PtrSrc < PtrDest && PtrDest < PtrSrc + bytes) // If there is an overlap
        {
            // unsigned char *buffer = (unsigned char *)malloc(bytes);
            PtrDest += bytes;
            PtrSrc += bytes;
            while (bytes--)
            {
                *(--PtrDest) = *(--PtrSrc);
            }
        }
        else
        {
            while (bytes--)
            {
                *PtrDest++ = *PtrSrc++;
            }
        }
    }

    return RetVal;
}

void *my_memchr(const void *str, int ch, int bytes)
{
    unsigned char *PtrStr = (unsigned char *)str;
    void *RetVal = NULL; /*ch Not Found!!*/
    if (NULL == str)
    {
        printf("Error: NULL pointer!\n");
        RetVal = NULL;
    }
    else
    {
        while (bytes--)
        {
            if ((unsigned char)ch == *PtrStr)
            {
                RetVal = PtrStr;
                break;
            }
            PtrStr++;
        }
    }

    return RetVal;
}
