#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string add(string s1,string s2){
	string final;
	int carry=0;
	int l1=s1.length();
	int l2=s2.length();
	int i=l1-1,j=l2-1;
	while((i>=0)&&(j>=0)){
		int a=s1[i]-'0';
		int b=s2[j]-'0';
		int sum  = (a+b+carry)%10;
		carry = (a+b+carry)/10;
		char k='0'+sum;
		final = k+final;
		i--;
		j--;
	}
	while(i>=0){
		int a = s1[i]-'0';
		int sum  = (a+carry)%10;
		carry = (a+carry)/10;
		char k='0'+sum;
		final = k+final;
		i--;
	}
	while(j>=0){
		int a = s2[j]-'0';
		int sum  = (a+carry)%10;
		carry = (a+carry)/10;
		char k='0'+sum;
		final = k+final;
		j--;
	}
	char k='0'+carry;
	if(carry>0)
	final = k+final;
	return final;
}
string hola(string s,int n){
	string final;
	while(n--){
		final=add(final,s);
	}
	return final;
}
string fac(string s,int n){
	if(n==1)
	return s;
	return fac(hola(s,n-1),n-1);
}

int main(){
    int n,p;
    cin>>n;
    p=n;
    string s;
    while(n>0){
    	char a = (n%10)+'0';
    	s=a+s;
    	n/=10;
    }
    cout<<fac(s,p)<<endl;
}

