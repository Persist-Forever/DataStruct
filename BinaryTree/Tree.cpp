#include "Tree.h"
#include <queue>
#include <stack>
#include <algorithm>

std::shared_ptr<TreeNode> Tree::CreateTree(std::string s, int& index)
{
	if (index >= s.length()) {
		return nullptr;
	}
	if (s.at(index) == '#') {
		index++;
		return nullptr;
	}
	std::shared_ptr<TreeNode> node = std::make_shared<TreeNode>(s.at(index));
	index++;
	node->leftNode = CreateTree(s, index);
	node->rightNode = CreateTree(s, index);
	return node;
}

std::shared_ptr<TreeNode> Tree::BuildTree(std::string s)
{
	int index = 0;
	return CreateTree(s, index);
}

void Tree::PreTraversal(std::shared_ptr<TreeNode> root, std::vector<char>& data)
{
	if (root == nullptr) {
		return;
	}
	data.push_back(root->data);
	PreTraversal(root->leftNode, data);
	PreTraversal(root->rightNode, data);
}

void Tree::InorderTraversal(std::shared_ptr<TreeNode> root, std::vector<char>& data)
{
	if (root == nullptr) {
		return;
	}
	InorderTraversal(root->leftNode, data);
	data.push_back(root->data);
	InorderTraversal(root->rightNode, data);
}


void Tree::PostTraversal(std::shared_ptr<TreeNode> root, std::vector<char>& data)
{
	if (root == nullptr) {
		return;
	}
	PostTraversal(root->leftNode, data);
	PostTraversal(root->rightNode, data);
	data.push_back(root->data);
}

void Tree::LevelTraversal(std::shared_ptr<TreeNode> root, std::vector<char>& data)
{
	if (root == nullptr) {
		return;
	}
	std::queue<std::shared_ptr<TreeNode>> que;
	que.push(root);	
	while (!que.empty()) {
		auto& node = que.front();
		if (node == nullptr) {
			que.pop();
			continue;
		}
		data.push_back(node->data);
		que.push(node->leftNode);
		que.push(node->rightNode);
		que.pop();
	}
}

void Tree::PreTravel(std::shared_ptr<TreeNode> root, std::vector<char>& data)
{
	if (root == nullptr) {
		return;
	}
	std::stack<std::shared_ptr<TreeNode>> st;
	st.push(root);
	while (!st.empty()) {
		auto node = st.top();
		st.pop();
		if (node == nullptr) {
			continue;
		}
		data.push_back(node->data);
		st.push(node->rightNode);
		st.push(node->leftNode);
	}
}

void Tree::PostTravel(std::shared_ptr<TreeNode> root, std::vector<char>& data)
{
	if (root == nullptr) {
		return;
	}
	std::stack<std::shared_ptr<TreeNode>> st;
	st.push(root);
	while (!st.empty()) {
		auto node = st.top();
		st.pop();
		if (node == nullptr) {
			continue;
		}
		data.push_back(node->data);
		st.push(node->leftNode);
		st.push(node->rightNode);
	}
	reverse(data.begin(), data.end());
}

void Tree::InorderTravel(std::shared_ptr<TreeNode> root, std::vector<char>& data)
{
	if (root == nullptr) {
		return;
	}
	std::stack<std::shared_ptr<TreeNode>> st;
	std::shared_ptr<TreeNode> node = root;
	while (node != nullptr || !st.empty()) {
		if (node != nullptr) {
			st.push(node);
			node = node->leftNode;
		} else {
			node = st.top();
			st.pop();
			data.push_back(node->data);
			node = node->rightNode;
		}
	}
}

void Tree::InorderTravel3(std::shared_ptr<TreeNode> root, std::vector<char>& data)
{
	if (root == nullptr) {
		return;
	}
	std::stack<std::shared_ptr<TreeNode>> st;
	st.push(root);
	while (!st.empty()) {
		auto node = st.top();
		st.pop();
		if (node != nullptr) {
			if (node->rightNode) {
				st.push(node->rightNode);
			}
			st.push(node);  // 添加中间节点
			st.push(nullptr);  // 中间节点访问过没处理，添加标记
			if (node->leftNode) {
				st.push(node->leftNode);
			}
		} else {
			node = st.top();
			st.pop();
			data.push_back(node->data);
		}
	}
}

void Tree::PreTravel3(std::shared_ptr<TreeNode> root, std::vector<char>& data)
{
	if (root == nullptr) {
		return;
	}
	std::stack<std::shared_ptr<TreeNode>> st;
	st.push(root);
	while (!st.empty()) {
		auto node = st.top();
		st.pop();
		if (node != nullptr) {
			if (node->rightNode) {
				st.push(node->rightNode);
			}
			if (node->leftNode) {
				st.push(node->leftNode);
			}
			st.push(node);
			st.push(nullptr);
		}
		else {
			node = st.top();
			st.pop();
			data.push_back(node->data);
		}
	}
}

void Tree::PostTravel3(std::shared_ptr<TreeNode> root, std::vector<char>& data)
{
	if (root == nullptr) {
		return;
	}
	std::stack<std::shared_ptr<TreeNode>> st;
	st.push(root);
	while (!st.empty()) {
		auto node = st.top();
		st.pop();
		if (node != nullptr) {
			st.push(node);
			st.push(nullptr);
			if (node->rightNode) {
				st.push(node->rightNode);
			}
			if (node->leftNode) {
				st.push(node->leftNode);
			}
		}
		else {
			node = st.top();
			st.pop();
			data.push_back(node->data);
		}
	}
}