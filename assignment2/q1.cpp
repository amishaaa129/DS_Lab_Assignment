#include<iostream>
using namespace std;

int binarySearch(int arr[], int n,int target){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target)
            low=mid+1;
        else 
            high=mid-1;
    }
    return -1;
}

int main(){
    int n,target;
    cout<<"enter size of array "<<endl;
    cin>>n;
    cout<<"enter array elements "<<endl;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"enter target"<<endl;
    cin>>target;
    int index=binarySearch(arr,n,target);
    cout<<"element found at index "<<index<<endl;
}