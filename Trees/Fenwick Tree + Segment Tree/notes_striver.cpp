//Fenwick Tree + Segment Tree

- If you see queries, use seg tree


---------------------------------------------------------------------------------------------------------
Striver Fenwick Tree + Segment Tree Playlist: https://www.youtube.com/playlist?list=PLgUwDviBIf0rf5CQf_HFt35_cF04d8dHN
Resource: 
---------------------------------------------------------------------------------------------------------

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//##########-------Fenwick Tree + Segment Tree--------###################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------1. Fenwick Tree Tutorial--------########
//Tutorial: https://youtu.be/9uaXG62Y8Uw?list=PLgUwDviBIf0rf5CQf_HFt35_cF04d8dHN
//Tutorial - Tushar Roy: https://www.youtube.com/watch?v=CWDQJGaN1gY&t=750s
//Tutorial: https://codeforces.com/blog/entry/61364
//Tutorial: https://www.topcoder.com/thrive/articles/Binary%20Indexed%20Trees
//Tutorial: https://www.shafaetsplanet.com/?p=1961
//Problem: 


------------------------Theory----------------------------------
//

update sum, find sum er jnno fenwick tree use kri
Fenwick tree update ans find operation in logn 


#include <iostream>
#include <vector>
using namespace std;

class FenwickTree{
private:
    // Get parent of a node
    int get_parent(int bit){
        return bit - (bit & -bit);
    }
    
    // Get next node in the tree
    int get_next(int bit){
        return bit + (bit & -bit);
    }

public:
    // Get the sum of elements from index 0 to index 'index'
    int getSum(const vector<int>& BITree, int index){
        int sum = 0;
        index = index + 1; // BITree indices are 1-based

        while (index > 0){
            sum += BITree[index];
            index = get_parent(index);
        }
        return sum;
    }

    // Update the BITree at index by adding 'val'
    void updateBIT(vector<int>& BITree, int n, int index, int val){
        index = index + 1; // BITree indices are 1-based

        while (index <= n){
            BITree[index] += val;
            index = get_next(index);
        }
    }

    // Construct the Fenwick Tree using the input array 'arr'
    vector<int> constructBITree(const vector<int>& arr, int n) {
        vector<int> BITree(n + 1, 0); // Initialize BITree with 0s

        // Update BITree for all elements in the input array
        for (int i = 0; i < n; i++)
            updateBIT(BITree, n, i, arr[i]);

        return BITree;
    }
};

int main() {
    // Input array
    vector<int> arr = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = arr.size();

    // Initialize Fenwick Tree
    FenwickTree ft;
    vector<int> BITree = ft.constructBITree(arr, n);

    // Get the sum of elements from index 0 to 5
    cout << "Sum of elements in arr[0..5] is " << ft.getSum(BITree, 5) << endl;

    // Update arr[3] (index 3) by adding 6
    arr[3] += 6;
    ft.updateBIT(BITree, n, 3, 6);

    // Get the sum of elements from index 0 to 5 after the update
    cout << "Sum of elements in arr[0..5] after update is " << ft.getSum(BITree, 5) << endl;

    return 0;
}


//#######################################################################
//#######-------2. Binary Lifting on Fenwick Tree Tutorial | Update and Query operations--------########
//Tutorial: 
//Problem: 

//#######################################################################
//#######-------3. Segment Tree: Build and Query--------########
//Tutorial: 
//Problem: 

2*ind + 1
2*ind + 2

//#######################################################################
//#######-------4. Lazy Propagation in Segment Tree | Point and Range Updates--------########
//Tutorial: 
//Problem: 

//#######################################################################
//#######-------5. Codeforces Education Round #87 | Multiset | Binary Search + Fenwick Tree Approach--------########
//Tutorial: 
//Problem: 

//#######################################################################
//#######-------6. Masterclass: Range Query DS | Segment Trees--------########
//Tutorial: https://www.youtube.com/watch?v=NEG-SoyigGE
//Problem: 

Build Function: O(N)[visiting every node]
just build using recursion
1. Low == high hole, seg[ind] = a[low]
2. go to left and go to right
3. after that update, seg[ind] = min(seg[left], seg[right]); 

Query: O(logN)
3 cases for finding min in a range 
1. If partial overlap go to left and right 
2. If no overlap return intmax[cause it cannot contribute to answer]
3. If full overlap take seg[ind]

Update:
1. Low == high hole, seg[ind] = val
2. if(i<=mid) go to left 
   else go to right
3. after that update, seg[ind] = min(seg[left], seg[right]); 



class SGTree {
	vector<int> seg;
public:
	SGTree(int n) {
		seg.resize(4 * n + 1);
	}

	void build(int ind, int low, int high, int arr[]) {
		if (low == high) {
			seg[ind] = arr[low];
			return;
		}

		int mid = (low + high) / 2;
		build(2 * ind + 1, low, mid, arr);
		build(2 * ind + 2, mid + 1, high, arr);
		seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
	}

	int query(int ind, int low, int high, int l, int r) {
		// no overlap
		// l r low high or low high l r
		if (r < low || high < l) return INT_MAX;

		// complete overlap
		// [l low high r]
		if (low >= l && high <= r) return seg[ind];

		int mid = (low + high) >> 1;
		int left = query(2 * ind + 1, low, mid, l, r);
		int right = query(2 * ind + 2, mid + 1, high, l, r);
		return min(left, right);
	}
	void update(int ind, int low, int high, int i, int val) {
		if (low == high) {
			seg[ind] = val;
			return;
		}

		int mid = (low + high) >> 1;
		if (i <= mid) update(2 * ind + 1, low, mid, i, val);
		else update(2 * ind + 2, mid + 1, high, i, val);
		seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
	}
};


https://github.com/striver79/Competitive_Codes-/blob/master/STsum_update.cpp
https://www.topcoder.com/thrive/articles/Binary%20Indexed%20Trees

left at 1:59:03 [see again]
range minimum done
segment tree problems: https://codeforces.com/blog/entry/22616
count inversion using segment tree: https://ideone.com/mLwRjf

//#######################################################################
//#######-------7. Marathon Class on Range Query DS - 2 | Segment Trees | Lazy Propagation--------########
//Tutorial: https://www.youtube.com/watch?v=rXnXRU8yMF0
//Problem: 



//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################-------Finished--------#########################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
-------------------------------------------------------------------------
-------------------------------------------------------------------------