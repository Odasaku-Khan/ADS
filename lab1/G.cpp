#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool prime(int b) {
    if (b <= 1) return false; 
    if (b <= 3) return true;  
    if (b % 2 == 0 || b % 3 == 0) return false; 
    for (int i = 5; i * i <= b; i += 6) {
        if ((b % i == 0 || b % (i + 2) == 0) || (b%(i+3)==0)) return false;
    }
    return true;
}
int main(){
    int x;
    cin>>x;
    int q=2;
    int c=0;
    queue<int> xr;
    while(xr.size()<x){
        if (prime(q)){
            c++;
            if (prime(c)){
                xr.push(q);
            }
            
        }
        q++;
    }
    cout<<xr.back()<<endl;
    return 0;
}