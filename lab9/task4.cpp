#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function (string s) {
 int n = (int) s.length();
 vector<int> pi (n);
 for (int i=1; i<n; ++i) {
  int j = pi[i-1];
  while (j > 0 && s[i] != s[j])
   j = pi[j-1];
  if (s[i] == s[j])  ++j;
  pi[i] = j;
 }
 return pi;
}

vector<int> kmp(string s, string t) {
    s = t + '#' + s;
    vector<int> res;
    vector<int> pi = prefix_function(s);
    for (int i = 0; i < s.size(); i++) {
        if (pi[i] == t.size()) {
            res.push_back(i - 2 * t.size());
        }
    }
    return res;
}

int main(){
    string s;
    string d;
    vector<string> inp;
    vector<string> out;
    int g;
    int n = 1;
    cin >> s >> g;
    for(int i = 0; i < g; i++){
        cin >> d;
        d[0] = tolower(d[0]);
        vector <int> res = prefix_function(d + "#" + s);
        if(res[res.size() - 1] != 0){
            d[0] = toupper(d[0]);
            if (res[res.size() - 1] > n){
                n = res[res.size() - 1];
                inp.clear();
                inp.push_back(d);
            }
            else if(res[res.size() - 1] == n){
                inp.push_back(d);
            }
            
        }
    }

    cout << inp.size() << "\n";
    
    for(int i = 0; i < inp.size(); i++){
        cout << inp[i] << "\n";
    }
 

}