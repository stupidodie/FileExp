//
// Created by tgr on 2020/11/13.
//

#ifndef FILEPACK_HUFFMAN_H
#define FILEPACK_HUFFMAN_H

#include<string>

typedef struct {
    unsigned char uch;    // 以8bits为单元的无符号字符
    unsigned long weight;    // 每类（以二进制编码区分）字符出现频度
} TmpNode;
// 哈夫曼树结点
typedef struct {
    unsigned char uch;    // 以8bits为单元的无符号字符
    unsigned long weight;    // 每类（以二进制编码区分）字符出现频度
    char *code;    // 字符对应的哈夫曼编码（动态分配存储空间）
    int parent, lchild, rchild;    // 定义双亲和左右孩子
} HufNode, *HufTree;

//inferface
//后面的两个参数为密码的位数和密码
void compressFile(const char *ifname, const char *ofname, int number, const std::string &password);

//
bool extract(const char *ifname, const char *ofname, const char *password);


void select(HufNode *huf_tree, unsigned int n, int *s1, int *s2);

void CreateTree(HufNode *huf_tree, unsigned int char_kinds, unsigned int node_num);

void HufCode(HufNode *huf_tree, unsigned char_kinds);

#endif //FILEPACK_HUFFMAN_H
