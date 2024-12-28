#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define ll long long

ll MOD = 1e9 + 7;
ll X = 31;
map <int, int> mp;
int ans = 0;

ll getHash(string & s) {
    ll hash = 0;
    ll curX = 1;
    for (int i = 0; i < s.size(); i++) {
        ll curHash = (s[i] - 'a' + 1) * curX % MOD;
        hash = (hash + curHash) % MOD;
        curX = (curX * X) % MOD;
    }
    return hash;
}

vector<ll> getPrefixHashes(string & s) {
    vector<ll> hashes(s.size());
    ll curX = 1;
    for (int i = 0; i < s.size(); i++) {
        hashes[i] = (s[i] - 'a' + 1) * curX % MOD;
        if (i != 0) {
            hashes[i] = (hashes[i] + hashes[i - 1]) % MOD;
        }
        curX = (curX * X) % MOD;
    }
    return hashes;
}

void rabinKarp(string & s, string & t) {
    if (t.size() > s.size()) return;
    ll smallHash = getHash(t);
    vector<ll> hashes = getPrefixHashes(s);
    for (int i = 0; i < s.size() - t.size() + 1; i++) {
        ll hashDif = hashes[i + t.size() - 1];
        if (i != 0) hashDif -= hashes[i - 1];
        if (hashDif < 0) hashDif += MOD;
        if (i != 0) smallHash = (smallHash * X) % MOD;
        if (smallHash == hashDif){
            if (mp.find(i) != mp.end()) {
//                cout << i << endl;
                ans++;
            }
            mp[i] = 1;
        }
    }

}

int main() {
    string s, t, str;
    cin >> s >> t >> str;
    rabinKarp(s, str);
    rabinKarp(t, str);
    cout << ans << endl;
}