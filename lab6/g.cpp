#include<iostream>
#include <map>
#include <cmath>
using namespace std;

int heapify3(string **&s, int i, int j){
    if(s[i][1].size()<s[j][1].size()){
        for(int k=0;k<s[i][1].size();k++){
            if((int)s[i][1][k]<(int)s[j][1][k]){
                return j;
            }
            else if((int)s[i][1][k]>(int)s[j][1][k]){
                return i;
            }
        }
        return j;
    }else{
        for(int k=0;k<s[j][1].size();k++){
            if((int)s[i][1][k]<(int)s[j][1][k]){
                return j;
            }else if((int)s[i][1][k]>(int)s[j][1][k]){
                return i;
            }
        }
        return i;
    }
}
int heapify2( string **&s, int i, int j){
    if(s[i][0].size()<s[j][0].size()){
        for(int k=0;k<s[i][0].size();k++){
            if((int)s[i][0][k]<(int)s[j][0][k]){
                return j;
            }
            else if((int)s[i][0][k]>(int)s[j][0][k]){
                return i;
            }
        }
        return j;
    }else if(s[i][0].size()>s[j][0].size()){
        for(int k=0;k<s[j][0].size();k++){
            if((int)s[i][0][k]<(int)s[j][0][k]){
                return j;
            }else if((int)s[i][0][k]>(int)s[j][0][k]){
                return i;
            }
        }
        return i;
    }else{
        for(int k=0;k<s[j][0].size();k++){
            if((int)s[i][0][k]<(int)s[j][0][k]){
                return j;
            }else if((int)s[i][0][k]>(int)s[j][0][k]){
                return i;
            }
        }    
        return heapify3(s,i,j);

    }
}
void heapify( string **&s,int i,int n){
    int largest=i;
    int l=i*2+1;
    int r=2*i+2;
    if(l<n){
        largest=heapify2(s,largest,l);
    }
    if(r<n){
        largest=heapify2(s,largest,r);
    }
    if(i!=largest){
        swap(s[i][0],s[largest][0]);
        swap(s[i][1],s[largest][1]);
        heapify(s,largest,n);
    }
}


void qsort(string **&s,int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(s,i,n);
    }
    for(int i=n-1;i>=0;i--){
        swap(s[i][1],s[0][1]);
        swap(s[i][0],s[0][0]);
        heapify(s,0,i);
    }
}
int main(){
    int n;
    cin>>n;
    int size=0;
    int cnt=0;
    string f;
    string g;
    map<string,string> mp;
    for(int i=0;i<n;i++){
       cin>>f>>g;
       bool ok=true;
       for(auto it : mp){
        if(mp[it.first]==f){
            mp[it.first]=g;
            ok=false;
            break;
        }
       }
       if(ok){ 
        mp[f]=g;
       }
    }
    cout<<mp.size()<<endl;
    for(auto it:mp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    
}  