#ifndef _MY_STRING_
#define _MY_STRING_

#define NULL ((void *)0)
typedef unsigned int uint32;

uint32 my_strlen(const char *str);
char* my_strcpy(char* dest, const char* src);
char* my_strncpy(char* dest, const char* src, int bytes);
char *my_strcat(char *dest_str, const char *src_str);
char *my_strncat(char *dest_str, const char *src_str, int bytes);
signed int my_strcmp(const void *str1, const void *str2);
signed int my_strncmp(const void *str1, const void *str2, int bytes);
char *my_strchr(const void *str, int ch);
char* my_strrchr(char* str, int chr);
char *my_strstr_brute_force(const char *str1, const char *str2);
char *my_strstr_KMP(char *haystack, char *needle);
int my_strcspn(const char *str1, const char *str2);
int my_strspn(const char *str1, const char *str2);
char *my_strpbrk(const char *s1, const char *s2);
char *my_strtok(char *str, const char *delim);
signed int my_strcoll(const char *str1, const char *str2);



void *my_memset(void *const str, int c, int n);
void *my_memcpy(void *str2, const void *str1, int bytes);
void *my_memmove(void *dest, const void *src, int bytes);
int my_memcmp(const void *str1, const void *str2, int bytes);
void *my_memchr(const void *str, int ch, int bytes);

#endif /*_MY_STRING_*/