float mediaTresValores(float i, float n, float p)
{
    float media;
    if (i > 0 && n > 0 && p > 0)
    {
        media = (i + n + p) / 3;
        return media;
    }
    else
    {
        return -1;
    }
}