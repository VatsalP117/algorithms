const int N = 1e6+1;
//we need to list of divisors for all number from 1 to 1e6
vector<int> divisors[N]; //create list of divisors of each number
//time complexity of this is not N*N but actually NlogN
// how?
// for every number from 1 to N(1e6) we are iterating over its multiples
// for 1 => N multiples are there
// 2 => N/2 Multiples
// 3 => N/3 Multiples
// therefore total operations = N + N/2 + N/3 + ..
// = N (1 + 1/2 + 1/3 + ..)
// bracket ke andar its an Harmonic progressiona and HP are always BOUNDED by logN
// so TC = NlogN
void precompute(){
    for(int i=1;i<=1e6;i++){
        //mark all multiples j
        //therefore, add to the list of multiples of i, i as divisor there
        for(int j=i;j<=1e6;j+=i){
            divisors[j].push_back(i);
        }
    }
}