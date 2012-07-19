/** \file
 * \brief Implementation of strtoupper/strntoupper
 */
#include <ctype.h>
#include <stddef.h>

/** \brief Convert string to uppercase
 *
 * Converts the given \0-terminated string to upper case.
 *
 * \param s Pointer to \0-terminated C string
 *
 * \return Pointer to the string converted to upper case
 *
 * \note In debug builds the given pointer is checked for NULL values
 * using assert(3)
 */
const char* strtoupper(char* s) {
  assert(s != NULL);

  char* p = s;
  while (*p != '\0') {
    *p = toupper(*p);
    p++;
  }

  return s;
}


/** \brief Convert string to upper case
 *
 * Converts at most n characters of the given \0-terminated string to 
 * upper case.
 *
 * \param s Pointer to \0-terminated C string
 * \param n Max numer of characters to convert
 *
 * \return Pointer to the string converted to upper case
 *
 * \note In debug builds the given pointer is checked for NULL values
 * using assert(3)
 */
const char* strntoupper(char* s, size_t n) {
  assert(s != NULL);
  assert(n >= 0);

  if (n == 0)
    return s;

  char *p = s;
  while (n > 0 && *p != '\0') {
    *p = toupper(*p);
    p++;
    n--;
  }

  return s;
}
