/*
 You are given integers K, M and a non-empty zero-indexed array A consisting of N integers. Every element of the array is not greater than M.
 
 You should divide this array into K blocks of consecutive elements. The size of the block is any integer between 0 and N. Every element of the array should belong to some block.
 
 The sum of the block from X to Y equals A[X] + A[X + 1] + ... + A[Y]. The sum of empty block equals 0.
 
 The large sum is the maximal sum of any block.
 
 For example, you are given integers K = 3, M = 5 and array A such that:
 
 A[0] = 2
 A[1] = 1
 A[2] = 5
 A[3] = 1
 A[4] = 2
 A[5] = 2
 A[6] = 2
 The array can be divided, for example, into the following blocks:
 
 [2, 1, 5, 1, 2, 2, 2], [], [] with a large sum of 15;
 [2], [1, 5, 1, 2], [2, 2] with a large sum of 9;
 [2, 1, 5], [], [1, 2, 2, 2] with a large sum of 8;
 [2, 1], [5, 1], [2, 2, 2] with a large sum of 6.
 The goal is to minimize the large sum. In the above example, 6 is the minimal large sum.
 
 Write a function:
 
 int solution(int K, int M, vector<int> &A);
 
 that, given integers K, M and a non-empty zero-indexed array A consisting of N integers, returns the minimal large sum.
 
 For example, given K = 3, M = 5 and array A such that:
 
 A[0] = 2
 A[1] = 1
 A[2] = 5
 A[3] = 1
 A[4] = 2
 A[5] = 2
 A[6] = 2
 the function should return 6, as explained above.
 
 Assume that:
 
 N and K are integers within the range [1..100,000];
 M is an integer within the range [0..10,000];
 each element of array A is an integer within the range [0..M].
 Complexity:
 
 expected worst-case time complexity is O(N*log(N+M));
 expected worst-case space complexity is O(1), beyond input storage (not counting the storage required for input arguments).
 Elements of input arrays can be modified.
 
 */

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

void printVector( vector<int> &A );

bool blocksEnough( vector<int> &A, int max, int K )
{
    int block = 1;
    int sum = 0;
    int size = (int)A.size();

    // check if the blocks are enough (less than or equal to K)
    for( int i = 0; i < size ; i++ )
    {
        if( sum + A[i] <= max )
        {
            sum += A[i];
        }
        else
        {
            // The sum in this block is larger than max, so add a new block to add A[i].
            // cout<< block << ":" << sum << endl;
            block++;
            sum = A[i];
        }
        
        // If number of blocks is larger than K, return false
        if( block > K )
        {
            return false;
        }
    }
    
    return true;
}

int solution(int K, int M, vector<int> &A)
{
    int max = 0;
    int min = 0;
    int size = (int)A.size();
    
    // get maximum, which is the upperbound
    vector<int>::iterator it;
    for( it = A.begin(); it != A.end(); it++ )
    {
        max += *it;
    }
    
    // get minimun value in the vector, which is also the lowerbound
    min = *max_element( A.begin(), A.end() );
    
    // handle special case
    if( K >= size )
    {
        return min;
    }
    else if ( K == 1 )
    {
        return max;
    }
    
    while( min < max )
    {
        int mid = ( min + max ) / 2;
        
        if( blocksEnough( A, mid, K ) )
        {
            max-=1;
        }
        else
        {
            min+=1;
        }
    
    }

    return min;
}

int main()
{
    int numbers[7] = { 2, 1, 5, 1, 2, 2, 2 };
    vector<int> A;
    
    for( int i = 0; i < 7; i++ )
    {
        A.push_back( numbers[i]) ;
    }
    
    printVector(A);
    
    int K = 3;
    int M = 5;
    
    int sol = solution( K, M, A);
    cout<<"MinMaxDivision = " << sol << endl;
}

void printVector( vector<int> &A )
{
    vector<int>::iterator it;
    for( it = A.begin(); it != A.end(); it++ )
    {
        cout << *it <<" ";
    }
    cout << endl;
}
