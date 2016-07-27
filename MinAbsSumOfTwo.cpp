/*
 Let A be a non-empty zero-indexed array consisting of N integers.
 
 The abs sum of two for a pair of indices (P, Q) is the absolute value |A[P] + A[Q]|, for 0 ≤ P ≤ Q < N.
 
 For example, the following array A:
 
 A[0] =  1
 A[1] =  4
 A[2] = -3
 has pairs of indices (0, 0), (0, 1), (0, 2), (1, 1), (1, 2), (2, 2).
 The abs sum of two for the pair (0, 0) is A[0] + A[0] = |1 + 1| = 2.
 The abs sum of two for the pair (0, 1) is A[0] + A[1] = |1 + 4| = 5.
 The abs sum of two for the pair (0, 2) is A[0] + A[2] = |1 + (−3)| = 2.
 The abs sum of two for the pair (1, 1) is A[1] + A[1] = |4 + 4| = 8.
 The abs sum of two for the pair (1, 2) is A[1] + A[2] = |4 + (−3)| = 1.
 The abs sum of two for the pair (2, 2) is A[2] + A[2] = |(−3) + (−3)| = 6.
 Write a function:
 
 int solution(vector<int> &A);
 that, given a non-empty zero-indexed array A consisting of N integers, returns the minimal abs sum of two for any pair of indices in this array.
 
 For example, given the following array A:
 
 A[0] =  1
 A[1] =  4
 A[2] = -3
 the function should return 1, as explained above.
 
 Given array A:
 
 A[0] = -8
 A[1] =  4
 A[2] =  5
 A[3] =-10
 A[4] =  3
 the function should return |(−8) + 5| = 3.
 
 Assume that:
 
 N is an integer within the range [1..100,000];
 each element of array A is an integer within the range [−1,000,000,000..1,000,000,000].
 Complexity:
 
 expected worst-case time complexity is O(N*log(N));
 expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
 Elements of input arrays can be modified.
 
 Copyright 2009–2016 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector( vector<int> &A )
{
    vector<int>::iterator it;
    for( it = A.begin(); it != A.end(); it++ )
    {
        cout << *it <<" ";
    }
    cout << endl;
}

int solution(vector<int> &A) {
    
    int size = (int)A.size();
    
    if( size == 1 )
    {
        return abs( A[0]*2 );
    }
    
    sort( A.begin(), A.end() );
    // printVector(A);
    
    int front = 0;
    int end = size - 1;
    int min = abs(A[front] + A[end]);
    
    while( front <= end )
    {
        int sum = abs( A[front] + A[end] );
        if( sum < min )
        {
            min = sum;
        }
        
        if( abs(A[front]) > abs(A[end]) )
        {
            front++;
        }
        else
        {
            end--;
        }
    }
    
    return min;
}

int main()
{
    int arrayA[3] = { 1, 4, -3 };
    int arrayB[5] = { -8, 4, 5, -10, 3 };
    int arrayC[1] = { 1 };
    
    vector<int> A ( arrayA, arrayA + 3 );
    vector<int> B ( arrayB, arrayB + 5 );
    vector<int> C ( arrayC, arrayC + 1 );
    
    printVector(A);
    printVector(B);
    
    cout<< solution(A) << endl; // 1
    cout<< solution(B) << endl; // 3
    cout<< solution(C) << endl; // 2
}
