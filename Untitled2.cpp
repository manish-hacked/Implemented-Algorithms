#include<bits/stdc++.h>
using namespace std;
#define sl(n) scanf("%lld",&n)
#define sll(m,n) scanf("%lld%lld",&m,&n)
#define debug(n) printf("%lld\n",n)
typedef long long int ll;
//#define INPUT
ll dp[51][3000];


int main(){
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       freopen("output.cpp", "w", stdout);
   	#endif
 	ll t;cin>>t;
	while(t--){
		ll n;
		cin>>n;
		string s;cin>>s;
		ll T[n][n];
		ll F[n][n];
		ll i,j;
		for(i=0;i<n;i++){
			T[i][i]=(s[i]=='T')?1:0;
			F[i][i]=(s[i]=='F')?1:0;
		}
		for(ll l=2;l<=n;l++){
			for(i=0;i<=n-l;i++){
				ll a=i;
				ll b=i+l-1;
				T[a][b] = F[a][b] = 0;
				for(j=a;j<b;j++){
					if(s[j]=='&'){
						T[a][b]+=T[a][j-1]*T[j+1][b];
						F[a][b]+=T[a][j-1]*F[j+1][b]+F[a][j-1]*T[j+1][b]+F[a][j-1]*F[j+1][b];
					}else if(s[j]=='^'){
						T[a][b]+=T[a][j-1]*F[j+1][b]+F[a][j-1]*T[j+1][b];
						F[a][b]+=T[a][j-1]*T[j+1][b]+F[a][j-1]*F[j+1][b];
					}else if(s[j]=='|'){
						T[a][b]+=T[a][j-1]*F[j+1][b]+F[a][j-1]*T[j+1][b]+T[a][j-1]*T[j+1][b];
						F[a][b]+=F[a][j-1]*F[j+1][b];
					}
				}
			}
		}
		cout<<T[0][n-1]%1003<<endl;
	}
}






//
