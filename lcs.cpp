#include<bits/stdc++.h>
using namespace std;

string getlcs(string s1,string s2){
    int m = s1.size() , n = s2.size();
    int dp[n+1][m+1];

    for(int i = 0; i <= n;i++){
        for(int j = 0;j <= m;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(s1[j-1] == s2[i-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else if(dp[i-1][j] >= dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = (dp[i][j-1]);
            }
        }
    }

   // for(int i = 0; i < )
    string op = "";
    int i = n,j = m;
    while(i > 0 && j > 0){
        if(s1[j-1] == s2[i-1]){
            op+=s1[j-1];
            i = i-1;
            j = j-1;
        }
        else if(dp[i][j] == dp[i-1][j]){
            i = i-1;
        }
        else{
            j = j-1;
        }
    }
    reverse(op.begin(),op.end());
    return op;
}

int main(){
    string s1,s2;
    cout<<"\nenter the string 1 : ";
    cin>>s1;
    cout<<"\nenter the string 2 : ";
    cin>>s2;

    cout<<getlcs(s1,s2);
    return 0;
}