#include<bits/stdc++.h>
using namespace std;
#define sl(n) scanf("%lld",&n)
#define sll(m,n) scanf("%lld%lld",&m,&n)
#define debug(n) printf("%lld\n",n)
//#define INPUT
typedef long long int ll;
vector<ll> v1[1000001];
vector<ll> v2[1000001];
bool visited[1000001];
ll dp[1000001];
bitset <50005> gk[50005];
ll n;
stack<ll> s;
vector<ll> temp;
void DFS(ll sr){
	visited[sr]=true;
	ll l = v1[sr].size();
	for(ll i=0;i<l;i++)
	if(!visited[v1[sr][i]])
	DFS(v1[sr][i]);
	s.push(sr);
}
void DFS1(ll sr){
	visited[sr]=true;
	ll l = v1[sr].size();
	for(ll i=0;i<l;i++)
	if(!visited[v1[sr][i]])
	DFS1(v1[sr][i]);
	temp.push_back(sr);
}

void dfs(ll sr,ll l){
	gk[l][l]=1;
	visited[sr]=true;
	dp[sr]=l;
	stack<ll> s1;
	s1.push(sr);
	while(!s1.empty()){
		ll p = s1.top();s1.pop();
		ll g = v2[p].size();
		for(ll i=0;i<g;i++){
			if(!visited[v2[p][i]]){
				visited[v2[p][i]]=true;
				dp[v2[p][i]]=l;
				s1.push(v2[p][i]);
			}
		}
	}
}

void init(){
	memset(visited,false,n+1);
}

ll hola(){
	ll i=0;
	while(!s.empty()){
		ll p = s.top();s.pop();
		if(!visited[p])
		dfs(p,++i);
	}
	return i;
}



int main(){
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       freopen("output.cpp", "w", stdout);
   	#endif
   	cin>>n;
   	ll i,j;
   	ll m;cin>>m;
   	vector< pair<ll,ll> > edges;
   	while(m--){
		ll a,b;cin>>a>>b;
		edges.push_back(make_pair(a,b));
		v1[a].push_back(b);
		v2[b].push_back(a);			   		
	}
	ll q;cin>>q;
	vector< pair<ll,ll> > query;
	while(q--){
		ll s;cin>>s;
		if(s==1){
			ll x,d;cin>>x>>d;
			if(d){
				v1[++n].push_back(x);
				edges.push_back(make_pair(n,x));
				v2[x].push_back(n);
			}else{
				v1[x].push_back(++n);
				edges.push_back(make_pair(x,n));
				v2[n].push_back(x);
			}
		}else{
			ll x,y;cin>>x>>y;
			query.push_back(make_pair(x,y));
		}
	}
	init();
	for(ll i=1;i<=n;i++){
		if(!visited[i])
		DFS(i);
	}
	init();
	ll noC = hola();
	ll l;
	for(i=1;i<=n;i++)v1[i].clear();
	l = edges.size();
	for(i=0;i<l;i++){
		if(dp[edges[i].first]!=dp[edges[i].second])v1[dp[edges[i].first]].push_back(dp[edges[i].second]);
	}
	init();
	for(ll i=1;i<=noC;i++){
		if(!visited[i])
		DFS1(i);
	}
	l=temp.size();
	for(i=0;i<l;i++){
		ll p = temp[i];
		gk[p][p]=1;
		ll size = v1[p].size();
		for(j=0;j<size;j++){
			gk[p]|=gk[v1[p][j]];
		}
	}
	l = query.size();
	for(i=0;i<l;i++){
		ll a = query[i].first;
		ll b = query[i].second;
		if(gk[dp[a]][dp[b]]==1){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
} 
