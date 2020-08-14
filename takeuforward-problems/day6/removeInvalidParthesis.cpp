#include <bits/stdc++.h>
using namespace std;

bool isvalid(string str) {
	int cnt = 0; 
    for (int i = 0; i < str.length(); i++) 
    { 
        if (str[i] == '(') 
            cnt++; 
        else if (str[i] == ')') 
            cnt--; 
        if (cnt < 0) 
            return false; 
    } 
    return (cnt == 0);
}

void removeInvalid(string str){
	queue<string> q;
	set<string> visit;
	vector<string> ans;
	// str is empty
	if(!str.size()) {
		cout<<" "<<endl;
		return;
	}

	q.push(str);
	visit.insert(str);
	bool level=false;
	while(!q.empty()){
		string s = q.front();
		q.pop();
		if(isvalid(s)){
			cout<<s<<endl;
			level = true;
		}
		if(level) continue;

		for(int i=0;i<s.size();i++){
			if(s[i]!='(' && s[i]!=')') continue;
			string samp_string = s.substr(0,i) + s.substr(i+1);
			if(visit.find(samp_string) == visit.end()){
				q.push(samp_string);
				visit.insert(samp_string);
			}
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	int t,n; cin>>t;
	while(t--){
		string str;
		cin>>str;
		removeInvalid(str);
	}
	return 0;
}