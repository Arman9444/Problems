class Solution {
public:
    int countBitsFlip(int a, int b) {
        int xorResult = a ^ b; // XOR identifies differing bits
        int count = 0;
        
        // Count set bits in XOR result
        while (xorResult > 0) {
            count += (xorResult & 1); // Increment if the last bit is 1
            xorResult >>= 1;          // Shift to process next bit
        }

        return count;
    }
};


// Naive apporach
class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        // Your logic here
        int count = 0;
        while(a>0 && b>0) {
            int bitA = a&1;
            int bitB = b&1;
            if(bitA != bitB) {
                count++;
            }
            
            a = a >> 1;
            b = b >> 1;
        }
        
        while(b>0) {
            if(b&1){
                count++;
            }
            
            b = b >> 1;
        }
        while(a>0) {
            if(a&1){
                count++;
            }
            
            a = a >> 1;
        }
        
        return count;
    }
};