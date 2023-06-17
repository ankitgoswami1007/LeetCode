class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Map to store whether a number is present in the input array
        unordered_map<int, bool> umap;

        // Mark all numbers as present in the map
        for(auto& num : nums) {
            umap[num] = true;
        }

        // Iterate through the numbers
        // If a number has a predecessor (num-1), mark it as false in the map
        for(auto& num : nums) {
            if(umap.find(num - 1) != umap.end()) {
                umap[num] = false;
            }
        }

        int max_start_point = 0;
        int max_len = 0;

        // Iterate through the numbers
        // For each number that is the start of a sequence, calculate its length
        // Update the maximum length and starting point if necessary
        for(auto& num : nums) {
            if(umap[num] == true) {
                int temp_len = 1;
                int temp_start_pnt = num;

                // Calculate the length of the consecutive sequence
                while(umap.find(temp_start_pnt + temp_len) != umap.end()) {
                    temp_len++;
                }

                // Update the maximum length and starting point if the current sequence is longer
                if(temp_len > max_len) {
                    max_len = temp_len;
                    max_start_point = temp_start_pnt;
                }
            }
        }

        // Print the consecutive sequence with maximum length
        for(int i = 0 ; i < max_len ; i++) {
            cout << (max_start_point + i) << " ";
        }

        return max_len;
    }
};
