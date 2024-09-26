#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

class FenwickTree{
private:
    int get_parent(int bit){
        return bit - (bit & -bit);
    }
    
    int get_next(int bit){
        return bit + (bit & -bit);
    }

public:
    int getSum(const vector<int>& BITree, int index){
        int sum = 0;
        index = index + 1;

        while (index > 0){
            sum += BITree[index];
            index = get_parent(index);
        }
        return sum;
    }

    void updateBIT(vector<int>& BITree, int index, int n, int val){
        index = index + 1;

        while (index <= n){
            BITree[index] += val;
            index = get_next(index);
        }
    }

    vector<int> constructBITree(const vector<int>& arr, int n) {
        vector<int> BITree(n + 1, 0);

        for (int i = 0; i < n; i++)
            updateBIT(BITree, i, n, arr[i]);

        return BITree;
    }
};

int32_t main() {
    vector<int> arr = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = arr.size();

    FenwickTree ft;
    vector<int> BITree = ft.constructBITree(arr, n);

	for(int x: BITree) cout<< x << ' ';
	cout<<endl;

    cout << "Sum of elements in arr[0..5] is " << ft.getSum(BITree, 5) << endl;

    arr[3] += 6;
    ft.updateBIT(BITree, 3, n, 6);
	for(int x: BITree) cout<< x << ' ';
	cout<<endl;


    cout << "Sum of elements in arr[0..5] after update is " << ft.getSum(BITree, 5) << endl;

    return 0;
}