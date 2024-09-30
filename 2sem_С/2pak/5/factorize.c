typedef struct Factors {
    int k; //сколько различных простых в разложении
    int primes[32]; //различные простые в порядке возрастания
    int powers[32]; //в какие степени надо эти простые возводить
} Factors;

void Factorize(int X, Factors *res)
{
    int div = 2, count_of_pow = 1, xconst = X;
    res -> k = 0;
    while (div * div <= xconst)
    {
        if (X % div == 0)
        {
            res -> primes[res->k] = div;
            res -> powers[res->k] = 1;
            X = X / div ;       
            while (X % div == 0) // посчитать степень делителя 
            {
                res -> powers[res->k]++;
                X = X / div;
            }
            res -> k++;
        }
        div++;
    }
    if (X != 1) // если остался делить > корня 
    {
        res -> primes[res->k] = X;
        res -> powers[res->k] = 1;
        res -> k++;
    }
}