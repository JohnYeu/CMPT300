#include "mystring.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 *   Implement the following functions: 
 * 
 *   You are NOT allowed to use any standard string functions such as 
 *   strlen, strcpy or strcmp or any other string function.
 */

/*
 *  mystrlen() calculates the length of the string s, 
 *  not including the terminating character '\0'.
 *  Returns: length of s.
 */
int mystrlen (const char *s) 
{
	/* Complete the body of the function */
	int res = 0;
	while (*s++ != '\0') {
		res++;
	}
	return res;
}

/*
 *  mystrcpy()  copies the string pointed to by src (including the terminating 
 *  character '\0') to the array pointed to by dst.
 *  Returns: a  pointer to the destination string dst.
 */
char  *mystrcpy (char *dst, const char *src)
{
	/* Complete the body of the function */
	char *p = dst;
	while (*src != '\0')
	{
		*dst++ = *src++;
	}
	*dst = '\0';
	return p;
}

/*
 * mystrcmp() compares two strings alphabetically
 * Returns: 
 * 	-1 if s1  < s2
 *  	0 if s1 == s2
 *  	1 if s1 > s2
 */
int mystrcmp(const char *s1, const char *s2)
{
	/* Complete the body of the function */
	while (*s1 && *s2 && (*s1 == *s2)) {

		s1++;
		s2++;
	}
	
	return (*s1 - *s2) > 0 ? 1 : (*s1 - *s2) == 0 ? 0 : -1;
}

/*
 * mystrdup() creates a duplicate of the string pointed to by s. 
 * The space for the new string is obtained using malloc.  
 * If the new string can not be created, a null pointer is returned.
 * Returns:  a pointer to a new string (the duplicate) 
 	     or null If the new string could not be created for 
	     any reason such as insufficient memory.
 */
char *mystrdup(const char *s1)
{
	/* Complete the body of the function */
   size_t  length = mystrlen(s1) +1;
   void *new = malloc(length);
   if (new == NULL)
      return NULL;
   return (char *) memcpy(new,s1,length);
}

