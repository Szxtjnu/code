import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.Queue;
import java.util.logging.Level;

import javax.swing.tree.TreeNode;

class Solution{
    public List<List<Integer>> zigzagLevelOrder(TreeNode root){
        List<List<Integer>> res = new ArrayList<>();
        Queue<TreeNode> q = new ArrayDeque<>();
        int idx = 0;
        if(root!=null){
            q.add(root);
        }
        while(!q.isEmpty()){
            int n = q.size();
            idx++;
            List<Integer> level = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                TreeNode n = q.poll();
                level.add(n.val);
                if(n.left != null){
                    q.add(n.left);
                }
                if(n.right != null){
                    q.add(n.right);
                }
            }
            if(idx%2 == 0){
                Collections.reverse(level);
                res.add(level);
            }else{
                res.add(level);
            }
        }
        return res;
    }
}