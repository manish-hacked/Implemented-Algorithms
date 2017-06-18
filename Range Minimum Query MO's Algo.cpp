#include<bits/stdc++.h>
using namespace std;
#define sl(n) scanf("%lld",&n)
#define sll(m,n) scanf("%lld%lld",&m,&n)
#define debug(n) printf("%lld\n",n)
typedef long long int ll;
//#define INPUT
const ll N =100001;
ll arr[N];
ll block_size;
ll M[1000];


int main(){
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       freopen("output.cpp", "w", stdout);
   	#endif
   	ll n;cin>>n;
   	ll i,j,k;
   	for(i=0;i<n;i++)
   	cin>>arr[i];
   	block_size = floor(sqrt(n));
   	for(i=0;i<n;){
   		ll p = i/block_size; 
   		M[p]=i;
   		for(j=i;j<n&&j<(i+block_size);j++){
   			if(arr[M[p]]>arr[j])
			  M[p]=j;	
		}
		i=j;
	}
	ll q;
	cin>>q;
	while(q--){
		ll l,r;cin>>l>>r;
		ll ans=1e17;
		ll a = l/block_size;
		ll b = r/block_size;
		for(i=a+1;i<b;i++)
		ans=min(ans,arr[M[i]]);
		a=min(block_size*(a+1),n);
		for(i=l;i<min(a,r+1);i++)
		ans=min(ans,arr[i]);
		for(i=max(l,b*block_size);i<=r;i++)
		ans=min(ans,arr[i]);
		cout<<ans<<endl;
	}
} 













//
