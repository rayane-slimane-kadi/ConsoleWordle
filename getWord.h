#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>

// Random num generator
int randomInt(int low, int high) { return rand() % (high - low + 1) + low; }

char *getWord() {
  srand((unsigned int)time(NULL)); // Needed for random number
  static char word[5];
  int random = randomInt(1, 410);           // Random number from 1 to file size
  FILE *fpt = fopen("dictionary.txt", "r"); // Open file

  for (int i = 0; i < random; i++) { // Loop that goes to the randomth word
    fscanf(fpt, "%s", word);         // scanf the random word in word
  }
  fclose(fpt); // closes the file

  return word; // returns word
}
