#include<iostream>
#include<vector>

using namespace std;

int BinarySearch_AscendingOrderArray(int arr[], int low, int high, int target){
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid]>target){
            low = mid+1;
        }else{ // if arr[mid] < target
            high = mid-1;
        }
    }
    return -1; // if element is not found
}

int BinarySearch_DescendingOrderArray(int arr[], int low, int high, int target){
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid]>target){
            high = mid-1;
        }else{ // if arr[mid] < target
            low = mid+1;
        }
    }
    return -1; // if element is not found
}

void checkOrder_thenFind(int arr[],int target,int size){
    if(size==1){
        if(arr[0]==target){
            cout<<"Element found at = "<<0<<"th index in given array \n";
            return;
        }
        cout<<"Element not found \n";
        return;
    }else if(size>1){
        int low=0;
        int high=size-1;
        if(arr[0]>arr[size-1]){ // Ascending
            int getIndex = BinarySearch_AscendingOrderArray(arr,low,high,target);
            if(getIndex>-1){
                cout<<"Element found at = "<<getIndex<<"th index in given array \n";
            }else{
                cout<<"Element not found \n";
            }
        }else{ // Descending
            int getIndex = BinarySearch_DescendingOrderArray(arr,low,high,target);
            if(getIndex>-1){
                cout<<"Element found at = "<<getIndex<<"th index in given array \n";
            }else{
                cout<<"Element not found \n";
            }
        }
    }
}

int main(){
    int arr[] = {9,8,7,6,5,4,3,2,1};
    int target = 6;
    int size = sizeof(arr)/sizeof(arr[0]);
    if(size==1){
        if(arr[0]==target)return 0;
    }
    checkOrder_thenFind(arr,target,size);
    return 0;
}