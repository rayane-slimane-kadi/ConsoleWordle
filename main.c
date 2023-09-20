#include "authentication.h"
#include "checkWord.h"
#include "getWord.h"
#include "isWinner.h"
#include "totalLines.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>

int main(void) {

  int found = 0;
  char guess[5];
  system("clear");
  int attempts = 6;
  int playAgain = 1;

  typedef struct {
    char username[15];
    int pin;
    int gamesPlayed;
    int wins;
    int losses;
  } Account;
  Account user[50];

  int choice;                            // choice for login or signup
  int validUsername = 0;




  int currentUser = authentication();
  int lineNumber = 0;
  lineNumber = totalLines();
    // printf("***************%d***********", lineNumber);

  FILE *fp = fopen("accounts.txt", "r"); // opening file

  
   while (!feof(fp)) {
    for (int i = 0; i < 50; i++) {
      fscanf(fp, "%s %d %d %d %d", user[i].username, &user[i].pin,
             &user[i].gamesPlayed, &user[i].wins, &user[i].losses);
    }
  }
  fclose(fp);

  // printf("%s\n\n", getWord());

  while (playAgain == 1) {
  char *word = getWord();
    attempts = 6;
    // system("clear");
    user[currentUser].gamesPlayed++;
    while (attempts > 0 && !isWinner(word, guess)) {
      printf("Guess a word: ");
      scanf("%s", guess);
      checkWord(word, guess);
      printf("\n\n");
      if (isWinner(word, guess)) {
        found = 1;
        break;
      } else {
        attempts--;
      }
    }

    if (found) {
      printf("TOTAL LINES: %d\n", lineNumber);
      user[currentUser].wins++;
      // printf("CURRENT USER: %d", currentUser);
      fp = fopen("accounts.txt", "w");
      for (int i = 0; i < lineNumber; i++) {
        fprintf(fp, "%s %d %d %d %d\n", user[i].username, user[i].pin,
                user[i].gamesPlayed, user[i].wins, user[i].losses);
      }
      fclose(fp);

      printf("\n\nYOU WIN!\n\nThe word was: %s\n\n", word);
      printf("Play again?\n\n1. Yes\n2. No\n\n--> ");
      scanf("%d", &playAgain);
    }

    else {
            printf("TOTAL LINES: %d\n", lineNumber);

      user[currentUser].losses++;
      printf("CURRENT USER: %d", currentUser);

      fp = fopen("accounts.txt", "w");
      for (int i = 0; i < lineNumber; i++) {
        fprintf(fp, "%s %d %d %d %d\n", user[i].username, user[i].pin,
                user[i].gamesPlayed, user[i].wins, user[i].losses);
      }
      fclose(fp);

      printf("\n\nGAME OVER :(\n\nThe word was: %s", word);
      printf("\n\nPlay again?\n\n1. Yes\n2. No\n\n--> ");
      scanf("%d", &playAgain);
  
    }
  }

  return 0;
}
