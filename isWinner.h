#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>

// Compares guess and word
int isWinner(char word[5], char guess[5]) {
  if (strcasecmp(word, guess) ==
      0) { // if word == guess regardless of case, return 1
    return 1;
  } else { // else, return false
    return 0;
  }
}
