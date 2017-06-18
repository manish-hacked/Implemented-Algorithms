/**You have an array of integers Arr of length N. You must count number of pairs of integers (L, R) such that:
	0 <= L <= R < N;
	gcd(ArrL, ArrL + 1, …, ArrR) = 1.
	N is up to 106.**/
#include<bits/stdc++.h>
using namespace std;
#define sl(n) scanf("%lld",&n)
#define sll(m,n) scanf("%lld%lld",&m,&n)
#define debug(n) printf("%lld\n",n)
typedef long long int ll;
//#define INPUT
const ll N = 1e6;
const ll k = 16;
const ll zero = 0;
ll table[N][k+1];
ll arr[N];

int main(){
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       freopen("output.cpp", "w", stdout);
   	#endif
   	ll n;cin>>n;
   	ll i,j;
   	for(i=0;i<n;i++)
   	cin>>arr[i];
   	for(i=0;i<n;i++)
   	table[i][0]=arr[i];
   	for(j=1;j<=k;j++){
   		for(i=0;i<=n-(1<<j);i++)
		table[i][j]=__gcd(table[i][j-1],table[i+(1<<(j-1))][j-1]);	
	}
	ll ans=0;
	for(i=0;i<n;i++){
		ll r = i;
		ll g=zero;
		for(j=k;j>=0;j--){
			if(r+(1<<j)-1>=n)
			continue;
			if(__gcd(g,table[r][j])>1){
				g=__gcd(g,table[r][j]);
				r+=(1<<j);
			}
		}
		ans+=(n-r);
	}
	cout<<ans<<endl;
	return 0;
} 













//
