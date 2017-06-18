#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mp(a,b) make_pair(a,b)
pair<ll, pair<ll,ll> > v[100001];
ll sum=0,m;
ll arr[10001];

ll root(ll a){
	while(arr[a]!=a){
		arr[a]=arr[arr[a]];
		a=arr[a];
	}
	return a;
}

void Union(ll a,ll b){
	ll p = root(a);
	ll q = root(b);
	arr[p]=q;
}

void Kruskal(){
	for(ll i=0;i<m;i++){
		ll w = v[i].first;
		ll a = v[i].second.first;
		ll b = v[i].second.second;
		if(root(a)!=root(b)){
			sum+=w;
			Union(a,b);
		}
	}
}

int main(){
	ll n,p;
	cin>>n>>m;
	ll i=0;
	p=m;
	while(p--){
		ll a,b,c;
		cin>>a>>b>>c;
		v[i]= make_pair(c,mp(a,b));
		i++;
	}
	sort(v,v+i);
	for(i=0;i<=n;i++)
	arr[i]=i;
	Kruskal();
	cout<<sum<<endl;
}
