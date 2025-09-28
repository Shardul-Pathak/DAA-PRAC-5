#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

vector<vector<pair<int,char>>> getMatrix(string s1,string s2,vector<vector<pair<int,char>>> &mat) {
    int len1=s1.size(),len2=s2.size();
    for(int i=0;i<len1;i++) {
        for(int j=0;j<len2;j++) {
            if(s1[i]==s2[j]) {
                mat[i+1][j+1].first=mat[i][j].first+1;
                mat[i+1][j+1].second='D';
            }
            else {
                if(mat[i][j+1].first>=mat[i+1][j].first) {
                    mat[i+1][j+1].first=mat[i][j+1].first;
                    mat[i+1][j+1].second='U';
                }
                else {
                    mat[i+1][j+1].first=mat[i+1][j].first;
                    mat[i+1][j+1].second='S';
                }
            }
        }
    }
    return mat;
}

string lcs(vector<vector<pair<int,char>>> &mat,int i,int j,string s) {
    string subsequence="";
    while(mat[i][j].second!='H') {
        if(mat[i][j].second=='D') {
            i--;
            j--;
            subsequence+=s[i];
        }
        else if(mat[i][j].second=='U') {
            i--;
        }
        else {
            j--;
        }
    }
    return subsequence;
}

void printMatrix(vector<vector<pair<int,char>>> &mat,int n,int m) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<mat[i][j].first<<"/"<<mat[i][j].second<<" ";
        }
        cout<<endl;
    }
}

int main() {
	string s1,s2;
	cin>>s1>>s2;
	int n=s1.size()+1,m=s2.size()+1;
	pair<int,char> defaultValue = {0,'H'};
	vector<vector<pair<int,char>>> mat(n,vector<pair<int,char>>(m, defaultValue));
	mat=getMatrix(s1,s2,mat);
	printMatrix(mat,n,m);
	cout<<"Longest Subsequence Length: "<<mat[n-1][m-1].first<<endl;
	string subsequence=lcs(mat,n-1,m-1,s1);
	reverse(subsequence.begin(),subsequence.end());
	cout<<"Subsequence: "<<subsequence<<endl;
}

