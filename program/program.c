/*
  program.c
  Name: Kristian Welsh
  Candidate Number: 
  Description:
  A program that keeps track of tabel tenis scores.
  xx/xx/xxxx
*/

#include <stdio.h>

void haltProgram(void);
void userInputPlayerNames(char names[5][33]);
void displayPlayerNames(char names[5][33]);

int main(void)
{
  char names[5][33];

  puts("Max player name length: 32");
  userInputPlayerNames(names);
  displayPlayerNames(names);
  haltProgram();
}

void userInputPlayerNames(char names[5][33])
{
  int index;

  for(index = 0; index < 5; index++)
  {
    printf("Please enter name for player %d: ", index);
    scanf("%32[^\n]", names[index]);
    fflush(stdin);
  }
}

void displayPlayerNames(char names[5][33])
{
  int index;

  for(index = 0; index < 5; index++)
  {
    printf("name of player %d: %s\n", index, names[index]);
  }
}

void haltProgram(void)
{
  char pausePorgramChar;

  printf("Press any key to continue...");
  scanf("%c", &pausePorgramChar);
}
