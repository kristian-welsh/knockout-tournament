/*
  program.c
  Name: Kristian Welsh
  Candidate Num: 
  Description:
  A program that keeps track of tabel tenis scores.
  xx/xx/xxxx
*/

#include <stdio.h>
#include <string.h>

struct player
{
  char name[33];
};

struct match
{
  struct player player1;
  struct player player2;
  int p1Scores[5];
  int p2Scores[5];
  int gamesPlayed;
};

struct round
{
  struct match matches[8];
  struct player playersAdvancing[8];
  int roundNum;
};

struct data
{
  struct round rounds[3];
  int currentRound;
};

struct round userInputPlayerNames();
void displayPlayerNames(struct round round1);
void displayMenuScreen(void);
void displayRound(int);

int getMenuSelection(void);
struct data switchScreen(int input, struct data);
struct round enterGameResult(struct round round);
void displayMatch(int);
void displayPlayersAdvancing(int);

void clearInputBuffer(void);
void haltProgram(void);

int main(void)
{
  struct player players[5];
  struct data data;
  struct round round1, round2, round3;
  int shouldExit;
  int screenNum;

  puts("Max player name length: 32");
  data.rounds[0] = userInputPlayerNames();
  data.currentRound = 0;

  haltProgram();

  while(screenNum != 5)
  {
    displayMenuScreen();
    screenNum = getMenuSelection();

    printf("\n\n");
    data = switchScreen(screenNum, data);
  }

  haltProgram();

  return 0;
}

struct round userInputPlayerNames()
{
  int matchNum;
  struct match curMatch;
  int matchPlayerNum;
  int playerNum = 1;
  struct round round1;

  round1.roundNum = 1;

  for(matchNum = 0; matchNum < 8; matchNum++)
  {
    curMatch = round1.matches[matchNum];
    printf("Please enter name for player %d: ", playerNum++);
    scanf("%32[^\n]", curMatch.player1.name);
    clearInputBuffer();

    printf("Please enter name for player %d: ", playerNum++);
    scanf("%32[^\n]", curMatch.player2.name);
    clearInputBuffer();

    curMatch.gamesPlayed = 0;
  }
  return round1;
}

void haltProgram(void)
{
  char pausePorgramChar;

  printf("Press any key to continue...");
  scanf("%c", &pausePorgramChar);
}

void displayMenuScreen(void)
{
  printf("* Menu *\n"
         "1. Enter a game result\n"
         "2. Display current round\n"
         "3. Display players advancing\n"
         "4. Display Previous Round\n"
         "5. Exit\n"
         "Please enter menu selection: ");
}

int getMenuSelection(void)
{
  int input;
  scanf("%d", &input);
  clearInputBuffer();
  return input;
}

struct data switchScreen(int input, struct data data)
{
  int curRound = data.currentRound;
  switch(input)
  {
    case 1:
      data.rounds[curRound] = enterGameResult(data.rounds[curRound]);
      break;
    case 2:
      displayRound(curRound);/*display current round*/
      break;
    case 3:
      displayPlayersAdvancing(curRound);/*display advancing*/
      break;
    case 4:
      displayRound(curRound);/*display previous round*/
      break;
  }
  return data;
}

struct round enterGameResult(struct round round)
{
  int matchNum;
  struct match curMatch;
  int player1Score;
  int player2Score;

  printf("Entering a result for round %d:\n"
         "\n"
         "Enter match number to add game results to: ", round.roundNum);
  scanf("%d", &matchNum);
  curMatch = round.matches[matchNum];

  printf("Please enter %s's score: ", "bob");
  scanf("%d", &player1Score);
  curMatch.p1Scores[curMatch.gamesPlayed] = player1Score;

  printf("Please enter %s's score: ", "bill");
  scanf("%d", &player2Score);
  curMatch.p1Scores[curMatch.gamesPlayed] = player2Score;

  curMatch.gamesPlayed++;

  return round;
}

void displayRound(int roundNum)
{
  printf("* Display Round Results *\n"
         "\n"
         "Results for round %d:\n"
         "\n", roundNum);
  displayMatch(1);
}

void displayMatch(int matchNum)
{
  printf("Match %d:\n"
         "+-----------------------------+\n"
         "| %32s |%2d|%2d|%2d|%2d|%2d|\n"
         "+-----------------------------+\n"
         "\n", matchNum, "name here", 1, 2, 3, 4, 5);
}

void displayPlayersAdvancing(int roundNum)
{
  int i;

  printf("Players advancing from round %d:", roundNum);
  for(i = 0; i < 5; i++)
  {
    printf("%s\n", "bob");
  }
}

void clearInputBuffer(void)
{
  /*
  fflush(stdin);
  /**/
  char token;
  do
  {
    token = getchar();
  } while(token != '\n' && token != '\r' && token != EOF);
  /**/
}
