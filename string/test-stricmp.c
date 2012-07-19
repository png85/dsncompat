#include <stdio.h>
#include <stdlib.h>

#include "string.h"

extern int stricmp(const char*, const char*);

int main(int argc, char** argv) {
  char foo[255] = "foo", bar[255] = "bar";
  int r1, r2;

  printf("running tests for string/stricmp.c:\n");

  /* test comparision of two different strings */
  printf("-- #1: comparision of two different strings\n"
	 "\tfoo = '%s', bar = '%s'\n", foo, bar);
  r1 = stricmp(foo, bar);
  r2 = stricmp(bar, foo);
  printf("\tr1 = stricmp(foo, bar); = %d\n"
	 "\tr2 = stricmp(bar, foo); = %d\n", r1, r2);
  if (r1 != -r2) {
    printf("!! #1: r1 != -r2; string comparision failed!\n");
    return EXIT_FAILURE;
  } else {
    printf ("-- #1: r1 == -r1; test passed :-)\n");
  }

  /* comparision of two strings with similar content in different cases */
  sprintf(foo, "fOO"); sprintf(bar, "Foo");
  printf("-- #2: comparision of two strings with similar content in "
	 "different cases:\n"
	 "\tfoo = '%s', bar = '%s'\n", foo, bar);
  r1 = stricmp(foo, bar);
  r2 = stricmp(bar, foo);
  printf("\tr1 = stricmp(foo, bar); = %d\n"
	 "\tr2 = stricmp(bar, foo); = %d\n", r1, r2);
  if (r1 != 0 || r2 != 0) {
    printf("!! #2: one of the return values isn't zero; "
	   "comparision failed!\n");
    return EXIT_FAILURE;
  } else {
    printf("-- #2: r1 == r2 == 0; test passed :-)\n");
  }

  return EXIT_SUCCESS;
}

