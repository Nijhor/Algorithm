#include<stdio.h>

    int binarySrc(int n,int a[],int x)
    {
        int high = n-1;
        int low = 0;
        int mid;
        while(high>=low){
            mid=(low+high)/2;
            if(a[mid]==x)
            {
                return mid;
            }
            else if(a[mid]>x)
            {
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return -1;
    }
int main()
{
        int a[100005],n,x[100000],i,j;
     scanf("%d",&n);
     scanf("%d",&j);
     for(i=0;i<=n-1;i++)
     {
         scanf("%d",&a[i]);
     }
     int k;
     for(k=0;k<=j-1;k++)
     {
         scanf("%d",&x[k]);

     }
     for(k=0;k<=j-1;k++)
     {
         int ans =binarySrc(n,a,x[k]);
         printf("%d\n",ans);
     }

}
