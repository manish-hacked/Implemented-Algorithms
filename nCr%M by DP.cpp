#include<bits/stdc++.h>
using namespace std;


typedef long long int ll;
const ll M = 1e9+7;


int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n,r;cin>>n>>r;
		ll dp[r+1] = {0};
		ll i,j;
		dp[0]=1;
		for(i=1;i<=n;i++){
			for(j=min(i,r);j>0;j--){
				dp[j]=(dp[j]+dp[j-1])%M;
			}
		}
		cout<<dp[r]<<endl;
	}
}





/*
INPUT
4
7 5 6 4
5 4 6 7
4 5 6 7
4 5 6 7
0 1 2 3
0 1 2 3
0 1 2 3
0 1 2 3
OUPUT
Woman   Man
 4      2
 5      1
 6      3
 7      0
*/
