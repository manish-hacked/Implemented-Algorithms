#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll n,m;
ll arr[1000];
ll size[1000];

ll root(ll a){
	while(arr[a]!=a){
		arr[a] = arr[arr[a]];
		a=arr[a];
	}
	return a;
}

void Union(ll a ,ll b){
	ll rA = root(a);
	ll rB = root(b);
	if(size[rA]<size[rB]){
		arr[rA]=arr[rB];
		size[rB]+=size[rA];
	}else{
		arr[rB]=arr[rA];
		size[rA]+=size[rB];
	}	
}

int main(){
	cin>>n>>m;
	ll i,j;
	for(i=1;i<=n;i++)
	arr[i]=i;
	for(i=1;i<=n;i++)
	size[i]=1;
	while(m--){
		ll a,b;
		cin>>a>>b;
		Union(a,b);
		multiset<ll> s;
		for(i=1;i<=n;i++)
		if(arr[i]==i)
		s.insert(size[i]);
		multiset<ll>::iterator itr;
		for(itr=s.begin();itr!=s.end();itr++){
			cout<<*itr<<" ";
		}
		cout<<endl;
	}
}
