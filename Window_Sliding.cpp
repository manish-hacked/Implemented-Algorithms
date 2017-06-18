#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long int n,i,j;
	scanf("%lld",&n);
	string s;
	cin>>s;
	long long int p=n/4;
	long long int a=0,c=0,t=0,g=0,aN=0,cN=0,tN=0,gN=0;
	for(i=0;i<n;i++){
		if(s[i]=='A')
		a++;
		else if(s[i]=='C')
		c++;
		else if(s[i]=='T')
		t++;
		else
		g++;
	}
	if(a>p)
	a=a-p;
	else
	a=0;
	if(c>p)
	c=c-p;
	else
	c=0;
	if(t>p)
	t=t-p;
	else
	t=0;
	if(g>p)
	g=g-p;
	else
	g=0;
	long long int start,last,length;
	for(i=0;i<n;i++){
		if(s[i]=='A'){
			aN++;
		}else if(s[i]=='C'){
			cN++;
		}else if(s[i]=='T'){
			tN++;
		}else{
			gN++;
		}
		if((aN>=a)&&(cN>=c)&&(tN>=t)&&(gN>=g)){
			last=i;
			break;
		}
	}
	length=last+1;
	start=0;
	while(1){
		while(1){
			if(s[start]=='A'){
					aN--;
				}else if(s[start]=='C'){
					cN--;
				}else if(s[start]=='T'){
					tN--;
				}else{
					gN--;
				}
				start++;
				if((aN>=a)&&(cN>=c)&&(tN>=t)&&(gN>=g)){
					length=last-start+1;
				}else{
					break;
				}
			}
			last++;
			if(last>=n)
			break;
			if(s[last]=='A'){
					aN++;
				}else if(s[last]=='C'){
					cN++;
				}else if(s[last]=='T'){
					tN++;
				}else{
					gN++;
				}
	}
	cout<<length<<endl;
    return 0;
}

