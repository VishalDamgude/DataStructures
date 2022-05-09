#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
class Solution{
public:
    unordered_map<string,int> mp;
    
    int solve(string S,int i,int j, bool isTrue)
    {
        if(i > j) return 0;
        if(i == j) {
            if(isTrue) {
                return S[i] == 'T' ? 1 : 0;
            }
            else {
                return S[i] == 'F' ? 1 : 0;
            }
        }
        
        string key = to_string(i);
        key.push_back(' ');
        key.append(to_string(j));
        key.push_back(' ');
        key.append(to_string(isTrue));
        
        if(mp.find(key) != mp.end()) {
            return mp[key];
        }
        
        int ans = 0;
        
        for(int k = i+1; k<=j-1; k=k+2)
        {
            int leftTrue, leftFalse, rightTrue, rightFalse;
            
            string leftTruekey = to_string(i);
            leftTruekey.push_back(' '); 
            leftTruekey.append(to_string(k-1)); 
            leftTruekey.push_back(' '); 
            leftTruekey.append(to_string(true));
            
            string leftFalsekey = to_string(i);
            leftFalsekey.push_back(' '); 
            leftFalsekey.append(to_string(k-1)); 
            leftFalsekey.push_back(' '); 
            leftFalsekey.append(to_string(false));
            
            string rightTruekey = to_string(k+1); 
            rightTruekey.push_back(' '); 
            rightTruekey.append(to_string(j)); 
            rightTruekey.push_back(' '); 
            rightTruekey.append(to_string(true));
            
            string rightFalsekey = to_string(k+1); 
            rightFalsekey.push_back(' '); 
            rightFalsekey.append(to_string(j)); 
            rightFalsekey.push_back(' ');
            rightFalsekey.append(to_string(false));
            
            if(mp.find(leftTruekey) != mp.end()) {
                leftTrue = mp[leftTruekey];
            }
            else {
                leftTrue = solve(S,i,k-1,true);
            }
            
            if(mp.find(leftFalsekey) != mp.end()) {
                leftFalse = mp[leftFalsekey];
            }
            else {
                leftFalse = solve(S,i,k-1,false);
            }
            
            if(mp.find(rightTruekey) != mp.end()) {
                rightTrue = mp[rightTruekey];
            }
            else {
                rightTrue = solve(S,k+1,j,true);
            }
            
            if(mp.find(rightFalsekey) != mp.end()) {
                rightFalse = mp[rightFalsekey];
            }
            else {
                rightFalse = solve(S,k+1,j,false);
            }
            
            if(S[k] == '&') 
            {
                if(isTrue) {
                    ans = ans + leftTrue*rightTrue; 
                }
                else {
                    ans = ans + leftFalse*rightTrue + leftTrue*rightFalse + leftFalse*rightFalse;  
                }
            }
            else if(S[k] == '|') 
            {
                if(isTrue) {
                    ans = ans + leftTrue*rightFalse + leftFalse*rightTrue + leftTrue*rightTrue;
                }
                else {
                    ans = ans + leftFalse*rightFalse;  
                }
            }
            else // S[k] == "^" 
            {
                if(isTrue) {
                    ans = ans + leftFalse*rightTrue + leftTrue*rightFalse; 
                }
                else {
                    ans = ans + leftTrue*rightTrue + leftFalse*rightFalse;  
                }
            }
            
        }
        return mp[key] = ans%1003;
    }
    
    int countWays(int N, string S){
        // code here
        mp.clear();
        return solve(S,0,N-1,true);
    }
};
