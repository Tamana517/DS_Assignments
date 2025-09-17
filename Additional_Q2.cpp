/*
String Split Challenge
You are given a string consisting of lowercase English alphabets. Your task is to determine if
it's possible to split this string into three non-empty parts (substrings) where one of these
parts is a substring of both remaining parts
*/

//Time Complexity: O(n)
//Space Complexity: O(1)   // fixed 26 chars

#include <iostream>
#include <string>
using namespace std;

// function to check if split is possible
bool canSplit(string s) {
    int freq[26] = {0};  // frequency of 'a' to 'z'

    // count chars
    for (char c : s) {
        freq[c - 'a']++;
    }

    // check if any char appears 2 or more times
    for (int i = 0; i < 26; i++) {
        if (freq[i] >= 3) return true;
    }

    return false;  // not possible
}

int main() {
    string s;

    // input string
    cout << "Enter string: ";
    cin >> s;

    // need at least 3 chars
    if (s.length() < 3) {
        cout << "Not possible";
        return 0;
    }

    // check and output
    if (canSplit(s))
        cout << "Yes, can be split";
    else
        cout << "No, cannot be split";

    return 0;
}
