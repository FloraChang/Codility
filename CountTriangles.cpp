/*
 A zero-indexed array A consisting of N integers is given. A triplet (P, Q, R) is triangular if it is possible to build a triangle with sides of lengths A[P], A[Q] and A[R]. In other words, triplet (P, Q, R) is triangular if 0 ≤ P < Q < R < N and:
 
 A[P] + A[Q] > A[R],
 A[Q] + A[R] > A[P],
 A[R] + A[P] > A[Q].
 For example, consider array A such that:
 
 A[0] = 10    A[1] = 2    A[2] = 5
 A[3] = 1     A[4] = 8    A[5] = 12
 There are four triangular triplets that can be constructed from elements of this array, namely (0, 2, 4), (0, 2, 5), (0, 4, 5), and (2, 4, 5).
 
 Write a function:
 
 int solution(vector<int> &A);
 that, given a zero-indexed array A consisting of N integers, returns the number of triangular triplets in this array.
 
 For example, given array A such that:
 
 A[0] = 10    A[1] = 2    A[2] = 5
 A[3] = 1     A[4] = 8    A[5] = 12
 the function should return 4, as explained above.
 
 Assume that:
 
 N is an integer within the range [0..1,000];
 each element of array A is an integer within the range [1..1,000,000,000].
 Complexity:
 
 expected worst-case time complexity is O(N2);
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
    
    int triangles = 0;
    int size = (int)A.size();
    
    if( size < 3 )
    {
        return 0;
    }
    
    sort( A.begin(), A.end() );
    // printVector(A);
    
    for( int x = 0; x < size -2 ; x ++ )
    {
        int z = x+2;
        
        for( int y = x+1; y < size -1; y ++ )
        {
            /* ------------------------------------------------------------------------
             Find the largest z, which can statisfy "A[x] + A[y] > A[z]". When y' = y+1,
             we know that y' can also satisfied A[x] + A[y'] > vaule: A[y'+1] ~ A[z].
             We can check from current z, instead of z = y' + 1.
             -------------------------------------------------------------------------- */
            while( z < size && (A[x] + A[y]) > A[z] )
            {
                z++;
            }

            triangles += ( z - (y+1) );
        }
    }
    
    return triangles;
}

int main()
{
    int arrayA[6] = { 10, 2, 5, 1, 8, 12 };
    int arrayB[5] = { 1, 1, 2, 2, 2 };
    int arrayC[1] = { 1 };
    
    vector<int> A ( arrayA, arrayA + 6 );
    vector<int> B ( arrayB, arrayB + 5 );
    vector<int> C ( arrayC, arrayC + 1 );
    
    printVector(A);
    //printVector(B);
    
    cout<< solution(A) << endl; // 4
    cout<< solution(B) << endl; // 7
    cout<< solution(C) << endl; // 0
}
