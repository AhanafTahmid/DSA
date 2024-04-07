//all subarray k^3
const int n = 5;
int a[n] = {1,4,5,6,7};
for(int i=0;i<n;i++){
for(int j=i;j<n;j++){
    for(int k=i;k<=j;k++){
        cout<<a[k]<<' ';
    }
    cout<<endl;}
}


//all subsequence k^3
//https://www.geeksforgeeks.org/print-subsequences-string/
#include <bits/stdc++.h>
using namespace std;

unordered_set<string> st;
void subsequence(string str)
{

	for (int i = 0; i < str.length(); i++) {
		for (int j = str.length(); j > i; j--) {
			string sub_str = str.substr(i, j);
			st.insert(sub_str);
			for (int k = 1; k < sub_str.length(); k++) {
				string sb = sub_str;
				sb.erase(sb.begin() + k);
				subsequence(sb);
			}
		}
	}
}

int main()
{
	string s = "aabc";
	subsequence(s);
	for (auto i : st)
		cout << i << " ";
	cout << endl;

	return 0;
}
