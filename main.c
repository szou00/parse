#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char ** parse_args(char * line) {
  int i = 0;
  char **p = malloc(5*sizeof(char));

  while (line != NULL) {
    p[i] = strsep(&line, " ");
    // printf("%d index: %s\n", i, p[i]);
    i++;
    // printf("Current String: %s\n", line);
  }
  p[i] = NULL;
  // execvp(p[0],p);
  return p;
}

int main(int argc, char *argv[]) {

  char line[100];
  char *l = line;

  printf("Please enter a command: ");
  fgets(l, 50, stdin);
  *(strchr(l, '\n')) = '\0'; //get rid of ending
  printf("Your command: %s\n\n", l);

  char ** args = parse_args(l);
  execvp(args[0],args);
}
