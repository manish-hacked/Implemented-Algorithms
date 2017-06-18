#include<bits/stdc++.h>
using namespace std;

int shift,add;
set<string> mp;


void dfs(string s){
	mp.insert(s);
	string temp=s;
	int n = s.length();
	for(int i=0;i<n;i++){
		temp[(i+shift)%n]=s[i];
	}
	if(mp.find(temp)==mp.end())
	dfs(temp);
	temp = s;
	for(int i=1;i<n;i+=2){
		temp[i]='0'+((s[i]-'0')+add)%10;
	}
	if(mp.find(temp)==mp.end())
	dfs(temp);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		cin>>add>>shift;
		mp.clear();
		dfs(s);
		cout<<*mp.begin()<<endl;
	}
}
