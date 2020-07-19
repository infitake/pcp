#include <bits/stdc++.h>
using namespace std;
#define ll long long

// map<ll,string> roman={{1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},{40,"XL"},{50,"L"},{90,"XC"},{100,"C"},{400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}}; 

string integertoroman(int number){
	string s;
    int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000}; 
    string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"}; 
    int i=12;     
    while(number>0) 
    { 
      int div = number/num[i]; 
      number = number%num[i]; 
      while(div--) 
      { 
        s += sym[i];
      } 
      i--; 
    } 
    return s;
} 
int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	ll t,n; cin>>t;
	
	while(t--){
		cin>>n;
		cout<<integertoroman(n)<<endl;
	}
	return 0;
}
// 3
// XL
// IL
// MCMIV
// 40
// 49
// 1904
