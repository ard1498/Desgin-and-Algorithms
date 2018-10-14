#include<bits/stdc++.h>
using namespace std;

void getsoln(vector<vector<int> > s,int i,int j){
    if(i == j){
        cout<<" "<<"A"<<i;
        return;
    }
    cout<<"(";
    getsoln(s,i,s[i][j]);
    getsoln(s,s[i][j]+1,j);
    cout<<")";
    return;
}

int getminval(vector<int> d,int n){
    vector<vector<int> > m (n+1,vector<int>(n+1,0));
    vector<vector<int> > s (n+1,vector<int>(n+1,0));
    //int s[n+1][n+1] = {0};

    for(int l = 2;l <= n;l++){
        for(int i = 1;i <= n-l+1 ;i++){
            int j = i + l - 1; 
            int cost = INT_MAX;
            for(int k = i;k < j;k++){
                int t = m[i][k]+m[k+1][j]+(d[i-1]*d[k]*d[j]);
                if(cost > t){
                    cost = t;
                    s[i][j] = k;
                }
            }
            m[i][j] = cost;
            //cout<<cost;

        }
    }
    cout<<endl<<"\ns is :"<<endl;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cout<<s[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<endl<<"m is:"<<endl;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n-1;j++){
            cout<<m[i][j]<<"\t";
        }
        cout<<"\n";
    }

    getsoln(s,1,n-1);
    cout<<endl;
    return m[1][n-1];
}

int main(){
    int n ;
    cout<<"\nenter the no of dimension :";
    cin>>n;
    vector<int> d(n);
    for(int i = 0;i < n;i++){
        cin>>d[i];
    }
    cout<<getminval(d,n);
    return 0;
}