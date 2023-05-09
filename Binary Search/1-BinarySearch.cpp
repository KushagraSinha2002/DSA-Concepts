#include<iostream>
#include<vector>

using namespace std;

int BinarySearch(int arr[], int low, int high, int target){
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

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int target = 6;
    int getIndex = BinarySearch(arr,0,sizeof(arr)/sizeof(arr[0]),target);
    if(getIndex>-1){
        cout<<"Element found at = "<<getIndex<<"th index in given array \n";
    }else{
        cout<<"Element not found \n";
    }
    return 0;
}