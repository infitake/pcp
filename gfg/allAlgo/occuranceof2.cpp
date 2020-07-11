// C++ program to count 2s from 0 to n 
#include <bits/stdc++.h> 
using namespace std; 

// Counts the number of 2s 
// in a number at d-th digit 
long long int count2sinRangeAtDigit(long long int n){
    long long int count=0,t;
    while(n>0){
        t = n%10;
        if(t ==2 )
            count++;
        n = n/10;
    }
    return count;
}

long long int finddigit(long long int n){
    long long int count=0;
    while(n>0){
        count++;
        n = n/10;
    }
    return count;
}
long long int getvaluptod(long long int d){
    long long int i = 1,val=1,ans = 0;
    if(d == 1) return 0;
    if(d == 2) return val;
    for(i=2;i<d;i++){
        val = (10)*val + pow(10,(i-1));
    }
    return val;
}
/* Counts the number of '2' digits between 0 and n */
long long int numberOf2sinRange(long long int number)
{
    long long int i,sum=0;
    long long int d = finddigit(number);
    long long int val = getvaluptod(d);
    long long int dg = pow(10,(d-1));
    // cout<<"d "<<d<<" val "<<val<<" dg "<<dg;
    if(number == dg) return val;
    
    else if(number>dg){
        for(i=dg;i<=number;i++){
            sum += count2sinRangeAtDigit(i);
        }
    }
    // cout<<" sum "<<sum<<endl;
    return (sum+val);
} 

// Driver Code 
int main() 
{ 
	cout << numberOf2sinRange(1000) << endl; 
	cout << numberOf2sinRange(18468); 
	return 0; 
} 
