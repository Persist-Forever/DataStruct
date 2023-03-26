#pragma once
#include <string>
#include <memory>
#include <vector>

struct TreeNode {
	TreeNode(char ch) : data(ch), leftNode(nullptr), rightNode(nullptr){}
	char data;
	std::shared_ptr<TreeNode> leftNode;
	std::shared_ptr<TreeNode> rightNode;
};

/**
 *
 *                    A
 *            B                E
 *      C          D                 F
 *  �������ַ���ǰ������� A B C # # D # # E # F # #
 *  ��ӡ��
 *      ǰ�� A B C D E F
 *      ���� C B D A E F
 *      ���� C D B F E A
 *		��Σ� A B E C D F
 * */

class Tree {
public:
	std::shared_ptr<TreeNode> BuildTree(std::string s);
	// �ݹ�ʵ�� ǰ�� ���� ���� ����
	void PreTraversal(std::shared_ptr<TreeNode> root, std::vector<char>& data);
	void InorderTraversal(std::shared_ptr<TreeNode> root, std::vector<char>& data);
	void PostTraversal(std::shared_ptr<TreeNode> root, std::vector<char>& data);
	// ��α���  --- ����
	void LevelTraversal(std::shared_ptr<TreeNode> root, std::vector<char>& data);
	
	// �����ķ�ʽʵ�����ֱ���  -- ջ
	// ǰ�����  �� L R
	void PreTravel(std::shared_ptr<TreeNode> root, std::vector<char>& data);
	// �������  L R ��   �� R L ---> ���� L R ��  �������ֻҪǰ�������΢��һЩ�����Ȼ����Ϳ�����
	void PostTravel(std::shared_ptr<TreeNode> root, std::vector<char>& data);
	// �������
	void InorderTravel(std::shared_ptr<TreeNode> root, std::vector<char>& data);
	
	// ���ֱ��� ������ܹ�һ  ���˼·�����ʹ�δ�������Ҫ��������
	void InorderTravel3(std::shared_ptr<TreeNode> root, std::vector<char>& data);
	void PreTravel3(std::shared_ptr<TreeNode> root, std::vector<char>& data);
	void PostTravel3(std::shared_ptr<TreeNode> root, std::vector<char>& data);

private:
	std::shared_ptr<TreeNode> CreateTree(std::string s, int& index);
};