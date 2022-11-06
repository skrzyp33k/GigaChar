//*
  *
  *
  */

#ifndef _GIGACHAR_H_
#define _GIGACHAR_H_

typedef unsigned short gigachar;

#define GC_BOLD 0b0000000100000000 ///<
#define GC_DIM  0b0000001000000000 ///<
#define GC_ITALIC 0b0000010000000000 ///<
#define GC_UNDERLINE 0b0000100000000000 ///<
#define GC_BLINKING 0b0001000000000000 ///<
#define GC_INVERSE 0b0010000000000000 ///<
#define GC_HIDDEN 0b0100000000000000 ///<
#define GC_STRIKETROUGH 0b1000000000000000 ///<

#define GC_GIGANULL 0 ///<

#define GC_CHAR 0b0000000011111111 ///<
/**
 * @brief Prints gigachar on console output
 * 
 * @param c Gigachar to print
 */
void putgigachar(gigachar c);

/**
 * @brief Prints gigastring on console output
 * 
 * @param gigastring Gigastring to print
 */
void printgigastring(gigachar* gigastring);


/**
 * @brief Creates gigachars array
 * 
 * @param buff 
 * @param buff_length 
 * @param str 
 * @param flags 
 */
void togigastring(gigachar *buff, size_t buff_length, const char* str, gigachar flags);

/**
 * @brief Copies one gigastring to another
 * 
 * @param destination Gigastring destination
 * @param source Gigastring to copy from
 */
void gigastrcpy (gigachar* destination, const gigachar* source);

/**
 * @brief Copies n gigachars from one gigastring to another
 * 
 * @param destination Gigastring destination
 * @param source Gigastring to copy from
 * @param num Number of chars
 */
void gigastrncpy(gigachar* destination, const gigachar* source, size_t num);

/**
 * @brief Concatenates one gigastring to another
 * 
 * @param destination Gigastring destination
 * @param source Gigastring to concatenate from
 */
void gigastrcat (gigachar* destination, const gigachar* source);

/**
 * @brief Concatenates n chars of one gigastring to another
 * 
 * @param destination Gigastring destination
 * @param source Gigastring to concatenate from
 * @param num Number of chars
 */
void gigastrncat(gigachar* destination, const gigachar* source, size_t num);

/**
 * @brief Returns gigastring length in gigachars
 * 
 * @param str Gigastring to get length from
 * @return size_t Number of gigachars
 */
size_t gigastrlen(const gigachar* str);

int gigastrcmp      (const gigachar* str1, const gigachar *str2);
int gigastrcmpfull  (const gigachar* str1, const gigachar *str2);
int gigastrncmp     (const gigachar* str1, const gigachar *str2, size_t num);
int gigastrncmpfull (const gigachar* str1, const gigachar *str2, size_t num);

char tonormalchar(gigachar gc);

#endif