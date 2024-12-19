
pbds benifit: 
helps on getting random access within a sorted list and position of element in a set[those of which a set does not provide]

#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

//template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
//oset<data_type> s;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key



// cout << "0th element: " << *A.find_by_order(0) << endl;
// cout << "No. of elems smaller than 6: " << A.order_of_key(6) << endl;



//################################################################
//################################################################
//################################################################
//################################################################

//This one to use

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
//oset<array<int, 2>> is;

int main()
{
	ordered_set p;
	p.insert(5);
	p.insert(2);
	p.insert(6);
	p.insert(4);

    //2 4 5 6

	cout<< *p.find_by_order(1) <<endl;//index 
    cout<< p.order_of_key(3) <<endl; //total count of element that are smaller than the current element 3
    cout<< *p.lower_bound(3) <<endl; //lowerbound
    cout<< *p.upper_bound(3) <<endl; //lowerbound

	return 0;
}