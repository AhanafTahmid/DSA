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


//#######-------xxxxxxxx-------########






//#######-------xxxxxxxx-------########


