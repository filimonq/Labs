#include <stdio.h>
#include <ctype.h>

char text[500001];
char token[5];
int pos = 0;

void readToken() // сдвигает тек. позицию
{
    while (isspace(text[pos]))
    {
        pos++;
    }
    if (text[pos] == '\0')
    {
        token[0] = '\0';
        return ;
    }
    if ((text[pos] == '+' || text[pos] == '-') || (text[pos] == '*' || text[pos] == '/') || (text[pos] == '(' || text[pos] == ')'))
    {
        token[0] = text[pos++];
        token[1] = '\0'; // чтобы юзать strcmp, например
        return ; 
    }
    int left = pos;
    while (isdigit(text[pos]))
    {
        token[pos - left] = text[pos]; 
        pos++;
    }
    token[pos - left] = '\0';
}

void peekToken() // не сдвигает тек. позицию
{
    int oldPos = pos;
    readToken();
    pos = oldPos;
}

double ParseExpr(); // declaration

double ParseAtom()
{
    double res = 0;
    peekToken();
    if (token[0] == '(')
    {
        readToken();
        res = ParseExpr();
        readToken(); // прочитали ')'
        return res;
    } else if (token[0] == '-') // унарный минус
    { 
        readToken();
        return -ParseAtom();
    } else // значит число
    {
        readToken();
        sscanf(token, "%lf", &res);
        return res;
    }
}

double ParseMonome()
{
    double res = ParseAtom();
    peekToken();
    char oper;
    while (token[0] == '*' || token[0] == '/')
    {
        readToken();
        oper = token[0];
        if (oper == '*')
        {
            res *= ParseAtom();
        } else
        {
            res /= ParseAtom();
        }
        peekToken();
    }
    return res;    
}

double ParseExpr()
{
    double res = ParseMonome();
    peekToken();
    char oper;
    while (token[0] == '+' || token[0] == '-')
    {
        readToken();
        oper = token[0];
        if (oper == '+')
        {
            res += ParseMonome();
        } else
        {
            res -= ParseMonome();
        }
        peekToken();
    }
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    gets(text);
    double res = ParseExpr();
    printf("%0.15lf", res);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
