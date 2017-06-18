#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool vstd[10001];
bool recS[10001];
vector<ll> v[10001];
bool isCyclic(ll s){
	if(vstd[s]==false){
		vstd[s]=true;
		recS[s]=true;
		for(ll i=0;i<v[s].size();i++){
			if(!vstd[v[s][i]]&&isCyclic(v[s][i])){
				return true;
			}else if(recS[v[s][i]]){
				return true;
			}
		}
	}
	recS[s]=false;
	return false;
}


int main(){
	ll n,m;
	cin>>n>>m;
	while(m--){
		ll a,b;cin>>a>>b;
		v[a].push_back(b);
	}
	memset(vstd,false,n+1);
	memset(recS,false,n+1);
	ll i,j;
	for(i=1;i<=n;i++)
	if(isCyclic(i)){
		cout<<"Yes"<<endl;
		return 0;
	}
	cout<<"No"<<endl;
	return 0;
}
