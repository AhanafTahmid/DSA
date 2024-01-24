//Binary search on answer

//binary search is basically elimination, removing parts where our answer does not lies


//#######-------Find the first index of '1' of a monotonic functin(upper bound of the previous element)--------########

Input: 
8
00011111

Answer:
4

int ar[100];
bool ok(int mid){
    if(ar[mid] == 0) return false;
    else return true;
}

void solve(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        scanf("%1d",&ar[i]);
    }
    int l = 0, r = 8, m;
    int ct = 0;

    while(l+1<r){
        m = (l+r)/2;
        if( ok(m) ) r = m;
        else l = m;
    }
    cout<<l<<endl;

    

    //int lo = lower_bound(ar,ar+n,1) - ar;
    //cout<<lo<<endl;
}




//Without ok function

void solve(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        scanf("%1d",&ar[i]);
    }
    int l = 0, r = 8, m;
    int ct = 0;

    while(l+1<r){
        m = (l+r)/2;
        if( ar[m] == 0 ) l = m;
        else r = m;
    }
    cout<<r<<endl;
}


//#######-------E. Maximum Distinct Numbers--------########


//Problem: https://codeforces.com/group/MWSDmqGsZm/contest/223338/problem/E

//OK function will be in sorted order (monotonous)
//OK = 111111000000
//OK = 000000111111



//For this problem Ok(l) = 1, Ok(r) = 0
//initially, l = 1, and r = 0, 111111000000

bool ok(ll mid, ll n){
    ll val = (mid*(mid+1))/2;
    if( val<=n  ) return true;
    else return false;
}

void solve(){
    ll n;
    cin>>n;
    ll l = 1, r = 1, m;
    while(ok(r,n)) r*=2;

    while(l+1<r){
        m = (l+r)/2;
        if( ok(m,n) ) l = m;
        else r = m;
    }
    cout<<l<<endl;
}






//#######------- SQRT FIND   --------########

//l and r pashapashi na asha prjnto, for 9 -> 2.9999999999 -> 3.000000000
//Proti 10 gun er jnno step 3-4 ta beshi hobe



void solve(){
    ll n;
    cin>>n;
    double l = 1, r = n, m;

    while((r-l)>0.000001){//kache anai baad diye dibo
        m = (l+r)/2;
        if( m*m > n){
            r = m;
        }
        else l = m;
    }
    cout<<r<<endl;
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}



//#######------- SQRT FIND - Version 2   --------########



#define eps 1e-12 //0.000000000001

void solve(){
    ll n;
    cin>>n;
    double l = 1, r = n, m;

    while((r-l)>eps){
        m = (l+r)/2;
        if( m*m > n){
            r = m;
        }
        else l = m;
    }

    //cout<< fixed << setprecision(10) << l<<endl;
    cout<< setprecision(10) << fixed << l <<endl;
}


int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}



//#######------- SQRT FIND - Version 3  --------########


void solve(){
    ll n;
    cin>>n;
    double l = 1, r = n, m;

    // log(10^18) ~=40,  60
    for(int i=1;i<=60;i++){
        m = (l+r)/2;
        if( m*m > n){
            r = m;
        }
        else l = m;
    }

    cout<< fixed << setprecision(20);
    cout<< 1e-12 <<endl;

}




void solve(){
    ll n;
    cin>>n;

    ll v = 1e18;// ~=40
    cout<<log(v)<<endl;

}



//#######------- Finding r value, right element where the answer is true or false  --------########




//For 11111000000
while(ok(r)) r*=2;


//For 00000011111
while(!ok(r)) r*=2;