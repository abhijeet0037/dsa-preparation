/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL)
            return head;
            
        Node* curr = head;
        while (curr != NULL) {
            if (curr->child != NULL) {

                Node* next = curr->next;
                Node* child = flatten(curr->child);

                curr->next = child;
                child->prev = curr;
                curr->child = NULL;

                Node* temp = child;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = next;

                if (next != NULL)
                    next->prev = temp;
            }
            curr = curr->next;
        }
        return head;
    }
};