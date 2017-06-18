#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define M 1000000007

ll fac(ll n,ll m){
	if(n==1||n==0||n==m){
		return 1;
	}
	return ((n%M)*fac(n-1,m))%M;
}

ll poww(ll a,ll n){
	if(n==0){
		return 1;
	}
	if(n%2==0){
		return (poww(a,n/2)*poww(a,n/2))%M;
	}else{
		return ((a*poww(a,n/2))%M*poww(a,n/2))%M;
	}
}

ll facc(ll n){
	if(n==1||n==0){
		return 1;
	}else{
		return (poww(n,M-2)*facc(n-1))%M;
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		m--;
		n--;
		ll p = fac(n+m,m);
		ll q = (facc(n))%M;
		ll ans = (p*q)%M;
		cout<<ans<<endl;
	}
}
