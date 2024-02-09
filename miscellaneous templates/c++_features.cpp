
//#######-------Strutured Bindings--------########

#include <iostream>
#include <tuple>

// Define a function that returns a tuple
std::tuple<int, double, std::string> getData() {
    return std::make_tuple(42, 3.14, "Hello");
}

int main() {
    // Using structured binding to unpack the tuple elements into individual variables
    auto [num, value, message] = getData();

    // Now you can use num, value, and message as separate variables
    std::cout << "Number: " << num << std::endl;
    std::cout << "Value: " << value << std::endl;
    std::cout << "Message: " << message << std::endl;

    return 0;
}



////////
#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 

	int arr[3] = { 1, 2, 3 }; 
	
	// Here, E is an array type, hence the 
	// names are bound to the array elements. 
	auto[x, y, z] = arr; 
	
	cout << x << " " << y << " " << z << endl; 

	return 0; 
} 


#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 

	int arr[] = { 1, 2, 3 , 7}; 

	auto[x, y, z, a] = arr; 
    
	cout << x << " " << y << " " << z << " "<< a << endl; 

	return 0; 
} 






//#######-------C++ Features--------########


//https://www.geeksforgeeks.org/features-of-c17-with-examples/
 //Change everything with $$$ 
    // Variable declaration in if and switch

    vector<string> str = {"abc", "def", "ghi", "abc", "jkl"};

    // Find and replace "abc" with "$$$"
    auto it = find(begin(str), end(str), "abc");
    while (it != end(str)) {
        *it = "$$$";
        it = find(begin(str), end(str), "abc");
    }

    // Print the modified vector
    for (const auto& s : str) {
        cout << s << " ";
    }
    cout << endl;




//#######-------size_t--------########
//size_t -> Unsigned integer data type


#include <bits/stdc++.h>
using namespace std;


int main()
{
	int array[5] = { 1, 2, 3, 4, 5 };
	size_t size = sizeof(array);

	printf("The size of the array is: %lu\n", size);
    size_t t = 1000;
    cout<< t <<endl;

	return 0;
}



//#######-------enum--------########

// C++ Program to Demonstrate the Functioning of Enumerators 
//user defined data type
// with an Example of Year 
#include <bits/stdc++.h> 
using namespace std; 

// Defining enum Year 
enum year { 
	Jan, 
	Feb, 
	Mar, 
	Apr, 
	May, 
	Jun, 
	Jul, 
	Aug, 
	Sep, 
	Oct, 
	Nov, 
	Dec 
}; 

// Driver Code 
int main() 
{ 
	int i; 

	// Traversing the year enum 
	for (i = Jan; i <= Dec; i++) 
		cout << i << " "; 

	return 0; 
}
