#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string,int>mp;

bool solve(string a,string b)
{
    if(a.compare(b)==0)
        return true;
    if(a.length()<=1)
        return false;
    string t="";
    t+=a+" "+b;
    if(mp.find(t)!=mp.end())
        return mp[t];
    int n=a.length();
    bool flag=false;
    for(int i=1;i<=n-1;i++)
    {
        bool cond1,cond2;
        cond1=cond2=false;
        if(solve(a.substr(0,i),b.substr(0,i))==true && solve(a.substr(i,n-i),b.substr(i,n-i))==true)
            cond1=true;
        if(solve(a.substr(0,i),b.substr(n-i,i))==true && solve(a.substr(i,n-i),b.substr(0,n-i))==true)
            cond2=true;
        if(cond1 || cond2)
            {
                flag=true;
                break;
            }
    }
    return mp[t]=flag;
}

int main()
{
    string a,b;
    cin>>a>>b;
    if(a.length()==0 && b.length()==0)
        return true;
    int n=a.length();
    int m=b.length();
    if(n>m || m>n)
        return false;
    mp.clear();
    cout<<solve(a,b);
    return 0;
}