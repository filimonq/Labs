#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char str[101];
    gets(str);
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '"')
        {
            printf("[");
            while (str[i+1] != '"')
            {
                printf("%c", str[i+1]);                    
                i++;
            }
            printf("]\n");
            i++;
        } else if (str[i] != ' ')
        {
            printf("[");
            while (str[i] != '\000')
            {
                if (str[i] == ' ')
                {
                   break; 
                }
                printf("%c", str[i]);
                i++;
            }
            printf("]\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}