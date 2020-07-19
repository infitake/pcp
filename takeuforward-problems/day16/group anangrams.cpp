// #include <bits/stdc++.h>
// using namespace std;

// // An anagram of a string is another string that contains same characters, 
// // only the order of characters can be different. 
// // For example, “abcd” and “dabc” are anagram of each other.


// // Method 1:(using map)
// // This contain extra space

// void checkanagram(vector<string> str){
// 	vector<vector<string>> groupanagram;
//         // if(str.size() == 0) return groupanagram;
//         map<string,int> mp;
//         char p='+';
//         for(auto s:str){
//             int gp=0;
//             for(auto x:s){
//                 gp += (x-'a'); 
//             }
//             // if(mp[s]!=0) mp[s+p]=gp;
//             else mp[s]=gp;
//         }
//         int n = mp.size();
//         map<int,int> fmp;
//         int i=1;
//         for(auto x:mp){
//             // if(fmp[x.second]==0){
//             //     fmp[x.second]=i;
//             //     i++;
//             // }
//         	cout<<x.first<<" "<<x.second<<endl;
//         }
//  //        map<int,vector<string>> smp;
//  //        for(auto x:mp){
//  //            string st=x.first;
//  //            int hp=st.size();
//  //            if(st[hp-1] == '+') st.pop_back();
//  //            smp[(fmp[x.second]-1)].push_back(st);
//  //        }
//  //        for(int i=0;i<smp.size();i++){
//  //            vector<string> v;
//  //            for(auto ktp:smp[i]){
//  //                v.push_back(ktp);
//  //            }
//  //            groupanagram.push_back(v);
//  //        }
// 	// int a = groupanagram.size();
// 	// for(int i=0;i<a;i++){
// 	// 	for(int j=0;j<groupanagram[i].size();j++){
// 	// 		cout<<groupanagram[i][j]<<" ";
// 	// 	}
// 	// 	cout<<endl;
// 	// }
// }

// int main() {
	// #ifndef ONLINE_JUDGE
 //    	freopen("input.txt", "r", stdin);
 //    	freopen("output.txt", "w", stdout);
	// #endif
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	//ios_base& scientific (ios_base& str);
// 	int t,n; cin>>t;
// 	while(t--){
// 		cin>>n;
// 		vector<string> str;
// 		string s;
// 		for(int i=0;i<n;i++){
// 			cin>>s;
// 			str.push_back(s);
// 		}
// 		checkanagram(str);
// 	}
// 	return 0;
// }

// // Method 2

// CPP program for finding all anagram 
// pairs in the given array 
#include <algorithm> 
#include <iostream> 
#include <unordered_map> 
#include <vector> 
using namespace std; 
  
// Utility function for 
// printing anagram list 
void printAnagram( 
    unordered_map<string, 
                  vector<string> >& store) 
{ 
    unordered_map<string, 
                  vector<string> >::iterator it; 
    for (it = store.begin(); 
         it != store.end(); it++) { 
        vector<string> temp_vec(it->second); 
        int size = temp_vec.size(); 
        if (size > 1) { 
            for (int i = 0; i < size; i++) { 
                cout << temp_vec[i] << " "; 
            } 
            cout << "\n"; 
        } 
    } 
} 
  
// Utility function for storing 
// the vector of strings into HashMap 
void storeInMap(vector<string>& vec) 
{ 
    unordered_map<string, 
                  vector<string> > 
        store; 
    for (int i = 0; i < vec.size(); i++) { 
  
        string tempString(vec[i]); 
        sort(tempString.begin(), 
             tempString.end()); 
  
        // Check for sorted string 
        // if it already exists 
        if (store.find( 
                tempString) 
            == store.end()) { 
            vector<string> temp_vec; 
            temp_vec.push_back(vec[i]); 
            store.insert(make_pair( 
                tempString, temp_vec)); 
        } 
  
        else { 
            // Push new string to 
            // already existing key 
            vector<string> temp_vec( 
                store[tempString]); 
            temp_vec.push_back(vec[i]); 
            store[tempString] = temp_vec; 
        } 
    } 
  
    // print utility function for printing 
    // all the anagrams 
    printAnagram(store); 
} 
  
// Driver code 
int main() 
{ 
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    // initialize vector of strings 
    vector<string> arr; 
    arr.push_back("geeksquiz"); 
    arr.push_back("geeksforgeeks"); 
    arr.push_back("abcd"); 
    arr.push_back("forgeeksgeeks"); 
    arr.push_back("zuiqkeegs"); 
    arr.push_back("cat"); 
    arr.push_back("act"); 
    arr.push_back("tca"); 
  
    // utility function for storing 
    // strings into hashmap 
    storeInMap(arr); 
    return 0; 
} 