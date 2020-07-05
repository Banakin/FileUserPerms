#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

// Function declaration
void askSight(struct stat fileStat);

void whoRead(struct stat fileStat);
void whoWrite(struct stat fileStat);
void whoEx(struct stat fileStat);
void userCan(struct stat fileStat);
void groupCan(struct stat fileStat);
void anyCan(struct stat fileStat);

// Main
int main() {
   char command[20];
   char filename[50];

   struct stat fileStat;

   // Ask for file path
   printf("📁 Enter the path to the desired file: ");
   scanf("%s", filename);
   
   stat(filename, &fileStat);

   // Present options
   printf("🤔 Select what you would like to see:\n");
   printf("1: 🎈 All permissions\n");
   printf("2: 🔍 Read permissions\n");
   printf("3: 📝 Write permissions\n");
   printf("4: 🏃‍♀️ Execute permissions\n");
   printf("5: 🧑 User permissions\n");
   printf("6: 🤗 Group permissions\n");
   printf("7: 💻 Anyone's permissions\n");
   
   // Ask for input
   askSight(fileStat);

   return 0;
}

// Function for sking the user what they want to see
void askSight(struct stat fileStat) {
   char whatmode[1];

   scanf("%s", whatmode);

   if (strcmp(whatmode, "1") == 0) {
      // All
      userCan(fileStat);
      groupCan(fileStat);
      anyCan(fileStat);
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
      userCan(fileStat);
   } else if (strcmp(whatmode, "6") == 0) {
      // Group
      groupCan(fileStat);
   } else if (strcmp(whatmode, "7") == 0) {
      // Anyone
      anyCan(fileStat);
   } else {
      printf("Please select a number from 1-7: ");
      askSight(fileStat);
   }
}

// Functions for listing perms
// Read
void whoRead(struct stat fileStat) {
   printf("\nWho can read the file includes:\n");
   printf("User:");
   printf( (fileStat.st_mode & S_IRUSR) ? "✅\n" : "❌\n");
   printf("Group:");
   printf( (fileStat.st_mode & S_IRGRP) ? "✅\n" : "❌\n");
   printf("Anyone:");
   printf( (fileStat.st_mode & S_IROTH) ? "✅\n" : "❌\n");
}
void whoWrite(struct stat fileStat) {
   printf("\nWho can write to the file includes:\n");
   printf("User:");
   printf( (fileStat.st_mode & S_IWUSR) ? "✅\n" : "❌\n");
   printf("Group:");
   printf( (fileStat.st_mode & S_IWGRP) ? "✅\n" : "❌\n");
   printf("Anyone:");
   printf( (fileStat.st_mode & S_IWOTH) ? "✅\n" : "❌\n");
}
void whoEx(struct stat fileStat) {
   printf("\nWho can execute the file includes:\n");
   printf("User:");
   printf( (fileStat.st_mode & S_IXUSR) ? "✅\n" : "❌\n");
   printf("Group:");
   printf( (fileStat.st_mode & S_IXGRP) ? "✅\n" : "❌\n");
   printf("Anyone:");
   printf( (fileStat.st_mode & S_IXOTH) ? "✅\n" : "❌\n");
}
// User
void userCan(struct stat fileStat) {
   printf("\nUser can:\n");
   printf("Read:");
   printf( (fileStat.st_mode & S_IRUSR) ? "✅\n" : "❌\n");
   printf("Write:");
   printf( (fileStat.st_mode & S_IWUSR) ? "✅\n" : "❌\n");
   printf("Execute:");
   printf( (fileStat.st_mode & S_IXUSR) ? "✅\n" : "❌\n");
}
// Group
void groupCan(struct stat fileStat) {
   printf("\nThe group can:\n");
   printf("Read:");
   printf( (fileStat.st_mode & S_IRGRP) ? "✅\n" : "❌\n");
   printf("Write:");
   printf( (fileStat.st_mode & S_IWGRP) ? "✅\n" : "❌\n");
   printf("Execute:");
   printf( (fileStat.st_mode & S_IXGRP) ? "✅\n" : "❌\n");
}
// Anyone
void anyCan(struct stat fileStat) {
   printf("\nAnyone can:\n");
   printf("Read:");
   printf( (fileStat.st_mode & S_IROTH) ? "✅\n" : "❌\n");
   printf("Write:");
   printf( (fileStat.st_mode & S_IWOTH) ? "✅\n" : "❌\n");
   printf("Execute:");
   printf( (fileStat.st_mode & S_IXOTH) ? "✅\n" : "❌\n");
}