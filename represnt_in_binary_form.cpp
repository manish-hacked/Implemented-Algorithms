#include<bits/stdc++.h>
using namespace std;

void show(int n){
	stack<int> s;
	while(n!=0){
		s.push(n%2);
		n=n/2;
	}
	while(!s.empty()){
		int p = s.top();
		s.pop();
		printf("%d",p);
	}
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
