#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

// Function declaration
void askSight(struct stat fileStat);
void whatChange(char* filename);

void whoRead(struct stat fileStats);
void whoWrite(struct stat fileStats);
void whoEx(struct stat fileStats);
void userCan(struct stat fileStats, int showNums);
void groupCan(struct stat fileStats, int showNums);
void anyCan(struct stat fileStats, int showNums);

// Main
int main() {
   char filename[50];
   char wantChange[5];

   struct stat fileStat;

   // Ask for file path
   printf("📁 Enter the path to the desired file: ");
   scanf("%s", filename);
   

   if (lstat(filename, &fileStat) == -1) {
      perror("Invalid file");
      exit(EXIT_FAILURE);
   }

   // Present options
   printf("🤔 Select what you would like to see:\n");
   printf("1 - 🎈 All permissions\n");
   printf("2 - 🔍 Read permissions\n");
   printf("3 - 📝 Write permissions\n");
   printf("4 - 🏃‍♀️ Execute permissions\n");
   printf("5 - 🧑 User permissions\n");
   printf("6 - 🤗 Group permissions\n");
   printf("7 - 💻 Other's permissions\n");
   
   // Ask for input
   askSight(fileStat);

   // Ask if they would like to change anything
   printf("\nWould you like to edit any of these permissions? [y/N]\n");
   scanf("%s", wantChange);
   if (!strcmp(wantChange, "y") || !strcmp(wantChange, "Y")) {
      whatChange(filename);
   } else {
      printf("See ya! 👋");
   }

   exit(EXIT_SUCCESS);
}

// Function for sking the user what they want to see
void askSight(struct stat fileStat) {
   char whatmode[5];

   scanf("%s", whatmode);

   if (!strcmp(whatmode, "1")) {
      // All
      userCan(fileStat, 0);
      groupCan(fileStat, 0);
      anyCan(fileStat, 0);
   } else if (!strcmp(whatmode, "2")) {
      // Read
      whoRead(fileStat);
   } else if (!strcmp(whatmode, "3")) {
      // Write
      whoWrite(fileStat);
   } else if (!strcmp(whatmode, "4")) {
      // Execute
      whoEx(fileStat);
   } else if (!strcmp(whatmode, "5")) {
      // User
      userCan(fileStat, 0);
   } else if (!strcmp(whatmode, "6")) {
      // Group
      groupCan(fileStat, 0);
   } else if (!strcmp(whatmode, "7")) {
      // Other
      anyCan(fileStat, 0);
   } else {
      printf("Please select a number from 1-7: ");
      askSight(fileStat);
   }
   return;
}

// Function asking what they want to change
void whatChange(char* filename) {
   char whatToChange[5];
   char com[50] = "chmod ";

   // Re-fetch file stats
   struct stat newFileStat;

   if (lstat(filename, &newFileStat) == -1) {
      perror("Invalid file");
      exit(EXIT_FAILURE);
   }

   // List options and file stats
   userCan(newFileStat, 1);
   groupCan(newFileStat, 1);
   anyCan(newFileStat, 1);
   printf("\n10 - Exit");
   printf("\nEnter the number for what you would like to toggle: ");

   // User input
   scanf("%s", whatToChange);

   if (!strcmp(whatToChange, "1")) {
      // Toggle user read
      if ((newFileStat.st_mode & S_IRUSR)) {
         strcat(com, "u-r ");
         strcat(com, filename);
         system(com);
      } else {
         strcat(com, "u+r ");
         strcat(com, filename);
         system(com);
      }
      whatChange(filename);
   } else if (!strcmp(whatToChange, "2")) {
      // Toggle user write
      if ((newFileStat.st_mode & S_IWUSR)) {
         strcat(com, "u-w ");
         strcat(com, filename);
         system(com);
      } else {
         strcat(com, "u+w ");
         strcat(com, filename);
         system(com);
      }
      whatChange(filename);
   } else if (!strcmp(whatToChange, "3")) {
      // Toggle user execute
      if ((newFileStat.st_mode & S_IXUSR)) {
         strcat(com, "u-x ");
         strcat(com, filename);
         system(com);
      } else {
         strcat(com, "u+x ");
         strcat(com, filename);
         system(com);
      }
      whatChange(filename);
   } else if (!strcmp(whatToChange, "4")) {
      // Toggle group read
      if ((newFileStat.st_mode & S_IRGRP)) {
         strcat(com, "g-r ");
         strcat(com, filename);
         system(com);
      } else {
         strcat(com, "g+r ");
         strcat(com, filename);
         system(com);
      }
      whatChange(filename);
   } else if (!strcmp(whatToChange, "5")) {
      // Toggle group write
      if ((newFileStat.st_mode & S_IWGRP)) {
         strcat(com, "g-w ");
         strcat(com, filename);
         system(com);
      } else {
         strcat(com, "g+w ");
         strcat(com, filename);
         system(com);
      }
      whatChange(filename);
   } else if (!strcmp(whatToChange, "6")) {
      // Toggle group execute
      if ((newFileStat.st_mode & S_IXGRP)) {
         strcat(com, "g-x ");
         strcat(com, filename);
         system(com);
      } else {
         strcat(com, "g+x ");
         strcat(com, filename);
         system(com);
      }
      whatChange(filename);
   } else if (!strcmp(whatToChange, "7")) {
      // Toggle other read
      if ((newFileStat.st_mode & S_IROTH)) {
         strcat(com, "o-r ");
         strcat(com, filename);
         system(com);
      } else {
         strcat(com, "o+r ");
         strcat(com, filename);
         system(com);
      }
      whatChange(filename);
   } else if (!strcmp(whatToChange, "8")) {
      // Toggle other wright
      if ((newFileStat.st_mode & S_IWOTH)) {
         strcat(com, "o-w ");
         strcat(com, filename);
         system(com);
      } else {
         strcat(com, "o+w ");
         strcat(com, filename);
         system(com);
      }
      whatChange(filename);
   } else if (!strcmp(whatToChange, "9")) {
      // Toggle other execute
      if ((newFileStat.st_mode & S_IXOTH)) {
         strcat(com, "o-x ");
         strcat(com, filename);
         system(com);
      } else {
         strcat(com, "o+x ");
         strcat(com, filename);
         system(com);
      }
      whatChange(filename);
   } else if (!strcmp(whatToChange, "10")) {
      // Exit the program
      printf("See ya! 👋");
   } else {
      // Reprompt if not 1-10
      printf("Please select a number from 1-10: ");
      whatChange(filename);
   }
   return;
}

// Functions for listing perms
// Read
void whoRead(struct stat fileStats) {
   printf("\nWho can read the file includes:\n");
   printf("User: ");
   printf( (fileStats.st_mode & S_IRUSR) ? "✅\n" : "❌\n");
   printf("Group: ");
   printf( (fileStats.st_mode & S_IRGRP) ? "✅\n" : "❌\n");
   printf("Other: ");
   printf( (fileStats.st_mode & S_IROTH) ? "✅\n" : "❌\n");
   return;
}
// Write
void whoWrite(struct stat fileStats) {
   printf("\nWho can write to the file includes:\n");
   printf("User: ");
   printf( (fileStats.st_mode & S_IWUSR) ? "✅\n" : "❌\n");
   printf("Group: ");
   printf( (fileStats.st_mode & S_IWGRP) ? "✅\n" : "❌\n");
   printf("Other: ");
   printf( (fileStats.st_mode & S_IWOTH) ? "✅\n" : "❌\n");
   return;
}
// Execute
void whoEx(struct stat fileStats) {
   printf("\nWho can execute the file includes:\n");
   printf("User: ");
   printf( (fileStats.st_mode & S_IXUSR) ? "✅\n" : "❌\n");
   printf("Group: ");
   printf( (fileStats.st_mode & S_IXGRP) ? "✅\n" : "❌\n");
   printf("Other: ");
   printf( (fileStats.st_mode & S_IXOTH) ? "✅\n" : "❌\n");
   return;
}
// User
void userCan(struct stat fileStats, int showNums) {
   printf("\nUser can:\n");
   if (showNums) {printf("1 - ");}
   printf("Read: ");
   printf( (fileStats.st_mode & S_IRUSR) ? "✅\n" : "❌\n");
   if (showNums) {printf("2 - ");}
   printf("Write: ");
   printf( (fileStats.st_mode & S_IWUSR) ? "✅\n" : "❌\n");
   if (showNums) {printf("3 - ");}
   printf("Execute: ");
   printf( (fileStats.st_mode & S_IXUSR) ? "✅\n" : "❌\n");
   return;
}
// Group
void groupCan(struct stat fileStats, int showNums) {
   printf("\nThe group can:\n");
   if (showNums) {printf("4 - ");}
   printf("Read: ");
   printf( (fileStats.st_mode & S_IRGRP) ? "✅\n" : "❌\n");
   if (showNums) {printf("5 - ");}
   printf("Write: ");
   printf( (fileStats.st_mode & S_IWGRP) ? "✅\n" : "❌\n");
   if (showNums) {printf("6 - ");}
   printf("Execute: ");
   printf( (fileStats.st_mode & S_IXGRP) ? "✅\n" : "❌\n");
   return;
}
// Other
void anyCan(struct stat fileStats, int showNums) {
   printf("\nOther can:\n");
   if (showNums) {printf("7 - ");}
   printf("Read: ");
   printf( (fileStats.st_mode & S_IROTH) ? "✅\n" : "❌\n");
   if (showNums) {printf("8 - ");}
   printf("Write: ");
   printf( (fileStats.st_mode & S_IWOTH) ? "✅\n" : "❌\n");
   if (showNums) {printf("9 - ");}
   printf("Execute: ");
   printf( (fileStats.st_mode & S_IXOTH) ? "✅\n" : "❌\n");
   return;
}