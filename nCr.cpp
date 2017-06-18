#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
typedef long long int ll;
ll C(ll n, ll r) {
    if(r > n / 2) r = n - r;
    ll ans = 1;
    ll i;
    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		cout<<C(n-1,m-1)<<endl;
	}
}
