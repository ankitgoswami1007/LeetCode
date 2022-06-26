class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int res = 0;
        
   /*     for (int i = 0 ; i < 32 ; i++){
            
            bool x = false , y = false , z = false ;
            
            if(a & (1 << i)) x = true ;
            if(b & (1 << i)) y = true ;
            if(c & (1 << i)) z = true ;
            
            if(z == false){
                if(x == true && y == true) res += 2;
                else {
                    if(x == true || y == true) res += 1;
                }
            }
            else{
                if(x == false && y == false) res +=1;
            }
            
        } */
        int bit_a , bit_b , bit_c;
        
        while(a || b || c){
            
            bit_a = a&1;
            bit_b = b&1;
            bit_c = c&1;
            
            if((bit_a | bit_b) != bit_c){
                if(bit_a && bit_b) res += 2;
                else res += 1;
            }
            a = a>>1;
            b = b>>1;
            c = c>>1;
        }
        
        return res ;
    }
};