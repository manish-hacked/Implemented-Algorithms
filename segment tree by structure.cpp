#include<bits/stdc++.h>
using namespace std;
#define sl(n) scanf("%lld",&n)
#define sll(m,n) scanf("%lld%lld",&m,&n)
#define debug(n) printf("%lld\n",n)
typedef long long int ll;
//#define INPUT
struct seg{
	ll Sum;
	ll pSum;
	ll sSum;
	ll mSum;
};
struct seg *tree;
ll *arr;


struct seg maxx(struct seg a,struct seg b){
	struct seg res;
	res.Sum = a.Sum+b.Sum;
	res.pSum = std::max(a.pSum,a.Sum+b.pSum);
	res.sSum = std::max(b.sSum,a.sSum+b.Sum);
	res.mSum = std::max(std::max(a.mSum,b.mSum),a.sSum+b.pSum);
	return res;
}

void build(long long int node,long long int start,long long int end){
	if(start==end){
		tree[node].Sum=tree[node].pSum=tree[node].sSum=tree[node].mSum=arr[start];
	}else{
		long long int mid = (start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node]=maxx(tree[2*node],tree[2*node+1]);
	}
}

struct seg query(long long int node,long long int start,long long int end,long long int l,long long int r){
	if(r<start||l>end){
		struct seg temp;
		temp.Sum=temp.pSum=temp.sSum=temp.mSum=-15008;
		return temp;
	}
	if(l<=start&&r>=end){
		return tree[node];
	}
	long long int mid=(start+end)/2;
	return maxx(query(2*node,start,mid,l,r),query(2*node+1,mid+1,end,l,r));
}
void update(ll node,ll start,ll end,ll index,ll value){
	if(start==end){
		arr[index] = value;
		tree[node].Sum=tree[node].pSum=tree[node].sSum=tree[node].mSum=arr[index];
		return;
	}
	else{
		ll mid=(start+end)/2;
		if(index>=start&&index<=mid)
		update(2*node,start,mid,index,value);
		else
		update(2*node+1,mid+1,end,index,value);
	}
	tree[node]=maxx(tree[2*node],tree[2*node+1]);
	return;
}

int main(){
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       freopen("output.cpp", "w", stdout);
   	#endif
   	ll n,i;
	scanf("%lld",&n);
	arr=(ll*)malloc(sizeof(ll)*n);
	for(i=0;i<n;i++)
	scanf("%lld",&arr[i]);
	ll p = (ceil)((log(n)/log(2))+1);
	p=1<<p;
	tree = (struct seg*)malloc(sizeof(struct seg)*(p));
	build(1,0,n-1);
	ll q;
	scanf("%lld",&q);
	while(q--){
		ll hola;cin>>hola;
		if(hola){
			ll l,r;
			scanf("%lld%lld",&l,&r);
			--l;--r;
			printf("%lld\n",query(1,0,n-1,l,r).mSum);
		}else{
			ll l,r;
			scanf("%lld%lld",&l,&r);
			--l;
			update(1,0,n-1,l,r);
		}
	}
} 
