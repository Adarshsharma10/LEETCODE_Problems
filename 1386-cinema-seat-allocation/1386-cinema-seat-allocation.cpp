class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // Map row number to bitmask of reserved seats among columns 2-9
        unordered_map<int, int> reserved;
        
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            // We only care about seats 2 to 9
            if (col >= 2 && col <= 9) {
                // Shift by col - 2 so column 2 corresponds to bit 0
                reserved[row] |= (1 << (col - 2));
            }
        }
        
        // Start assuming every row contributes 2 groups
        int totalGroups = (n - reserved.size()) * 2;
        
        // Check rows that have reserved seats
        for (const auto& [row, mask] : reserved) {
            bool leftPossible   = !(mask & 0b00001111); // seats 2, 3, 4, 5
            bool rightPossible  = !(mask & 0b11110000); // seats 6, 7, 8, 9
            bool middlePossible = !(mask & 0b00111100); // seats 4, 5, 6, 7
            
            if (leftPossible && rightPossible) {
                totalGroups += 2;
            } else if (leftPossible || rightPossible || middlePossible) {
                totalGroups += 1;
            }
        }
        
        return totalGroups;
    }
};