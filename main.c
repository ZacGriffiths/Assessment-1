#include <stdio.h>
#include "myfunctions.h" /* This is my functions for the encryption and decryption ciphers */

int main(void){
FILE *output, *input;
char c; /* this is used to store the users input value */
int i;  /* used for character identifying in the File I/O of functions*/
char characters; /* used as a temporary value for characters in File I/O */
input = fopen("input.txt", "r+"); /* used as the input file for the messege to code or coded messege */
output = fopen("output.txt", "w"); /* output file to show outputed decrypted or encrypted code */

/* This is the user interface. It allows the user to pick what type of 
encryption or decryption they wish to use. These printf statements print
the user interface while the scanf scans a character that the user has 
inputed and stores it as a character 'c'*/

     do
     {
     printf("\nPlease enter a letter that correspondes to the function you wish to use\n");
     printf("a) rotation cipher encryption\n");
     printf("b) rotation cipher decryption using the rotation amount\n");
     printf("c) rotation cipher decryption (no help)\n");
     printf("d) substitution cipher encryption\n");
     printf("e) substitution cipher decryption with given substitutions\n");   
     printf("f) substitution cipher decryption (no help)\n\n");
     printf("Selection: ");
     scanf(" %c", &c);
     if (c < 'a' || c > 'f')
         {
               printf("\nThat is an incorrect function value, please choose a value corresponding to a function (a-f)\n");
         }
     }
    /* this do while loop is used to control the switch of the user interface.
    What this does is while a value is less then 'a' (under the alphabet) or is
    greater then 'f' (any other number or letter) it will print the do loop (all
    the printf statements) and print the wrong character line until the user
    inputs a value of either 'a, b, c, d, e or f' */
   
     while(c < 'a' || c > 'f');
    {}
    /* If a character between a and f are inputed then the code then proceeds to
    this switch statement where the character inputed causes a cipher code to proceed */
     switch(c)
      {
/************************************************************************/       
          case 'a':
       {
            char str[1000];
            int n;
            fprintf(output, "Inputed phrase:\n\n");
            for(i = 0; feof(input) == 0; i++)
            {
                fscanf(input, "%c", &characters);
                fprintf(output, "%c", characters);
                str[i] = characters;
                characters = 0;
           }
           if(str[0] == 0)
           {
               printf("Enter the phrase you wish to encrypt: ");
               scanf(" %[^\n]s", str);
               fprintf(output, "%s", str);
           }
            printf("Enter the number of rotations/key you want (any number over 26 will just loop over e.g. entering 29 will revert to 3: ");
            scanf("%d", &n);
            RotationEncrypt(str, n);
            fprintf(output, "\n\nOutputed code: \n\n%s", str);
            printf("your text is outputed in the output.txt file\n\n");
            fopen("input.txt", "w+");
            break;
     }
          
/************************************************************************/
          
          case 'b':
          {
               char str[1000];
               int n;
               printf("Enter the phrase you wish to decrypt: ");
               scanf(" %[^\n]s", str);
               printf("Enter the number of rotations/key of the encryption (any number over 26 will just loop over e.g. entering 29 will revert to 3: ");
               scanf("%d", &n);
               RotationKeyDecryption(str, n);
               break;
          }    
/************************************************************************/          
          
          case 'c':
          printf("You have selected 'c'\n");             /* and here*/
          break;
          
/************************************************************************/             
          
          case 'd':
          printf("You have selected 'd'\n");             /* and here*/
          break;
          
/************************************************************************/         
          
          case 'e':
          printf("You have selected 'e'\n");             /* same again*/
          break;
          
/************************************************************************/                
          
          case 'f':
          printf("You have selected 'f'\n");             /* same again*/
          break;
          
/************************************************************************/                 
          
          default:
          return 0;
  }
}
