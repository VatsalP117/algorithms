void sieve(){
     void sieve(){
        is_prime[0] = false;
        is_prime[1] = false;
        for(int i=2;i*i<=1e6;i++){
            if(is_prime[i]){
                for(int j=i*i;j<=1e6;j+=i){
                    is_prime[j] = false;
                }
            }
        }
    }
}