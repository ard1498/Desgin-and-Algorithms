#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int> a1,vector<int> a2){
    return a1[a1.size()-1] < a2[a2.size()-1];
}

int main(){
    vector<vector<int> > a = {{3,2,1},{4,5,6},{1,2,3}};
    sort(a.begin(),a.end(),compare);
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            cout<<a[i][j];
        }
        cout<<"\n";
    }
    cout<<(2%3);
}

/*

kruskals algorithm unoin-find without using rank..........................................................................

bool compare(vector<int> v1,vector<int> v2){
    return v1[2] < v2[2];
}

int findparent(int node , vector<int> parent){
    if(parent[node] == node){
        return  node;
    }
    return findparent(parent[node],parent);
}

int Solution::solve(int A, vector<vector<int> > &B) {
    
    vector<int> parent(A+1);
    for(int i = 1;i < A+1;i++){
        parent[i] = i;
    }
    
    int n = B.size();
    sort(B.begin(),B.end(),compare);
    int count = 0, w = 0;
    int i = 0;
    while(count != A-1){
        int sourceparent = findparent(B[i][0],parent);
        int destparent = findparent(B[i][1],parent);
        if(sourceparent != destparent){
            w += B[i][2];
            count++;
            parent[sourceparent] = destparent;
        }
        i++;
    }
    
    return w;
}


kruskals algorithm using unoin-rank method with trees concept.........................................................................

struct subset{
    int parent;
    int rank;
};


int find(vector<subset> &s , int val){
    
}


void unionset(vector<subset> &s,int source,int dest){
    if(s[source].rank > s[dest].rank){
        s[dest].parent = source;
    }
    else if(s[source].rank < s[dest].rank){
        s[source].parent = dest;
    }
    else{
        s[source].parent = dest;
        s[dest].rank++;
    }
}

int findparent(int val,vector<subset> &s){
    if(s[val].parent == val){
        return val;
    }
    s[val].parent = findparent(s[val].parent,s);
    return s[val].parent;
}

bool compare(vector<int> v1,vector<int> v2){
    return v1[2] < v2[2];
}

int Solution::solve(int A, vector<vector<int> > &B) {
    int n = B.size();
    sort(B.begin(),B.end(),compare);
    vector<subset> s(A+1);
    for(int i= 1 ;i < A+1;i++){
        s[i].parent = i;
        s[i].rank = 0;
    }
    
    int count = 0,i = 0,w = 0;
    while(count != A-1){
        int sourceparent = findparent(B[i][0],s);
        int destparent = findparent(B[i][1],s);
        if(sourceparent != destparent){
            count++;
            w += B[i][2];
            unionset(s,sourceparent,destparent);
        }
        i++;
    }
    return w;
}


*/



/*
	
*/