#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll number=0;


void Merge(ll arr[],ll l,ll r){
	ll mid = (l+r)/2;
	ll L[mid-l+1];
	ll R[r-mid];
	ll k=0;
	ll i;
	for(i=l;i<=mid;i++){
		L[k]=arr[i];
		k++;
	}
	k=0;
	for(;i<=r;i++){
		R[k]=arr[i];
		k++;
	}
	i=0;
	k=l;
	ll j=0;
	while(i<(mid-l+1)&&j<(r-mid)){
		if(L[i]<=R[j]){
			arr[k]=L[i];
			i++;
		}else{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<(mid-l+1)){
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<(r-mid)){
		arr[k]=R[j];
		j++;
		k++;
	}
}

void MergeSort(ll arr[],ll l,ll r){
	if(l>=r)
	return;
	ll mid = (l+r)/2;
	MergeSort(arr,l,mid);
	MergeSort(arr,mid+1,r);
	Merge(arr,l,r);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		number=0;
		ll n;
		cin>>n;
		ll arr[n];
		ll i,j;
		for(i=0;i<n;i++)
		cin>>arr[i];
		MergeSort(arr,0,n-1);
		for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
		cout<<endl;
	}
}
