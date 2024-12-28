#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define F first
#define S second
#define endl "\n"
#define MAX 111
using namespace std;


int main(){

    vector<pair<double, pair<string, string>>> students;
    int t; cin >> t;
    while(t--){
        string first, second;
      cin >> first >> second;
      

      int subj;
      cin >> subj;

      double crsm = 0, sm = 0;
      for(int i = 0; i < subj; i++){
        string grade; double cr;
        cin >> grade >> cr;
        if(grade.size() == 1){
          if(grade == "A"){sm += cr * 3.75;}
          if(grade == "B"){sm += cr * 3;}
          if(grade == "C"){sm += cr * 2;}
          if(grade == "D"){sm += cr * 1;}
          if(grade == "F"){sm += cr * 0;}
        }
        else{
          if(grade[0] == 'A'){sm += cr * 4;}
          if(grade[0] == 'B'){sm += cr * 3.5;}
          if(grade[0] == 'C'){sm += cr * 2.5;}
          if(grade[0] == 'D'){sm += cr * 1.5;}
        }
        crsm += cr;
      }

      double gpa = sm / crsm;
      students.pb({gpa, {first, second}});
    }

    sort(students.begin(), students.end());
    for(auto i: students){
      cout << i.S.F << ' ' << i.S.S << ' ' << fixed << setprecision(3) << i.F << endl;
    }
    