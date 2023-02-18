#include<stdio.h>

int n;
int arr[1000005];
long long int mergesort(int arr[], int sz){
long long int cnt = 0;
if(sz==1)
    {
        return 0;
    }

int ls = sz/2;
int rs = sz - ls;
int left[ls];
int right[rs];

for(int i=0; i< ls; i++)
    {

        left[i] = arr[i];
    }

for(int i = ls; i<sz; i++)
    {
        right[i-ls] = arr[i];
    }

cnt += mergesort(left, ls);
cnt += mergesort (right, rs);
int l = 0;
int r = 0;
int end = 0;

while (l < ls && r < rs )
    {
        if(left[l]<= right[r])
            {
                arr[end] = left[l];
                end++;
                l++;
            }
        else
            {
                arr[end]=right[r];
                end++;
                r++;
                cnt = cnt + (ls - l);
            }
        }

     while(l<ls)
        {
            arr[end]=left[l];
            end++;
            l++;
        }
    while(r<rs)
        {
            arr[end]=right[r];
            end++;
            r++;
        }

    return cnt;


}

  int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    long long int total = mergesort(arr, n);
    printf("%lld", total);
    return 0;
}

