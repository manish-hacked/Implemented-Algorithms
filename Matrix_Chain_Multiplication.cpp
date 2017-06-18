#include<stdio.h>
#include<malloc.h>
typedef long long int ll;
ll dp[101][101][2];
int main(){
	ll n;
	while(scanf("%lld",&n) != EOF){
		ll *p = (ll*)malloc(sizeof(ll)*(n+1));
		ll i,j,k,l;
		for(i=1;i<=n;i++)
		scanf("%lld",&p[i]);
		for(i=1;i<=n;i++){
			dp[i][i][0]=0;
			dp[i][i][1]=p[i];
		}
		for(l=2;l<=n;l++){
			for(i=1;i<=(n-l+1);i++){
				j = i+l-1;
				dp[i][j][0] = 1000000;
				for(k=i;k<j;k++){
					if((dp[i][k][0]+dp[k+1][j][0]+dp[i][k][1]*dp[k+1][j][1])<dp[i][j][0]){
						dp[i][j][0]=dp[i][k][0]+dp[k+1][j][0]+dp[i][k][1]*dp[k+1][j][1];
						dp[i][j][1]=(dp[i][k][1]+dp[k+1][j][1])%100;
					}
				}
			}
		}
		printf("%lld\n",dp[1][n][0]);
	}
}
