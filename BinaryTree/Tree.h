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
 *  构造数字符串前序遍历： A B C # # D # # E # F # #
 *  打印：
 *      前序： A B C D E F
 *      中序： C B D A E F
 *      后序： C D B F E A
 *		层次： A B E C D F
 * */

class Tree {
public:
	std::shared_ptr<TreeNode> BuildTree(std::string s);
	// 递归实现 前序 中序 后序 遍历
	void PreTraversal(std::shared_ptr<TreeNode> root, std::vector<char>& data);
	void InorderTraversal(std::shared_ptr<TreeNode> root, std::vector<char>& data);
	void PostTraversal(std::shared_ptr<TreeNode> root, std::vector<char>& data);
	// 层次遍历  --- 队列
	void LevelTraversal(std::shared_ptr<TreeNode> root, std::vector<char>& data);
	
	// 迭代的方式实现三种遍历  -- 栈
	// 前序遍历  中 L R
	void PreTravel(std::shared_ptr<TreeNode> root, std::vector<char>& data);
	// 后序遍历  L R 中   中 R L ---> 倒序 L R 中  后序遍历只要前序遍历稍微做一些处理后然后倒序就可以了
	void PostTravel(std::shared_ptr<TreeNode> root, std::vector<char>& data);
	// 中序遍历
	void InorderTravel(std::shared_ptr<TreeNode> root, std::vector<char>& data);
	
	// 三种遍历 迭代框架归一  设计思路：访问过未处理的需要，加入标记
	void InorderTravel3(std::shared_ptr<TreeNode> root, std::vector<char>& data);
	void PreTravel3(std::shared_ptr<TreeNode> root, std::vector<char>& data);
	void PostTravel3(std::shared_ptr<TreeNode> root, std::vector<char>& data);

private:
	std::shared_ptr<TreeNode> CreateTree(std::string s, int& index);
};