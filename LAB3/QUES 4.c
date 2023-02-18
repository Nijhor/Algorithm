#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int cnt =0;
        int x;

            x =n/500;
            cnt+=x;
            n = n%500;

            x = n/100;
            cnt+=x;
            n = n%100;

            x = n/50;
            cnt+=x;
            n = n%50;

            x = n/20;
            cnt +=x;
            n = n%20;

            x = n/10;
            cnt+=x;
            n = n%10;

            x = n/5;
            cnt+=x;
            n = n%5;

            x = n/2;
            cnt+=x;
            n = n%2;
            x = n;
            cnt+=x;

    printf("%d",cnt);
}
