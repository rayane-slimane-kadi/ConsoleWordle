#include <stdio.h>
#include <stdlib.h>

int totalLines() {

  char c;
  int totalLines;

  FILE *fp = fopen("accounts.txt", "r");

// coded with help from geeksforgeeks
  while (!feof(fp)) {
    c = getc(fp);
    if (c == '\n') {
      totalLines++;
    }
  }
  // printf("\n\n\n%d\n\n\n", totalLines);
  // printf("");  // code doesnt work without this for some reason
  fclose(fp);
  // printf("\n\n\n%d\n\n\n", totalLines);

  return totalLines;
}
