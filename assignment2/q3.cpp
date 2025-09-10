#include<iostream>
using namespace std;

int findMissingNumber(int a[],int n){
    for (int i = 0; i < n - 1; i++) {
        if (a[i+1] != a[i] + 1) {
            return a[i] + 1; 
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