#include <iostream>
using namespace std;

string LCS(string s1, string s2){
    int n = s1.size();
    int m = s2.size();
    int maxn = 0;

    int a[n+1][m+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 or j == 0){
                a[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1]){
                a[i][j] = a[i-1][j-1] + 1;
                if(maxn < a[i][j]){
                    maxn = a[i][j];
                }
            }
            else{
                a[i][j] = 0;
            }
        }
    }
    string ans = "";
    int i, j;
    for(i = 0; i <= n; i++){
        for(j = 0; j <= m; j++){
            if(a[i][j] == maxn){
                int t = j;
                for(int x = 0; x < maxn; x++){
                    ans = s2[t-1] + ans;
                    t--;
                }
                return ans;
            }
        }
    }
    return ans;
}

int main(){
    int k;
    cin >> k;
    string str1, str2;
    cin >> str1;
    for(int i = 1; i < k; i++){
        cin >> str2;
        str1 = LCS(str1, str2);
    }
    cout << str1;
}