#include<bits/stdc++.h>
using namespace std;

int binsearch(vector<int> arr,int ele,int n){
    if(n==0){
        return -1;
    }    
    int beg= 0,end = n-1;
    while(beg <= end){
        int mid = (beg+end)/2;
        if(arr[mid]==ele){
            return mid;
        }
        else if(arr[mid] < ele){
            beg=mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"\nenter the size of array:";
    cin>>n;
    vector<int> arr(n);
    cout<<"\nenter the array elements :";
    for(int i = 0 ;i < n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    cout<<"\nsorted array is:";
    for(int i = 0;i < n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    int ele;
    cout<<"\nenter the element to be searched for:";
    cin>>ele;
    cout<<"\nelement found(pos) or not(-1):"<<binsearch(arr,ele,n);
}