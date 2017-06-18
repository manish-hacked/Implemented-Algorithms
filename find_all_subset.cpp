#include<bits/stdc++.h>
using namespace std;

void show(char a[],int n){
	int p =pow(2,n);
	for(int i=0;i<p;i++){
		for(int j=0;j<n;j++){
			if(i&(1<<j))
			cout<<a[j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	char a[]={'a','b','c','d'};
	show(a,4);
}
