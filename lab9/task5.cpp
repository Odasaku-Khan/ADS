#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> prefix(string p){
    int m = p.size();
    vector<int> pref(m);
    int j = 0; 
    int i = 1;
    while(i < m){
        while(j > 0 && p[i] != p[j]){
            j = pref[j - 1]; 
        }
        if(p[i] == p[j]){
            j++; 
        }
        pref[i] = j; 
        i++;
    } 
    return pref;
}
int main() {
    int t; 
    cin >> t;
    while(t--) {
        string s; 
        cin >> s; 
        int k; 
        cin >> k; 
        vector <int> pref = prefix(s); 
        int minlen = s.size() - pref.back(); 
        cout << minlen * (k - 1) + s.size() << endl; 
    }

    return 0;
}