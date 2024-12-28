#include <bits/stdc++.h> 
using namespace std; 
int partition(vector<int>& arr,int low,int high){ 
    int random=low+rand()%(high-low+1); 
    swap(arr[random],arr[high]); 
    int pivot=arr[high]; 
  int  i=low-1; 
    for(int j=low;j<high;j++){ 
        if(arr[j]<pivot){ 
            i++; 
            swap(arr[i],arr[j]); 
        } 
    } 
    swap(arr[i+1],arr[high]); 
    return i+1; 
} 
void quicksort(vector<int>&sandar,int low,int high){ 
    if(low<high){ 
        int pi=partition(sandar,low,high); 
        quicksort(sandar,low,pi-1); 
        quicksort(sandar,pi+1,high); 
    } 
 
} 
 
int main(){ 
    int n,m; 
    cin>>n>>m; 
    vector<int>sandar(n); 
    vector<int>sandar2(m); 
    for(int i=0;i<n;i++){ 
        cin>>sandar[i]; 
    } 
    for(int i=0;i<m;i++){ 
        cin>>sandar2[i]; 
    } 
    quicksort(sandar,0,sandar.size()-1); 
    quicksort(sandar2,0,sandar2.size()-1); 
    int i=0,j=0; 
    vector<long long>common; 
    while(i<n&&j<m){ 
        if(sandar[i]==sandar2[j]){ 
            common.push_back(sandar[i]); 
            i++; 
            j++; 
        } 
        else if(sandar[i]<sandar2[j]){ 
            i++; 
        } 
        else{ 
        j++; 
    } 
    } 
    for(int element:common){ 
        cout<<element<<" "; 
    } 
 
 
}