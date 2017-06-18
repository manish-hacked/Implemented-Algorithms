#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pr;
#define bitcount                    __builtin_popcount
#define gcd                         __gcd 
#define p(n) printf("%d\n",n)
#define sc(n) scanf("%c",&n)
#define pc(n) printf("%c\n",n)
#define sl(n) scanf("%lld",&n)
#define sll(a,b) scanf("%lld%lld",&a,&b)
#define debug() printf("hello\n")
#define debug1(n) printf("%lld\n",n)
#define debug2(a,b) printf("%lld %lld\n",a,b)
#define debug3(a,b,c) printf("%lld %lld %lld\n",a,b,c)
#define sf(n) scanf("%lf",&n)
#define pf(n) printf("%lf\n",n)
#define ss(n) scanf("%s",n)
#define forall(i,a,b) for(int i=a;i<b;i++)
#define foreach(v, c) for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a) a.begin(), a.end()
#define pb push_back
#define in(a,b) ( (b).find(a) != (b).end())
#define fill(a,v) memset(a, v, sizeof a)
#define sz(a) ((int)(a.size()))
#define mp  make_pair
#define f first
#define s second
#define checkbit(n,b) ( (n >> b) & 1)
#define index(arr,ind) (lower_bound(all(arr),ind)-arr.begin())
#define INPUT
ll BIT[1025][1025];
ll n;
ll sum(ll x,ll y){
	ll sum=0;
	while(x!=0){
		ll p = y;
		while(p!=0){
			sum = sum + BIT[x][p];
			p= p&(p-1);
		}
		x= x&(x-1);
	}
	return sum;
}
void update(ll x,ll y,ll value){
	while(x<=n){
		ll p = y;
		while(p<=n){
			BIT[x][p]+=value;
			p = p+(p&(-p));
		}
		x = x+(x&(-x));
	}
}
char a[20];
char b[]={'S','E','T','\0'};
char c[]={'S','U','M','\0'};
int main(){
	//cout<<b<<endl;
	/**ios_base::sync_with_stdio(false);
    cin.tie(NULL); **/
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       //freopen("output.cpp", "w", stdout);
   	#endif
   	ll t;sl(t);while(t--){
   		ll i,j;sl(n);
   		for(i=0;i<=n;i++){
   			for(j=0;j<=n;j++)
   			BIT[i][j]=0;
   		}
   		while(1){
   			ss(a);
	   		if(strcmp(a,b) == 0){
	   			ll p,q,r;sll(p,q);sl(r);
	   			p++;q++;
	   			ll k = sum(p,q)-sum(p-1,q)-sum(p,q-1)+sum(p-1,q-1);
	   			update(p,q,r-k);
	   		}else if(strcmp(a,c) == 0){
	   			ll q,w,e,r;sll(q,w);sll(e,r);
	   			q++;e++;w++;r++;
	   			ll ans=0;
	   			ans=sum(e,r)-sum(q-1,r)-sum(e,w-1)+sum(q-1,w-1);
	   			debug1(ans);
	   		}else{
	   			break;
	   		}	
   		}
   	}
}





//End
