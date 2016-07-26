/*
 You are given N counters, initially set to 0, and you have two possible operations on them:
 
 increase(X) − counter X is increased by 1,
 max counter − all counters are set to the maximum value of any counter.
 A non-empty zero-indexed array A of M integers is given. This array represents consecutive operations:
 
 if A[K] = X, such that 1 ≤ X ≤ N, then operation K is increase(X),
 if A[K] = N + 1 then operation K is max counter.
 For example, given integer N = 5 and array A such that:
 
 A[0] = 3
 A[1] = 4
 A[2] = 4
 A[3] = 6
 A[4] = 1
 A[5] = 4
 A[6] = 4
 the values of the counters after each consecutive operation will be:
 
 (0, 0, 1, 0, 0)
 (0, 0, 1, 1, 0)
 (0, 0, 1, 2, 0)
 (2, 2, 2, 2, 2)
 (3, 2, 2, 2, 2)
 (3, 2, 2, 3, 2)
 (3, 2, 2, 4, 2)
 The goal is to calculate the value of every counter after all operations.
 
 Write a function:
 
 vector<int> solution(int N, vector<int> &A);
 that, given an integer N and a non-empty zero-indexed array A consisting of M integers, returns a sequence of integers representing the values of the counters.
 
 The sequence should be returned as:
 
 a structure Results (in C), or
 a vector of integers (in C++), or
 a record Results (in Pascal), or
 an array of integers (in any other programming language).
 For example, given:
 
 A[0] = 3
 A[1] = 4
 A[2] = 4
 A[3] = 6
 A[4] = 1
 A[5] = 4
 A[6] = 4
 the function should return [3, 2, 2, 4, 2], as explained above.
 
 Assume that:
 
 N and M are integers within the range [1..100,000];
 each element of array A is an integer within the range [1..N + 1].
 Complexity:
 
 expected worst-case time complexity is O(N+M);
 expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
 Elements of input arrays can be modified.
 
 Copyright 2009–2016 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

#include <iostream>
#include <vector>

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

void setCounters( vector<int> &C, int N, int num )
{
    for( int i = 0; i < N; i++ )
    {
        C[i] = num;
    }
}
vector<int> solution(int N, vector<int> &A) {
    
    vector<int> counters;
    int maximum = 0;
    int current_max = 0;

    for( int i = 0; i < N; i++ )
    {
        counters.push_back( 0 );
    }
    
    for( int i = 0; i < (int)A.size(); i++ )
    {
        if( A[i] == N+1 )
        {
            maximum = current_max;
        }
        else
        {
            int idx = A[i] - 1;
            // Compare value of counter with the maximum.
            // If it is less than maximum, we should add it to maximum first then increase one,
            // Otherwise, just increase one on the counter.
            counters[idx] = ( maximum > counters[idx] ) ? maximum+1 : counters[idx]+1;
            
            // Maintain current maximum
            current_max = max( current_max, counters[idx] );
        }
    } // end for
    
    for( int i = 0; i < N; i++ )
    {
        counters[i] = max( counters[i], maximum );
    }

    return counters;
}

int main()
{
    int array1[7] = { 3, 4, 4, 6, 1, 4, 4 };
    vector<int> A( array1, array1 + 7 );
    printVector(A);
    
    vector<int> C;
    C = solution( 5, A );
    printVector(C); // 3 2 2 4 2

    return 1;
}
