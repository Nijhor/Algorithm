
#include <stdio.h>


int divisorSum(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += (n / i) * i;
    return sum;
}


int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n", divisorSum(n));

}
