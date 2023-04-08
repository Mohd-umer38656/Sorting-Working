#include<iostream>
using namespace std;
void merge(int *arr,int si,int mid,int ei){
    int first = mid - si +1;
    int second = ei - mid;
    int *arr1 = new int[first];
    int *arr2 = new int[second];
    int mainIndex = si;
    
    for (int i = 0; i < first; i++)
    {
        *arr1[i] = arr[mainIndex++];
    }
    mainIndex = mid+1;
    for(int i = 0;i <second;i++){
        *arr2[i] = arr[mainIndex++];
    }

    int left = 0;
    int right = 0;
    mainIndex = si;
    while(left < first && right < second)
    {
        if(*arr1[left] < *arr2[right])
        {
           arr[mainIndex++] = *arr1[left++];
        }
        else{
            arr[mainIndex++] = *arr2[right++];
        }
    }
    while(left < first)
    {
        arr[mainIndex++] = *arr1[left++];
    
    }
    while(right <  second)
    {
        arr[mainIndex++] = *arr2[right++];
    } 
}
void printing(int *arr,int size)
{
    for(int i = 0;i < size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void mergeSort(int *arr,int si,int ei)
{
    //base case
    if(si >= ei){
        return;
    }
    int mid = si + (ei - si) /2;
    mergeSort(arr,si,mid);
    mergeSort(arr,mid +1,ei);
    //calling the merge function
    merge(arr,si,mid,ei);
}
int main()
{
    int arr[100];
    int size;
    cout<<"Enter the size of the Array  : ";
    cin>>size;
    cout<<"Enter the Elements : "<<endl;
    for(int i = 0;i < size;i++){
        cin>>arr[i];
    }
    cout<<endl;
    int si = 0;
    int ei = size -1;
    mergeSort(arr,si,ei);
    cout<<"This is Sorted Array : "<<endl;
    printing(arr,size);
}