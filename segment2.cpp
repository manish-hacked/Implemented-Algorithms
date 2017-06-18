#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int *arr,*tree,n,p,i;

void build(int node,int start,int end){
	if(start==end){
		tree[node]=arr[start];
	}else{
		int mid = (start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node]=tree[2*node]+tree[2*node+1];
	}
}

int query(int node,int start,int end,int l,int r){
	if(r<start||l>end||start>end){
		return 0;
	}else{
		if(l<=start&&r>=end){
			return tree[node];
		}
		int mid = (start+end)/2;
		return query(2*node,start,mid,l,r)+query(2*node+1,mid+1,end,l,r);
	}
}

void update(int node,int start,int end,int index,int value){
	if(start==end){
		arr[index]+=value;
		tree[node]+=value;
	}else{
		int mid = (start+end)/2;
		if(index>=start&&index<=mid)
		update(2*node,start,mid,index,value);
		else
		update(2*node+1,mid+1,end,index,value);
		tree[node]=tree[2*node]+tree[2*node+1];
		return;
	}
}

void updateRange(int node,int start,int end,int l,int r,int value){
	if(start>end||l>end||start>r)
	return;
	if(start==end){
		tree[node]+=value;
		return;
	}
	int mid = (start+end)/2;
	updateRange(2*node,start,mid,l,r,value);
	updateRange(2*node+1,mid+1,end,l,r,value);
	tree[node]=tree[2*node]+tree[2*node+1];
}

int main(){
	scanf("%d",&n);
	arr=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	p=(ceil)((log(n)/log(2))+1);
	p=1<<p;
	tree=(int*)malloc(sizeof(int)*p);
	build(1,0,n-1);
	int l,r,v;
	printf("Enter The left and right value\n");
	scanf("%d%d",&l,&r);
	printf("The Sum is %d",query(1,0,n-1,l,r));
	printf("\n");
	printf("Enter The left and right and  value\n");
	scanf("%d%d%d",&l,&r,&v);
	updateRange(1,0,n-1,l,r,v);
	printf("Enter The left and right value\n");
	scanf("%d%d",&l,&r);
	printf("The Sum is %d",query(1,0,n-1,l,r));
	printf("\n");
}
