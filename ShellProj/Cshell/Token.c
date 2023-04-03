// Extracting string tokens using strtok() 
#include <stdio.h> 
#include <string.h> 
  
int main() 
{ 
    char str[200]; 
    int    i = 0;
    if(fgets(str, 200, stdin)==NULL)   // The statement reads a line
    {
       printf("Error\n");
       return 0;
    } 
  
    str[strlen(str) - 1] = '\0';       //  It replaces newline ch with null

    // Returns first token with delimiter space
    char* token = strtok(str, " "); 
  
    // Keep extracting tokens
    while (token != NULL) { 
        printf("%s\n", token);    // shows each token at a time 
        token = strtok(NULL, " "); 
    } 
    return 0; 
}
