//all templates is here

//#######-------Prefix sum--------########


void solve(){
    long long int n,q;
	cin>>n>>q;
	long long ar[100000],p[10000]={};//long long ar[],p[] here is must, might give WA becaue of this
	for(int i=1;i<=n;i++){
		cin>>ar[i];
		//p[0]=ar[0];
		p[i]=p[i-1]+ar[i];
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<p[y]-p[x-1]<<endl;
		
	}
}

//#######-------Suffix sum--------########

//suffixSum[i + 1] -> suffix sum
//prefixSum[i - 1] -> prefix sum
vector<int> createSuffixSum(vector<int> arr, int n)
{
    vector<int> suffixSum(n, 0);
    suffixSum[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suffixSum[i] = suffixSum[i + 1] + arr[i];
    return suffixSum;
}
 

//########################################
//########################################
//#######-------Sortings--------########
//########################################
//########################################

//#######-------Insertion Sort--------########

void insertion_sort(){
    int n= 5,k=1;
    int ar[100]={2,10,3,1,4};

    //using while loop
    for(int i=0;i<n;i++){
        int j = i;
        while(j>0 && ar[j-1]>ar[j]){//for comaparing index 4, it will go ---> ar[3]>ar[4] hole swap till ar[0]>ar[1], j>=0 avoid for j[-1]>j[0]
            swap(ar[j],ar[j-1]);
            j--;
        }
    }


    
    //using for loop
        for(int i=0;i<n;i++){
            for(int j=i;j>0;j--){
                if(ar[j-1]>ar[j]) swap(ar[j],ar[j-1]);
            }
        }


    

    //sorted array
    for(int i=0;i<n;i++){
        cout<<ar[i]<<endl;
    }


    
}

//#######-------Merge sort--------########

//Merge sort algorithm

#include <bits/stdc++.h>
using namespace std;


void merge(int ar[],int l,int m, int h){
    vector<int> temp;

    //low...mid
    //mid+1...high
    int i = l;      // Initial index of left subarray
    int j = m + 1;  // Initial index of right subarray

    // Merging the two arrays
    while (i <= m && j <= h) {
        if (ar[i] <= ar[j]) {
            temp.push_back(ar[i]);
            i++;//oi position er kaj shesh, tai ++
        } else {
            temp.push_back(ar[j]);
            j++;
        }
    }

    //if there are elements on the left still remains
    while (i <= m) {
        temp.push_back(ar[i]);
        i++;
    }

    //if there are elements on the right still remains
    while (j <= h) {
        temp.push_back(ar[j]);
        j++;
    }

    // moving all elements to an array / Copy elements from temp back to ar[]
    for (int k = l; k <= h; k++) {
        ar[k] = temp[k-l];//
    }


}


void merge_sort(int ar[], int l,int h){
    if(l>=h){
        return;
    }
    int m = (l+h)/2;
    merge_sort(ar,l,m);//left half
    merge_sort(ar,m+1,h);//right half
    
    //function to merge and sort the array
    merge(ar,l,m,h);
   
}


int main(){

    int t=1;
    //cin >> t;
    while(t--){
        int ar[100]={2,1,23,45,22,3,6};
        int n = 7;
        int l = 0;
        int h = 6;
        int mid = (l+h)/2;

        merge_sort(ar,0,n-1); //high and low
        for(int i=0;i<n;i++){
            cout<<ar[i]<<endl;
        }
        cout<<endl;
    }
    return 0;
}

//#######-------Selection Sort--------########
void solve(){
    int n = 5;
    int ar[100]={33,12,3,1,4};
    int min = ar[0];
    int minIndex = 0;
    for(int i=0;i<n-1;i++){
        min = ar[i];
        for(int j=i+1;j<n;j++){
            if(min>=ar[j]){
                min = ar[j];
                minIndex = j;
            }
        }

        //now swapping with index, swapping with min does not work
        if(ar[i]>=min){
            int t = ar[i];
            ar[i] = ar[minIndex];
            ar[minIndex] = t;
        }

        // for(int x=0;x<n;x++){
        //     cout<<ar[x]<<" ";
        // }
        // cout<<endl;
    }
    for(int x=0;x<n;x++){
        cout<<ar[x]<<" ";
    }
}


//########################################
//########################################
//#######-------Number Theory--------#####
//########################################
//########################################



//#######-------All possible subsets--------########
int main() {
    //int a=2,b=3,c=5;
    int ar[100]={2,3,5};
    int n = 3;//total element is 3
    int subsets = 1<<n;
    for(int i=1;i<subsets;i++){
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                cout<<ar[j]<<" ";
            }
            //else cout<<0;
        }
      cout<<endl;
      
    }
  
    return 0;
}
//#######-------Big Integer ALL--------########
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

const int base = 1000000000;
const int base_digits = 9;

struct bigint {
	vector<int> a;
	int sign;
 
	bigint() :
		sign(1) {
	}
 
	bigint(long long v) {
		*this = v;
	}
 
	bigint(const string &s) {
		read(s);
	}
 
	void operator=(const bigint &v) {
		sign = v.sign;
		a = v.a;
	}
 
	void operator=(long long v) {
		sign = 1;
		if (v < 0)
			sign = -1, v = -v;
		for (; v > 0; v = v / base)
			a.push_back(v % base);
	}
 
	bigint operator+(const bigint &v) const {
		if (sign == v.sign) {
			bigint res = v;
 
			for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {
				if (i == (int) res.a.size())
					res.a.push_back(0);
				res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
				carry = res.a[i] >= base;
				if (carry)
					res.a[i] -= base;
			}
			return res;
		}
		return *this - (-v);
	}
 
	bigint operator-(const bigint &v) const {
		if (sign == v.sign) {
			if (abs() >= v.abs()) {
				bigint res = *this;
				for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) {
					res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
					carry = res.a[i] < 0;
					if (carry)
						res.a[i] += base;
				}
				res.trim();
				return res;
			}
			return -(v - *this);
		}
		return *this + (-v);
	}
 
	void operator*=(int v) {
		if (v < 0)
			sign = -sign, v = -v;
		for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
			if (i == (int) a.size())
				a.push_back(0);
			long long cur = a[i] * (long long) v + carry;
			carry = (int) (cur / base);
			a[i] = (int) (cur % base);
			//asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
		}
		trim();
	}
 
	bigint operator*(int v) const {
		bigint res = *this;
		res *= v;
		return res;
	}
 
	friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
		int norm = base / (b1.a.back() + 1);
		bigint a = a1.abs() * norm;
		bigint b = b1.abs() * norm;
		bigint q, r;
		q.a.resize(a.a.size());
 
		for (int i = a.a.size() - 1; i >= 0; i--) {
			r *= base;
			r += a.a[i];
			int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
			int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
			int d = ((long long) base * s1 + s2) / b.a.back();
			r -= b * d;
			while (r < 0)
				r += b, --d;
			q.a[i] = d;
		}
 
		q.sign = a1.sign * b1.sign;
		r.sign = a1.sign;
		q.trim();
		r.trim();
		return make_pair(q, r / norm);
	}
 
	bigint operator/(const bigint &v) const {
		return divmod(*this, v).first;
	}
 
	bigint operator%(const bigint &v) const {
		return divmod(*this, v).second;
	}
 
	void operator/=(int v) {
		if (v < 0)
			sign = -sign, v = -v;
		for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) {
			long long cur = a[i] + rem * (long long) base;
			a[i] = (int) (cur / v);
			rem = (int) (cur % v);
		}
		trim();
	}
 
	bigint operator/(int v) const {
		bigint res = *this;
		res /= v;
		return res;
	}
 
	int operator%(int v) const {
		if (v < 0)
			v = -v;
		int m = 0;
		for (int i = a.size() - 1; i >= 0; --i)
			m = (a[i] + m * (long long) base) % v;
		return m * sign;
	}
 
	void operator+=(const bigint &v) {
		*this = *this + v;
	}
	void operator-=(const bigint &v) {
		*this = *this - v;
	}
	void operator*=(const bigint &v) {
		*this = *this * v;
	}
	void operator/=(const bigint &v) {
		*this = *this / v;
	}
 
	bool operator<(const bigint &v) const {
		if (sign != v.sign)
			return sign < v.sign;
		if (a.size() != v.a.size())
			return a.size() * sign < v.a.size() * v.sign;
		for (int i = a.size() - 1; i >= 0; i--)
			if (a[i] != v.a[i])
				return a[i] * sign < v.a[i] * sign;
		return false;
	}
 
	bool operator>(const bigint &v) const {
		return v < *this;
	}
	bool operator<=(const bigint &v) const {
		return !(v < *this);
	}
	bool operator>=(const bigint &v) const {
		return !(*this < v);
	}
	bool operator==(const bigint &v) const {
		return !(*this < v) && !(v < *this);
	}
	bool operator!=(const bigint &v) const {
		return *this < v || v < *this;
	}
 
	void trim() {
		while (!a.empty() && !a.back())
			a.pop_back();
		if (a.empty())
			sign = 1;
	}
 
	bool isZero() const {
		return a.empty() || (a.size() == 1 && !a[0]);
	}
 
	bigint operator-() const {
		bigint res = *this;
		res.sign = -sign;
		return res;
	}
 
	bigint abs() const {
		bigint res = *this;
		res.sign *= res.sign;
		return res;
	}
 
	long long longValue() const {
		long long res = 0;
		for (int i = a.size() - 1; i >= 0; i--)
			res = res * base + a[i];
		return res * sign;
	}
 
	friend bigint gcd(const bigint &a, const bigint &b) {
		return b.isZero() ? a : gcd(b, a % b);
	}
	friend bigint lcm(const bigint &a, const bigint &b) {
		return a / gcd(a, b) * b;
	}
 
	void read(const string &s) {
		sign = 1;
		a.clear();
		int pos = 0;
		while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
			if (s[pos] == '-')
				sign = -sign;
			++pos;
		}
		for (int i = s.size() - 1; i >= pos; i -= base_digits) {
			int x = 0;
			for (int j = max(pos, i - base_digits + 1); j <= i; j++)
				x = x * 10 + s[j] - '0';
			a.push_back(x);
		}
		trim();
	}
 
	friend istream& operator>>(istream &stream, bigint &v) {
		string s;
		stream >> s;
		v.read(s);
		return stream;
	}
 
	friend ostream& operator<<(ostream &stream, const bigint &v) {
		if (v.sign == -1)
			stream << '-';
		stream << (v.a.empty() ? 0 : v.a.back());
		for (int i = (int) v.a.size() - 2; i >= 0; --i)
			stream << setw(base_digits) << setfill('0') << v.a[i];
		return stream;
	}
 
	static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
		vector<long long> p(max(old_digits, new_digits) + 1);
		p[0] = 1;
		for (int i = 1; i < (int) p.size(); i++)
			p[i] = p[i - 1] * 10;
		vector<int> res;
		long long cur = 0;
		int cur_digits = 0;
		for (int i = 0; i < (int) a.size(); i++) {
			cur += a[i] * p[cur_digits];
			cur_digits += old_digits;
			while (cur_digits >= new_digits) {
				res.push_back((int)(cur % p[new_digits]));
				cur /= p[new_digits];
				cur_digits -= new_digits;
			}
		}
		res.push_back((int) cur);
		while (!res.empty() && !res.back())
			res.pop_back();
		return res;
	}
 
	typedef vector<long long> vll;
 
	static vll karatsubaMultiply(const vll &a, const vll &b) {
		int n = a.size();
		vll res(n + n);
		if (n <= 32) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					res[i + j] += a[i] * b[j];
			return res;
		}
 
		int k = n >> 1;
		vll a1(a.begin(), a.begin() + k);
		vll a2(a.begin() + k, a.end());
		vll b1(b.begin(), b.begin() + k);
		vll b2(b.begin() + k, b.end());
 
		vll a1b1 = karatsubaMultiply(a1, b1);
		vll a2b2 = karatsubaMultiply(a2, b2);
 
		for (int i = 0; i < k; i++)
			a2[i] += a1[i];
		for (int i = 0; i < k; i++)
			b2[i] += b1[i];
 
		vll r = karatsubaMultiply(a2, b2);
		for (int i = 0; i < (int) a1b1.size(); i++)
			r[i] -= a1b1[i];
		for (int i = 0; i < (int) a2b2.size(); i++)
			r[i] -= a2b2[i];
 
		for (int i = 0; i < (int) r.size(); i++)
			res[i + k] += r[i];
		for (int i = 0; i < (int) a1b1.size(); i++)
			res[i] += a1b1[i];
		for (int i = 0; i < (int) a2b2.size(); i++)
			res[i + n] += a2b2[i];
		return res;
	}
 
	bigint operator*(const bigint &v) const {
		vector<int> a6 = convert_base(this->a, base_digits, 6);
		vector<int> b6 = convert_base(v.a, base_digits, 6);
		vll a(a6.begin(), a6.end());
		vll b(b6.begin(), b6.end());
		while (a.size() < b.size())
			a.push_back(0);
		while (b.size() < a.size())
			b.push_back(0);
		while (a.size() & (a.size() - 1))
			a.push_back(0), b.push_back(0);
		vll c = karatsubaMultiply(a, b);
		bigint res;
		res.sign = sign * v.sign;
		for (int i = 0, carry = 0; i < (int) c.size(); i++) {
			long long cur = c[i] + carry;
			res.a.push_back((int) (cur % 1000000));
			carry = (int) (cur / 1000000);
		}
		res.a = convert_base(res.a, 6, base_digits);
		res.trim();
		return res;
	}
};

void solve(){
    int n;cin>>n;
    string v;cin>>v;
    if(v[0]=='9')cout<< bigint(string(n+1,'1')) - bigint(v) <<endl;
    else cout<< bigint(string(n,'9')) - bigint(v) <<endl;

    cout<< bigint("1111111113323232323233232321115") * bigint("41111111111") <<endl;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    cin >> t;
    while(t--)solve(); 
    return 0;
}





//#######-------Big Integer Addition--------########
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
//#######-------Big Integer Multiplication--------########
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

//#######-------Binomial Coefficient--------########
// nCr = n! / (r!(n-r)!)

// if a<b then binomial coeffiecient = 0
//For numerator use normal factorial
//Use fermet little theorem for the denominator

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int md = 1e9 + 7;
ll factorial[10001000];//1e7

ll binpow(ll a, ll b, ll m) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%m;
        a = (a * a) %m;
        b >>= 1;
    }
    return res;
}


void precalculateFactorials(int n) {
    factorial[0] = 1;
    for (int j = 1; j <= n; j++) {
        factorial[j] = (factorial[j - 1] * j) % md;
    }
}

// nCr = n! / (r!(n-r)!)
ll binomial_coefficient(int n, int r){
    //Numerator = factorial[a]
    ll numerator = factorial[n];
    //Determinator
    //Denominator, first find the factorial(tt = ((n-r)!*r!) ) then binexpo(tt,M-2,M); = a^(M-2)%M
    ll denominator = (factorial[r] * factorial[n-r]) %md;//t
    ll denominator2 = binpow(denominator, md-2, md);//binexpo(tt,M-2,M); = a^(M-2)%M
    ll ans = (numerator * denominator2)%md;

    return ans;
}


void solve(){
    precalculateFactorials(1000100);//1e6 porjntoi kaj korbe inside local function, main function e 1e8 o cholbe

    ll n;
    cin>>n;
    ll a,b;

    for(ll i=0;i<n;i++){
        cin>>a>>b;
        cout<<binomial_coefficient(a,b)<<endl;
    }
}


int main(){
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}

//#######-------Burnside Lemma--------########
#define ll long long
int md = 1e9 + 7;

ll power(ll a, ll b, ll m) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%m;
        a = (a * a) %m;
        b >>= 1;
    }
    return res;
}

ll inverse(ll i){
    return power(i, md-2, md);
}

void burnside_lemma(ll N, ll M)
{
 
    ll ans = 0;
 
    for (ll i = 0; i < N; i++) {
 
        // Find M^(GCD(k,n))
        ans = ( ans + power(M,__gcd(i,N),md))%md;
        //cout<< N << " " << M << " " << ans <<endl;
    }
    
    //for very long N size, we must do inverse modulo
    ll nn = inverse(N);//cause divided by, so -> ans = ans * N^-1
    ans = (ans%md * nn%md)%md;// modulo multiplication rule
    cout << ans << endl;
}
//#######-------Catalan Numbers--------########

ll catalan[1001000];
void solve(){

    ll n;
    cin>>n;
    catalan[0] = catalan[1] = 1;
 
    // Fill entries in catalan[] using recursive formula
    for (int i = 2; i <= n; i++) {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
            catalan[i] += catalan[j] * catalan[i - j - 1];
    }

    for(int i=1;i<=n;i++){
        cout<<catalan[i]<<endl;
    }
 
    
}
//#######-------Derangement--------########
//n! = (n-1) * ((n-1)!+(n-2)!)
//Can be solved using recursion(DP) and inclusion exclusion iterative approach

//Using Dynamic Programming
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int md = 1e9 + 7;
ll dp[2000000];
ll dearrangement(ll n){
    if(n==1) return 0;
    else if(n==2) return 1;

    if(dp[n]!=-1) return dp[n];
    return  dp[n] = (n-1) * ( dearrangement(n-1) + dearrangement(n-2) );
}

void solve(){
    ll n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<dearrangement(n)<<endl;
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}


//#######-------Divisors--------########
void divisors(int n){
    for(int i = 1; i*i <= n; i++){
        if(n % i == 0){
			cout << i << " ";
			if(i != n/i) cout << n/i << " ";
		}
    }
}

int main(){
	divisors(36);
    return 0;
}
//#######-------Euler Totient-------########
//phi = coprimes of a number
// coprime = of 6 is 2, because of 2 number, 1,6 gcd  = 1 and 5,6 gcd = 1
long long phi[1000001];
void etf(){
	for(int i=0; i < 1000001; ++i)
		phi[i] = i;
	for(int i=2; i < 1000001; ++i){
		if(phi[i] == i ){
			for(int j=1; i*j < 1000001; ++j){
				phi[i*j] /= i;//divide by 2 multiplied by 1, for i = 2
				phi[i*j] *= (i-1);
			}
		}
        //cout<<i<<" "<<phi[i]<<endl;
	}
}
//#######-------Factorial--------########
//Using DP
long long factorial[10001000];//1e9+1000
void fac(int n) {
    factorial[0] = 1;
    for (int i = 1; i <= n; i++) {
        factorial[i] = (factorial[i - 1] * i);
    }
}




//using recursion
int fac(int n){
    if(n==1) return 1;
    return n * fac(n-1);
}

//Factorial using non recursive method
void non_recursive(int n){
    //int n = 6; 
    int s = 1;
    for(int i=1;i<=n;i++){
        s*=i;
    }
    cout<<s<<endl;
}
//#######-------Fermet Little Theorem--------########
//Creating Strings II problem
//n!/p! = n! * p!^-1
//for calculating p!^-1 we will use fermet's little theorem
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int md = 1e9+7;

ll factorial[1002000];
void precalculateFactorials(int n) {
    factorial[0] = 1;
    for (int j = 1; j <= n; j++) {
        factorial[j] = (factorial[j - 1] * j) % md;
    }
}

ll binpow(ll a, ll b, ll m) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%m;
        a = (a * a) %m;
        b >>= 1;
    }
    return res;
}


void solve(){
    precalculateFactorials(1001000);

    string s;
    cin>>s;
    int n = s.size();
    int fr[26]={};

    
    for(int i=0;i<n;i++){
        fr[s[i]-'a']++;
    }

    vector<int> p;
    for(int i=0;i<=25;i++){
        //cout<<fr[i]<<" "<<char(i+97)<<endl;
        if(fr[i]>=2) p.push_back(fr[i]);
    }

    // (n! * inverse(common!))%mod
    ll numerator = factorial[s.size()];
    ll denominator = 1;
    for(auto x: p){
        denominator = (denominator * factorial[x])%md;
    }
    denominator = binpow(denominator,md-2,md);
    cout<< (numerator * denominator)%md <<endl;
    // cout<<numerator<<endl;
    // cout<<denominator<<endl;

    


}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}
//#######-------Fibonacci--------########
//Sequence followed here: 0,1,1,2,3,5,8,13,21...

//fibonacci using dp -> O(N)
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[100];
ll fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = fib(n-2) + fib(n-1);
}

void solve(){
    memset(dp,-1,sizeof(dp));
    ll n;
    cin>>n;
    cout<<fib(n)<<endl;
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}



//#######-------Binet formula of fibonacci number--------########
//Works only upto n<71
//0,1,2,3,5,8,13,21,34,55

#define ll long long

ll binet(ll n) 
{ 
	double phi = (1 + sqrt(5)) / 2; 
	return round(pow(phi, n) / sqrt(5)); 
} 

ll binet_2(ll n){
    return (pow((1 + sqrt(5)),n) - pow((1 - sqrt(5)),n))/ (pow(2,n) * sqrt(5));
}




//#######-------Using Matrix Exponentiation--------######## O(logn)

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void multiply(ll F[2][2], ll M[2][2]);
void power(ll F[2][2], ll n);

// Function that returns nth Fibonacci number
ll fib(ll n)
{
	ll F[2][2] = { { 1, 1 }, { 1, 0 } };
	if (n == 0)
		return 0;
	power(F, n - 1);

	return F[0][0];
}

// Optimized version of power() in method 4
void power(ll F[2][2], ll n)
{
	if (n == 0 || n == 1)
		return;
	ll M[2][2] = { { 1, 1 }, { 1, 0 } };

	power(F, n / 2);
	multiply(F, F);//F matrix * F matrix, if power is even

	if (n % 2 != 0)
		multiply(F, M);//F matrix * M matrix, if power is odd
}

void multiply(ll F[2][2], ll M[2][2])
{
	ll x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
	ll y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
	ll z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
	ll w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}

void solve(){
    ll n;
    cin>>n;
    cout<<fib(n)<<endl;
}

//#######-------GCD and LCM--------########

//Euclidean’s theorem
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int lcm(int a,int b){
	return (a*b)/gcd(a,b);
}

int main()
{

	int a = 4, b = 8;
	cout <<"The GCD of the two numbers is "<<gcd(a, b);//goshagu
	cout <<"The lcm of the two numbers is "<<lcm(a, b);//loshagu

    //Built in
    cout<<__gcd(a,b)<<endl;
    cout<<gcd(a,b)<<endl;
    cout<<lcm(a,b)<<endl;
}

//#######-------Inclusion-Exclusion--------########
// n = 30, values = 2,3,5
void inclusion_exclusion(){
    int val = 30;
    int n = 3;
    int ar[n+1] = {2,3,5};
    int all_subset= (1<<n);
    int ct = 0, prod = 1;
    ll sum = 0;
    for(int i=1;i<all_subset;i++){
        ct = 0, prod = 1;//count, product
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                ct++;
                prod*=ar[j];
                cout<<ar[j]<<" ";
            }
        }
        if(ct%2==1) sum+=(val/prod);
        else sum-=(val/prod);
    }
}

//#######-------Matrix Exponentiation--------########
//matrix exponentiation using normal modular exponentiation, but using matrix



#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define N 101
ll ar[N][N],I[N][N];
ll md = 1e9+7;

void mul(ll A[][N],ll B[][N],ll n)
{
	ll i,j,k;
	ll R[n+1][n+1];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			R[i][j]=0;
			for(k=1;k<=n;k++)
			{
				ll x = (A[i][k]*B[k][j]);
				R[i][j]=(R[i][j]+x);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			A[i][j]=R[i][j];
		}
	}
}

void power(ll A[][N],ll n,ll p)
{
	ll i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j)I[i][j]=1;
			else I[i][j]=0;
		}
	}

	//multiply the matrix
	/*
	for(i=1;i<=p;i++)
	{
		mul(I,A,n);
	}
	*/
	while(p)
	{
		if(p%2==1)
		{
			mul(I,A,n);
			p--;
		}
		else{
			mul(A,A,n);
			p/=2;
		}
	}
	//return value

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			A[i][j]=I[i][j];
		}
	}

}

/*
Sample input:
2 1
3 1
2 4

*/

void solve()
{
    ll n, p, i, j, k;
    cin >> n >> p;//n = size of matrix , p = power of matrix
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> ar[i][j];
        }
    }
    power(ar, n, p);
    // cout<<"print the answer"<<endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }
}


//#######-------Modular Inverse--------########
//Main Inverse template, for divisional power
int md = 1e9 + 7;
ll power(ll a, ll b, ll m) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%m;
        a = (a * a) %m;
        b >>= 1;
    }
    return res;
}


ll inverse(ll i){
    return power(i, md-2, md);//binexpo(tt,M-2,M); = a^(M-2)%M
}



///############################################




int md = 1e9 + 7;
ll inverse(ll i){
    if(i==1) return 1;
    return (md - ((md/i)*inverse(md%i))%md+md)%md;
}

//#######-------Modular Exponentiation--------########
//Binary Exponentiation

#include <bits/stdc++.h>
using namespace std;
#define ll long long


//#######-------Version 1--------########
//Without using val, calling recursion function again and again

//a^b
//For Even: 3^8 = 3^4 * 3^4
//For Odd : 3^9 = 3^4 * 3^4 * 3
int bin_expo(int a,int b){
    if(b==0) return 1;
    //ll val = bin_expo(n/2);
    else if(b%2==0) return bin_expo(a,b/2) * bin_expo(a,b/2);
    else if(b%2==1) return bin_expo(a,b/2) * bin_expo(a,b/2)  * a;//3^9 = 3^4 * 3^4 * 3
}

void solve(){
    cout<<bin_expo(2,5);
}

//#######-------Version 2--------########


int bin_expo(int a,int b){
    if(b==0) return 1;
    int val = bin_expo(a,b/2);
    if(b%2==0) return val * val;
    else if(b%2==1) return val * val * a;
}

void solve(){
    cout<<bin_expo(3,5);
}


//#######-------Version 3 - Using while loop--------########

ll bin_expo(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            //cout<<res<<endl;
            res = res * a;
        cout<<a<<endl;
        a = a * a;
        b >>= 1;
    }
    return res;
}

res = 1 * 2;//2
a = 2 * 2;//4
b = 7/2;//3(aro 2 bar hobe)

a = 4 * 4;//16
b = 3/2;//1(aro 1 bar hobe)

res = 2*16
a = 16*16//256
b = 1/2//0 get out of the loop



//Mainnnnnnnnnn*************//#######-------Version 4 --------########



//Exponentiation Codes

//Binary Exponential using recursion
ll power(ll a, ll b) {
    if (b == 0)
        return 1;
    ll res = power(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}


//non recursive
ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}




//#######-------Prime Factors--------########
//Prime factors, Prime factorization

//O(sqrt(n))
void pf(int n){
    vector<int> prime_factors;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            prime_factors.push_back(i);
            n = n/i;
        }
    }
    if(n>1)prime_factors.push_back(n);
    // for(auto x: prime_factors)cout<<x<<" ";
    // cout<<endl;
}


//#######-------Segmented Sieve--------########
//Segmented Sieve

//Range will always be in between 10^6 to 10^7, will not be given more than that

/*
Steps
1. Count primes of the sqrt of the total length using normal siever
2. Total area of the prime vector should be = r-l+1,0
3. We will start our loop from ----- (low/the_prime_number)*the_prime_number   ------ (l/x)*x;
4. we will keep marking the prime multiples as non prime




Main section of code where segmenting is occuring:



void seg_sieve(int l, int r){
    vector<int> isPrime(r-l+1,0);
    
    for(auto x: primes){
        //int start = max(x * x, (l + x - 1) / x * x);
        int start = (l/x)*x;
        if(start<l) start+=x;
        //making the factors non prime
        for(int i=start;i<=r;i+=x){
            //if(i!=x) -> prime k non prime korbo na
            if(i!=x)isPrime[i-l] = 1;
        }
    }

    //appending the primes a vector

    for(int i=0;i<isPrime.size();i++){
        if(!isPrime[i]) cout<< i+l <<" ";//ans++;
    }
    cout<<endl;

}

*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

vector<int> primes;

void precalc_sieve(int x){
    vector<int>pr(x+1,0);

    pr[0] = 1;//0 and 1 is not prime
    pr[1] = 1;
    for(int i=2;i*i<=x;i++){
        if(!pr[i]){
            for(int j=i*i;j<=x;j+=i){
                pr[j] = 1;
            }
        }
    }
    for(int k=2;k<=x;k++){
        if(!pr[k]) primes.push_back(k);
    }
}

void seg_sieve(int l, int r){
    if(l==1)l++;
    vector<int> isPrime(r-l+1,0);
    
    for(auto x: primes){
        int start = (l/x)*x;
        if(start<l) start+=x;
        for(int i=start;i<=r;i+=x){
            if(i!=x)isPrime[i-l] = 1;
        }
    }

    for(int i=0;i<isPrime.size();i++){
        if(!isPrime[i]) cout<< i+l <<" ";
    }
    cout<<endl;

}

void solve(){
    int l, r, ans = 0;
    cin>> l >> r;
    int sq = sqrt(r);
    precalc_sieve(sq);
    seg_sieve(l,r);
}

//#######-------Sieve--------########
//sieve of eratosthenes for prime chekcking
#include <bits/stdc++.h>
using namespace std;
int isPrime(int n){
    if(n<=1){
        return false;
    }
    bool prime[n+1];
    memset(prime,true,sizeof(prime));

    for(int p=2;p*p<=n;p++){
        if(prime[p]==1){
            for(int i=p*p;i<=n;i+=p){
                prime[i] = false;
            }
        }
    }
    return prime[n];
}

void solve(){
    int n;
    cin>>n;
    if(isPrime(n))cout<<"Prime"<<endl;
    else cout<<"Not Prime"<<endl;
}



//https://www.geeksforgeeks.org/bitwise-sieve/
//https://www.shafaetsplanet.com/?p=855
// Bitwise Sieve of Eratosthenes
#include <bits/stdc++.h>
using namespace std;

bool ifnotPrime(int prime[], int x){
	return (prime[x/64] & (1 << ((x >> 1) & 31)));
}

bool makeComposite(int prime[], int x){
	prime[x/64] |= (1 << ((x >> 1) & 31));
}

void bitWiseSieve(int n)
{
	int prime[n/64];
	memset(prime, 0, sizeof(prime));

	for (int i = 3; i * i <= n; i += 2) {
		if (!ifnotPrime(prime, i))
			for (int j = i * i, k = i << 1; j < n; j += k)
				makeComposite(prime, j);
	}

	printf("2\n");

	for (int i = 3; i <= n; i += 2){
        if (!ifnotPrime(prime, i)){
            printf("%d\n", i);
        }
    }
		
        
			
            
}

// Driver code
int main()
{
	int n = 10000000;
	bitWiseSieve(n);
	return 0;
}


//#######-------Another version(bitwise sieve)--------########
//https://www.shafaetsplanet.com/?p=855

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int lim = 1e8;

int N =lim,prime[lim]; 
int status[3200000];

bool check(int N,int pos){return (bool)(N & (1<<pos));}
int Set(int N,int pos){	return N=N | (1<<pos);}

void bitwise_sieve(){
    int i, j; 
    for( i = 3; i * i <= N; i += 2 ) 
    {
        if(check(status[j>>5],i & 31)==0){
            for( j = i*i; j <= N; j += (i<<1)){
                status[j>>5]=Set(status[j>>5],j & 31);
            }
        }
    }
    printf("%lld\n",2);
    for(i=3;i<=N;i+=2){
        if(check(status[j>>5],i & 31)==0)printf("%d\n",i);
    }
}

void solve(){
    bitwise_sieve();
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}


//#######-------Binary Search On Answer--------########
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ar[1000100];
bool ok(){

}

void solve(){
    
    ll l = 0, r = , m;
    
    while(l+1<r){
        m = (l+r)>>1;
        if( ok(m) ) l = m;
        else r = m;
    }
    cout<< l <<endl;

}

//#######-------Adjacency List and Adjacency Matrix--------########
//Adjacency List
#include <bits/stdc++.h>
using namespace std;
void adjacency_list(){
    int v,e;//v=vertices, e = edges
    cin>>v>>e;
    vector<int> graph[N];//can be done like this also
    vector<vector<int>> graph(v + 1); // 2d vector array
    for(int i=1;i<=e;i++){
        int v1,v2;//vertex 1, vertex 2
        cin>>v1>>v2;
        //graph[v1][v2]=1;
        //graph[v2][v1]=1;
        
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);

    }



    //Display the graph
    cout << "Adjacency List:" << endl;

    // Displaying the adjacency list
    for (int i = 1; i <= v; i++) {
        cout << i << ": ";
        for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }



}


int main(){

    int t=1;
    //cin >> t;
    while(t--)adjacency_list(); 
    return 0;
}


//#########################################################################
//#########################################################################

//Adjacency Matrix
#include <bits/stdc++.h>
using namespace std;
void adjacency_matrix(){
    int v,e;//v=vertices, e = edges
    cin>>v>>e;
    int graph[v+1][v+1]={};
    for(int i=1;i<=e;i++){
        int v1,v2;//vertex 1, vertex 2
        cin>>v1>>v2;
        graph[v1][v2]=1;
        graph[v2][v1]=1;//for undirected graph, it is 2 way
    }



    //Display the graph
    cout << "Adjacency Matrix:" << endl;

    // Displaying the adjacency matrix
    for (int i = 1; i <=v; i++) {
        for (int j = 1; j <=v; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)adjacency_matrix(); 
    return 0;
}

//#######-------BFS--------########
#include <bits/stdc++.h>
using namespace std;

/**

Input:

6 5
1 2
1 3
2 4
2 5
3 6
1

Output:
1 2 3 4 5 6

**/

int visited[100];
vector <int> adj[100];
void bfs(int n, int s) {
    // for(int i=0; i<n; i++)
    //     visited[i] = 0;
    queue<int>q;
    q.push(s);
    visited[s] = 1;//parent node visited kore dicchi
    while(!q.empty()) {//queue-r vitor child node visit krtesi
        int u = q.front();
        q.pop();
        //printf("%d ", u);
        for(int i=0; i<adj[u].size(); i++) {
            int v = adj[u][i];
            //cout<<u<< " " <<v<<endl;
            if(visited[v] == 0) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
    printf("\n");
}


int main()
{
    int n, s, edges, a, b;
    scanf("%d%d", &n, &edges);
    // n = no. of vertices and edges =no. of edges
    for(int i=0; i<edges; i++){
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    scanf("%d", &s); //s = source node
    bfs(n, 2);
    return 0;
}




//Practice
#include <bits/stdc++.h>
using namespace std; 

vector<int>g[100];
int visited[100];

void bfs(int s){
    queue<int> q;
    q.push(s);
	visited[s] = 1;

    while(q.empty()==0){
        int u = q.front();//etar sathe linked node gulate jawa
        q.pop();
        //cout<<u;
        for(int i=0;i<g[u].size();i++){
            //cout<<g[u][i];// g[1 0] -> 2, g[1 1] -> 3
            
            if(visited[g[u][i]]==0){
                q.push(g[u][i]);
                visited[g[u][i]] = 1;
                //cout<<q.front();

            }
            // if(){
            //     //q.push(x);
            //    // cout<<x;
                
            // }
            
        }
        //cout<<q.front();
        
    }

}
int main() 
{ 
	int n,e;
	cin>>n>>e;
	for(int i=1;i<=e;i++){
		int v1,v2;
		cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
	}

    int s; //source
    cin>>s;
    cin>>s;
    bfs(s);
	return 0; 
} 


//https://codeforces.com/contest/1829/submission/249861552
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int n,m;
bool vis[1005][1005]={};
int mat[1005][1005];
int sum = 0; 
bool isValid(int i, int j){
    return 0 <= i && i < n && 0 <= j && j < m;
}

int dx[]={-1,1,0, 0};
int dy[]={ 0,0,1,-1};

void bfs(int i, int j){
    queue<pair<int,int>>q;
    q.push({i,j});
    vis[i][j] = 1;
    while(!q.empty()){
        auto [x,y] = q.front();
        sum+=mat[x][y];
        q.pop();
        for(int k=0;k<4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(isValid(nx,ny) && mat[nx][ny]!=0 && !vis[nx][ny])q.push({nx,ny}),vis[nx][ny]=1;
        }
    }
}

void solve(){
    cin>>n>>m;
    memset(vis, 0, sizeof(vis));
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]!=0 && !vis[i][j]){
                sum = 0;
                bfs(i,j);
                ans = max(ans, sum);
            }
        }
    }
    cout<< ans <<endl;
}

//#######-------DFS--------########
#include <bits/stdc++.h>

using namespace std;

int visited[100];
vector <int> adj[100];

void dfs(int s) {
        if (visited[s]) return;
        visited[s] = true;
        //cout<<s<<endl;
        cout<<endl<<endl;
        //visiting neighbours, for 1 adj[s]={4,3,2,1}
        for (auto u: adj[s]) {
            //if(!visited[u])cout<<s<<"rrr "<<u<<"ttt "<<endl;
            cout<<s<<"rrr "<<u<<"ttt "<<endl;
            cout<<adj[s].size()<<endl;
            dfs(u);
        }
        
}


//input 
// 6 5 -> 6 nodes, 5 edges, which is bascially a tree
// 0 1
// 1 4
// 1 3
// 0 2
// 2 5

int main()
{
    int n, s, edges, a, b;
    scanf("%d%d", &n, &edges);
    for(int i=0; i<edges; i++) {
        scanf("%d%d", &a, &b);//not directed graph
        adj[a].push_back(b);//creating adjacency list
        adj[b].push_back(a);
    }
    scanf("%d", &s);
    dfs(s);
    return 0;
}
//#######-------Tree Traversal-------########
//A Binary Search Tree of n elements and then display the elements (preorder, in order and post order) of the tree.
#include <bits/stdc++.h>
using namespace std;


//here Bst *root means a node is getting created
//struct
struct Bst{
    int data;
    Bst *left;
    Bst *right;
};

//preorder
void preorder(Bst *root){
    if(root==NULL) return;
    cout<<root->data<<endl;//root
    preorder(root->left);//left
    preorder(root->right);//right
}

//inorder
void inorder(Bst *root){
    if(root==NULL) return;
    inorder(root->left);//left
    cout<<root->data<<endl;//root
    inorder(root->right);//right
}

//postorder
void postorder(Bst *root){
    if(root==NULL) return;
    postorder(root->left);//
    postorder(root->right);
    cout<<root->data<<endl;
}


//insert element in the tree
Bst *insert(Bst *root, int data){
    if(root==NULL){
        root = new Bst();
        root-> data = data;//
        root->left = root->right = NULL;
    }
    else if(data<=root->data){
        root->left = insert(root->left,data);
    }
    else if(data>root->data){
        root->right = insert(root->right,data);
    }
    return root;//
}



int main(){
    Bst *root = NULL;

    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 55);
    root = insert(root, 2);
    root = insert(root, 13);
    root = insert(root, 15);
    root = insert(root, 144);


    cout<<"Preorder: "<<endl;
    preorder(root);
    cout<<endl<<endl;
    cout<<"Inorder: "<<endl;
    inorder(root);
    cout<<endl<<endl;
    cout<<"Postorder: "<<endl;
    postorder(root);
    cout<<endl<<endl;

    
    return 0;
}
//#######-------Searching in Tree--------########
//A Binary Search Tree of n elements and then search an element from the tree.

//structure is a user defined data type
#include <bits/stdc++.h>
using namespace std;
//creating node datatype of the binary tree, node is the container of data type
struct Bst 
{   
    int data;
    Bst *left;
    Bst *right;
};
//creating new node in the tree
Bst *create_node(int data){
    Bst* new_node = new Bst();//we are creating a new node here
    new_node->data = data;//int data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}
//struct Bst = Bst* = data type like int 


//Inserting data 
Bst *insert(int data, Bst *root){
    //If the tree is empty then create the node
    if(root == NULL){
        root = create_node(data);
    }
    // if data to be inserted is greater, insert in right subtree. 
    //20>=15
    else if(data>= root->data){
        root->right = insert(data, root->right);//root->right = address of the data
    }
    //10>=15
    else if(data<root->data){
        root->left = insert(data, root->left);
    }
    return root;
}
//searching in the tree
// data = the value we are looking for
int search(Bst* root, int data){
    //If there are 0 elements in the tree
    if(root == NULL){
        return false;
    }
    //root er j value I guess
    else if(root->data == data){
        return true;
    }
    //searching in right subtree, data-r man beshi thakle data 
    else if(data>= root->data){
        return search(root->right,data);
    }
    else if(data< root->data){
        return search(root->left,data);
    }
    return false;

}



int main(){

    Bst *root = NULL;//creating an empty tree
    root = insert(15,root);
    root = insert(8,root);
    root = insert(4,root);
    root = insert(11,root);
    root = insert(23,root);
    root = insert(16,root);
    root = insert(27,root);

    int n=27;
    if(search(root,n)==1) cout<<"Found"<<endl;
    else cout<<"Not Found"<<endl; 


    //cout<<root->right<<endl;

    return 0;
}
//#######-------Sliding Window Maximum--------########
void sliding_window(int ar[], int n, int k){
    deque<int> dq;
    for(int i=0;i<k;i++){
        while(!dq.empty() && ar[dq.back()]<ar[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    
    for(int i=k;i<n;i++){
        cout<< ar[dq.front()]<<" ";
        //remove out of all window indices
        while(dq.front()<=i-k)dq.pop_front();
        // Add the current val indices in the dequeue
        while(!dq.empty() && ar[dq.back()]<ar[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout<< ar[dq.front()]<<endl;

}

//#######-------Two Pointer(tripet sum==0 find)--------########
void two_pointer(int ar[],int n){
    sort(ar,ar+n);
    for(int i=0;i<n;i++){
       //do two pointer here
        int l = i+1, r = n-1, x = ar[i], sum = 0;
        while(l<r){
            sum = x + ar[l] + ar[r];
            if(sum>0)r--;//if sum is positive r--
            else if(sum<0)l++;//if sum is negative l++

            else if(sum==0){
                printf("%lld %lld %lld\n",x,ar[l],ar[r]);
                //break;//there would be one triplet in one sequence
                l++;//or we can increase l, and decrease r
                r--;
            }
       }
    }
}


//#######-------all subarray and subsequence-------########


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




//#######-------Bitwise Priyansh-------########

// Resource: https://youtu.be/LGrE0siZ-ZA
//bitwise Operators
//1. even or odd
    // x&1
    cout<< (5&1) <<endl;//prints 1, odd, compare binary 5 and binary 1, rest beocomes zero
    cout<< (6&1) <<endl;//prints 0, even

//2. Power of two
    // x & (x-1)
    cout<< (32 & (32-1)) <<endl;//prints 0, cause 32 is power two
    cout<< (5 & (5-1)) <<endl;//prints 4, non zero value

//3. Manipulating bits
    //check if kth bit is set
    // x & (1<<k)
    cout<< (4 & (1<<2)) <<endl;//prints 4, as 4th bit is set, works in 0 base index, right to left
    cout<< (4 & (1<<1)) <<endl;//prints 0, as 1 index is 0

    //Toggle the kth bit
    // x ^ (1<<k)
    cout<< (4 ^ (1<<2)) <<endl;//prints 0, toggle the 4th bit
    cout<< (4 ^ (1<<1)) <<endl;//prints 6, toggle the 2th bit, 100 ^ 010 -> 110

    //Set the kth bit
    // x | (1<<k)
    cout<< (4 | (1<<1)) <<endl;//prints 6, sets the 2nd bit 1

    //Unset the kth bit
    // x ~ (1<<k)
    cout<< (4 &  ~(1<<2)) <<endl;//prints 0
    cout<< (4 &  ~(1<<1)) <<endl;//prints 4

//4. Multiply or divide a number
    //Multiply
    // x << k
    cout<< (4 << 1) <<endl;//8
    cout<< (4 << 3) <<endl;//32 -> 4 * 8

    //Division
    // x >> k
    cout<< (4 >> 1) <<endl;//0
    cout<< (16 >> 1) <<endl;//8

//5. Find x % 2^k
    // x & ((1<<k)-1)
    cout<< (4 << 1) <<endl;//8

//6. Swap 2 numbers
    // x = x^y
    // y = x^y
    // x = x^y
    int t1 = 12; 
    int t2 = 112;
    cout<< t1 <<' '<<t2<<endl;//12 112
    t1 = t1 ^ t2;
    t2 = t1 ^ t2;
    t1 = t1 ^ t2;
    cout<< t1 <<' '<<t2<<endl;//112 12

//7. Toggle assignment(Finding out the the number)
    // x = a^b^x;

//8. important identities
    // a + b = (a^b) + 2 (a&b)
    // a + b = (a|b) + (a&b)

//9. Count set bits
    cout<< __builtin_popcount(4) <<endl;// 1
    cout<< __builtin_popcountll(4) <<endl;//1




/////Bitset

//print bitset
bitset<32>bset;//1st way
bitset<32>bset(5);//2nd way //print 5 binary with 32 bits
cout<<bset<<endl; 
bitset<32>bset(string("101"));//3rd way
cout<< bset.to_ulong()<<endl;//unsigned long, binary string sset to number, print binary to unsigned long
cout<< bset.to_ullong() <<endl; //unsigned long long

//print bitset
bitset<32>bset;
bset.set();//setting all bits to 1
bset.reset();//setting all bits to 0
cout<<bset<<endl;

//count how many one's in the bitset(like builtinpopcount)
bitset<32>bset;
bset.set(10);
cout<<bset.count()<<endl;//counting the total 1's
cout<< bset.flip() <<endl;//flipping 0 to 1, 1 to 0
cout<< bset[0] <<endl;//after flipping, 1 ans, 
//indexing ulta theke bitset e hoi, karon binary te ultatheke count hoi



//#######-------xxxxxxxx-------########
//#######-------xxxxxxxx-------########

//Dynamic Programming
- Think the transition state
- Solve small testcase either in tabulation or recursive
- Every types first video is the most important
- Learn to write bottom up table
- Learn to draw solving recursively, ==  f(idx, val) diye

How to think in recursion: 
1. Play with indexes, find the base case(destination, or out of bound cases). Always write the out of bounds first
2. explore all paths / Try out all possible choices at a given index.
3. Find minimum, maximum based on the problem statement

Steps to Memoise(DP):
    1. declare dp array 
    2. store value in dp[n]== somthing 
    3. find it previously solved dp[n]! =n(check if subproblems has been previously solved)

////
- we write tabulation method to reduce the stackspace
- In 2d array, solve the position and previous positions with recursion
- Memoization code will not give TLE if both the strings are passed by reference in the function... 
  as no copies will be generated which will limit the memory and Time
  if no passed by reference it will create a new copy everytime and will take a lot of space
- Always send parameters in dp function by pass by reference
- Both 2 rowr kaj at the same time thakle one 1d array te convert korte pari na
- Make the dp of changing parameters
- write changing parameter in opposite fashion in tabulation(when converting recursive to tabulation)
- FOR ALL THE COUNT PROBLEMS: if the condition is satisfied return 1, else return 0

Space optimization:
converting:
1d DP -> two variables
2d DP -> 1d DP 
3d DP -> 2d DP 


1. In grid take x,y as dp[x][y]
2. in subsequences, take dp[ind][target]

Confusions:
1. 
Dp 16. Partition A Set Into Two Subsets With Minimum Absolute Sum Difference | DP on Subsequences
for(int i=0;i<=k;i++){//Getting WA for k/2 on top down approach.
		if(dp[n-1][i]==1)ans = min(ans,abs(i - (sum-i)) );
	}
2. DP 17. Counts Subsets with Sum K | Dp on Subsequences, handling 0 case in bottom up
3. DP 27. Longest Common Substring . Why memoization code does not work here? https://www.geeksforgeeks.org/longest-common-substring-dp-29/, solve this dp problem in memoization also
4. DP 33. Edit Distance | Recursive to 1D Array Optimised Solution draw the recursive tree
5. draw and learn the tabulation of bottom up : DP 37. Buy and Sell Stocks III , gettting WA
6. DP 47. Number of Longest Increasing Subsequences intuition bujhtesi na??
7. DP 48. Matrix Chain Multiplication 

---------------------------------------------------------------------------------------------------------
Stiver DP Playlist: https://www.youtube.com/playlist?list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY
Tutorials: https://takeuforward.org/dynamic-programming/striver-dp-series-dynamic-programming-problems/
---------------------------------------------------------------------------------------------------------

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//###################-------Introduction to DP--------###################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------DP 1. Introduction to Dynamic Programming--------########
//Tutorial: https://takeuforward.org/data-structure/dynamic-programming-introduction/


//Top Down approach Fibonacci
int f(int n, vector<int>& dp){
    if(n<=1) return n;
    
    if(dp[n]!= -1) return dp[n];
    return dp[n]= f(n-1,dp) + f(n-2,dp);
}
// Bottom Up approach Fibonacci
int fib() {

    int n=5;
    vector<int> dp(n+1,-1);
    
    dp[0]= 0;
    dp[1]= 1;
    
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1]+ dp[i-2];
    }
    cout<<dp[n];
}

//Bottom Up approach Fibonacci With O(1) space complexity
int fib() {
    int n=5;
    
    int prev2 = 0;
    int prev = 1;
    
    for(int i=2; i<=n; i++){
        int cur_i = prev2+ prev;
        prev2 = prev;
        prev= cur_i;
    }
    cout<<prev;
}

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#####################-------1D DP--------##############################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

1D DP Code: 
//Top Down
#include <bits/stdc++.h> 
int rec(int i, vector<int>&heights, vector<int>&dp){
    if(i==0) return 0;
    //n-1 to 1
    if(dp[i]!=-1) return dp[i];
    int f1 = rec(i-1, heights,dp) + abs(heights[i]-heights[i-1]);
    int f2 = INT_MAX;
    if(i>1) f2 = rec(i-2, heights,dp) + abs(heights[i]-heights[i-2]);

    return dp[i] = min(f1,f2);
}
int frogJump(int n, vector<int> &heights)
{   
    vector<int> dp(n+1,-1);
    return rec(n-1, heights,dp);
}
//Bottom Up
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(1000000,-1);
    dp[0] = 0;
    for(int i=1;i<heights.size();i++){
        int jump1 = dp[i-1] + abs(heights[i-1]-heights[i]);
        int jump2 = INT_MAX;
        if(i>1) jump2 = dp[i-2] + abs(heights[i]-heights[i-2]);//dp[i-2] will not always be valid, so i>1 condition
        dp[i] = min(jump1,jump2);
    }
    return dp[n-1];
}



//#######################################################################
//#######-------DP 2. Climbing Stairs--------########
//Tutorial: https://takeuforward.org/data-structure/dynamic-programming-climbing-stairs/
//Problem: https://www.naukri.com/code360/problems/count-ways-to-reach-nth-stairs_798650

#include <bits/stdc++.h> 
int countDistinctWays(long long nStairs) {
    vector<int> dp(nStairs+1,-1);
    dp[0] = dp[1] = 1;
    for(int i=2;i<=nStairs;i++){
        dp[i] = (dp[i-1] + dp[i-2])%1000000007;
    }
    return dp[nStairs];
}

//#######################################################################
//#######-------DP 3. Frog Jump | Dynamic Programming | Learn to write 1D DP--------########
//Tutorial: https://takeuforward.org/data-structure/dynamic-programming-frog-jump-dp-3/
//Problem: https://www.naukri.com/code360/problems/frog-jump_3621012

//solve from the beginning, the cost of jumping each in minimum
//bottom to up
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(1000000,-1);
    dp[0] = 0;
    for(int i=1;i<heights.size();i++){
        int jump1 = dp[i-1] + abs(heights[i-1]-heights[i]);
        int jump2 = INT_MAX;
        if(i>1) jump2 = dp[i-2] + abs(heights[i]-heights[i-2]);//dp[i-2] will not always be valid, so i>1 condition
        dp[i] = min(jump1,jump2);
    }
    return dp[n-1];
}


// rec(i-1) is same as dp[i-1] in bottom up

//up to bottom

#include <bits/stdc++.h> 
int rec(int i, vector<int>&heights, vector<int>&dp){
    if(i==0) return 0;
    //n-1 to 1
    if(dp[i]!=-1) return dp[i];
    int f1 = rec(i-1, heights,dp) + abs(heights[i]-heights[i-1]);
    int f2 = INT_MAX;
    if(i>1) f2 = rec(i-2, heights,dp) + abs(heights[i]-heights[i-2]);

    return dp[i] = min(f1,f2);
}
int frogJump(int n, vector<int> &heights)
{   
    vector<int> dp(n+1,-1);
    return rec(n-1, heights,dp);
}

//bottom to up with (space optimization)
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    int pr = 0, pr2 = 0;
    for(int i=1;i<heights.size();i++){
        int jump1 = pr + abs(heights[i-1]-heights[i]);
        int jump2 = INT_MAX;
        if(i>1) jump2 = pr2 + abs(heights[i]-heights[i-2]);
        
        int v = min(jump1,jump2);
        pr2 = pr;
        pr = v;
    }
    return pr;
}


//#######################################################################
//#######-------DP 4. Frog Jump with K Distance--------########
//Tutorial: https://takeuforward.org/data-structure/dynamic-programming-frog-jump-with-k-distances-dp-4/
//Problem: https://www.naukri.com/code360/problems/minimal-cost_8180930

//Top Down
int rec(int i, int k, vector<int> &dp, vector<int> &height ){
    if(i==0)return 0;
    int v = INT_MAX;
    if(dp[i]!=-1)return dp[i];
    for(int j=1;j<=k;j++){
        if(i-j>=0){
            int jump = rec(i-j, k, dp, height) + abs(height[i]-height[i-j]);
            v = min(v, jump);
        }
        
    }
    return dp[i] = v;
}
int minimizeCost(int n, int k, vector<int> &height){
    vector<int>dp(n+1,-1);
    return rec(n-1, k, dp, height);
}

//Bottom Up
int minimizeCost(int n, int k, vector<int> &height){
    vector<int>dp(n+1,-1);
    dp[0]=0;
    for(int i=1;i<n;i++){//2nd step theke shuru kora, tahole minimum ekbar holeo i-j>=0 loop er vitor jabe
        int v = INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int jump = dp[i-j] + abs(height[i]-height[i-j]);
                v = min(v, jump);
            }
        }
        dp[i] = v;
    }
    return dp[n-1];
}

//#######################################################################
//#######-------DP 5. Maximum Sum of Non-Adjacent Elements | 1-D | DP on Subsequences--------########
//Tutorial: https://takeuforward.org/data-structure/maximum-sum-of-non-adjacent-elements-dp-5/
//Problem: https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261


//recursion on subsequences - prerequisite for this problem
void rec(int i, int n, vector<int>&a, vector<int>&li){
	if(i==n){
		//print all the subsequences
		for(auto x: li)cout<< x <<' ';
		cout<<endl;
		return;
	}
	//take 
	li.push_back(a[i]);
	rec(i+1, n, a, li);
	//not take
	li.pop_back();
	rec(i+1, n, a, li);
}

void solve(){
    vector<int> a = {3,1,2};
	vector<int> li;
	rec(0,a.size(), a, li);
}

//Problem solution
//Top Down -> Recursive version 1(kind of bottom up)
#include <bits/stdc++.h> 
int rec(int i, vector<int>&nums, vector<int>&dp){
    if(i>=nums.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    int pick = nums[i] + rec(i+2, nums, dp);
    int notpick = 0 + rec(i+1, nums, dp);
    return dp[i] = max(pick, notpick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums.size(),-1);
    return rec(0, nums, dp);
}


//Top Down -> Recursive version 2
#include <bits/stdc++.h> 
int rec(int i, vector<int>&nums, vector<int>&dp){
    if(dp[i]!=-1) return dp[i];
    if(i==0) return nums[i];
    if(i<0) return 0;
   
    int pick = nums[i] + rec(i-2, nums, dp);
    int notpick = 0 + rec(i-1, nums, dp);
    return dp[i] = max(pick, notpick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums.size(),-1);
    return rec(nums.size()-1, nums, dp);
}


//Bottom Up
#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,-1);
    dp[0] = nums[0];
    for(int i=1;i<n;i++){
        int notpick = 0 + dp[i-1];
        int pick = nums[i];
        if(i>1) pick += dp[i-2];
        dp[i] = max(pick, notpick);
    }
    return dp[n-1];
}

//Bottom Up(with space optimized)
#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    //vector<int> dp(n,-1);
    int prv = nums[0], prv2 = 0, mx;
    for(int i=1;i<n;i++){//starting from 1, cause we know the answer for 0th index
        int notpick = 0 + prv;
        int pick = nums[i];
        if(i>1) pick += prv2;
        mx = max(pick, notpick);
        prv2 = prv;
        prv = mx;
    }
    return prv;
}

//#######################################################################
//#######-------DP 6. House Robber 2 | 1D DP | DP on Subsequences--------########
//Tutorial: https://takeuforward.org/data-structure/dynamic-programming-house-robber-dp-6/
//Problem: https://www.naukri.com/code360/problems/house-robber_839733

//Top Down
//Use long long for dp array to pass testcase 6/8
#include <bits/stdc++.h>
long long rob(int i, vector<int>&valueInHouse, vector<long long>&dp){
    if(i>=valueInHouse.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    long long pick = valueInHouse[i] + rob(i+2, valueInHouse, dp);
    long long notpick = 0 + rob(i+1, valueInHouse, dp);
    return dp[i] = max(pick, notpick);
}

long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    if(n==1) return valueInHouse[0];
    vector<long long> dp(n-1, -1), dp2(n-1,-1);
    vector<int> ar,ar2;
    for(int i=1;i<n;i++)ar.push_back(valueInHouse[i]);
    for(int i=0;i<n-1;i++)ar2.push_back(valueInHouse[i]);
    long long v1 = rob(0, ar, dp);
    long long v2 = rob(0, ar2, dp2);
    return max(v1,v2);
}


//Bottom Up
#include <bits/stdc++.h> 
long long rob(vector<int> &valueInHouse){
    int n = valueInHouse.size();
    long long prv = valueInHouse[0], prv2 = 0;
    for(int i=1;i<n;i++){
        long long pick = valueInHouse[i];
        if(i>1)pick+=prv2;
        long long notpick = 0 + prv;
        long long mx = max(pick, notpick);
        prv2 = prv;
        prv = mx;
    }
    return prv;
}
long long int houseRobber(vector<int>& valueInHouse)
{   
    int n = valueInHouse.size(); 
    if(n==1)return valueInHouse[0];
    else{
        vector<int> ar,ar2;
        for(int i=1;i<n;i++)ar.push_back(valueInHouse[i]);
        for(int i=0;i<n-1;i++)ar2.push_back(valueInHouse[i]);
        n--;
        long long v1 = rob(ar);
        long long v2 = rob(ar2);
        return max(v1,v2);
    }
}


//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#####################-------DP on Grids(2d,3d)--------#################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

DP on Grids(2d,3d) Code: 
//Top Down
- for day = 0, donot write the condition extra, just write day<0 return 0

int rec(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    if(dp[day][last]!=-1)return dp[day][last];
    if(day==0){
        int mx = 0;
        for(int j=0;j<=2;j++){
            if(j!=last){
                mx = max(mx, points[0][j]);
            }
        }
        return dp[0][last] = mx;
    }
    int mx = 0;
    for(int j=0;j<=2;j++){
        if(j!=last){
            int activity = points[day][j] + rec(day-1, j, points, dp);
            mx = max(mx, activity);
        }
    }
    return dp[day][last] = mx;
}
//Bottom Up 
int asTraining(int n, vector<vector<int>> &points)
{
    vector< vector<int> > dp(n, vector<int>(4,-1));
    //for every value, removing each position see which one is maximum, compute the first
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][0],points[0][1]);
    dp[0][3] = max(max(points[0][1],points[0][1]),points[0][2]);

    for(int day = 1;day<n;day++){
        for(int last=0;last<4;last++){
            int mx = 0;
            for(int t=0;t<3;t++){
                if(last!=t){
                    mx = max(mx, points[day][t]+dp[day-1][t]);
                    dp[day][last] = mx;
                }
            }
        }
    }
    return dp[n-1][3];
}


//#######################################################################
/////////REVISITTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
//#######-------DP 7. Ninja's Training | MUST WATCH for 2D CONCEPTS--------########
//Tutorial: https://takeuforward.org/data-structure/dynamic-programming-ninjas-training-dp-7/
//Problem: https://www.naukri.com/code360/problems/ninja-s-training_3621003

//Top Down
int rec(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    if(dp[day][last]!=-1)return dp[day][last];
    if(day==0){
        int mx = 0;
        for(int j=0;j<=2;j++){
            if(j!=last){
                mx = max(mx, points[0][j]);
            }
        }
        return dp[0][last] = mx;
    }
    int mx = 0;
    for(int j=0;j<=2;j++){
        if(j!=last){
            int activity = points[day][j] + rec(day-1, j, points, dp);
            mx = max(mx, activity);
        }
    }
    return dp[day][last] = mx;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    //day, points, dp
    vector< vector<int> > dp(n, vector<int>(4,-1));
    return rec(n-1, 3, points, dp);
}

//bottom up
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector< vector<int> > dp(n, vector<int>(4,-1));
    //for every value, removing each position see which one is maximum, compute the first
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][0],points[0][1]);
    dp[0][3] = max(max(points[0][1],points[0][1]),points[0][2]);

    for(int day = 1;day<n;day++){
        for(int last=0;last<4;last++){
            int mx = 0;
            for(int t=0;t<3;t++){
                if(last!=t){
                    mx = max(mx, points[day][t]+dp[day-1][t]);
                    dp[day][last] = mx;
                }
            }
        }
    }
    return dp[n-1][3];
}

//bottom up (space optimization)
// time complexity : n*3*4
// space complexity: O(4)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int>dp(4,0);
    //for every value, removing each position see which one is maximum, compute the first
    dp[0] = max(points[0][1],points[0][2]);
    dp[1] = max(points[0][0],points[0][2]);
    dp[2] = max(points[0][0],points[0][1]);
    dp[3] = max(max(points[0][1],points[0][1]),points[0][2]);

    for(int day = 1;day<n;day++){
        vector<int>tmp(4,0);
        for(int last=0;last<4;last++){
            for(int t=0;t<3;t++){
                if(last!=t){
                    tmp[last] = max(tmp[last], points[day][t]+dp[t]);
                }
            }
        }
        dp = tmp;
    }
    return dp[3];
}



//#######################################################################
//#######-------DP 8. Grid Unique Paths | Learn Everything about DP on Grids--------########
//Tutorial: https://takeuforward.org/data-structure/grid-unique-paths-dp-on-grids-dp8/
//Problem: https://www.naukri.com/code360/problems/total-unique-paths_1081470

//Top Down
#include <bits/stdc++.h> 
int f(int i, int j, vector<vector<int>>&dp){
	if(i==0 && j==0) return 1;
	if(i<0 || j<0) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	int up = f(i-1,j,dp);
	int right = f(i,j-1,dp);
	return dp[i][j] = up + right;
}
int uniquePaths(int m, int n) {
	vector<vector<int>>dp(m, vector<int>(n,-1));
	return f(m-1,n-1,dp);
}

//Bottom Up
#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	vector<vector<int>>dp(m, vector<int>(n,-1));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i==0 && j==0){
                dp[0][0] = 1;
				continue;
			}
			int up = 0, right = 0;
			if(i>0) up = dp[i-1][j];
			if(j>0) right = dp[i][j-1];
			dp[i][j] = up+right;
		}
	}
	return dp[m-1][n-1];
}

//Bottom Up(Space optimized)
//rowwise compute kora
#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	vector<int>dp(n,0);
	for(int i=0;i<m;i++){
		vector<int>tmp(n,0);
		for(int j=0;j<n;j++){
			if(i==0 && j==0){
				tmp[0] = 1;
				continue;
			}
			int up = 0, right = 0;
			if(i>0) up = dp[j];
			if(j>0) right = tmp[j-1];
			tmp[j] = up+right;
		}
		dp = tmp;
	}
	return dp[n-1];
}


//#######################################################################
//#######-------DP 9. Unique Paths 2 | DP on Grid with Maze Obstacles--------########
//Tutorial: https://takeuforward.org/data-structure/grid-unique-paths-2-dp-9/
//Problem: https://www.naukri.com/code360/problems/maze-obstacles_977241

//Top Down
const int md = 1e9+7;
int f(int i, int j, vector<vector<int>>&mat,vector<vector<int>>&dp){
    if(i<0 || j<0 || mat[i][j]==-1) return 0;
    if(i==0 && j==0) return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    int up = f(i-1,j,mat,dp);
    int left = f(i,j-1,mat,dp);
    return dp[i][j] = (up+left)%md;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>>dp(n, vector<int>(m,-1));
    return f(n-1,m-1,mat,dp);
}

//Bottom UP
const int md = 1e9+7;
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>>dp(n, vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                dp[i][j] = 1;
                continue;
            }
            int up = 0, left = 0;
            if(mat[i][j]==-1)continue;

            if(i>0) up = dp[i-1][j]; 
            if(j>0) left = dp[i][j-1];
            dp[i][j] = (up+left)%md; 
        }
    }
    return dp[n-1][m-1];
}

//Bottom UP(Space Optimizatoin) - space -> O(number of colums)
//rowwise kaj kora space optimization er somoy
const int md = 1e9+7;
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<int>dp(m,0);
    for(int i=0;i<n;i++){
        vector<int>tmp(m,0);
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                tmp[j] = 1;
                continue;
            }
            int up = 0, left = 0;
            if(mat[i][j]==-1)continue;

            if(i>0) up = dp[j]; 
            if(j>0) left = tmp[j-1];
            tmp[j] = (up+left)%md; 
        }
        dp = tmp;
    }
    return dp[m-1];
}


//#######################################################################
//#######-------DP 10. Minimum Path Sum in Grid--------########
//Tutorial: https://takeuforward.org/data-structure/minimum-path-sum-in-a-grid-dp-10/
//Problem: https://www.naukri.com/code360/problems/minimum-path-sum_985349

//Top Down
//up and left er moddhe jeta minimum sheta choose kora
//dp te all possible ways try kortesi

#include <bits/stdc++.h> 
int inf = 1e8;
int f(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp){
    if(i==0 && j==0) return grid[i][j];
    if(i<0 || j<0) return inf;
    if(dp[i][j]!=-1) return dp[i][j];

    //solve grid, and bakita recursion e solve korar jnno pathano
    int up = grid[i][j] + f(i-1,j,grid,dp);
    int left = grid[i][j] + f(i,j-1,grid,dp);
    return dp[i][j] = min(up,left);
}
int minSumPath(vector<vector<int>> &grid) {
    int m = grid[0].size();
    int n = grid.size();
    vector<vector<int>> dp(n, vector<int>(m,-1));
    return f(n-1,m-1,grid,dp);
}


//Bottom Up
#include <bits/stdc++.h> 
int inf = 1e8;
int minSumPath(vector<vector<int>> &grid) {
    int m = grid[0].size();
    int n = grid.size();
    vector<vector<int>> dp(n, vector<int>(m,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                dp[i][j] = grid[i][j];
                continue;
            }
            int up = 0,left = 0;
            if(i>0) up = grid[i][j] + dp[i-1][j];
            else up = inf;
            if(j>0) left = grid[i][j] + dp[i][j-1];
            else left = inf;
            dp[i][j] = min(up,left);
        }
    }
    return dp[n-1][m-1];
}

//Bottom Up(space optimized)
#include <bits/stdc++.h> 
int inf = 1e8;
int minSumPath(vector<vector<int>> &grid) {
    int m = grid[0].size();
    int n = grid.size();
    vector<int> dp(m,0);
    for(int i=0;i<n;i++){
        vector<int> tmp(m,0);
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                tmp[j] = grid[i][j];
                continue;
            }
            int up = 0,left = 0;
            if(i>0) up = grid[i][j] + dp[j];//first loop e dhukbe na
            else up = inf;
            if(j>0) left = grid[i][j] + tmp[j-1];
            else left = inf;
            tmp[j] = min(up,left);
        }
        dp = tmp;
    }
    return dp[m-1];
}


//#######################################################################
//#######-------DP 11. Triangle | Fixed Starting Point and Variable Ending Point | DP on GRIDS--------########
//Tutorial: https://takeuforward.org/data-structure/minimum-path-sum-in-triangular-grid-dp-11/
//Problem: https://www.naukri.com/code360/problems/triangle_1229398


// ***** This problem has Variable Starting and Ending Points ***** ///


//Top Down (but go from down to top, it is always top down, not bottom up) -> 
//recursion is always top down

#include <bits/stdc++.h> 
int f(int i,int j,int n, vector<vector<int>>& triangle, vector<vector<int>>&dp){
	if(i==n-1) return triangle[i][j];
	if(dp[i][j]!=-1) return dp[i][j];
	int up = triangle[i][j] + f(i+1, j,n,triangle, dp);//take current + find the rest answer in vertically
	int diagonal =  triangle[i][j] + f(i+1,j+1,n,triangle,dp);
	return dp[i][j] = min(up,diagonal);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int> > dp(n, vector<int>(n,-1));
	return f(0, 0, n, triangle,dp);
}

//Bottom Up(Tabulation) ->(but do in like top down in loop) / nich theke upore uthbo
//space complexity: O(N*N)
1. solve the last index first
2. solve the rest of the index -> i+1, i+1 and j+1 indexes
3. find the minimum of places traveled
4. dp[0][0] is the answer

#include <bits/stdc++.h>
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int> > dp(n, vector<int>(n,-1));
	for(int i=n-1;i>=0;i--){
		dp[n-1][i] = triangle[n-1][i];
	}
	for(int i=n-2;i>=0;i--){
		for(int j=i;j>=0;j--){
			int up = triangle[i][j] + dp[i+1][j];
			int diagonal = triangle[i][j] + dp[i+1][j+1];//solve the position and previous positions
			dp[i][j] = min(up,diagonal);
		}
	}
	return dp[0][0];
}

//Bottom Up(Tabulation) -> space optimized

#include <bits/stdc++.h>
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<int> dp(n, -1);
	for(int i=n-1;i>=0;i--){
		dp[i] = triangle[n-1][i];
	}
	for(int i=n-2;i>=0;i--){
		vector<int> tmp(n, -1);
		for(int j=i;j>=0;j--){
			int up = triangle[i][j] + dp[j];
			int diagonal = triangle[i][j] + dp[j+1]; //solve the position and previous positions
			tmp[j] = min(up,diagonal);
		}
		dp = tmp;
	}
	return dp[0];
}


//#######################################################################
//#######-------DP 12. Minimum/Maximum Falling Path Sum | Variable Starting and Ending Points--------########
//Question Type: 1. DP on 2d grid
//Tutorial: https://takeuforward.org/data-structure/minimum-maximum-falling-path-sum-dp-12/
//Problem: https://www.naukri.com/code360/problems/maximum-path-sum-in-the-matrix_797998

//Time complexity: 3^n without dp, cause 3 recursion
//Top Down - 1
#include <bits/stdc++.h> 
int f(int i, int j, int n, int m,vector<vector<int>> &matrix, vector<vector<int>> &dp){
    if(j<0 || j==m) return -1e9;
    if(i==0)return matrix[i][j];
    if(dp[i][j]!=-1)return dp[i][j];
    //solve the position and previous positions
    int up = matrix[i][j] + f(i-1,j,n, m, matrix, dp);
    int ld = matrix[i][j] + f(i-1,j-1,n,m,matrix,dp);
    int rd = matrix[i][j] + f(i-1,j+1,n,m,matrix,dp);
    return dp[i][j] = max({up,ld,rd});
}
int getMaxPathSum(vector<vector<int>> &matrix)
{   
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    int ans = -1e9;
    //all answer is in 1st row
    for(int i=0;i<m;i++){
        //Calculate the maximum path sum for each column of row 0
        ans = max(ans,f(n-1,i,n,m,matrix,dp));
    }
    return ans;
}

//Top Down - 2
#include <bits/stdc++.h> 
int f(int i, int j, int n, int m,vector<vector<int>> &matrix, vector<vector<int>> &dp){
    if(j<0 || j>=m) return -1e9;
    if(i==n-1)return matrix[i][j];
    if(dp[i][j]!=-1)return dp[i][j];
    //solve the position and next positions
    int down = matrix[i][j] + f(i+1,j,n, m, matrix, dp);
    int ld = matrix[i][j] + f(i+1,j-1,n,m,matrix,dp);
    int rd = matrix[i][j] + f(i+1,j+1,n,m,matrix,dp);
    return dp[i][j] = max({down,ld,rd});
}
int getMaxPathSum(vector<vector<int>> &matrix)
{   
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    int ans = -1e9;
    for(int i=0;i<m;i++){
        ans = max(ans, f(0,i,n,m,matrix,dp) );
    }
    return ans;
}

//Bottom Up
#include <bits/stdc++.h>
int getMaxPathSum(vector<vector<int>> &matrix)
{   
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(int i=0;i<m;i++){
        dp[0][i] = matrix[0][i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int down = matrix[i][j], ld = matrix[i][j], rd = matrix[i][j];
            down += dp[i-1][j];
            if(j+1<m) ld +=dp[i-1][j+1];
            //outof bounds index recursion-eo same kaj korsi 
            //down jaite parbo, but diagonal gele out of bounds hoe jabe tai large negative disi
            else ld = -1e9;
            if(j)rd +=dp[i-1][j-1];
            else rd = -1e9;
            dp[i][j] = max({down,ld,rd});
        }
    }
        
    int ans = -1e9;
    for(int i=0;i<m;i++){
        ans = max(ans, dp[n-1][i]);//last ghorer prottekta column e answer thakbe, find the max one
    }
    return ans;
}

//Bottom Up(space optimized)
#include <bits/stdc++.h>
int getMaxPathSum(vector<vector<int>> &matrix)
{   
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int>dp(m,0);
    //first row manually set kora
    for(int i=0;i<m;i++){
        dp[i] = matrix[0][i];
    }
    //do dp for rest of the rows
    for(int i=1;i<n;i++){
        vector<int>tmp(m,0);
        for(int j=0;j<m;j++){
            int down = matrix[i][j], ld = matrix[i][j], rd = matrix[i][j];
            if(i) down += dp[j];
            else down = -1e9;
            if(j+1<m) ld +=dp[j+1];
            else ld = -1e9;
            if(j)rd +=dp[j-1];
            else rd = -1e9;
            tmp[j] = max({down,ld,rd});
        }
        dp = tmp;
    }
    int ans = -1e9;
    //last ghorer prottekta column e answer thakbe
    for(int i=0;i<m;i++){
        ans = max(ans, dp[i]);
    }
    return ans;
}


//#######################################################################
//#######-------DP 13. Cherry Pickup II | 3D DP Made Easy | DP On Grids--------########
//Question Type: 1. fixed starting point, variable ending point 2. DP on 3d grid
//Tutorial: https://takeuforward.org/data-structure/3-d-dp-ninja-and-his-friends-dp-13/
//Problem:  https://www.naukri.com/code360/problems/ninja-and-his-friends_3125885

//Top Down
#include <bits/stdc++.h> 
int f(int i, int j1, int j2, int n,int m,vector<vector<int>> &grid, vector<vector<vector<int>>>&dp ){
    if(j1<0 || j2<0 || j1>=m || j2>=m ) return -1e9; 
    if(i==n-1){
        if(j1==j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
    int mx = -1e9;
    for(int p=-1;p<=1;p++){
        for(int q=-1;q<=1;q++){
            int v = 0;
            if(j1==j2) v =  grid[i][j1];
            else v = grid[i][j1] + grid[i][j2];
            v+=f(i+1, j1+p, j2+q,n, m, grid, dp);//solve the rest 
            mx = max(mx, v);
        }
    }
    return dp[i][j1][j2] = mx;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>>dp(r, vector<vector<int>>(c,vector<int>(c,-1)));
    return f(0, 0, c-1, r, c, grid, dp);
}

//Bottom Up(a little confused)
#include <bits/stdc++.h> 
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>>dp(r, vector<vector<int>>(c,vector<int>(c,-1)));

    int n = r, m = c;

    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2) dp[n-1][j1][j1] =  grid[n-1][j1];
            else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
        }
    }

    for(int i=n-2;i>=0;i--){
        for(int j1=0;j1<c;j1++){
            for(int j2=0;j2<c;j2++){
                int mx = -1e9;
                for(int p=-1;p<=1;p++){
                    for(int q=-1;q<=1;q++){
                        int v = 0;
                        if(j1==j2) v =  grid[i][j1];
                        else v = grid[i][j1] + grid[i][j2];

                        if(j1+p>=m || j1+p<0 || j2+q>=m || j2+q<0 ) v = -1e8;
                        else v+=dp[i+1][j1+p][j2+q];
                        mx = max(mx, v);
                    }
                }
                dp[i][j1][j2] = mx;
            }
        }
    }
    return dp[0][0][m-1];//confused ?????
}


//Bottom Up(Space optimized)
#include <bits/stdc++.h> 
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<int>>dp(c, vector<int>(c,0));
    int n = r, m = c;

    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2) dp[j1][j1] =  grid[n-1][j1];
            else dp[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
        }
    }

    for(int i=n-2;i>=0;i--){
        vector<vector<int>>tmp(c, vector<int>(c,0));
        for(int j1=0;j1<c;j1++){
            for(int j2=0;j2<c;j2++){
                int mx = -1e9;
                for(int p=-1;p<=1;p++){
                    for(int q=-1;q<=1;q++){
                        int v = 0;
                        if(j1==j2) v =  grid[i][j1];
                        else v = grid[i][j1] + grid[i][j2];

                        if(j1+p>=m || j1+p<0 || j2+q>=m || j2+q<0 ) v = -1e8;
                        else v+=dp[j1+p][j2+q];//get the solved dp
                        mx = max(mx, v);
                    }
                }
                tmp[j1][j2] = mx;
            }
        }
        dp = tmp;
    }
    return dp[0][m-1];
}
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#####################-------DP on Subsequences/Subsets--------#########
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

- Either take it or not take it concept

int f(int i, int target, vector<int>&arr, vector<vector<int>>&dp){
    if(i==0){

    }
    int not_taken = 
    int taken = 
    if(){
        taken = 
    }
    return 
}
DP on Subsequences/Subsets Code: 
//Top Down 
#include <bits/stdc++.h> 
bool f(int i, int target, vector<int> &arr, vector<vector<int>> &dp ){
    if(target==0)return true;
    if(i==0)return (arr[0]==target);//same hoe jabe or 0 hoe jabe target
    if(dp[i][target]!=-1)return dp[i][target];
    bool not_taken = f(i-1,target,arr,dp);
    bool taken = false;
    if(arr[i]<=target){
        taken = f(i-1, target-arr[i],arr,dp);
    }
    return dp[i][target] = taken || not_taken;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n,vector<int>(k+1, -1));
    return f(n-1,k, arr, dp);
}
//Bottom Up
#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n,vector<int>(k+1, 0));
    for(int i=0;i<n;i++){
        dp[i][0] = true;
    }

    //Base case: If the first element of 'arr' is less than or equal to 'k', set prev[arr[0]] to true
    //if target is lesser than first value
    //example out of bound: if n=1,k=5,arr[0]=10, it will be out of bounds 
    if (arr[0] <= k)dp[0][arr[0]] = true;
    for(int i=1;i<n;i++){
        for(int target=1;target<=k;target++){
            bool not_taken = dp[i-1][target];
            bool taken = false;
            if(target>=arr[i]) taken = dp[i-1][target-arr[i]];
            dp[i][target] = taken || not_taken;
        }
    }
    return dp[n-1][k];
}

//#######################################################################
//#######-------DP 14. Subset Sum Equals to Target | Identify DP on Subsequences and Ways to Solve them--------########
//Question Type: DP on Subsequences, 
//Tutorial: https://takeuforward.org/data-structure/subset-sum-equal-to-target-dp-14/
//Tushar  : https://youtu.be/s6FhG--P7z0
//Problem:  https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954

//--------
//Top Down
//--------
#include <bits/stdc++.h> 
bool f(int i, int target, vector<int> &arr, vector<vector<int>> &dp ){
    if(target==0)return true;
    if(i==0)return (arr[0]==target);//same hoe jabe or 0 hoe jabe target
    if(dp[i][target]!=-1)return dp[i][target];
    bool not_taken = f(i-1,target,arr,dp);
    bool taken = false;
    if(arr[i]<=target){
        taken = f(i-1, target-arr[i],arr,dp);
    }
    return dp[i][target] = taken || not_taken;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n,vector<int>(k+1, -1));
    return f(n-1,k, arr, dp);
}
//--------
//Bottom Up
//--------
#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n,vector<int>(k+1, 0));
    for(int i=0;i<n;i++){
        dp[i][0] = true;
    }

    //Base case: If the first element of 'arr' is less than or equal to 'k', set prev[arr[0]] to true
    //if target is lesser than first value
    //example out of bound: if n=1,k=5,arr[0]=10, it will be out of bounds 
    if (arr[0] <= k)dp[0][arr[0]] = true;
    for(int i=1;i<n;i++){
        for(int target=1;target<=k;target++){
            bool not_taken = dp[i-1][target];
            bool taken = false;
            if(target>=arr[i]) taken = dp[i-1][target-arr[i]];
            dp[i][target] = taken || not_taken;
        }
    }
    return dp[n-1][k];
}
//--------
//Bottom Up(space optimized)
//--------
#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<int>prev(k+1,0);
    prev[0] = true;
    //k is the target, prev and cur is working with target only here
    if (arr[0] <= k)prev[arr[0]] = true;
    for(int i=1;i<n;i++){
        vector<int>cur(k+1,0);
        cur[0] = true;
        for(int target=1;target<=k;target++){
            bool not_taken = prev[target];
            bool taken = false;
            if(target>=arr[i]) taken = prev[target-arr[i]];
            cur[target] = taken || not_taken;
        }
        prev = cur;
    }
    return prev[k];
}


//#######################################################################
//#######-------DP 15. Partition Equal Subset Sum | DP on Subsequences--------########
//Question Type: DP on Subsequences, 
//Tutorial: https://takeuforward.org/data-structure/partition-equal-subset-sum-dp-15/
//Problem:  https://www.naukri.com/code360/problems/partition-equal-subset-sum_892980

//--------
//Top Down
//--------
bool f(int ind, int target, vector<int> &arr,vector<vector<int>> &dp){
	if(target==0) return true;
	if(ind == 0) return arr[ind] == target;
	if(dp[ind][target]!=-1) return dp[ind][target];

	bool not_taken = f(ind-1, target, arr,dp);
	bool taken = false;
	if(arr[ind]<=target){
		taken = f(ind-1, target-arr[ind], arr, dp);
	}
	return dp[ind][target] = taken || not_taken;
}

bool canPartition(vector<int> &arr, int n)
{
	int sum = 0;
	for(auto x: arr) sum+=x;
	if(sum%2) return false;
	else{
		int target = sum/2;
		vector<vector<int>> dp(n, vector<int>(target+1, -1));
		return f(n-1, target, arr, dp);
	}
}

//--------
//Bottom Up
//--------
bool canPartition(vector<int> &arr, int n)
{
	int sum = 0;
	for(auto x: arr) sum+=x;
	if(sum%2) return false;
	else{
		int target = sum/2;
		vector<vector<int>> dp(n, vector<int>(target+1, 0));
		for(int ind=0;ind<n;ind++){
			dp[ind][0] = true;
		}
        if (arr[0] <= target) dp[0][arr[0]] = true;

		for(int ind=1;ind<n;ind++){
			for(int t=1;t<=target;t++){
				bool not_taken = dp[ind-1][t];
				bool taken = false;
				if(arr[ind]<=t){
					taken = dp[ind-1][t-arr[ind]];
				}
				dp[ind][t] = taken || not_taken;
			}
		}
		return dp[n-1][target];
	}
}



//--------
//Bottom Up(Space optimized)
//--------
bool canPartition(vector<int> &arr, int n)
{
	int sum = 0;
	for(auto x: arr) sum+=x;
	if(sum%2) return false;
	else{
		int target = sum/2;
		vector<int> prev(target+1, 0), cur(target+1,0);
		prev[0] = true;
		cur[0] = true;
        if (arr[0] <= target) prev[arr[0]] = true;

		for(int ind=1;ind<n;ind++){
			for(int t=1;t<=target;t++){
				bool not_taken = prev[t];
				bool taken = false;
				if(arr[ind]<=t){
					taken = prev[t-arr[ind]];
				}
				cur[t] = taken || not_taken;
			}
			prev = cur;
		}
		return cur[target];
	}
}


//#######################################################################
//#######-------Dp 16. Partition A Set Into Two Subsets With Minimum Absolute Sum Difference | DP on Subsequences--------########
//Question Type: DP on Subsequences, 
//Tutorial: https://takeuforward.org/data-structure/partition-set-into-2-subsets-with-min-absolute-sum-diff-dp-16/
//Problem:  https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494

------------
Approach:
1. Generate the whole dp from dp[0][0] to dp[n-1][target] (target sum concept)
2. The answer lies in dp[n-1][0] to dp[n-1][target], get the minimum from there, Going till half is enough
------------

//--------
//Top Down
//--------

bool f(int i, int target, vector<int> &arr, vector<vector<int>> &dp ){
    if(target==0)return true;
    if(i==0)return (arr[0]==target);
    if(dp[i][target]!=-1)return dp[i][target];
    bool not_taken = f(i-1,target,arr,dp);
    bool taken = false;
    if(arr[i]<=target){
        taken = f(i-1, target-arr[i],arr,dp);
    }
    return dp[i][target] = taken || not_taken;
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum = 0;
	for(auto x: arr) sum+=x;
	int k = sum;

	vector<vector<int>>dp(n,vector<int>(k+1, -1));
	//solve the answer for all 0 to target values
	for(int i=0;i<=k;i++) f(n-1,i, arr, dp);
	
	int ans = 1e9;
	for(int i=0;i<=k;i++){//Getting WA for k/2 on top down approach.
		if(dp[n-1][i]==1)ans = min(ans,abs(i - (sum-i)) );
	}
	return ans;

}


//--------
//Bottom Up
//--------
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum = 0;
	for(auto x: arr) sum+=x;
	int k = sum;
	vector<vector<int>>dp(n,vector<int>(k+1, 0));
	for(int i=0;i<n;i++){
        dp[i][0] = true;
    }

	if (arr[0] <= k)dp[0][arr[0]] = true;
    for(int i=1;i<n;i++){
        for(int target=1;target<=k;target++){
            bool not_taken = dp[i-1][target];
            bool taken = false;
            if(target>=arr[i]) taken = dp[i-1][target-arr[i]];
            dp[i][target] = taken || not_taken;
        }
    }

	int ans = 1e9;
	for(int i=0;i<=k/2;i++){
		if(dp[n-1][i]==1)ans = min(ans,abs(i - (sum-i)) );
	}
	return ans;
}

//--------
//Bottom Up(Space optimized)
//--------
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum = 0;
	for(auto x: arr) sum+=x;
	int target = sum;
	vector<int> prev(target+1, 0), cur(target+1,0);
	prev[0] = true;
	cur[0] = true;
	if (arr[0] <= target) prev[arr[0]] = true;

	for(int ind=1;ind<n;ind++){
		for(int t=1;t<=target;t++){
			bool not_taken = prev[t];
			bool taken = false;
			if(arr[ind]<=t){
				taken = prev[t-arr[ind]];
			}
			cur[t] = taken || not_taken;
		}
		prev = cur;
	}

    //this is the main part of this problem
	int ans = 1e9;
	for(int i=0;i<=target/2;i++){
		if(prev[i]==1)ans = min(ans,abs(i - (sum-i)) );
	}
	return ans;
}


//#######################################################################
//#######-------DP 17. Counts Subsets with Sum K | Dp on Subsequences--------########
//Question Type: DP on Subsequences, 
//Tutorial: https://takeuforward.org/data-structure/count-subsets-with-sum-k-dp-17/
//Problem:  https://www.naukri.com/code360/problems/number-of-subsets_3952532

FOR ALL THE COUNT PROBLEMS:
if the condition is satisfied return 1, else return 0
- To explore all the paths, best way is to do recursion, that is why we are using recursion
------
for handling the cases in which the array contains 0 --> 
use only one base condition -->
if(ind < 0) return tar == 0;

or you can use--> 
if(ind == 0){
         if(num[0] == 0 && tar == 0) return 2;
         if(num[0] == tar || tar == 0) return 1;
         return 0;
   }
-----

//--------
//Top Down(HANDLE 0 case, getting wa)
//--------

const int md = 1e9+7;
int f(int i, int target,vector<int>& arr,  vector<vector<int>>&dp){
	if(i==0){
		if(target==0 && arr[i]==0) return 2;
		else if(target==arr[i] || target==0) return 1;
		else return 0;
	}
	if(dp[i][target]!=-1)return dp[i][target];
	int not_taken = f(i-1, target, arr, dp);
	int taken = 0;
	if(arr[i]<=target){
		taken = f(i-1, target-arr[i], arr, dp);
	}
	return dp[i][target] = (taken + not_taken)%md;
}
int findWays(vector<int>& arr, int k)
{	
	int n = arr.size();
	vector<vector<int>>dp(n, vector<int>(k+1, -1));
	return f(n-1, k, arr, dp);
}


//---------
//Bottom Up
//---------

const int md = 1e9+7;
int findWays(vector<int>& arr, int k)
{	
	int n = arr.size();
	vector<vector<int>>dp(n, vector<int>(k+1, 0));
	if(arr[0] == 0) dp[0][0] = 2;  // 2 cases -pick and not pick
    else dp[0][0] = 1;  // 1 case - not pick
    if(arr[0]!=0 && arr[0]<=k) dp[0][arr[0]] = 1;  // 1 case -pick

	for(int i=1;i<n;i++){
		for(int t=0;t<=k;t++){
			int not_taken = dp[i-1][t];
			int taken = 0;
			if(arr[i]<=t){
				taken = dp[i-1][t-arr[i]];
			}
			dp[i][t] = (taken + not_taken)%md;
		}
	}
	return dp[n-1][k];
}

//---------
//Bottom Up(Space optimized)
//---------


//#######################################################################
//#######-------DP 18. Count Partitions With Given Difference | Dp on Subsequences--------########
//Question Type: DP on Subsequences, 
//Tutorial: https://takeuforward.org/data-structure/count-partitions-with-given-difference-dp-18/
//Problem:  https://www.naukri.com/code360/problems/partitions-with-given-difference_3751628

------------
Approach:
(this is just dp 17 with modified target)
1. count the subsets where sum is equal to , s2 = (tot - d)/2;
2. 2 ta ghor fillup kora first row er(what if there is 0 in arr[0])
------------

//---------
//Top Down
//---------

const int md = 1e9+7;
int f(int i, int target,vector<int> &arr, vector<vector<int>>&dp ){
    if(i==0){
		if(target==0 && arr[i]==0) return 2;
		else if(target==arr[i] || target==0) return 1;
		else return 0;
	}
	if(dp[i][target]!=-1)return dp[i][target];
	int not_taken = f(i-1, target, arr, dp);
	int taken = 0;
	if(arr[i]<=target){
		taken = f(i-1, target-arr[i], arr, dp);
	}
	return dp[i][target] = (taken + not_taken)%md;
}

int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0;
    for(auto x: arr)sum+=x;
    int target = (sum-d);
    //target%2 -> s2/target er value decimal hoite parbe na
    if(target<0 || target%2) return 0;
    target/=2;
    vector<vector<int>>dp(n, vector<int>(target+1,-1));
    return f(n-1,target, arr,dp);
}

//---------
//Bottom Up
//---------
const int md = 1e9+7;
int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0;
    for(auto x: arr)sum+=x;
    int target = (sum-d);
    if(target<0 || target%2) return 0;
    target/=2;
    vector<vector<int>>dp(n, vector<int>(target+1,0));
    
    //2 ta ghor fillup kora first row er
    if(arr[0]==0) dp[0][0] = 2;
    else dp[0][0] = 1;
    if(arr[0]!=0 && arr[0]<=target) dp[0][arr[0]] = 1;

    for(int i=1;i<n;i++){
        for(int t=0;t<=target;t++){
            int not_taken = dp[i-1][t];
            int taken = 0;
            if(arr[i]<=t){
                taken = dp[i-1][t-arr[i]];
            }
            dp[i][t] = (taken + not_taken)%md;
        }
    }

    return dp[n-1][target];
}
//---------
//Bottom Up(Space optimized)
//---------
const int md = 1e9+7;
int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0;
    for(auto x: arr)sum+=x;
    int target = (sum-d);
    if(target<0 || target%2) return 0;
    target/=2;
    vector<int>prev(target+1),cur(target+1);

    if(arr[0]==0) prev[0] = 2;
    else prev[0] = 1;
    if(arr[0]!=0 && arr[0]<=target) prev[arr[0]] = 1;


    for(int i=1;i<n;i++){
        for(int t=0;t<=target;t++){
            int not_taken = prev[t];
            int taken = 0;
            if(arr[i]<=t){
                taken = prev[t-arr[i]];
            }
            cur[t] = (taken + not_taken)%md;
        }
        prev = cur;
    }

    return prev[target];
}

//#######################################################################
//#######-------DP 19. 0/1 Knapsack | Recursion to Single Array Space Optimised Approach--------########
//Question Type: DP on Subsequences, 
//Tutorial: https://takeuforward.org/data-structure/0-1-knapsack-dp-19/
//Problem:  https://www.naukri.com/code360/problems/0-1-knapsack_920542
- When there is no uniformity, you cannot apply greedy
- Think base case as a single element

//---------
//Top Down
//---------
#include <bits/stdc++.h> 
int f(int i, int w, vector<int> wg, vector<int> vl, vector<vector<int>>&dp){
	if(i==0){
		if(wg[i]<=w) return vl[i];
		else return 0;
	}
	if(dp[i][w]!=-1) return dp[i][w];
	int not_taken = 0 + f(i-1, w, wg, vl, dp);
	int taken = 0;
	if(wg[i]<=w){
		taken = vl[i]+ f(i-1, w-wg[i], wg, vl, dp);
	}
	return dp[i][w] = max(taken , not_taken);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n, vector<int>(maxWeight+1,-1));
	return f(n-1, maxWeight, weight, value, dp);
}

//---------
//Bottom Up
//---------

#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n, vector<int>(maxWeight+1,0));
	for(int i=0;i<n;i++) dp[i][0] = 0;
	for(int i=1;i<=maxWeight;i++){
		if(i>=weight[0]) dp[0][i] = value[0];
		else dp[0][i] = 0;
	}

	for(int i=1;i<n;i++){
		for(int w=1;w<=maxWeight;w++){
			int not_taken = 0 + dp[i-1][w];
			int taken = 0;
			if(weight[i]<=w){
				taken = value[i]+ dp[i-1][w-weight[i]];
			}
			dp[i][w] = max(taken , not_taken);
		}
	}
	return dp[n-1][maxWeight];
}


//---------
//Bottom Up(Space optimized)
//---------
#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int>prev(maxWeight+1,0), cur(maxWeight+1,0);
	for(int i=weight[0];i<=maxWeight;i++){
		prev[i] = value[0];
	}

	for(int i=1;i<n;i++){
		for(int w=1;w<=maxWeight;w++){
			int not_taken = 0 + prev[w];
			int taken = 0;
			if(weight[i]<=w){
				taken = value[i]+ prev[w-weight[i]];
			}
			cur[w] = max(taken , not_taken);
		}
		prev = cur;
	}
	return prev[maxWeight];
}

//---------
//Bottom Up(Space optimized, without cur array, 1 array optimization)
//---------

#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int>prev(maxWeight+1,0);
	for(int i=weight[0];i<=maxWeight;i++){
		prev[i] = value[0];
	}

	for(int i=1;i<n;i++){
		for(int w=maxWeight;w>=1;w--){
			int not_taken = 0 + prev[w];
			int taken = 0;
			if(weight[i]<=w){
				taken = value[i]+ prev[w-weight[i]];
			}
			prev[w] = max(taken , not_taken);
		}
	}
	return prev[maxWeight];
}

//#######################################################################
//#######-------DP 20. Minimum Coins | DP on Subsequences | Infinite Supplies Pattern--------########
//Question Type: DP on Subsequences, 
//Tutorial: https://takeuforward.org/data-structure/minimum-coins-dp-20/
//Problem:  https://www.naukri.com/code360/problems/minimum-elements_3843091
- when find minimum apply INT_MAX to not consider it
- when find maximum apply INT_MIN to not consider it
- Infinite supply, multiple use -> take is always will be in that index
- Time complexity in recursion - >>O(2^n)

//---------
//Top Down
//---------

#include <bits/stdc++.h> 
int f(int i, int target, vector<int> &num, vector<vector<int>>&dp ){
    if(i==0){
        if(target%num[i]==0) return target/num[i];
        else return 1e9;
    }
    if(dp[i][target]!=-1) return dp[i][target];
    int not_taken = f(i-1, target, num, dp);
    int taken = 1e9;//confuse
    if(num[i]<=target){
        taken = 1 + f(i, target-num[i], num, dp);//confuse
    }
    return dp[i][target] = min(not_taken , taken);
}
int minimumElements(vector<int> &num, int x)
{  
    int n = num.size();
    vector<vector<int>>dp(n, vector<int>(x+1,-1));
    int ans = f(n-1, x, num, dp);
    if(ans>=1e9) return -1;
    return ans;
}

//---------
//Bottom Up
//---------
#include <bits/stdc++.h> 
int minimumElements(vector<int> &num, int x)
{  
    int n = num.size();
    vector<vector<int>>dp(n, vector<int>(x+1,0));

    for(int i=1;i<=x;i++){
        if(i%num[0]==0)dp[0][i] = i/num[0];
        else dp[0][i] = 1e9;
    }
    for(int i=1;i<n;i++){
        for(int t=1;t<=x;t++){
            int not_taken = dp[i-1][t];//uporer ta
            int taken = 1e9;//current row ta
            if(num[i]<=t){
                taken = 1 + dp[i][t-num[i]];
            }
            dp[i][t] = min(taken, not_taken);
        }
    }
    int ans = dp[n-1][x];
    if(ans>=1e9) return -1;
    return ans;
}

//---------
//Bottom Up(Space optimized)
//---------
#include <bits/stdc++.h> 
int minimumElements(vector<int> &num, int x)
{  
    int n = num.size();
    vector<int>prev(x+1,0),cur(x+1,0);

    for(int i=1;i<=x;i++){
        if(i%num[0]==0)prev[i] = i/num[0];
        else prev[i] = 1e9;
    }
    for(int i=1;i<n;i++){
        for(int t=1;t<=x;t++){
            int not_taken = prev[t];
            int taken = 1e9;
            if(num[i]<=t){
                taken = 1 + cur[t-num[i]];
            }
            cur[t] = min(taken, not_taken);
        }
        prev = cur;
    }
    int ans = prev[x];
    if(ans>=1e9) return -1;
    return ans;
}

//#######################################################################
//#######-------DP 21. Target Sum | DP on Subsequences--------########
//Question Type: DP on Subsequences, 
//Tutorial: https://takeuforward.org/data-structure/target-sum-dp-21/
//Problem:  https://www.naukri.com/code360/problems/target-sum_4127362

Same as DP 18. Count Partitions With Given Difference

//---------
//Top Down
//---------
#include <bits/stdc++.h> 

int f(int i, int target,vector<int> &arr, vector<vector<int>>&dp ){
    if(i==0){
		if(target==0 && arr[i]==0) return 2;
		else if(target==arr[i] || target==0) return 1;
		else return 0;
	}
	if(dp[i][target]!=-1)return dp[i][target];
	int not_taken = f(i-1, target, arr, dp);
	int taken = 0;
	if(arr[i]<=target){
		taken = f(i-1, target-arr[i], arr, dp);
	}
	return dp[i][target] = (taken + not_taken);
}

int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0;
    for(auto x: arr)sum+=x;
    int target = (sum-d);
    if(target<0 || target%2) return 0;
    target/=2;
    vector<vector<int>>dp(n, vector<int>(target+1,-1));
    return f(n-1,target, arr,dp);
}

int targetSum(int n, int target, vector<int>& arr) {
    return countPartitions(n, target, arr);
}

//---------
//Bottom Up
//---------
Same as DP 18.
//---------
//Bottom Up(Space optimized)
//---------
Same as DP 18.

//#######################################################################
//#######-------DP 22. Coin Change 2 | Infinite Supply Problems--------########
//Question Type: DP on Subsequences, 
//Tutorial: https://takeuforward.org/data-structure/coin-change-2-dp-22/
//Problem:  https://www.naukri.com/code360/problems/ways-to-make-coin-change_630471

Recursion time complexity for this: more than 2^n

//---------
//Top Down
//---------
#include <bits/stdc++.h> 
long f(int i, int target, int *arr, vector<vector<long>>&dp){
    if(i==0){
        if(target%arr[0]==0) return 1;//last e jodi 1 or emn value thake
        else return 0;
    }
    if(dp[i][target]!=-1) return dp[i][target];
    long not_taken = f(i-1,target,arr,dp);
    long taken = 0;
    if(arr[i]<=target){
        taken = f(i, target-arr[i],arr, dp);
    }
    return dp[i][target] = taken + not_taken;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>>dp(n, vector<long>(value+1, -1));
    return f(n-1, value,denominations, dp);
}
//---------
//Bottom Up
//---------
#include <bits/stdc++.h> 
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>>dp(n, vector<long>(value+1, 0));
    for(int i=1;i<=value;i++) if(i%denominations[0]==0)dp[0][i] = 1;
    //if cannot select any that is one way
    for(int i=0;i<n;i++)dp[i][0] = 1;
    for(int i=1;i<n;i++){
        for(int t=1;t<=value;t++){
            long not_taken = dp[i-1][t];
            long taken = 0;
            if(denominations[i]<=t){
                taken = dp[i][t-denominations[i]];
            }
            dp[i][t] = taken + not_taken;
        }
    }
    return dp[n-1][value];
}

//---------
//Bottom Up(Space optimized)
//---------
#include <bits/stdc++.h> 
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<long>prev(value+1, 0), cur(value+1,0);
    for(int i=1;i<=value;i++) if(i%denominations[0]==0)prev[i] = 1;
    //if cannot select any that is one way
    prev[0] = cur[0] = 1;
    for(int i=1;i<n;i++){
        for(int t=1;t<=value;t++){
            long not_taken = prev[t];
            long taken = 0;
            if(denominations[i]<=t){
                taken = cur[t-denominations[i]];
            }
            cur[t] = taken + not_taken;
        }
        prev = cur;
    }
    return prev[value];
}


//---------
//Bottom Up(Space optimized) - 1d array
//---------
#include <bits/stdc++.h> 
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<long>prev(value+1, 0);
    for(int i=1;i<=value;i++) if(i%denominations[0]==0)prev[i] = 1;
    //if cannot select any that is one way
    prev[0] = 1;
    for(int i=1;i<n;i++){
        for(int t=1;t<=value;t++){
            long not_taken = prev[t];
            long taken = 0;
            if(denominations[i]<=t){
                taken = prev[t-denominations[i]];
            }
            prev[t] = taken + not_taken;
        }
    }
    return prev[value];
}



//#######################################################################
//#######-------DP 23. Unbounded Knapsack | 1-D Array Space Optimised Approach--------########
//Question Type: DP on Subsequences, 
//Tutorial: https://takeuforward.org/data-structure/unbounded-knapsack-dp-23/
//Problem:  https://www.naukri.com/code360/problems/unbounded-knapsack_1215029

Unbounded - multiple time taking allowed(infinite supply)
bounded - multiple time taking not allowed
- when there is infinite supply it will always be in that index

//---------
//Top Down
//---------

int f(int i, int w, vector<int> &profit, vector<int> &weight,vector<vector<int>>&dp){
    if(i==0){
        return (w/weight[i])*profit[i];
    }
    if(dp[i][w]!=-1) return dp[i][w];
    int not_taken = f(i-1, w, profit, weight,dp);
    int taken = 0;
    if(weight[i]<=w){
        taken = profit[i] + f(i, w-weight[i], profit, weight,dp);
    }
    return dp[i][w] = max(not_taken, taken);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>>dp(n, vector<int>(w+1,-1));
    return f(n-1, w, profit, weight,dp);
}

//---------
//Bottom Up
//---------
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>>dp(n, vector<int>(w+1,0));
    for(int i=0;i<=w;i++) dp[0][i] = (i/weight[0])*profit[0];
    for(int i=1;i<n;i++){
        for(int wg=1;wg<=w;wg++){
            int not_taken = dp[i-1][wg];
            int taken = 0;
            if(weight[i]<=wg){
                taken = profit[i] + dp[i][wg-weight[i]];
            }
            dp[i][wg] = max(not_taken, taken);
        }
    }
    return dp[n-1][w];
}
//---------
//Bottom Up(Space optimized)
//---------
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<int>prev(w+1,0), cur(w+1,0);
    for(int i=0;i<=w;i++) prev[i] = (i/weight[0])*profit[0];
    for(int i=1;i<n;i++){
        for(int wg=1;wg<=w;wg++){
            int not_taken = prev[wg];
            int taken = 0;
            if(weight[i]<=wg){
                taken = profit[i] + cur[wg-weight[i]];
            }
            cur[wg] = max(not_taken, taken);
        }
        prev = cur;
    }
    return prev[w];
}

//---------
//Bottom Up(Space optimized) - one 1d array
- Because we only need current top element, and current-thatelement value
//---------
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<int>prev(w+1,0);
    for(int i=0;i<=w;i++) prev[i] = (i/weight[0])*profit[0];
    for(int i=1;i<n;i++){
        for(int wg=1;wg<=w;wg++){
            int not_taken = prev[wg];
            int taken = 0;
            if(weight[i]<=wg){
                taken = profit[i] + prev[wg-weight[i]];
            }
            prev[wg] = max(not_taken, taken);
        }
    }
    return prev[w];
}

//#######################################################################
//#######-------DP 24. Rod Cutting Problem | 1D Array Space Optimised Approach--------########
//Question Type: DP on Subsequences, 
//Tutorial: https://takeuforward.org/data-structure/rod-cutting-problem-dp-24/
//Problem:  https://www.naukri.com/code360/problems/rod-cutting-problem_800284

//---------
//Top Down
//---------
int f(int i, int target, vector<int> &price,vector<vector<int>>&dp){
	if(i==0){
		return target*price[0];
	}
	if(dp[i][target]!=-1) return dp[i][target];
	int not_taken = f(i-1,target, price, dp);
	int taken = 0;
	int rd = i+1;
	if(rd<=target){
		taken = price[i] + f(i,target-rd, price, dp);
	}
	return dp[i][target] = max(taken, not_taken);
}
int cutRod(vector<int> &price, int n)
{	
	vector<vector<int>>dp(n,vector<int>(n+1,-1));
	return f(n-1, n, price,dp);
}

//---------
//Bottom Up
//---------
int cutRod(vector<int> &price, int n)
{	
	vector<vector<int>>dp(n,vector<int>(n+1,0));
	for(int i=0;i<=n;i++){
		dp[0][i] = i*price[0];
	}
	for(int i=1;i<n;i++){
		for(int t=1;t<=n;t++){
			int not_taken = dp[i-1][t];
			int taken = 0;
			int rd = i+1;
			if(rd<=t){
				taken = price[i] + dp[i][t-rd];
			}
			dp[i][t] = max(taken, not_taken);
		}
	}
	return dp[n-1][n];
}
//---------
//Bottom Up(Space optimized) - one 1d array
//---------

- We donot need 2 array in unbounded knapsack type problems, we can space optimize with 1 array only

int cutRod(vector<int> &price, int n)
{	
	vector<int>prev(n+1,0);
	for(int i=0;i<=n;i++){
		prev[i] = i*price[0];
	}
	for(int i=1;i<n;i++){
		for(int t=1;t<=n;t++){
			int not_taken = prev[t];
			int taken = 0;
			int rd = i+1;
			if(rd<=t){
				taken = price[i] + prev[t-rd];
			}
			prev[t] = max(taken, not_taken);
		}
	}
	return prev[n];
}


//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#####################-------DP on Strings--------######################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

Problems on this 
- Comparision 
- Replacement 
- edit

DP on strings concepts: Dp 25. Longest Common Subsequence, DP 32. Distinct Subsequences[Those 2 videos are most important]

- There is not dp[-1] index, not possible in c++
- For string related dp problem, when doing tabulation think about empty sequence also

DP ON Strings Code:

//Top Down
#include<bits/stdc++.h>
int f(int i, int j, string&s, string&t, vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j]){
        return dp[i][j] = 1 + f(i-1,j-1,s,t,dp);
    }
    return dp[i][j] = max(f(i-1,j,s,t,dp), f(i,j-1,s,t,dp));
}

int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n, vector<int>(m,-1));
	return f(n-1, m-1, s, t, dp);
}

//Bottom Up
#include<bits/stdc++.h>
int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
	return dp[n][m];
}

//#######################################################################
//#######-------Dp 25. Longest Common Subsequence --------########
//Question Type: DP on Strings, 
//Tutorial: https://takeuforward.org/data-structure/longest-common-subsequence-dp-25/
//BOTTOM UP: https://youtu.be/NnD96abizww?list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr
//Problem:  https://www.naukri.com/code360/problems/longest-common-subsequence_624879

Sequence: maintains order

//---------
//Top Down
//---------

#include<bits/stdc++.h>
int f(int i, int j, string s, string t, vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j]){
        return dp[i][j] = 1 + f(i-1,j-1,s,t,dp);
    }
    return dp[i][j] = max(f(i-1,j,s,t,dp), f(i,j-1,s,t,dp));
}

int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n, vector<int>(m,-1));
	return f(n-1, m-1, s, t, dp);
}


////////Both if else statement in return 
#include<bits/stdc++.h>
int f(int i, int j, string s, string t, vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j]){
        return dp[i][j] = 1 + f(i-1,j-1,s,t,dp);
    }
    else return dp[i][j] = max(f(i-1,j,s,t,dp), f(i,j-1,s,t,dp));
}

int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n, vector<int>(m,-1));
	return f(n-1, m-1, s, t, dp);
}

//---------
//Bottom Up
//---------

#include<bits/stdc++.h>
int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
	return dp[n][m];
}

//---------
//Bottom Up(Space optimized)
//---------
#include<bits/stdc++.h>
int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<int>prev(m+1), cur(m+1);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                cur[j] = 1 + prev[j-1];
            }
            else cur[j] = max(prev[j], cur[j-1]);
        }
        prev = cur;
    }
	return prev[m];
}


//#######################################################################
//#######-------DP 26. Print Longest Common Subsequence | Dp on Strings--------########
//Question Type: DP on Strings, 
//Tutorial: https://takeuforward.org/data-structure/print-longest-common-subsequence-dp-26/
//Problem:  https://www.naukri.com/code360/problems/longest-common-subsequence_624879

- If there are multiple answers, you cannot apply using a dp table, but for this you can

//---------
//Bottom Up(just prints the sequence)
//---------

adebc
dcadb
->adb 

Time complexity: worst case O(n+m), best case O(n)

//Full Code Printing Longest Common Subsequence 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int index = dp[n][m];
	vector<char>ans(index, 0);

    int i = n, j = m;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            ans[index-1] = s[i-1];
            i--;
            j--;
            index--;
        }
        else{
            if(dp[i][j-1]>dp[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }
    }

    for(auto x: ans) cout<<x;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--)lcs("adebc","dcadb");
    return 0;
}

//#######################################################################
//#######-------DP 27. Longest Common Substring | DP on Strings--------########
//Question Type: DP on Strings, 
//Tutorial: https://takeuforward.org/data-structure/longest-common-substring-dp-27/
//Tutorial 2: https://www.geeksforgeeks.org/longest-common-substring-dp-29/
//Problem:  https://www.naukri.com/code360/problems/longest-common-substring_1235207

- Since, this is consecutive you are not dependant on the previous guy

//---------
//Top Down
//---------

NOT SURE??????

//---------
//Bottom Up
//---------
int lcs(string &str1, string &str2){
    int n = str1.size(), m = str2.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1));
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
        }
    }
    return ans;
}
//---------
//Bottom Up(Space optimized)
//---------

int lcs(string &str1, string &str2){
    int n = str1.size(), m = str2.size();
    vector<int>prev(m+1), cur(m+1);
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
                cur[j] = 1 + prev[j-1];
                ans = max(ans, cur[j]);
            }
            else cur[j] = 0;
        }
        prev = cur;
    }
    return ans;
}

//---------
//Bottom Up(Space optimized) - 1d array only ones
//---------

int lcs(string &str1, string &str2){
    int n = str1.size(), m = str2.size();
    vector<int>prev(m+1);
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=m;j>0;j--){
            if(str1[i-1]==str2[j-1]){
                prev[j] = 1 + prev[j-1];
                ans = max(ans, prev[j]);
            }
            else prev[j] = 0;
        }
    }
    return ans;
}

//#######################################################################
//#######-------DP 28. Longest Palindromic Subsequence--------########
//Question Type: DP on Strings, 
//Tutorial: https://takeuforward.org/data-structure/longest-palindromic-subsequence-dp-28/
//Problem:  https://www.naukri.com/code360/problems/longest-palindromic-subsequence_842787

- This is just an extension of longtest common subsequence
- Just reverse the string and find the longest common subsequence

string s1 = "bbabcbcab";
string s2 = s1;
reverse(s2.begin(),s2.end());
while(t--) lcs(s1,s2);



//---------
//Top Down
//---------

Top down approach of longest common subsequence where s1 = string and s2 = reverse(s1);

#include <bits/stdc++.h> 
int f(int i, int j, string s, string t, vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j]){
        return dp[i][j] = 1 + f(i-1,j-1,s,t,dp);
    }
    return dp[i][j] = max(f(i-1,j,s,t,dp), f(i,j-1,s,t,dp));
}

int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n, vector<int>(m,-1));
	return f(n-1, m-1, s, t, dp);
}

int longestPalindromeSubsequence(string s)
{   
    string s1 = s;
    reverse(s.begin(),s.end());
    string s2 = s;
    return lcs(s1,s2);
}

//---------
//Bottom Up
//---------

Bottom Up approach of longest common subsequence where s1 = string and s2 = reverse(s1); 

#include <bits/stdc++.h> 
int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
	return dp[n][m];
}

int longestPalindromeSubsequence(string s)
{   
    string s1 = s;
    reverse(s.begin(),s.end());
    string s2 = s;
    return lcs(s1,s2);
}


//---------
//Bottom Up(Space optimized)
//---------
Bottom Up(Space optimized) approach of longest common subsequence where s1 = string and s2 = reverse(s1);

#include <bits/stdc++.h> 
int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<int>prev(m+1), cur(m+1);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                cur[j] = 1 + prev[j-1];
            }
            else cur[j] = max(prev[j], cur[j-1]);
        }
        prev = cur;
    }
	return prev[m];
}

int longestPalindromeSubsequence(string s)
{   
    string s1 = s;
    reverse(s.begin(),s.end());
    string s2 = s;
    return lcs(s1,s2);
}

//FULL CODE - Printing Longest Palindromic Subsequence

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int index = dp[n][m];
	vector<char>ans(index, 0);

    int i = n, j = m;
    while(i>0 && j>0){
        //If same diagonally then only go!
        if(s[i-1]==t[j-1]){
            ans[index-1] = s[i-1];
            i--;
            j--;
            index--;
        }
        else{
            if(dp[i][j-1]>dp[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }
    }

    for(auto x: ans) cout<<x;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    string s1 = "bbabcbcab";
    string s2 = s1;
    reverse(s2.begin(),s2.end());

    while(t--)lcs(s1,s2);
    return 0;
}

//#######################################################################
//#######-------DP 29. Minimum Insertions to Make String Palindrome--------########
//Question Type: DP on Strings, 
//Tutorial: https://takeuforward.org/data-structure/minimum-insertions-to-make-string-palindrome-dp-29/
//Problem:  https://www.naukri.com/code360/problems/minimum-insertions-to-make-palindrome_985293

------------
Approach:
Longest Palindromic Subsequence and n - Longest Palindromic Subsequence
------------
//---------
//Top Down
//---------

Top Down of Longest Palindromic Subsequence and n - Longest Palindromic Subsequence;

int f(int i, int j, string s, string t, vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j]){
        return dp[i][j] = 1 + f(i-1,j-1,s,t,dp);
    }
    return dp[i][j] = max(f(i-1,j,s,t,dp), f(i,j-1,s,t,dp));
}

int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n, vector<int>(m,-1));
	return f(n-1, m-1, s, t, dp);
}

int longestPalindromeSubsequence(string s)
{   
    string s1 = s;
    reverse(s.begin(),s.end());
    string s2 = s;
    return lcs(s1,s2);
}
int minimumInsertions(string &str)
{
	return str.size() - longestPalindromeSubsequence(str);
}

//---------
//Bottom Up
//---------

Bottom Up of Longest Palindromic Subsequence and n - Longest Palindromic Subsequence;

int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
	return dp[n][m];
}

int longestPalindromeSubsequence(string s)
{   
    string s1 = s;
    reverse(s.begin(),s.end());
    string s2 = s;
    return lcs(s1,s2);
}
int minimumInsertions(string &str)
{
	return str.size() - longestPalindromeSubsequence(str);
}


//---------
//Bottom Up(Space optimized)
//---------

Bottom Up(Space optimized) of Longest Palindromic Subsequence and n - Longest Palindromic Subsequence;

int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<int>prev(m+1), cur(m+1);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                cur[j] = 1 + prev[j-1];
            }
            else cur[j] = max(prev[j], cur[j-1]);
        }
        prev = cur;
    }
	return prev[m];
}

int longestPalindromeSubsequence(string s)
{   
    string s1 = s;
    reverse(s.begin(),s.end());
    string s2 = s;
    return lcs(s1,s2);
}
int minimumInsertions(string &str)
{
	return str.size() - longestPalindromeSubsequence(str);
}


//#######################################################################
//#######-------DP 30. Minimum Insertions/Deletions to Convert String A to String B--------########
//Question Type: DP on Strings, 
//Tutorial: https://takeuforward.org/data-structure/minimum-insertions-deletions-to-convert-string-dp-30/
//Problem:  https://www.naukri.com/code360/problems/can-you-make_4244510

------------
Approach:
(n - lcs(s1,s2)) + (m - lcs(s1,s2))
------------

//---------
//Top Down
//---------

int f(int i, int j, string s, string t, vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j]){
        return dp[i][j] = 1 + f(i-1,j-1,s,t,dp);
    }
    return dp[i][j] = max(f(i-1,j,s,t,dp), f(i,j-1,s,t,dp));
}

int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n, vector<int>(m,-1));
	return f(n-1, m-1, s, t, dp);
}

int canYouMake(string &s1, string &s2){
    int n = s1.size(), m = s2.size();
    return (n - lcs(s1,s2)) + (m - lcs(s1,s2));
}

//---------
//Bottom Up
//---------
int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
	return dp[n][m];
}
int canYouMake(string &s1, string &s2){
    int n = s1.size(), m = s2.size();
    return (n - lcs(s1,s2)) + (m - lcs(s1,s2));
}

//---------
//Bottom Up(Space optimized)
//---------

int lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<int>prev(m+1), cur(m+1);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                cur[j] = 1 + prev[j-1];
            }
            else cur[j] = max(prev[j], cur[j-1]);
        }
        prev = cur;
    }
	return prev[m];
}

int canYouMake(string &s1, string &s2){
    int n = s1.size(), m = s2.size();
    return (n - lcs(s1,s2)) + (m - lcs(s1,s2));
}


//#######################################################################
//#######-------DP 31. Shortest Common Supersequence | DP on Strings--------########
//Question Type: DP on Strings, 
//Tutorial: https://takeuforward.org/data-structure/shortest-common-supersequence-dp-31/
//Problem:  https://www.naukri.com/code360/problems/shortest-supersequence_4244493

------------
The length is n + m - lcs(n,m)

Approach:
1. Apply LCS 
2. Add string part of that is same(diagonal) + that is getting reduced(vertical or horizontal)
------------

//---------
//Top Down
//---------

Just apply the steps portion

//---------
//Bottom Up
//---------

#include <bits/stdc++.h> 

string lcs(string s, string t)
{      
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

	string ans = "";

    int i = n, j = m;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            ans+= s[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i][j-1]<dp[i-1][j]){
				ans+=s[i-1];
                i--;
            }
            else{
				ans+=t[j-1];
                j--;
            }
        }
    }

	while(i>0) ans+=s[i-1],i--;
	while(j>0) ans+=t[j-1],j--;
	reverse(ans.begin(),ans.end());
	return ans;
}

string shortestSupersequence(string a, string b)
{
	return lcs(a,b);
}


//---------
//Bottom Up(Space optimized)
//---------

Just apply the steps portion


//#######################################################################
//#######-------DP 32. Distinct Subsequences | 1D Array Optimisation Technique--------########
//Question Type: DP on Strings, 
//Tutorial: https://takeuforward.org/data-structure/distinct-subsequences-dp-32/
//Problem:  https://www.naukri.com/code360/problems/subsequence-counting_3755256

------------
Approach:
1. j == -1 means j has passed all, so return 1, and if i==-1 means i has passed all and did not matched, so return 0
2. if(s1[i]==s2[j]) check in above and above left, else check only above
------------

//---------
//Top Down
//---------

//0 base indexing
const int md = 1e9+7;
int f(int i, int j,string &s1,string &s2,vector<vector<int>>&dp ){
	if(j<0) return 1;
	if(i<0) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	if(s1[i]==s2[j]){
		return dp[i][j] = (f(i-1,j-1,s1,s2,dp) + f(i-1,j,s1,s2,dp))%md;
	}
	else return dp[i][j] = f(i-1,j,s1,s2,dp)%md;
}
int distinctSubsequences(string &str, string &sub)
{
	int n = str.size(), m = sub.size();
	vector<vector<int>>dp(n, vector<int>(m,-1));
	return f(n-1,m-1,str,sub,dp);
}

//1 base indexing
const int md = 1e9+7;
int f(int i, int j,string &s1,string &s2,vector<vector<int>>&dp ){
	if(j==0) return 1;
	if(i==0) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	if(s1[i-1]==s2[j-1]){
		return dp[i][j] = (f(i-1,j-1,s1,s2,dp) + f(i-1,j,s1,s2,dp))%md;
	}
	else return dp[i][j] = f(i-1,j,s1,s2,dp)%md;
}
int distinctSubsequences(string &str, string &sub)
{
	int n = str.size(), m = sub.size();
	vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
	return f(n,m,str,sub,dp);
}

//---------
//Bottom Up
//---------
- If matched take both diagonal and upor else take only upor

const int md = 1e9+7;
int distinctSubsequences(string &str, string &sub)
{
	int n = str.size(), m = sub.size();
	vector<vector<int>>dp(n+1, vector<int>(m+1,0));
	for(int i=0;i<=m;i++)dp[0][i] = 0;
	for(int i=0;i<=n;i++) dp[i][0] = 1;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(str[i-1]==sub[j-1]){
				dp[i][j] = (dp[i-1][j-1] +dp[i-1][j])%md;
			}
			else dp[i][j] = dp[i-1][j]%md;
		}
	}
	return dp[n][m];
}

//---------
//Bottom Up(Space optimized)
//---------

const int md = 1e9+7;

int distinctSubsequences(string &str, string &sub)
{
	int n = str.size(), m = sub.size();
	vector<int>prev(m+1,0), cur(m+1);
	prev[0] = 1, cur[0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(str[i-1]==sub[j-1]){
				cur[j] = (prev[j-1] + prev[j])%md;
			}
			else cur[j] = prev[j]%md;
		}
		prev = cur;
	}
	return prev[m];
}

//---------
//Bottom Up(Space optimized) - one 1d array
//---------

const int md = 1e9+7;

int distinctSubsequences(string &str, string &sub)
{
	int n = str.size(), m = sub.size();
	vector<int>prev(m+1,0);
	prev[0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			//don't need the last index after computing, just override that
			if(str[i-1]==sub[j-1]){
				prev[j] = (prev[j-1] + prev[j])%md;
			}
			else prev[j] = prev[j]%md;
		}
	}
	return prev[m];
}

//#######################################################################
//#######-------DP 33. Edit Distance | Recursive to 1D Array Optimised Solution--------########
//Question Type: DP on Strings, 
//Tutorial: https://takeuforward.org/data-structure/edit-distance-dp-33/
//Problem:  https://www.naukri.com/code360/problems/edit-distance_630420

if same -> diagonal side 
else -> minimum of the 3 side + 1


Delete,Replace,Insert

Step:
1. If same then move ahead
2. If not same, do one of (Delete,Replace,Insert)



//---------
//Top Down
//---------

//0 base indexing
int f(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){
    if(i<0) return j+1;//add all j
    if(j<0) return i+1;//delete all i
    if(dp[i][j]!=-1)return dp[i][j];

    //If same then move ahead
    if(s1[i]==s2[j]){
        return dp[i][j] = f(i-1,j-1,s1,s2,dp);
    }
    //insert, delete, replace
    int ins = 1 + f(i, j-1,s1,s2,dp);//insert
    int del = 1 + f(i-1,j,s1,s2,dp);//delete
    int rep = 1 + f(i-1,j-1,s1,s2,dp);//replace
    return dp[i][j] = min(min(ins,del), rep);//minimum of all
}
int editDistance(string str1, string str2)
{   
    int n = str1.size(), m = str2.size();
    vector<vector<int>>dp(n, vector<int>(m,-1));
    return f(n-1, m-1, str1, str2, dp);
}

//1 base indexing
int f(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){
    if(i==0) return j;//add all j
    if(j==0) return i;//delete all i
    if(dp[i][j]!=-1)return dp[i][j];

    //If same then move ahead
    if(s1[i-1]==s2[j-1]){
        return dp[i][j] = f(i-1,j-1,s1,s2,dp);
    }
    //insert, delete, replace
    int ins = 1 + f(i, j-1,s1,s2,dp);
    int del = 1 + f(i-1,j,s1,s2,dp);
    int rep = 1 + f(i-1,j-1,s1,s2,dp);
    return dp[i][j] = min(min(ins,del), rep);
}
int editDistance(string str1, string str2)
{   
    int n = str1.size(), m = str2.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
    return f(n, m, str1, str2, dp);
}

//---------
//Bottom Up
//---------

int editDistance(string str1, string str2)
{   
    int n = str1.size(), m = str2.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1,0));
    //for empty sequence matching
    for(int i=0;i<=n;i++) dp[i][0] = i;//for deleting extra sequence from s2
    for(int i=0;i<=m;i++) dp[0][i] = i;//for adding  

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
                int ins = 1 + dp[i][j-1];//insert
                int del = 1 + dp[i-1][j];//delete
                int rep = 1 + dp[i-1][j-1];//replace
                dp[i][j] = min(min(ins,del), rep);
            }           
        }
    }
    return dp[n][m];
}

//---------
//Bottom Up(Space optimized) 
//---------

int editDistance(string str1, string str2)
{   
    int n = str1.size(), m = str2.size();
    vector<int>prev(m+1,0), cur(m+1,0);

    for(int i=0;i<=m;i++) prev[i] = i;
    for(int i=1;i<=n;i++){
        cur[0] = i;
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]) cur[j] = prev[j-1];
            else{
                int ins = 1 + cur[j-1];//insert
                int del = 1 + prev[j];//delete
                int rep = 1 + prev[j-1];//replace
                cur[j] = min(min(ins,del), rep);
            }           
        }
        prev = cur;
    }
    return prev[m];
}


//#######################################################################
//#######-------DP 34. Wildcard Matching | Recursive to 1D Array Optimisation--------########
//Question Type: DP on Strings, 
//Tutorial: https://takeuforward.org/data-structure/wildcard-matching-dp-34/
//Problem:  https://www.naukri.com/code360/problems/wildcard-pattern-matching_701650

------------
Approach:
1. if both are exhausted then it is true
   if i is exhausted and j is still remaining then it is never possible
   if j is exhausted and i is still remaining then all remaining in i must be '*'
2. if both index has same value or '?' then shrink the string, f(i-1,j-1)
3. if s1[i]=='*' then apply take or not take condition 
4. else it is false(the both indices have different values)
------------

//---------
//Top Down
//---------

//0 base indexing
#include<bits/stdc++.h>
bool f(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){
   if(i<0 && j<0) return true;
   if(i<0 && j>=0)return false;
   if(i>=0 && j<0){
      //rest should be * only
      for(int k=0;k<=i;k++){
         if(s1[k]!='*') return false;
      }
      return true;
   }

   if(dp[i][j]!=-1) return dp[i][j];

   if(s1[i]==s2[j] || s1[i]=='?'){
      return dp[i][j] = f(i-1,j-1,s1,s2,dp);
   }
   else if(s1[i]=='*'){
      //take or not take
      return dp[i][j] = f(i,j-1,s1,s2,dp) || f(i-1,j,s1,s2,dp);
   }
   else false;
}
bool wildcardMatching(string pattern, string text)
{
   int n = pattern.size();
   int m = text.size();
   vector<vector<int>>dp(n, vector<int>(m,-1));
   return f(n-1, m-1, pattern, text, dp);
}

//1 base indexing
#include<bits/stdc++.h>
bool f(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){
   if(i==0 && j==0) return true;
   if(i==0 && j>0)return false;
   if(i>0 && j==0){
      //rest should be * only
      for(int k=0;k<i;k++){
         if(s1[k]!='*') return false;
      }
      return true;
   }

   if(dp[i][j]!=-1) return dp[i][j];

   if(s1[i-1]==s2[j-1] || s1[i-1]=='?'){
      return dp[i][j] = f(i-1,j-1,s1,s2,dp);
   }
   else if(s1[i-1]=='*'){
      //take or not take
      return dp[i][j] = f(i,j-1,s1,s2,dp) || f(i-1,j,s1,s2,dp);
   }
   else false;
}
bool wildcardMatching(string pattern, string text)
{
   int n = pattern.size();
   int m = text.size();
   vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
   return f(n, m, pattern, text, dp);
}

//---------
//Bottom Up
//---------

#include<bits/stdc++.h>

bool wildcardMatching(string pattern, string text)
{
   int n = pattern.size();
   int m = text.size();
   string s1 = pattern;
   string s2 = text;
   
   vector<vector<int>>dp(n+1, vector<int>(m+1,0));
   dp[0][0] = 1;
   for(int i=1;i<=m;i++) dp[0][i] = 0;
   for(int i=1;i<=n;i++){
      bool ok = 1;
      for(int k=0;k<i;k++){
         if(pattern[k] != '*'){
            ok = 0;
            break;
         }
         if(ok)dp[i][0] = 1;
      }
   }

   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         if(s1[i-1]==s2[j-1] || s1[i-1]=='?'){
            dp[i][j] = dp[i-1][j-1];
         }
         else if(s1[i-1]=='*'){
            dp[i][j] = dp[i][j-1] || dp[i-1][j];
         }
         else dp[i][j] = 0;
      }
   }

   return dp[n][m];
}

//---------
//Bottom Up(Space optimized)
//---------

#include<bits/stdc++.h>

bool wildcardMatching(string pattern, string text)
{
   int n = pattern.size();
   int m = text.size();
   string s1 = pattern;
   string s2 = text;
   
   vector<int>prev(m+1,0), cur(m+1,0);
   prev[0] = 1;
   for(int i=1;i<=m;i++) prev[i] = 0;
   
   for(int i=1;i<=n;i++){
      bool ok = 1;
      for(int k=0;k<i;k++){
         if(pattern[k] != '*'){
            ok = 0;
            break;
         }
      }
      cur[0] = ok;

      for(int j=1;j<=m;j++){
         if(s1[i-1]==s2[j-1] || s1[i-1]=='?'){
            cur[j] = prev[j-1];
         }
         else if(s1[i-1]=='*'){
            cur[j] = cur[j-1] || prev[j];
         }
         else cur[j] = 0;
      }
      prev = cur;
   }

   return prev[m];
}


//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#####################-------DP on Stocks--------#######################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


DP 35. Best Time to Buy and Sell Stock          - 1 transaction
DP 36. Buy and Sell Stock - II                  - unlimited transaction
DP 37. Buy and Sell Stocks III                  - 2 transaction
DP 38. Buy and Stock Sell IV                    - k transaction
DP 39. Buy and Sell Stocks With Cooldown        - cannot buy and sell consecutive day, (after selling there is atleast 1 day gap)
DP 40. Buy and Sell Stocks With Transaction Fee - with transaction fee

DP ON Stocks Code:
#include<bits/stdc++.h>

long getMaximumProfit(long *values, int n)
{   
    vector<vector<long>>dp(n+1, vector<long>(2,0));

    dp[n][1]=dp[n][0] = 0;
    for(int i=n-1;i>=0;i--){
        for(buy : {0,1}){
            long prof = 0;
            if(buy){
                prof = max(-values[i] + dp[i+1][0], dp[i+1][1]);//kine felle values kombe, barbe, then take or not take
            }
            else prof = max(values[i] + dp[i+1][1], dp[i+1][0]);
            dp[i][buy] = prof;
        }
    }
    return dp[0][1];
}

//#######################################################################
//#######-------DP 35. Best Time to Buy and Sell Stock | DP on Stocks--------########
//Tutorial: https://takeuforward.org/data-structure/stock-buy-and-sell-dp-35/
//Problem:  https://www.naukri.com/code360/problems/stocks-are-profitable_893405

We are solving smaller problems to solve bigger problems, this is why this is dp problem
- It is also a constructive algorithm problem
first buy, then sell

------------
Approach:
1. first minimum is the first value and initially the answer is 0
2. keep the minimum prices and keep the mamxium answer possible
------------

//---------
//Top Down
//---------


//---------
//Bottom Up
//---------

#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int mn = prices[0], ans = 0;
    for(int i=1;i<prices.size();i++){
        mn = min(mn, prices[i]);
        ans = max(ans, prices[i] - mn);
    }
    return ans;
}


//---------
//Bottom Up(Space optimized)
//---------


//#######################################################################
//#######-------DP 36. Buy and Sell Stock - II | Recursion to Space Optimisation--------########
//Tutorial: https://takeuforward.org/data-structure/buy-and-sell-stock-ii-dp-36/
//Problem:  https://www.naukri.com/code360/problems/selling-stock_630282

BSBSBSBS is allowed but BBBSSS not allowed

------------
Approach:
1. On that day, kinle/sell krle profit kombe or barbe[this is take case]
2. On that day, na kinle/sell krle profit kombe na or barbe na[this is not take case]
------------

//---------
//Top Down
//---------

#include<bits/stdc++.h>
long f(int i, int buy, int n, long *values,vector<vector<long>>&dp ){
    if(i==n) return 0;
    if(dp[i][buy]!=-1)return dp[i][buy];
    long prof = 0;
    if(buy){
        prof = max(-values[i] + f(i+1,0,n,values, dp), f(i+1,1,n,values, dp));//kine felle values kombe, barbe, then take or not take
    }
    else prof = max(values[i] + f(i+1,1,n,values, dp), f(i+1,0,n,values, dp));

    return dp[i][buy] = prof;
}
long getMaximumProfit(long *values, int n)
{   
    vector<vector<long>>dp(n, vector<long>(2,-1));
    return f(0,1,n,values, dp);
}

//---------
//Bottom Up
//---------

#include<bits/stdc++.h>

long getMaximumProfit(long *values, int n)
{   
    vector<vector<long>>dp(n+1, vector<long>(2,0));

    dp[n][1]=dp[n][0] = 0;
    for(int i=n-1;i>=0;i--){
        for(buy : {0,1}){
            long prof = 0;
            if(buy){
                prof = max(-values[i] + dp[i+1][0], dp[i+1][1]);//kine felle values kombe, barbe, then take or not take
            }
            else prof = max(values[i] + dp[i+1][1], dp[i+1][0]);
            dp[i][buy] = prof;
        }
    }
    return dp[0][1];
}

//---------
//Bottom Up(Space optimized)
//---------

#include<bits/stdc++.h>

long getMaximumProfit(long *values, int n)
{   
    vector<long> prev(2, 0), cur(2,0);
    for(int i=n-1;i>=0;i--){
        for(buy : {0,1}){
            long prof = 0;
            if(buy){
                prof = max(-values[i] + prev[0], prev[1]);
            }
            else prof = max(values[i] + prev[1], prev[0]);
            cur[buy] = prof;
        }
        prev = cur;
    }
    return prev[1];
}


//#######################################################################
//#######-------DP 37. Buy and Sell Stocks III | Recursion to Space Optimisation--------########
//Tutorial: https://takeuforward.org/data-structure/buy-and-sell-stock-iii-dp-37/
//Problem:  https://www.naukri.com/code360/problems/buy-and-sell-stock_1071012

only when buy + sell done a transaction is completed
There are 3 changing states in this problem: index, total transactions, buy or not buy

------------
Approach:
1. 
------------

//---------
//Top Down(Partially Accepted)
//---------

long f(int i, int buy, int k, int n, vector<int>&values,vector<vector<vector<int>>>&dp){
    if(k==0) return 0;
    if(i==n) return 0;
    if(dp[i][buy][k]!=-1)return dp[i][buy][k];
    long prof = 0;
    if(buy){
        prof = max(-values[i] + f(i+1,0,k, n,values, dp), f(i+1,1,k,n,values, dp));
    }
    else prof = max(values[i] + f(i+1,1,k-1, n,values, dp), f(i+1,0,k, n,values, dp));
    //only when buy + sell done a transaction is completed

    return dp[i][buy][k] = prof;
}
int maxProfit(vector<int>& prices)
{
    int n = prices.size();
    vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
    return f(0, 1, 2,n, prices, dp);
}

//---------
//Bottom Up
//---------
draw the tabulation of bottom up
WA
int maxProfit(vector<int>& prices)
{
    int n = prices.size();
    vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));

    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            for(int k=1;k<=2;k++){
                long prof = 0;
                if(buy){
                    prof = max(-prices[i] + dp[i+1][1][k], dp[i+1][0][k]);
                }
                else prof = max(prices[i] + dp[i+1][1][k-1], dp[i+1][0][k]);
                dp[i][buy][k] = prof;
            }
        }
    }
   return dp[0][1][2];
}

//---------
//Bottom Up(Space optimized)
//---------


////////////////////////////////////////////////////////////////////////////////////////////////
//Using 2 changing parameters
//---------
//Top Down
//---------

1. there are only 2 transaction, so BSBS, hence k is 0123 

int f(int i, int k, int n,vector<int>& prices,vector<vector<int>>&dp){
    if(i==n || k==4)return 0;
    if(dp[i][k]!=-1) return dp[i][k];
    int profit = 0;
    if(k%2==0){
        profit = max(-prices[i] + f(i+1, k+1, n, prices, dp), f(i+1, k, n, prices, dp));
    }
    else {
        profit = max(prices[i] + f(i+1, k+1, n, prices, dp), f(i+1, k, n, prices, dp));
    }
    return dp[i][k] = profit;
}

int maxProfit(vector<int>& prices)
{
    int n = prices.size();
    vector<vector<int>>dp(n, vector<int>(4,-1));
    return f(0, 0, n, prices, dp);
}


//---------
//Bottom Up
//---------
int maxProfit(vector<int>& prices)
{
    int n = prices.size();
    vector<vector<int>>dp(n+1, vector<int>(4,0));

    for(int i=n-1;i>=0;i--){
        for(int k=0;k<4;k++){
            int profit = 0;
            if(k%2==0){
                profit = max(-prices[i] + dp[i+1][k+1], dp[i+1][k]);
            }
            else {
                profit = max(prices[i] + dp[i+1][k+1], dp[i+1][k]);
            }
            dp[i][k] = profit;
        }
    }
    return dp[0][0];
}

//---------
//Bottom Up(Space optimized) - one 1d array
//---------

int maxProfit(vector<int>& prices)
{
    int n = prices.size();
    vector<int>prev(4,0);

    for(int i=n-1;i>=0;i--){
        for(int k=0;k<4;k++){
            int profit = 0;
            if(k%2==0){
                profit = max(-prices[i] + prev[k+1], prev[k]);
            }
            else {
                profit = max(prices[i] + prev[k+1], prev[k]);
            }
            prev[k] = profit;
        }
    }
    return prev[0];
}



//#######################################################################
//#######-------DP 38. Buy and Stock Sell IV | Recursion to Space Optimisation--------########
//Tutorial: https://takeuforward.org/data-structure/buy-and-sell-stock-iv-dp-38/
//Problem:  https://www.naukri.com/code360/problems/best-time-to-buy-and-sell-stock_1080698

------------
Approach:
1. apply k in the transaction part, instead of 2(previous question)
------------

//---------
//Top Down
//---------

#include <bits/stdc++.h> 
long f(int i, int buy, int k, int n, vector<int>&values,vector<vector<vector<int>>>&dp){
    if(k==0) return 0;
    if(i==n) return 0;
    if(dp[i][buy][k]!=-1)return dp[i][buy][k];
    long prof = 0;
    if(buy){
        prof = max(-values[i] + f(i+1,0,k, n,values, dp), f(i+1,1,k,n,values, dp));
    }
    else prof = max(values[i] + f(i+1,1,k-1, n,values, dp), f(i+1,0,k, n,values, dp));
    return dp[i][buy][k] = prof;
}

int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(k+1,-1)));
    return f(0, 1, k,n, prices, dp);
}


//---------
//Bottom Up - 3d dp
//---------

#include <bits/stdc++.h> 

int maximumProfit(vector<int> &prices, int n, int t)
{
    vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(t+1,0)));
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            for(int k=1;k<=t;k++){
                long prof = 0;
                if(buy){
                    prof = max(-prices[i] + dp[i+1][0][k], dp[i+1][1][k]);
                }
                else prof = max(prices[i] + dp[i+1][1][k-1], dp[i+1][0][k]);
                dp[i][buy][k] = prof;
            }
        }
    }
    
    return dp[0][1][t];
}


//---------
//Bottom Up(Space optimized) - 2d dp
//---------
#include <bits/stdc++.h> 

int maximumProfit(vector<int> &prices, int n, int t)
{
    vector<vector<int>>dp(2, vector<int>(t+1,0));
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            for(int k=1;k<=t;k++){
                long prof = 0;
                if(buy){
                    prof = max(-prices[i] + dp[0][k], dp[1][k]);
                }
                else prof = max(prices[i] + dp[1][k-1], dp[0][k]);
                dp[buy][k] = prof;
            }
        }
    }
    
    return dp[1][t];
}

//---------
//Bottom Up(Space optimized) - 1d dp
//---------
#include <bits/stdc++.h> 

int maximumProfit(vector<int> &prices, int n, int t)
{
    vector<int>prev(2*t+1),cur(2*t+1);
    for(int i=n-1;i>=0;i--){
       for(int k=2*t-1;k>=0;k--){
            long prof = 0;
            if(k%2==0){
                prof = max(-prices[i] + prev[k+1], cur[k]);
            }
            else prof = max(prices[i] + prev[k+1], cur[k]);
            cur[k] = prof;
        } 
        prev = cur;
    }
    return prev[0];
}


//#######################################################################
//#######-------DP 39. Buy and Sell Stocks With Cooldown | Recursion to Space Optimisation--------########
//Tutorial: https://takeuforward.org/data-structure/buy-and-sell-stocks-with-cooldown-dp-39/
//Problem:  https://www.naukri.com/code360/problems/highway-billboards_3125969

------------
Approach:
1. just apply i+2 on the selling day
------------

//---------
//Top Down
//---------

long f(int i, int buy, int n,vector<int> &prices,vector<vector<int>>&dp ){
    if(i==n || i==n+1) return 0;
    if(dp[i][buy]!=-1)return dp[i][buy];
    long prof = 0;
    if(buy){
        prof = max(-prices[i] + f(i+1,0,n,prices, dp), f(i+1,1,n,prices, dp));
    }
    else prof = max(prices[i] + f(i+2,1,n,prices, dp), f(i+1,0,n,prices, dp));

    return dp[i][buy] = prof;
}

int stockProfit(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>>dp(n, vector<int>(2,-1));
    return f(0, 1, n, prices, dp);
}

//---------
//Bottom Up
//---------

int stockProfit(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>>dp(n+2, vector<int>(2,0));
    for(int i=n-1;i>=0;i--){
        for(int buy:{0,1}){
            long prof = 0;
            if(buy){
                prof = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
            }
            else prof = max(prices[i] + dp[i+2][1], dp[i+1][0]);
            dp[i][buy] = prof;
        }
    }
    return dp[0][1];
}

//Omitting buy portion, explicitly writing it
int stockProfit(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>>dp(n+2, vector<int>(2,0));
    for(int i=n-1;i>=0;i--){
        dp[i][1] = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
        dp[i][0] = max(prices[i] + dp[i+2][1], dp[i+1][0]);
    }
    return dp[0][1];
}

//---------
//Bottom Up(Space optimized) - 3 1d array
//---------
- Here, we need 3 rows, so keep the 3 rows 

int stockProfit(vector<int> &prices){
    int n = prices.size();
    vector<int> cur(2, 0); 
    vector<int> front1(2, 0);
    vector<int> front2(2, 0);    
    for(int i=n-1;i>=0;i--){
        cur[1] = max(-prices[i] + front1[0], front1[1]);
        cur[0] = max(prices[i] + front2[1], front1[0]);
        front2 = front1;
        front1 = cur;
    }
    return cur[1];
}

//#######################################################################
//#######-------DP 40. Buy and Sell Stocks With Transaction Fee | Recursion to Space Optimisation--------########
//Tutorial:https://takeuforward.org/data-structure/buy-and-sell-stocks-with-transaction-fees-dp-40/
//Problem:  https://www.naukri.com/code360/problems/rahul-and-his-chocolates_3118974

------------
Approach:
1. Just delete fee everytime you buy or sell, {delete only 1 time}
------------

//---------
//Top Down
//---------
long f(int i, int buy, int n,vector<int> &prices,int fee, vector<vector<int>>&dp ){
    if(i==n) return 0;
    if(dp[i][buy]!=-1)return dp[i][buy];
    long prof = 0;
    if(buy){
        prof = max(-prices[i] + f(i+1,0,n,prices, fee, dp), f(i+1,1,n,prices, fee, dp));
    }
    else prof = max(prices[i]-fee + f(i+1,1,n,prices,fee, dp), f(i+1,0,n,prices,fee, dp));

    return dp[i][buy] = prof;
}

int maximumProfit(vector<int> &prices, int n, int fee)
{
    vector<vector<int>>dp(n, vector<int>(2,-1));
	return f(0, 1, n, prices,fee, dp);
}

//---------
//Bottom Up
//---------
int maximumProfit(vector<int> &prices, int n, int fee)
{
    vector<vector<int>>dp(n+1, vector<int>(2,0));
    for(int i=n-1;i>=0;i--){
        dp[i][1] = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
        dp[i][0] = max(prices[i]-fee + dp[i+1][1], dp[i+1][0]);
    }
    return dp[0][1];
}

//---------
//Bottom Up(Space optimized)
//---------
int maximumProfit(vector<int> &prices, int n, int fee)
{
    vector<int> ahead(2, 0); 
    vector<int> cur(2, 0);
    for(int i=n-1;i>=0;i--){
        cur[1] = max(-prices[i] + ahead[0], ahead[1]);
        cur[0] = max(prices[i]-fee + ahead[1], ahead[0]);
        ahead = cur;
    }
    return ahead[1];
}
//a little different
int maximumProfit(vector<int> &prices, int n, int fee)
{
    vector<int> ahead(2, 0); 
    vector<int> cur(2, 0);
    for(int i=n-1;i>=0;i--){
        cur[1] = max(-prices[i] + ahead[0], cur[1]);
        cur[0] = max(prices[i]-fee + ahead[1], cur[0]);
        ahead = cur;
    }
    return ahead[1];
}

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#####################-------DP on LIS--------##########################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

LIS CODE: 
#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int>dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i] = max(1+dp[j], dp[i]);
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++) ans = max(ans, dp[i]);
    return ans;
}

//#######################################################################
//#######-------DP 41. Longest Increasing Subsequence | Memoization--------########
//Tutorial: https://takeuforward.org/data-structure/longest-increasing-subsequence-dp-41/
//Problem:  https://www.naukri.com/code360/problems/longest-increasing-subsequence_630459

------------
Approach:
1. At first set previous anything -1,-100 anything
2. if taken, previous would be that index and move main index to index + 1    
   if not taken, previous would be same, index+1 would go on 
------------

//---------
//Top Down(Runtime error because of constraints)
//---------
#include<bits/stdc++.h>
int f(int i, int j, int n,int arr[], vector<vector<int>>&dp){
    if(i==n)return 0;
    if(dp[i][j+1]!=-1)return dp[i][j+1];
    int taken = 0;
    int not_taken = f(i+1,j,n,arr,dp);
    if(j==-1 || arr[i]>arr[j]){
        taken = 1 + f(i+1,i,n,arr,dp);
    }
    return dp[i][j+1] = max(not_taken, taken);
}
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>>dp(n, vector<int>(n+1,-1));
    return f(0, -1, n, arr,dp);
}


//#######################################################################
//#######-------DP 42. Printing Longest Increasing Subsequence | Tabulation | Algorithm--------########
//Tutorial: https://takeuforward.org/data-structure/printing-longest-increasing-subsequence-dp-42/
//Problem:  https://www.naukri.com/code360/problems/longest-increasing-subsequence_630459

------------
Approach:
1. by backtracking print the array
------------

//---------
//Bottom Up(TLE cause of constraints)
//---------

#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int>dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i] = max(1+dp[j], dp[i]);
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++) ans = max(ans, dp[i]);
    return ans;
}

//---------
//Bottom Up(Print the full increasing sequence by backtrack)
//---------

#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int>dp(n,1), hash(n,1);
    for(int i=0;i<n;i++){
        hash[i] = i;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && 1+dp[j]>dp[i] ){
                dp[i] = 1+dp[j];
                hash[i] = j;
            }
        }
    }
    int ans = 0, last = -1;
    for(int i=0;i<n;i++){
        if(dp[i]>ans){
            ans = dp[i];
            last = i;
        }
    }
    vector<int>tmp;
    tmp.push_back(arr[last]);
    while(hash[last] != last){
        last = hash[last];
        tmp.push_back(arr[last]);    
    }
    reverse(tmp.begin(),tmp.end());
    for(auto x: tmp)cout<< x << ' ';

    return ans;
}


//#######################################################################
//#######-------DP 43. Longest Increasing Subsequence | Binary Search | Intuition--------########
//Tutorial: https://takeuforward.org/data-structure/longest-increasing-subsequence-binary-search-dp-43/
//Problem:  https://www.naukri.com/code360/problems/longest-increasing-subsequence_630459

To regenerate the sequence you have to do a lot more things, but doing binary search you can get the length

------------
Approach:
1. if the element is greater than the last element add it in the array 
   else change the value with arr[index]
------------


//---------
//Binary Search Approach(nlogn)
//---------

#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int>v;
    for(int i=0;i<n;i++){
        int lw = lower_bound(v.begin(),v.end(),arr[i]) - v.begin();
        if(v.size()==lw) v.push_back(arr[i]);
        else v[lw] = arr[i];
    }
    return v.size();
}

//#######################################################################
//#######-------DP 44. Largest Divisible Subset | Longest Increasing Subsequence--------########
//Tutorial: https://takeuforward.org/data-structure/longest-common-subsequence-dp-25/
//Problem:  https://www.naukri.com/code360/problems/divisible-set_3754960

------------
Approach:
1. sort the array (and apply lIS)
2. 1 -> 4 -> 8 -> 16 (to become divisible 16 must be 16%4==0, 8%4==0, previous should be divisible) 
------------

//---------
//Bottom Up
//---------
vector<int> divisibleSet(vector<int> &arr)
{   
    int n = arr.size();
    vector<int>dp(n,1), hash(n);
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        hash[i] = i;
        for(int j=0;j<i;j++){
            if(arr[i]%arr[j]==0 && dp[i]<dp[j]+1){
                dp[i] = dp[j]+1;
                hash[i] = j;
            }
        }
    }
    
    int ans = 0, last = -1;
    for(int i=0;i<n;i++){
        if(dp[i]>ans){
            ans = dp[i];
            last = i;
        }
    }
    vector<int>tmp;
    tmp.push_back(arr[last]);
    while(hash[last] != last){
        last = hash[last];
        tmp.push_back(arr[last]);    
    }
    reverse(tmp.begin(),tmp.end());

    return tmp;
}



//#######################################################################
//#######-------DP 45. Longest String Chain | Longest Increasing Subsequence | LIS--------########
//Tutorial: https://takeuforward.org/data-structure/longest-string-chain-dp-45/
//Problem:  https://www.naukri.com/code360/problems/longest-string-chain_3752111

------------
Approach:
1. Apply LIS 
2. sort the string array in terms of size
3. write a check function and see if the s1.size() == s2.size() + 1 and all except 1 is different
------------

*****before comparing it must be sorted(missed in the video)
//---------
//Bottom Up
//---------
bool check(string &s1, string &s2){
    //s1 is greater in size than s2
    if(s1.size()!=s2.size()+1) return false;
    int f = 0, l = 0;
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    while(f<s1.size()){
        if(s2.size()>l && s1[f]==s2[l]){
            f++;
            l++;
        }
        else f++;
    }
    if(f==s1.size() && l==s2.size()) return true;
    else return false;
}

int longestStrChain(vector<string> &arr){
    sort(arr.begin(),arr.end(), 
        [](string &s1,string &s2){
            return s1.size()<s2.size();
    });
    int n = arr.size();
    vector<int>dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(check(arr[i],arr[j]) && dp[i]<dp[j]+1){
                dp[i] = dp[j]+1;
            }
        }
    }
    
    int ans = 0;
    for(int i=0;i<n;i++) ans = max(ans, dp[i]);
    return ans;
}

//#######################################################################
//#######-------DP 46. Longest Bitonic Subsequence | LIS--------########
//Tutorial: https://takeuforward.org/data-structure/longest-bitonic-subsequence-dp-46/
//        : https://youtu.be/TWHytKnOPaQ?list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr
//Problem:  https://www.naukri.com/code360/problems/longest-bitonic-sequence_1062688

bitonic: first increases then decreases

------------
Approach:
1. Find LIS from front and from back, 
2. the answer is max(front[i] + back[i] - 1)
------------

//---------
//Bottom Up
//---------

#include<bits/stdc++.h>
int longestBitonicSubsequence(vector<int>& arr, int n)
{
	vector<int>dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i] = max(1+dp[j], dp[i]);
            }
        }
    }

	reverse(arr.begin(),arr.end());
	vector<int>dp2(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp2[i] = max(1+dp2[j], dp2[i]);
            }
        }
    }
	reverse(dp2.begin(),dp2.end());

	int ans = 0;
    for(int i=0;i<n;i++) ans = max(ans, dp[i]+dp2[i]-1);
    return ans;

}

//#######################################################################
//#######-------DP 47. Number of Longest Increasing Subsequences--------########
//Tutorial: https://takeuforward.org/data-structure/number-of-longest-increasing-subsequences-dp-47/
//Problem:  https://www.naukri.com/code360/problems/number-of-longest-increasing-subsequence_3751627

If you want to verify, this is how the solution should look:
array:  1 5 4 3 2 6 7 10 8 9 
length: 1 2 2 2 2 3 4 5 5 6 
count:  1 1 1 1 1 4 4 4 4 4

------------
Approach:
1. manage a max length(dp) and count of the sequences 
2. at the end if found the max length count the total max 
------------

//---------
//Bottom Up
//---------

confused


//---------
//Bottom Up(DO THE BELOW DRY RUN FOR BETTER UNDERSTANDING)
//---------
#include <bits/stdc++.h>
using namespace std;

// Function to find the count of Longest Increasing Subsequences (LIS)
void findNumberOfLIS(vector<int>& arr) {
    int n = arr.size();

    vector<int> dp(n, 1); // dp[i] stores the length of the LIS ending at arr[i]
    vector<int> ct(n, 1); // ct[i] stores the count of LIS ending at arr[i]

    int maxi = 1; // Initialize the maximum length as 1

    for (int i = 0; i < n; i++) {
        for (int prev_index = 0; prev_index < i; prev_index++) {
            if (arr[prev_index] < arr[i] && dp[prev_index] + 1 > dp[i]) {
                dp[i] = dp[prev_index] + 1;
                // Inherit count
                ct[i] = ct[prev_index];
            } else if (arr[prev_index] < arr[i] && dp[prev_index] + 1 == dp[i]) {
                // Increase the count
                ct[i] = ct[i] + ct[prev_index];
            }
        }
        maxi = max(maxi, dp[i]);
    }

    int numberOfLIS = 0;

    for (int i = 0; i < n; i++) {
        if (dp[i] == maxi) {
            numberOfLIS += ct[i];
        }
    }

    for(int i=0;i<n;i++){
        cout<< arr[i] << ' ';
    }
    cout<<endl;

    for(int i=0;i<n;i++){
        cout<< dp[i] << ' ';
    }
    cout<<endl;

    for(int i=0;i<n;i++){
        cout<< ct[i] << ' ';
    }
    cout<<endl;

    cout<< numberOfLIS <<endl;

    //return numberOfLIS;
}

int main() {
    vector<int> arr = {1, 5, 4, 3, 2, 6, 7, 10, 8 , 9};
    findNumberOfLIS(arr);

    //cout << "The count of Longest Increasing Subsequences (LIS) is " << findNumberOfLIS(arr) << endl;

    return 0;
}



//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//##################-------MCM DP/Partition DP--------###################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

- When there are multiple ways to solve it is partition dp 
- solve portion and return  

------------
Approach:
1. Start with entire block
2. Try all partitions 
3. Return the best possible 2 partition
------------

MCM DP/Partition DP CODE:

#include <bits/stdc++.h> 
int f(int i, int j, vector<int> &arr, vector<vector<int>>&dp){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mn = 1e9;
    for(int k=i;k<j;k++){
        int v = f(i,k,arr,dp) + f(k+1,j,arr,dp) + arr[i-1] *arr[k] *arr[j];
        //i, k should be different, that is why i-1
        mn = min(mn, v);
    }
    return dp[i][j] = mn;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    int i = 1;
    int j = N-1;
    vector<vector<int>>dp(N, vector<int>(N,-1));
    return f(i, j, arr,dp);
}

//#######################################################################
//#######-------DP 48. Matrix Chain Multiplication | MCM | Partition DP Starts--------########
//Tutorial: https://takeuforward.org/dynamic-programming/matrix-chain-multiplication-dp-48/
//Tutorial2: https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
//Problem:  https://www.naukri.com/code360/problems/matrix-chain-multiplication_975344

- col1, row2 must be same to multiply two matrices 

------------
Approach:
1. the matrix is from 0 to n-1 index, multiply with any 3 index and find the minimum, i must be lesser than k, so start with 1
------------

//---------
//Top Down
//---------
#include <bits/stdc++.h> 
int f(int i, int j, vector<int> &arr, vector<vector<int>>&dp){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mn = 1e9;
    for(int k=i;k<j;k++){
        int v = f(i,k,arr,dp) + f(k+1,j,arr,dp) + arr[i-1] *arr[k] *arr[j];
        //i, k should be different, that is why i-1
        mn = min(mn, v);
    }
    return dp[i][j] = mn;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    int i = 1;
    int j = N-1;
    vector<vector<int>>dp(N, vector<int>(N,-1));
    return f(i, j, arr,dp);
}

//#######################################################################
//#######-------DP 49. Matrix Chain Multiplication | Bottom-Up | Tabulation--------########
//Tutorial: https://takeuforward.org/data-structure/matrix-chain-multiplication-tabulation-method-dp-49/
//Problem:  https://www.naukri.com/code360/problems/matrix-chain-multiplication_975344

------------
Approach:
1. 
------------

//---------
//Bottom Up
//---------

#include <bits/stdc++.h> 
int matrixMultiplication(vector<int> &arr, int N)
{
    int ii = 1;
    int jj = N-1;
    vector<vector<int>>dp(N, vector<int>(N,0));
    for(int i=N-1;i>=1;i--){
        //j is always right side of i
        for(int j=i+1;j<N;j++){
            int mn = 1e9;
            for(int k=i;k<j;k++){
                int v = dp[i][k] + dp[k+1][j] + arr[i-1] *arr[k] *arr[j];
                mn = min(mn, v);
            }
            dp[i][j] = mn;
        }
    }
    return dp[ii][jj];
}


//#######################################################################
//#######-------DP 50. Minimum Cost to Cut the Stick--------########
//Tutorial: https://takeuforward.org/data-structure/minimum-cost-to-cut-the-stick-dp-50/
//Problem:  https://www.naukri.com/code360/problems/cost-to-cut-a-chocolate_3208460

------------
Approach:
1. 
------------

Confused??? DRAW tabulation to understand

//---------
//Top Down
//---------


//---------
//Bottom Up
//---------


//---------
//Bottom Up(Space optimized)
//---------


//#######################################################################
//#######-------DP 51. Burst Balloons | Partition DP--------########
//Tutorial: https://takeuforward.org/data-structure/burst-balloons-partition-dp-dp-51/
//Problem:  https://www.naukri.com/code360/problems/mining-diamonds_4244494

------------
Approach:
1. 
------------

Confused??

//---------
//Top Down
//---------


//---------
//Bottom Up
//---------


//---------
//Bottom Up(Space optimized)
//---------


//#######################################################################
//#######-------DP 52. Evaluate Boolean Expression to True | Partition DP--------########
//Tutorial: https://takeuforward.org/data-structure/evaluate-boolean-expression-to-true-partition-dp-dp-52/
//Problem:  https://www.naukri.com/code360/problems/problem-name-boolean-evaluation_1214650

------------
Approach:
1. 
------------

//---------
//Top Down
//---------
Confused??

//---------
//Bottom Up
//---------


//---------
//Bottom Up(Space optimized)
//---------


//#######################################################################
//#######-------DP 53. Palindrome Partitioning - II | Front Partition--------########
//Tutorial: https://takeuforward.org/data-structure/palindrome-partitioning-ii-front-partition-dp-53/
//Problem:  https://www.naukri.com/code360/problems/palindrome-partitioning_873266

------------
Approach:
1. 
------------

//---------
//Top Down
//---------

int pal(int i, int j, string &s){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++,j--;
    }
    return true;
}
int f(int i, string &str, vector<int>&dp){
    if(i==str.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    int mn = 1e19;
    for(int j=i;j<str.size();j++){
        if( pal(i, j, str) ){
            int v = 1 + f(j+1, str, dp);//+1 and solve for other length
            mn = min(mn, v);
        }
    }
    return dp[i] = mn;
}
int palindromePartitioning(string str)
{
    int n = str.size();
    vector<int>dp(n, -1);
    return f(0, str, dp)-1;
}


//---------
//Bottom Up
//---------
int pal(int i, int j, string &s){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++,j--;
    }
    return true;
}

int palindromePartitioning(string str)
{
    int n = str.size();
    vector<int>dp(n+1, -1);
    for(int i=n-1;i>=0;i--){
        int mn = 1e19;
        for(int j=i;j<str.size();j++){
            if( pal(i, j, str) ){
                int v = 1 + dp[j+1];
                mn = min(mn, v);
            }
        }
        dp[i] = mn;
    }
    return dp[0];
}


draw tabulation for this


//#######################################################################
//#######-------DP 54. Partition Array for Maximum Sum | Front Partition--------########
//Tutorial: https://takeuforward.org/data-structure/partition-array-for-maximum-sum-front-partition-dp-54/
//Problem:  https://www.naukri.com/code360/problems/maximum-subarray_3755255

------------
Approach:
1. 
------------

//---------
//Top Down
//---------

#include<bits/stdc++.h>
int f(int i, int k,vector<int> &arr, vector<int> &dp ){
    int n = arr.size();
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];
    int mx = INT_MIN, l = 0,mxsum = INT_MIN;
    for(int j=i;j<min(n,i+k);j++){
        l++;
        mx = max(mx, arr[j]);
        int v = mx * l + f(j+1, k, arr,dp);//solve rest
        mxsum = max(v, mxsum);
    }
    return dp[i] = mxsum;
}
int maximumSubarray(vector<int> &arr, int k){
    vector<int>dp(arr.size(),-1);
    return f(0, k, arr, dp);
}

//---------
//Bottom Up
//---------

#include<bits/stdc++.h>
int maximumSubarray(vector<int> &arr, int k){
    int n = arr.size();
    vector<int>dp(n+1,0);

    for(int i=n-1;i>=0;i--){
        int mx = INT_MIN, l = 0,mxsum = INT_MIN;
        for(int j=i;j<min(n,i+k);j++){
            l++;
            mx = max(mx, arr[j]);
            int v = mx * l + dp[j+1];
            mxsum = max(v, mxsum);
        }
        dp[i] = mxsum;
    }
    return dp[0];
}


//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#####################-------DP On Squares--------######################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------DP 55. Maximum Rectangle Area with all 1's | DP on Rectangles--------########
//Histogram problem: https://takeuforward.org/data-structure/area-of-largest-rectangle-in-histogram/
//Tutorial: https://takeuforward.org/data-structure/maximum-rectangle-area-with-all-1s-dp-on-rectangles-dp-55/
//Problem:  https://www.naukri.com/code360/problems/maximum-size-rectangle-sub-matrix-with-all-1-s_893017

------------
Approach:
1. Get the Histogram problem function 
2. for every row run the Histogram problem function  and get the maximum rectangle
------------

//---------
//Bottom Up
//---------

#include<bits/stdc++.h>
int largestRectangleArea(vector < int > & histo) {
	stack < int > st;
	int maxA = 0;
	int n = histo.size();
	for (int i = 0; i <= n; i++) {
	while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
		int height = histo[st.top()];
		st.pop();
		int width;
		if (st.empty()) width = i;
		else width = i - st.top() - 1;
		maxA = max(maxA, width * height);
	}
	st.push(i);
	}
	return maxA;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	int ans = 0;
	vector<int>tmp(m,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mat[i][j]==0)tmp[j] = 0;
			else tmp[j]++;
		}
		ans = max(ans, largestRectangleArea(tmp));
	}
	return ans;
}

//#######################################################################
//#######-------DP 56. Count Square Submatrices with All Ones | DP on Rectangles--------########
//Tutorial: https://takeuforward.org/data-structure/count-square-submatrices-with-all-1s-dp-on-rectangles-dp-56/
//Problem:  https://www.naukri.com/code360/problems/count-square-submatrices-with-all-ones_3751502

------------
Approach:
1. get the minimum from above, above left and left + 1 in the dp-th box if it is 1, else leave it as 0
------------

//---------
//Bottom Up
//---------

int countSquares(int n, int m, vector<vector<int>> &arr) {
    vector<vector<int>>dp(n, vector<int>(m,0));
    //fill the 0th row and 0th column
    for(int i=0;i<m;i++) dp[0][i] = arr[0][i] == 1;
    for(int i=0;i<n;i++) dp[i][0] = arr[i][0] == 1;
    
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            int mn = min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]}) + 1;
            if(arr[i][j]) dp[i][j] = mn;
            else dp[i][j] = 0;
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) ans+=dp[i][j];
    }

    return ans;
}

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#####################-------FINISHED--------###########################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######-------xxxxxxxx-------########
//#######-------xxxxxxxx-------########

//Graph
//Graph

- See notion notes / striver notes for details
- Think what is the starting point(in bfs)
- Grid type problems, think graph
- Always use bool type for visited array(2 bytes)
- Result can be different in bfs topological or dfs topological sort

Confusions:
1. G-17. Bipartite Graph | BFS -> little confused on queue stack also
Wrong Answer(in my way )
60 / 81 testcases passed
Input graph =
[[1],[0,3],[3],[1,2]]
2. g-40. not sure about dist[node] vs dis???? - /?????????WA on leetcode
//Problem: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/
3.todo: G-42. Floyd Warshall Algorithm - solve using dijkstra as well
4. todo: G-43. Find the City With the Smallest Number of Neighbours at a Threshold Distance - solve using dijkstra as well
5. todo: G-51. Number of Islands - II - Online Queries - DSU solve using dfs, or bfs
q.pop();//always forgets

2. G-18. Bipartite Graph | DFS - little confused on how dfs in working 
3. G-19. Detect cycle in a directed graph using DFS
4. G-20. Find Eventual Safe States - DFS (draw the tree )
5. not sure why queue is faster than pq in dijkstra, it will visit all the nodes even if we donot use 
pq, it will just not change the values
6. G-52. Making a Large Island - DSU
if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==1){
    ds.unionBySize(u,v);//a little confused
}
7. confused on the solution: https://www.geeksforgeeks.org/problems/bridge-edge-in-graph/1
8. G-55. Bridges in Graph - Using Tarjans Algorithm of time in and low time confused

Questions: 
1. How to get shortest path having negative cycle
2. How to get get all the shortest path dijkstra


Good practice: donot temper data, make a copy and solve[for this type of question, just remember]
- For undirected graph dijkstra use queue instead of priority queue, cause it does not make it different, level e same distance thakbe[binary maze question]

---------------------------------------------------------------------------------------------------------
Striver Graph Playlist: https://www.youtube.com/playlist?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn
Resource: https://takeuforward.org/graph/striver-graph-series-top-graph-interview-questions/
---------------------------------------------------------------------------------------------------------

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//##########-------Introduction to Graph--------####################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------G-1. Introduction to Graph | Types | Different Conventions Used--------########
//Tutorial: https://takeuforward.org/graph/introduction-to-graph/
//Problem: https://www.geeksforgeeks.org/problems/graph-and-vertices/1

Code:(number of undirected graph in node)
In a graph G with n vertices, maixmum number of edges possible = ( n*(n-1) ) / 2
Total number of graphs with n vertices = 2 ^ ( n*(n-1) ) / 2
example:
1LL<<((n*(n-1) )/2);

------------------------Theory----------------------------------
Graph -> having nodes and edges
Undirected Graph-> NO Direction 
Directed Graph-> With Direction (all edges are direceted)
- Nodes/Vertex is the same
- There is no specific order of numbering nodes 
- Edge -> Directed or Undirected(bi direction)
- Cycles in a Graph: Start and end at the same node(enclosed structure)
- every edge has 2 nodes in undirected graph

//Directed graph 
Acyclic Graph: Having no cycles 
DAG: 
Directed cyclic graph(not closed at the same node, no cycle having direction
, have directions but no cycle)
Path -> direction of having the edge
Degree(for undirected graph): Number of edges that are attached to a node
Degree property: total degree = 2 x edges [because every edge attached with 2 direction]
- A node cannot appear twice in a path

//Undirected graph 
- indegree(node)  [number of incoming edges]
- outdegree(node) [number of outgoing edges]


edge weight: edge having value
if weights are not assigned, we will always assume unit weight -> 1



//#######################################################################
//#######-------G-2. Graph Representation in C++ | Two Ways to Represent--------########
//Tutorial: https://takeuforward.org/graph/graph-representation-in-c/
//Problem: https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1
vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges){
    vector<vector<int>>adj(V);
    int n = edges.size();
    for(int i=0;i<n;i++){
        int u = edges[i].first, v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}

------------------------Theory----------------------------------
Input: n,m -> will always give node and edge, + edge lines
n is constant, m can be anything

Store:
1. Adjacency Matrix - (O(N*N) Space Complexity, have unused space where value is 0, so it is cosly in space)
2. Adjacency list - (O(N+2E) ~ O(N+E), Better Space Complexity)

//Code:
-------------------------------
1. Adjacency Matrix 
int v,e;//v=vertices, e = edges
cin>>v>>e;
int graph[v+1][v+1]={};
cin>>v1>>v2;
//for undirected graph, it is 2 way
graph[v1][v2]=1;
graph[v2][v1]=1;
//for weighted graph
graph[v1][v2]=weight;
-------------------------------
2. Adjacency list
vector<int>adj[10];//empty vector
scanf("%d%d", &a, &b);
adj[a].push_back(b);
adj[b].push_back(a);
//weighed graph {node, weight}
adj[u].push_back({v, wt});
adj[v].push_back({u, wt});




//#######################################################################
//#######-------G-3. Graph Representation in Java | Two Ways to Represent--------########


//#######################################################################
//#######-------G-4. What are Connected Components?--------########
//Tutorial: https://takeuforward.org/graph/connected-components-in-graphs/
//Problem: https://neetcode.io/problems/count-connected-components
class Solution {
public:
    void dfs(int i,vector<int>&vis, vector<int> adj[]){
        if(vis[i]) return;
        vis[i] = 1;
        for(auto x: adj[i]) dfs(x, vis, adj);
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<int>vis(n);
        int m = edges.size();
        for(int i=0;i<m;i++){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i, vis, adj);
                ans++;
            }
        }
        return ans;
    }
};

------------------------Theory----------------------------------
- Single Graph separated by components
- i = Go 1 to N 
- if(!visit) traverse(I)

//#######################################################################
//#######-------G-5. Breadth-First Search (BFS) | Traversal Technique in Graphs--------########
//Tutorial: https://takeuforward.org/graph/breadth-first-search-bfs-level-order-traversal/
//Problem: https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
-----------------------------
BFS in adjacency list
-----------------------------
class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool>vis(V);
        queue<int>q;
        q.push(0);//source node
        ans.push_back(0);
        vis[0] = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int x: adj[u]){
                if(!vis[x]){
                    q.push(x);
                    vis[x] = 1;
                    ans.push_back(x);
                }
            }
        } 
        return ans;
    }
};

------------------------Theory----------------------------------
2 types of graph: 0 base indexing, 1 base indexing
Breadth First Search / Level Wise
Everything depends on the starting node in bfs

go on a node and asks: who are the neighbours

Time Complexity: O(N+2E) [for undirected graph]
node goes once into the bfs, and runs its neighbours

Code:


//#######################################################################
//#######-------G-6. Depth-First Search (DFS) | Traversal Technique in Graphs--------########
//Tutorial: https://takeuforward.org/data-structure/depth-first-search-dfs/
//Problem: https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

-----------------------------
DFS in adjacency list
-----------------------------

class Solution {
  public:
    void dfs(int i,vector<int>adj[], vector<bool>&vis,vector<int>&ans){
        if(vis[i]) return;
        vis[i] = 1;
        ans.push_back(i);
        for(int x: adj[i])dfs(x, adj, vis, ans);
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        vector<bool>vis(V);
        for(int i=0;i<V;i++){
            if(!vis[i]) dfs(i,adj, vis, ans);
        }
        return ans;
    }   
};

------------------------Theory----------------------------------
- There will be plenty of dfs depending on the starting node
- Depending on the adjacency_list the traversal will change
- Time Complexity: O(N+2E) [for undirected graph]

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//##########-------Problems on BFS/DFS--------###########################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

//BFS:
vector<bool>vis(V);
queue<int>q;
q.push(0);//source node
ans.push_back(0);
vis[0] = 1;
while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int x: adj[u]){
        if(!vis[x]){
            q.push(x);
            vis[x] = 1;
            ans.push_back(x);
        }
    }
} 


//DFS: 
int visited(100);
vector <int> adj[100];
void dfs(int s) {
    if (visited[s]) return;
    visited[s] = 1;
    for (int u: adj[s]) dfs(u);
}



//#######################################################################
//#######-------G-7. Number of Provinces | Connected Components--------########
//Tutorial: https://takeuforward.org/data-structure/number-of-provinces/
//Problem: https://leetcode.com/problems/number-of-provinces

Time Complexity: O(N) + O(V+2E)

class Solution {
public:
    void dfs(int i,vector<bool>&visited,vector<int>adj[]){
        if(visited[i])return;
        visited[i] = 1;
        for(int x: adj[i])dfs(x, visited, adj);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>adj[n];
        vector<bool>visited(n);
        //converting the matrix to adjacency list
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if( isConnected[i][j] == 1 ){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                dfs(i, visited, adj);
            }
        }
        return ans;
    }
};


//#######################################################################
//#######-------G-8. Number of Islands | Number of Connected Components in Matrix--------########
//Tutorial: https://takeuforward.org/data-structure/number-of-islands/
//Problem: https://leetcode.com/problems/number-of-islands/description/


2d grid bfs
------------
BFS
Space complexity: O(N*N) + O(N*N)[for queue, all are connected, marked as 1]
------------
class Solution {
public:
    vector<int>dx{ 0,  0, 1,-1};
    vector<int>dy{-1, +1, 0, 0};
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<bool>>visited(n, vector<bool>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    ans++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j] = 1;
                    while(!q.empty()){
                        int xx = q.front().first;
                        int yy = q.front().second;
                        q.pop();
                        //go in 4 direction
                        for(int k=0;k<4;k++){
                            int x = xx + dx[k];
                            int y = yy + dy[k];
                            if( x>=0 && x<n && y<m && y>=0  && grid[x][y] != '0' && !visited[x][y]){
                                visited[x][y] = 1;
                                q.push({x,y});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};

------------
DFS:
------------
2d grid dfs

class Solution {
public:
    void dfs(int i, int j, int n, int m,vector<vector<char>>& grid,vector<vector<bool>>&visited){
        //outbound hole backtrack
        if( i<0 || i==n || j==m || j<0 ) return;
        //already visited or '0' grid then don't visit
        if(visited[i][j] || grid[i][j] == '0') return;
        visited[i][j] = 1;
        dfs(i+1,j, n, m, grid, visited);
        dfs(i-1,j, n, m, grid, visited);
        dfs(i,j-1, n, m, grid, visited);
        dfs(i,j+1, n, m, grid, visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<bool>>visited(n, vector<bool>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    ans++;
                    dfs(i, j, n, m, grid, visited);
                }
            }
        }
        return ans;
    }
};


//#######################################################################
//#######-------G-9. Flood Fill Algorithm--------########
//Tutorial: https://takeuforward.org/graph/flood-fill-algorithm-graphs/
//Problem: https://leetcode.com/problems/flood-fill/description/
(matrix ei solve korle better, instead of adjacency list)
------------
BFS
------------
class Solution {
public:
    vector<int>dx{ 0,  0,+1, -1};
    vector<int>dy{-1, +1, 0,  0};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m));
        int color_prev = image[sr][sc];

        queue<pair<int, int>>q;
        q.push({sr,sc});
        visited[sr][sc] = 1;
        image[sr][sc] = color;
        while(!q.empty()){
            int xx = q.front().first;
            int yy = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int x = xx + dx[i];
                int y = yy + dy[i];
                if( x>=0 && x<n && y<m && y>=0  && image[x][y] == color_prev && !visited[x][y]){
                    visited[x][y] = 1;
                    image[x][y] = color;
                    q.push({x,y});
                }
            }
        }

        return image;
    }
};

------------
DFS
Time complexity: O(N*M)
Space complexity: O(N*M) + O(N*M)[recursion stack space]
------------

class Solution {
public:
    void dfs(int i, int j, int n, int m, int color_prev, int color,vector<vector<int>>&image,vector<vector<bool>>&visited){
        if(i<0 || i==n || j==m || j<0) return;
        if(visited[i][j] || image[i][j]!=color_prev) return;
        visited[i][j] = 1;
        image[i][j] = color;
        dfs(i+1, j, n, m, color_prev, color, image, visited);
        dfs(i-1, j, n, m, color_prev, color, image, visited);
        dfs(i, j+1, n, m, color_prev, color, image, visited);
        dfs(i, j-1, n, m, color_prev, color, image, visited);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m));
        int color_prev = image[sr][sc];
        dfs(sr, sc, n, m, color_prev, color, image, visited);
        return image;
    }
};

//#######################################################################
//#######-------G-10. Rotten Oranges--------########
//Tutorial: https://takeuforward.org/data-structure/rotten-oranges-min-time-to-rot-all-oranges-bfs/
//Problem: https://leetcode.com/problems/rotting-oranges/description/

------------
BFS
Minimum time: that is why use bfs, going simultaneously to its neigbour
Time complexity and Space Complexity: O(N*M)
------------
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<int>dx = {1, -1, 0, 0};
        vector<int>dy = {0, 0, -1, 1};
        queue<pair<int, int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( grid[i][j] == 2 ){
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()){
            int q_all = q.size();
            bool ok = 0;
            while(q_all--){//all the added elements in queue until become 0
                int xx = q.front().first;
                int yy = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int x = xx + dx[k];
                    int y = yy + dy[k];
                    if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1){
                        ok = 1;
                        grid[x][y] = 2;
                        q.push({x,y});
                    }
                }
            }
            if(ok) ans++;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) if(grid[i][j]==1) return -1;
        }
        return ans;
    }
};

//Another approach(striver way)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int>dx = {1, -1, 0, 0};
        vector<int>dy = {0, 0, -1, 1};
        queue<pair<pair<int, int>, int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( grid[i][j] == 2 ){
                    q.push({{i,j},0});
                }
            }
        }
        
        int ans = 0;
        while(!q.empty()){
            int xx = q.front().first.first;
            int yy = q.front().first.second;
            int ct = q.front().second;
            ans = max(ct, ans);
            q.pop();
            for(int k=0;k<4;k++){
                int x = xx + dx[k];
                int y = yy + dy[k];
                if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1){
                    grid[x][y] = 2;
                    q.push({{x,y} ,ct+1});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) if(grid[i][j]==1) return -1;
        }
        return ans;
    }
};



//#######################################################################
//#######-------G-11. Detect a Cycle in an Undirected Graph using BFS--------########
//Tutorial: https://takeuforward.org/data-structure/detect-cycle-in-an-undirected-graph-using-bfs/
//Problem: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

------------
BFS
Intuition: Starting in different and colliding in the same path
Time complexity:  O(N + 2E) + O(N)
Space Complexity: O(N) + O(N) ~ O(N), Space for queue data structure and visited array.
------------

class Solution {
  public:
    bool detect(int i,vector<int> adj[],vector<bool>visited){
        queue<pair<int, int>>q;
        visited[i] = 1;
        //source, destination
        q.push({i, -1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(int x: adj[node]){
                if(!visited[x]){
                    visited[x] = 1;
                    q.push({x, node});
                }
                else if(visited[x] && x!=parent){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>visited(V);
        for(int i=0;i<V;i++){
            //start from all nodes
            if(detect(i, adj, visited)) return true;
        }
        return false;
    }
};


//#######################################################################
//#######-------G-12. Detect a Cycle in an Undirected Graph using DFS--------########
//Tutorial: https://takeuforward.org/data-structure/detect-cycle-in-an-undirected-graph-using-dfs/
//Problem: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
------------
DFS
Intuition: Starting in different and colliding in the same path
Time complexity:  O(N + 2E) + O(N)
Space Complexity: O(N) + O(N) ~ O(N), Space for recursive stack space and visited array.
------------
class Solution {
  public:
    bool detect(int i,int p, vector<int> adj[],vector<bool>visited){
        visited[i] = 1;
        for(int x: adj[i]){
            if(!visited[x]){
                if(detect(x, i, adj, visited)){
                    return true;
                }
            }
            else if(visited[x] && x!=p){//-1 is the source parent
                return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>visited(V);
        for(int i=0;i<V;i++){
            //start from all nodes
            if(!visited[i] && detect(i, -1, adj, visited)) return true;
        }
        return false;
    }
};

//#######################################################################
//#######-------G-13. Distance of nearest cell having 1 | 0/1 Matrix--------########
//Tutorial: https://takeuforward.org/graph/distance-of-nearest-cell-having-1/
//Problem: https://leetcode.com/problems/01-matrix/description/

------------
BFS
Approach: put all 0s(cause nearest 0 bolse) in the queue and build the matrix from this 
Time complexity:  O(NxM + NxMx4) ~ O(N x M)
------------

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(); 
        vector<vector<int>> ans(n, vector<int>(m));
        vector<int>dx = {0,  0, 1, -1};
        vector<int>dy = {-1, 1, 0,  0};
        queue<pair<int, int>>q;
        vector<vector<int>> visited(n, vector<int>(m));  
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }     
        }

        int v = 1;
        while(!q.empty()){
            int qsize = q.size();
            while(qsize--){
                int xx = q.front().first;
                int yy = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int x = xx + dx[k];
                    int y = yy + dy[k];
                    if( x>=0 && x<n && y>=0 && y<m && !visited[x][y]){
                        q.push({x,y});
                        visited[x][y] = 1;
                        ans[x][y] = v;
                    }
                }
            }
            v++;
        }
        return ans;
    }
};

//Another way(striver way)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(); 
        vector<vector<int>> ans(n, vector<int>(m));
        vector<int>dx = {0,  0, 1, -1};
        vector<int>dy = {-1, 1, 0,  0};
        queue<pair<pair<int, int>, int>>q;
        vector<vector<int>> visited(n, vector<int>(m));  
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }     
        }

        while(!q.empty()){
            int xx = q.front().first.first;
            int yy = q.front().first.second;
            int step = q.front().second;
            ans[xx][yy] = step;
            q.pop();
            for(int k=0;k<4;k++){
                int x = xx + dx[k];
                int y = yy + dy[k];
                if( x>=0 && x<n && y>=0 && y<m && !visited[x][y]){
                    visited[x][y] = 1;
                    q.push({{x,y},step+1});
                }
            }
        }
        return ans;
    }
};


//#######################################################################
//#######-------G-14. Surrounded Regions | Replace O's with X's--------########
//Tutorial: https://takeuforward.org/graph/surrounded-regions-replace-os-with-xs/
//Problem: https://leetcode.com/problems/surrounded-regions/description/


------------
BFS
Approach: 
If not visit from boundary, convert to 'X'
side er charpasher gular connected component visited[i][j] = 1 kora, 
          rest 'X' kra jegulate visited == 0
------------
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        queue<pair<int, int>>q;
        vector<vector<bool>>visited(n, vector<bool>(m));
        for(int i=0;i<m;i++) if(board[0][i]=='O') q.push({0,i}), visited[0][i] = 1;
        for(int i=1;i<n-1;i++) if(board[i][0]=='O') q.push({i,0}), visited[i][0] = 1;
        for(int i=0;i<m;i++) if(board[n-1][i]=='O') q.push({n-1,i}), visited[n-1][i] = 1;
        for(int i=1;i<n-1;i++) if(board[i][m-1]=='O') q.push({i,m-1}), visited[i][m-1] = 1;
        
        vector<int>dx = {1, -1, 0, 0};
        vector<int>dy = {0, 0, 1, -1};
        while(!q.empty()){
            int xx = q.front().first;
            int yy = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int x = xx + dx[i];
                int y = yy + dy[i];
                if(x>=0 && x<n && y>=0 && y<m && !visited[x][y] && board[x][y]=='O'){
                    visited[x][y] = 1;
                    q.push({x,y});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]) board[i][j] = 'X';
            }
        }
    }
};


------------
DFS
Time complexity:  O(N) + O(M) + O(NxMx4) ~ O(N x M)
Space Complexity: O(N x M), O(N x M) 
------------
class Solution {
public:
    vector<int>dx = {1, -1, 0, 0};
    vector<int>dy = {0, 0, 1, -1};
    void dfs(int xx, int yy,int n, int m, vector<vector<char>>& board, vector<vector<bool>>&visited){
        visited[xx][yy] = 1;
        for(int i=0;i<4;i++){
            int x = xx + dx[i];
            int y = yy + dy[i];
            if(x>=0 && x<n && y>=0 && y<m && !visited[x][y] && board[x][y]=='O'){
                dfs(x, y,n, m, board, visited);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m));
        for(int i=0;i<m;i++) if(board[0][i]=='O') dfs(0,i,n, m, board, visited);
        for(int i=1;i<n-1;i++) if(board[i][0]=='O') dfs(i,0,n, m, board, visited);
        for(int i=0;i<m;i++) if(board[n-1][i]=='O') dfs(n-1,i,n, m, board, visited);
        for(int i=1;i<n-1;i++) if(board[i][m-1]=='O') dfs(i, m-1,n, m, board, visited);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]) board[i][j] = 'X';
            }
        }
    }
};

//#######################################################################
//#######-------G-15. Number of Enclaves | Multi-source BFS--------########
//Tutorial: https://takeuforward.org/graph/number-of-enclaves/
//Problem: https://leetcode.com/problems/number-of-enclaves/description/



------------
BFS
Approach: Boundary connected component, Same like the above question(G-14)
Time complexity:  O(NxMx4) ~ O(N x M), For the worst case, assuming all the pieces as land, 
the BFS function will be called for (N x M) nodes and for every node, we are traversing for 4 neighbors, so it will take O(N x M x 4) time. 
Space Complexity: O(N x M), O(N x M) for the visited array, and queue space takes up N x M locations at max. 
------------
class Solution {
public:
    int numEnclaves(vector<vector<int>>&grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m));
        queue<pair<int, int>>q;
        for(int i=0;i<m;i++) if(grid[0][i]==1 && !visited[0][i]) q.push({0,i}), visited[0][i] = 1;
        for(int i=1;i<n-1;i++) if(grid[i][0]==1 && !visited[i][0]) q.push({i,0}), visited[i][0] = 1;
        for(int i=0;i<m;i++) if(grid[n-1][i]==1 && !visited[n-1][i]) q.push({n-1,i}), visited[n-1][i] = 1;
        for(int i=1;i<n-1;i++) if(grid[i][m-1]==1 && !visited[i][m-1]) q.push({i,m-1}), visited[i][m-1] = 1;

        vector<int>dx = {1, -1, 0, 0};
        vector<int>dy = {0, 0, 1, -1};
        while(!q.empty()){
            int xx = q.front().first;
            int yy = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int x = xx + dx[i];
                int y = yy + dy[i];
                if(x>=0 && x<n && y>=0 && y<m && !visited[x][y] && grid[x][y]==1){
                    visited[x][y] = 1;
                    q.push({x,y});
                }
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1)ans++;
            }
        }
        return ans;
    }
};

------------
DFS
------------

class Solution {
public:
    void dfs(int xx, int yy, int n, int m,vector<vector<int>>&grid, vector<vector<bool>>&visited  ){
        visited[xx][yy] = 1;
        vector<int>dx = {1, -1, 0, 0};
        vector<int>dy = {0, 0, -1, 1};
        for(int i=0;i<4;i++){
            int x = xx + dx[i];
            int y = yy + dy[i];
            if(x>=0 && x<n && y>=0 && y<m && !visited[x][y] && grid[x][y]==1){
                dfs(x, y, n, m, grid, visited);
            }
        }
    }

    int numEnclaves(vector<vector<int>>&grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m));
        for(int i=0;i<m;i++) if(grid[0][i]==1 && !visited[0][i]) dfs(0,i,n, m, grid, visited);
        for(int i=1;i<n-1;i++) if(grid[i][0]==1 && !visited[i][0]) dfs(i,0,n, m, grid, visited);
        for(int i=0;i<m;i++) if(grid[n-1][i]==1 && !visited[n-1][i]) dfs(n-1,i,n, m, grid, visited);
        for(int i=1;i<n-1;i++) if(grid[i][m-1]==1 && !visited[i][m-1]) dfs(i, m-1,n, m, grid, visited);

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1)ans++;
            }
        }
        return ans;
    }
};

//#######################################################################
//#######-------G-16. Number of Distinct Islands | Constructive Thinking + DFS--------########
//Tutorial: https://takeuforward.org/data-structure/number-of-distinct-islands/
//Problem: https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

------------
BFS
Approach: write bfs, and put the list in a set, print set size at the end(same approach for dfs also)
------------

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m));
        set<vector<pair<int, int>>>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    vector<pair<int, int>>v;
                    int bx = i;//basex
                    int by = j;//basey
                    v.push_back({bx-bx,by-by});
                    visited[bx][by] = 1;
                    queue<pair<int, int>> q;
                    q.push({bx,by});
                    vector<int>dx = {1,-1,0,0};
                    vector<int>dy = {0,0,1,-1};
                    while(!q.empty()){
                        int xx = q.front().first;
                        int yy = q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++){
                            int x = xx + dx[k];
                            int y = yy + dy[k];
                            if(x>=0 && x<n && y>=0 && y<m && !visited[x][y] && grid[x][y]==1){
                                v.push_back({x-bx,y-by});
                                visited[x][y] = 1;
                                q.push({x,y});
                            }
                                
                        }
                    }
                    st.insert(v);
                }
            }
        }
        return st.size();
    }
};
------------
DFS
TC: O(N x M x log(N x M)) + O(NxMx4) ~ O(N x M)
SP: O(N x M), O(N x M) 
------------
class Solution {
        void dfs(int r, int c, int rp, int cp,vector<vector<int>>&grid, vector<vector<bool>>&visited, vector<pair<int, int>>&v){
            int n = grid.size(), m = grid[0].size();
            visited[r][c] = 1;
            v.push_back({r-rp,c-cp});
            vector<int>dx = {1,-1,0,0};
            vector<int>dy = {0,0,1,-1};
            for(int k=0;k<4;k++){
                int x = r + dx[k];
                int y = c + dy[k];
                if(x>=0 && x<n && y>=0 && y<m && !visited[x][y] && grid[x][y]==1){
                    dfs(x,y, rp, cp, grid,visited, v);
                }
            }
        }
public:
    int countDistinctIslands(vector<vector<int>>&grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m));
        set<vector<pair<int, int>>>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    vector<pair<int, int>>v;
                    int bx = i;//basex
                    int by = j;//basey
                    dfs(bx, by, bx, by, grid, visited, v);
                    st.insert(v);
                }
            }
        }
        return st.size();
    }
};

//#######################################################################
//#######-------G-17. Bipartite Graph | BFS--------########
//Tutorial: https://takeuforward.org/graph/bipartite-graph-bfs-implementation/
//Problem: https://leetcode.com/problems/is-graph-bipartite/description/

Bipartite: Coloring with two colors alternatively(no two path has the same color)
------------
BFS
------------

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1);
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }

        for(int i=0;i<n;i++){
            if(color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;
                while(!q.empty()){
                    int v = q.front();
                    q.pop();
                    for(auto x: adj[v]){
                        if(color[x]==-1){
                            color[x] = !color[v];
                            q.push(x);
                        }
                        else if(color[x] == color[v]){//parenet cannot be same with child
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};



//#######################################################################
//#######-------G-18. Bipartite Graph | DFS--------########
//Tutorial: https://takeuforward.org/graph/bipartite-graph-dfs-implementation/
//Problem: https://leetcode.com/problems/is-graph-bipartite/description/

------------
DFS
TC: O(V + 2E)
SP: O(3V) ~ O(V)
------------

class Solution {
    bool dfs(int i, int now,vector<int>&color,vector<int>adj[]){
        color[i] = now;
        for(auto x: adj[i]){
            if(color[x] == -1){
                //ekbar false then keep false
                if(!dfs(x, !now, color, adj))return false;
            }
            else if(now == color[x]){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1);
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }

        for(int i=0;i<n;i++){
            if(color[i] == -1) {
                if(!dfs(i, 0, color, adj))return false;
            }
        }
        return true;
    }
};

//Another version
class Solution {
    bool dfs(int i, int now,vector<int>&color,vector<int>adj[], int ans){
        color[i] = now;
        for(auto x: adj[i]){
            if(color[x] == -1){
                ans = ans & dfs(x, !now, color, adj, ans);
            }
            else if(now == color[x]){
                ans = ans & 0;
            }
        }
        return ans;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1);
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }

        for(int i=0;i<n;i++){
            if(color[i] == -1) {
                if(!dfs(i, 0, color, adj, 1))return false;
            }
        }
        return true;
    }
};

//#######################################################################
//#######-------G-19. Detect cycle in a directed graph using DFS--------########
//Tutorial: https://takeuforward.org/data-structure/detect-cycle-in-a-directed-graph-using-dfs-g-19/
//Problem: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

Approach: 
On the same path node has to be visited again
visited and  path visited  == true , then there is a cycle
- BFS will not work for directed graph

------------
DFS
TC: O(V+E)+O(V) , where V = no. of nodes and E = no. of edges. There can be at most V components. So, another O(V) time complexity.
SP: O(2N) + O(N) ~ O(2N): O(2N) for two visited arrays and O(N) for recursive stack space.
------------


class Solution {
    bool dfs(int node, vector<bool>&pathVis,vector<bool>&visited, vector<int> adj[]){
        visited[node] = 1;
        pathVis[node] = 1;
        for(auto child: adj[node]){
            if(!visited[child]){
                if(dfs(child, pathVis, visited, adj)) return true;
            }
            else if(pathVis[child]){
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool>visited(V);
        vector<bool>pathVis(V);
        for(int i=0;i<V;i++){
            if( dfs(i, pathVis, visited, adj)  == true) return true;
        }
        return false;
    }
};



//Another approach:
3 states in visited array (that is why use int type in visited array)
0 , 1 , 2 state 

class Solution {
    bool dfs(int node,vector<int>&visited, vector<int> adj[]){
        visited[node] = 1;
        for(auto child: adj[node]){
            if(!visited[child]){
                if(dfs(child, visited, adj)) return true;
            }
            else if(visited[child]==1){
                return true;
            }
        }
        visited[node] = 2;
        return false;
    }
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>visited(V);
        for(int i=0;i<V;i++){
            if( !visited[i] && dfs(i, visited, adj)  == true) return true;
        }
        return false;
    }
};


//#######################################################################
//#######-------G-20. Find Eventual Safe States - DFS--------########
//Tutorial: https://takeuforward.org/data-structure/find-eventual-safe-states-dfs-g-20/
//Problem: https://www.geeksforgeeks.org/problems/eventual-safe-states/1

- Everynode that is connected to the cycle can never be safe node 
- everynode that is incoming to the cycle is not a safe node
- all path has to come at a terminal node -> then it is a safe node

------------
DFS
------------
class Solution {
public:
    bool dfs(int i, vector<int>adj[], vector<bool>&visited, vector<bool>&pathvisited, vector<bool>&choice){
        visited[i] = 1;
        choice[i] = 0;
        pathvisited[i] = 1;
        for(int x: adj[i]){
            if(!visited[x]){
                if(dfs(x, adj, visited, pathvisited, choice)) return true;
            }
            else if(pathvisited[x]==1){
                return true;
            }
        }
        choice[i] = 1;
        pathvisited[i] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>ans;
        vector<int>adj[V];
        vector<bool>visited(V), pathvisited(V), choice(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i, adj, visited, pathvisited, choice);
            }
        }

        for(int i=0;i<V;i++){
            if(choice[i]==1) ans.push_back(i);
        }
        return ans;
    }
};

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################nnn
//##########-------Problems on Topo Sort--------####################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
 
- Something before something, Use topological sort
- Topological sorting only exists/valid in Directed Acyclic Graph (DAG).
- Toplogical sort: In topological sorting, node u will always appear before node v if there is a directed edge from node u towards node v(u -> v).

//#######################################################################
//#######-------G-21. Topological Sort Algorithm | DFS--------########
//Tutorial: https://takeuforward.org/data-structure/topological-sort-algorithm-dfs-g-21/
//Problem: https://www.geeksforgeeks.org/problems/topological-sort/1

------------
DFS
TC: O(V+E)+O(V), where V = no. of nodes and E = no. of edges. There can be at most V components. So, another O(V) time complexity.
SC: O(2N) + O(N) ~ O(2N): O(2N) for the visited array and the stack carried during DFS calls and O(N) for recursive stack space, where N = no. of nodes.
------------

class Solution
{   
    void dfs(int i,vector<int> adj[],vector<bool>&visited,stack<int>&st){
        visited[i] = 1;
        for(int x: adj[i]){
            if(!visited[x]){
                dfs(x, adj, visited, st);
            }
        }
        st.push(i);
    }
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool>visited(V);
	    stack<int>st;
	    vector<int>ans;
	    for(int i=0;i<V;i++){
	        if(!visited[i])dfs(i, adj, visited, st);
	    }
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};

//#######################################################################
//#######-------G-22. Kahn's Algorithm | Topological Sort Algorithm | BFS--------########
//Tutorial: https://takeuforward.org/data-structure/kahns-algorithm-topological-sort-algorithm-bfs-g-22/
//Problem: https://www.geeksforgeeks.org/problems/topological-sort/1


Kahns Algorithm: Calculate indegree and from indegree find topological sorting(see striver notes for more)
- By using kahns we can use topological sort in bfs 

------------
BFS
Time Complexity: O(V+E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm.
Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the indegree array, and O(N) for the queue data structure used in BFS(where N = no.of nodes).
------------

class Solution
{   
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{

	    vector<int>ans;
	    vector<int> indegree(V);
	    for(int i=0;i<V;i++){
	       for(int x: adj[i]) indegree[x]++;
	    }
	    
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0)q.push(i);
	    }
	    
        //someone will always be in queue as it is DAG
	    while(!q.empty()){
	       int v = q.front();
	       q.pop();
	       ans.push_back(v);
	       for(int x: adj[v]){
	           indegree[x]--;
	           if(indegree[x]==0){
	               q.push(x);
	           }
	       }
	    }
	    
	    return ans;
	}
};

//#######################################################################
//#######-------G-23. Detect a Cycle in Directed Graph | Topological Sort | Kahn's Algorithm | BFS--------########
//Tutorial: https://takeuforward.org/data-structure/detect-a-cycle-in-directed-graph-topological-sort-kahns-algorithm-g-23/
//Problem: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

------------
BFS
Approach: If ct == vertices, then it is a dag, hence, toposort is available, hence no cycle,else cycle ase
Time Complexity: O(V+E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm.
Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the in-degree array, and O(N) for the queue data structure used in BFS(where N = no.of nodes).
------------

class Solution {
  public:
    bool isCyclic(int V, vector<int> adj[]) {
	    vector<int> indegree(V);
	    for(int i=0;i<V;i++){
	       for(int x: adj[i]) indegree[x]++;
	    }
	    int ct = 0;
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0)q.push(i);
	    }
	    while(!q.empty()){
	        int v = q.front();
	        q.pop();
	        ct++;
	        for(int x: adj[v]){
	            indegree[x]--;
	            if(indegree[x] == 0)q.push(x);
	        }
	    }
        
        return (ct==V?false:true);
    }
};

//#######################################################################
//#######-------G-24. Course Schedule I and II | Pre-requisite Tasks | Topological Sort--------########
//Tutorial: https://takeuforward.org/data-structure/course-schedule-i-and-ii-pre-requisite-tasks-topological-sort-g-24/

//Problem1: https://leetcode.com/problems/course-schedule/description/
------------
BFS
------------
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int>indegree(numCourses);
        for(int i=0;i<numCourses;i++){
            for(int x: adj[i]) indegree[x]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }

        int ct = 0;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            ct++;
            for(int x: adj[v]){
                indegree[x]--;
                if(indegree[x]==0)q.push(x);
            }
        }

        if(ct==numCourses) return true;//means there is no cycle
        return false;
    }
};

//Problem2: https://leetcode.com/problems/course-schedule-ii/description/
------------
BFS
------------
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            // {0, 1}
            // to finish 0 you must finish 1, 0 is dependent to 1
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int>indegree(numCourses);
        for(int i=0;i<numCourses;i++){
            for(int x: adj[i]) indegree[x]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }

        vector<int>ans;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            ans.push_back(v);
            for(int x: adj[v]){
                indegree[x]--;
                if(indegree[x]==0)q.push(x);
            }
        }

        if(ans.size()!=numCourses)ans.clear();
        return ans;
    }
};

//#######################################################################
//#######-------G-25. Find Eventual Safe States - BFS - Topological Sort--------########
//Tutorial: https://takeuforward.org/data-structure/find-eventual-safe-states-bfs-topological-sort-g-25/
//Problem: https://leetcode.com/problems/find-eventual-safe-states/description/

------------
BFS
Approach: backtracking the answer
Time Complexity: O(V+E)+O(N*logN), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm. Extra O(N*logN) for sorting the safeNodes array, where N is the number of safe nodes.
Space Complexity: O(N) + O(N) + O(N) ~ O(3N), O(N) for the indegree array, O(N) for the queue data structure used in BFS(where N = no.of nodes), and extra O(N) for the adjacency list to store the graph in a reversed order.
------------

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>ans;
        vector<int>indegree(V);
        vector<int>adj2[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<graph[i].size();j++){
                adj2[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)q.push(i);
        }
        
        while(!q.empty()){
            int v = q.front();
            q.pop();
            ans.push_back(v);
            for(auto x: adj2[v]){
                indegree[x]--;
                if(indegree[x]==0)q.push(x);
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//#######################################################################
//#######-------G-26. Alien Dictionary - Topological Sort--------########
//Tutorial: https://takeuforward.org/data-structure/alien-dictionary-topological-sort-g-26/
//Problem: https://www.geeksforgeeks.org/problems/alien-dictionary/1

------------
BFS
Approach: convert the string to directed graph, after that, use topological to find the sequence
Not possible, when: 1. abcd , abc 2. Cyclic dependency
Time Complexity: O(N*len)+O(K+E), where N is the number of words in the dictionary, ‘len’ is the length up to the index where the first inequality occurs, K = no. of nodes, and E = no. of edges.
Space Complexity: O(K) + O(K)+O(K)+O(K) ~ O(4K), O(K) for the indegree array, and O(K) for the queue data structure used in BFS(where K = no.of nodes), O(K) for the answer array and O(K) for the adjacency list used in the algorithm.
------------

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //make directed graph
        vector<int>adj[K];
        for(int i=0;i<N-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int l = 0;
            while(l<s1.size()){
                if(s1[l]!=s2[l]){
                    adj[s1[l] - 'a'].push_back(s2[l]-'a');
                    break;
                }
                l++;
            }
        }
        
        vector<int>indegree(K);
        for(int i=0;i<K;i++){
            for(int x: adj[i]){
                indegree[x]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<K;i++){
            if( indegree[i] == 0) q.push(i);
        }
        
        string s = "";
        while(!q.empty()){
            int v = q.front();
            s+= (v+'a'); 
            q.pop();
            for(int x: adj[v]){
                indegree[x]--;
                if(indegree[x]==0) q.push(x);
            }
        }
        
        return s;
    }
};

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#########-------Shortest Path Algorithms and Problems--------##########
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

Dijkstra's algorithm is necessary for graphs that can contain cycles because they cannot be topologically sorted. In other cases, the topological sort would work fine as we start from the first node, and then move on to the others in a directed manner.

//#######################################################################
//#######-------G-27. Shortest Path in Directed Acyclic Graph - Topological Sort--------########
//Tutorial: https://takeuforward.org/data-structure/shortest-path-in-directed-acyclic-graph-topological-sort-g-27/
//Problem: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

(ei question ta khatai kore bujha important beshi)

------------
BFS
Approach: 1. Do toposort 2. build the distance array from the values
Time Complexity: O(N+M) {for the topological sort} + O(N+M) {for relaxation of vertices, each node and its adjacent nodes get traversed} ~ O(N+M). Where N= number of vertices and M= number of edges.
Space Complexity:  O( N) {for the stack storing the topological sort} + O(N) {for storing the shortest distance for each node} + O(N) {for the visited array} + O( N+2M) {for the adjacency list} ~ O(N+M) .
------------
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        //1. Do toposort 2. build the distance array from the values
        vector<pair<int, int>>  adj[N];
        for(int i=0;i<M;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
        
        //1. Toposort
        vector<int>indegree(N);
        for(int i=0;i<N;i++){
            for(auto x: adj[i]){
                indegree[x.first]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<N;i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int>g;
        while(!q.empty()){
            int v = q.front();
            g.push_back(v);
            q.pop();
            for(auto x: adj[v]){
                indegree[x.first]--;
                if(indegree[x.first]==0)q.push(x.first);
            }
        }
        
        //2. build the distance array from the values
        vector<int>dist(N,1e9);
        dist[0] = 0;
        for(int i=0;i<N;i++){
            int v = g[i];
            for(auto x: adj[v]){
                int p = x.first;//to the node
                int q = x.second;//weight
                //neighbour weight e beshi cost lagle komai fela
                if( dist[v] + q < dist[p] ){
                    dist[p] = dist[v] + q;
                }
            }
        }
        
        for(int i=0;i<N;i++){
            if(dist[i]==1e9) dist[i] = -1;
        }
        
        return dist;
    }
};

//#######################################################################
//#######-------G-28. Shortest Path in Undirected Graph with Unit Weights--------########
//Tutorial: https://takeuforward.org/data-structure/shortest-path-in-undirected-graph-with-unit-distance-g-28/
//Problem: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

------------
BFS
Approach: 1. Make adjacency list 2. build distance array using formula dist[v]+1<dist[x]
Time Complexity: O(M) { for creating the adjacency list from given list edges} + O(N + 2M) { for the BFS Algorithm} + O(N) { for adding the final values of the shortest path in the resultant array} ~ O(N+2M). Where N= number of vertices and M= number of edges.
Space Complexity:  O(N) {for the stack storing the BFS} + O(N) {for the resultant array} + O(N) {for the dist array storing updated shortest paths} + O( N+2M) {for the adjacency list} ~ O(N+M). Where N= number of vertices and M= number of edges.
------------

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
		for(int i=0;i<M;i++){
			adj[edges[i][0]].push_back(edges[i][1]);
			adj[edges[i][1]].push_back(edges[i][0]);
		}
		vector<int>dist(N, 1e9);
		dist[src] = 0;
		queue<int> q;
		q.push(src);
		while(!q.empty()){
			int v = q.front();
			q.pop();
			for(int x: adj[v]){
				if(dist[v]+1<dist[x]){
					dist[x] = dist[v] + 1;
					q.push(x);
				}
			}
		}

		for(int i=0;i<N;i++) if(dist[i]==1e9) dist[i] = -1;
		return dist;
    }
};

//#######################################################################
//#######-------G-29. Word Ladder - I | Shortest Paths--------########
//Tutorial: https://takeuforward.org/graph/word-ladder-i-g-29/
//Problem: https://leetcode.com/problems/word-ladder/description/

------------
BFS
Approach: 1. Put all the words in a set 2. for each startword keep finding the word in wordlist by changing characters. If found push in the queue
Time Complexity: O(N * M * 26). Where N = size of wordList Array and M = word length of words present in the wordList..
Note that, hashing operations in an unordered set takes O(1) time, but if you want to use set here, then the time complexity would increase by a factor of log(N) as hashing operations in a set take O(log(N)) time.
Space Complexity:  O( N ) { for creating an unordered set and copying all values from wordList into it }
Where N = size of wordList Array.
------------

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st (wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(startWord);
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word==endWord){
                return steps;
            }
            for(int j=0;j<word.size();j++){
                for(char i='a';i<='z';i++){
                    string nword = word;
                    nword[j] = i;
                    if( st.find(nword)!=st.end() ){
                        st.erase(nword);
                        q.push({nword, steps+1});
                    }
                }
            }
        }
        return 0;
    }
};


//#######################################################################
//#######-------G-30. Word Ladder - 2 | Shortest Paths--------########
//Tutorial: https://takeuforward.org/graph/g-30-word-ladder-ii/
//Problem: https://leetcode.com/problems/word-ladder-ii/description/

build array along the way

//#######################################################################
//#######-------G-31. Word Ladder - 2 | Optimised Approach for Leetcode--------########
//Tutorial: https://takeuforward.org/graph/word-ladder-ii-optimised-approach-g-31/
//Problem: https://leetcode.com/problems/word-ladder-ii/description/


//#######################################################################
//#######-------G-32. Dijkstra's Algorithm - Using Priority Queue - C++ and Java - Part 1--------########
//Tutorial: https://takeuforward.org/data-structure/dijkstras-algorithm-using-priority-queue-g-32/
//Problem: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

dijkstra does not work in negative weight and negative cycle, fall in infiinte loop
0 -> 1 (with -2 weight not possible)
------------
BFS
Approach: 1. build distance array using formula dist[v]+1<dist[x] [Must use priority queue]
Time Complexity: O( E log(V) ), Where E = Number of edges and V = Number of Nodes.
Space Complexity: O( |E| + |V| ), Where E = Number of edges and V = Number of Nodes.
------------

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
		vector<pair<int, int>> adj2[V];
		
		for(int i=0;i<V;i++){
			for(int j=0;j<adj[i].size();j++){
				adj2[i].push_back({adj[i][j][0], adj[i][j][1]});
			}
		}

		// for(int i=0;i<V;i++){
		// 	cout<< i << endl;
		// 	for(auto x: adj2[i]){
		// 		cout<< x.first << ' ' << x.second << endl;
		// 	}
		// 	cout<<endl<<endl;
		// }

		vector<int>dist(V, 1e9);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({S, 0});
		dist[S] = 0;
		while(!pq.empty()){
			int nd = pq.top().first;
			int wg = pq.top().second;//this is just for optimizing time complexity, else it is not needed
			pq.pop();
			for(auto [x,y]: adj2[nd]){
				if(dist[nd] + y < dist[x] ){
					dist[x] = dist[nd] + y;
					pq.push({x, dist[x]});
				}
			}
		}
		for(int i=0;i<V;i++) if(dist[i]==1e9) dist[i] = -1;

        return dist;
	}
};

int main()
{
    // Driver code.
    int V = 3, E = 3, S = 2;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges;
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    int i = 0;
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);

    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}


//////////////////////////////////////////////////////////////////
//another version gfg
class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>dist(V, 1e9);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({0, S});
		dist[S] = 0;
		while(!pq.empty()){
			int nd = pq.top().second;
			int wg = pq.top().first;//this is just for optimizing time complexity, else it is not needed, 
            //or can be used like this, wg + y < dist[x] 
			pq.pop();
			for(auto v: adj[nd]){
			    int x = v[0];
			    int y = v[1];
				if(dist[nd] + y < dist[x] ){
					dist[x] = dist[nd] + y;
					pq.push({dist[x], x});
				}
			}
		}
        return dist;
    }
};

//#######################################################################
//#######-------G-33. Dijkstra's Algorithm - Using Set - Part 2--------########
//Tutorial: https://takeuforward.org/data-structure/dijkstras-algorithm-using-set-g-33/
//Problem: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1


------------
BFS
Time Complexity : O( E log(V) ) Where E = Number of edges and V = Number of Nodes.
Space Complexity : O( |E| + |V| ) Where E = Number of edges and V = Number of Nodes.
------------

class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>dist(V, 1e9);
		set<int> st;
		st.insert(S);
		dist[S] = 0;
		while(!st.empty()){
			int nd = (*st.begin());
			st.erase(*st.begin());
			for(auto x: adj[nd]){
			    int adjn = x[0];
			    int w = x[1];
				if(dist[nd] + w < dist[adjn]){
                    //if(dist[adjn]!=1e9)st.erase(adjn);
					dist[adjn] = dist[nd] + w;
					st.insert(adjn);
				}
			}
		}
        return dist;
    }
};


//#######################################################################
//#######-------G-34. Dijkstra's Algorithm - Why PQ and not Q, Intuition, Time Complexity Derivation - Part 3--------########
//Tutorial: https://takeuforward.org/data-structure/g-34-dijkstras-algorithm-intuition-and-time-complexity-derivation/

Theory 

//#######################################################################
//#######-------G-35. Print Shortest Path - Dijkstra's Algorithm--------########
//Tutorial: https://takeuforward.org/data-structure/g-35-print-shortest-path-dijkstras-algorithm/
//Problem: https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

------------
BFS
Approach: build a parent array and backtrack the path from n to 1
Time Complexity: O( E log(V) ) { for Dijkstra’s Algorithm } + O(V) { for backtracking in order to find the parent for each node } Where E = Number of edges and V = Number of Nodes.
Space Complexity: O( |E| + |V| ) { for priority queue and dist array } + O( |V| ) { for storing the final path } Where E = Number of edges and V = Number of Nodes.
------------
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector< pair<int, int> >adj[n+1];
        // node -> {directed node, weight}
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>> > pq;
        pq.push({0, 1});//{weight, node}
        
        vector<int> dist(n+1, 1e9), parent(n+1, -1), path;
        parent[1] = 1;//1 er parent 1 e
        dist[1] = 0; //distance of source node
        while(!pq.empty()){
            int nd = pq.top().second;
            pq.pop();
            for(auto v: adj[nd]){
                int x = v.first;
                int y = v.second;
                if(dist[x] > dist[nd] + y ){
                    dist[x] = dist[nd] + y;
                    pq.push({dist[x], x});
                    parent[x] = nd;//new parent 
                }
            }
        }
        
        if(dist[n]==1e9) return {-1};
        
        int i = n;
        while(1){
            path.push_back(i);
            i = parent[i];
            if(i==1){
                path.push_back(i);
                break;
            }
            if(i==-1)return {-1};
        }
        path.push_back(dist[n]);// first element is the weight of the path acc to gfg
        reverse(path.begin(), path.end());
        return path;
    }
};

------------
//CF Problem: https://codeforces.com/problemset/problem/20/C
------------
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve(){
	int n, m;cin>>n>>m;
	vector<vector<int>>edges;
	for(int i=0;i<m;i++){
		int x, y, z;cin>> x >> y >> z;
		edges.push_back({x,y,z});
	}

	vector< pair<int, int> >adj[n+1];
	for(int i=0;i<m;i++){
		adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
		adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
	}
	priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>> > pq;
	pq.push({0, 1});
	
	vector<int> dist(n+1, 1e19), parent(n+1, -1), path;
	parent[1] = 1;
	dist[1] = 0;
	while(!pq.empty()){
		int nd = pq.top().second;
		pq.pop();
		for(auto v: adj[nd]){
			int x = v.first;
			int y = v.second;
			if(dist[x] > dist[nd] + y ){
				dist[x] = dist[nd] + y;
				pq.push({dist[x], x});
				parent[x] = nd;
			}
		}
	}
	
	
	int i = n;
	while(1){
		path.push_back(i);
		i = parent[i];
		if(i==1){
			path.push_back(i);
			break;
		}
		if(i==-1){
			cout<< -1 <<endl;
			return;
		}
	}
	reverse(path.begin(), path.end());
	for(auto x: path)cout << x << ' ';
	cout<<endl;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1;
	//cin >> t;
	while(t--)solve(); 
	return 0;
}


//#######################################################################
//#######-------G-36. Shortest Distance in a Binary Maze--------########
//Tutorial: https://takeuforward.org/data-structure/g-36-shortest-distance-in-a-binary-maze/
//Problem: https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

2d grid dijkstra
------------
BFS
Approach: apply bfs and use dijkstra algo for undirected graph -> dist[x][y] > dist[xx][yy] + 1
Time Complexity: O( 8*N*M ) { N*M are the total cells, for each of which we also check 8 adjacent nodes for the shortest path length}, Where N = No. of rows of the binary maze and M = No. of columns of the binary maze.
Space Complexity: O( N*M ), Where N = No. of rows of the binary maze and M = No. of columns of the binary maze.
------------

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<int> dirx = {1, -1, 0, 0, 1, -1, -1,  1};
        vector<int> diry = {0, 0, -1, 1, -1, 1,  -1, 1};
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        
        int sx = 0, sy = 0;
        int dx = n-1, dy = n-1;
        dist[sx][sy] = 1;

        if(grid[sx][sy]==1) return -1;

        queue<pair< int, pair<int, int> > >q;
        q.push({0, {sx, sy}});
        
        while(!q.empty()){
            int xx = q.front().second.first;
            int yy = q.front().second.second;
            //int wg = q.front().first;
            q.pop();
            for(int k=0;k<8;k++){
                int x = xx + dirx[k];
                int y = yy + diry[k];
                if(x>=0 && x<n && y>=0 && y<n &&  grid[x][y] == 0 && dist[x][y] > dist[xx][yy] + 1){
                    dist[x][y] = dist[xx][yy] + 1;
                    q.push({dist[x][y], {x,y}});
                }
            }
        }
        
        if(dist[dx][dy]==1e9) return -1;
        return dist[dx][dy];
    }
};

//#######################################################################
//#######-------G-37. Path With Minimum Effort--------########
//Tutorial: https://takeuforward.org/data-structure/g-37-path-with-minimum-effort/
//Problem: https://leetcode.com/problems/path-with-minimum-effort/description/

------------
BFS
Approach: apply little dijkstra algo and if dist[r][c]>diff keep updating
Time Complexity: O( 4*N*M * log( N*M) ) { N*M are the total cells, for each of which we also check 4 adjacent nodes for the minimum effort and additional log(N*M) for insertion-deletion operations in a priority queue }
Where, N = No. of rows of the binary maze and M = No. of columns of the binary maze.
Space Complexity: O( N*M ) { Distance matrix containing N*M cells + priority queue in the worst case containing all the nodes ( N*M) }.
------------

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), columns = heights[0].size();

        vector<vector<int>> dist(rows, vector<int>(columns, 1e9));
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1,-1, 0,  0};
        priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> >>, greater<pair<int, pair<int, int> >>> pq;
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        while(!pq.empty()){
            int w = pq.top().first;
            int rr = pq.top().second.first;
            int cc = pq.top().second.second;
            pq.pop();
            for(int k=0;k<4;k++){
                int r = rr + dx[k];
                int c = cc + dy[k];
                if(r>=0 && r<rows && c>=0 && c<columns){
                    int diff = max(abs(heights[r][c] - heights[rr][cc]), w);
                    if(dist[r][c]>diff){
                        dist[r][c] = diff;
                        pq.push({diff,{r,c}});
                    }
                }
            }
        }
        
        return dist[rows-1][columns-1]; 
    }
};

//#######################################################################
//#######-------G-38. Cheapest Flights Within K Stops--------########
//Tutorial: https://takeuforward.org/data-structure/g-38-cheapest-flights-within-k-stops/
//Problem: https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

First priority should be steps
steps are increasing by +1, that is why queue can be used instead of priority queue
------------
BFS
Approach: apply dijkstra
Time Complexity: O( N ) { Additional log(N) of time eliminated here if we’re using a simple queue rather than a priority queue which is usually used in Dijkstra’s Algorithm }.
Where N = Number of flights / Number of edges.
Space Complexity:  O( |E| + |V| ) { for the adjacency list, priority queue, and the dist array }.
Where E = Number of edges (flights.size()) and V = Number of Airports.
------------

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];

        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        vector<int> dist(n, 1e9);
        //steps, cost, node
        priority_queue< tuple<int, int,int> ,vector< tuple<int, int,int> >, greater<tuple<int, int,int>> > pq;
        pq.push({0, 0, src});
        dist[src] = 0;
        while(!pq.empty()){
            auto [steps, cost , node] = pq.top();
            pq.pop();
            for(auto x: adj[node]){
                int nd = x.first;
                int wg = x.second;
                if(steps<=k && dist[nd] > cost+wg){
                    dist[nd] = cost+wg;
                    pq.push({steps+1, dist[nd], nd});
                }
            }
        }
        return dist[dst]==1e9?-1:dist[dst];
    }
};

//#######################################################################
//#######-------G-39. Minimum Multiplications to Reach End--------########
//Tutorial: https://takeuforward.org/graph/g-39-minimum-multiplications-to-reach-end/
//Problem: https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

First priority should be steps
steps are increasing by +1, that is why queue can be used instead of priority queue
------------
BFS
Approach: 1 to 1e5 prjnto dist array maintain kora
Time Complexity : O(100000 * N) 
Where 100000 are the total possible numbers generated by multiplication (hypothetical) and N = size of the array with numbers of which each node could be multiplied.
Space Complexity :  O(100000 * N) 
Where 100000 are the total possible numbers generated by multiplication (hypothetical) and N = size of the array with numbers of which each node could be multiplied. 100000 * N is the max possible queue size. The space complexity of the dist array is constant.
------------
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        //steps, node
        queue<pair<int, int>> q;
        q.push({0,start});
        vector<int>dist(100000, 1e9);
        dist[start] = 0;
        while(!q.empty()){
            int nd = q.front().second;
            int steps = q.front().first;
            if(nd==end){
                return steps;
            }
            q.pop();
            for(int x: arr){
                int v = (x * nd)%100000;
                if( dist[v] > dist[nd] + 1){//if smaller then enter
                    dist[v] = dist[nd] + 1;
                    q.push({steps+1, v});
                }
            }
            
        }
        
        return dist[end]==1e9?-1:dist[end];
        
    }
};

//#######################################################################
//#######-------G-40. Number of Ways to Arrive at Destination--------########
//Tutorial: https://takeuforward.org/data-structure/g-40-number-of-ways-to-arrive-at-destination/
//Problem: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

if you know how many ways you have come to a node then you donot need source node 
------------
BFS
Approach: keep pushing {distance, node} in priority queue and remember the total ways[number]
Time Complexity: O( E* log(V)) { As we are using simple Dijkstra's algorithm here, the time complexity will be or the order E*log(V)} Where E = Number of edges and V = No. of vertices.
Space Complexity :  O(N) { for dist array + ways array + approximate complexity for priority queue }Where, N = Number of nodes.
------------
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>>adj[n];
        int md = 1e9+7;
        for(int i=0;i<roads.size();i++){
            adj[ roads[i][0] ].push_back({ roads[i][1],roads[i][2] });
            adj[ roads[i][1] ].push_back({ roads[i][0],roads[i][2] });
        }
        //cost, destination
        priority_queue< pair<int, int> , vector< pair<int, int> > , greater< pair<int, int> > > pq;
        pq.push({0,0});
        vector<long long>dist(n, LLONG_MAX), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        while(!pq.empty()){
            auto [dis, node] = pq.top();
            pq.pop();
            for(auto x: adj[node]){
                long long nd = x.first;//destination
                long long d = x.second;//
                if(dist[nd] > dis + d){//not sure about dist[node] vs dis????
                    dist[nd] = dis + d;
                    ways[nd] = ways[node];
                    pq.push({dist[nd], nd});
                }
                else if(dist[nd] == dis + d) ways[nd] = (ways[nd] + ways[node])%md;
            }
        }
        return ways[n-1]%md;
    }
};

//#######################################################################
//#######-------G-41. Bellman Ford Algorithm--------########
//Tutorial: https://takeuforward.org/data-structure/bellman-ford-algorithm-g-41/
//Problem: https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
- dijkstra and bellman ford is single source shortest path algorithm
Bellman Ford Algorithm: Helps to detect negative cycles as well, only application in directed graph 
for directed graph change it to undirected graph in bellman ford
dijkstra + n-1 iternation
- The Bellman-Ford algorithm is a way to find single source shortest paths in a graph with negative edge weights (but no negative cycles).
relax all the edges n-1 times sequentially
complete all the edges n-1 times 
in nth time the distance will be reducing - for negative cycle

------------
BFS
Approach: Run dijkstra N-1 times(edges order does not matter)
Time Complexity: O(V*E), where V = no. of vertices and E = no. of Edges.
Space Complexity: O(V) for the distance array which stores the minimized distances.
------------

class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        int m = edges.size();
        vector<int>dist(V,1e8);
        dist[S] = 0;
        int times = V-1;//all nodes - 1
        while(times--){
            for(int i=0;i<m;i++){
                int n1 = edges[i][0];
                int n2 = edges[i][1];
                int wg = edges[i][2];
                if( dist[n1]!= 1e8 && dist[n1] + wg < dist[n2] ){
                    dist[n2] = dist[n1] + wg;
                }
            }
        }
        
        for(int i=0;i<m;i++){
                int n1 = edges[i][0];
                int n2 = edges[i][1];
                int wg = edges[i][2];
                if( dist[n1]!= 1e8 && dist[n1] + wg < dist[n2] ){
                    return {-1};
                }
            }
        
        return dist;
    }
};


//#######################################################################
//#######-------G-42. Floyd Warshall Algorithm--------########
//Tutorial: https://takeuforward.org/data-structure/floyd-warshall-algorithm-g-42/
//Problem: https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
//Yt1: https://youtu.be/YbY8cVwWAvw
//Yt2: https://youtu.be/tFQAoyEu6Bk


- Floyd Warshall is multi source shortest path algorithm
- If there are no negative values, you can use dijkstra for all the values individually - N * Elogv (better than N^3)
- not possible for negative cycle
- if source to source distance is negative, then there is cycle exits

------------
Brute Force(Floyd Warshall)
Approach: 
1. Make all diagonal 0, put all the values 
2. keep finding values for each nodes via other node
Formula: matrix[i][j] = min(matrix[i][j], matrix[i][node] + matrix[node][j]); {via a matrix way, or the matrix way}
Time Complexity: O(V3), as we have three nested loops each running for V times, where V = no. of vertices.
Space Complexity: O(V2), where V = no. of vertices. This space complexity is due to storing the adjacency matrix of the given graph.
------------

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    
	    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == -1)matrix[i][j] = 1e9;
            }
        }
	    
	    for(int node=0;node<n;node++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                matrix[i][j] = min(matrix[i][j], matrix[i][node] + matrix[node][j]);
	            }
	        }
	    }
	    
	    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 1e9)matrix[i][j] = -1;
            }
        }
	    
	}
};

//#######################################################################
//#######-------G-43. Find the City With the Smallest Number of Neighbours at a Threshold Distance--------########
//Tutorial: https://takeuforward.org/data-structure/find-the-city-with-the-smallest-number-of-neighbours-at-a-threshold-distance-g-43/
//Problem: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/


------------
Brute Force(Floyd Warshall)
Approach: 1. Apply floyd warshall 2. Find the max node with least cities connected in the distanceThreshold
Time Complexity: O(V3), as we have three nested loops each running for V times, where V = no. of vertices.
Space Complexity: O(V2), where V = no. of vertices. This space complexity is due to storing the adjacency matrix of the given graph.
------------

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>mat(n, vector<int>(n,1e9));
        for(int i=0;i<edges.size();i++){
            mat[edges[i][0]][edges[i][1]] = edges[i][2];
            mat[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for(int i=0;i<n;i++) mat[i][i] = 0;

        //build the matrix array 
        for(int node=0;node<n;node++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mat[i][j] = min(mat[i][j], mat[i][node] + mat[node][j]);
                }
            }
        }

        int mn = 1e9;
        int node_ans = -1;
        for(int i=0;i<n;i++){
            int ct = 0;
            for(int j=0;j<n;j++){
                if(mat[i][j]<=distanceThreshold) ct++;
            }
            if(ct<=mn){
                mn = ct;
                node_ans = i;
            }
        }
        return node_ans;
    }
};

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//##########-------MinimumSpanningTree/Disjoint Set--------##############
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------G-44. Minimum Spanning Tree - Theory--------########
//Tutorial: https://takeuforward.org/data-structure/minimum-spanning-tree-theory-g-44/

Minimum Spanning Tree - MST 
MST: A tree which have n nodes and n-1 edges, and all nodes are reachable from each other
everything is in a single component
a graph can have a lot of spanning tree
- The tree which has the minimum edges(in summation, minimum sum), is the mst

MST finding algorithm:
1. Prims algorithm 
2. Kruskal algorithm(must know disjoint set)

//#######################################################################
//#######-------G-45. Prim's Algorithm - Minimum Spanning Tree--------########
//Tutorial: https://takeuforward.org/data-structure/prims-algorithm-minimum-spanning-tree-c-and-java-g-45/
//Problem: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
//Yt:  https://youtu.be/mJcZjjKzeqk
//Yt2: https://youtu.be/KwYMYX0a73k

Intuition: Going Greedy is the intuition

Steps to find mst using prims algo(in khatai): 
From graph
1. Loop delete 
2. Parallel edge delete 
3. There should be no cycle in new mst

- Helps finding sum as well as the tree 

------------
Steps (in code)
1. Mark the visited array as 0 for all the nodes
2. Start with 0th node and push
(0,0,-1)//weight, node, parent
explanation:  -1 means 0 is the genesis node
Mark 0 as visited
3. Push all the neighbours of 0 in pq Do not mark them visited  (footnote 1)
Since its a min heap the edge with minimum weight will be at the top
4. Pick up the top edge , insert it in the mst , mark the picked node as visited , insert all neighbours of picked node into pq
5. keep repeating steps 3 and 4 untill all the nodes have been picked up and thats when the algorithm ends

footnote:
1. why to not mark it visited?
in bfs , when we push the element inside a queue we mark it as visited cause that element will be picked up later for sure (algorithm ends only when the queue is empty )
but in msts case even if we push the edge into pq , theres no surety that the edge will be picked up . when prims algo ends there are still a few non accepted edges present in the pq hence we only mark it visited once its picked up from pq


------------
BFS
Approach: 
If not visited keep taking the weight of the destination value, keep doing it until all are visited
Time Complexity: O(E*logE) + O(E*logE)~ O(E*logE), where E = no. of given edges.
Space Complexity: O(E) + O(V), where E = no. of edges and V = no. of vertices. O(E) occurs due to the size of the priority queue and O(V) due to the visited array. If we wish to get the mst, we need an extra O(V-1) space to store the edges of the most.
------------

////////////////////////
------------------------
--Total sum of MST--
------------------------
////////////////////////
class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {   
        
        priority_queue< pair<int, int> , 
        vector< pair<int, int> > , greater < pair<int, int> > >pq;
        pq.push({0, 0});
        vector<int>visited(V,0);
        int sum = 0;
        while(!pq.empty()){
            int wg = pq.top().first;
            int nd = pq.top().second;
            pq.pop();
            if(!visited[nd]){
                visited[nd] = 1;
                sum+=wg;
                for(auto x: adj[nd]){
                   if(!visited[x[0]])pq.push({x[1], x[0]});
                }
            }
        }
        return sum;
    }
};

////////////////////////
------------------------
--Total sum + the tree(parents) of MST--
------------------------
////////////////////////

class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {   
        
        priority_queue<pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        pq.push({0, {0, -1}});
        vector<int>visited(V,0), parent(V, -1);
        parent[0] = 0;
        int sum = 0;
        while(!pq.empty()){
            int wg = pq.top().first;
            int nd = pq.top().second.first;
            int par = pq.top().second.second;
            pq.pop();
            if(!visited[nd]){
                visited[nd] = 1;
                sum+=wg;
                for(auto x: adj[nd]){
                   if(!visited[x[0]])pq.push({x[1],{x[0], nd}}),parent[x[0]] = nd;
                }
            }
        }
        
        for(auto x: parent)cout<< x << ' ';
        cout<<endl;
        
        return sum;
    }
};


//#######################################################################
//#######################################################################
------------------------------DSU----------------------------------------
//#######################################################################
//#######################################################################

//#######################################################################
//#######-------G-46. Disjoint Set | Union by Rank | Union by Size | Path Compression--------########
//Tutorial: https://takeuforward.org/data-structure/disjoint-set-union-by-rank-union-by-size-path-compression-g-46/

- When dynamically changing graphs use DSU 

----------------------------------
//Problem: https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1
int find(int A[],int X)
{
    if(A[X]==X) return X;
    return A[X] = find(A, A[X]);
}
void unionSet(int A[],int X,int Z)
{
	int u = find(A, X);
	int v = find(A, Z);
	if(u==v) return;
	A[u] = v;
}

----------------------------------
- We are making a datastructure here
Disjoing Set working:(TC: O(4alpha))
- Finding Parents
- Finding Union(1. rank, 2. size)

Disjoint set: 
- Helps to find out if nodes in the same component in constant time(kon node kon component er)
- Union (in broad terms this method basically adds an edge between two nodes)
ultimate parent is the boss
path compression -> find parent in change it with ultimate parent

dynamic graphs: Graph that keeps changing


------------
Making Datastructure DSU
Approach: see striver notes
------------

//Disjoint Set Union - By Rank and By Size 
#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> rank, parent, size;
public:
    //initialize the values
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    //this will keep finding the ultimate parent of each node
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    //Method1
    //keep updating the tree as nodes are gets added
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    //Method2
    //keep updating the tree as nodes are gets added
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int main() {
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}


//#######################################################################
//#######-------G-47. Kruskal's Algorithm - Minimum Spanning Tree--------########
//Tutorial: https://takeuforward.org/data-structure/kruskals-algorithm-minimum-spanning-tree-g-47/
//Problem: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

------------
Approach: 
1. Sort the edges by weight
2. If u,v do not belong to the ultimate same parent, then add in the tree 
If ultimate parent is same donot add
------------

class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {   
        vector<pair<int, pair<int, int>> > edges;
        for(int i=0;i<V;i++){
            for(auto x: adj[i]) edges.push_back({x[1], {x[0], i}});
        }
        sort(edges.begin(),edges.end());
        int n = edges.size(), sum = 0;
        DisjointSet ds(V);
        for(int i=0;i<n;i++){
            int n1 = edges[i].second.first;
            int n2 = edges[i].second.second;
            if(ds.findUPar(n1) != ds.findUPar(n2)){
                sum+= edges[i].first;
                ds.unionBySize(n1, n2);
            }
        }
        return sum;
    }
};

//#######################################################################
//#######-------G-48. Number of Provinces - Disjoint Set--------########
//Tutorial: https://takeuforward.org/data-structure/number-of-provinces-disjoint-set-g-48/
//Problem: https://www.geeksforgeeks.org/problems/number-of-provinces/1

------------
DSU
Approach: 
The number of ultimate parents they themselves is the answer
Time Complexity: O(N2)+O(N* 4α) ~ O(N2)+O(N) where N = no. of nodes. 
O(N2) for visiting the adjacency matrix and O(N) for the counting of ultimate parents. 4α is so small that this term can be ignored.
Space Complexity: O(2N), where N = no. of nodes. O(2N) for the two arrays parent and size(or rank) of size N.
------------

class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        DisjointSet ds(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if( adj[i][j] == 1 ){
                    ds.unionBySize(i,j);
                }
            }
        }
        
        int ans = 0;
        for(int i=0;i<V;i++){
            if(ds.parent[i]==i){//total parents is they themselves
                ans++;
            }
        }
        return ans;
    }
};


//#######################################################################
//#######-------G-49. Number of Operations to Make Network Connected - DSU--------########
//Tutorial: https://takeuforward.org/data-structure/number-of-operations-to-make-network-connected-dsu-g-49/
//Problem: https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

------------
DSU
Approach: 
if ( Total connected components - 1 <= extra edges) return Total connected components -1
else -1
extra edges: if both the parents are same then it is an extra edge

Time Complexity: O(E*4α)+O(N*4α) where E = no. of edges and N = no. of nodes. The first term is to calculate the number of extra edges and the second term is to count the number of components. 4α is for the disjoint set operation we have used and this term is so small that it can be considered constant.
Space Complexity: O(2N) where N = no. of nodes. 2N for the two arrays(parent and size) of size N we have used inside the disjoint set.
------------

class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& edges) {
        int extra = 0, con = 0;
        DisjointSet ds(n);
        for(int i=0;i<edges.size();i++){
            if( ds.findUPar(edges[i][0]) == ds.findUPar(edges[i][1]) ) extra++;
            else ds.unionBySize(edges[i][0], edges[i][1]);
        }
        for(int i=0;i<n;i++){
            if( ds.parent[i] == i ) con++;
        }
        if(extra>=con-1) return con-1;
        else return -1;
    }
};

//#######################################################################
//#######-------G-50. Accounts Merge - DSU--------########
//Tutorial: https://takeuforward.org/data-structure/accounts-merge-dsu-g-50/
//Problem: https://leetcode.com/problems/accounts-merge/description/

------------
DSU
Approach: 
add all edges to corresponding numbers
1. Connect the nodes(strings) 
2. Merge the nodes/mails if same name is found(with the same parent)
3. Print the answer

Time Complexity: O(N+E) + O(E*4ɑ) + O(N*(ElogE + E)) where N = no. of indices or nodes and E = no. of emails. The first term is for visiting all the emails. The second term is for merging the accounts. And the third term is for sorting the emails and storing them in the answer array.
Space Complexity: O(N)+ O(N) +O(2N) ~ O(N) where N = no. of nodes/indices. The first and second space is for the ‘mergedMail’ and the ‘ans’ array. The last term is for the parent and size array used inside the Disjoint set data structure.

------------



//#######################################################################
//#######-------G-51. Number of Islands - II - Online Queries - DSU--------########
//Tutorial: https://takeuforward.org/graph/number-of-islands-ii-online-queries-dsu-g-51/
//Problem: https://www.geeksforgeeks.org/problems/number-of-islands/1
//https://www.naukri.com/code360/problems/number-of-islands-ii_1266048

------------
DSU
Approach: 
Look if the grid has been used previosuly(use visited array), if so and u,v has different parent then ct--;
vis[n][m] = kon ghortate kaj hoise oita track rakhar jnno visited array, age kaj hoile ar kaj na kora, ager answer print kora

Time Complexity: O(Q*4α) ~ O(Q) where Q = no. of queries. The term 4α is so small that it can be considered constant.
Space Complexity: O(Q) + O(N*M) + O(N*M), where Q = no. of queries, N = total no. of rows, M = total no. of columns. The last two terms are for the parent and the size array used inside the Disjoint set data structure. The first term is to store the answer.

------------

class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        vector<int>ans;
        vector<vector<int>>vis(n, vector<int>(m));
        int ct = 0;
        vector<int>dx = {1,-1,0,0};
        vector<int>dy = {0,0,1,-1};
        for(int i=0;i<operators.size();i++){
            int px = operators[i][0], py = operators[i][1];
            int u = m * px + py;
            if(vis[px][py]==1){
                ans.push_back(ct);
                continue;
            }
            ct++;
            vis[px][py] = 1;
            for(int k=0;k<4;k++){
                int x = px + dx[k];
                int y = py + dy[k];
                int v = m*x + y;
                if(x>=0 && x<n && y>=0 && y<m && vis[x][y]==1 && ds.findUPar(u) != ds.findUPar(v)){
                    ds.unionBySize(u,v);
                    ct--;
                }
            }
            ans.push_back(ct);
        }
        return ans;
    }
};

//#######################################################################
//#######-------G-52. Making a Large Island - DSU--------########
//Tutorial: https://takeuforward.org/data-structure/making-a-large-island-dsu-g-52/
//Problem: https://leetcode.com/problems/making-a-large-island/description/

------------
DSU
Approach: 
1. Using DSU get the size of every component
2. Convert 0 to 1, keep taking the distinct ultimate parents
3. Finally, Keep taking the max answer

Time Complexity: O(N2)+O(N2) ~ O(N2) where N = total number of rows of the grid. Inside those nested loops, all the operations are taking apparently constant time. So, O(N2) for the nested loop only, is the time complexity.
Space Complexity: O(2*N2) where N = the total number of rows of the grid. This is for the two arrays i.e. parent array and size array of size N2 inside the Disjoint set.

------------

class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>&grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        vector<int>dx = {0,0,-1,1};
        vector<int>dy = {-1,1,0,0};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int u = i*n + j;
                    for(int k=0;k<4;k++){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        int v = x*n + y;
                        if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==1){
                            ds.unionBySize(u,v);//a little confused
                        }
                    }
                }
            }
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    set<int>st;
                    for(int k=0;k<4;k++){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        int v = x*n + y;
                        if(x>=0 && x<n && y >=0 && y<n && grid[x][y]==1){
                            st.insert(ds.findUPar(v));
                        }
                    }
                    int ct = 1;
                    for(int v: st) ct+= ds.size[v];
                    ans = max(ans, ct);
                } 
            }
        }
        
        ans = max(ans, ds.size[ds.findUPar(0)]);//all are 1
        
        return ans;
    }
};

//#######################################################################
//#######-------G-53. Most Stones Removed with Same Row or Column - DSU--------########
//Tutorial: https://takeuforward.org/data-structure/most-stones-removed-with-same-row-or-column-dsu-g-53/
//Problem: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/

- In connection we use DSU, not traversal techniques

//#######################################################################
//#######-------Swim in rising water--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/swim-in-rising-water/description/



//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//####################-------Other Algorithms--------####################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------G-54. Strongly Connected Components - Kosaraju's Algorithm--------########
//Tutorial: https://takeuforward.org/graph/strongly-connected-components-kosarajus-algorithm-g-54/
//Problem: https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

SCC -> Strongly Connected Components(kosaraju algo)
Questions: Figure out the number of scc, number of scc
- Only valid for directed graph
pair that is reachable each other == scc

reverse the edges
starting time finishing time
thought: stopping one guy to go to other


------------
Kosarajus Algorithm
Approach/Steps: 
1. Sort all the edges according to the finishing line(by running dfs, putting in stack)
2. Reverse the graph 
3. Do a dfs of connected component

Time Complexity: O(V+E) + O(V+E) + O(V+E) ~ O(V+E) , where V = no. of vertices, E = no. of edges. The first step is a simple DFS, so the first term is O(V+E). The second step of reversing the graph and the third step, containing DFS again, will take O(V+E) each.
Space Complexity: O(V)+O(V)+O(V+E), where V = no. of vertices, E = no. of edges. Two O(V) for the visited array and the stack we have used. O(V+E) space for the reversed adjacent list.

------------

class Solution
{   
    void dfs1(int i,vector<bool>&visited,vector<int>adj1[],stack<int>&st){
        visited[i] = 1;
        for(int x: adj1[i]){
            if(!visited[x]) dfs1(x, visited,adj1,st);
        }
        st.push(i);
    }
    void dfs2(int i,vector<bool>&visited,vector<int>adj2[]){
        visited[i] = 1;
        for(int x: adj2[i]){
            if(!visited[x]) dfs2(x, visited,adj2);
        }
    }
	public:
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int>adj1[V],adj2[V];
        vector<bool>visited(V), visited2(V);
        for(int i=0;i<V;i++){
            for(int x: adj[i]) adj1[i].push_back(x);
        }
        //Sort all the edges according to the finishing line
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!visited[i]) dfs1(i, visited,adj1,st);
        }
        
        //Reverse the graph 
        for(int i=0;i<V;i++){
            for(int x: adj[i]) adj2[x].push_back(i);
        }

        int scc = 0;
        while(!st.empty()){
            int i = st.top();
            st.pop();
            if(!visited2[i]) dfs2(i, visited2,adj2), scc++;
        }
        return scc;
    }
};

//#######################################################################
//#######-------G-55. Bridges in Graph - Using Tarjan's Algorithm of time in and low time--------########
//Tutorial: https://takeuforward.org/graph/bridges-in-graph-using-tarjans-algorithm-of-time-in-and-low-time-g-55/
//Problem: https://leetcode.com/problems/critical-connections-in-a-network/description/

find the edges jegula remove korle component 2 ta hoe jabe

Bridge: the critical part of the graph, if we cut the edges it becomes more than 1 component
The whole graph is a 1 component, After cutting down an edge it should not disconnect

Time of insertion(When going through dfs)
Lowest time of insertion(take the lowest child, and also not the parent itself)

------------
DFS
Approach/Steps: 
1. If cannot reach then that is a bridge 

1. Maintain (Time of insertion + Lowest Time of insertion array) and run a dfs 
For knowing the algo: think(if not able to do see striver note and video)

Time Complexity: O(V+2E), where V = no. of vertices, E = no. of edges. It is because the algorithm is just a simple DFS traversal.
Space Complexity: O(V+2E) + O(3V), where V = no. of vertices, E = no. of edges. O(V+2E) to store the graph in an adjacency list and O(3V) for the three arrays i.e. tin, low, and vis, each of size V.
------------
class Solution {
    int timer = 0;
    void dfs(int node, int parent, vector<int>adj[], vector<int>&visited, vector<int>&toi,
        vector<int>&ltoi,vector<vector<int>>&bridges){
        visited[node] = 1;
        toi[node] = ltoi[node] = timer;
        timer++;
        for(auto x: adj[node]){
            if(x==parent) continue;//confused{other than parent->node if there is other paths of reaching parent}
            if(!visited[x]){
                dfs(x, node, adj, visited, toi, ltoi, bridges);
                ltoi[node] = min(ltoi[x], ltoi[node]);
                if(ltoi[x]>toi[node]){//if this is the case, then it cannot traverse back with the paths
                    bridges.push_back({x, node});
                }
            }
            else{
                ltoi[node] = min(ltoi[x], ltoi[node]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto x: connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<vector<int>>bridges;
        vector<int>visited(n,0), toi(n,0), ltoi(n,0);
        dfs(0, -1, adj, visited, toi, ltoi, bridges);
        return bridges;
    }
};

//#######################################################################
//#######-------G-56. Articulation Point in Graph--------########
//Tutorial: https://takeuforward.org/data-structure/articulation-point-in-graph-g-56/
//Problem: https://www.geeksforgeeks.org/problems/articulation-point-1/1

bridges: edges , Articulation Points = Nodes 
bridges: cut edges , Articulation Points = cut Nodes 


Articulation Points of a graph are the nodes on whose removal, the graph breaks into multiple components. 

------------
DFS
Approach/Steps: 
1. 

Time Complexity: O(V+2E), where V = no. of vertices, E = no. of edges. It is because the algorithm is just a simple DFS traversal.
Space Complexity: O(3V), where V = no. of vertices. O(3V) is for the three arrays i.e. tin, low, and vis, each of size V.
------------



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






//#######-------xxxxxxxx-------########
//#######-------xxxxxxxx-------########
//Stack and Queue

//Stack + Queue

Confusions:
1. why below next and previous greater and smaller template is same ???
2. 9. Number of NGEs to the right -  Not sure how stack works here???
3. 10. Trapping Rainwater using stack 
4. https://www.geeksforgeeks.org/problems/stack-using-two-queues/1 confused

---------------------------------------------------------------------------------------------------------
Striver Stack + Queue Playlist: https://www.youtube.com/playlist?list=PLgUwDviBIf0pOd5zvVVSzgpo6BaCpHT9c
Resource: https://takeuforward.org/blogs/stack
Resource: https://takeuforward.org/blogs/queue
---------------------------------------------------------------------------------------------------------

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//####################-------Learning--------############################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

//#######################################################################
//#######-------1. Introduction to Stack and Queue | Implementation using Data Structures--------########

------------------------Theory----------------------------------

Stack follows LIFO
Functions: push(), pop(), top(), size()

Queue follows LIFO
Functions: push(), pop(), top(), size()

Implementing stack using array is not dynamic, space complexity would be the defined array size

Implementing stack using array [variables: top, size]
Implementing queue using array [variables: start, end, current_size]
            
//#######################################################################
//#######-------1.1 Implement Stack using Arrays--------########
//Tutorial: https://takeuforward.org/data-structure/implement-stack-using-array/
//Problem: https://www.geeksforgeeks.org/problems/implement-stack-using-array/1

------------
Approach:
1. move the top++ when pushing and top-- when popping
2. printing value = arr[top];
------------
Time Complexity: O(1) for every operation
Space Complexity: O(N) - for defining a particular array size 

#include <bits/stdc++.h>

using namespace std;
class Stack
{
    int size;
    int *arr;
    int top;

public:
    Stack()
    {
        top = -1;
        size = 1000;
        arr = new int[size];
    }
    void push(int x)
    {
        top++;
        arr[top] = x;
    }
    int pop()
    {
        int x = arr[top];
        top--;
        return x;
    }
    int Top()
    {
        return arr[top];
    }
    int Size()
    {
        return top + 1;
    }
};
int main()
{

    Stack s;
    s.push(6);
    s.push(3);
    s.push(7);
    cout << "Top of stack is before deleting any element " << s.Top() << endl;
    cout << "Size of stack before deleting any element " << s.Size() << endl;
    cout << "The element deleted is " << s.pop() << endl;
    cout << "Size of stack after deleting an element " << s.Size() << endl;
    cout << "Top of stack after deleting an element " << s.Top() << endl;
    return 0;
}

//#######################################################################
//#######-------1.2 Implement Queue using Arrays--------########
//Tutorial: https://takeuforward.org/data-structure/implement-queue-using-array/

------------
Approach:
1. move the end++ when pushing and start++ when popping
------------
Time Complexity: O(1) - for every operation
Space Complexity: O(N) - for defining a particular array size 

#include <bits/stdc++.h>
using namespace std;
class Queue
{
    int *arr;
    int start, end, currSize, maxSize;

public:
    Queue()
    {
        arr = new int[16];
        start = -1;
        end = -1;
        currSize = 0;
    }

    Queue(int maxSize)
    {
        (*this).maxSize = maxSize;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }
    void push(int newElement)
    {
        if (currSize == maxSize)
        {
            cout << "Queue is full\nExiting..." << endl;
            exit(1);
        }
        if (end == -1)
        {
            start = 0;
            end = 0;
        }
        else
            end = (end + 1) % maxSize;
        arr[end] = newElement;
        cout << "The element pushed is " << newElement << endl;
        currSize++;
    }
    int pop()
    {
        if (start == -1)
        {
            cout << "Queue Empty\nExiting..." << endl;
        }
        int popped = arr[start];
        if (currSize == 1)
        {
            start = -1;
            end = -1;
        }
        else
            start = (start + 1) % maxSize;
        currSize--;
        return popped;
    }
    int top()
    {
        if (start == -1)
        {
            cout << "Queue is Empty" << endl;
            exit(1);
        }
        return arr[start];
    }
    int size()
    {
        return currSize;
    }
};

int main()
{
    Queue q(6);
    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);
    cout << "The peek of the queue before deleting any element " << q.top() << endl;
    cout << "The size of the queue before deletion " << q.size() << endl;
    cout << "The first element to be deleted " << q.pop() << endl;
    cout << "The peek of the queue after deleting an element " << q.top() << endl;
    cout << "The size of the queue after deleting an element " << q.size() << endl;

    return 0;
}

//#######################################################################
//#######-------1.3 Implement Stack using Queue--------########
//Tutorial: https://takeuforward.org/data-structure/implement-stack-using-single-queue/
//Problem:  https://leetcode.com/problems/implement-stack-using-queues/description/
//Problem2: https://www.geeksforgeeks.org/problems/stack-using-two-queues/1

------------
Approach:
1. For approach see the blog 
------------
//Single Queue

class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size()?false:true;
    }
};

//Double Queue


//#######################################################################
//#######-------1.4 Implement Queue using Stack--------########
//Tutorial: https://takeuforward.org/data-structure/implement-queue-using-stack/
//Problem:  https://leetcode.com/problems/implement-queue-using-stacks/description/
//Problem2: https://www.geeksforgeeks.org/problems/queue-using-stack/1

------------
Approach:
1. For approach see the blog 
------------
//Double stack
class Queue {
    stack<int> input, output;
public:

    void enqueue(int x) {
        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }
        output.push(x);
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
    }

    int dequeue() {
        int val = output.top();
        output.pop();
        return val;
    }
};

//#######################################################################
//#######-------1.5 Implement stack using Linkedlist--------########
//Tutorial: https://takeuforward.org/data-structure/implement-stack-using-linked-list/
//Problem: https://www.geeksforgeeks.org/problems/implement-stack-using-linked-list/1

------------
Approach:
1. For approach see the blog 
------------

Time Complexity: O(1) - for every operation
Space Complexity: O(1) - for using linked list

#include <iostream>
using namespace std;

struct stackNode
{
    int data;
    stackNode *next;
    int size;
    stackNode(int d)
    {
        data = d;
        next = NULL;
    }
};
struct stack
{
    stackNode *top;
    int size;
    stack()
    {
        top = NULL;
        size = 0;
    }
    void stackPush(int x)
    {
        stackNode *element = new stackNode(x);
        element->next = top;
        top = element;
        cout << "Element pushed" << "\n";
        size++;
    }
    int stackPop()
    {
        if (top == NULL)
        {
            return -1;
        }
        int topData = top->data;
        stackNode *temp = top;
        top = top->next;
        delete temp;
        size--;
        return topData;
    }
    int stackSize()
    {
        return size;
    }
    bool stackIsEmpty()
    {
        return top == NULL;
    }
    int stackPeek()
    {
        if (top == NULL)
            return -1;
        return top->data;
    }
    void printStack()
    {
        stackNode *current = top;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }
};
int main()
{
    stack s;
    s.stackPush(10);
    cout << "Element popped: " << s.stackPop() << "\n";
    cout << "Stack size: " << s.stackSize() << "\n";
    cout << "Stack empty or not? " << s.stackIsEmpty() << "\n";
    cout << "stack's top element: " << s.stackPeek() << "\n";
    return 0;
}

//#######################################################################
//#######-------1.6 Implement queue using Linkedlist--------########
//Tutorial: https://takeuforward.org/data-structure/implement-queue-using-linked-list/
//Problem: https://www.geeksforgeeks.org/problems/implement-queue-using-linked-list/1

------------
Approach:
1. For approach see the blog 
------------
#include <bits/stdc++.h>
using namespace std;

class QueueNode
{
public:
    int val;
    QueueNode *next;
    QueueNode(int data)
    {
        val = data;
        next = nullptr;
    }
};
QueueNode *Front = nullptr, *Rare = nullptr;

class Queue
{
public:
    int size = 0;
    bool Empty();
    void Enqueue(int value);
    void Dequeue();
    int Peek();
};
bool Queue ::Empty()
{
    return Front == nullptr;
}
int Queue ::Peek()
{
    if (Empty())
    {
        cout << "Queue is Empty" << endl;
        return -1;
    }
    else
        return Front->val;
}
void Queue ::Enqueue(int value)
{
    QueueNode *Temp;
    Temp = new QueueNode(value);
    if (Temp == nullptr) // When heap exhausted
        cout << "Queue is Full" << endl;
    else
    {
        if (Front == nullptr)
        {
            Front = Temp;
            Rare = Temp;
        }
        else
        {
            Rare->next = Temp;
            Rare = Temp;
        }
        cout << value << " Inserted into Queue " << endl;
        size++;
    }
}
void Queue ::Dequeue()
{
    if (Front == nullptr)
        cout << "Queue is Empty" << endl;
    else
    {
        cout << Front->val << " Removed From Queue" << endl;
        QueueNode *Temp = Front;
        Front = Front->next;
        delete Temp;
        size--;
    }
}
int main()

{
    Queue Q;
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);
    Q.Dequeue();
    cout << "The size of the Queue is " << Q.size << endl;
    cout << "The Peek element of the Queue is " << Q.Peek() << endl;
    return 0;
}

//#######################################################################
//#######-------2. Check for Balanced Parentheses | Stack and Queue--------########
//Tutorial: https://takeuforward.org/data-structure/check-for-balanced-parentheses/
//Problem: https://leetcode.com/problems/valid-parentheses/description/

should have same corresponding in the same order
------------
Approach:
1. Last opening bracket er opposite bracket na ashle no, else yes 
------------
Time Complexity: O(n)
Space Complexity: O(n) - when all are opening brackets

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char ch: s){
            if( ch=='(' || ch=='[' || ch=='{' ) st.push(ch);
            else {
                if(st.empty()) return false;
                if(st.top()=='(' && ch!=')' ) return false;
                if(st.top()=='[' && ch!=']' ) return false;
                if(st.top()=='{' && ch!='}' ) return false;
                st.pop();
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};

//#######################################################################
//#######-------3. Implement Min Stack--------########
//Tutorial: https://takeuforward.org/data-structure/implement-min-stack-o2n-and-on-space-complexity/
//Problem: https://leetcode.com/problems/min-stack/description/
https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1

formula: 2 x val - prev_min = new_minimum - this is modified minimum

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#####-------Prefix, Infix, PostFix Conversion Problems--------#########
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

//#######################################################################
//#######-------4. Prefix, Infix, and Postfix Conversion--------########

Infix - bracket er vitor operator gula, (+)
prefix - operators before the operand, + pq - used in lisp
prefix - operators after the operand, pq + 

//#######################################################################
//#######-------4.1 Infix to Postfix Conversion using Stack--------########
//Tutorial: https://takeuforward.org/data-structure/infix-to-postfix/
//Problem: https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1

- operand answer e add kora 
- operator stack e add kora 

Steps:
https://www.youtube.com/watch?v=92TmPsNRjwk
1. Two operators of the same priority cannot stay together
2. lowest priority ashle highest priority operator shob jabe ga, ulta hole push hobe stack e
3. parenthese close hoile all operand e add kora


//#######################################################################
//#######-------4.2 Prefix to Infix Conversion--------########
//Tutorial: https://www.geeksforgeeks.org/prefix-postfix-conversion/
//Problem: https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1

//#######################################################################
//#######-------4.3 Prefix to Postfix Conversion--------########
//Tutorial: https://www.geeksforgeeks.org/prefix-postfix-conversion/
//Problem: https://www.geeksforgeeks.org/problems/prefix-to-postfix-conversion/1

//#######################################################################
//#######-------4.4 Postfix to Prefix Conversion--------########
//Tutorial: https://www.geeksforgeeks.org/postfix-prefix-conversion/
//Problem: https://www.geeksforgeeks.org/problems/postfix-to-prefix-conversion/1

//#######################################################################
//#######-------4.5 Postfix to Infix--------########
//Tutorial: https://www.geeksforgeeks.org/postfix-to-infix/
//Problem: https://www.geeksforgeeks.org/problems/postfix-to-infix-conversion/1

//#######################################################################
//#######-------4.6 Convert Infix To Prefix Notation--------########
//Tutorial: https://takeuforward.org/data-structure/infix-to-prefix/
//Problem: https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1


//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#####-------Monotonic Stack/Queue Problems [VVV. Imp]--------##########
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

monotonic stack: Putting element in specific order
                 Boro theke choto or choto theke boro akare stack sajano according to question


//Template for next and previous greater
int n = arr.size();
stack<int>st;
//next greater
vector<int>left(n);
for(int i=n-1;i>=0;i--){
    while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
    left[i] = st.empty() ? n: st.top();
    st.push(i);
}
while(!st.empty())st.pop();

//previous greater
vector<int>right(n);
for(int i=0;i<n;i++){
    while(!st.empty() && arr[st.top()]>arr[i])st.pop();
    right[i] = st.empty() ? -1: st.top();
    st.push(i);
}


------------------------------------------------------------------------
//Template for next and previous smaller
int n = arr.size();
stack<int>st;
//next smaller
vector<int>left(n);
for(int i=n-1;i>=0;i--){
    while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
    left[i] = st.empty() ? n: st.top();
    st.push(i);
}
while(!st.empty())st.pop();

//previous smaller
vector<int>right(n);
for(int i=0;i<n;i++){
    while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
    right[i] = st.empty() ? -1: st.top();
    st.push(i);
}

//#######################################################################
//#######-------5. Next Greater Element--------########
//Tutorial: 
//Problem: https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1

- Here we are putting value in increasing order
- boro kono value ashle order distort hoe jabe, and stack empty kre dibo

------------
Approach:
1. Move from the back and keep adding values in the stack 
2. condition to add element in the stack: st.top() > arr[i], else keep popping
------------


----------------------------------------------------------------------
Time Complexity: O(2N)
Space Complexity: O(2N)
class Solution
{
    public:
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<long long>st;
        vector<long long>ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i] ) st.pop();
            ans[i] = st.empty() ? -1: st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};


----------------------------------------------------------------------
Another way 
class Solution
{
    public:
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<long long>st;
        st.push(arr[n-1]);
        vector<long long>ans(n, -1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty()){
                if( st.top() > arr[i] ){
                    ans[i] = st.top();
                    break;
                }
                st.pop();
            } 
            st.push(arr[i]);
        }
        return ans;
    }
};

----------------------------------------------------------------------
//Problem: https://leetcode.com/problems/next-greater-element-i/description/

Same concept, a little different problem
Q: next greater element subset akare thakbe

------------
Approach:
1. Same approach as Next Greater Element
2. Just maintain a hashing to keep the track of the changed element
------------

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& arr) {
        stack<int>st;
        int n = arr.size();
        st.push(arr[n-1]);
        map<int, int> mp;
        vector<int>ans(nums1.size());
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i]) st.pop();
            if(st.empty()) mp[arr[i]] = -1;
            else mp[arr[i]] = st.top();
            st.push(arr[i]);
        }

        for(int i=0;i<nums1.size();i++){
            if(mp[nums1[i]]) ans[i] = mp[nums1[i]];
        }
        return ans;
    }
};

//#######################################################################
//#######-------6. Next Greater Element - II--------########
//Tutorial: https://takeuforward.org/data-structure/next-greater-element-using-stack/
//Problem: https://leetcode.com/problems/next-greater-element-ii/description/

prerequisite: 5. Next Greater Element

------------
Approach:
- Hypothetically add another array with the existing array

1. solve 5. Next Greater Element [2 times]
------------
Time Complexity: O(4N)
Space Complexity: O(3N) [stack size = 2N, ans = N]


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        stack<int>st;
        int n = arr.size();
        st.push(arr[n-1]);
        vector<int>ans(n, -1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty()){
                if( st.top() > arr[i] ){
                    break;
                }
                st.pop();
            } 
            st.push(arr[i]);
        }

        for(int i=n-1;i>=0;i--){
            while(!st.empty()){
                if( st.top() > arr[i] ){
                    ans[i] = st.top();
                    break;
                }
                st.pop();
            } 
            st.push(arr[i]);
        }

        return ans;

    }
};

//#######################################################################
//#######-------7. Previous Smaller Element--------########
//Tutorial: 
//Problem: https://www.interviewbit.com/problems/nearest-smaller-element/

prerequisite: 5. Next Greater Element

------------
Approach:
1. Top e small rakhbo, increasing order e stack building
2. if st.top()>=arr[i] keep destroying stack until this condition holds

------------
Time Complexity: O(2N)
Space Complexity: O(2N)

vector<int> Solution::prevSmaller(vector<int> &arr) {
    int n = arr.size();
    stack<int> st;
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()>=arr[i])st.pop();
        ans[i] = st.empty() ? -1: st.top();
        st.push(arr[i]);
    }
    return ans;
}

//#######################################################################
//#######-------8. Next Smaller Element--------########
//Tutorial: 
//Problem: https://www.naukri.com/code360/problems/next-smaller-element_1112581

prerequisite: 5. Next Greater Element

------------
Approach:
1. just maintain this, st.top()>=arr[i]
------------
Time Complexity: O(2N)
Space Complexity: O(2N)

#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()>=arr[i])st.pop();
        ans[i] = st.empty() ? -1: st.top();
        st.push(arr[i]);
    }
    return ans;
}

//#######################################################################
//#######-------9. Number of NGEs to the right--------########
//Tutorial: https://www.geeksforgeeks.org/number-nges-right/
//Problem: https://www.geeksforgeeks.org/problems/number-of-nges-to-the-right/1

------------
Approach:
1. Brute force totally
------------
class Solution{
public:
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        vector<int>ans;
        for(int ind: indices){
            int ct = 0;
            for(int i=ind+1;i<n;i++){
                if(arr[i] > arr[ind] ) ct++;
            }
            ans.push_back(ct);
        }
        return ans;
    }
};

//#######################################################################
//#######-------10. Trapping Rainwater | 2 Approaches--------########
//Tutorial: https://takeuforward.org/data-structure/trapping-rainwater/
//Problem: https://leetcode.com/problems/trapping-rain-water/description/

Formula: min(prefix_leftmax, suffix_rightmax) - arr[i]
------------
Approach:
1. Get suffix max and prefix max 
2. Use the formula 
------------
Time Complexity: O(3N)
Space Complexity: O(2N)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>pre(n), suf(n);
        pre[0] = height[0];
        suf[n-1] = height[n-1];
        for(int i=1;i<n;i++){
            pre[i] = max(height[i], pre[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            suf[i] = max(height[i], suf[i+1]);
        }

        int total = 0;
        for(int i=0;i<n;i++){
            total+= min(pre[i], suf[i]) - height[i];
        }
        return total;
    }
};

//Approach 2 - Using Stack
https://www.geeksforgeeks.org/trapping-rain-water/


//#######################################################################
//#######-------11. Sum of Subarray Minimum--------########
//Tutorial: https://www.geeksforgeeks.org/sum-of-minimum-elements-of-all-subarrays/
//Problem: https://leetcode.com/problems/sum-of-subarray-minimums/description/

GFG approach is simpler than striver
------------
Formula: (number of previous greater element * number of next greater element) * that number
Approach:
1. get previous greater element
2. get next greater element
3. Apply the formula and solve
------------
Time Complexity: O(2N) + O(2N) + O(N)
Space Complexity: O(2N) + O(2N)

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        int mod = 1e9 + 7;

        //next greater
        vector<int>left(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            left[i] = st.empty() ? n: st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();

        //previous greater
        vector<int>right(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i])st.pop();
            right[i] = st.empty() ? -1: st.top();
            st.push(i);
        }

        int sum = 0;
        for(int i=0;i<n;i++){
            int lft = left[i] - i;
            int rght = i - right[i];
            sum= (sum + (lft * rght * 1LL * arr[i])%mod)%mod ;
        }
        return sum;
    }
};

//#######################################################################
//#######-------12. Sum of subarray ranges--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/sum-of-subarray-ranges/description/

Prerequisite: 11. Sum of Subarray Minimum

------------
Approach:
Formula: Sum of subarray maximum - Sum of subarray minimum
1. Just apply the formula
------------
Time Complexity: O(5N) + O(5N) = O(10N) [better than N*N]
Space Complexity: O(4N) + O(4N) = O(8N)

class Solution {
public:
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        int mod = 1e9 + 7;

        //next greater
        vector<int>left(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            left[i] = st.empty() ? n: st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();

        //previous greater
        vector<int>right(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i])st.pop();
            right[i] = st.empty() ? -1: st.top();
            st.push(i);
        }

        long long sum = 0;
        for(int i=0;i<n;i++){
            int lft = left[i] - i;
            int rght = i - right[i];
            sum= sum + (lft * rght * 1LL * arr[i]) ;
        }
        return sum;
    }

    long long sumSubarrayMax(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        int mod = 1e9 + 7;

        //next greater
        vector<int>left(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i])st.pop();
            left[i] = st.empty() ? n: st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();

        //previous greater
        vector<int>right(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<arr[i])st.pop();
            right[i] = st.empty() ? -1: st.top();
            st.push(i);
        }

        long long sum = 0;
        for(int i=0;i<n;i++){
            int lft = left[i] - i;
            int rght = i - right[i];
            sum= sum + (lft * rght * 1LL * arr[i]) ;
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMax(nums) - sumSubarrayMins(nums);
    }
};

//#######################################################################
//#######-------13. Aestroid Collisions--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/asteroid-collision/description/

------------
Approach:
positive er jnno jhamela nai, negative er jnno jhamela 

1. if positive put in stack 
2. if negative maintain the colliding condition 
       2.1 st.top()>0 to popping up elements 
       2.2 if stack is not empty and st.top == last element st.pop 
       2.3 else if stack is empty and st.top()<0 put in stack
------------
Time Complexity: O(2N) + O(N) + O(N) [for reverse]
Space Complexity: O(N) + O(N) [stack and ans array]

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            // all negatives
            if(asteroids[i]<0){
                while(!st.empty() && st.top()>0 && st.top()< abs(asteroids[i]) ){
                    st.pop();
                }
                if(!st.empty() && st.top() == abs(asteroids[i]))st.pop();
                else if ( st.empty() || st.top()<0 ) st.push(asteroids[i]);
            }
            else {
                //all positives
                st.push(asteroids[i]);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//#######################################################################
//#######-------14. Remove K Digits--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/remove-k-digits/description/

------------
Approach:
1. Maintain increasing order in stack

3 edge cases 
1. k>=N, return "0"
2. number becomes 00001000, return "1000"
3. after performing stack - k remains, so remove the top elements , n = 123456, k = 3 return "123"
------------
Time Complexity: O(4N) + O(K)
Space Complexity: O(N) + O(N) [stack and ans array]

class Solution {
public:
    string removeKdigits(string s, int k) {
        int n = s.size(), ind = n;
        string ans = "";
        stack<char>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()>s[i] && k>0){
                k--;
                st.pop();
            }
            st.push(s[i]);
        }
        
        //edge case 3
        while(!st.empty() && k-->0){
            st.pop();
        }
        
        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }
        
        //edge case 2
        while(ans.size()>0 && ans[ans.size()-1]=='0') ans.pop_back();
        
        reverse(ans.begin(), ans.end());
        
        if(ans.empty()) return "0";
        return ans;
    }
};

//#######################################################################
//#######-------15. Largest Rectangle in Histogram--------########
//Tutorial: https://takeuforward.org/data-structure/area-of-largest-rectangle-in-histogram/
//Problem: https://leetcode.com/problems/largest-rectangle-in-histogram/description/

get the 'index' of both pse and nse
------------
Formula: area = arr[i] * (nse - pse - 1)

Approach:
1. Get the nse and pse
2. apply the formula and solve it 

note:
previous smaller index na thakle set -1
next smaller na thakle set n
------------
Time Complexity: O(5N) 
Space Complexity: O(4N)

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        //next smaller
        vector<int>left(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            left[i] = st.empty() ? n: st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();

        //previous smaller
        vector<int>right(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            right[i] = st.empty() ? -1: st.top();
            st.push(i);
        }
        
        int mx = 0;
        for(int i=0;i<n;i++){
            mx = max(mx, (left[i]-right[i]-1) * arr[i] );
        }
        return mx;
    }
};

//Another Approach
Time Complexity: O(2N) 
Space Complexity: O(4N)

------------
Formula: area = arr[i] * (nse - pse - 1)

Approach:
1. Keep maintain increasing 'index' order in stack 
2. if arr[st.top()]>arr[i], then nse = i, pse = st.top()

3. Get the nse and pse
4. apply the formula and solve it 

note:
previous smaller index na thakle set -1
next smaller na thakle set n
------------
class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        int mx = 0, pse, nse;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                int ind = st.top();
                st.pop();
                pse = (st.empty()?-1:st.top());
                nse = i;
                mx = max(mx, (nse - pse - 1) * arr[ind]);
            }
            st.push(i);
        }
        //if still elements left, for increasing order array te erokom hobe -> 2 4 6 
        while(!st.empty()){
            int ind = st.top();
            st.pop();
            nse = n;
            pse = (st.empty()?-1:st.top());
            mx = max(mx, (nse - pse - 1) * arr[ind]);
        }
        return mx;
    }
};

//#######################################################################
//#######-------16. Maximal Rectangle--------########
//Tutorial: https://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/
//Problem:https://leetcode.com/problems/maximal-rectangle/description/

Prerequisite: 15. Largest Rectangle in Histogram

------------
Approach:
1. apply prefix sum in the matrix 
2. Use 15. Largest Rectangle in Histogram concept to solve every prefix[row] 
------------
Time Complexity: O(MxN) + O(Nx2M) 
Space Complexity: O(MxN) + O(M)

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        int mx = 0, pse, nse;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                int ind = st.top();
                st.pop();
                pse = (st.empty()?-1:st.top());
                nse = i;
                mx = max(mx, (nse - pse - 1) * arr[ind]);
            }
            st.push(i);
        }
        while(!st.empty()){
            int ind = st.top();
            st.pop();
            nse = n;
            pse = (st.empty()?-1:st.top());
            mx = max(mx, (nse - pse - 1) * arr[ind]);
        }
        return mx;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> prefix(n+1, vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0') prefix[i+1][j] = 0;
                else prefix[i+1][j] = prefix[i][j] + 1;

            }
        }

        int mx = 0;
        for(int i=0;i<n;i++){
            mx = max(mx, largestRectangleArea(prefix[i+1]));
        }
        return mx;
    }
};

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#############-------Implementation Problems--------####################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

//#######################################################################
//#######-------17. Sliding Window Maximum--------########
//Tutorial: https://takeuforward.org/data-structure/sliding-window-maximum/
//Problem: https://leetcode.com/problems/sliding-window-maximum/description/

------------
Approach:
1. Create a deque to store first K elements. Add the greatest element index in deque(add in decreasing order)
2. Run loop for rest of the window
   a. Remove out of all window indices from deque
   b. pop_back the dq elements that is not maintaining increasing order with the current value nums[i]
   c. Add the current val indices in the dequeue(add in decreasing order)
   d. nums[dq.front()] will be maximum element
------------
Time Complexity: O(2N) 
Space Complexity: O(K) + O(N-K)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size()<k)return {0};
        vector<int> ans;
        deque<int> dq;

        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        //max will always be in front
        ans.push_back(nums[dq.front()]);
        for(int i=k;i<nums.size();i++){
            if(!dq.empty() && dq.front()==i-k)dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }

        return ans;

    }
};

//#######################################################################
//#######-------18. Stock Span Problem--------########
//Tutorial: https://www.geeksforgeeks.org/the-stock-span-problem/
//Problem: https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

------------
Approach:
1. maintain the stack < value, index > st;
2. and just apply the formula: ans[i] = that index - last greater element index 

note: 
last greater element index na thakle -1 diye subtraction
------------
Time Complexity: O(2N) 
Space Complexity: O(2N) 

class Solution
{
    public:
    vector <int> calculateSpan(int price[], int n)
    {
        vector<int>ans(n);
        
        //{val, index}
        stack< pair<int, int> > st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first<=price[i]){
                st.pop();
            }
            int span = i;
            if(st.empty()) span -= -1;
            else span-= st.top().second;
            
            st.push({price[i], i});
            
            ans[i] = span;
        }
        return ans;
    }
};

//#######################################################################
//#######-------19. The Celebrity Problem--------########
//Tutorial: https://www.geeksforgeeks.org/the-celebrity-problem/
//Problem: https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

------------
Approach:
1. 
------------

//#######################################################################
//#######-------20. Implement LRU Cache--------########
//Tutorial: https://takeuforward.org/data-structure/implement-lru-cache/
//Problem: https://leetcode.com/problems/lru-cache/description/
https://www.geeksforgeeks.org/problems/lru-cache/1

------------
Approach:
1. 
------------

//#######################################################################
//#######-------21. Implement LFU cache | Leetcode(Hard)--------########
//Tutorial: https://www.geeksforgeeks.org/least-frequently-used-lfu-cache-implementation/
//Problem: https://leetcode.com/problems/lfu-cache/description/
https://www.geeksforgeeks.org/problems/lfu-cache-1665050355/0

------------
Approach:
1. 
------------

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




//#######-------xxxxxxxx-------########
//#######-------xxxxxxxx-------########

//Interactive Problem
//binary search or constructive algorithms are mostly found in interactive problems
//https://codeforces.com/gym/101021/problem/1
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve(){
    int l = 1, r = 1000001, m;
    while(l+1<r){
        m = (l+r)>>1;
        printf("%lld\n",m);
        string s;cin>>s;
        if(s=="<")r = m;
        else l = m;
    }
    cout<< "! " << l <<endl;
    cout<<flush;
}

int32_t main(){
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}


------------------------------------------------------------
// Template

#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    
}

int32_t main(){
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}


//#######-------xxxxxxxx-------########
//#######-------xxxxxxxx-------########
//Ternary Search
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve(){
    int l = 1, r = 1001, m;
    for(int i=0;i<100;i++){
        int m1 = l + (r - l) / 3;
        int m2 = l + (r - l) * 2 / 3;
        
    }
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    cin >> t;
    while(t--)solve(); 
    return 0;
}


//#######-------xxxxxxxx-------########
//#######-------xxxxxxxx-------########

//Recursion + Backtracking

//Recursion + Backtracking

*** Draw the recursive tree to understand in depth Everything ***

- Recursion: Try every possible combination
- If constraints are very low think in recursion, backtracking
- Thinking depth wise a little bit tougher than breadth wise 

---------------------------------------------------------------------------------------------------------
Striver Recursion + Backtracking Playlist: https://www.youtube.com/playlist?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9
Resource: https://takeuforward.org/blogs/recursion
---------------------------------------------------------------------------------------------------------


Template - Take not take approach for all subsequence 

void f(vector<int>arr, int index,int n,vector<int> &subarr, vector<vector<int>>&ans){
    if (index == n){
        ans.insert(subarr);
        return;
    }
    //pick
    subarr.push_back(arr[index]);
    f(arr, index+1,n,subarr, ans);
    subarr.pop_back();
    //not_pick
    f(arr, index + 1,n,subarr, ans);
}


void f(vector<int>arr, int index,int n, int s, vector<int>&ans){
    if (index == n){
        ans.push_back(s);
        return;
    }
    //take
    f(arr, index+1,n,s + arr[index],ans);
    //not take
    f(arr, index+1,n,s,ans);
}

//backtracking template

bool possible(){

}
bool f(){
    //traverse and check if possible
    //do backtrack here
}

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#####################-------Recursion--------##########################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------1. Introduction to Recursion | Recursion Tree | Stack Space--------########
//Tutorial: https://takeuforward.org/recursion/what-is-recursion/

------------------------Theory----------------------------------

Recursion: When a function calls itself until a specified condition is met
Stack overflow: if no condition met than it is an infinite recursion. It is called stack overflow
Segmentation fault:stackoverflow hoile hoy
base condition: condition to stop
backtracking: call call call, went back went back, went back

Learn to draw recursive tree effectively


//#######################################################################
//#######-------2. Problems on Recursion--------########

In recursion while going, things happen 
while in backtracking, in coming back things happen, thats why the term backtracking.

//#######-------2.1 Print names N time using recursion--------########
//Tutorial: https://takeuforward.org/recursion/print-name-n-times-using-recursion/
//Problem: https://www.geeksforgeeks.org/problems/print-gfg-n-times/0

void f(int i, int n){
   if(i>n) return;
   cout<<"Raj"<<endl;
   f(i+1,n);
}

//#######-------2.2 Printing 1 to N--------########
//Tutorial: https://takeuforward.org/recursion/print-1-to-n-using-recursion/
//Problem: https://www.geeksforgeeks.org/problems/print-1-to-n-without-using-loops3621/1

void f(int i, int n){
   if(i>n) return;
   cout<<i<<endl;
   f(i+1,n);
}

//#######-------2.3 Printing N to 1--------########
//Tutorial: https://takeuforward.org/data-structure/print-n-to-1-and-1-to-n-using-recursion/
//Problem: https://www.geeksforgeeks.org/problems/print-n-to-1-without-loop/1

void f(int i, int n){
   if(i>n) return;
   f(i+1,n);
   cout<<i<<endl;
}
//#######-------2.4 Printing 1 to N using backtracking--------########
//Tutorial: https://takeuforward.org/data-structure/print-n-to-1-and-1-to-n-using-recursion/
//Problem: https://www.geeksforgeeks.org/problems/print-1-to-n-without-using-loops3621/1

f(1,n)
void f(int i, int n){
    if(i>n) return;
    cout<<i<< endl;
    f(i+1,n);
}

//#######-------2.5 Printing N to 1 using backtracking--------########
//Tutorial: https://takeuforward.org/recursion/print-n-to-1-using-recursion/
//Problem: https://www.geeksforgeeks.org/problems/print-n-to-1-without-loop/1

f(n,n);
void f(int i, int n){
   if(i<1) return;
   cout<<i<<endl;
   f(i-1,n);
}

//#######################################################################
//#######-------3. Parameterised and Functional Recursion--------########

Parameterised and Functional Recursion: Doing everything in the parameter
Function recursion: returing something recursion

//#######-------3.1 Factorial--------########
//Tutorial: https://takeuforward.org/data-structure/factorial-of-a-number-iterative-and-recursive/
//Problem: https://www.geeksforgeeks.org/problems/factorial5739/1

f(n);
int f(int s){
    if(s<=1) return 1;
    return s * f(s-1);
}

//#######-------3.2 Sum of first N--------########
//Tutorial: https://takeuforward.org/data-structure/sum-of-first-n-natural-numbers/
//Problem:  https://www.geeksforgeeks.org/problems/sum-of-first-n-terms5843/1

Time Complexity: O(N)
Space Complexity: O(N) - for auxilary space 

f(n,0);
void f(int i, int sum){
   if(i<1)
   {
       cout<<sum<<endl;
       return;
   }
   f(i-1,sum+i);
}

//Another One - Sum of first N
f(n);
void f(int i){
   if(i==0) return 0;
   return i + f(i-1);
}

//#######################################################################
//#######-------4. Problems on Functional Recursion--------########


//#######-------4.1 Reverse an Array--------########
//Tutorial: https://takeuforward.org/data-structure/reverse-a-given-array/
//Problem: 
------------
Approach:
1. swap and move l and r
------------
Time Complexity: O(N/2)
Space Complexity: O(N/2) - for auxilary space 

void f(int arr[], int start, int end) {
    if(start>=end) return;
    swap(arr[start], arr[end]);
    f(arr, start + 1, end - 1);   
}

//#######-------4.2 Checking if a string is Palindrome--------########
//Tutorial: 
//Problem: https://www.geeksforgeeks.org/problems/palindrome-string0817/1

Note: If after reversing they are same, then it is a palindrome
------------
Approach:
1. same as reversing array
2. Just check if s[l] == s[r], if not return false
------------
Time Complexity: O(N/2)
Space Complexity: O(N/2) - for auxilary space 


palindrome(0,s);
bool palindrome(int i, string& s){
    if(i>=s.length()/2) return true;
    if(s[i]!=s[s.length()-i-1]) return false;//will not move ahead if this ever executes
    return palindrome(i+1,s);
}

//#######################################################################
//#######-------5. Multiple Recursion Calls--------########
//Tutorial: https://takeuforward.org/arrays/print-fibonacci-series-up-to-nth-term/
//Problem: https://www.naukri.com/code360/problems/print-fibonacci-series_7421617

Note: Fibonacci is the best example to learn multiple recursion calls

1 will happen, come back
2 will happen, come back
3 will happen, come back

int f(int n){
    if(n<=1) return n;
    return f(n-1) + f(n-2);
}

//#######################################################################
//#######-------6. Recursion on Subsequences--------########
//Tutorial: https://takeuforward.org/data-structure/power-set-print-all-the-possible-subsequences-of-the-string/
//Problem: https://leetcode.com/problems/subsets/

------------
Approach:
1. use take, not take method
------------
Time Complexity: O(2^N x N)
Space Complexity: O(N) [for auxilary space, maximum the depth can go upto N, then it will release]

class Solution {
public:
    void printSubsequences(vector<int>arr, int index, vector<int> &subarr,int n, vector<vector<int>>&ans){
        if (index == n){
            ans.push_back(subarr);
            return;
        }
        //take
        subarr.push_back(arr[index]);
        printSubsequences(arr, index + 1, subarr,n, ans);
        //not take
        subarr.pop_back();
        printSubsequences(arr, index + 1, subarr,n, ans);
    }
    vector<vector<int>> subsets(vector<int>& a) {
        vector<vector<int>> ans;
        vector<int>sub;
        printSubsequences(a, 0, sub, a.size() , ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//#######################################################################
//#######-------7. All Kind of Patterns in Recursion | Print All | Print one | Count--------########

------------
Approach:
1. Just use take, not take approach for the below 3 problems
------------
Time Complexity: O(2^N)
Space Complexity: O(N)

//#######-------7.1 Print All the Subsequence where sum is K--------########

#include <bits/stdc++.h>
using namespace std;
void f(vector<int>arr, int index, int n, vector<int> &subarr,int s, int sum){
    if (index == n){
        if(s == sum){
            for(auto x: subarr) cout<< x << ' ';
            cout<<endl;
        }
        return;
    }
    //take
    subarr.push_back(arr[index]);
    s+=arr[index];
    f(arr, index + 1, n, subarr, s, sum);
    //not take
    subarr.pop_back();
    s-=arr[index];
    f(arr, index + 1, n, subarr,s, sum);
}

int main(){
    int n = 4;
    vector<int> ar{1,2,4,6};
    vector<int> sub;
    f(ar,0,n, sub, 0, 6);

    return 0;
}

//#######-------7.2 Print one Subsequence where sum is K--------########

Note: bool function if one time true then it is always true
    - Ekbar true hoilei hbe, ar kichu return hobe na 

#include <bits/stdc++.h>
using namespace std;
bool f(vector<int>arr, int index, int n, vector<int> &subarr,int s, int sum){
    if (index == n){
        if(s == sum){
            for(auto x: subarr) cout<< x << ' ';
            cout<<endl;
            return true;
        }
        else return false;
    }
    //take
    subarr.push_back(arr[index]);
    s+=arr[index];
    if( f(arr, index + 1, n, subarr, s, sum) ) return true;
    //not take
    subarr.pop_back();
    s-=arr[index];
    if( f(arr, index + 1, n, subarr, s, sum) ) return true;
    return false;
}

int main() {
    int n = 4;
    vector<int> ar{1,2,4,6};
    vector<int> sub;
    f(ar,0,n, sub, 0, 6);
    return 0;
}

//#######-------7.3 Print count of all Subsequence where sum is K(retun 0 or 1 in count problem)--------########

******** This problem is V.V.Imp. ********

#include <bits/stdc++.h>
using namespace std;
int f(vector<int>arr, int index,int n, vector<int> &subarr,int s, int sum){
    if (index == n){
        if(s == sum){
            return 1;
        }
        else return 0;
    }
    //take
    subarr.push_back(arr[index]);
    s+=arr[index];
    int take = f(arr, index + 1,n, subarr, s, sum);
    //not take
    subarr.pop_back();
    s-=arr[index];
    int not_take = f(arr, index + 1, n, subarr,s, sum);

    return take + not_take;
}

int main() {
    int n = 4;
    vector<int> ar{1,2,4,6};
    vector<int> sub;
    cout<< f(ar,0,n, sub, 0, 6) << endl;
    return 0;
}

//#######-------7.4 Count all subsequences with sum K--------########
//Problem: https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

------------
Approach:
1. s > sum hole, out of bounds hobe, So return 0
2. For rest use take and not take approach and use a dp array
------------
class Solution{
	public:
	int md = 1e9+7;
	int f(int arr[], int index,int n,int s, int sum,
	 vector<vector<int>>&dp){
        if (index == n){
            if(s == sum) return 1;
            return 0;
        }
        if(s>sum) return 0;
        if(dp[index][s] != -1) return dp[index][s];
        int take = f(arr, index + 1,n, s + arr[index], sum, dp);
        int not_take = f(arr, index + 1, n,s, sum, dp);
        return dp[index][s] = (take + not_take)%md;
    }
    
	int perfectSum(int arr[], int n, int sum)
	{   
	    vector<vector<int>>dp(n+1, vector<int>(sum+1, -1));
        return f(arr,0,n, 0LL, sum, dp)%md;
	}
};

//#######-------7.5 Check if there exists a subsequence with sum K--------########
//Problem: https://www.naukri.com/code360/problems/subset-sum_630213

------------
Approach:
If one time true always true 
1. Use the take and not_take approach
------------
bool f(vector<int>arr, int index, int n,int s, int sum){
    if (index == n){
        if(s == sum) return true;
        else return false;
    }
    if(s>sum) return false;
    if( f(arr, index + 1, n, s + arr[index], sum) ) return true;
    if( f(arr, index + 1, n, s, sum) ) return true;
    return false;
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    return f(a, 0, n, 0, k);
}

//#######################################################################
//#######-------8. Merge Sort--------########
//Tutorial: https://takeuforward.org/data-structure/merge-sort-algorithm/
//Tutorial2: https://www.geeksforgeeks.org/merge-sort/
//Problem: https://www.geeksforgeeks.org/problems/merge-sort/1

------------
Approach:
1. Divide and merge
2. Instead of dividing the arrays, divide the indexes
3. After dividing, merge the array by using a temp variable
------------
Time Complexity: O(N * log2N)
Space Complexity: O(N)

#include <bits/stdc++.h>
using namespace std;

//merge function takes O(N) time
void merge(int ar[],int l,int m, int h){
    vector<int> temp;

    //low...mid
    //mid+1...high
    int i = l;      // Initial index of left subarray
    int j = m + 1;  // Initial index of right subarray

    // Merging the two arrays
    while (i <= m && j <= h) {
        if (ar[i] <= ar[j]) {
            temp.push_back(ar[i]);
            i++;//oi position er kaj shesh, tai ++
        } else {
            temp.push_back(ar[j]);
            j++;
        }
    }

    //if there are elements on the left still remains
    while (i <= m) {
        temp.push_back(ar[i]);
        i++;
    }

    //if there are elements on the right still remains
    while (j <= h) {
        temp.push_back(ar[j]);
        j++;
    }

    // moving all elements to an array / Copy elements from temp back to ar[]
    for (int k = l; k <= h; k++) {
        ar[k] = temp[k-l];//
    }

}

void merge_sort(int ar[], int l,int h){
    if(l>=h){
        return;
    }
    int m = (l+h)/2;
    merge_sort(ar,l,m);//left half
    merge_sort(ar,m+1,h);//right half

    //function to merge and sort the array
    merge(ar,l,m,h);
}


int main(){

    int t=1;
    //cin >> t;
    while(t--){
        int ar[100]={2,1,23,45,22,3,6};
        int n = 7;
        int l = 0;
        int h = 6;

        merge_sort(ar,0,n-1); //high and low
        for(int i=0;i<n;i++){
            cout<<ar[i]<<endl;
        }
        cout<<endl;
    }
    return 0;
}

//#######################################################################
//#######-------9. Quick Sort--------########
//Tutorial: https://takeuforward.org/data-structure/quick-sort-algorithm/
//Tutorial2: https://www.geeksforgeeks.org/quick-sort-algorithm/
//Problem: https://www.geeksforgeeks.org/problems/quick-sort/1

------------
Approach:
Way to do quick sort: select pivot, place element in its correct position

1. selects pivot, smaller than it goes left, larger than it goes right
------------

Time Complexity: O(N * log2N)
Space Complexity: O(1) [except the recursion stack, it does not use any temporary array]

#include <bits/stdc++.h>
using namespace std;
int partition(int arr[],int low,int high){
    int pivot=arr[high];//pivot is the last element
    int i=(low-1);//start the loop from the low
    
    for(int j=low;j<=high-1;j++){
        //If current element is smaller than the pivot
        if(arr[j]<pivot){
        //Increment index of smaller element
        i++;
        swap(arr[i],arr[j]);}
    }
    swap(arr[i+1],arr[high]);//swap pivot with the lowest+1 index
    return (i+1);
}
           
void quickSort(int arr[],int low,int high){
    // when low is less than high
    if(low>=high) return;
        
    int pi=partition(arr,low,high);
    //Recursion Call
    //smaller element than pivot goes left and
    //higher element goes right
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
}
             
int main() {
    int arr[]={10,7,8,9,1,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);
    cout<<"Sorted Array\n";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}

//Another one - Clean Code
class Solution {
public:
    int partition(vector<int>&arr,int low,int high){
        int pivot=arr[high];
        int i=(low-1);
        
        for(int j=low;j<=high-1;j++){
            if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);}
        }
        swap(arr[i+1],arr[high]);
        return (i+1);
    }
    void quickSort(vector<int>&arr,int low,int high){
        if(low>=high) return;
            
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
    vector<int> sortArray(vector<int>& nums) {

        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

//#######################################################################
//#######-------10. Combination Sum--------########
//Tutorial: https://takeuforward.org/data-structure/combination-sum-1/
//Problem: https://leetcode.com/problems/combination-sum/description/

------------
Approach:
1. Use take, not take approach
Draw the recursive tree to understand in depth
------------
Time Complexity: O(2^t * K)
Space Complexity: O(k*x) [hypothetical]

class Solution {
public:
    void f(vector<int>arr, int index,int n,vector<int> &subarr, int s, int sum, vector<vector<int>>&ans){
        if(s == sum){
            ans.push_back(subarr);
            return;
        }
        if (index == n || s>sum){
            return;
        }
        //pick
        subarr.push_back(arr[index]);
        s+=arr[index];
        f(arr, index ,n,subarr, s, sum, ans);
        //not_pick
        subarr.pop_back();
        s-=arr[index];
        f(arr, index + 1,n,subarr,s, sum, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int>sub;
        f(arr, 0, arr.size(), sub, 0, target, ans);
        return ans;
    }
};

//#######################################################################
//#######-------11. Combination Sum II--------########
//Tutorial: https://takeuforward.org/data-structure/combination-sum-ii-find-all-unique-combinations/
//Problem: https://leetcode.com/problems/combination-sum-ii/description/

*** V V important technique ***
------------
Approach:
1. Donot Use take, not take approach, always take in this problem 
Draw the recursive tree to understand in depth
------------
class Solution {
public:
    void f(vector<int>arr, int index,int n,vector<int> &subarr, int s, int sum, vector<vector<int>>&ans){
        if(s == sum){
            ans.push_back(subarr);
            return;
        }
        if (s>sum){
            return;
        }
        for(int i=index;i<n;i++){
            if(i > index && arr[i] == arr[i-1]) continue;
            subarr.push_back(arr[i]);
            f(arr, i+1,n,subarr, s + arr[i], sum, ans);
            subarr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int>sub;
        sort(arr.begin(),arr.end());
        f(arr, 0, arr.size(), sub, 0, target, ans);
        return ans;
    }
};

//#######################################################################
//#######-------12. Combination Sum - III--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/combination-sum-iii/description/

Prerequisite: 11. Combination Sum II
------------
Approach:
1. Use the same approach for  Combination Sum - II
------------
class Solution {
public:
    void f(int index, int sz,vector<int>&arr, vector<int>&subarr, int s, 
        int target, vector<vector<int>>&ans){
        if(subarr.size() == sz && s == target){
            ans.push_back(subarr);
            return;
        }
        if(s>target) return;
        for(int i=index;i<9;i++){
            subarr.push_back( arr[i] );
            f(i+1, sz, arr, subarr, s+arr[i], target, ans);
            subarr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int sz, int target) {
        vector<vector<int>> ans;
        vector<int>sub, arr{1,2,3,4,5,6,7,8,9};
        f(0, sz, arr, sub, 0, target, ans);
        return ans;
    }
};

//#######################################################################
//#######-------13. Subset Sum I--------########
//Tutorial: https://takeuforward.org/data-structure/subset-sum-sum-of-all-subsets/
//Problem: https://www.geeksforgeeks.org/problems/subset-sums2234/1

------------
Approach:
1. Use take, not take approach
*** Draw the recursive tree to understand in depth ***
------------
Time Complexity: O(2^N)
Space Complexity: O(2^N) [ 2^N subset ase bole ]

class Solution {
  public:
    void f(vector<int>arr, int index,int n, int s, vector<int>&ans){
        if (index == n){
            ans.push_back(s);
            return;
        }
        s+=arr[index];
        f(arr, index+1,n,s,ans);
        s-=arr[index];
        f(arr, index+1,n,s,ans);
    }
    vector<int> subsetSums(vector<int> arr, int n){
        vector<int> ans;
        f(arr, 0, n, 0, ans);
        return ans;
    }
};

//Another
class Solution {
  public:
    void f(vector<int>arr, int index,int n, int s, vector<int>&ans){
        if (index == n){
            ans.push_back(s);
            return;
        }
        //take
        f(arr, index+1,n,s + arr[index],ans);
        //not take
        f(arr, index+1,n,s,ans);
    }
    vector<int> subsetSums(vector<int> arr, int n){
        vector<int> ans;
        f(arr, 0, n, 0, ans);
        return ans;
    }
};

//#######################################################################
//#######-------14. Subset Sum II--------########
//Tutorial: https://takeuforward.org/data-structure/subset-ii-print-all-the-unique-subsets/
//Problem: https://leetcode.com/problems/subsets-ii/description/

------------
Approach:
1. Use take, not take approach
*** Draw the recursive tree to understand in depth ***
------------
Time Complexity: O(2^N x N) [N for copying in the answer list]
Space Complexity: O(2^N) x O(K)

//Approach
class Solution {
public:
    void f(vector<int>arr, int index,int n,vector<int> &subarr, set<vector<int>>&ans){
        if (index == n){
            ans.insert(subarr);
            return;
        }
        //pick
        subarr.push_back(arr[index]);
        f(arr, index+1,n,subarr, ans);
        //not_pick
        subarr.pop_back();
        f(arr, index + 1,n,subarr, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        set<vector<int>> ans;
        vector<vector<int>> ans2;
        vector<int>sub;
        sort(arr.begin(),arr.end());
        f(arr, 0, arr.size(), sub, ans);
        
        for(auto x: ans)ans2.push_back(x);
        return ans2;
    }
};

//Approach 2 - Optimized Version
class Solution {
public:
    void f(vector<int>arr, int index,int n,vector<int> &subarr, vector<vector<int>>&ans){
        ans.push_back(subarr);
        for(int i=index;i<n;i++){
            if(i > index && arr[i] == arr[i-1]) continue;
            subarr.push_back(arr[i]);
            f(arr, i+1,n,subarr, ans);
            subarr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int>sub;
        sort(arr.begin(),arr.end());
        f(arr, 0, arr.size(), sub, ans);
        return ans;
    }
};

//#######################################################################
//#######-------15. Print all Permutations of a String/Array | Recursion | Approach - 1--------########
//Tutorial: https://takeuforward.org/data-structure/print-all-permutations-of-a-string-array/
//Problem: https://leetcode.com/problems/permutations/description/

*** Draw the recursive tree to understand in depth ***

------------
Approach:
1. Take a map and Use take, not take approach
------------
Time Complexity: O(N! x N)
Space Complexity: O(N) + O(N)

class Solution {
public:
    void f(vector<int>&arr, int index, int n, vector<int>&subarr, 
    map<int, int>&mp, vector<vector<int>>&ans){
        if(subarr.size() == n){
            ans.push_back( subarr );
            return;
        }        
        for(int i=0;i<n;i++){
            if(mp[i]==0){
                mp[i] = 1;
                subarr.push_back(arr[i]);

                f(arr, i, n, subarr, mp, ans);

                //backtrack
                mp[i] = 0;
                subarr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>sub;
        map<int, int>mp;
        f(nums, 0, nums.size(), sub, mp, ans);
        return ans;
    }
};

//#######################################################################
//#######-------16. Print all Permutations of a String/Array | Recursion | Approach - 2--------########
//Tutorial: https://takeuforward.org/data-structure/print-all-permutations-of-a-string-array/
//Problem: https://leetcode.com/problems/permutations/description/

Donot need extra map for this approach

------------
Approach:
1. Use the swapping approach(see striver notes for details)
------------
Time Complexity: O(N! x N)
Space Complexity: O(1) [except the recursion stack space this is the space complexity]

class Solution {
public:
    void f(vector<int>&arr, int index, int n, vector<vector<int>>&ans){
        if(index == n){
            ans.push_back( arr );
            return;
        }        
        for(int i=index;i<n;i++){
            swap(arr[index], arr[i]);
            f(arr, index+1, n, ans);
            swap(arr[index], arr[i]);//backtrack
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        f(nums, 0, nums.size(), ans);
        return ans;
    }
};

//#######################################################################
//#######-------17. N-Queens | Backtracking--------########
//Tutorial: https://takeuforward.org/data-structure/n-queen-problem-return-all-distinct-solutions-to-the-n-queens-puzzle/
//Problem: https://leetcode.com/problems/n-queens/description/

------------
Approach:
1. Place queen in each grid 
2. After that check the next valid ghor by going rowwise, columnnwise, diagonalwise
3. if total i == board row size , then answer is found, add answer and return 
------------
Time Complexity: O(N! * N) nearly.
Space Complexity: O(N^2)

//Approach
class Solution {
public:
    bool ok(int r, int c, int n, vector<string>&board ){
        int tmpr = r;
        int tmpc = c;
        //rowwise
        while(tmpr>=0){
            if(board[tmpr][tmpc]=='Q') return false;
            tmpr--;
        }
        tmpr = r;
        tmpc = c;
        //diagonalwise upore
        while(tmpr>=0 && tmpc>=0){
            if(board[tmpr][tmpc]=='Q') return false;
            tmpr--;tmpc--;
        }
        tmpr = r;
        tmpc = c;
        //diagonalwise niche
        while(tmpr>=0 && tmpc<n){
            if(board[tmpr][tmpc]=='Q') return false;
            tmpr--;tmpc++;
        }
        return true;
    }
    void nqueen(int i, int n,vector<string>&board, vector<vector<string>>&ans){
        if(i==n){
            ans.push_back(board);
            return;
        }
        for(int cc=0;cc<n;cc++){
            if(ok(i, cc, n, board)){
                board[i][cc] = 'Q';
                nqueen(i+1, n, board, ans);
                board[i][cc] = '.';//backtrack
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n, string(n, '.'));
        nqueen(0, n, board, ans);
        return ans;
    }
};

//Another Approach
Time Complexity: O(N!)
Space Complexity: O(N^2)

- This approach is slightly better cause uses hashing 

class Solution {
public:
    void nqueen(int col, int n,vector<string>&board, vector<vector<string>>&ans, 
    vector<int>&leftrow, vector<int>&updiagonal, vector<int>&downdiagonal){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if( leftrow[row]==0 &&  updiagonal[row + col]==0 && downdiagonal[n-1 + col - row]==0){
                leftrow[row] = 1;
                updiagonal[row + col] = 1;
                downdiagonal[n-1 + col - row] = 1;
                board[col][row] = 'Q';
                nqueen(col+1, n, board, ans, leftrow, updiagonal, downdiagonal);
                //backtrack
                board[col][row] = '.';
                leftrow[row] = 0;
                updiagonal[row + col] = 0;
                downdiagonal[n-1 + col - row] = 0;
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n, string(n, '.'));
        vector<int> leftrow(n,0), updiagonal(2*n - 1, 0), downdiagonal(2*n - 1 , 0);
        nqueen(0, n, board, ans, leftrow, updiagonal, downdiagonal);
        return ans;
    }
};

//#######################################################################
//#######-------18. Sudoko Solver | Backtracking--------########
//Tutorial: https://takeuforward.org/data-structure/sudoku-solver/
//Problem: https://leetcode.com/problems/sudoku-solver/description/

Similar to N Queen
------------
Approach:
1. check if it is valid box for number 0 to 9
2. if so run the recursion 
3. If ulmately the recursion completes all the numbers, keep returning true 
------------

class Solution {
public:
    bool ok(vector<vector<char>>&board, int r, int c, char ch){
        for(int i=0;i<9;i++){
            if(board[i][c]==ch) return false;
            if(board[r][i]==ch) return false;
            if(board[ 3 * (r/3) + i/3 ][3 * (c/3) + i%3] == ch) return false;
        }
        return true;
    }
    bool f(vector<vector<char>>&board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if( board[i][j] == '.'){
                    for(int k='1';k<='9';k++){
                        if( ok(board, i, j, k) ){
                            board[i][j] = k;
                            if( f(board) == true ) return true;//if anytime this is false then backtracking
                            else board[i][j] = '.';
                        } 
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        f(board);
    }
};

//#######################################################################
//#######-------19. M-Coloring Problem | Backtracking--------########
//Tutorial: https://takeuforward.org/data-structure/m-coloring-problem/
//Problem: https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

------------
Approach:
1. 
------------
Time Complexity: O(M^N)
Space Complexity: O(N^2)

//#######################################################################
//#######-------20. Palindrome Partitioning--------########
//Tutorial: https://takeuforward.org/data-structure/palindrome-partitioning/
//Problem: https://leetcode.com/problems/palindrome-partitioning/description/

------------
Approach:
instead of take and not_take use 1 ghor, some ghor cutting approach:

1. 1 ghor and some ghor vag kora jodi palindrome hoi 
2. if index == n tahole push the answer
------------
class Solution {
public:
    bool check_pal(string s, int l, int r){
        while(l<=r){
            if(s[l++]!=s[r--]) return false;
        }
        return true;
    }
    void f(int index, int n,vector<string>subarr, string original,vector<vector<string>>&ans){
        if(index == n){
            ans.push_back(subarr);
            return;
        }
        
        for(int i=index;i<n;i++){
            string s = original.substr(index, i-index+1);
            if( check_pal(s, 0, s.size()-1) ){
                subarr.push_back(s);
                f(i+1, n, subarr, original,ans);
                //ek part e divide korar jnno i+1, dicchi everytime
                //na parle i er man berei jabe
                //eg: acaded, ["aca","ded"] is a valid answer
                subarr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string original) {
        vector<vector<string>> ans;
        int n = original.size();
        vector<string>sub;
        f(0, n, sub, original, ans);
        return ans;
    }
};

//#######################################################################
//#######-------21. Rat in A Maze | Backtracking--------########
//Tutorial: https://takeuforward.org/data-structure/rat-in-a-maze/
//Problem: https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

- Did similar problems in Dynamic Programming
------------
Approach:
1. Move L, R, U, D and keep adding answer if it is a valid ghor 
2.1 After reaching n-1 and m==1 backtrack,
2.2 remove direction and visited cell while backtracking
------------
Time Complexity: O(3^(m*n)), because on every cell we need to try 3 different directions. 1 cell is eliminated because we came from that
Space Complexity:  O(m*n), Maximum Depth of the recursion tree(auxiliary space).

class Solution {
  public:
    bool isValid(int x, int y, int n, int m){
        return x>=0 && x<n && y>=0 && y<m;
    }
    void f(int i, int j, int n, int m,string sub, vector<vector<int>> &mat,
    vector<vector<int>> &visited, vector<string>&ans){
        if(i==n-1 && j==m-1){
            ans.push_back(sub);
            return;
        }
        vector<int>dx={0, 0, -1, 1};
        vector<int>dy={-1, 1, 0, 0};
        vector<char>dir={'L', 'R', 'U', 'D'};
        visited[i][j] = 1;
        for(int k=0;k<4;k++){
            int x = i + dx[k];
            int y = j + dy[k];
            char d = dir[k];
            if( isValid(x,y,n,m) && !visited[x][y] && mat[x][y]==1){
                sub+=d;
                f(x, y,n, m, sub, mat, visited, ans);
                sub.pop_back();
            }
        }
        visited[i][j] = 0;
        return;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<string> ans;
        string sub = "";
        vector<vector<int>>visited(n, vector<int>(m, 0));
        f(0, 0, n, m, sub, mat, visited, ans);
        if( mat[0][0] == 0 ) return {"-1"};
        if( !ans.empty() ) return ans;
        else return {"-1"};
    }
};

//#######################################################################
//#######-------22. K-th Permutation Sequence--------########
//Tutorial: https://takeuforward.org/data-structure/find-k-th-permutation-sequence/
//Problem: https://leetcode.com/problems/permutation-sequence/description/

------------
Approach:
1. 
------------

//#######################################################################
//#######-------23. Count Inversions in an Array--------########
//Tutorial: https://takeuforward.org/data-structure/count-inversions-in-an-array/

//Problem: https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

------------
Approach:
1. Use merge sort to count the inversion
------------
Time Complexity: O(Nlogn)
Space Complexity: O(N)

class Solution {
  public:
    long long merge(long long ar[],long long l,long long m, long long h){
        vector<long long> temp;
        long long cnt = 0;
    
        //low...mid
        //mid+1...high
        long long i = l;      // Initial index of left subarray
        long long j = m + 1;  // Initial index of right subarray
    
        // Merging the two arrays
        while (i <= m && j <= h) {
            if (ar[i] <= ar[j]) {
                temp.push_back(ar[i]);
                i++;//oi position er kaj shesh, tai ++
            } else {
                temp.push_back(ar[j]);
                cnt+= (m + 1 - i);
                j++;
            }
        }
    
        //if there are elements on the left still remains
        while (i <= m) {
            temp.push_back(ar[i]);
            i++;
        }
    
        //if there are elements on the right still remains
        while (j <= h) {
            temp.push_back(ar[j]);
            j++;
        }
    
        // moving all elements to an array / Copy elements from temp back to ar[]
        for (long long k = l; k <= h; k++) {
            ar[k] = temp[k-l];//
        }
        return cnt;
    }
    
    long long merge_sort(long long ar[], long long l,long long h){
        long long cnt = 0;
        if(l>=h){
            return cnt;
        }
        long long m = l + (h-l)/2;
        cnt+=merge_sort(ar,l,m);//left half
        cnt+=merge_sort(ar,m+1,h);//right half
    
        //function to merge and sort the array
        cnt+=merge(ar,l,m,h);
        return cnt;
    }
    long long int inversionCount(long long arr[], int n) {
        return merge_sort(arr, 0LL, n-1);
    }
};
--------------------------------------------
--------------------------------------------
//Problem: https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/



//###############################################################################################
-------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------
//###############################################################################################



//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//##########-------More Problems - Not On Video --------#################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

- Below are the problems available in the tuf website, but not in the videos

//#######################################################################
//#######-------Lec1 - Get a strong hold--------########


//#######################################################################
//#######-------Lec1.1 Recursive Implementation of atoi()--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/string-to-integer-atoi/description/
https://www.geeksforgeeks.org/problems/implement-atoi/1

------------
Approach:
1. 
------------

//#######################################################################
//#######-------Lec1.2 Pow(x, n)--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/powx-n/description/

------------
Approach:
1. Use Binary Exponentiation 
2. When it is negative number gets reduced by half, so 1/number
------------
class Solution {
public:
    double pows(double A, int b){
        long long B = b;
        if(B==0){
            return 1;
        }
        if(B<0){
            B = 1LL * -B;
            A = 1/A;
        }
        double v = pows(A , B/2);
        v = (v * v);
        if( B%2 ) v = ( v * A);
        return v;
    }

    double myPow(double x, int n) {
        return pows(x, n);
    }
};

//#######################################################################
//#######-------Lec1.3 Count Good numbers--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/count-good-numbers/description/
https://www.geeksforgeeks.org/problems/count-good-numbers/0
------------
Approach:
1. 
------------

//#######################################################################
//#######-------Lec1.4 Sort a stack using recursion--------########
//Tutorial: 
//Problem: https://www.geeksforgeeks.org/problems/sort-a-stack/1

------------
Approach:
1. 
------------

//#######################################################################
//#######-------Lec1.5 Reverse a stack using recursion--------########
//Tutorial: 
//Problem: https://www.geeksforgeeks.org/problems/reverse-a-stack/1

------------
Approach:
1. 
------------


-------------------------------------------------------------------------
-------------------------------------------------------------------------
//#######################################################################
//#######-------Lec2 - Subsequences Pattern--------########


//#######################################################################
//#######-------Lec2.1 Generate all binary strings--------########
//Tutorial: 
//Problem: https://www.geeksforgeeks.org/problems/generate-all-binary-strings/1

------------
Approach:
1. 0 thakle 2 ta option, 0 or 1 add korbo 
1. 1 thakle 1 ta option, add 0

NOTE: for num == 1, ans, '0' and '1'
------------
class Solution{
public:
    void f(int index, int num, string sub, vector<string>&ans){
        //cout<< sub << ' ' << index << endl;
        if(index==num){
            ans.push_back(sub);
            return;
        }

        if(sub.back()=='0'){
            sub+='0';
            f(index+1, num, sub, ans);
            sub.pop_back();
            sub+='1';
            f(index+1, num, sub, ans);
        }
        else if(sub.back()=='1') {
            sub+='0';
            f(index+1, num, sub, ans);
        }
    }
    vector<string> generateBinaryStrings(int num){
        vector<string> ans;
        f(1, num, "0",ans);
        f(1, num, "1",ans);
        return ans;
    }
};

//#######################################################################
//#######-------Lec2.2 Generate Paranthesis--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/generate-parentheses/description

------------
Approach:
4 Cases
1. if '(' count == n/2, then need only ')'
2.1 if '(' count == ')' count, then need only '('
2.2 else need both '(' and ')' 
------------

class Solution {
public:
    void f(int cnt,int cnt2, int n, string subarr, vector<string>&ans){
        if(cnt+cnt2==n*2){
            ans.push_back(subarr);
            return;
        }

        if(cnt == n){
            f(cnt, cnt2+1, n, subarr+')', ans);
        }
        else{
            if( cnt == cnt2 ) f(cnt+1, cnt2, n, subarr+'(', ans);
            else{
                f(cnt+1, cnt2, n, subarr+'(', ans);
                f(cnt, cnt2+1, n, subarr+')', ans);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string sub = "(";
        f(1,0, n, sub, ans);
        return ans;
    }
};

//#######################################################################
//#######-------Lec2.3 Letter Combinations of a Phone number--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

------------
Approach:
1. Just generate all subsets using all the digits using recursion
------------
class Solution {
public:
    void f(int index, int n, string subarr,string digits, vector<string>list, vector<string>&ans){
        if(index == n){
            ans.push_back(subarr);
            return;
        }
        int indices = digits[index] - '0';
        for(int i=0;i<list[indices].size();i++){
            f(index+1, n, subarr + list[indices][i],digits, list, ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> list{"","","abc", "def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        int n = digits.size();
        string sub = "";
        if(digits.empty()) return ans;
        f( 0, n, sub, digits, list, ans);// A little confused on why loop is not used here
        return ans;
    }
};

-------------------------------------------------------------------------
-------------------------------------------------------------------------
//#######################################################################
//#######-------Lec 3 - Trying out all Combos / Hard--------########


//#######################################################################
//#######-------Lec3.1 Word Search--------########
//Tutorial: https://takeuforward.org/data-structure/word-search-leetcode/
//Problem: https://leetcode.com/problems/word-search/description/

Prerequisite: Lec3.2 Word Break

------------
Approach:
1. Start from i,j every cell where i,j is board[i][j] == original[0]
2. From there keep building the string, and keep increasing index+1 with it whenever matches with original
3. if index == original.size() keep returning answer
------------

class Solution {
public:
    bool isValid(int x, int y, int n, int m){
        return x>=0 && x<n && y>=0 && y<m;
    }

    bool f(int xx, int yy, int index, int ln, string original,int n, int m,
        vector<vector<char>>& board, vector<vector<int>>&visited){
        if(index==ln) return true;

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {-1, 1, 0, 0};

        visited[xx][yy] = true;
        for(int k = 0;k<4;k++){
            int x = xx + dx[k];
            int y = yy + dy[k];
            if( isValid(x,y,n,m) && !visited[x][y] && board[x][y] == original[index] ){
                if( f(x, y, index+1, ln, original, n,m, board, visited) ) return true;
            }
        }
        visited[xx][yy] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string original) {
        int n = board.size();
        int m = board[0].size();
        int ln = original.size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        //start from every cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == original[0]) {
                    if( f(i, j, 1, ln, original, n, m, board,visited) == true )
                    return true;
                }
            }
        }
        return false;
    }
};

//#######################################################################
//#######-------Lec3.2 Word Break--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/word-break/description/

------------
Approach:
Think of substr of original word concept 

1. Run recursion for every word in the list
2. update the size only if it is inside the original word
3. word thakle sz == original.size() ekbar hobei
------------
class Solution {
public:
    bool f(int sz, string original, int n,vector<string>& wordDict,
        vector<int>&dp){
        if(sz==original.size()) return true;
        if(dp[sz]!=-1) return dp[sz];

        for(int i=0;i<n;i++){
            int ln = wordDict[i].size();
            //make sure the size if always below original size and the word is a substr of original
            if( sz+ln <= original.size() && original.substr(sz, ln) == wordDict[i] ){
                if( f(sz+ln, original, n, wordDict,dp) ) return dp[sz] = true;
            }
            
        }
        return dp[sz] = false;
    }
    bool wordBreak(string original, vector<string>& wordDict){
        vector<string>sub;
        int n = wordDict.size();
        int ln = original.size();
        vector<int>dp(ln+1, -1);
        return f(0, original, n, wordDict,dp);
    }
};

//#######################################################################
//#######-------Lec3.3 Expression Add Operators--------########
//Tutorial: 
//Problem: https://leetcode.com/problems/expression-add-operators/description/
https://www.geeksforgeeks.org/problems/expression-add-operators/0

------------
Approach:
1. 
------------


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


//#######-------xxxxxxxx-------########
//#######-------xxxxxxxx-------########

//Linked List
//LinkedList

- See notion notes 
- All you have to do is the linking in linkedlist
- never ever change/temper your head, use a temporary node before traversing or manipulating it
- be sure where to start and where to stop in linked list 
- connect other nodes, then untie the tmp node, then delete tmp
- Know where to link and where to not link
- Concept of dummy nodes, when returning own head as answer

Confusions:

1. Intution of L17. Find the starting point of the Loop/Cycle in LinkedList 
2. 
L18. Delete all occurrences of a Key in DLL
//confused on this part
if(curr == *head){
    *head = (*head)->next;
}
3. https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/
not sure how to solve it
4.
L10. Check if a LinkedList is Palindrome or Not
???? Where is wrong bujhtesi na optimal approach e
5. L9. Reverse a LinkedList | Iterative and Recursive
recursive approach bujhi nai
6. 
L4. Reverse a DLL
7.
https://leetcode.com/problems/remove-linked-list-elements/
solve it 

todo:

https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1



---------------------------------------------------------------------------------------------------------
Stiver LinkedList Playlist: https://www.youtube.com/playlist?list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU
Resource: https://takeuforward.org/linked-list/top-linkedlist-interview-questions-structured-path-with-video-solutions/
Resource2: https://takeuforward.org/blogs/linked-list
---------------------------------------------------------------------------------------------------------

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//##########-------Lec 1: Learn 1D LinkedList--------####################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------L1. Introduction to LinkedList | Traversal | Length | Search an Element--------########
//Tutorial: https://www.geeksforgeeks.org/what-is-linked-list/


//Introduction to LinkedList, array to linkedist
//Problem1: https://www.geeksforgeeks.org/problems/introduction-to-linked-list/1
Node* constructLL(vector<int>& arr) {
    Node *head = new Node(arr[0]);
    Node *move = head;//first address is the head itself
    for(int i=1;i<arr.size();i++){
        Node *tmp = new Node(arr[i]);
        move->next = tmp;//link the address
        move = tmp;//change the new link with new address
    }
    return head;
}

//Find the length of the linkedlist
//Problem2: https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/0
//Function to count nodes of a linked list.
int getCount(struct Node* head){
    int ct = 0;
    Node *tmp = head;
    while(tmp != NULL){
        ct++;
        tmp = tmp->next;
    }
    return ct;
}

//Search an element in the LL
//Problem3: https://www.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1
class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, struct Node* head, int key) {
        Node *tmp = head;
        while(tmp){
            if(tmp->data == key) return true;
            tmp = tmp->next;
        }
        return false;
    }
};

//#######################################################################
//#######-------L2. Deletion and Insertion in LL | 8 Problems--------########
//Tutorial: https://takeuforward.org/data-structure/maximum-sum-of-non-adjacent-elements-dp-5/
//Problem: https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261


//8 Problems
Delete, insert -> at head, at last, at a position, value wise (Total 8 problems)

-------------------------------------------------------------------------
//Delete
Tutorial: https://www.geeksforgeeks.org/deletion-in-linked-list/

1. Delete First Node: https://www.geeksforgeeks.org/remove-first-node-of-the-linked-list/
2. Delete last Node: https://www.geeksforgeeks.org/remove-last-node-of-the-linked-list/
3. Delete any Node: https://www.geeksforgeeks.org/problems/delete-a-node-in-single-linked-list/1
4. Delete with value: Delete node with a value (same as 3 no)
delete any node: keep a track of previous and target->next->next er sathe link kora

//delete node at a position
Node* deleteNode(Node *head,int x)
{   
    if(head == NULL) return NULL;
    Node *tmp = head, *prev = NULL;
    if(x==1){
        head = head->next;
        delete tmp;
        return head;
    }
    int ct = 0;
    while(tmp){
        ct++;
        if(ct==x){
            prev->next = prev->next->next;//linking
            delete tmp;
            break;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return head;
}

-------------------------------------------------------------------------
//Insert in linkedlist
//Tutorial: https://www.geeksforgeeks.org/insertion-in-linked-list/
//Problem: https://www.geeksforgeeks.org/problems/linked-list-insertion-1587115620/0

class Solution{
  public:
    Node *insertAtBegining(Node *head, int x) {
       Node *tmp = new Node(x);
       tmp->next = head;
       return tmp;
    }
    
    
    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  {
       Node *tmp = head;
       Node *ins = new Node(x);
       if(head==NULL){
           return ins;
       }
       while(tmp->next){//tmp->next stop at the last element not the after last element
           tmp = tmp->next;
       }
       tmp->next = ins;
       return head;
    }
};

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//########-------Lec 2: Learn Doubly LinkedList--------##################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################


//#######################################################################
//#######-------L3. Introduction to Doubly LinkedList | Insertions and Deletions--------########

//Tutorial: https://www.geeksforgeeks.org/introduction-and-insertion-in-a-doubly-linked-list/

8 variation: 
Deletion and insertion(front, back, kth, at a node)

//Delete
Delete head: https://takeuforward.org/data-structure/delete-head-of-a-doubly-linked-list/
Delete last node/tail: https://takeuforward.org/data-structure/delete-last-node-of-a-doubly-linked-list/
Delete kth: https://takeuforward.org/doubly-linked-list/delete-the-kth-node-of-a-doubly-linked-list/
Delete node: https://www.geeksforgeeks.org/delete-a-node-in-a-doubly-linked-list/


//Insert
Before head: https://takeuforward.org/doubly-linked-list/insertion-at-the-head-of-a-doubly-linked-list/
Before tail: https://takeuforward.org/doubly-linked-list/insert-before-the-tail-of-a-doubly-linked-list/
Before kth: https://takeuforward.org/doubly-linked-list/insert-before-the-kth-node-of-a-doubly-linked-list/
Before a node: https://takeuforward.org/doubly-linked-list/insert-before-a-given-node-of-a-dll/



//////////////////////////////////////////////////////////////

problems:
-------------------------------------------------------------------------
//Convert Array to DLL
//Problem: https://www.naukri.com/code360/problems/introduction-to-doubly-linked-list_8160413
Node* constructDLL(vector<int>& arr) {
    Node *head = new Node(arr[0]);//cause we cannot temper head
    Node *mv = head;
    for(int i=1;i<arr.size();i++){
        Node *tmp = new Node(arr[i], nullptr, mv);//Node(value, next, prev)
        mv->next = tmp;//connect the next
        mv = tmp;
    }
    return head;
}

-------------------------------------------------------------------------
-------------------------------------------------------------------------
//Deletion of head of the DLL
//Problem: https://www.naukri.com/code360/problems/insert-before-the-given-node-of-a-doubly-linked-list_9719100

Node * deleteHead(Node *head) {
    if(head->next == NULL){
        return NULL;
    }
    Node *tmp = head;
    head = head->next;
    tmp->next = head->prev = NULL;
    free(tmp);
    return head;
}
-------------------------------------------------------------------------
//Deletion of tail of the DLL
//Problem: https://www.naukri.com/code360/problems/delete-last-node-of-a-doubly-linked-list_8160469
 
Node * deleteLastNode(Node *head) {
    if(head->next == NULL) return nullptr;
    Node *move = head;
    while(move->next){//last er tate thama
        move = move->next;
    }
    move->prev->next = move->prev = NULL;
    delete move;
    return head;
}
-------------------------------------------------------------------------
//Deletion of the Kth node of the DLL
//Problem: https://www.naukri.com/code360/problems/delete-k-th-node-from-doubly-linked-list_9723679
 
- connect other nodes, then untie the tmp node, then delete 
Node *deleteNode(Node *head, int k){
    if(k==1){
        return head->next;
    }
    int ct = 0;
    Node *tmp = head;
    while(head->next){
        ct++;
        if(ct==k)break;
        tmp = tmp->next;
    }
    Node *previous = tmp->prev;
    Node *front = tmp->next;
    
    if(front==NULL){
        previous->next = nullptr;
        tmp->prev = nullptr;
        delete tmp;
        return head;
    }
    
    previous->next = front;//this will give segmeneted fault when front is null, so handle it correctly
    front->prev = previous;

    tmp->prev = tmp->next = nullptr;
    delete tmp;
    return head;
}
-------------------------------------------------------------------------
//Deletion of a given node(!head)
//Problem: https://www.naukri.com/code360/problems/non-head-node-deletion_9719173

void deleteNode(Node* node) {
    Node *previous = node->prev;
    Node *front = node->next;
    if(front == NULL){
        previous->next = node->prev = NULL;
        delete node;
        return;
    }

    //linking
    previous->next = front;
    front->prev = previous;

    node->prev = node->next = NULL;
    delete node;
    return;
}

-------------------------------------------------------------------------
-------------------------------------------------------------------------
//Insert at end
//Problem: https://www.naukri.com/code360/problems/insert-at-end-of-doubly-linked-list_8160464

Node * insertAtTail(Node *head, int k) {
    if(head==NULL){
        return new Node(k);
    }
    Node *tmp = head;
    while(tmp->next){
        tmp = tmp->next;
    }
    Node *newnode = new Node(k);
    newnode->prev = tmp;
    tmp->next = newnode;
    return head;
}

-------------------------------------------------------------------------
//Insert at a position
//Problem: https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1

void addNode(Node *head, int pos, int data)
{
   Node *tmp = head;
   pos++;
   int ct = 0;
   while(tmp){
       ct++;
       if(ct==pos)break;
       tmp = tmp->next;
   }
    Node *front = tmp->next;
    Node *back = tmp;
    if(front==NULL){
       Node *newnode = new Node(data);
       back->next = newnode;
       newnode->prev = back;
       return;
    }
    Node *newnode = new Node(data);
    newnode->next = front;
    newnode->prev = back;
    back->next = newnode;
    front->prev = newnode;
    return;
}

//#######################################################################
//#######-------L4. Reverse a DLL | Multiple Approaches--------########
//Tutorial: https://takeuforward.org/data-structure/reverse-a-doubly-linked-list/
//Problem: https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

------------
Approach:
1. Keep swapping, swap(curr->prev, curr->next);
2. at the end, return curr->prev->prev;
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
  public:
    DLLNode* reverseDLL(DLLNode* head) {
        if(head == NULL || head->next==NULL) return head;
        DLLNode* curr = head, *ans;
        while(curr){
            swap(curr->prev, curr->next);
            ans = curr;
            curr = curr->prev;//due to swap it is the next node actually
        }
        return ans;
    }
};

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#########-------Lec 3: Medium Problems of LL--------###################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

//#######################################################################
//#######-------L5. Add 2 numbers in LinkedList | Dummy Node Approach--------########
//Tutorial: https://takeuforward.org/data-structure/add-two-numbers-represented-as-linked-lists/
//Problem: https://leetcode.com/problems/add-two-numbers/description/

- Prefer the concept of dummy node when you have to create a new list
------------
Approach:
1. Create a dummy node which is the head of new linked list.
2. Create a node curr, initialise it with dummy
3. Initialize carry to 0.
4. Loop through lists l1 and l2, Keep calculating sum and carry on the way

Note: if carry remains at the end, create another node for that and move the curr
------------
Time Complexity: O(max(m,n)). Assume that m and n represent the length of l1 and l2 respectively
Space Complexity: O(max(m,n)). The length of the new list is at most max(m,n)+1.

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        int sum = 0, carry = 0;
        while(l1 || l2){
            sum = 0;
            if(l1) sum+=l1->val;
            if(l2) sum+=l2->val;
            sum = sum + carry;
            ListNode* node = new ListNode( sum%10 );
            curr->next = node;
            curr = curr->next;
            carry = sum/10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        if(carry){
            ListNode* node = new ListNode( carry );
            curr->next = node;
            curr = curr->next;
        }
        return dummy->next;
    }
};

//#######################################################################
//#######-------L6. Odd Even Linked List | Multiple Approaches--------########
//Tutorial: https://takeuforward.org/data-structure/segregate-even-and-odd-nodes-in-linkedlist
//Problem: https://leetcode.com/problems/odd-even-linked-list/description/
https://www.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1


------------
Approach:
1. Even indices always odd indices er theke agai thakbe, (so even indices check kora)
2. Move odd->next = odd->next->next; and even->next = even->next->next;
3. After that, update even node 
4. Last odd Node er sathe first even Node linkup kora 
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL  || head->next==NULL) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* even_head = head->next;
        while(even!=NULL && even->next!=NULL){
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }
        odd->next = even_head;
        return head;
    }
};

//#######################################################################
//#######-------L7. Sort a LinkedList of 0's, 1's and 2's--------########
//Tutorial: https://www.geeksforgeeks.org/sort-linked-list-0s-1s-2s-changing-links/
//Problem: https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

//Better Approach
------------
Approach:
1. count the frequency of the ones , zeros, twos 
2. Make a new node, keep updating the node according to frequency
------------
Time Complexity: O(2N)
Space Complexity: O(1) [not creating any extra space to solve the problem]

class Solution {
  public:
    Node* segregate(Node* head) {
        int z = 0, o = 0, t = 0;
        Node *cur = head;
        Node *ans = head;
        if(cur==NULL) return NULL;
        
        while(cur){
            if(cur->data==0)z++;
            else if(cur->data==1)o++;
            else if(cur->data==2)t++;
            cur=cur->next;
        }
        
        while(z--){
            ans->data = 0;
            ans = ans->next;
        }
        while(o--){
            ans->data = 1;
            ans = ans->next;
        }
        while(t--){
            ans->data = 2;
            ans = ans->next;
        }
        
        return head;
    }
};


//Optimal Approach
------------
Approach:
1. Take 3 node for 0, 1, 2, and move the nodes when 0, 1, 2 found
2. Link all of them after traversing the full array
3. return the zeroHead->next; as answer
------------
Time Complexity: O(N)
Space Complexity: O(1) [using the same nodes]
class Solution {
  public:
    Node* segregate(Node* head) {
        Node *cur = head;
        
        Node *zeroHead = new Node(-1);
        Node *oneHead = new Node(-1);
        Node *twoHead = new Node(-1);
        
        Node *zero = zeroHead;
        Node *one = oneHead;
        Node *two = twoHead;
        
        if(cur==NULL) return NULL;
        
        while(cur){
            if(cur->data==0){
                zero->next = cur;
                zero = zero->next;
            }
            else if(cur->data==1){
                one->next = cur;
                one = one->next;
            }
            else if(cur->data==2){
                two->next = cur;
                two = two->next;
            }
            cur=cur->next;
        }

        zero->next = oneHead->next?oneHead->next: twoHead->next;
        one->next = twoHead->next;
        two->next = NULL;
        Node *ans = zeroHead->next;
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        return ans;
    }
};

//#######################################################################
//#######-------L8. Remove Nth Node from the end of the LinkedList--------########
//Tutorial: https://takeuforward.org/data-structure/remove-n-th-node-from-the-end-of-a-linked-list/
//Problem: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

//Better Approach
------------
Approach:
1. You will have to delete the length - k + 1 node 
2. Calculate length, and find out the index to delete 
3. after that delete that index and connect the pointers

Note: keep a prev to connect prev ->next = delIndex->next;

3 point deletion:
a.first 
b.middle
c. last
------------
Time Complexity: O(2N)
Space Complexity: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        int ct = 0, ln = 0;
        ListNode *curr = head;
        if(curr==NULL) return curr;

        while(curr){
            curr = curr->next;
            ln++;
        }
        curr = head;
        int delIndex = ln - k + 1;
        ListNode *delnode, *prev = NULL;
        if(delIndex<0) return curr;//if delIndex > total length

        while(curr){
            if( delIndex == ++ct){
                delnode = curr;
                break;
            }
            prev = curr;
            curr = curr->next;
        }

        //first
        if(prev == NULL){
            //delete 
            return delnode->next;
        }
        //last
        else if(delnode->next==NULL){
            prev->next = NULL;
            delete delnode;
            return head;
        }
        //middle
        else{
            prev->next = delnode->next;
            delete delnode;
            return head;
        }
    }
};

//Optimal Approach
------------
Approach:
1. Keep a fast pointer and keep a slow pointer, make slow pointer to be deleted inex
2. Move fast and slow pointer simultaneouly
3. at the end, remove the slow->next pointer

------------
Time Complexity: O(N)
Space Complexity: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        ListNode *fast = head;
        ListNode *slow = head;
        //if(head==NULL) return head;

        for(int i=0;i<k;i++) fast = fast->next;

        //removing the first node
        if(fast==NULL){
            return head->next;
        }

        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode *delnode = slow->next;
        slow->next = slow->next->next;
        delete delnode;
        return head;
    }
};

//#######################################################################
//#######-------L9. Reverse a LinkedList | Iterative and Recursive--------########
//Tutorial: https://takeuforward.org/data-structure/reverse-a-linked-list/
//Problem: https://leetcode.com/problems/reverse-linked-list/description/


//Better Approach

------------
Approach:
1. Put all elements in the stack
2. change the links from st.top(), and move next 
------------
Time Complexity: O(2N)
Space Complexity: O(N) [for using the stack]

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> st;
        ListNode *curr = head;
        if(curr==NULL) return NULL;
        while(curr){
            st.push(curr);
            curr = curr->next;
        }
        
        head = st.top();
        curr = head;
        st.pop();
        while(!st.empty()){
            curr->next = st.top();
            st.pop();
            curr = curr->next;
        }
        curr->next = NULL;
        return head;
    }
};

//Optimal Approach
------------
Approach:
1. reverse the linking
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head, *prev = NULL, *front = head;
        if(curr==NULL) return NULL;

        while(curr){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
};

//Recursive Approach
------------
Approach:
1. reverse the linking
------------
Time Complexity: O(N)
Space Complexity: O(N)

???????


//#######################################################################
//#######-------L10. Check if a LinkedList is Palindrome or Not--------########
//Tutorial: https://takeuforward.org/data-structure/check-if-given-linked-list-is-plaindrome/
//Problem: https://leetcode.com/problems/palindrome-linked-list/description/

//Better Approach
------------
Approach:
1. Keep a stack of the elements 
2. cur->val == st.top(), if not equal then false, else true
------------
Time Complexity: O(2N)
Space Complexity: O(N)

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> st;
        ListNode *curr = head;
        if(curr==NULL) return NULL;
        while(curr){
            st.push(curr);
            curr = curr->next;
        }
        curr = head;
        while(!st.empty()){
            if (curr->val!=st.top()->val) return false;
            st.pop();
            curr = curr->next;
        }
        return true;
    }
};

//Optimal Approach
Using Tortoise and Hare Algorithm
- Slow pointer goes 1 step 
- Fast pointer goes 2 step

------------
Approach:
1. Compare half of the list
2. 
- Slow pointer goes 1 step 
- Fast pointer goes 2 step

slow pointer is your middle element 
after that compare head->data == slow->data and move 

if head->data != slow->data then false, else true

------------
Time Complexity: O(N/2 + N/2 + N/2)
Space Complexity: O(1)

???? Where is wrong bujhtesi na

//#######################################################################
//#######-------L11. Add 1 to a number represented by LinkedList--------########
//Tutorial: https://www.geeksforgeeks.org/add-1-number-represented-linked-list/
//Problem: https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

//Better Approach
------------
Approach:
1. Reverse the linked list 
2. Add 1 to the elements in the list, Keep taking carry 
3. If carry is 0, then break from the linked list and return the newhead as answer
------------
Time Complexity: O(N) + O(2N) [for reversing] = O(3N)
Space Complexity: O(1)

class Solution{
  public:
    Node* reverseList(Node* head) {
        Node *curr = head, *prev = NULL, *front = head;
        if(curr==NULL) return NULL;

        while(curr){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
    
    Node* addOne(Node* head) {
        Node *curr = head;
        if(curr==NULL) return curr;
        
        Node* rev = reverseList(curr);
        Node* newHead = rev;
        if(rev->data!=9){
            newHead->data = newHead->data + 1;// eg: 4 5 == 46 is the answer 
            return reverseList(newHead);
        }
        
        int carry = 0;
        Node *prev = NULL;
        while(rev){
            if(rev->data == 9){
                rev->data = 0;
                carry = 1;
            }
            else{
                rev->data = rev->data + carry;
                carry = 0;//make carry as 0, and return: eg : 4 9 9 == 500 is the answer
                break;
            }
            prev = rev;
            rev = rev->next;
        }
        if(carry){//eg: 9 9 9 == 1000 is the answer
            Node *node = new Node(1);
            prev->next = node;
        }
        return reverseList(newHead);
    }
};


//Optimal Approach
------------
Approach:
1. while backtracking keep adding the carry 
2. if carry remains, add a new node
------------
Time Complexity:  O(N) - Using recursion
Space Complexity: O(N) [stack space of recursion]

class Solution {
  public:
    int add(Node* head) {
        if(head==NULL) return 1;
        int carryNow = head->data + add(head->next);
        head->data = carryNow;
        carryNow/=10;
        return carryNow;
    }
    
    Node* addOne(Node* head) {
        Node *curr = head;
        int carry = add(curr);
        if(carry){
            Node *node = new Node(1);
            node->next = head;
            return node;
        }
        return head;
    }
};

//#######################################################################
//#######-------L12. Find the intersection point of Y LinkedList--------########
//Tutorial: https://takeuforward.org/data-structure/find-intersection-of-two-linked-lists/
//Problem: https://leetcode.com/problems/intersection-of-two-linked-lists/description/

//Better Approach(Using Hashing)
------------
Using Hashing
Approach:
1. Put the addressed of headA by traversing headA 
2. Search for headA in unordered map while traversing headB
------------
Time Complexity: O(N*1) + O(N*1) [unordered set time complexity == O(1)] 
Space Complexity: O(N)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> us;
        while(headA){
            us.insert(headA);
            headA = headA->next;
        }

        while(headB){
            if( us.find(headB)!=us.end() ) return headB;
            headB = headB->next;
        }
        return NULL;
    }
};

//Better Approach(Using Length Difference)
------------
Approach:
1. Find the length of both lists.
2. move the list of which length are bigger
3. Move both list simultaneously, if the both list length is similar after some time
------------
Time Complexity: O(max(a_len, b_len)) + O(till intersion point)
Space Complexity: O(1)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *currA = headA, *currB = headB;
        int a_len = 0, b_len = 0; 
        while(currA || currB){
            if(currA){
                a_len++;
                currA = currA->next;
            }
            if(currB){
                b_len++;
                currB = currB->next;
            }
        }

        currA = headA, currB = headB;
        while(currA || currB){
            if(currA == currB) return currA;
            if(a_len == b_len){//both length is similar so move both simultaneouly
                currA = currA->next;
                currB = currB->next;
            }
            else if(a_len>b_len){
                currA = currA->next;
                a_len--;
            }
            else if(a_len<b_len){
                currB = currB->next;
                b_len--;
            }
        }
        return NULL;
    }
};

//Optimal Approach(Moving both list simultaneously)
------------
Approach:
duitar length different holeo ekbar traverse korar porei length soman howe jabe

1. Take two dummy nodes for each list. Point each to the head of the lists.
2. Iterate over them. If anyone becomes null, point them to the head of the opposite lists 
   and continue iterating until they collide.
3. Handle the case for both become null, if both become null donot move further

Important Oberservations: 
a. For not intersecting nodes, If both of them are at there last node donot move, answer would be null in this case
b. For intersecting nodes, If both of them are at the same node, answer would be that node
------------
Time Complexity: O(a_len + b_len)
Space Complexity: O(1)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *currA = headA, *currB = headB;

        while(currA != currB){
            currA = currA->next;
            currB = currB->next;
            if(currA==currB) return currA;
            if(currA==NULL) currA = headB;
            if(currB==NULL) currB = headA;
        }
        return currA;
    }
};

//#######################################################################
//#######-------L13. Find the middle element of the LinkedList--------########
//Tutorial: https://takeuforward.org/data-structure/find-middle-element-in-a-linked-list/
//Problem: https://leetcode.com/problems/middle-of-the-linked-list/description/

Use Hare and Tortoise Algorithm

------------
Approach:
1. Move slow pointer one time and fast pointer two times 
2. ultimately slow->next is the middle element 
------------
Time Complexity: O(N/2)
Space Complexity: O(1)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head->next==NULL) return head;
        ListNode *slow = head, *fast = head->next;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->next;
    }
};

//#######################################################################
//#######-------L14. Detect a loop or cycle in LinkedList--------########
//Tutorial: https://takeuforward.org/data-structure/detect-a-cycle-in-a-linked-list/
//Problem: https://leetcode.com/problems/linked-list-cycle/description/

Hare and Tortoise Algorithm

------------
Approach:
1. Move slow pointer one time and fast pointer two times 
2. slow == fast hobe if there is a cycle, else fast exhaused hoi jabe 

Observation: 
a. In case of loops, there will never be a last node
------------
Time Complexity: O(N) [Depends on the testcase]
Space Complexity: O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL) return head;
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};

//#######################################################################
//#######-------L15. Find the length of the Loop in LinkedList--------########
//Tutorial: https://takeuforward.org/linked-list/length-of-loop-in-linked-list
//Problem: https://www.geeksforgeeks.org/problems/find-length-of-loop/1

Hare and Tortoise Algorithm

------------
Approach:
1. Apply Hare and Tortoise Algorithm to find out cycle
2. If a cycle found, keep moving one of the pointer until matches again
   Keep increasing answer while on the way 
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
  public:
    int countNodesinLoop(Node *head) {
        if(head==NULL) return 0;
        Node *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                int ans = 1;
                fast = fast->next;
                while(slow!=fast){
                    ans++;
                    fast = fast->next;
                }
                return ans;
            }
        }
        return 0;
    }
};

//#######################################################################
//#######-------L16. Delete the middle node of the LinkedList--------########
//Tutorial: https://takeuforward.org/linked-list/delete-the-middle-node-of-the-linked-list
//Problem: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

Hare and Tortoise Algorithm

------------
Approach:
1. Apply Hare and Tortoise Algorithm to get middle element
2.1 Link Before and after middle element
2.2 Delete the middle element
------------
Time Complexity: O(N/2)
Space Complexity: O(1)

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next==NULL) return NULL;//0 or 1 element
        ListNode *slow = head, *fast = head->next;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* deleteme = slow->next;
        slow->next = slow->next->next;//next element porer element theke nibo
        delete deleteme;
        return head;
    }
};

//#######################################################################
//#######-------L17. Find the starting point of the Loop/Cycle in LinkedList--------########
//Tutorial: https://takeuforward.org/data-structure/starting-point-of-loop-in-a-linked-list/
//Problem: https://leetcode.com/problems/linked-list-cycle-ii/description/

Hare and Tortoise Algorithm

------------
Approach:
1. Apply Hare and Tortoise Algorithm to detect the cycle 
2. If cycle exits, Find the move slow = head, 
3. Now, move both slow and fast, when they are equal that is our starting poin

Intuition:
Slow D distance par kore cycle e before meeting
Fast 2D distance par kore cycle e before meeting

After that head theke arekta pathaile oitao D distance por starting e collide korbe

------------
Time Complexity: O()
Space Complexity: O()
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return head;
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#########-------Lec 4: Medium Problems of DLL--------##################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

//#######################################################################
//#######-------L18. Delete all occurrences of a Key in DLL--------########
//Tutorial: https://www.geeksforgeeks.org/delete-occurrences-given-key-doubly-linked-list/
//Problem: https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1

------------
Approach:
1. If values matches, keep deleting the current pointer and set the links correctly 

Observation:
a. head ei key thakle head->next e point kor
b. Last node er previous thakbe na
c. First node er next thakbe na
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head, int key) {
        Node *curr = *head;
        while(curr){
            if(curr->data == key){
                //confused on this part
                if(curr == *head){
                    *head = (*head)->next;
                }
                
                Node *nextNode = curr->next;
                Node *prevNode = curr->prev;
                
                if(nextNode) nextNode->prev = prevNode;//last node er previous thakbe na
                if(prevNode) prevNode->next = nextNode;//first node er next thakbe na
                delete curr;
                curr = nextNode;
            }
            else{
                curr = curr->next;
            }
        }
    }
};

//#######################################################################
//#######-------L19. Find all Pairs with given Sum in DLL--------########
//Tutorial: https://www.geeksforgeeks.org/find-pairs-given-sum-doubly-linked-list/
//Problem: https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

------------
Approach:
1. Get the head and tail of the list 
2. As the array is sorted, Apply two pointer to solve the problem
------------
Time Complexity: O(2N)
Space Complexity: O(1)

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int, int>> ans;
        Node *curr = head;
        while(curr->next){
            curr = curr->next;
        }
        
        //another condition: while(head->data < curr->data)
        while(head!=curr && head->prev!=curr){//crossing each other
            int s = head->data + curr->data;
            if(s>target) curr = curr->prev;
            else if(s<target) head = head->next;
            else if(s==target){
                ans.push_back({head->data, curr->data});
                curr = curr->prev;
                head = head->next;
            }
        }
        return ans;
    }
};

//#######################################################################
//#######-------L20.1 Remove duplicates from sorted DLL--------########
//Tutorial: https://www.geeksforgeeks.org/remove-duplicates-sorted-doubly-linked-list/
//Problem: https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1

------------
Approach:
1. if curr->data == previous_node->data link properly and delete current node 
Do step 1 until the current pointer is exhausted
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {   
        if(head==NULL ||head->next==NULL) return head;
        Node *curr = head->next;
        
        while(curr){
            Node *prevNode = curr->prev;
            if(curr->data == prevNode->data){
                Node *nextNode = curr->next;
                if(nextNode) nextNode->prev = prevNode;//last element does not have previous, that is why
                prevNode->next = nextNode;
                delete curr;
                curr = nextNode;
            }
            else curr = curr->next;
        }
        return head;
    }
};


//#######-------L20.2 Remove duplicates from sorted LL--------########
//Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
------------
Approach:
1. if curr->data == previous_node->data link properly and delete current node 
Do step 1 until the current pointer is exhausted
------------
Time Complexity: O(N)
Space Complexity: O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL ||head->next==NULL) return head;
        ListNode *curr = head->next, *prev = head;
        
        while(curr){
            if(curr->val == prev->val){
                ListNode *nextNode = curr->next;
                prev->next = nextNode;
                delete curr;
                curr = nextNode;
            }
            else prev = curr, curr = curr->next;
        }
        return head;
    }
};

//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#########-------Lec 5: Hard Problems of LL--------###################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################
//#######################################################################

//#######################################################################
//#######-------L21. Reverse Nodes in K Group Size of LinkedList--------########
//Tutorial: https://takeuforward.org/data-structure/reverse-linked-list-in-groups-of-size-k/
//Problem: https://leetcode.com/problems/reverse-nodes-in-k-group/description/
https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()


//#######################################################################
//#######-------L22. Rotate a LinkedList--------########
//Tutorial: https://takeuforward.org/data-structure/rotate-a-linked-list/
//Problem: https://leetcode.com/problems/rotate-list/description/

------------
Approach:
1. Calculate the length of the list.
2.1 Link the last node with first node
2.2 make the modified kth node point to null
2.3 make the modified k+1th node as your new head 

modified k = total_length - actual k
------------
Time Complexity: O(N)
Space Complexity: O(1)

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL  || k==0) return head;

        ListNode *curr = head;
        int len = 1;
        while(curr->next){
            len++;
            curr = curr->next;
        }
        k = k%len;
        if(k == 0) return head;
        k = len - k;

        //last one link with first one 
        curr->next = head;

        curr = head;
        while(--k){
            curr = curr->next;
        }

        //link thik kora, jekhane rotation hoise
        ListNode *newhead = curr->next;
        curr->next = NULL;
        curr = newhead;

        return newhead;
    }
};

//#######################################################################
//#######-------L23. Merge two sorted Linked Lists--------########
//Tutorial: https://takeuforward.org/data-structure/merge-two-sorted-linked-lists/
//Problem: https://leetcode.com/problems/merge-two-sorted-lists/description/

------------
Approach:
1. Create a dummy node, and point head to the dummy node 
2. Move either of the pointer in which it has smaller value 
Keep doing it until the both list1 and list2 gets exhausted

3. Return dummynode->node as this is our head

Note: Dummy node create kora v v important, nahole head empty value niyei boshe thakbe, we will never get head
------------
Time Complexity: O(N+M)
Space Complexity: O(1) [for storing in list3, we are not creating any space]


Q: Why Time complexity is not O(min(n1 + n2)) ?
A:
example:
list1 = {1, 3, 5, 7, 9}
list2 = {2, 4, 6, 8, 10}

For this case, we would have to travel (n+m) times. Hence, time complexity would be O(n+m)
----------

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *list3= new ListNode(-1), *head = list3;
        while(list1 || list2){
            if(list1 && list2){
                if(list1->val < list2->val){
                    list3->next = list1;
                    list1 = list1->next;
                }
                else{
                    list3->next = list2;
                    list2 = list2->next;
                }
            }
            else if(list1){
                list3->next = list1;
                list1 = list1->next;
                break;//link rest and get out of the while loop
            }
            else if(list2){
                list3->next = list2;
                list2 = list2->next;
                break;//link rest and get out of the while loop
            }

            list3 = list3->next;
        }
        return head->next;
    }
};

//#######################################################################
//#######-------L24. Flattening a LinkedList--------########
//Tutorial: https://takeuforward.org/data-structure/flattening-a-linked-list/
//Problem: https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

------------
Approach:
1. Apply flattenTwoLists algo(same as mergeTwoLists) 
2. Keep solving the flattenTwoLists(head,head->next) until it gets exhausted
------------
Time Complexity: O( N*(2M) ) ~ O(2 N*M) where N is the length of the linked list 
along the next pointer and M is the length of the linked list along the child pointers.
Space Complexity: O(1)

class Solution {
  public:
    Node *flattenTwoLists(Node *list1, Node*list2){
        Node *list3= new Node(-1), *head = list3;
        while(list1 || list2){
            if(list1 && list2){
                if(list1->data < list2->data){
                    list3->bottom = list1;
                    list1 = list1->bottom;
                }
                else{
                    list3->bottom = list2;
                    list2 = list2->bottom;
                }
            }
            else if(list1){
                list3->bottom = list1;
                list1 = list1->bottom;
                break;
            }
            else if(list2){
                list3->bottom = list2;
                list2 = list2->bottom;
                break;
            }
            list3 = list3->bottom;
        }
        return head->bottom;
    }
    
    Node *flatten(Node *head) {
        Node *curr = head;
        while(curr->next){
            head = flattenTwoLists(head, curr->next);
            curr = curr->next;
        }
        return head;
    }
};

//#######################################################################
//#######-------L25. Merge K Sorted Lists--------########
//Tutorial: https://takeuforward.org/linked-list/merge-k-sorted-linked-lists
//Problem: https://leetcode.com/problems/merge-k-sorted-lists/description/

//Better Approach(Taking minimum in every k steps)
------------
Approach:
1. From the head of all the kth node, choose the one with the least value 
2. After that, move that element of the least value 
------------
Time Complexity: O( (N1 + N2 + .... + N*k) * k) ~ O(N * k^2)
Space Complexity: O(1) [As no additional data structures or space is allocated for storing data]

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode *lis= new ListNode(-1), *headd = lis;
        while(1){
            ListNode *curr = NULL;
            int ind = -1;//least node index
            for(int i=0;i<k;i++){
                ListNode *head = lists[i];
                if(head){
                    if(curr==NULL || curr && head->val < curr->val){
                        curr = head;
                        //head = head->next; this is not moving, move the actual lists[ind], 
                        //not some temporary thing 
                        ind = i;
                    }
                }
            }
            if(curr==NULL)break;
            lis->next = curr;
            lis = lis->next;

            lists[ind] = lists[ind]->next;//move the least index value, use this for moving
        }
        return headd->next;
    }
};

//Optimal Approach(Using Min Heap)
------------
Approach:
1. If head is true in the kth node, push them in the priority queue
2.1 After that, maintain the priority queue 
2.2 update lis->next to current element in priority queue 
2.3 if current head is not null push current element in the priority queue
2.4 update lis until priority queue is empty
------------
Time Complexity: O(K log K) + O(N*K*(3*log K)) [first for loop, then for the priority queue list]
Space Complexity: O(K) [at max k element priority queue te ase]

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode *lis= new ListNode(-1), *head = lis;
        priority_queue< pair<int, ListNode*> , vector< pair<int, ListNode*> > , greater< pair<int, ListNode*> > > pq;
        for(int i=0;i<k;i++){
            if(lists[i])pq.push({lists[i]->val, lists[i]});
        }

        while(!pq.empty()){
            auto [v, curr] = pq.top();
            pq.pop();
            
            lis->next = curr;
            lis = lis->next;

            curr = curr->next;
            if(curr) pq.push({curr->val, curr});
        }
        return head->next;
    }
};

//#######################################################################
//#######-------L26. Sort a Linked List | Merge Sort and Brute Force--------########
//Tutorial: https://takeuforward.org/linked-list/sort-a-linked-list
//Problem: https://leetcode.com/problems/sort-list/description/

------------
Approach:
1. Apply merge sort in the linked list 
2. to get the middle element apply Hare and tortoise algo 
------------
Time Complexity: O(logN x (N + N/2)) ~ O(NlogN)
Space Complexity: O(1 * logN) [1 = memory space, Recursive stack space]

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *list3= new ListNode(-1), *head = list3;
        while(list1 || list2){
            if(list1 && list2){
                if(list1->val < list2->val){
                    list3->next = list1;
                    list1 = list1->next;
                }
                else{
                    list3->next = list2;
                    list2 = list2->next;
                }
            }
            else if(list1){
                list3->next = list1;
                list1 = list1->next;
                break;
            }
            else if(list2){
                list3->next = list2;
                list2 = list2->next;
                break;
            }

            list3 = list3->next;
        }
        return head->next;
    }
    
    //O(N/2) for finding middle
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head->next==NULL) return head;
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* merge_sort(ListNode *head){
        if(head==NULL || head->next == NULL) return head;
        
        ListNode* middle = middleNode(head);
        ListNode* left = head, *right = middle->next;
        middle->next = NULL;//unlink the middle node, make it a seperate linkedlist
        
        ListNode* l = merge_sort(left);
        ListNode* r = merge_sort(right);
        return mergeTwoLists(l, r);
    }

    ListNode* sortList(ListNode* head) {
        ListNode *h = merge_sort(head);
        return h;
    }
};

//#######################################################################
//#######-------L27. Clone a LinkedList with Next and Random Pointers | Copy List with Random Pointers--------########
//Tutorial: https://takeuforward.org/data-structure/clone-linked-list-with-random-and-next-pointer/
//Problem: https://leetcode.com/problems/copy-list-with-random-pointer/description/
https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

//Better Approach(Hashing)
------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()


//Optimal Approach
------------
Approach:
1. 
------------
Time Complexity: O()
Space Complexity: O()


//#######################################################################
//#######-------L28. Design a Browser History | LinkedList Implementation--------########
//Tutorial: https://takeuforward.org/linked-list/design-a-browser-history
//Problem: https://leetcode.com/problems/design-browser-history/description/

------------
Approach:
1. Create a Custom Node for the problem
2.1 BrowserHistory() : create a Node 
2.2 visit() : create a Node, and link with preiovus and next 
2.3 back() : move to back until the min(steps, first element) 
2.4 forward() : move to forward until the min(steps, last element) 
------------

class Node {
public:
    string data;
    Node* next;
    Node* prev;

    Node(string x) : data(x), next(nullptr), prev(nullptr) {};
};

class BrowserHistory {
public:
    Node *curr = NULL;
    //Time Complexity: O(1)
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }

    //Time Complexity: O(1)
    void visit(string url) {
        curr->next = new Node(url);
        curr->next->prev = curr;

        curr = curr->next;//move to current
    }

    //Time Complexity: O( min(steps, remaining nodes) )
    string back(int steps) {
        while(steps-- && curr->prev){
            curr = curr->prev;
        }
        return curr->data;
    }
    //Time Complexity: O( min(steps, remaining nodes) )
    string forward(int steps) {
        while(steps-- && curr->next){
            curr = curr->next;
        }
        return curr->data;
    }
};

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



//#######-------xxxxxxxx-------########
//#######-------xxxxxxxx-------########

//Fenwick Tree + Segment Tree
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

        for (int i = 0; i < n; i++)
            // Update BITree for all elements in the input array
            updateBIT(BITree, i, n, arr[i]);

        return BITree;
    }
};

int32_t main() {
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



//#######-------xxxxxxxx-------########
//#######-------xxxxxxxx-------########

//PBDS - policy_based_ordered_set.cpp

//#######-------xxxxxxxx-------########
//#######-------xxxxxxxx-------########




