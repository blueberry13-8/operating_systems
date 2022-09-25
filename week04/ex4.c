#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

// <WRITE YOUR CODE HERE>

int main(void)
{
  char *command = malloc(sizeof(char)*100);
  size_t n = 100;
  char quit[] = "quit\n";
  printf("Print 'quit' if you want to stop the program\n");
  getline(&command, &n, stdin);
  while (strcmp(command, quit) != 0){
    system(command);
    getline(&command, &n, stdin);
  }
  free(command);

  return EXIT_SUCCESS;
}

// Example on using system
// https://www.codingunit.com/c-reference-stdlib-h-function-system

// Example on using execve
// https://linuxhint.com/c-execve-function-usage/