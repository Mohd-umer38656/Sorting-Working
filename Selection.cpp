#include<iostream>
using namespace std;

void selectionSort(int arr[],int size){
    for(int i =0;i <= size-1;i++){
        int minIndex = i;
        for(int j =i +1;j <= size;j++){
            if(arr[j] < arr[minIndex])
            minIndex = j;
        }
        swap(arr[minIndex],arr[i]);
    }
}


int main()
{
    int arr[] = {4,8,3,6,1,2,5,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    //funcion call
    selectionSort(arr,size-1);
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}