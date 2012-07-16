/* \file
 * \brief Implementation of strnicmp
 *
 * \author Peter 'png' Hille <peter@das-system-networks.de>
 */
#include <ctype.h>
#include <stddef.h>
#include <string.h>

/* \brief Compare Strings without Case Sensitivity
 *
 * stricmp compares, at most, the first n characters of s1 and s2 without
 * sensitivity to case. All alphabetic characters in the two arguments
 * s1 and s2 are converted to lowercase before the comparision.
 *
 * The function operates on null-ended strings. The string arguments to the
 * function are expected to contain a null character (\0) at the end of the
 * string.
 *
 * \return A value indicating the relationship between the two strings similar
 * to the one returned by strcmp(3)
 *
 * \see http://publib.boulder.ibm.com/infocenter/iseries/v7r1m0/index.jsp?topic=%2Frtref%2Fstrnicmp.htm
 */
int strncasecmp(const char* s1, const char* s2, size_t n) {
#ifdef HAVE_STRNICMP
  return strnicmp(s1, s2, n);
#else
  if (n == 0)
    return 0;

  do {
    if (tolower((unsigned char) *s1) != tolower((unsigned char) *s2++))
      return (int)tolower((unsigned char)*s1) -
	(int) tolower((unsigned char) *--s2);
    if (*s1++ == 0)
      break;
  } while (--n != 0);

  return 0;
#endif /* !HAVE_STRNICMP */
}
