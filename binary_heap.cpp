#include<bits/stdc++.h>
using namespace std;
#define N 100001
typedef long long int ll;

ll arr[N];
ll size=0;

map<ll,ll> m;

void swap(ll *a,ll *b){
	ll temp = *a;
	*a=*b;
	*b=temp;
}

void heapify(ll i){
	ll left = 2*i;
	ll right = 2*i+1;
	ll largest;
	if(left<=size&&arr[left]<arr[i]){
		largest = left;
	}else{
		largest = i;
	}	
	if(right<=size&&arr[right]<arr[largest]){
		largest=right;
	}
	if(largest!=i){
		swap(&arr[largest],&arr[i]);
		heapify(largest);
	}
}

ll check(ll i,ll x){
	for(i=1;i<=size;i++)
	if(arr[i]==x){
		return i;
	}
	return 0;
}

void Insert(ll x){
	arr[++size]=x;
	m[x]=size;
	ll p = size/2;
	ll q= size;
	while(p>0&&arr[p]>arr[q]){
		swap(&arr[p],&arr[q]);
		q=p;
		p=p>>1;
	}
}

void Delete(ll x){
	ll index = m[x];
	
	swap(&arr[index],&arr[size]);
	size--;
	heapify(index);
}

int main(){
	ll q;
	cin>>q;
	ll p;
	while(q--){
		int x;
		cin>>x;
		switch(x){
			case 1:
				cin>>p;
				Insert(p);
				break;
			case 2:
				cin>>p;
				Delete(p);
				break;
			case 3:
				cout<<arr[1]<<endl;
				break;
		}
	}
}
