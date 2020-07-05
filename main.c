#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

// Function declaration
void askSight(struct stat fileStat);
void whatChange();

void whoRead(struct stat fileStatsInFunc);
void whoWrite(struct stat fileStatsInFunc);
void whoEx(struct stat fileStatsInFunc);
void userCan(struct stat fileStatsInFunc, int showNums);
void groupCan(struct stat fileStatsInFunc, int showNums);
void anyCan(struct stat fileStatsInFunc, int showNums);

// Main
int main() {
   char command[20];
   char filename[50];
   char wantChange[5];

   struct stat fileStat;

   // Ask for file path
   printf("📁 Enter the path to the desired file: ");
   scanf("%s", filename);
   
   stat(filename, &fileStat);

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

   return 0;
}

// Function for sking the user what they want to see
void askSight(struct stat fileStat) {
   char whatmode[1];

   scanf("%s", whatmode);

   if (strcmp(whatmode, "1") == 0) {
      // All
      userCan(fileStat, 0);
      groupCan(fileStat, 0);
      anyCan(fileStat, 0);
   } else if (strcmp(whatmode, "2") == 0) {
      // Read
      whoRead(fileStat);
   } else if (strcmp(whatmode, "3") == 0) {
      // Write
      whoWrite(fileStat);
   } else if (strcmp(whatmode, "4") == 0) {
      // Execute
      whoEx(fileStat);
   } else if (strcmp(whatmode, "5") == 0) {
      // User
      userCan(fileStat, 0);
   } else if (strcmp(whatmode, "6") == 0) {
      // Group
      groupCan(fileStat, 0);
   } else if (strcmp(whatmode, "7") == 0) {
      // Other
      anyCan(fileStat, 0);
   } else {
      printf("Please select a number from 1-7: ");
      askSight(fileStat);
   }
}

// Function asking what they want to change
void whatChange(char filename[50]) {
   char whatToChange[5];

   // Re-fetch file stats
   struct stat newFileStat;
   stat(filename, &newFileStat);

   // List options and file stats
   userCan(newFileStat, 1);
   groupCan(newFileStat, 1);
   anyCan(newFileStat, 1);
   printf("\n10 - Exit");
   printf("\nEnter the number for what you would like to toggle: ");
   // User input
   scanf("%s", whatToChange);

   if (!strcmp(whatToChange, "1")) {
      whatChange(filename);
   } else if (!strcmp(whatToChange, "2")) {
      whatChange(filename);
   } else if (!strcmp(whatToChange, "3")) {
      whatChange(filename);
   } else if (!strcmp(whatToChange, "4")) {
      whatChange(filename);
   } else if (!strcmp(whatToChange, "5")) {
      whatChange(filename);
   } else if (!strcmp(whatToChange, "6")) {
      whatChange(filename);
   } else if (!strcmp(whatToChange, "7")) {
      whatChange(filename);
   } else if (!strcmp(whatToChange, "8")) {
      whatChange(filename);
   } else if (!strcmp(whatToChange, "9")) {
      whatChange(filename);
   } else if (!strcmp(whatToChange, "10")) {
      printf("See ya! 👋");
   } else {
      printf("Please select a number from 1-10: ");
      whatChange(filename);
   }

}

// Functions for listing perms
// Read
void whoRead(struct stat fileStatsInFunc) {
   printf("\nWho can read the file includes:\n");
   printf("User:");
   printf( (fileStatsInFunc.st_mode & S_IRUSR) ? "✅\n" : "❌\n");
   printf("Group:");
   printf( (fileStatsInFunc.st_mode & S_IRGRP) ? "✅\n" : "❌\n");
   printf("Other:");
   printf( (fileStatsInFunc.st_mode & S_IROTH) ? "✅\n" : "❌\n");
}
// Write
void whoWrite(struct stat fileStatsInFunc) {
   printf("\nWho can write to the file includes:\n");
   printf("User:");
   printf( (fileStatsInFunc.st_mode & S_IWUSR) ? "✅\n" : "❌\n");
   printf("Group:");
   printf( (fileStatsInFunc.st_mode & S_IWGRP) ? "✅\n" : "❌\n");
   printf("Other:");
   printf( (fileStatsInFunc.st_mode & S_IWOTH) ? "✅\n" : "❌\n");
}
// Execute
void whoEx(struct stat fileStatsInFunc) {
   printf("\nWho can execute the file includes:\n");
   printf("User:");
   printf( (fileStatsInFunc.st_mode & S_IXUSR) ? "✅\n" : "❌\n");
   printf("Group:");
   printf( (fileStatsInFunc.st_mode & S_IXGRP) ? "✅\n" : "❌\n");
   printf("Other:");
   printf( (fileStatsInFunc.st_mode & S_IXOTH) ? "✅\n" : "❌\n");
}
// User
void userCan(struct stat fileStatsInFunc, int showNums) {
   printf("\nUser can:\n");
   if (showNums) {printf("1 - ");}
   printf("Read:");
   printf( (fileStatsInFunc.st_mode & S_IRUSR) ? "✅\n" : "❌\n");
   if (showNums) {printf("2 - ");}
   printf("Write:");
   printf( (fileStatsInFunc.st_mode & S_IWUSR) ? "✅\n" : "❌\n");
   if (showNums) {printf("3 - ");}
   printf("Execute:");
   printf( (fileStatsInFunc.st_mode & S_IXUSR) ? "✅\n" : "❌\n");
}
// Group
void groupCan(struct stat fileStatsInFunc, int showNums) {
   printf("\nThe group can:\n");
   if (showNums) {printf("4 - ");}
   printf("Read:");
   printf( (fileStatsInFunc.st_mode & S_IRGRP) ? "✅\n" : "❌\n");
   if (showNums) {printf("5 - ");}
   printf("Write:");
   printf( (fileStatsInFunc.st_mode & S_IWGRP) ? "✅\n" : "❌\n");
   if (showNums) {printf("6 - ");}
   printf("Execute:");
   printf( (fileStatsInFunc.st_mode & S_IXGRP) ? "✅\n" : "❌\n");
}
// Other
void anyCan(struct stat fileStatsInFunc, int showNums) {
   printf("\nOther can:\n");
   if (showNums) {printf("7 - ");}
   printf("Read:");
   printf( (fileStatsInFunc.st_mode & S_IROTH) ? "✅\n" : "❌\n");
   if (showNums) {printf("8 - ");}
   printf("Write:");
   printf( (fileStatsInFunc.st_mode & S_IWOTH) ? "✅\n" : "❌\n");
   if (showNums) {printf("9 - ");}
   printf("Execute:");
   printf( (fileStatsInFunc.st_mode & S_IXOTH) ? "✅\n" : "❌\n");
}