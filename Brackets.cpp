/*
 
 Task description
 A string S consisting of N characters is considered to be properly nested if any of the following conditions is true:
 
 S is empty;
 S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
 S has the form "VW" where V and W are properly nested strings.
 For example, the string "{[()()]}" is properly nested but "([)()]" is not.
 
 Write a function:
 
 int solution(string &S);
 that, given a string S consisting of N characters, returns 1 if S is properly nested and 0 otherwise.
 
 For example, given S = "{[()()]}", the function should return 1 and given S = "([)()]", the function should return 0, as explained above.
 
 Assume that:
 
 N is an integer within the range [0..200,000];
 string S consists only of the following characters: "(", "{", "[", "]", "}" and/or ")".
 Complexity:
 
 expected worst-case time complexity is O(N);
 expected worst-case space complexity is O(N) (not counting the storage required for input arguments).
 
 Copyright 2009–2016 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
 
 */

#include <string>
#include <iostream>
#include <stack>

using namespace std;

char getLeft( char c )
{
    if( c == '}' )
    {
        return '{';
    }
    else if( c == ')')
    {
        return '(';
    }
    else if( c == ']' )
    {
        return '[';
    }
    else
    {
        return ' ';
    }
}

int solution(string &S)
{
    stack<char> stack;
    
    if( S.empty() )
    {
        return 1;
    }
    else if( (int)S.size() == 1 )
    {
        return 0;
    }

    char c;
    
    for( int i = 0; i < (int)S.size(); i++ )
    {
        c = S.at(i);
        if( c == '{' || c == '[' || c == '(' )
        {
            stack.push( c );
        }
        else
        {
            if( !stack.empty() && stack.top() == getLeft( c ) )
            {
                stack.pop();
            }
            else
            {
                return 0; // wrong bracket
            }
        }
    }
    
    if( !stack.empty() )
    {
        return 0; // right bracket is not enough
    }
    else
    {
        return 1;
    }
}

int main()
{
    string str1 = "{[()()]}";
    string str2 = "([)()]";
    string str3 = "{{{{";
    
    cout << solution( str1 ) <<endl;
    cout << solution( str2 ) <<endl;
    cout << solution( str3 ) <<endl;
}
