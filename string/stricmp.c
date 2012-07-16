/* \file
 * \brief Implementation of stricmp
 *
 * \author Peter 'png' Hille <peter@das-system-networks.de>
 */
#include <ctype.h>

/* \brief Compare Strings without Case Sensitivity
 *
 * stricmp compares s1 and s2 without sensitivity to case. All alphabetic
 * characters in the two arguments s1 and s2 are converted to lowercase
 * before the comparision.
 *
 * The function operates on null-ended strings. The string arguments to the
 * function are expected to contain a null character (\0) at the end of the
 * string.
 *
 * \return A value indicating the relationship between the two strings similar
 * to the one returned by strcmp(3)
 *
 * \see http://publib.boulder.ibm.com/infocenter/iseries/v7r1m0/index.jsp?topic=%2Frtref%2Fstricmp.htm
 */
int stricmp(const char* s1, const char* s2) {
  while (tolower((unsigned char) *s1) == tolower((unsigned char) *s2)) {
    if (*s1 == '\0')
      return 0;
    s1++; s2++;
  }

  return (int) tolower((unsigned char) *s1) -
    (int) tolower((unsigned char) *s2);
}


