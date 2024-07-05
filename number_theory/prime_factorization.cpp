    void prime_fact(int num){
        for(int i=2;i*i<=num;i++){
            if(num%i==0){
                int cnt = 0;
                while(num%i==0){
                    cnt++;
                    num = num/i;
                }
                freq[i] += cnt;
            }
        }
        if(num>1) freq[num]++;
    }

    //TC = O(Sqrt(N))