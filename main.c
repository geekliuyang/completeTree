#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countNodes(struct TreeNode* root) {
    int ldepth, rdepth;

    if(root == NULL){
        return 0;
    }

    ldepth = getDepth(root->left);
    rdepth = getDepth(root->right);

    if(ldepth == rdepth){
        return (1<<ldepth) + countNodes(root->right);
    }
    else{
        return (1<<rdepth) + countNodes(root->left);
    }
}

int getDepth(struct TreeNode* node) {
    int depth = 0;

    while(node){
        node = node->left;
        depth++;
    }

    return depth;
}
int main()
{
    int result;

    struct TreeNode* node1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node1->data = 1;
    node1->left = NULL;
    node1->right = NULL;

    struct TreeNode* node2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node2->data = 2;
    node2->left = NULL;
    node2->right = NULL;

    struct TreeNode* node3 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node3->data = 3;
    node3->left = NULL;
    node3->right = NULL;

    struct TreeNode* node4 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node4->data = 4;
    node4->left = NULL;
    node4->right = NULL;

    struct TreeNode* node5 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node5->data = 5;
    node5->left = NULL;
    node5->right = NULL;

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;

    result = countNodes(node1);

    printf("%d", result);
    return 0;
}
