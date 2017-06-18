#include<stdio.h>
#include<malloc.h>
#include<math.h>
typedef long long int ll;
ll *arr,*tree,n,p,*lazy,i;

void buildTree(ll node,ll start,ll end){
	if(start==end){
		tree[node]=arr[start];
		return;
	}
	ll mid = (start+end)/2;
	buildTree(2*node,start,mid);
	buildTree(2*node+1,mid+1,end);
	tree[node]=tree[2*node]+tree[2*node+1];
}

void update(ll node,ll start,ll end,ll index,ll value){
	if(start==end){
		arr[start]+=value;
		tree[node]+=value;
	}else{
		ll mid = (start+end)/2;
		if(index>=start&&index<=mid)
		update(2*node,start,mid,index,value);
		else
		update(2*node+1,mid+1,end,index,value);
		tree[node]=tree[2*node]+tree[2*node+1];
	}
	return;
}

ll queryRange(ll node,ll start,ll end,ll l,ll r){
	if(start>end||r<start||l>end){
		return 0;
	}
	if(lazy[node]!=0){
		tree[node]+=(end - start + 1)*lazy[node];
		if(start!=end){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(start>=l&&end<=r){
		return tree[node];
	}
	ll mid=(start+end)/2;
	return queryRange(2*node,start,mid,l,r)+queryRange(2*node+1,mid+1,end,l,r);
}

void updateRange(ll node,ll start,ll end,ll l,ll r,ll value){
	if(lazy[node]!=0){
		tree[node]+=(end - start + 1)*lazy[node];
		if(start!=end){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(start>end||l>end||r<start)
	return;
	if(start>=l&&end<=r){
		tree[node]+=(end-start+1)*value;
		if(start!=end){
			lazy[2*node]+=value;
			lazy[2*node+1]+=value;
		}
		return;
	}
	ll mid=(start+end)/2;
	updateRange(2*node,start,mid,l,r,value);
	updateRange(2*node+1,mid+1,end,l,r,value);
	tree[node]=tree[2*node]+tree[2*node+1];
}

int main(){
	scanf("%d",&n);
	arr=(ll*)malloc(sizeof(ll)*n);
	p=(ceil)((log(n)/log(2))+1);
	p=1<<p;
	tree=(ll*)malloc(sizeof(ll)*p);
	lazy=(ll*)malloc(sizeof(ll)*p);
	for(i=0;i<p;i++)
	lazy[i]=0;
	buildTree(1,0,n-1);
}
