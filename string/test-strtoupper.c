#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern char* strtoupper(char*);
extern char* strntoupper(char*, size_t);

int main(void) {
  char foo[] = "foo";
  char *bar;
  char bla[] = "FOObar";

  printf("strtoupper/strntoupper tests:\n");

  printf("-- #1: strtoupper\n"
	 "\tfoo = '%s', bar = strtoupper(foo) = '%s'\n",
	 foo, bar = strtoupper(foo));
  if (!(strcmp(bar, "FOO") == 0)) {
    printf("!! bar != 'FOO'; case conversion failed!\n");
    return EXIT_FAILURE;
  }
  printf("-- bar == 'FOO'; test passed :-)\n");

  printf("-- #2: strntoupper\n"
	 "\tbla = '%s', bar = strntoupper(bla, 3) = '%s'\n",
	 bla, bar = strntoupper(bla, 3));
  if (!(strcmp(bar, "FOObar") == 0)) {
    printf("!! bar != 'FOObar'; case conversion failed!\n");
    return EXIT_FAILURE;
  }
  printf("--bar == 'FOObar'; test passed :-)\n");

  return EXIT_SUCCESS;
}
