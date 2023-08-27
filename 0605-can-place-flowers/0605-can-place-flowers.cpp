class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        if(n == 0) return true;
        int l = flowerbed.size();
        if(l == 1 && flowerbed[0] == 0 && n == 1) return true;
        int count = 0 ;
        for(int i = 0 ; i < l; i++){
            if(flowerbed[i] == 1) continue;
            if(i == 0 && i != l-1  && flowerbed[i+1] == 0 && flowerbed[i] == 0){
                flowerbed[i] = 1;
                count++;
                if(count == n) return true;
            }
            else if(i != 0 && i != l-1 && flowerbed[i-1] == 0  && flowerbed[i+1] == 0 && flowerbed[i] == 0){
                flowerbed[i] = 1;
                count++;
                if(count == n) return true;
            }
            else if(i == l-1 && flowerbed[i-1] == 0 && flowerbed[i] == 0){
                flowerbed[i] = 1;
                count++;
                if(count == n) return true;
            }

        }
        if(count == n) return true;
        return false ;
        
    }
};