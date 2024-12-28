#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> build_suffix_array(const string& s) {
    int n = s.size();
    vector<int> suffix_array(n), rank(n), temp_rank(n);
    for (int i = 0; i < n; ++i) {
        suffix_array[i] = i;
        rank[i] = s[i];
    }

    for (int k = 1; k < n; k *= 2) {
        auto compare = [&rank, &n, &k](int a, int b) {
            if (rank[a] != rank[b]) return rank[a] < rank[b];
            int rank_a_k = (a + k < n) ? rank[a + k] : -1;
            int rank_b_k = (b + k < n) ? rank[b + k] : -1;
            return rank_a_k < rank_b_k;
        };
        sort(suffix_array.begin(), suffix_array.end(), compare);

        temp_rank[suffix_array[0]] = 0;
        for (int i = 1; i < n; ++i) {
            temp_rank[suffix_array[i]] = temp_rank[suffix_array[i - 1]] +
                                         (compare(suffix_array[i - 1], suffix_array[i]) ? 1 : 0);
        }
        rank = temp_rank;
    }
    return suffix_array;
}

vector<int> build_lcp_array(const string& s, const vector<int>& suffix_array) {
    int n = s.size();
    vector<int> rank(n), lcp(n - 1);
    for (int i = 0; i < n; ++i) {
        rank[suffix_array[i]] = i;
    }

    int h = 0;
    for (int i = 0; i < n; ++i) {
        if (rank[i] > 0) {
            int j = suffix_array[rank[i] - 1];
            while (i + h < n && j + h < n && s[i + h] == s[j + h]) {
                ++h;
            }
            lcp[rank[i] - 1] = h;
            if (h > 0) --h;
        }
    }
    return lcp;
}

int count_distinct_substrings(const string& s) {
    int n = s.size();
    vector<int> suffix_array = build_suffix_array(s);
    vector<int> lcp_array = build_lcp_array(s, suffix_array);

    int total_substrings = 0;
    for (int i = 0; i < n; ++i) {
        int num_substrings_starting_here = n - suffix_array[i];
        if (i > 0) {
            num_substrings_starting_here -= lcp_array[i - 1];
        }
        total_substrings += num_substrings_starting_here;
    }
    return total_substrings;
}

int main() {
    string s;
    cin >> s;
    cout << count_distinct_substrings(s) << endl;
    return 0;
}