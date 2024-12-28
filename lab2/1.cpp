#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;
int main(){
    int k=0;
    cin>>k;
    vector<int> z(k);
    queue<pair<int,int>> r;
    for (int i = 0; i < k; i++){
        cin>>z[i];
    }
    int c;
    cin>>c;
    for (int i = 0; i < k; i++){
        int q=abs(z[i]-c);
        r.push(make_pair(q,i));
    }
    pair<int,int> near = r.front();
    r.pop();
    while (!r.empty()){
        pair<int,int> x=r.front();
        r.pop();
        if (x.first<near.first){
            near=x;
        }
    }
    cout<<near.second<<endl;
    return 0;
}