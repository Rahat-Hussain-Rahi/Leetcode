// Finding a Unique Binary String Using Set (C++ Solution)

// Problem Statement
// Given an array of binary strings nums, return a binary string of length n that does not appear in nums. 
//If there are multiple answers, you may return any of them.   
// Intuition
// The problem provides n unique binary strings, each of length n. Since there are 2^𝑛 possible binary strings of length n, at least one binary string must exist that is not present in the given list.

// The initial idea is to store all given binary strings in a C++ Standard Template Library set so that we can quickly check whether a generated string already exists. Then we slightly modify one of the existing strings by flipping its bits and check if the new string is absent from the set. If it is not found, that string becomes our answer.

// This approach leverages the fast lookup property of a set.

// Approach
// Create a set of strings to store all binary strings from the input vector.
// Initialize a new string (newstr) using the first string in the input.
// Iterate through each index of the string.
// Flip the current bit:
// '0' becomes '1'
// '1' becomes '0'
// After flipping, check whether the new string exists in the set using find().
// If the string does not exist in the set, return it immediately.
// Otherwise, revert the bit and continue checking the next position.
// If no new string is found, return an empty string (though the problem guarantees a valid answer).
// This method uses the efficient search capability of a set to determine uniqueness.

// Complexity
// Time complexity:
// O(nlogn)

// Space complexity:
// O(n)
#include<set>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) 
    {
        set<string> str;
        for(string s:nums){
            str.insert(s);
        }
        string newstr=nums[0];
        for(int i=0;i<str.size();++i){
            newstr[i]=newstr[i]=='0'?'1':'0';
            if(str.find(newstr)==str.end()){
                return newstr;
            }
            newstr[i]=newstr[i]=='0'?'1':'0';
        }
        return "";
    }
};