#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	priority_queue< ll, vector<ll> , greater<ll> > arrive;
	priority_queue< ll, vector<ll> , greater<ll> > arrive;
	ll no=0,n,k;
	cin>>n;
	ll i,p;
	i=1;
	while(i<=n){
		cin>>p;
		if(i%2!=0){
			if(min.empty()){
				max.push(p);
			}else{
				if(min.top()<p){
					max.push(min.top());
					min.pop();
					min.push(p);
				}else{
					max.push(p);
				}
			}
		}else{
			if(max.empty()){
				min.push(p);
			}else{
				if(max.top()>p){
					min.push(max.top());
					max.pop();
					max.push(p);
				}else{
					min.push(p);
				}
			}
		}
		
		if(i%2==0){
			double m = max.top();
			double n = min.top();
			double ans = (m+n)/2;
			printf("%.1f\n",ans);
		}else{
			double m = max.top();
			printf("%.1f\n",m);
		}
		i++;
	}
	return 0;
}

