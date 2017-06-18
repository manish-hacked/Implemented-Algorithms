#include<bits/stdc++.h>
using namespace std;

//This method is only applicable when M is prime

typedef long long int ll;
const ll M = 1e9+7;


ll nCrModpDp(ll n,ll r,ll m){
	ll dp[r+1]={0};
	dp[0]=1;
	ll i,j;
	for(i=1;i<=n;i++){
		for(j=min(r,i);j>0;j--){
			dp[j]=(dp[j-1]+dp[j])%m;
		}
	}
	return dp[r];
}


ll nCrModpLucas(ll n,ll r,ll m){
	//Base case
	if(r==0)
	return 1;
	
	//Compute The Last Digit of n and r in base m
	ll nl = n%m;
	ll rl = r%m;
	
	return (nCrModpLucas(n/m,r/m,m)*nCrModpDp(nl,rl,m))%m;
}


int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n,r;cin>>n>>r;
		cout<<nCrModpLucas(n,r,M)<<endl;
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
