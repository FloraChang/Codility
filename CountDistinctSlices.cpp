/*
 An integer M and a non-empty zero-indexed array A consisting of N non-negative integers are given. All integers in array A are less than or equal to M.
 
 A pair of integers (P, Q), such that 0 ≤ P ≤ Q < N, is called a slice of array A. The slice consists of the elements A[P], A[P + 1], ..., A[Q]. A distinct slice is a slice consisting of only unique numbers. That is, no individual number occurs more than once in the slice.
 
 For example, consider integer M = 6 and array A such that:
 
 A[0] = 3
 A[1] = 4
 A[2] = 5
 A[3] = 5
 A[4] = 2
 There are exactly nine distinct slices: (0, 0), (0, 1), (0, 2), (1, 1), (1, 2), (2, 2), (3, 3), (3, 4) and (4, 4).
 
 The goal is to calculate the number of distinct slices.
 
 Write a function:
 
 int solution(int M, vector<int> &A);
 that, given an integer M and a non-empty zero-indexed array A consisting of N integers, returns the number of distinct slices.
 
 If the number of distinct slices is greater than 1,000,000,000, the function should return 1,000,000,000.
 
 For example, given integer M = 6 and array A such that:
 
 A[0] = 3
 A[1] = 4
 A[2] = 5
 A[3] = 5
 A[4] = 2
 the function should return 9, as explained above.
 
 Assume that:
 
 N is an integer within the range [1..100,000];
 M is an integer within the range [0..100,000];
 each element of array A is an integer within the range [0..M].
 Complexity:
 
 expected worst-case time complexity is O(N);
 expected worst-case space complexity is O(M), beyond input storage (not counting the storage required for input arguments).
 Elements of input arrays can be modified.
 Copyright 2009–2016 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void resetTable( bool* table, int M )
{
    for( int i = 0; i <= M; i++ )
    {
        table[i] = false;
    }
}

int solution( int M, vector<int> &A) {
    bool *seen = new bool[ M + 1 ];
    
    int front = 0;
    int back = 0;
    int total = 0;
    
    resetTable( seen, M );
    
    while( front < A.size() && back < A.size() )
    {
        // move front foward as far as posiible
        while( front < A.size() && seen[ A[front] ] == false )
        {
            seen[ A[front] ] = true;
            
            // Add the number of toatal sequecnes:
            // (A[back], A[front]), (A[back+1], A[front]), (A[back+2], A[front]) ..., (A[front], A[front])
            total+= front- back + 1;
            
            if( total >= 1000000000 )
            {
                return 1000000000;
            }
            
            // cout<< "+" << front- back + 1 << endl;
            front++;
        }
        
        // move back to the dupicate value
        while( front < A.size() && back < A.size() && A[back] != A[front] )
        {
            seen[ A[back] ] = false; // reset
            back++;
        }
        
        // make back to next number
        seen[ A[back] ] = false;
        back++;
        
    }
    return total;
}

int main(){
    int M = 6;
    vector<int> A = { 1, 2, 3, 5, 6, 2, 3, 5, 4, 4, 5, 6 };
    vector<int> B = { 0, 0, 1  };
    
    cout << solution( M, A ) << endl; // 38
    cout << solution( 1, B ) << endl; // 2


    return 0;
}
