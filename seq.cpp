#include<bits/stdc++.h>
#define se second
using namespace std;

             
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int r = 1000;
    int in_cir = 0;
    int tot = 10000000;
    for(int k=0;k<tot;k++){
        int x = rand()%(2*r-1)-r;
        int y = rand()%(2*r-1)-r;
        if(x*x + y*y <= r*r){
           in_cir++;
        }
    }
    //double pi = 4.0*((double)in_cir/tot);
    printf("%ld" , 4.0*(in_cir/tot));
    cout << pi << "\n";
    return 0;
}