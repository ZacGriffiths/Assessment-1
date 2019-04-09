#include <stdio.h>

int main(void){
char c;
 /* This is the user interface. It allows the user to pick what type of encryption or decryption they wish to use*/
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

 }
     while(c < 'a' || c > 'f');        /*the do loop is repeated until one of the letters is inputed*/
    {}
     switch(c)
      {
/************************************************************************/       
          case 'a':
     {
            char str[100];
            int c = 0;
            int n;
            printf("Enter the word you wish to encrypt: ");
            scanf("%s", str);
            printf("Enter the number of rotations you want (any number over 26 will just loop over e.g. entering 29 will revert to 3: ");
            scanf("%d", &n);
            if (n > 26)
                {
                        n = n % 26;
                }
    
            while (str[c] != '\0') 
        {
            if (str[c] >= 'a' && str[c] <= 'z')
                {
                        str[c] = str[c] - 32;
                }
            str[c] = str[c] - n;
      
            if (str[c] < 65)
                {
                        str[c] = str[c] + 26;
                }
            c++;
        }
          printf("\n%s\n", str);
          break;
      }

          
/************************************************************************/
          
          case 'b':
          printf("You have selected 'b'\n");             /*same here*/
          break;
          
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
          printf("That inputed character is not allocated to one of the functions, please select another character\n");
  }
}


