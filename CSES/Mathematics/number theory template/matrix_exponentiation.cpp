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

int main(){

    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}