#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"


char str[] = "Ahmed";

char name1[20] = "Ahmed Elgebaly";
char name2[20] = "Essam";

char word1[] = "Ahmed";
char word2[] = "Emad";

int main()
{
    printf("------------ my_memset Function Test ------------\n");
    
    printf("%s \n", str);
    my_memset(str + 1,'7', 1);
    printf("%s \n", str);
    /* ------------------------------------------------- */

    printf("------------ my_memcpy Function Test ------------\n");

    printf("%s \n", name1);
    printf("%s \n", name2);

    my_memcpy(name2 + 5, name1 + 5, 9); 
    
    printf("%s \n", name2);
    /* ------------------------------------------------- */

    printf("------------ my_memcmp Function Test ------------\n");


    signed int Res = my_memcmp(word1, word2, 5);
    printf("%d \n", Res);

    ((0 == Res)? printf("str1 equals str2\n")
    : ((0 > Res)? printf("str1 less than str2\n") 
    : printf("str2 less than str1\n")));
    /* ------------------------------------------------- */

    printf("------------ my_memchr Function Test ------------\n");

    unsigned char MyEmail[30] = "ahmedelgebaly2511@gmail.com";
    char ch = 'd';
    unsigned char* result = (unsigned char *)my_memchr(MyEmail, ch, 30);

    if (result != NULL) {
        printf("'%c' found at position %ld\n", ch, result - MyEmail);
    } else {
        printf("'%c' not found in the string\n", ch);
    }

    printf("%s \n", result);

    /* ------------------------------------------------- */

    printf("------------ my_strcat Function Test ------------\n");


    char dest_str[50] = "C ";
    const char src_str[] = "JAVA";

   // Concatenate src_str to dest_str
    my_strcat(dest_str, src_str);

   // The result store in destination string
    printf("%s \n", dest_str); 

    printf("----------------\n");

    char str[100]; 
    
    // Copy the first string to the variable
    my_strcpy(str, "Ahmed "); 

    // String concatenation 
    my_strcat(str, "Elgebaly"); 

    // Show the result
    printf("%s\n", str);

    /* ------------------------------------------------- */

    printf("------------ my_strcspn Function Test ------------\n");

    int len;
   // Intializing string(Unmatched Characters)
    const char str1[] = "Xutorialspoint";
    const char str2[] = "Textbook";

    len = my_strcspn(str1, str2);

    printf("First matched character is at %d\n", len);

    /* ------------------------------------------------- */

    printf("------------ my_strlen Function Test ------------\n");

    char sstr[50];
    int llen;
    my_memcpy(sstr, "This is tutorialspoint",50);
    llen = my_strlen(sstr);
    printf("Length of |%s| is |%d|\n", sstr, llen);

    /* ------------------------------------------------- */

    // printf("------------ my_strtok Function Test ------------\n");



    /* ------------------------------------------------- */

    printf("------------ my_memmove vs my_memcpy in overlap ------------\n");

    char strr[100] = "Learningisfun"; 
    char *first, *second; 
    first = strr; 
    second = strr; 
    printf("Original string :%s\n ", strr); 
    
    // when overlap happens then it just ignore it 
    my_memcpy(first + 8, first, 10); 
    printf("memcpy overlap : %s\n ", strr); 

    // when overlap it start from first position 
    my_memmove(second + 8, first, 10); 
    printf("memmove overlap : %s\n ", strr); 
    /* ------------------------------------------------- */

    printf("------------ my_strstr_bruteforce Test ------------\n");
    printf("------------    my_strstr_KMP Test  ------------\n");

    char *str11 = "zzabcdef", *str22 = "abc";
    printf("%s \n", my_strstr_brute_force(str11, str22));
    printf("%s \n", my_strstr_KMP(str11, str22));

    /* ------------------------------------------------- */

    printf("------------    my_strncpy Test  ------------\n");
    /*
    If src is shorter than n, the remainder of dest will be padded with null characters,
    ensuring the destination string is properly null-terminated.
    */
    char src1[] = "Hi";      // Length of src is 2
    char dest1[10];          // Length of dest is 10

    my_strncpy(dest1, src1, 10); // Copy 10 characters from src to dest

    printf("Copied string: '%s'\n", dest1);
    printf("Destination array content (in hex): ");
    for (int i = 0; i < 10; i++) {
        printf("%02x ", (unsigned char)dest1[i]);
    }
    printf("\n");

    printf("---------------------\n");
    /*
    The strncpy() function does not null-terminate the destination string
    if the length of src is greater than or equal to n.
    Therefore, it is important to manually null-terminate the destination string.
    */
        // Source string
    char src2[] = "Boyer-Moore Algorithm";
    // Destination string
    char dest2[20];

    // Copy a fixed-length substring from src to dest
    my_strncpy(dest2, src2 + 6, 5);

    // Null-terminate the destination string
    dest2[5] = '\0';

    // Print the destination string
    printf("Fixed-length substring: %s\n", dest2);
    /* ------------------------------------------------- */

    printf("------------ my_strcmp Function Test ------------\n");

    // b has less ASCII value than g
    char first_str[] = "bfb";
    char second_str[] = "gfg";
    
    int res = my_strcmp(first_str, second_str);
    
    if (res==0)
        printf("Strings are equal");
    else
        printf("Strings are unequal");
    
    printf("\nValue returned by strcmp() is: %d \n" , res);


    /* ------------------------------------------------- */

    printf("------------ my_strncmp Function Test ------------\n");

        // Take any two strings
    char ssttrr1[10] = "akash";
    char ssttrr2[10] = "aksh";

    // Compare strings using strncmp()
    int retresult = my_strncmp(ssttrr1, ssttrr2, 4);

    if (retresult == 0) {
        // num is the 3rd parameter of strncmp() function
        printf("ssttrr1 is equal to ssttrr2 up to num characters\n");
    }
    else if (retresult > 0)
        printf("ssttrr1 is greater than ssttrr2\n");
    else
        printf("ssttrr2 is greater than ssttrr1\n");


    printf("Value returned by strncmp() is: %i \n", retresult);


    /* ------------------------------------------------- */

    printf("------------ my strcmp vs my_strncmp vs my_memcmp Function Test ------------\n");

    const char s1[] = "atoms\0\0\0\0";  // extra null bytes at end
    const char s2[] = "atoms\0abc";     // embedded null byte
    const char s3[] = "atomsaaa";

    printf("%i", my_strcmp(s1, s2) == 0); /*1*/     // strcmp stops at null terminator
    printf("%i", my_strcmp(s1, s3) != 0); /*1*/     // Strings are different
    printf("%i", my_strncmp(s1, s3, 5) == 0); /*1*/ // First 5 characters of strings are the same
    printf("%i", my_memcmp(s1, s3, 5) == 0); /*1*/  // First 5 bytes are the same
    printf("%i", my_strncmp(s1, s2, 8) == 0); /*1*/ // Strings are the same up through the null terminator
    printf("%i", my_memcmp(s1, s2, 8) != 0); /*1*/  // First 8 bytes are different


    /* ------------------------------------------------- */
    printf("------------ my_strchr Function Test ------------\n");

    //  // Original string containing username and password
    // const char* str = "GeeksforGeeks:abc@123";
    // // Delimiter to separate username and password

    // char delimiter = ':';
    // // Find the position of the delimiter in the string
    // char* delimiter_position = my_strchr(str, delimiter);

    // // If the delimiter is found in the string
    // if (delimiter_position != NULL) {
    //     // Calculate the length of the username
    //     size_t username_length = delimiter_position - str;

    //     // Allocate memory for the username and copy the
    //     // username part of the string
    //     char username[username_length + 1];
    //     my_strncpy(username, str, username_length);

    //     // Null-terminate the username string
    //     username[username_length] = '\0';

    //     // The password starts right after the delimiter
    //     char* password = delimiter_position + 1;

    //     // Print the extracted username and password
    //     printf("Username: %s\n", username);
    //     printf("Password: %s\n", password);
    // }
    // else {
    //     // If the delimiter is not found, print an error
    //     // message
    //     printf("Delimiter not found.\n");
    // }


    /* ------------------------------------------------- */
    printf("------------ my_strrchr Function Test ------------\n");

    char ahm[] = "ahmehed";

    printf("%s \n", my_strchr(ahm,'h'));
    printf("%s \n", my_strrchr(ahm,'h'));

    /* ------------------------------------------------- */

    printf("------------ my_strspn Function Test ------------\n");

    char ss1[] = "583914502ABJKTMNTY";
    char ss2[] = "0128934567";

    int pos = my_strspn(ss1, ss2);

    printf("pos: %d\n", pos);

    char *remaining = ss1 + pos;

    printf("remaining: %s\n", remaining);

    /* ------------------------------------------------- */

    printf("------------ my_strcspn Function Test ------------\n");

    char s[] = "ADSFASFAS42312321";
    char num[] = "0123894567";

    int init = my_strcspn(s, num);

    printf("init: %d \n", init);

    char *numcode = s + init;

    printf("numcode: %s\n", numcode);


    /* ------------------------------------------------- */


    printf("------------my_strcspn is versus of my_strspn------------\n");

    const char *a1 = "abcdef123";
    const char *a2 = "123";

    int len1 = my_strspn(a1, a2); // len1 will be 0, as 'a' is not in "123"
    int len2 = my_strcspn(a1, a2); // len2 will be 6, as '1' is the first match

    printf("strspn: %zu\n", len1); // Output: 0
    printf("strcspn: %zu\n", len2); // Output: 6

    /*
    //strspn\\: This function returns the length of the initial segment of str1
    that consists entirely of characters found in str2. In other words, 
    it counts how many characters at the beginning of str1 belong to the set of characters in str2.

    \\strcspn\\: This function returns the length of the initial segment of str1 
    that consists of characters not found in str2. 
    It counts how many characters at the beginning of str1 are not part of the set of characters in str2.
    */

    /* ------------------------------------------------- */

    printf("------------ my_strpbrk Function Test ------------\n");
    	// Declaring three strings 
	char so[] = "geeksforgeeks"; 
	char st[] = "kite"; 
	char *t;
	// Checks for matching character 
	// first match found at "e" 
	t = my_strpbrk(so, st); 
	if (t != 0) {
		printf("First matching character: %c\n", *t); 
        printf("%s\n", t); 
    }
	else
		printf("Character not found"); 

    /* ------------------------------------------------- */

    return 0;
}