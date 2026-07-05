/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void MakeSerialization(string &ans, TreeNode* root){
        if(!root) {
            ans += "N,";
            return ;
        }
        ans += to_string(root -> val) + ",";
        
        MakeSerialization(ans , root -> left);

        MakeSerialization(ans , root -> right);

        return ;
    }
    string serialize(TreeNode* root) {
        string ans = "";
       MakeSerialization(ans , root);
       return ans;
    }

    TreeNode* MakeDeserialization(vector<string>& nodes, int &i) {
        if (nodes[i] == "N") {
            i++;
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(nodes[i]));
        i++;

        root->left = MakeDeserialization(nodes, i);
        root->right = MakeDeserialization(nodes, i);

        return root;
    }
    TreeNode* deserialize(string s) {   
       vector<string> nodes;
        string temp = "";

        for (char ch : s) {
            if (ch == ',') {
                nodes.push_back(temp);
                temp = "";
            } else {
                temp += ch;
            }
        }
        int i = 0;
        return MakeDeserialization(nodes,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));