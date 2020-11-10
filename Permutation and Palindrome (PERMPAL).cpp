#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    string n;
	    cin>>n;
	    map<char,vector<int> > m;
	    for(int i=0;i<n.length();i++){
	        m[n[i]].push_back(i);
	    }
	    int oddFreq = 0;
	    for(int i=0;i<26;i++){
	        if( (m[(char)(i+97)].size() % 2) != 0){
	            oddFreq++;
	        }
	    }
	    if(oddFreq>=2){
	         cout<<"-1"<<endl;
	         return -1;
	    }
	    int result[n.length()];
	    int start = 0, end = n.length()-1;
	    for(int i=0;i<26;i++){
	        for(int j=0;j< m[(char)(i+97)].size() ;j+=2){
	            
	            if(( m[(char)(i+97)].size() -j) == 1) {         //Odd frequency
	                result[n.length()/2] = m[(char)(i+97)][j+1];
	                continue;
	            }          
	            result[start] = m[(char)(i+97)][j] ;            //Even frequency
	            result[end] = m[(char)(i+97)][j+1];             //Even frequency
	            start++; end--;
	        }
	    }
	    for(int i=0;i<n.length();i++){
	        cout<<result[i]+1<<" ";
	    }
	       
	}
	return 0;
}

