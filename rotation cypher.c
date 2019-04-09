/* Hello World program */

#include<stdio.h>

int main(void){
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
    
   while (str[c] != '\0') {
       if (str[c] >= 'a' && str[c] <= 'z')
    {
        str[c] = str[c] - 32;
    }
      str[c] = str[c] - n;
      
      if (str[c] < 65)
      {
          str[c] = str[c] + 26;
      }
      printf("\n%d %c\n", str[c], str[c]);
      c++;
  }
  
  printf("\n%s\n", str);

    return 0;
}