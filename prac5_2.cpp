#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

string lrs(string s) {
    int n = s.length();
    vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i-1] == s[j-1] && i != j) {
                mat[i][j] = mat[i-1][j-1] + 1;
            } else {
                mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
            }
        }
    }
    string result = "";
    int i = n, j = n;
    while (i > 0 && j > 0) {
        if (s[i-1] == s[j-1] && i != j && mat[i][j] == mat[i-1][j-1] + 1) {
            result = s[i-1] + result;
            i--;
            j--;
        } else if (mat[i-1][j] > mat[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    return result;
}

int main() {
    string s;
    cin >> s;
    cout << lrs(s) << endl;
    return 0;
}