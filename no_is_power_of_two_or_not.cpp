#include<stdio.h>


int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		printf("Enter The Number\n");
		int n;
		scanf("%d",&n);
		if((n&(n-1))==0)
		printf("The Number is power of 2\n");
		else
		printf("The Number is not power of 2\n");
	}
}
