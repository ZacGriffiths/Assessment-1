void RotationEncrypt(char str[], int n)
{
    int c = 0;
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

            if (str[c] >= 'A' && str[c] <= 'Z')
            {
                str[c] = str[c] - n;
                
                if (str[c] > 32 && str[c] < 65)
                {
                        str[c] = str[c] + 26;
                }
            }     
            c++;
        }
    return;
}

/**************************************************/

void RotationKeyDecryption (char str[], int n)
{
    int c = 0;
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

            if (str[c] >= 'A' && str[c] <= 'Z')
            {
                str[c] = str[c] + n;
                
                if (str[c] > 32 && str[c] < 65)
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
    while (str[c] != '\0') 
    {
        if (str[c] >= 'a' && str[c] <= 'z')
        {
                str[c] = str[c] - 32;
        }
        c++;
   }

    while (key[j] != '\0')
    {
        if(key[j] >= 'a' && key[j] <= 'z')
        {
            key[j] = key[j] - 32;
        }
        j++;
    }
    for(i = 0; str[i] != '\0'; i++)
          {
              if(str[i] >= 'A' && str[i] <= 'Z')
              {
                  n = str[i] - 65;
                  str[i] = key[n];
              }
          }
    return;
}

/******************************************************/

void SubstitutionCipherDecryption(char str[], char key[])
{  
    int c = 0, i, j = 0, idk = 0, y;
    while (str[c] != '\0') 
    {
        if (str[c] >= 'a' && str[c] <= 'z')
        {
                str[c] = str[c] - 32;
        }
        c++;
    }

    while (key[j] != '\0')
    {
        if(key[j] >= 'a' && key[j] <= 'z')
        {
            key[j] = key[j] - 32;
        }
        j++;
    }
    for(i = 0; str[i] != '\0'; i++)
    {
      if(str[i] >= 'A' && str[i] <= 'Z')
      {
          for(y = 0; key[y] != '\0' && key[y] != str[i]; y++)
          {
                 idk++;
          }
      str[i] = idk + 65;
      idk = 0 ;
      }
    }
    return;
}