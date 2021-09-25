#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <signal.h>
#include <ctype.h>
#include <math.h>



/*

Hello! Thank you for using kuDOS. kuDOS is free and open source, meaning you can edit the code in any way you please and do whatever you wish with it.
But please remember, if you sell the kuDOS source and don't change anything, that's stealing and you can get into big trouble for that.


Credits:

Scott - Developer
YoPoster - Developer
Scarf - Designer, Tester
Official B - Tester

*/

int main() {
  
  // startup
  
  system("cls");
  sleep(1);
  printf ("kuDOS Ver 1.0 \n");
  sleep(2);
  system("cls");
  
  // main
  
  command:
  printf ("\nEnter command: \n");
  char cmd[200];
  scanf("%s",&cmd);
  
  // commands
  
  if (strcmp(cmd, "time") == 0) {
    
    time_t currtime = time(NULL);
    char * s_time = ctime(&currtime);
    s_time[strlen(s_time)-1] = '/0';
  	printf ("%s", s_time);
    goto command;
    
  } else if (strcmp(cmd, "delete") == 0) {
    
  	printf ("\nEnter file name: \n");
  	char fileToDelete[255];
  	scanf("%s",&fileToDelete);
    int del_task = remove(fileToDelete);
    if (del_task == 0) {
    printf ("File deleted successfully.");
    } else {
    printf ("File couldn't be deleted.");
    }
    goto command;
    
  } else if (strcmp(cmd, "touch") == 0) {
    
  	printf ("\nEnter file name: \n");
  	char fileToTouch[255];
  	scanf("%s",&fileToTouch);
    FILE *fp;
    fp = fopen (fileToTouch, "W");
    fclose (fp);
    goto command;
    
  } else if (strcmp(cmd, "version") == 0) {
    
    printf ("kuDOS® 1.0");
    goto command;
    
  } else if (strcmp(cmd, "info") == 0) {
    
  	printf ("kuDOS Version 1.0\n");
  	printf ("Credits:\n");
  	printf ("Scott: Developer\n");
  	printf ("YoPoster: Developer\n");
  	printf ("Scarf: Designer, Tester\n");
  	printf ("Official B: Tester\n");
    goto command;
    
  } else if (strcmp(cmd, "rename") == 0) {
    
    char r1[255], r2[255];
    printf("\nFile to rename: \n");
    scanf("%s", r1);
    printf("\nRename to: \n");
    scanf("%s", r2);
    if (rename(r1, r2) == 0) {
    	printf ("Successfully renamed file.");
    } else {
    	printf ("Failed to rename file.");
    }
    goto command;
    
  } else if (strcmp(cmd, "clear") == 0) {
    
    system("cls");
    goto command;
    
  } else if (strcmp(cmd, "exit") == 0) {
    
    printf ("Aborting...\n");
    sleep (1);
    printf ("Thank you for choosing kuDOS");
    
  } else {
    
    printf ("Command invalid.");
    goto command;
    
  }
}
