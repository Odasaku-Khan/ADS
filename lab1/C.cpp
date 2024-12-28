#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
string equality(const string &s){
    stack<char> qwer;
    for (char c : s){
        if (c=='#'){
            if (!qwer.empty()){
                qwer.pop();
            }
        }else{
        qwer.push(c);
        }
    }
    string m;
    while (!qwer.empty()){
        m=qwer.top()+m;
        qwer.pop();
    }
    return m;
}
bool checking(const string &s1, const string &s2){
    return equality(s1)==equality(s2);
    
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    if (checking(s1,s2)){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}