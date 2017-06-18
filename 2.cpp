#include<bits/stdc++.h>
using namespace std;


#define X 50
#define Y 50

#define R 50

#define PI 3.14159265

int check(double x,double y){
	double l;
	l = ((x-X)*(x-X)+(y-Y)*(y-Y)-2500);
	if(l<=0)
	return 1;
	else
	return 0;
}


int main(){
	int t;
	cin>>t;
	int i;
	for(i=1;i<=t;i++){
		double p,x,y;
		cin>>p>>x>>y;
		if(check(x,y)){
			double ans;
			if(x>=50&&y>=50){
				if((x-X)==0)
				ans=0;
				else{
					double p = (y-Y)/(x-X);
					ans  = 90.000-(atan (p) * 180 / PI);
				}
				//cout<<ans<<endl;
			}else if(x>=50&&y<50){
				if((x-X)==0)
				ans=180.0;
				else{
					double p = (y-Y)/(x-X);
					ans  = 90.000-(atan (p) * 180 / PI);	
				}
				//cout<<ans<<endl;
			}else if(x<50&&y<50){
				double p = (y-Y)/(x-X);
				ans  = 270.000-(atan (p) * 180 / PI);
				//cout<<ans<<endl;
			}else{
				if((x-X)==0)
				ans=270.0;
				else{
					double p = (y-Y)/(x-X);
					ans  = 270.000- (atan (p) * 180 / PI);	
				}
				//cout<<ans<<endl;
			}	
			p = (p/100)*360;
			//cout<<p<<endl;
			if(p>=ans){
				cout<<"Case #"<<i<<": "<<"black"<<endl;
			}else{
				cout<<"Case #"<<i<<": "<<"white"<<endl;
			}
		}else{
			cout<<"Case #"<<i<<": "<<"white"<<endl;
		}
	}
}
