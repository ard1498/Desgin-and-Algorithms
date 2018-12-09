#include<bits/stdc++.h>
using namespace std;

struct mm{
    int min,max;
};

mm getminmax(vector<int> arr,int beg,int end){
    mm obj;
    if(beg > end){
        obj.min = INT_MIN;
        obj.max = INT_MAX;
        return obj;
    }
    else if(beg == end){
        obj.min = arr[beg];
        obj.max = arr[beg];
        return obj;
    }
    int mid = (beg+end)/2;
    mm left_obj = getminmax(arr,beg,mid);
    mm right_obj = getminmax(arr,mid+1,end);

    obj.min = min(left_obj.min,right_obj.min);
    obj.max = max(left_obj.max,right_obj.max);
    return obj;
}

int main(){
    int n;
    cout<<"\nenter the no of elements in array:";
    cin>>n;
    vector<int> arr(n);
    cout<<"\nenter array elements:";
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    mm ans = getminmax(arr,0,n-1);
    cout<<"\nthe min element is:"<<ans.min;
    cout<<"\nthe max element is:"<<ans.max;
    return 0;
}