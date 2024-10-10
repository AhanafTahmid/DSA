#include <iostream>
using namespace std;


//Sample Code - My Way
//everything is working in bits/ binary not in decimal numbers
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



