#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern char* strtolower(char*);
extern char* strntolower(char*, size_t);

int main(void) {
  char foo[] = "FOO";
  char *bar;
  char bla[] = "FOObar";

  printf("strtolower/strntolower tests:\n");

  printf("-- #1: strtolower\n"
	 "\tfoo = '%s', bar = strtolower(foo) = '%s'\n",
	 foo, bar = strtolower(foo));
  if (!(strcmp(bar, "foo") == 0)) {
    printf("!! bar != 'foo'; case conversion failed!\n");
    return EXIT_FAILURE;
  }
  printf("-- bar == 'foo'; test passed :-)\n");

  printf("-- #2: strntolower\n"
	 "\tbla = '%s', bar = strntolower(bla, 3) = '%s'\n",
	 bla, bar = strntolower(bla, 3));
  if (!(strcmp(bar, "foobar") == 0)) {
    printf("!! bar != 'foobar'; case conversion failed!\n");
    return EXIT_FAILURE;
  }
  printf("--bar == 'FOObar'; test passed :-)\n");

  return EXIT_SUCCESS;
}
