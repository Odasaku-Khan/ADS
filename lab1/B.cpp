#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
void searching(int n,vector<int> age){
vector<int> finito(n,-1);
stack<int> z;
for (int i = 0; i < n; i++){
    while (!z.empty() && age[z.top()]>age[i]){
        z.pop();
    }
    if (!z.empty()){
        finito[i]=age[z.top()];
    }
    z.push(i);
}
for (int i = 0; i < n; i++){
    cout<<finito[i]<<" ";
}
cout<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<int> age(n);
    for (int i = 0; i <n; i++){
        cin>>age[i];
    }
    searching(n,age);
    return 0;
}