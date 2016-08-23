'''
A non-empty zero-indexed array A consisting of N integers is given.

A triplet (X, Y, Z), such that 0 ≤ X < Y < Z < N, is called a double slice.

The sum of double slice (X, Y, Z) is the total of A[X + 1] + A[X + 2] + ... + A[Y − 1] + A[Y + 1] + A[Y + 2] + ... + A[Z − 1].

For example, array A such that:

    A[0] = 3
    A[1] = 2
    A[2] = 6
    A[3] = -1
    A[4] = 4
    A[5] = 5
    A[6] = -1
    A[7] = 2
contains the following example double slices:

double slice (0, 3, 6), sum is 2 + 6 + 4 + 5 = 17,
double slice (0, 3, 7), sum is 2 + 6 + 4 + 5 − 1 = 16,
double slice (3, 4, 5), sum is 0.
The goal is to find the maximal sum of any double slice.

Write a function:

def solution(A)
that, given a non-empty zero-indexed array A consisting of N integers, returns the maximal sum of any double slice.

For example, given:

    A[0] = 3
    A[1] = 2
    A[2] = 6
    A[3] = -1
    A[4] = 4
    A[5] = 5
    A[6] = -1
    A[7] = 2
the function should return 17, because no double slice of array A has a sum of greater than 17.

Assume that:

N is an integer within the range [3..100,000];
each element of array A is an integer within the range [−10,000..10,000].
Complexity:

expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.
Copyright 2009–2016 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.A non-empty zero-indexed array A consisting of N integers is given.

A triplet (X, Y, Z), such that 0 ≤ X < Y < Z < N, is called a double slice.

The sum of double slice (X, Y, Z) is the total of A[X + 1] + A[X + 2] + ... + A[Y − 1] + A[Y + 1] + A[Y + 2] + ... + A[Z − 1].

For example, array A such that:

    A[0] = 3
    A[1] = 2
    A[2] = 6
    A[3] = -1
    A[4] = 4
    A[5] = 5
    A[6] = -1
    A[7] = 2
contains the following example double slices:

double slice (0, 3, 6), sum is 2 + 6 + 4 + 5 = 17,
double slice (0, 3, 7), sum is 2 + 6 + 4 + 5 − 1 = 16,
double slice (3, 4, 5), sum is 0.
The goal is to find the maximal sum of any double slice.

Write a function:

def solution(A)
that, given a non-empty zero-indexed array A consisting of N integers, returns the maximal sum of any double slice.

For example, given:

    A[0] = 3
    A[1] = 2
    A[2] = 6
    A[3] = -1
    A[4] = 4
    A[5] = 5
    A[6] = -1
    A[7] = 2
the function should return 17, because no double slice of array A has a sum of greater than 17.

Assume that:

N is an integer within the range [3..100,000];
each element of array A is an integer within the range [−10,000..10,000].
Complexity:

expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.

Copyright 2009–2016 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
'''

def solution(A):
    max_sub_sum_left = [0] * len(A)
    max_sub_sum_right = [0] * len(A)
    '''
    Get max sub sum end at i position from left to right.
    Index i starts from 1 since A[0] cannot be the answer.
    '''
    max_end_here = 0
    for i in range( 1, len(A)-1 ):
        max_end_here = max( 0, max_end_here + A[i] )
        max_sub_sum_left[i] = max_end_here
    #print(max_sub_sum_left)

    '''
    Get max sub sum end at i position from right to left.
    Index i starts from len(A)-2 since A[len(A)-1] cannot be the answer.
    '''
    max_end_here = 0
    for i in range( len(A)-2, 0, -1 ):
        max_end_here = max( 0, max_end_here + A[i] )
        max_sub_sum_right[i] = max_end_here
    #print(max_sub_sum_right)

    '''Scan i-th position to get the max double slice'''
    max_double_slice = 0

    for idx in range( 1, len(A) -1 ) :
        #if ( max_sub_sum_left[idx-1] + max_sub_sum_right[idx+1] ) > max_double_slice:
            #print( "idx = ", idx, ", left = ", max_sub_sum_left[idx-1], ", right = ", max_sub_sum_right[idx+1] )
        max_double_slice = max( max_double_slice, max_sub_sum_left[idx-1] + max_sub_sum_right[idx+1] )

    return max_double_slice


list1 = [ 3, 2, 6, -1, 4, 5, -1, 2 ]
list2 = [ 0, 10, -5, -2, 0 ]
list3 = [-1, -1, -1, -1, -1 ] # the anwser of all negative array will be zero

sol = solution( list1 )
print(sol)
