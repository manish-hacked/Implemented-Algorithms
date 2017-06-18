#include<bits/stdc++.h>
using namespace std;
#define sl(n) scanf("%lld",&n)
#define sll(m,n) scanf("%lld%lld",&m,&n)
#define debug(n) printf("%lld\n",n)
//#define INPUT
typedef long long int ll;

struct trie{
	ll value;
	ll what;
	struct trie *arr[2];
};


class Trie{
	public:
		struct trie* root;
		Trie();
		struct trie* newNode();
		void insert(struct trie *root,ll value,ll p);
		ll query(struct trie *root,ll value,ll *p);
};
struct trie* Trie::newNode(){
	trie* temp = new trie;
	temp->value = 0;
	temp->what = -1;
	temp->arr[0]=temp->arr[1]=NULL;
	return temp;
}


void Trie::insert(trie* root,ll value,ll p){
	trie* temp = root;
	ll i;
	for(i=31;i>=0;i--){
		bool val = value&(1<<i);
		if(temp->arr[val]==NULL)
		temp->arr[val] = this->newNode();
		temp = temp->arr[val];
	}
	temp->what = p;
	temp->value = value;
}

ll Trie::query(trie* root,ll p,ll *l){
	trie* temp = root;
	for(ll i=31;i>=0;i--){
		bool val = p&(1<<i);
		if(temp->arr[1-val]!=NULL){
			temp = temp->arr[1-val];
		}else{
			temp = temp->arr[val];
		}
	}
	*l = temp->what;
	return temp->value^p;
}

Trie::Trie(){
	this->root = this->newNode();
	this->insert(this->root,0,-1);
}


int main(){
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       freopen("output.cpp", "w", stdout);
   	#endif
		ll n;cin>>n;
		ll i,j;
		ll arr[n];
		for(i=0;i<n;i++){
			cin>>arr[i];
		}
		ll temp=0;
		ll ans=0;
		Trie t;
		ll p,r;
		for(i=0;i<n;i++){
			temp^=arr[i];
			t.insert(t.root,temp,i);
			ll l;
			ll  q = t.query(t.root,temp,&l);
			if(ans<=q){
				//cout<<i+1<<endl;
				if(ans==q){
					if(l<p){
						p=l+2;
						r=i+1;
					}
				}else{
					ans=q;
					p = l+2;
					r=i+1;	
				}
			}
		}
		cout<<ans<<endl;
		cout<<p<<" "<<r<<endl;
}



//  

