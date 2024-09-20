#include <stdio.h>

typedef struct polynomial{
    int coef;
    int exp;
} polynomial;

int main(void)
{
    polynomial a[10], b[10], c[10];
    int deg1,deg2;
    printf("Enter the highest degree of polynomial A: ");
    scanf("%i", &deg1);
    printf("Enter the highest degree of polynomial B: ");
    scanf("%i", &deg2);


    printf("Enter the coefficients and exponents of polynomial A: ");
    for(int i = 0; i <= deg1;i++)
    {
        printf("Enter the coefficient of x^%i: ", i);
        scanf("%i", &a[i].coef);
        a[i].exp = i;
    }

    printf("Enter the coefficients and exponents of polynomial B: ");
    for(int i = 0; i <= deg2;i++)
    {
        printf("Enter the coefficient of x^%i: ", i);
        scanf("%i", &b[i].coef);
        b[i].exp = i;
    }

    int m;
    int n;
    if(deg1 > deg2)
    {
        n = deg1;
        m = deg2;
    }
    else
    {
        n = deg2;
        m = deg1;
    }

    for(int i = 0;i <= n; i++)
    {
        if(i <= m)
        {
            c[i].coef = a[i].coef + b[i].coef;
            c[i].exp = i;
        }
        else{
            if(deg1 > deg2)
            {
                c[i].coef = a[i].coef;
                c[i].exp = i;
            }
            else
            {
                c[i].coef = b[i].coef;
                c[i].exp = i;
            }
        }

        
        
    }

    printf("The sum of the two polynomials is: ");
    for(int i = 0; i <= n; i++)
    {
        printf("%i x^%i + ", c[i].coef, c[i].exp);
    }

    return 0;
}