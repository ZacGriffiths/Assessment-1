#include <stdio.h>

int main(){

 /* This will be the user interface*/
char c;

     printf("Please enter a letter that correspondes to the function you wish to use\n");
     printf("a) rotation cipher encryption\n");
     printf("b) rotation cipher decryption using the rotation amount\n");
     printf("c) rotation cipher decryption (no help)\n");
     printf("d) substitution cipher encryption\n");
     printf("e) substitution cipher decryption with given substitutions\n");   
     printf("f) substitution cipher decryption (no help)\n\n");
     printf("Selection:\n ");
     scanf(" %s", &c);

     while(c < 'a' || c > 'f');        /*the do loop is repeated until one of the letters is inputed*/
      {
      switch(c)
      {
          case 'a':
          printf("a\n");              /*this printf is just a place holder, input the function later*/
          break;
          
          case 'b':
          printf("b\n");             /*same here*/
          break;
          
          case 'c':
          printf("c\n");             /* and here*/
          break;
          
          case 'd':
          printf("d\n");             /* and here*/
          break;
          
          case 'e':
          printf("e\n");             /* same again*/
          break;
          
          case 'f':
          printf("f\n");             /* same again*/
          break;
          
          default:
          printf("That inputed character is not allocated to one of the function, please select another character\n");
  }
  }
}


