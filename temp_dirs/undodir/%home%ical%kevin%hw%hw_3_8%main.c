Vim�UnDo� �O�|� MC)g���oR�O8H�9�b~H�G[   &                                   \��    _�                             ����                                                                                                                                                                                                                                                                                                                                       4           V        \��     �              4   #include <stdio.h>   #include <stdlib.h>   #include "string.h"       
int main()   {       //declare variable   "    char str[20];//original string       char str1[20];//temporary       char *ptr;   
    int n;       char c;           //enter a string        printf("original string: ");           scanf(" %s", str);           //connected string   !    printf("connected string: ");           scanf(" %s", str1);       *    printf("want to add how many char: ");       scanf(" %d", &n);       ?    printf("after connected: \"%s\"\n", Strncat(str, str1, n));           //compare string        printf("compared string: ");           scanf(" %s", str1);       .    printf("want to compare how many char: ");       scanf(" %d", &n);       @    printf("consequence of compare: %d\n", Strncmp(str,str1,n));            //search character in string   !    printf("search character: ");       scanf(" %c", &c);           ptr = Strchr(str, c);           if ( *ptr == NULL)   :        printf("the character doesn't exist in string\n");       else   ;        printf("string after character(contain): %s", ptr);           return 0;   }    5�_�                             ����                                                                                                                                                                                                                                                                                                                                                  V        \��    �                   5��