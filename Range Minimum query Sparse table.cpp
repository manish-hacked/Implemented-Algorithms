#include<bits/stdc++.h>
using namespace std;
#define sl(n) scanf("%lld",&n)
#define sll(m,n) scanf("%lld%lld",&m,&n)
#define debug(n) printf("%lld\n",n)
typedef long long int ll;
//#define INPUT
const ll N =100001;
ll k;
ll arr[N];
ll table[N][17];


int main(){
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       freopen("output.cpp", "w", stdout);
   	#endif
   	ll n;cin>>n;
   	ll i,j,k;
   	for(i=0;i<n;i++)
   	cin>>arr[i];
   	for(i=0;i<n;i++)
   	table[i][0]=arr[i];
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
	while(q--){
		ll ans;
		ll l,r;cin>>l>>r;
		ll  p = floor(log(r-l+1)/log(2));
		if(table[l][p]<=table[r-(1<<p)+1][p])
		ans=table[l][p];
		else
		ans=table[r-(1<<p)+1][p];
		cout<<ans<<endl;	
	}
} 













//
