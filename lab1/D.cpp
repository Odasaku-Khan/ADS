#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
bool balanced(const string &s){
    stack<char> luffy;
    for(char c : s){
        if (!luffy.empty() && luffy.top()==c){
            luffy.pop();
        }else{
            luffy.push(c);
        }
    }
    return luffy.empty();
}
int main(){
    string s;
    cin>>s;
    if (balanced(s)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}