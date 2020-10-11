# include <stdio.h>

int n;
char a[15] = {0,'a','b','c','d','e','f','g','h','i','j','k','l'};

void search(int );
void swap(int ,int );
void output();

int main(void)
{
    int i;

    scanf("%d", &n);

    search(1);

    return 0;
}

void search(int k)
{
    int i;

    if (k == n + 1)
        output();
    else
    {
        for (i = k; i <= n; ++i)
        {
            swap(i, k);
            search(k + 1);
            swap(i, k);
        }
    }
}

void swap(int x, int y)
{
    int t;

    t = a[x];
    a[x] = a[y];
    a[y] = t;
}

void output()
{
    int i;

    for (i = 1; i <= n; ++i)
        printf("%c", a[i]);
    printf("\n");
}