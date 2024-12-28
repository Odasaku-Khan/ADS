#include <bits/stdc++.h>
using namespace std;
vector <int> computeLPS(string str){
    vector<int> LPS(str.size(),0);
    int len=0,i=1;
    while (i<str.size()){
        if(str[i]==str[len]){
            len++;
            LPS[i]=len;
            i++;
        }else{
            if (len!=0){
                len=LPS[len-1];
            }else{
                LPS[i]=0;
                i++;
            }
            
        }
    }
    return LPS;
}
int repetition(string sub, string str){
    int m=sub.size();
    int n=str.size();
    vector<int> LPS=computeLPS(str);
    int i=0,j=0;
    int rep=1;
    while (i<m*rep){
        if (sub[i%m]==str[j]){
            i++,j++;
            if (j==n){
                return rep;
            }
        }else{
            if(j!=0){
                j=LPS[j-1];
            }else{
                i++;
            }
        }if (i>=m*rep){
            rep++;
        }if (rep>(n/m)+2){
            return -1;
        }
    }
    return -1;
    
}
int main(){
    string sub, str;
    cin>>sub>>str;
    int result=repetition(sub,str);
    cout<<result;
    return 0;
}