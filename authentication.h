#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>

int authentication() {
  int totalLines = 0;

  // initializing structure
  typedef struct {
    char username[15];
    int pin;
    int gamesPlayed;
    int wins;
    int losses;
  } Account;
  Account user[50];

  FILE *fp = fopen("accounts.txt", "r"); // opening file
  int choice;                            // choice for login or signup
  int validUsername = 0;
  int currentUser;

  // Filling in all the information
  while (!feof(fp)) {
    for (int i = 0; i < 50; i++) {
      fscanf(fp, "%s %d %d %d %d", user[i].username, &user[i].pin,
             &user[i].gamesPlayed, &user[i].wins, &user[i].losses);
    }
  }
fclose(fp);
  printf("1. Login\n2. Signup\n\n--> ");
  scanf("%d", &choice);

  if (choice == 1) {
    int isLoggedIn = 0; // Flag to check if user is logged in
    char nameInput[15];
    int pinInput;

    system("clear");

    while (isLoggedIn == 0) {
      // Prompting the user to log in

      printf("Username: "); // Asking for username
      scanf("%s", nameInput);

      // Going through the file
      for (int i = 0; i < 50; i++) {

        // Looking for the username in the file
        if (strcasecmp(user[i].username, nameInput) == 0) {

          // If the username is found, prompt for password
          printf("Pin: ");
          scanf("%d", &pinInput);

          // if password is right, login
          if (user[i].pin == pinInput) {
            printf("Success! ");
            currentUser = i;

            isLoggedIn = 1;
          }
        }
      }
      // else: prints an error
      system("clear");
      if (isLoggedIn == 0) {
        printf("Error: Username or Password Incorrect.\n\n");
      }
    }
  }

  // If user chose to signup
  else if (choice == 2) {

    // Open file in append mode
    fp = fopen("accounts.txt", "a");
    char username[15];
    int pin;

    system("clear");

    while (validUsername == 0) {

      printf("Choose a username (15 Characters Max)\n\n--> "); // Asking for
                                                               // username
      scanf("%s", username);

      for (int i = 0; i < 50; i++) {
        if (strcasecmp(user[i].username, username) == 0) {
          system("clear");
          printf("Error: Username Already Taken.\n\n");
          validUsername = 0;
          break;
        } else {
          validUsername = 1;
        }
      }

      // If username is longer than 15 chars, rejects username
      while (strlen(username) > 15) {
        system("clear");
        printf("Invalid Username.\n\nChoose a username (15 Characters "
               "Max)\n\n--> ");
        scanf("%s", username);
      }
    }
    // When valid username, prints it to file
    fprintf(fp, "%s ", username);

    // Prompting for a pin
    system("clear");
    printf("Pick a 4 digit pin code\n\n--> ");
    scanf("%d", &pin);

    // If pin is smaller or larger than 4 digits, rejects pin
    while (pin < 999 || pin > 9999) {
      system("clear");
      printf("Invalid Pin.\n\nPick a 4 digit pin code\n\n--> ");
      scanf("%d", &pin);
    }
    fprintf(fp, "%d 0 0 0\n", pin); // prints pin to file along with stats
                                    // for games played, wins and losses

    fclose(fp);
    system("clear");
    printf("Account creation is Successful!\n\nNow login with your new "
           "account:\n\n");

    fp = fopen("accounts.txt", "r");

    while (!feof(fp)) {
      for (int i = 0; i < 50; i++) {
        fscanf(fp, "%s %d %d %d %d", user[i].username, &user[i].pin,
               &user[i].gamesPlayed, &user[i].wins, &user[i].losses);
      }
    }
    fclose(fp);

    int isLoggedIn = 0; // Flag to check if user is logged in
    char nameInput[15];
    int pinInput;

    while (isLoggedIn == 0) {
      // Prompting the user to log in

      printf("Username: "); // Asking for username
      scanf("%s", nameInput);

      // Going through the file
      for (int i = 0; i < 50; i++) {

        // Looking for the username in the file
        if (strcasecmp(user[i].username, nameInput) == 0) {

          // If the username is found, prompt for password
          printf("Pin: ");
          scanf("%d", &pinInput);

          // if password is right, login
          if (user[i].pin == pinInput) {
            printf("Success! ");
            isLoggedIn = 1;
            currentUser = i;
          }
        }
      }
      // else: prints an error
      system("clear");
      if (isLoggedIn == 0) {
        printf("Error: Username or Password Incorrect.\n\n");
      }
    }
  }

  int option;

  printf("Welcome %s!\n\n\n", user[currentUser].username);
  printf("Here's what your profile looks like:\n\n");
  printf("Games Played: %d\n", user[currentUser].gamesPlayed);
  printf("Wins: %d\n", user[currentUser].wins);
  printf("Losses: %d\n", user[currentUser].losses);

  printf("\n\n1. Play Game");
  printf("\n2. Quit\n\n--> ");
  scanf("%d", &option);

  if (option == 1) {
    system("clear");
  } else if (option == 2) {
    exit(0);
  }

  return currentUser;
}
