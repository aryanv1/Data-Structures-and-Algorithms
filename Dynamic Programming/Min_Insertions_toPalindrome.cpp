#include <bits/stdc++.h> // bits/stdc++.h
using namespace std;

/*
    Given a string and need to find min insertions to make it palindrome
    Here we just need to find the longest palindromic subsequence
    and subtract its length from the total length of string
    Longest palindromic subsequence can be found by find LCS of
    given string and its reverse
    Time Complexity: O(n*n)
    Space Complexity: O(n*n)
*/

/*
    Similar question - Min inertions/deletion to make strings equal
    Here we first need to find LCS of both strings
    Here we delete char other than LCS first and then insert the missing chars
    Then number of deletions = len(s1) - len(LCS)
    Number of insertions = len(s2) - len(LCS)
    so total = len(s1) + len(s2) - 2*len(LCS) which will be the answer
    Time Complexity: O(n*m)
    Space Complexity: O(n*m)
*/

int main()
{

    return 0;
}