// Problem Statement
// Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.    
// Intuition
// When we have a sorted array, the middle element naturally becomes the root of a balanced BST because it divides the array into two roughly equal halves. The left half contains all smaller elements (perfect for left subtree) and the right half contains all larger elements (perfect for right subtree). This recursive property ensures the resulting tree is height-balanced.

// Approach
// Recursive Construction: Use divide-and-conquer approach
// Base Case: If left > right, return nullptr (no nodes to process)
// Find Middle: Calculate mid = left + (right - left)/2 to avoid overflow
// Create Root: Create new TreeNode with nums[mid] as value
// Build Subtrees:
// Recursively build left subtree from indices [left, mid-1]
// Recursively build right subtree from indices [mid+1, right]
// Return: Return the constructed root node
// Complexity
// Time complexity:
// O(n)
// Space complexity:
// O(logn)
// Code
//  Definition for a binary tree node.

#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
  int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    TreeNode* Construct(vector<int> num,int left,int right)
    {
        if(left>right) return nullptr;
        int mid=left+ (right-left)/2;
        TreeNode* newNode=new TreeNode(num[mid]);
        newNode->left=Construct(num,left,mid-1);
        newNode->right=Construct(num,mid+1,right);
        return newNode;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
       TreeNode* head=Construct(nums,0,nums.size()-1);
       return head;
        
    }
};