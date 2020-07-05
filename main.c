#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char command[20];
   char filename[50];

   scanf("%s", filename);
   strcpy(command, "ls -l ");
   
   system(strcat(command, filename));

   return 0;
}