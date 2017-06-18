#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define sl(n) scanf("%lld",&n)
#define debug(n) printf("%lld\n",n)
typedef long long int ll;
#define INPUT
const ll m = 1e9+7;
ll cnt;
char a[55];
ll l;
ll dp[54][2][18][18][18];
void init(){
	ll i,j,k,l,m;
	for(i=0;i<54;i++){
		for(j=0;j<2;j++){
			for(k=0;k<18;k++){
				for(l=0;l<18;l++){
					for(m=0;m<18;m++){
						dp[i][j][k][l][m]=-1;
					}
				}
			}
		}
	}
}
ll get(ll len,int isEqual,ll n3,ll n6,ll n9){
	if(n3 > 17 || n6 > 17 || n9 > 17) return 0;
	if(len==l){
		if(n3>=1&&n3==n6&&n6==n9)
		return 1;
		return 0;
	}
	if(dp[len][isEqual][n3][n6][n9]==-1){
		dp[len][isEqual][n3][n6][n9]=0;
		if(!isEqual){
		for(ll i=0;i<=9;i++){
			if(i==3){
				dp[len][isEqual][n3][n6][n9]=(dp[len][isEqual][n3][n6][n9]%m+get(len+1,0,n3+1,n6,n9)%m)%m;
				}else if(i==6){
					dp[len][isEqual][n3][n6][n9]=(dp[len][isEqual][n3][n6][n9]%m+get(len+1,0,n3,n6+1,n9)%m)%m;
				}else if(i==9){
					dp[len][isEqual][n3][n6][n9]=(dp[len][isEqual][n3][n6][n9]%m+get(len+1,0,n3,n6,n9+1)%m)%m;
				}else{
					dp[len][isEqual][n3][n6][n9]=(dp[len][isEqual][n3][n6][n9]%m+get(len+1,0,n3,n6,n9)%m)%m;
				}
			}
		}else{
			for(ll i=0;i<=(a[len]-'0');i++){
				if(i<(a[len]-'0')){
					if(i==3){
						dp[len][isEqual][n3][n6][n9]=(dp[len][isEqual][n3][n6][n9]%m+get(len+1,0,n3+1,n6,n9)%m)%m;
						}else if(i==6){
							dp[len][isEqual][n3][n6][n9]=(dp[len][isEqual][n3][n6][n9]%m+get(len+1,0,n3,n6+1,n9)%m)%m;
						}else if(i==9){
							dp[len][isEqual][n3][n6][n9]=(dp[len][isEqual][n3][n6][n9]%m+get(len+1,0,n3,n6,n9+1)%m)%m;
						}else{
							dp[len][isEqual][n3][n6][n9]=(dp[len][isEqual][n3][n6][n9]%m+get(len+1,0,n3,n6,n9)%m)%m;
						}
					}else{
					if(i==3){
						dp[len][isEqual][n3][n6][n9]=(dp[len][isEqual][n3][n6][n9]%m+get(len+1,1,n3+1,n6,n9)%m)%m;
						}else if(i==6){
							dp[len][isEqual][n3][n6][n9]=(dp[len][isEqual][n3][n6][n9]%m+get(len+1,1,n3,n6+1,n9)%m)%m;
						}else if(i==9){
							dp[len][isEqual][n3][n6][n9]=(dp[len][isEqual][n3][n6][n9]%m+get(len+1,1,n3,n6,n9+1)%m)%m;
						}else{
							dp[len][isEqual][n3][n6][n9]=(dp[len][isEqual][n3][n6][n9]%m+get(len+1,1,n3,n6,n9)%m)%m;
						}
					}
				}
			}
		}
	ll p = dp[len][isEqual][n3][n6][n9];
	dp[len][isEqual][n3][n6][n9]=p;
	dp[len][isEqual][n3][n9][n6]=p;
	dp[len][isEqual][n6][n3][n9]=p;
	dp[len][isEqual][n6][n9][n3]=p;
	dp[len][isEqual][n9][n6][n3]=p;
	dp[len][isEqual][n9][n3][n6]=p;
	return p;
}
bool sub(){
	ll i=l-1;
	while(a[i]=='0'){
		a[i]='9';
		i--;
	}
	if(a[i]=='1'&&i==0){
		return true;
	}else{
		a[i]--;
	}
	return false;
}
int main(){
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       //freopen("output.cpp", "w", stdout);
   	#endif
   	ll t;sl(t);
   	while(t--){
   		init();
   		cnt=0;
		scanf("%s",a);
   		l=strlen(a);
   		ll x,y;
   		if(!sub())
   		x = get(0,1,0,0,0);
		else
		x = get(1,1,0,0,0);
   		init();
   		scanf("%s",a);
   		l=strlen(a);
   		y = get(0,1,0,0,0);
   		//debug(y);
   		ll ans = (y-x+m)%m;
   		debug(ans);
   	}
}
