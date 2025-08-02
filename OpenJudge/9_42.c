#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET];
    int is_end;
} TrieNode;

// 创建新节点
TrieNode* createNode() {
    TrieNode* node  =  (TrieNode*)malloc(sizeof(TrieNode));
    //每个结点都有可能有26个孩子
    for(int i  =  0; i < ALPHABET; ++i) node->children[i]  =  NULL;
    node->is_end  =  0;
    return node;
}

// 插入
void insert(TrieNode* root, char* block) {
    TrieNode* p  =  root;
    for(int i  =  0; block[i]; ++i) {
        int idx  =  block[i] - 'a';
        //根据字母来索引孩子
        if(!p->children[idx]) {
            p->children[idx]  =  createNode();
        }
        p  =  p->children[idx];
    }
    p->is_end  =  1;
}

// 查找
int search(TrieNode* root, char* block) {
    TrieNode* p  =  root;
    for(int i  =  0; block[i]; ++i) {
        int idx  =  block[i] - 'a';
        if(!p->children[idx]) return 0;
        p  =  p->children[idx];
    }
    return p->is_end;
}

// 递归删除
int deleteWord(TrieNode* root, char* block, int depth) {
    if(!root) return 0;
    //单词已经结尾
    if(block[depth]  ==  '\0') {
        if(root->is_end) {
            root->is_end  =  0;
            // 检查是否可以删除此节点, 如果其他单词还要用这个结点, 就不能删除
            for(int i = 0;i<ALPHABET;++i) {
                if(root->children[i]) return 0;
            }
            return 1; //删
        } else {
            return 0;
        }
    }
    int idx  =  block[depth] - 'a';
    if(root->children[idx]) {
        if(deleteWord(root->children[idx], block, depth+1)) {
            free(root->children[idx]);
            root->children[idx]  =  NULL;
            // 删除后判断当前节点是否还能删除
            if(root->is_end) return 0;
            for(int i = 0;i<ALPHABET;++i) {
                if(root->children[i]) return 0;
            }
            return 1;
        }
    }
    return 0;
}

int main() {
    TrieNode* root  =  createNode();
    int op;
    char buf[105];
    while(scanf("%d %s", &op, buf)  ==  2) {
        if(op  ==  1) {
            insert(root, buf);
        } else if(op  ==  2) {
            deleteWord(root, buf, 0); // 删除
        } else if(op  ==  3) {
            printf("%s\n", search(root, buf) ? "True" : "False");
        }
    }
    return 0;
}