/*
 A company of dwarfs is travelling across the New Zealand. On reaching the Clutha River the dwarfs need to get across, but recent storms have washed away the bridge. Luckily, a small ferry, in the form of a square raft, is operating.
 
 The raft is square and has N rows of seats, numbered from 1 to N. Each row contains N seats, labeled with consecutive letters (A, B, C, etc.). Each seat is identified by a string composed of its row number followed by its column number; for example, "9C" denotes the third seat in the 9th row.
 
 The raft has already been loaded with barrels in some seat positions, and other seats are already occupied by dwarfs. Our company of dwarfs may only take the remaining unoccupied seats. The ferryman wants to accommodate as many dwarfs as possible, but the raft needs to be stable when making the crossing. That is, the following conditions must be satisfied:
 
 the front and back halves of the raft (in terms of the rows of seats) must each contain the same number of dwarfs;
 similarly, the left and right sides of the raft (in terms of the columns of seats) must each contain the same number of dwarfs.
 You do not have to worry about balancing the barrels; you can assume that their weights are negligible.
 
 For example, a raft of size N = 4 is shown in the following illustration:
 
 
 
 Barrels are marked as brown squares, and seats that are already occupied by dwarfs are labeled d.
 
 The positions of the barrels are given in string S. The occupied seat numbers are given in string T. The contents of the strings are separated by single spaces and may appear in any order. For example, in the diagram above, S = "1B 1C 4B 1D 2A" and T = "3B 2D".
 
 In this example, the ferryman can accommodate at most six more dwarfs, as indicated by the green squares in the following diagram:
 
 
 
 The raft is then balanced: both left and right halves have the same number of dwarfs (four), and both front and back halves have the same number of dwarfs (also four).
 
 Write a function:
 
 int solution(int N, string &S, string &T);
 that, given the size of the raft N and two strings S, T that describes the positions of barrels and occupied seats, respectively, returns the maximum number of dwarfs that can fit on the raft. If it is not possible to balance the raft with dwarfs, your function should return -1.
 
 For instance, given N = 4, S = "1B 1C 4B 1D 2A" and T = "3B 2D", your function should return 6, as explained above.
 
 Assume that:
 
 N is an even integer within the range [2..26];
 strings S, T consist of valid seat numbers, separated with spaces;
 each seat number can appear no more than once in the strings;
 no seat number can appear in both S and T simultaneously.
 
 In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.
 Copyright 2009–2016 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

int solution(int N, string &S, string &T) {
    
     /*
     A: left front
     B: left back
     C: right front
     D: right back 
     */
    
    // number of exsiting dwrafs
    int d_A = 0;
    int d_C = 0;
    int d_B = 0;
    int d_D = 0;
    
    // number of vacancies
    int v_A = N * N / 4;
    int v_C = N * N / 4;
    int v_B = N * N / 4;
    int v_D = N * N / 4;
    
    // Split string S
    char *position = strtok( const_cast<char*>(S.c_str()), " " );
    while( position != NULL )
    {
        int row = position[0] - '0' - 1; // 1->0, 2->1, ...
        int column = position[1] - 'A'; // A->0, B->1, ...
        
        if( row < N/2 )
        {
            if( column < N/2 )
            {
                v_A--;
            }
            else
            {
                v_B--;
            }
        }
        else
        {
            if( column < N/2 )
            {
                v_C--;
            }
            else
            {
                v_D--;
            }
        }
        
        position = strtok( NULL, " " );
    }
    
    // Split string T
    position = strtok( const_cast<char*>(T.c_str()), " " );
    while( position != NULL )
    {
        int row = position[0] - '0' - 1; // 1->0, 2->1, ...
        int column = position[1] - 'A'; // A->0, B->1, ...
        
        if( row < N/2 )
        {
            if( column < N/2 )
            {
                v_A--;
                d_A++;
            }
            else
            {
                v_B--;
                d_B++;
            }
        }
        else
        {
            if( column < N/2 )
            {
                v_C--;
                d_C++;
            }
            else
            {
                v_D--;
                d_D++;
            }
        }
        
        position = strtok( NULL, " " );
    }
    
    // Cannot balance, return -1
    if( v_A < d_D || v_D < d_A || v_B < d_C || v_C < d_B )
    {
        return -1;
    }
    
    // left front V.S right back
    int max1 = min( v_A + d_A, v_D + d_D );
    
    // left back V.S right front
    int max2 = min( v_C + d_C, v_B + d_B );
    //cout<< max1 << " " << max2 << endl;
    
    return 2 * (max1 + max2) - d_A - d_C - d_B - d_D;
}

int main()
{
    int N = 4;
    
    string S = "1B 1C 4B 1D 2A";
    string T = "3B 2D";
    
    string S1 = "1B 1A 2A";
    string T1 = "3C 4C";
    
    string S2 = "1B";
    string T2 = "1A";

    cout << solution( N, S, T ) << endl;
}
