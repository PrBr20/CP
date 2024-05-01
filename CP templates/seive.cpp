//seive prime factorization storing the least common factors

#define MAX 1000000

int lpf[MAX];

void seve (){
    lpf[1] = 1;
    for(ll i=2; i<MAX; i++){
        if(lpf[i] == 0){
            lpf[i] = i;
            for (ll j=i*i; j<MAX; j+=i){
                if(lpf[j] == 0) lpf[j] = i;
            }
        }
    }
}

// time complexity :
// -> n+(n/2)+(n/3)+(n/some prime number) -> harmonic series -> nlogn 