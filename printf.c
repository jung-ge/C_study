#include <stdio.h>

int main()
{
    int a = 1;
    int b = 2;
    int c = 3;
    int i;

    for(int i = 1; i<10;i++) // 구구단
    {
        for(int j = 1; j < 10; j++)
        {
            printf("%d * %d = %d\n",i,j ,i * j);
        }
    }
    return 0;
}
