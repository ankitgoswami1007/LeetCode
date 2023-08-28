class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string b = "balloon";

        unordered_map<char , int> umap;

        for(char t : text){
            if(t == 'b' ||t == 'a' ||t == 'l' ||t == 'l' ||t == 'o' ||t == 'o' ||t == 'n' )
            umap[t]++;
        }

        return min(umap['b'], min(umap['a'], min(umap['l']/2, min(umap['o']/2,umap['n']))));
    }
};