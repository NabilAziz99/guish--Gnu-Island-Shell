#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <ctype.h>
//global variable mainly for history function
char data[10][100];
int count =0;

void add_hist(char x[])//function for adding to history
{
  int i;
  const char *test = x;
if(test[0] == 'r' && isdigit(test[2]) || test[0] == 'r' && test[1] == '\0')
{
  return;
}
  
 if (count < 10)
 {
    strcpy(data[count], x);
    ++ count;
 }
 else   // shift if it is full
 {
   for (i = 0; i < 9; ++ i)
      strcpy(data[i], data[i+1]);
      strcpy(data[9],x);
 }
 return;

}

char* get_command()//command for collecting user input
{
  char *str= malloc(200);

  printf("# ");
  if(fgets(str, 200, stdin)==NULL)   // The statement reads a line
  {
     printf("Error\n");
  }

  str[strlen(str) - 1] = '\0';

  return str;
}


int main()
{
  //variable delcarations
  char* command;
  char* token;
  char* argv[10];
  char* folder;

  folder = malloc(200);
  int i =0;


  command = get_command();

  while((strcmp(command, "exit") != 0))//infinite loop, ends if  user inputs exit
  {
    int pid = fork();// creating child process

    add_hist(command);

    if(pid !=0)// parent process if statement
    {
      wait(NULL);
      command = get_command();
    }

    else{ // child function processes, the main part of the shell

      token = strtok(command, " "); //tokenizing the command from user

      if((strcmp(command, "hist") == 0))//testing for 'hist' input, displays hist
      {
        int x =0;
        while (x < count)
        {

          printf("%d %s\n", x+1,data[x]);
          x++;
        }
        exit(0);
      }

    if((strcmp(token, "r") == 0))//testing for 'r' input, runs r n command
    {
      int num;
      num = atoi(&command[2]); //converting number from r into int

          if(num <= count)
          {

            //going to need the -1 command, to account for array indexing
            token = strtok(data[num-1], " ");

            
            if((strcmp(token, "hist") == 0))
            {
              int x =0;
              while (x < count)
              {
      
                printf("%d %s\n", x+1,data[x]);
                x++;
              }
              exit(0);
            }
                  while (token != NULL)
                  {
                        if(i < 10)
                        {
                          argv[i] = malloc (50);
                          strcpy(argv[i], token);
                          i++;
                        }

                  token = strtok(NULL, " ");
                }
            argv[i] = (char *) 0;

            folder = strcpy(folder, "/bin/");
            folder = strcat(folder, argv[0]);

            execv(folder, argv);

            printf("Error, uknown command\n");

          }
          else //if number inputted is not in the history, execute this
          {
            printf("Not in the list\n" );
          }
      exit(0); // ends child function
    }

  while (token != NULL) //tokenizer for all standard program executions
  {
     if(i < 10)
     {
     argv[i] = malloc (50);
     strcpy(argv[i], token);
     i++;
     }

     token = strtok(NULL, " ");
  }
  argv[i] = (char *) 0;

  folder = strcpy(folder, "/bin/");
  folder = strcat(folder, argv[0]);

  execv(folder, argv); //executing commands

  printf("Error, uknown command\n");
  exit(0);
        }//else loop

}//While loop
return 0;
}
