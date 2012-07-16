/* \file
 * \brief Functions for operating on C-style strings
 *
 * \author Peter 'png' Hille <peter@das-system-networks.de>
 */
#ifndef DSNCOMPAT_STRING_H
#define DSNCOMPAT_STRING_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef HAVE_STRICMP
  int stricmp(const char* s1, const char* s2);
#endif /* !HAVE_STRICMP */

#ifndef HAVE_STRNICMP
  int strnicmp(const char* s1, const char* s2);
#endif /* !HAVE_STRNICMP */

#ifdef __cplusplus
};
#endif /* __cplusplus */

#enidf /* !DSNCOMPAT_STRING_H */
