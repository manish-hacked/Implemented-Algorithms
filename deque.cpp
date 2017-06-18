#include<bits/stdc++.h>
using namespace std;
struct _ { ios_base::Init i; _() { cin.sync_with_stdio(0); cin.tie(0); } } _;
typedef long long int ll;

ll *arr,*tree,n,p,i;

void build(ll node,ll start,ll end){
	if(start==end){
		tree[node]=arr[start];
	}else{
		ll mid = (start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node]=max(tree[2*node],tree[2*node+1]);
	}
}

ll query(ll node,ll start,ll end,ll l,ll r){
	if(r<start||l>end||start>end){
		return 0;
	}else{
		if(l<=start&&r>=end){
			return tree[node];
		}
		ll mid = (start+end)/2;
		return max(query(2*node,start,mid,l,r),query(2*node+1,mid+1,end,l,r));
	}
}

int main(){
	scanf("%lld",&n);
	ll q;
	cin>>q;
	arr=(ll*)malloc(sizeof(ll)*n);
	for(i=0;i<n;i++)
	scanf("%lld",&arr[i]);
	p=(ceil)((log(n)/log(2))+1);
	p=1<<p;
	tree=(ll*)malloc(sizeof(ll)*p);
	build(1,0,n-1);
	while(q--){
		ll p;
		cin>>p;
		ll minn = 1000000;
		ll a=0,b=p-1;
		while(b<n){
			minn = min(minn,query(1,0,n-1,a,b));
			a++;
			b++;
		}
		cout<<minn<<endl;
	}
}

