#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int hash_roly_poly(string s, int p){
    int hash = 0;
    int pow = 1;
    for (int i = s.length()-1; i >= 0; i--)
    {
        hash = (hash + (s.at(i)*pow)%p)%p;
        pow = (pow*128)%p;
    }
    return hash;
}


vector<int> rabin_karp(string text, string pat, int p){
    int hash = 0;
    int pow = 1;
    int last_pow = 0;
    int searched_hash = hash_roly_poly(pat,p);
    vector<int> v; 

    string s = text.substr(0,pat.length());
    for (int i = s.length()-1; i >= 0; i--)
    {
        last_pow = pow;//in the end -- 128**5 mod 5003
        hash = (hash + (s.at(i)*pow)%p)%p;
        pow = (pow*128)%p;
    }

    if(hash == searched_hash && pat == s)
        v.push_back(0);


    for (int i = 1; i < text.length()-pat.length()+1; i++)
    {
        hash = ((((hash - (text.at(i-1)*last_pow)%p)%p)*128)%p+text.at(i+pat.length()-1))%p;

        hash = (hash+p)%p;
        cout<<text.substr(i,pat.length())<<"->"<<hash<<endl;
        if(hash == searched_hash){
            if(pat == text.substr(i,pat.length()))
                v.push_back(i);
        }
        
    } 
    return v;
}


int main()
{   
    int p = 5003;


    string text = "this is a strangely stringy string";

    string pat = "string";


    cout<<"string:"<<hash_roly_poly(pat,p)<<endl;

    for (int i = 0; i < text.length()-pat.length()+1; i++)
    {
        cout<<text.substr(i,pat.length())<<":"
        <<hash_roly_poly(text.substr(i,pat.length()),p)<<endl;
    }

    vector<int> v = rabin_karp(text,pat,p);
    
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v.at(i)<<" ";
    }
    
    
    return 0;
}