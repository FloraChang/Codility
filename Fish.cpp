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

#include <vector>
#include <iostream>
using namespace std;

void printVector( vector<int> &A );

int solution(vector<int> &A, vector<int> &B)
{
    int i = 0; // index of fish
    
    if( (int)A.size() == 1 )
    {
        return 1;
    }
    
    while( i < ( (int)A.size() -1 ) )
    {
        if( B[i] == 1 && B[i+1] == 0 )
        {
            int fish = 0;
            
            if( A[i] > A[i+1] )
            {
                fish = i+1;
            }
            else
            {
                fish = i;
                i = i -1;
            }
            A.erase( A.begin()+fish );
            B.erase( B.begin()+fish );
            // cout << "fish "<< fish << " is eatten."<<endl;
            // printVector(A);
            // printVector(B);
        }
        else
        {
            i++;
        }
        
    } // end while
    
    return (int)A.size();
}

int main()
{
    int arrayA[5] = { 4, 3, 2, 1, 5 };
    int arrayB[5] = { 1, 1, 0, 0, 0 };
    
    vector<int> A ( arrayA, arrayA + 5 );
    vector<int> B ( arrayB, arrayB + 5 );
    
    printVector(A);
    printVector(B);
    
    int sol = solution( A, B );
    cout << "number of fish, which stay alive = " << sol << endl;
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
