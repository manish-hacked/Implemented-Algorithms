//Method of finding nCr%m by chinese remainder theorm
//In this method m can be anything not neccessarily to be prime
// Here n can be upto 1e18
//Here m can be upto 1e6

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll size=1e6;
const ll limit = (ll)sqrt(size)+1;
vector<ll> primes;
ll isPrime[size+1]={0};

void seive(){
	ll i,j;
	for(i=2;i<limit;i++){
		if(!isPrime[i]){
			for(j=i*i;j<=size;j+=i){
				isPrime[j]=1;
			}
		}
	}
	for(i=2;i<=size;i++){
		if(!isPrime[i]){
			primes.push_back(i);
		}
	}
}

void factorise(vector< pair<ll,ll> >& v,ll n){
	ll l = primes.size();
	for(ll i=0;i<l;i++){
		ll p = primes[i];
		if(p*p>n){
			break;
		}
		int pow=0;
		while(n%p==0){
			pow++;
			n/=p;
		}
		if(pow){
			v.push_back(make_pair(p,pow));
		}
	}
	if(n>1){
		v.push_back(make_pair(n,1));
	}
}



ll crt(vector < ll > &num, vector < ll > &rem, ll n){
	ll x=1;
	// As per the Chinise remainder theorem,
    // this loop will always break.
    while (true)
    {
        // Check if remainder of x % num[j] is 
        // rem[j] or not (for all j from 0 to k-1)
        int j;
        for (j=0; j < n; j++ )
            if ( x % num[j] != rem[j])
               break;
 
        // If all remainders matched, we found x
        if (j == n)
            return x;
 
        // Else try next number
        x++;
    }
    return x;
}

void extended_gcd(ll a, ll b, ll& lastx, ll& lasty) 
{
  ll x, y, q, tmp;
  x = 0; lastx = 1;
  y = 1; lasty = 0;
  while (b != 0) {
    q = a / b;
    tmp = b;
    b = a % b;
    a = tmp;
 
    tmp = x;
    x = lastx - q*x;
    lastx = tmp;
 
    tmp = y;
    y = lasty - q*y;
    lasty = tmp;
  }
}

ll mod_inverse(ll a, ll m) {
  ll lastx, lasty;
  extended_gcd(a, m, lastx, lasty);
  while (lastx < 0)
    lastx += m;
  return lastx;
}

ll facmodpq(ll n, ll p, ll q) {
  ll pq = 1;
  for (int i = 0; i < q; ++i) pq *= p;
 
  if (n <= 1) return 1;
 
  ll r = ((n/pq) % 2) ? -1 : 1;
  for (int i = 2; i <= n % pq; ++i)
    if (i % p)
      r = (r * i) % pq;
  while (r < 0) r += pq;
  return r;
}

int binomod(ll n, ll m, ll p, ll q) 
{
#define MD 70
  ll oldq = q;
  ll ndigs[MD], mdigs[MD], rdigs[MD], N[MD], M[MD], R[MD], e[MD];
  memset(ndigs, 0, sizeof ndigs);
  memset(mdigs, 0, sizeof mdigs);
  memset(mdigs, 0, sizeof rdigs);
  memset(N, 0, sizeof N);
  memset(M, 0, sizeof M);
  memset(M, 0, sizeof R);
  memset(e, 0, sizeof e);
  int d = 0; 
  ll n1 = n, m1 = m, r1 = n-m;
  while (n1) {
    ndigs[d] = n1 % p;
    mdigs[d] = m1 % p;
    rdigs[d] = r1 % p;
    n1 /= p; m1 /= p; r1 /= p;
    ++d;
  }
  for (int i = 0; i < d; i++)
    e[i] = (ndigs[i] < (mdigs[i] + ((i > 0) ? e[i-1] : 0)));
  //cout << "e(1) = "; for (int i = 0; i < d; i++) cout << e[i] << " "; cout << endl;
  for (int i = d - 2; i >= 0; i--)
    e[i] += e[i+1];
 
  if (e[0] >= q) return 0;
  ll pq = 1;
  for (int i = 0; i < q; ++i) pq *= p;
  q -= e[0];
 
  n1 = n; m1 = m; r1 = n-m;
  ll pq1 = 1;
  for (int i = 0; i < q; ++i) pq1 *= p;
  d = 0;
  while (n1) {
    N[d] = n1 % pq1;
    M[d] = m1 % pq1;
    R[d] = r1 % pq1;
    n1 /= p; m1 /= p; r1 /= p;
    ++d;
  }
 
  ll res = 1;
  if ((p > 2 || q < 3) && q < d && e[q-1] % 2)
    res = -1;
  for (ll i = 0; i < e[0]; i++)
    res = (res * p) % pq;
 
  for (int i = 0; i < d; i++) {
    ll x = facmodpq(N[i], p, q) % pq;
    x = (x * mod_inverse(facmodpq(M[i], p, q), pq)) % pq;
    x = (x * mod_inverse(facmodpq(R[i], p, q), pq)) % pq;
    res = (res * x) % pq;
  }
  while (res < 0) res += pq;
 
  return res;
}

ll ChineseRemainderTherom(ll n,ll r,ll m){
	vector< pair<ll,ll> > p_factors;
	factorise(p_factors,m);
	vector<ll> num,rem;
	for(ll i=0;i<p_factors.size();i++){
		rem.push_back(binomod(n,r, p_factors[i].first, p_factors[i].second));
		num.push_back((ll) pow(p_factors[i].first, p_factors[i].second));
	}
	return crt(num,rem,num.size())%m;
}



int main(){
	seive();
	ll n,r,m;
	cin>>n>>r>>m;
	cout<<ChineseRemainderTherom(n,r,m)<<endl;	
}




