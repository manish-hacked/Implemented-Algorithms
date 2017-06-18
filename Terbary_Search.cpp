#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
double x[60001];
double v[60001];
ll n;
double get(double d){
	ll i;
	double ans=0;
	for(i=0;i<n;i++){
		double a = x[i];
		double b = v[i];
		if(a<d){
			double p = d-a;
			ans=max(ans,p/b);
		}else{
			double p = a-d;
			ans=max(ans,p/b);
		}
	}
	return ans;
}
int main(){
	//<<1e4;
	ll i;
	cin>>n;double l,r;
	for(i=0;i<n;i++)cin>>x[i];
	for(i=0;i<n;i++)cin>>v[i];
	l = *min_element(x,x+n);
	r = *max_element(x,x+n);
	double ans;
	while(r>=l){
        //cout<<l<<" "<<r<<" "<<l1<<" "<<r1<<endl;
        if(abs(l-r)<0.000001){
        	ans = get(l);
        	break;
        }
		double mid1 = l + (r-l)/3;
        double mid2 = r -  (r-l)/3;
        double a = get(mid1);
        double b = get(mid2);
        if(a<=b){
        	r = mid2;
        }else{
        	l=mid1;
        }
	}
	printf("%.12lf\n",ans);
}
