class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int i = 0;
        while (i < data.size()) {
            int first = data[i];
            
            // 1-byte character
            if ((first >> 7) == 0) {
                i++;
                continue;
            }
            
            // Count leading 1's to get byte length
            int n = 0;
            int mask = 1 << 7;
            while ((first & mask) && n <= 4) {
                n++;
                mask >>= 1;
            }
            
            // Invalid cases:
            // - n must be 2, 3, or 4
            // - if n == 1, it's a 0xxxxxxx but we already handled, so n>1 here actually
            if (n == 1 || n > 4) return false;
            
            // Check we have enough bytes left
            if (i + n > data.size()) return false;
            
            // Check continuation bytes
            for (int j = 1; j < n; j++) {
                int cont = data[i + j];
                if ((cont >> 6) != 0b10) return false;
            }
            
            i += n;
        }
        return true;
    }
};
