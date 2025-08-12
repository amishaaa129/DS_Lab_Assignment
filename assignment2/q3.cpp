#include<iostream>
using namespace std;

int findMissingNumber(int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i]-i!=1){
            return arr[i]-1;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"enter size of array "<<endl;
    cin>>n;
    cout<<"enter array elements "<<endl;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=findMissingNumber(arr,n);
    ans==-1?cout<<"no missing number"<<endl : cout<<"missing number is "<<ans;
}