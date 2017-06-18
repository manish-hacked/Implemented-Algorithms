//Binary Index Tree

/**

			4
	       / \
	      2   6
         / \  / \
        1  3  5  7 

**/

#include<iostream>
#include<algorithm>
typedef long long int ll;
using namespace std;
ll sum(ll index,ll BIT[]){
	ll sum=0;
	while(index!=0){
		sum = sum + BIT[index];
		index= index&(index-1);
	}
	return sum;
}

void update(ll index,ll value,ll n,ll BIT[]){
	while(index<=n){
		BIT[index]+=value;
		index = index+(index&(-index));
	}
}


int main(){
	cout<<"Enter The Size Of Array"<<endl;
	int n;
	cin>>n;
	int arr[n+1],BIT[n+1]={0};
	int i;
	for(i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(i=1;i<=n;i++){
		update(i,arr[i],n,BIT);
	}
	for(i=1;i<=n;i++)
	cout<<BIT[i]<<" ";
	cout<<endl;
	int t;
	cin>>t;
	while(t--){
		int l,r;
		cin>>l>>r;
		cout<<"sum is = "<<(sum(r,BIT)-sum(l-1,BIT))<<endl;
	}
}
