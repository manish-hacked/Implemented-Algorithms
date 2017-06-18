//Kmp Algorithm

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

void init(string &pat,ll lps[]){
	ll m = pat.length();
	ll len=0;
	lps[0]=0;
	ll i=1;
	while(i<m){
		if(pat[i]==pat[len]){
			len++;
			lps[i]=len;
			i++;
		}else{
			if(len!=0){
				len = lps[len-1];
			}else{
				i++;
				lps[i]=0;
			}
		}
	}
}
void KMPSearch(string &src,string &pat,ll lps[]){
	ll n = src.length();
	ll m = pat.length();
	ll i=0,j=0;
	while(i<n){
		if(src[i]==pat[j]){
			i++;
			j++;
		}
		if(j==m){
			printf("Found pattern at index %d \n", i-j);
			j = lps[j-1];
						
		}else if(i<n&&pat[j]!=src[i]){
			if(j!=0){
				j = lps[j-1];
			}else{
				i++;
			}
		}
	}
}
int main(){
	string src,pat;
	cin>>src>>pat;
	ll n = src.length();
	ll m = pat.length();
	ll lps[m];
	init(pat,lps);
	ll i,j;
	KMPSearch(src,pat,lps);
}
