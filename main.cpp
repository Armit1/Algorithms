#include<iostream>

using namespace std;


int partition(int arr[],int left,int right){ //Put code on github!
    int i = left-1;
    int pivot = right;
    
    for(int j = left; j < right; j++){
        if(arr[j] <= arr[pivot]){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[pivot];
    arr[pivot]= temp;
    return i+1;
}

void quicksort(int arr[],int left,int right){
    if(left < right){
        int pivotLocation = partition(arr,left,right);
        
        quicksort(arr,left,pivotLocation-1);
        quicksort(arr,pivotLocation+1,right);
    }
}

int main(){
    int arr[] = {3,2,7,8,1};
    quicksort(arr,0,(sizeof(arr)/sizeof(*arr)-1));
    for(int i : arr){
        cout<<i;
    }
    return 0;
}