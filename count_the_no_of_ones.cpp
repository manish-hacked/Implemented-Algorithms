#include<bits/stdc++.h>
using namespace std;

void show(int n){
	int count=0;
	while(n){
		n=n&(n-1);
		count++;
	}
	cout<<count;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		printf("Enter A Number\n");
		scanf("%d",&n);
		show(n);
		printf("\n");
	}
}
