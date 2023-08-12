class Solution {
    public boolean containsDuplicate(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();

        for(int num : nums){
            map.put(num, map.getOrDefault(num, 0)+1);
        }
        for(Integer value: map.values()) {
           if(value >= 2) return true;
       }
    return false;
    }
}