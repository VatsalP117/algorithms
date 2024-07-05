double myPow(double a, int n) {
        double res = 1;
        while(n){
            if(n%2){
                //odd power
                res = res * a;
                //we can do res = (res*a) % p if we need a^n % MOD
                n--;
            }
            //even power to square base and half power
            a = a*a;
            //we can do a = (a*a) % p if we need a^n % MOD
            n = n/2;
        }
        return res;
}