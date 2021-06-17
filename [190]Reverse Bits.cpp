//Reverse bits of a given 32 bits unsigned integer. 
//
// Note: 
//
// 
// Note that in some languages such as Java, there is no unsigned integer type. 
//In this case, both input and output will be given as a signed integer type. They
// should not affect your implementation, as the integer's internal binary represe
//ntation is the same, whether it is signed or unsigned. 
// In Java, the compiler represents the signed integers using 2's complement not
//ation. Therefore, in Example 2 above, the input represents the signed integer -3
// and the output represents the signed integer -1073741825. 
// 
//
// Follow up: 
//
// If this function is called many times, how would you optimize it? 
//
// 
// Example 1: 
//
// 
//Input: n = 00000010100101000001111010011100
//Output:    964176192 (00111001011110000010100101000000)
//Explanation: The input binary string 00000010100101000001111010011100 represen
//ts the unsigned integer 43261596, so return 964176192 which its binary represent
//ation is 00111001011110000010100101000000.
// 
//
// Example 2: 
//
// 
//Input: n = 11111111111111111111111111111101
//Output:   3221225471 (10111111111111111111111111111111)
//Explanation: The input binary string 11111111111111111111111111111101 represen
//ts the unsigned integer 4294967293, so return 3221225471 which its binary repres
//entation is 10111111111111111111111111111111.
// 
//
// 
// Constraints: 
//
// 
// The input must be a binary string of length 32 
// 
// Related Topics Bit Manipulation 
// 👍 1829 👎 588


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    uint32_t swapPosBits(uint32_t n, int p1, int p2)
    {
        int p1_bit = (n >> p1) & 1;
        int p2_bit = (n >> p2) & 1;

        if(p1_bit ^ p2_bit)
        {
            n ^= (1 << p1);
            n ^= (1 << p2);
        }

        return n;
    }
public:
    uint32_t reverseBits(uint32_t n)
    {
        int MAX_BITS = 32;
        for(int i = 0; i < MAX_BITS/2; i++)
            n = swapPosBits(n, i, MAX_BITS - 1 - i);
        return n;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
