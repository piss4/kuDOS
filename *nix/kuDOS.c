#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <signal.h>
#include <ctype.h>
#include <math.h>
#include <dirent.h>



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
  
  system("clear");
  sleep(1);
  printf ("kuDOS Ver 1.0 \n");
  sleep(2);
  system("clear");
  
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
    fp = fopen (fileToTouch, "a");
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
    
    system("clear");
    goto command;
    
  } else if (strcmp(cmd, "exit") == 0) {
    
    printf ("Aborting...\n");
    sleep (1);
    printf ("Thank you for choosing kuDOS");
    
  } else if (strcmp(cmd, "file") == 0) {

    printf ("\nEnter file name: \n");
    char fname[255];
    scanf("%s",&fname);
    int size;
    FILE *f = NULL;
    f = fopen(fname, "r");
    fseek(f, 0, SEEK_END);
    size = ftell(f);
    fseek(f, 0, SEEK_SET);
    printf ("\nFile: %s\n", fname);
    printf ("Size: %d Bytes", size);

    goto command;

  } else if (strcmp(cmd, "dir") == 0) {

    printf ("\nListing all files in current directory... \n");
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
    goto command;

  } else if (strcmp(cmd, "read") == 0) {

    FILE *fptr;
    char filename[100], c;
    printf("Enter file name: \n");
    scanf("%s", filename);
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);
    goto command;

  } else {
    
    printf ("Command invalid.");
    goto command;
    
  }
}
