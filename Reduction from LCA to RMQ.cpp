#include<bits/stdc++.h>
using namespace std;
#define sl(n) scanf("%lld",&n)
#define sll(m,n) scanf("%lld%lld",&m,&n)
#define debug(n) printf("%lld\n",n)
typedef long long int ll;
//#define INPUT
void swap(ll *a,ll *b){
	ll temp = *a;
	*a=*b;
	*b=temp;
}
const ll N = 1001;
vector<ll> v[N];
ll hola[N];
ll level[N];
ll E[2*N];
bool visited[N];
ll F[N];
ll k;
ll table[2*N][100];
void BFS(ll s){
	visited[s]=true;
	queue< pair<ll,ll> > q;
	q.push(make_pair(s,0));
	while(!q.empty()){
		pair<ll,ll> p = q.front();q.pop();
		level[p.first]=++k;
		hola[k]=p.first;
		ll l = v[p.first].size();
		for(ll i=0;i<l;i++){
			if(!visited[v[p.first][i]]){
				visited[v[p.first][i]]=true;
				q.push(make_pair(v[p.first][i],p.second+1));	
			}
		}
	}
	return;
}
 
void DFS(ll s){
	visited[s]=true;
	E[k++]=level[s];
	F[s]=k-1;
	ll l=v[s].size();
	for(ll i=0;i<l;i++){
		if(!visited[v[s][i]]){
			DFS(v[s][i]);
			E[k++]=level[s];
		}
	}
	return;
}
 
int main(){
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       freopen("output.cpp", "w", stdout);
   	#endif
	ll t;cin>>t;
	ll z;
	for(z=1;z<=t;z++){
		ll n;cin>>n;
		ll i,j;
		for(i=0;i<=n;i++)
		v[i].clear();
		memset(visited,false,n+1);
		ll m=n;
		for(i=1;i<=n;i++)
		{
			ll p;cin>>p;
			while(p--){
				ll a;cin>>a;
				v[i].push_back(a);
				v[a].push_back(i);
			}
		}
		k=0;
		BFS(1);
		memset(visited,false,n+1);
		k=0;
		DFS(1);
		n=k;
		for(i=0;i<n;i++)
	   	table[i][0]=E[i];
	   	k = floor(log(n)/log(2));
	   	for(j=1;j<=k;j++){
	   		for(i=0;i<=(n-(1<<j));i++){
	   			if(table[i][j-1]<table[i+(1<<(j-1))][j-1]){
	   				table[i][j]=table[i][j-1];	
				}else{
					table[i][j]=table[i+(1<<(j-1))][j-1];
				}	
			}	
		}
		ll q;cin>>q;
		printf("Case %lld:\n",z);
		while(q--){
			ll ans;
			ll l,r;cin>>l>>r;
			l=F[l];
			r=F[r];
			if(l>r)
			swap(l,r);
			ll  p = floor(log(r-l+1)/log(2));
			if(table[l][p]<=table[r-(1<<p)+1][p])
			ans=table[l][p];
			else
			ans=table[r-(1<<p)+1][p];
			cout<<hola[ans]<<endl;	
		}
	}
} 
 
 
 
 
 
 
 
 
 
 
 
 
 
// 
