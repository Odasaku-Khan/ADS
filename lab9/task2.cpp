#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Rabin-Karp Hash Function to compute the hash of a string
int hash_roly_poly(const string &s, int p) {
    int hash = 0;
    int pow = 1;
    for (int i = s.length() - 1; i >= 0; i--) {
        hash = (hash + (s.at(i) * pow) % p) % p;
        pow = (pow * 128) % p;
    }
    return hash;
}

// Rabin-Karp Algorithm to find all occurrences of the pattern in the text
vector<int> rabin_karp(const string &text, const string &pat, int p) {
    int pat_len = pat.length();
    int text_len = text.length();
    int hash = 0;
    int pow = 1;
    int last_pow = 0;
    int searched_hash = hash_roly_poly(pat, p);
    vector<int> v;

    // Compute hash of the first window in the text
    string s = text.substr(0, pat_len);
    for (int i = s.length() - 1; i >= 0; i--) {
        last_pow = pow;  // Save the previous power for later
        hash = (hash + (s.at(i) * pow) % p) % p;
        pow = (pow * 128) % p;
    }

    // Check if the first window matches the pattern
    if (hash == searched_hash && pat == s) {
        v.push_back(0);
    }

    // Sliding window over the text
    for (int i = 1; i <= text_len - pat_len; i++) {
        // Remove the old character and add the new character to the hash
        hash = ((((hash - (text.at(i - 1) * last_pow) % p) + p) % p) * 128 + text.at(i + pat_len - 1)) % p;

        // Recompute the modulus to ensure it's positive
        hash = (hash + p) % p;

        // If hashes match, check the actual substring
        if (hash == searched_hash) {
            if (pat == text.substr(i, pat_len)) {
                v.push_back(i);
            }
        }
    }

    return v;
}

int main() {
    int p = 5003;  // A prime number for modulus

    string pat;
    int k;
    string text;

    // Read the input
    cin >> pat >> k;
    cin.ignore(); // To ignore the newline after the integer input
    getline(cin, text);  // Read the entire line of the text

    // Perform Rabin-Karp to find all occurrences of the password in the text
    vector<int> v = rabin_karp(text, pat, p);

    // If the password occurs at least 'k' times, print YES, otherwise NO
    if (v.size() >= k) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
