#include<iostream>
using namespace std;

void BubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
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
    BubbleSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}