/*
A zero-indexed array A consisting of N integers is given. An equilibrium index of this array is any integer P such that 0 ≤ P < N and the sum of elements of lower indices is equal to the sum of elements of higher indices, i.e.
A[0] + A[1] + ... + A[P−1] = A[P+1] + ... + A[N−2] + A[N−1].
Sum of zero elements is assumed to be equal to 0. This can happen if P = 0 or if P = N−1.

For example, consider the following array A consisting of N = 8 elements:

A[0] = -1
A[1] =  3
A[2] = -4
A[3] =  5
A[4] =  1
A[5] = -6
A[6] =  2
A[7] =  1
P = 1 is an equilibrium index of this array, because:

A[0] = −1 = A[2] + A[3] + A[4] + A[5] + A[6] + A[7]
P = 3 is an equilibrium index of this array, because:

A[0] + A[1] + A[2] = −2 = A[4] + A[5] + A[6] + A[7]
P = 7 is also an equilibrium index, because:

A[0] + A[1] + A[2] + A[3] + A[4] + A[5] + A[6] = 0
and there are no elements with indices greater than 7.

P = 8 is not an equilibrium index, because it does not fulfill the condition 0 ≤ P < N.

Write a function:

int solution(vector<int> &A);
that, given a zero-indexed array A consisting of N integers, returns any of its equilibrium indices. The function should return −1 if no equilibrium index exists.

For example, given array A shown above, the function may return 1, 3 or 7, as explained above.

Assume that:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
Complexity:

expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.

Copyright 2009–2016 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

#include <vector>
#include <iostream>
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

    long int leftSum = 0;
    long int rightSum = 0;
    long int sum = 0;
    
    // special case: no elements
    if( (int)A.size() == 0 )
    {
        return -1;
    }
    
    for( int i = 0; i < (int)A.size(); i++ )
    {
        sum += A[i];
    }
    
    // special case : P = 0
    if( sum == A[0] )
    {
        return 0;
    }

    for( int P = 1; P < (int)A.size(); P++ )
    {
        leftSum += A[P-1];
        rightSum = sum - leftSum - A[P];
        
        if( leftSum == rightSum )
        {
            return P;
        }
    }
    
    return -1;
}

int main()
{
    int arrayA[8] = { -1, 3, -4, 5, 1, -6, 2, 1 };
    int arrayB[2] = { -1, 0 };
    
    vector<int> A ( arrayA, arrayA + 8 );
    vector<int> B ( arrayB, arrayB + 2 );
    
    printVector(A);
    printVector(B);
    
    cout << solution( A ) << endl; // 1 or 3 or 7
    cout << solution( B ) << endl; // 0
}
