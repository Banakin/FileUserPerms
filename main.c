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
   char filename[50]; // File name var
   char wantChange[5]; // Input var for if change is wanted

   struct stat fileStat; // File stats

   // Ask for file path
   printf("Enter the path to the desired file: ");
   scanf("%s", filename);
   
   // Make sure the file works
   if (lstat(filename, &fileStat) == -1) {
      perror("Invalid file");
      exit(EXIT_FAILURE);
   }

   // Present options
   printf("Select what you would like to see:\n");
   printf("1 - All permissions\n");
   printf("2 - Read permissions\n");
   printf("3 - Write permissions\n");
   printf("4 - Execute permissions\n");
   printf("5 - User permissions\n");
   printf("6 - Group permissions\n");
   printf("7 - Other's permissions\n");
   
   askSight(fileStat); // Ask for input and show stats

   // Ask if they would like to change anything
   printf("\nWould you like to edit any of these permissions? [y/N]\n");
   scanf("%s", wantChange);
   if (!strcmp(wantChange, "y") || !strcmp(wantChange, "Y")) {
      whatChange(filename);
   }

   printf("Good bye!");
   exit(EXIT_SUCCESS);
}

// Function for asking the user what they want to see
void askSight(struct stat fileStat) {
   char whatmode[5]; // What they want to see input var

   scanf("%s", whatmode); // Get user input

   // Show stats
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
      askSight(fileStat); // Reprompt
   }
   return;
}

// Function asking what they want to change
void whatChange(char* filename) {
   char whatToChange[5]; // Var for which option they want to change
   char com[50]; // Chmod var to stick the command in

   // Re-fetch file stats
   struct stat newFileStat;

   // Make sure the file still works
   if (lstat(filename, &newFileStat) == -1) {
      perror("Invalid file");
      exit(EXIT_FAILURE);
   }

   // List options and file stats
   userCan(newFileStat, 1); // List user stats
   groupCan(newFileStat, 1); // List group stats
   anyCan(newFileStat, 1); // List other stats
   printf("\n10 - Exit"); // Exit option
   printf("\nEnter the number for what you would like to toggle: ");

   scanf("%s", whatToChange);  // User input on what they want changed

   if (!strcmp(whatToChange, "1")) {
      // Toggle user read
      if ((newFileStat.st_mode & S_IRUSR)) {
         sprintf(com, "chmod u-r %s", filename); // Add flags and file path to command
         system(com); // Run command
      } else {
         sprintf(com, "chmod u+r %s", filename); // Add flags and file path to command
         system(com); // Run command
      }
      whatChange(filename); // Reprompt
   } else if (!strcmp(whatToChange, "2")) {
      // Toggle user write
      if ((newFileStat.st_mode & S_IWUSR)) {
         sprintf(com, "chmod u-w %s", filename); // Add flags and file path to command
         system(com); // Run command
      } else {
         sprintf(com, "chmod u+w %s", filename); // Add flags and file path to command
         system(com); // Run command
      }
      whatChange(filename); // Reprompt
   } else if (!strcmp(whatToChange, "3")) {
      // Toggle user execute
      if ((newFileStat.st_mode & S_IXUSR)) {
         sprintf(com, "chmod u-x %s", filename); // Add flags and file path to command
         system(com); // Run command
      } else {
         sprintf(com, "chmod u+x %s", filename); // Add flags and file path to command
         system(com); // Run command
      }
      whatChange(filename); // Reprompt
   } else if (!strcmp(whatToChange, "4")) {
      // Toggle group read
      if ((newFileStat.st_mode & S_IRGRP)) {
         sprintf(com, "chmod g-r %s", filename); // Add flags and file path to command
         system(com); // Run command
      } else {
         sprintf(com, "chmod g+r %s", filename); // Add flags and file path to command
         system(com); // Run command
      }
      whatChange(filename); // Reprompt
   } else if (!strcmp(whatToChange, "5")) {
      // Toggle group write
      if ((newFileStat.st_mode & S_IWGRP)) {
         sprintf(com, "chmod g-w %s", filename); // Add flags and file path to command
         system(com); // Run command
      } else {
         sprintf(com, "chmod g+w %s", filename); // Add flags and file path to command
         system(com); // Run command
      }
      whatChange(filename); // Reprompt
   } else if (!strcmp(whatToChange, "6")) {
      // Toggle group execute
      if ((newFileStat.st_mode & S_IXGRP)) {
         sprintf(com, "chmod g-x %s", filename); // Add flags and file path to command
         system(com); // Run command
      } else {
         sprintf(com, "chmod g+x %s", filename); // Add flags and file path to command
         system(com); // Run command
      }
      whatChange(filename); // Reprompt
   } else if (!strcmp(whatToChange, "7")) {
      // Toggle other read
      if ((newFileStat.st_mode & S_IROTH)) {
         sprintf(com, "chmod o-r %s", filename); // Add flags and file path to command
         system(com); // Run command
      } else {
         sprintf(com, "chmod o+r %s", filename); // Add flags and file path to command
         system(com); // Run command
      }
      whatChange(filename); // Reprompt
   } else if (!strcmp(whatToChange, "8")) {
      // Toggle other wright
      if ((newFileStat.st_mode & S_IWOTH)) {
         sprintf(com, "chmod o-w %s", filename); // Add flags and file path to command
         system(com); // Run command
      } else {
         sprintf(com, "chmod o+w %s", filename); // Add flags and file path to command
         system(com); // Run command
      }
      whatChange(filename); // Reprompt
   } else if (!strcmp(whatToChange, "9")) {
      // Toggle other execute
      if ((newFileStat.st_mode & S_IXOTH)) {
         sprintf(com, "chmod o-x %s", filename); // Add flags and file path to command
         system(com); // Run command
      } else {
         sprintf(com, "chmod o+x %s", filename); // Add flags and file path to command
         system(com); // Run command
      }
      whatChange(filename); // Reprompt
   } else if (!strcmp(whatToChange, "10")) {
      return;
   } else {
      // Reprompt if not 1-10
      printf("Please select a number from 1-10: ");
      whatChange(filename);
   }
   return;
}

// Functions for listing perms
// Permission based listings
// Read
void whoRead(struct stat fileStats) {
   printf("\nWho can read the file includes:\n");
   printf("User: ");
   printf( (fileStats.st_mode & S_IRUSR) ? "YES\n" : "NO\n");
   printf("Group: ");
   printf( (fileStats.st_mode & S_IRGRP) ? "YES\n" : "NO\n");
   printf("Other: ");
   printf( (fileStats.st_mode & S_IROTH) ? "YES\n" : "NO\n");
   return;
}
// Write
void whoWrite(struct stat fileStats) {
   printf("\nWho can write to the file includes:\n");
   printf("User: ");
   printf( (fileStats.st_mode & S_IWUSR) ? "YES\n" : "NO\n");
   printf("Group: ");
   printf( (fileStats.st_mode & S_IWGRP) ? "YES\n" : "NO\n");
   printf("Other: ");
   printf( (fileStats.st_mode & S_IWOTH) ? "YES\n" : "NO\n");
   return;
}
// Execute
void whoEx(struct stat fileStats) {
   printf("\nWho can execute the file includes:\n");
   printf("User: ");
   printf( (fileStats.st_mode & S_IXUSR) ? "YES\n" : "NO\n");
   printf("Group: ");
   printf( (fileStats.st_mode & S_IXGRP) ? "YES\n" : "NO\n");
   printf("Other: ");
   printf( (fileStats.st_mode & S_IXOTH) ? "YES\n" : "NO\n");
   return;
}

// Identity based listings
// User
void userCan(struct stat fileStats, int showNums) {
   printf("\nUser can:\n");
   if (showNums) {printf("1 - ");}
   printf("Read: ");
   printf( (fileStats.st_mode & S_IRUSR) ? "YES\n" : "NO\n");
   if (showNums) {printf("2 - ");}
   printf("Write: ");
   printf( (fileStats.st_mode & S_IWUSR) ? "YES\n" : "NO\n");
   if (showNums) {printf("3 - ");}
   printf("Execute: ");
   printf( (fileStats.st_mode & S_IXUSR) ? "YES\n" : "NO\n");
   return;
}
// Group
void groupCan(struct stat fileStats, int showNums) {
   printf("\nThe group can:\n");
   if (showNums) {printf("4 - ");}
   printf("Read: ");
   printf( (fileStats.st_mode & S_IRGRP) ? "YES\n" : "NO\n");
   if (showNums) {printf("5 - ");}
   printf("Write: ");
   printf( (fileStats.st_mode & S_IWGRP) ? "YES\n" : "NO\n");
   if (showNums) {printf("6 - ");}
   printf("Execute: ");
   printf( (fileStats.st_mode & S_IXGRP) ? "YES\n" : "NO\n");
   return;
}
// Other
void anyCan(struct stat fileStats, int showNums) {
   printf("\nOther can:\n");
   if (showNums) {printf("7 - ");}
   printf("Read: ");
   printf( (fileStats.st_mode & S_IROTH) ? "YES\n" : "NO\n");
   if (showNums) {printf("8 - ");}
   printf("Write: ");
   printf( (fileStats.st_mode & S_IWOTH) ? "YES\n" : "NO\n");
   if (showNums) {printf("9 - ");}
   printf("Execute: ");
   printf( (fileStats.st_mode & S_IXOTH) ? "YES\n" : "NO\n");
   return;
}