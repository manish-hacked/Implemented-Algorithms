#include<bits/stdc++.h>
using namespace std;
#define sl(n) scanf("%lld",&n)
#define sll(m,n) scanf("%lld%lld",&m,&n)
#define debug(n) printf("%lld\n",n)
//#define INPUT
typedef long long int ll;

ll size = 100000000;
ll limit = sqrt(size)+1;
unsigned long long int prime[100000000/32];

vector<ll> v;
void seive(){
	ll i,j;
	for(i=0;i<size/32;i++)
	prime[i]=0xffffffff;
	prime[2/32]&=~(1<<(1%32));
	for(i=2;i<limit;i++){
		if(prime[i/32]&(1<<(i%32))){
			for(j=i*i;j<size;j+=i){
				prime[j/32]&=~(1<<(j%32));
			}
		}
	}	
}

bool isPrime(ll n){
	return prime[n/32]&(1<<(n%32));
}

void hola(){
	for(ll i=2;i<size;i++){
		if(isPrime(i))
		v.push_back(i);	
	}
}

double get(ll ans,ll n){
	double g =ans;
	double k = n/(log(n)/log(2.7182818285));
	double p = abs(g-k);
	return (p*100)/g;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       freopen("output.cpp", "w", stdout);
   	#endif
   	seive();
   	hola();
	ll n;
	cin>>n;
	while(n){
		ll ans;
		if(upper_bound(v.begin(),v.end(),n)==lower_bound(v.begin(),v.end(),n)){
			ans = lower_bound(v.begin(),v.end(),n)-v.begin();
		}else{
			ans = lower_bound(v.begin(),v.end(),n)-v.begin()+1;
		}
		//cout<<isPrime(n)<<endl;
		printf("%.1llf\n",get(ans,n));
		cin>>n;
	}
}



//  

