void RotationEncrypt(char str[], int n)
{
    int c = 0;
                /*If statement calculates key if the number is over 26*/
                if (n > 26)
                {
                        n = n % 26;
                }
/*This code will read till the end of the string(inputed phrase), convert all lower case letters to
upper case, take those upper case letters and change them to a new letter based on the key number. If the 
new letters are under the ascii number of 65(out of alphabet and into random symbols) then then code will convert
them back to the beginning of the alphabet*/
            /*reads till end of string*/
            while (str[c] != '\0') 
        {
            /*converts lower case to upper case*/
            if (str[c] >= 'a' && str[c] <= 'z')
                {
                        str[c] = str[c] - 32;
                }
            /*does calculation with key*/
            if (str[c] >= 'A' && str[c] <= 'Z')
            {
                str[c] = str[c] - n;
                /*converts back to start of alphabet if under 65*/
                if (str[c] > 32 && str[c] < 65)
                {
                        str[c] = str[c] + 26;
                }
            }     
            c++; /*used to change to next position of string (eg str[0] to str[1])*/
        }
    return;
}

/**************************************************/

void RotationKeyDecryption (char str[], int n)
{
    /*Pretty much same again*/
    int c = 0;
                /*Calculates key over 26*/
                if (n > 26)
                {
                        n = n % 26;
                }
            /*Reads till string finishes*/
            while (str[c] != '\0') 
        {
            /*Converts to uppercase*/
            if (str[c] >= 'a' && str[c] <= 'z')
                {
                        str[c] = str[c] - 32;
                }
            /*Does the calculation with the key*/
            if (str[c] >= 'A' && str[c] <= 'Z')
            {
                str[c] = str[c] + n;
                /*If new letter is over the uppercase letter number then alphabet starts again*/
                if (str[c] > 90)
                {
                        str[c] = str[c] - 26;
                }
            }     
            c++;
        }
    return;
}

/****************************************************/

void SubstitutionCipherEncryption(char str[], char key[])
{
    int c = 0, i, n, j = 0;
    /*Converts to uppercase for the users string*/
    while (str[c] != '\0') 
    {
        if (str[c] >= 'a' && str[c] <= 'z')
        {
                str[c] = str[c] - 32;
        }
        c++;
   }
    /*Converts the key to uppercase using the same method*/
    while (key[j] != '\0')
    {
        if(key[j] >= 'a' && key[j] <= 'z')
        {
            key[j] = key[j] - 32;
        }
        j++;
    }
    /*Reads until the end of the string is reached*/
    for(i = 0; str[i] != '\0'; i++)
          {
              /*For uppercase letters*/
              if(str[i] >= 'A' && str[i] <= 'Z')
              {
                  /*Finds the key for that letter in alphabet(position in alphabet (eg a is 0, b is 1))*/
                  n = str[i] - 65;
                  /*Takes that number and convert the string character to the corresponding numbered character in the new alphabet*/
                  str[i] = key[n];
              }
          }
    return;
}

/******************************************************/

void SubstitutionCipherDecryption(char str[], char key[])
{  
    int c = 0, i, j = 0, idk = 0, y;
    /*Reads string and converts to uppercase*/
    while (str[c] != '\0') 
    {
        if (str[c] >= 'a' && str[c] <= 'z')
        {
                str[c] = str[c] - 32;
        }
        c++;
    }
    /*Reads key and converts to uppercase*/
    while (key[j] != '\0')
    {
        if(key[j] >= 'a' && key[j] <= 'z')
        {
            key[j] = key[j] - 32;
        }
        j++;
    }
    /*reads the whole string*/
    for(i = 0; str[i] != '\0'; i++)
    {
      /*If that character in the sting is an uppercase letter*/
      if(str[i] >= 'A' && str[i] <= 'Z')
      {
          /*calculates the number corresponding to that character on the new alphabet
          by taking the temporary value idk and increasing it very time the characters dont equal*/
          for(y = 0; key[y] != '\0' && key[y] != str[i]; y++)
          {
                 idk++;
          }
      /*Takes the placement of the character in the new alphabet and matches in with the corresponding
      letter on the regular alphabet*/
      str[i] = idk + 65;
      /*Reverts the temporary value back to zero to calculate the next character in the string*/
      idk = 0 ;
      }
   }
    return;
}