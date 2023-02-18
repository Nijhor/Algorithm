#include <stdio.h>
int main()
{
  int arr[1000], n, x, d, pos, t;
  scanf("%d",&n);
  for (x=0; x<=(n-1); x++)
    {
    scanf("%d",&arr[x]);
    }

  for (x=0; x<(n-1); x++)
  {
    pos=x;

    for (d=x+1; d<n; d++)
    {
      if (arr[pos]>arr[d])
        pos = d;
    }
    if (pos!=x)
    {
      t=arr[x];
      arr[x]=arr[pos];
      arr[pos]=t;
    }
  }

  for (x=0; x<n; x++)
    printf("%d ",arr[x]);

  return 0;
}
