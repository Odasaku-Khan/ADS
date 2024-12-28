#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
vector<int> rotation(int n){
    queue<int> q;
    vector<int> z(n);
    for (int i = 0; i < n; i++){
        q.push(i);
    }
    for (int i = 1; i <=n; i++){
        for (int j=0; j <i%q.size(); j++){
            q.push(q.front());
            q.pop();
        }
        z[q.front()]=i;
        q.pop();
    }
    return z;
}
int main(){
    int m;
    cin>>m;
    while (m--){
        int n;
        cin>>n;
        vector<int> qwe= rotation(n);
        for (int i = 0; i < qwe.size(); i++){
            if (i>0)cout<<" ";
                cout<<qwe[i];
        }
        cout<<endl;
    }
    return 0;
}