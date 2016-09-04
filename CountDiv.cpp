/*
 Write a function:
 
 int solution(int A, int B, int K);
 that, given three integers A, B and K, returns the number of integers within the range [A..B] that are divisible by K, i.e.:
 
 { i : A ≤ i ≤ B, i mod K = 0 }
 For example, for A = 6, B = 11 and K = 2, your function should return 3, because there are three numbers divisible by 2 within the range [6..11], namely 6, 8 and 10.
 
 Assume that:
 
 A and B are integers within the range [0..2,000,000,000];
 K is an integer within the range [1..2,000,000,000];
 A ≤ B.
 Complexity:
 
 expected worst-case time complexity is O(1);
 expected worst-case space complexity is O(1).
 Copyright 2009–2016 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
 */

#include <iostream>
using namespace std;

int solution(int A, int B, int K) {
 
    if( A % K == 0 )
    {
        return ( B - A ) / K + 1;
    }
    else
    {
        return ( B - ( A - A % K ) ) / K;
    }
}

int main()
{
    cout << solution( 6, 11, 2 ) << endl; // 3
    
    cout << solution( 11, 14, 2 ) << endl; // 2
    
    cout << solution( 11, 345, 17 ) << endl; // 20

    cout << solution( 1, 1, 11 ) << endl; // 0

    return 1;
}
