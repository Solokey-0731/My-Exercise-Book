//CX06 Recursion
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//01 The Largest gcd
/*
int gcd(int x, int y)
{
    if (x % y == 0)
        return y;
    else
        return gcd(y, x % y);
}

int main()
{
    int m, n, g = 1, r;
    scanf("%d %d", &m, &n);
    if (m < n)
    {
        r = m;
        m = n;
        n = r;
    }
    g = gcd(m, n);
    printf("%d", g);
    return 0;
}*/

//02 Combination
/*
int comb(int m, int n)
{
    if (n < 0)
        return 0;
    else if (n == 0)
        return 1;
    else if (n == 1)
        return m;
    else if (m < 2 * n)
        return comb(m, m - n);
    else
        return (comb(m - 1, n - 1) + comb(m - 1, n));
}

int main()
{
    int m, n, c;
    scanf("%d %d", &m, &n);
    c = comb(m, n);
    printf("%d", c);
    return 0;
}*/

//03 Reverse the array
/*
void NegaSequence(int a[], int n)
{
    if (n == 1)
    {
        printf("%d", a[0]);
        return;
    }
    else
    {
        printf("%d ", a[n - 1]);
        NegaSequence(a, n - 1);
    }
}
int main()
{
    int n, a[100], i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    NegaSequence(a, n);
    return 0;
}*/

//04 Transform decimal into others
/*
int i = 0, a[100];
void Trans(unsigned int n, int b)
{
    if (n / b > 0)
    {
        a[i] = n % b;
        i++;
        Trans(n / b, b);
    }
    if (n / b == 0)
    {
        a[i] = n % b;
        return;
    }
}

int main()
{
    unsigned int n;
    int b, j;
    char c[100];
    scanf("%u %d", &n, &b);
    Trans(n, b);
    for (j = 0; j <= i; j++)
    {
        if (a[j] >= 10)
            c[j] = (char)(a[j] - 10 + 65);
        else
            c[j] = (char)(a[j] + 48);
    }
    for (j = i; j >= 0; j--)
        printf("%c", c[j]);
    return 0;
}*/

//05 Hermite
//mooc11

//06 Sequential Search
/*
int SqcSearch(int a[], int i, int n, int key)
{
    while (i < n)
    {
        if (key == a[i])
            return i;
        else
        {
            return SqcSearch(a, i + 1, n, key);
        }
    }
    return -1;
}
int main()
{
    int i, n, key, a[100], ikey;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &key);
    ikey = SqcSearch(a, 0, n, key);
    if (ikey == -1)
        printf("NULL");
    if (ikey >= 0)
        printf("%d", ikey);
    return 0;
}*/

//07 the Largest element
/*
int maxnum(int a[], int i, int n, int max)
{
    while (i < n)
    {
        if (max < a[i])
            max = a[i];
        return maxnum(a, i + 1, n, max);
    }
    return max;
}

int main()
{
    int i, n, max, a[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    max = a[0];
    max = maxnum(a, 0, n, max);
    printf("%d", max);
    return 0;
}*/

//08 Ackerman Function
/*
int Ack(int m, int n)
{
    if (m == 0)
        return n + 1;
    if (n == 0)
        return Ack(m - 1, 1);
    if (m > 0 && n > 0)
        return Ack(m - 1, Ack(m, n - 1));
}

int main()
{
    int m, n, a;
    scanf("%d %d", &m, &n);
    a = Ack(m, n);
    printf("%d", a);
    return 0;
}*/