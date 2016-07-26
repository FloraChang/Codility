/*
 Solution to this task can be found at our blog.
 
 You are going to build a stone wall. The wall should be straight and N meters long, and its thickness should be constant; however, it should have different heights in different places. The height of the wall is specified by a zero-indexed array H of N positive integers. H[I] is the height of the wall from I to I+1 meters to the right of its left end. In particular, H[0] is the height of the wall's left end and H[N−1] is the height of the wall's right end.
 
 The wall should be built of cuboid stone blocks (that is, all sides of such blocks are rectangular). Your task is to compute the minimum number of blocks needed to build the wall.
 
 Write a function:
 
 int solution(vector<int> &H);
 that, given a zero-indexed array H of N positive integers specifying the height of the wall, returns the minimum number of blocks needed to build it.
 
 For example, given array H containing N = 9 integers:
 
 H[0] = 8    H[1] = 8    H[2] = 5
 H[3] = 7    H[4] = 9    H[5] = 8
 H[6] = 7    H[7] = 4    H[8] = 8
 the function should return 7. The figure shows one possible arrangement of seven blocks.
 
 
 
 Assume that:
 
 N is an integer within the range [1..100,000];
 each element of array H is an integer within the range [1..1,000,000,000].
 Complexity:
 
 expected worst-case time complexity is O(N);
 expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
 Elements of input arrays can be modified.
 
 Copyright 2009–2016 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
 */

#include <vector>
#include <iostream>
#include <stack>

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

int solution(vector<int> &H) {
    stack<int> stack;
    int stones = 0;
    
    for( int i = 0; i < (int)H.size(); i++ )
    {
        if( stack.empty() )
        {
            stack.push(H[i]);
            stones++;
        }
        else
        {
            if( stack.top() < H[i] )
            {
                stack.push( H[i] );
                stones++;
            }
            else if( stack.top() > H[i] )
            {
                while( !stack.empty() && stack.top() > H[i] )
                {
                    stack.pop();
                }
                
                // If stack.top() == H[i], it means we don't need an extra block.
                // Otherwise, we need one.

                if( stack.empty() || stack.top() < H[i] )
                {
                    stack.push( H[i] );
                    stones++;
                }
            }
        }
    } // end for
    
    return stones;
}

int main()
{
    int array1[9] = { 8, 8, 5, 7, 9, 8, 7, 4, 8 };
    int array2[9] = { 2, 5, 1, 4, 6, 7, 9, 10, 1 };
    vector<int> H1( array1, array1 + 9 );
    vector<int> H2( array2, array2 + 9 );
    //printVector(H1);
    
    cout <<  solution( H1 ) << " stones" << endl;
    cout <<  solution( H2 ) << " stones" << endl;
    return 1;
}
