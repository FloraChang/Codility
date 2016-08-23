fibo_table = [ 1, 1 ] # initial value

def build_fibo( num ):
    for i in range( 2, num+1 ):
        fibo_table.append( fibo_table[i-1] + fibo_table[i-2] )
        #print(fibo_table[i], end=' ')

def solution(A, B):
    max_element = max(A)
    #print( max_element )
    build_fibo( max_element )

    result = []
    for i in range( 0, len(A) ):
        answer = fibo_table[A[i]] % pow( 2, B[i] )
        result.append( answer )

    return result

A = [ 4, 4, 5, 5, 1 ]
B = [ 3, 2, 4, 3, 1 ]

result = solution( A, B )

for num in result:
    print(num, end=' ')
