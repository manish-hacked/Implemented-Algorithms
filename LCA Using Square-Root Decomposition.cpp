//Lowest Common Ancestor By Square Root Decompositon
// Time Complexity for Preprocessing: o(n)
// Time Complexity for answering each query: o(sqrt(n))
#include<bits/stdc++.h>
using namespace std;
#define sl(n) scanf("%lld",&n)
#define sll(m,n) scanf("%lld%lld",&m,&n)
#define debug(n) printf("%lld\n",n)
typedef long long int ll;
//#define INPUT
const ll N = 1001;
vector<ll> v[N];
ll parent[N];
ll level[N];
ll p[N];
bool visited[N];

void BFS(ll s){
	visited[s]=true;
	parent[s]=s;
	queue< pair<ll,ll> > q;
	q.push(make_pair(s,0));
	while(!q.empty()){
		pair<ll,ll> p = q.front();q.pop();
		level[p.first]=p.second;
		ll l = v[p.first].size();
		for(ll i=0;i<l;i++){
			if(!visited[v[p.first][i]]){
				visited[v[p.first][i]]=true;
				parent[v[p.first][i]]=p.first;
				q.push(make_pair(v[p.first][i],p.second+1));	
			}
		}
	}
	return;
}

void calc(ll node,ll head,ll prev){
	visited[node]=true;
	ll cur_sec = sqrt(level[node])+1;
	if(cur_sec==1){
		p[node]=1;
	}else{
		if(cur_sec==prev){
			p[node]=p[head];
		}else{
			p[node]=parent[node];
			head=node;
		}
	}
	ll l = v[node].size();
	for(ll i=0;i<l;i++){
		if(!visited[v[node][i]])
		calc(v[node][i],head,cur_sec);
	}
}

ll get(ll u,ll v){
	while(p[u]!=p[v]){
		if(level[u]>level[v]){
			u=p[u];
		}else{
			v=p[v];
		}
	}
	while(u!=v){
		if(level[u]>level[v]){
			u=parent[u];
		}else{
			v=parent[v];
		}
	}
	return u;
}

int main(){
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       freopen("output.cpp", "w", stdout);
   	#endif
	ll t;cin>>t;
	ll j;
	for(j=1;j<=t;j++){
		ll n;cin>>n;
		ll i;
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
		BFS(1);
		memset(visited,false,n+1);
		calc(1,1,0);
		ll q;cin>>q;
		printf("Case %lld:\n",j);
		while(q--){
			ll a,b;cin>>a>>b;
			cout<<get(a,b)<<endl;
		}
	}
} 













//
