/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    public int res = 0;
    public int recursion(TreeNode root) {
        if(root == null)
            return 0;

        int left = recursion(root.left);
        int right = recursion(root.right);

        if(left == Integer.MIN_VALUE || right == Integer.MIN_VALUE)
            return Integer.MIN_VALUE;
        
        int curr = root.val;

        if(root.left != null){
            TreeNode temp = root.left;
            while(temp.right != null)
                temp = temp.right;
            if(temp.val >= curr)
                return Integer.MIN_VALUE;
        }

        if(root.right != null){
            TreeNode temp = root.right;
            while(temp.left != null)
                temp = temp.left;
            if(temp.val <= curr)
                return Integer.MIN_VALUE;
        }   
        
        int value = curr + left + right;
        if(value > res)
            res = value;
        return value;
    }
    public int maxSumBST(TreeNode root) {
        recursion(root);
        return res;
    }
}
