#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
long long int n,k,i,j;
long long int poww(int x,int p){
	if(p==0)
	return 1;
	return x*poww(x,p-1);
}
#define l 32
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld",&n,&k);
		long long int *arr = (long long int *)malloc(sizeof(long long int)*n);
		long long int sum=0,start,count=0,end,x,hola=0,max=0;
		for(i=0;i<n;i++){
			scanf("%lld",&arr[i]);
		}
		long long int *p = (long long int *)malloc(sizeof(long long int)*l);
		for(i=0;i<l;i++)
		p[i]=0;
		for(i=0;i<n;i++){
			sum=sum|arr[i];
			for(j=0;j<l;j++){
				if(arr[i]&(1<<j))
				p[j]++;
			}
			if(sum>=k){
				count+=(n-i);
				end=i;
				break;
			}
		}
		if(i==n){
			printf("%lld\n",count);
			continue;
		}
		start=0;
		while(1){
			while(1){
				hola=0;
				x=arr[start];
				for(j=0;j<l;j++){
				if(x&(1<<j))
				p[j]--;
				}
				for(j=0;j<l;j++){
					if(p[j]>0)
					hola+=poww(2,j);
				}
				start++;
				if(hola>=k){
					count+=(n-end);
				}else{
					break;
				}	
			}
			end++;
			if(end>=n)
			break;
				hola=0;
				x=arr[end];
				for(j=0;j<l;j++){
				if(x&(1<<j))
				p[j]++;
				}
				for(j=0;j<l;j++){
					if(p[j]>0)
					hola+=poww(2,j);
				}
				if(hola>=k){
					count+=(n-end);
				}
		}
		printf("%lld\n",count);
	}
	return 0;
}
