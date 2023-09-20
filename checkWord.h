#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

void green() { printf("\033[0;32m"); }  // Sets text colour to green
void yellow() { printf("\033[0;33m"); } // Sets text colour to yellow
void noColor() { printf("\033[0m"); }   // Resets text colour

void checkWord(char word[5], char guess[5]) {

  char invalidLetters[30];
  for (int i = 0; i < 5;
       i++) { // Loop through each character in "word" and "guess"

    // Checks if a letter is in the right location and prints it in green
    if (tolower(word[i]) == guess[i]) {
      green();
      printf("%c ", guess[i]);
      noColor();
    }

    // Checks if a letter is correct but in the wrong location
    else {

      int matchFound = 0; // Flag to check if a match is found

      // Loop through each character in the word to check for a match
      for (int j = 0; j < 5; j++) {
        if (guess[i] ==
            tolower(word[j])) { // Prints text in yellow if a match is found
          yellow();
          printf("%c ", guess[i]);
          noColor();
          matchFound = 1;
          break;
        }
      }
      // If a match was not found prints letter with no colour
      if (!matchFound) {
        invalidLetters[i] = guess[i];
        printf("%c ", guess[i]);
      }
    }
  }
  // printf("\n\nInvalid Letters: ");
  //           for (int i =0; i < strlen(invalidLetters); i++){
  //             printf("%c, ", invalidLetters[i]);
  //           }
  // printf("\n\n\n\n");
}
