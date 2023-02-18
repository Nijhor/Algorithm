#include <bits/stdc++.h>
using namespace std;


struct strc
{
    long long int start, finish;
};
strc arr[1000006] ;
long int n,count1=0;
bool check(strc s1, strc s2)
{
    return (s1.finish < s2.finish);
}

void solution(strc arr[], int n)
{

    sort(arr, arr+n, check);




    int i = 0;
   count1++;


    for (int j = 1; j < n; j++)
    {

      if (arr[j].start >= arr[i].finish)
      {
          count1++;
          i = j;
      }
    }
}


int main()
{
    scanf("%ld", &n);

    for(int i=0; i<n; i++){
        scanf("%lld %lld", &arr[i].start,&arr[i].finish);
    }
    solution(arr, n);
    printf("%ld",count1);
    return 0;
}
