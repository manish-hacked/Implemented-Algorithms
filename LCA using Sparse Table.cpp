//Lowest Common Ancestor By Sparse Method
// Precomputation : O(Nlog(n))
// Per Query : O(log(n))

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
ll p[N][50];
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

void calc(ll n){
	ll i,j;
	for(i=1;i<=n;i++){
		for(j=0;(1<<j)<=N;j++)
		p[i][j]=-1;
	}
	for(i=1;i<=n;i++)
	p[i][0]=parent[i];
	
	for(j=1;(1<<j)<n;j++){
		for(i=1;i<=n;i++){
			if(p[i][j-1]!=-1){
				p[i][j]=p[p[i][j-1]][j-1];
			}
		}
	}
	
}

ll get(ll u,ll v){
	ll i,j;
	if(level[u]<level[v]){
		ll temp=u;
		u=v;
		v=temp;
	}
	ll dist = level[u]-level[v];
	while(dist>0){
		ll k = log(dist)/log(2);
		u=p[u][k];
		dist-=(1<<k);
	}
	if(u==v)
	return u;
	ll hola = log(N-1)/log(2);
	for(j=hola;j>=0;j--){
		if(p[u][j]!=-1&&p[u][j]!=p[v][j]){
			u=p[u][j];
			v=p[v][j];
		}
	}
	return parent[u];
	
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
		//memset(visited,false,n+1);
		calc(n);
		ll q;cin>>q;
		printf("Case %lld:\n",j);
		while(q--){
			ll a,b;cin>>a>>b;
			cout<<get(a,b)<<endl;
		}
	}
} 













//
