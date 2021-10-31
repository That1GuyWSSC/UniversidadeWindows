int verificaAscendente(int *array, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[i])
            {
                return 0;
            }
        }
    }
    return 1;
}

int verificaAscendente2(int *array, int n)
{
    int i = 0;
    int j = i + 1;
    while (i < n - 1)
    {
        while (j < n)
        {
            if (array[j] < array[i])
            {
                return 0;
            }
            j++;
        }
        i++;
    }
    return 1;
}

int verificaAscendente3(int *array, int n)
{
    int i = 0;
    int j = i + 1;
    if (n > 1)
    {
        do
        {
            do
            {
                if (array[j] < array[i])
                {
                    return 0;
                }
                j++;
            } while (j < n - 1);
            i++;
        } while (i < n - 2);
    }
    else
    {
        return 1;
    }
    return 1;
}