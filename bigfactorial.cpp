#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int arr[200];
int main(){
    int n,p;
    cin>>n;
    p=n;
    int i=0;
    while(p>0){
    	arr[i]=p%10;
    	p/=10;
    	i++;
    }
    int len = i;
    int j=n-1;
    for(;j>1;j--){
    	int carry=0;
    	int k;
    	for(k=0;k<len;k++){
    		int m = (arr[k]*j)+carry;
    		arr[k]=(m%10);
    		carry = m/10;
    	}
    	while(carry>0){
    		arr[len]=carry%10;
    		carry/=10;
    		len++;
    	}
    }
    for(j=(len-1);j>=0;j--)
    cout<<arr[j];
    cout<<endl;
}

