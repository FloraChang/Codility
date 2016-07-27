/*
 A non-empty zero-indexed array A consisting of N numbers is given. The array is sorted in non-decreasing order. The absolute distinct count of this array is the number of distinct absolute values among the elements of the array.
 
 For example, consider array A such that:
 
 A[0] = -5
 A[1] = -3
 A[2] = -1
 A[3] =  0
 A[4] =  3
 A[5] =  6
 The absolute distinct count of this array is 5, because there are 5 distinct absolute values among the elements of this array, namely 0, 1, 3, 5 and 6.
 
 Write a function:
 
 int solution(vector<int> &A);
 that, given a non-empty zero-indexed array A consisting of N numbers, returns absolute distinct count of array A.
 
 For example, given array A such that:
 
 A[0] = -5
 A[1] = -3
 A[2] = -1
 A[3] =  0
 A[4] =  3
 A[5] =  6
 the function should return 5, as explained above.
 
 Assume that:
 
 N is an integer within the range [1..100,000];
 each element of array A is an integer within the range [−2,147,483,648..2,147,483,647];
 array A is sorted in non-decreasing order.
 Complexity:
 
 expected worst-case time complexity is O(N);
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
    
    for( int i = 0; i < (int)A.size(); i++ )
    {
        if( A[i] < 0 )
        {
            A[i] = A[i] * (-1); // make nagtive number to positive
        }
    }
    
    sort( A.begin(), A.end() ); // sort the vector
    // printVector(A);
    
    int previous = A[0];
    int distinct = 1;
    for( int i = 1; i <(int)A.size(); i++ )
    {
        if( A[i] != previous )
        {
            distinct++;
            previous = A[i];
        }
    }
    return distinct;
    
}

int main()
{
    int arrayA[6] = { -5,-3, -1, 0, 3, 6 };
    int arrayB[1] = { 0 };
    
    vector<int> A ( arrayA, arrayA + 6 );
    vector<int> B ( arrayB, arrayB + 1 );
    
    printVector(A);
    printVector(B);
    
    cout<< solution(A) << endl; // 5
    cout<< solution(B) << endl; // 1
}
