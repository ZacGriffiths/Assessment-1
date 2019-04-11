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
            }

            if (str[c] > 32 && str[c] < 65)
                {
                        str[c] = str[c] + 26;
                }
            printf("%s\n", str);
            c++;
        }
        printf("\n%s\n", str);
}