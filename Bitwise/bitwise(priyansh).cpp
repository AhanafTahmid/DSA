// Resource: https://youtu.be/LGrE0siZ-ZA
//bitwise Operators
//1. even or odd
    // x&1
    cout<< (5&1) <<endl;//prints 1, odd, compare binary 5 and binary 1, rest beocomes zero
    cout<< (6&1) <<endl;//prints 0, even

//2. Power of two
    // x & (x-1)
    cout<< (32 & (32-1)) <<endl;//prints 0, cause 32 is power two
    cout<< (5 & (5-1)) <<endl;//prints 4, non zero value

//3. Manipulating bits
    //check if kth bit is set
    // x & (1<<k)
    cout<< (4 & (1<<2)) <<endl;//prints 4, as 4th bit is set, works in 0 base index, right to left
    cout<< (4 & (1<<1)) <<endl;//prints 0, as 1 index is 0

    //Toggle the kth bit
    // x ^ (1<<k)
    cout<< (4 ^ (1<<2)) <<endl;//prints 0, toggle the 4th bit
    cout<< (4 ^ (1<<1)) <<endl;//prints 6, toggle the 2th bit, 100 ^ 010 -> 110

    //Set the kth bit
    // x | (1<<k)
    cout<< (4 | (1<<1)) <<endl;//prints 6, sets the 2nd bit 1

    //Unset the kth bit
    // x ~ (1<<k)
    cout<< (4 &  ~(1<<2)) <<endl;//prints 0
    cout<< (4 &  ~(1<<1)) <<endl;//prints 4

//4. Multiply or divide a number
    //Multiply
    // x << k
    cout<< (4 << 1) <<endl;//8
    cout<< (4 << 3) <<endl;//32 -> 4 * 8

    //Division
    // x >> k
    cout<< (4 >> 1) <<endl;//2
    cout<< (16 >> 1) <<endl;//8

//5. Find x % 2^k
    // x & ((1<<k)-1)
    cout<< (4 << 1) <<endl;//8

//6. Swap 2 numbers
    // x = x^y
    // y = x^y
    // x = x^y
    int t1 = 12; 
    int t2 = 112;
    cout<< t1 <<' '<<t2<<endl;//12 112
    t1 = t1 ^ t2;
    t2 = t1 ^ t2;
    t1 = t1 ^ t2;
    cout<< t1 <<' '<<t2<<endl;//112 12

//7. Toggle assignment(Finding out the the number)
    // x = a^b^x;

//8. important identities
    // a + b = (a^b) + 2 (a&b)
    // a + b = (a|b) + (a&b)

//9. Count set bits
    cout<< __builtin_popcount(4) <<endl;// 1
    cout<< __builtin_popcountll(4) <<endl;//1



//$$$$$$$$$$$$
//get the rightmost set bit
/* Get the xor of all array elements */
for (i = 1; i < n; i++)
    xor1 = xor1 ^ arr[i];

/* XOR the previous result with numbers 
    from 1 to n*/
for (i = 1; i <= n; i++)
    xor1 = xor1 ^ i;

/* Get the rightmost set bit in set_bit_no */
set_bit_no = xor1 & ~(xor1 - 1);