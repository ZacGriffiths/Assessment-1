/****************************************************************
 *   Hello and welcome to my code.
 *   Before running code you can place your phrase or word into
 *   input.txt or input through stdin.
 *   If using the substitution cipher, you can input your new alphabet/key
 *   through the newalphabet.txt file or through stdin.
 *   The inputed, alphabet(if using substitute cipher) and outputed code
 *   will be displayed in the output.txt file.
 *   The outputed code will also be displayed through stdout.
 * 
 *   Enjoy :)
 * ***************************************************************/

#include <stdio.h>
#include "myfunctions.h" /* This is my functions for the encryption and decryption ciphers */
#include <string.h>

int main(void){
FILE *output, *input, *newalphabet;
char c; /* this is used to store the users input value */
int i;  /* used for character identifying in the File I/O of functions*/
int j;  /* another temporary character used in File I/O */
char characters; /*used as a temporary value for characters in File I/O*/
input = fopen("input.txt", "r+"); /* used as the input file for the messege to code or coded messege */
output = fopen("output.txt", "w"); /* output file to show outputed decrypted or encrypted code */
newalphabet = fopen("newalphabet.txt", "r+"); /* This is the input file used for the newalphabet in substitution cipher*/
/* This is the user interface. It allows the user to pick what type of 
encryption or decryption they wish to use. These printf statements print
the user interface while the scanf scans a character that the user has 
inputed and stores it as a character 'c'*/
     do
     {
     printf("\nPlease enter a letter that correspondes to the function you wish to use\n");
     printf("a) rotation cipher encryption\n");
     printf("b) rotation cipher decryption using the rotation amount\n");
     printf("c) substitution cipher encryption\n");
     printf("d) substitution cipher decryption with given substitutions\n");
     printf("e) rotation cipher decryption (no help)\n");   
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
/************************************************************************
 * This is the code for the rotation cipher encryption. It takes the users phrase and number of
 * rotations/key to output a new phrase.
 **************************************************************************/

          case 'a':
       {
            char str[1000];/* The original and new string will be stored in here*/
            int n;/* key */
            fprintf(output, "Inputed phrase:\n\n");/*prints "inputed phrase" to file output */
            /* this for loop takes the characters in the input.txt file, reads all of them until it reaches
            the end of the file and prints out all charcters to the output.txt file under "inputed phrase".
            The characters = 0 line is so there is no offset by 1 error*/
            for(i = 0; feof(input) == 0; i++)
            {
                fscanf(input, "%c", &characters);
                fprintf(output, "%c", characters);
                str[i] = characters;
                characters = 0;
           }
           /*This if string will consider if there is any characters in the input.txt file and of not will ask
           the user to input the phrase through stdin and subsequently printf that to output.txt*/
           if(str[0] == 0)
           {
               printf("Enter the phrase you wish to encrypt: ");
               scanf(" %[^\n]s", str);
               fprintf(output, "%s", str);
           }
           /* printf and scanf used to identify the key*/
            printf("Enter the number of rotations/key you want (any number over 26 will just loop over e.g. entering 29 will revert to 3: ");
            scanf("%d", &n);
            RotationEncrypt(str, n);/* The main code used for rotation cipher encryption */
            fprintf(output, "\n\nOutputed code: \n\n%s", str); /*prints 'Outputed code' to output.txt*/
            printf("your text is outputed in the output.txt file\n\n");/*Prints to console*/
            fopen("input.txt", "w+"); /*Clears the input.txt file*/
            printf("\n\nOutputed code: %s\n", str); /*prints new code to stdout*/
            break;
     }
          
/************************************************************************
 * Code used for rotation cipher decryption. It takes the users phrase and the key to decrypt the code
 * and print the output
 ***********************************************************************/
          
          case 'b':
          {
            /* This code is similar to that used in the rotation cipher encryption*/
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
               printf("Enter the phrase you wish to decrypt: ");
               scanf(" %[^\n]s", str);
               fprintf(output, "%s", str);
           }
            printf("Enter the number of rotations/key you want (any number over 26 will just loop over e.g. entering 29 will revert to 3: ");
            scanf("%d", &n);
            RotationKeyDecryption(str, n); /*main code used for rotation cipher decryption(with key)*/
            fprintf(output, "\n\nOutputed code: \n\n%s", str);
            printf("your text is outputed in the output.txt file\n\n");
            fopen("input.txt", "w+");
            printf("\n\nOutputed code: %s\n", str);
            break;
          }    
/************************************************************************
 * This is the code for substitution cipher encryption. It takes the users phrase and the new alphabet
 * to output the users encrypted code
 ************************************************************************/
          
          case 'c':
          {
              char str[1000]; /*users phrase*/
              char key[1000]; /*The new alphabet*/
              char newalphabetcharacters; /*temporary value for new alphabet*/
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
              fprintf(output, "\n\nThe new alphabet:\n\n");
              /*A similar code used for recognising the new alphabet*/
              for(j = 0; feof(newalphabet) == 0; j++)
              {
                  fscanf(newalphabet, "%c", &newalphabetcharacters);
                  fprintf(output, "%c", newalphabetcharacters);
                  key[j] = newalphabetcharacters;
                  newalphabetcharacters = 0;
              }
              if(key[0] == 0)
              {
                 printf("Please enter the key (the new alphabet): ");
                 scanf("%s", key);
              }
              fprintf(output, "%s", key);
              SubstitutionCipherEncryption(str, key); /*main code used for substitution cipher encryption*/
              fprintf(output, "\n\nOutputed code: \n\n%s", str);
              printf("your text is outputed in the output.txt file\n\n");
              printf("\n\nOutputed code: %s\n", str);
              fopen("input.txt", "w+"); /*Clears input.txt*/
              fopen("newalphabet.txt", "w+"); /*Clears newalphabet.txt*/
          break;
        }

          
/************************************************************************
 * The is the code used for substitution cipher decryption (with key). It takes the users phrase and the new
 * alphabet to output the users decrypted code.
 ***********************************************************************/
          
          case 'd':
          {
              /*Code is similar to the substitution cipher encryption*/
              char str[1000];
              char key[1000];
              char newalphabetcharacters;
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
                  printf("Enter the phrase you wish to decrypt: ");
                  scanf(" %[^\n]s", str);
                  fprintf(output, "%s", str);
              }
              fprintf(output, "\n\nThe new alphabet:\n\n");
              for(j = 0; feof(newalphabet) == 0; j++)
              {
                  fscanf(newalphabet, "%c", &newalphabetcharacters);
                  fprintf(output, "%c", newalphabetcharacters);
                  key[j] = newalphabetcharacters;
                  newalphabetcharacters = 0;
              }
              if(key[0] == 0)
              {
                 printf("Please enter the key (the new alphabet): ");
                 scanf("%s", key);
              }
              fprintf(output, "%s", key);
              SubstitutionCipherDecryption(str, key); /*main code used for substitution cipher decryption*/
              fprintf(output, "\n\nOutputed code: \n\n%s", str);
              printf("your text is outputed in the output.txt file\n\n");
              printf("\n\nOutputed code: %s\n", str);
              fopen("input.txt", "w+");
              fopen("newalphabet.txt", "w+");
          break;
      }

          
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
