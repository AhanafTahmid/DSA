#include <bits/stdc++.h>
using namespace std;


//Big Mod ADDITION
void biginteger(){
    string s1 = "111111999199";
    string s2 = "123993334";
  
   
    int carry = 0;
    string answer ;
    int x = 0;

    string s3;
    int max_string = s1.size();
    s3 = s2;
    if(s1.size()<=s2.size()){
        max_string = s2.size();
        s3 = s1;
    }
    reverse(s3.begin(),s3.end());

    //0 diye fillup kora
    for(int i=s3.size();i<max_string;i++){
        s3+='0';
    }
    reverse(s3.begin(),s3.end());
    s2=s3;


    //carry-r jnno ulta loop chalaite hocche
    for(int i=s1.size()-1;i>=0;i--){
        x = s1[i]-'0'+s2[i]-'0'+carry;
        answer+=x%10+'0';
        carry = x/10;
    }
    
    reverse(answer.begin(),answer.end());
    cout<<answer<<endl;
    
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)biginteger(); 
    return 0;
}


//################################################################

//Another WAY Big Mod ADDITION, JAMIL SIR METHOD



//single digit jog kore kore jawa
#include <bits/stdc++.h>
using namespace std;

void biginteger(){
    string s1="999199";
    string s2 = "123993334";//999199+123993334=124992533

    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());

    int carry = 0;
    string answer ;
    int x = 0;
		

    if(s1.size()<=s2.size()){
        swap(s1,s2);
    }

    //assuming s2 choto
    for(int i=0;i<s2.size();i++){
        x = s1[i]-'0'+s2[i]-'0'+carry;
        answer+=x%10+'0';//getting the last digit, string e rakhte hobe, karon ekta somoy exceed kore felbe
        carry = x/10;//getting the carry, cause 9+9=18 highest can go
        //cout<<answer<<" "<<carry<<endl;
    }
    x = 0;
    //ekhane ar s2 nai
    for(int i=s2.size();i<s1.size();i++){
        x = s1[i]-'0'+carry;
        answer+=x%10+'0';
        carry = x/10;
        //cout<<answer<<" "<<carry<<endl;
    }
    reverse(answer.begin(),answer.end());
    cout<<answer<<endl;
    
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)biginteger(); 
    return 0;
}




///Multiplication
// Include header file
#include <bits/stdc++.h>
using namespace std;

int main()
{
	string num1 = "1235421415454545454545454544";
	string tempnum1 = num1;
	string num2 = "1714546546546545454544548544544545";
	string tempnum2 = num2;
	// Check condition if one string is negative
	if (num1[0] == '-' && num2[0] != '-') {
		num1 = num1.substr(1);
	}
	else if (num1[0] != '-' && num2[0] == '-') {
		num2 = num2.substr(1);
	}
	else if (num1[0] == '-' && num2[0] == '-') {
		num1 = num1.substr(1);
		num2 = num2.substr(1);
	}
	string s1 = num1;
	string s2 = num2;
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	vector<int> m(s1.length() + s2.length());
	// Go from right to left in num1
	for (int i = 0; i < s1.length(); i++) {
		// Go from right to left in num2
		for (int j = 0; j < s2.length(); j++) {
			m[i + j]
				= m[i + j] + (s1[i] - '0') * (s2[j] - '0');
		}
	}
	string product = "";
	// Multiply with current digit of first number
	// and add result to previously stored product
	// at current position.
	for (int i = 0; i < m.size(); i++) {
		int digit = m[i] % 10;
		int carry = m[i] / 10;
		if (i + 1 < m.size()) {
			m[i + 1] = m[i + 1] + carry;
		}
		product = to_string(digit) + product;
	}
	// ignore '0's from the right
	while (product.length() > 1 && product[0] == '0') {
		product = product.substr(1);
	}
	// Check condition if one string is negative
	if (tempnum1[0] == '-' && tempnum2[0] != '-') {
		product = "-" + product;
	}
	else if (tempnum1[0] != '-' && tempnum2[0] == '-') {
		product = "-" + product;
	}

	cout << "Product of the two numbers is :"
		<< "\n"
		<< product << endl;
}

// This code is contributed by Aarti_Rathi
