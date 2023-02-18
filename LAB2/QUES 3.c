#include <stdio.h>
int n,limit;
int ara[100005];

int sizeOfLargestRange(){
	int max=0,l=0, r=0;
	int sum=0;
	while(r<n){
		sum+=ara[r];
		while(sum>limit){
			sum-=ara[l];
			l++;
		}
		if((r-l+1)>max)
		max=r-l+1;
		r++;
	}
	return max;
}
int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &ara[i]);
	}
	scanf("%d", &limit);
	printf("%d\n",sizeOfLargestRange());
	return 0;
}
