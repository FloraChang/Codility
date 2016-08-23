/*
 Write a function:
 
 int solution(vector<int> &A);
 that, given a non-empty zero-indexed array A of N integers, returns the minimal positive integer (greater than 0) that does not occur in A.
 
 For example, given:
 
 A[0] = 1
 A[1] = 3
 A[2] = 6
 A[3] = 4
 A[4] = 1
 A[5] = 2
 the function should return 5.
 
 Assume that:
 
 N is an integer within the range [1..100,000];
 each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
 Complexity:
 
 expected worst-case time complexity is O(N);
 expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
 Elements of input arrays can be modified.
 
 Copyright 2009–2016 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> &A) {

    int num;
    map<int,bool> table;
    map<int,bool> ::iterator it;
    
    for( int i = 0; i < A.size(); i++ )
    {
        num = A[i];
        if( num > 0 ) // ignore nagative numbers
        {
            table[num] = true;
        }
    }

    for( int i = 1; i <= table.size(); i++ ) // Note: the upperbound should be 'table.size()'
    {
        it = table.find(i);

        if( it == table.end() )
        {
            return i;
        }
    }

    return (int)table.size()+1;
}

int main()
{
    vector<int> A = { 1, 3, 6, 4, 1, 2 };
    vector<int> B = { 0 };
    
    cout<< solution( B ) << endl;
}
