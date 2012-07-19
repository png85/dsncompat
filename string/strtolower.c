/** \file
 * \brief Implementation of strtolower/strntolower
 */
#include <ctype.h>
#include <stddef.h>

/** \brief Convert string to lower case
 *
 * Converts the given \0-terminated string to lower case.
 *
 * \param s Pointer to \0-terminated C string
 *
 * \return Pointer to the string converted to lower case
 *
 * \note In debug builds the given pointer is checked for NULL values
 * using assert(3)
 */
const char* strtolower(char* s) {
  assert(s != NULL);

  char* p = s;
  while (*p != '\0') {
    *p = tolower(*p);
    p++;
  }

  return s;
}

/** \brief Convert string to lower case
 *
 * Converts at most n characters of the given \0-terminated string to 
 * lower case.
 *
 * \param s Pointer to \0-terminated C string
 * \param n Max numer of characters to convert
 *
 * \return Pointer to the string converted to lower case
 *
 * \note In debug builds the given pointer is checked for NULL values
 * using assert(3)
 */
const char* strntolower(char* s, size_t n) {
  assert(s != NULL);
  assert(n >= 0);

  if (n == 0)
    return s;

  char *p = s;
  while (n > 0 && *p != '\0') {
    *p = tolower(*p);
    p++;
    n--;
  }

  return s;
}
