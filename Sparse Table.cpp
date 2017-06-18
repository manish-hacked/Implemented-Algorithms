//Range Sum Query
//N and Q are up to 10^5
//we set k=16 because 2^17 is greater than n while 2^16 is not
#include<bits/stdc++.h>
using namespace std;
#define sl(n) scanf("%lld",&n)
#define sll(m,n) scanf("%lld%lld",&m,&n)
#define debug(n) printf("%lld\n",n)
typedef long long int ll;
//#define INPUT

const ll k=16;
const ll N =1e5;
const ll zero =0;
ll table[N][k+1];  //k + 1 because we need to access table[r][k]
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
   	// build Sparse Table
    for(i = 0; i < n; i++)
        table[i][0] = arr[i];
    for(j = 1; j <= k; j++) {
        for(int i = 0; i <= n - (1 << j); i++)
            table[i][j] = table[i][j - 1] + table[i + (1 << (j - 1))][j - 1];
    } 
    ll q;cin>>q;
    while(q--){
    	ll l,r;cin>>l>>r; //boundaries of next query, 0-indexed
    	ll ans=0;
    	for(j=k;j>=0;j--){
    		if(l+(1<<j)-1<=r){
    			ans+=table[l][j];
    			l+=(1<<j); 
			}
		}
		cout<<ans<<endl;
	}
} 













//
