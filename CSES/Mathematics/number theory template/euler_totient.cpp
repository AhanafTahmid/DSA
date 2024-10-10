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