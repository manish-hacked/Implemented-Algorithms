#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef long long int ll;
void build(ll node,ll start,ll end,ll arr[],ll tree[]){
	if(start==end){
		tree[node]=arr[start];
	}else{
		ll mid = (start+end)/2;
		build(2*node,start,mid,arr,tree);
		build(2*node+1,mid+1,end,arr,tree);
		tree[node]=tree[2*node]+tree[2*node+1];
	}
}

ll query(ll node,ll start,ll end,ll l,ll r,ll arr[],ll tree[]){
	if(r<start||l>end){
		return 0;
	}
	if(l<=start&&r>=end){
		return tree[node];
	}
	ll mid=(start+end)/2;
	return query(2*node,start,mid,l,r,arr,tree)+query(2*node+1,mid+1,end,l,r,arr,tree);
}

void update(ll node,ll start,ll end,ll index,ll value,ll arr[],ll tree[]){
	if(start==end){
		arr[index]+=value;
		tree[node]+=value;
		return;
	}
	else{
		ll mid=(start+end)/2;
		if(index>=start&&index<=mid)
		update(2*node,start,mid,index,value,arr,tree);
		else
		update(2*node+1,mid+1,end,index,value,arr,tree);
	}
	tree[node]=tree[2*node]+tree[2*node+1];
	return;
}
void updateRange(ll node,ll start,ll end,ll l,ll r,ll value,ll arr[],ll tree[]){
	
	if(start>end||l>end||r<start){
		return;
	}
	if(start==end){
		tree[node]+=value;
		return;
	}
	ll mid=(start+end)/2;
	updateRange(2*node,start,mid,l,r,value,arr,tree);
	updateRange(2*node+1,mid+1,end,l,r,value,arr,tree);
	tree[node]=tree[2*node]+tree[2*node+1];
}



int main(){
	long long int n,i;
	printf("Enter The Number Of Elements\n");
	scanf("%lld",&n);
	long long int *arr=(long long int*)malloc(sizeof(long long int)*n);
	printf("Enter The Elements Of Array\n");
	for(i=0;i<n;i++)
	scanf("%lld",&arr[i]);
	long long int p = (ceil)((log(n)/log(2))+1);
	p=1<<p;
	long long int *tree = (long long int*)malloc(sizeof(long long int)*(p));
	build(1,0,n-1,arr,tree);
	long long int l,r,v;
	printf("Enter The left and right value\n");
	scanf("%lld%lld",&l,&r);
	printf("The Sum is %lld",query(1,0,n-1,l,r,arr,tree));
	printf("\n");
	printf("Enter The left and right and  value\n");
	scanf("%lld%lld%lld",&l,&r,&v);
	updateRange(1,0,n-1,l,r,v,arr,tree);
	printf("Enter The left and right value\n");
	scanf("%lld%lld",&l,&r);
	printf("The Sum is %lld",query(1,0,n-1,l,r,arr,tree));
	printf("\n");
}
