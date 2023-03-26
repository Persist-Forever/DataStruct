#include <iostream>

#include "Tree.h"


using namespace std;

double t1(const double a, const double b)
{
	double c = a + b;
	this_thread::sleep_for(chrono::seconds(5));//假设t1函数是个复杂的计算过程，需要消耗3秒
	return c;
}

template<typename T>
void PrintVec(const vector<T>& vec)
{
	for (auto ch : vec) {
		cout << ch;
	}
	cout << endl;
}


int main() {
	Tree tree;
	std::shared_ptr<TreeNode> root = tree.BuildTree("ABC##D##E#F##");
	vector<char> vec;
	tree.PreTraversal(root, vec);
	PrintVec(vec);
	vec.clear();

	tree.PreTravel(root, vec);
	PrintVec(vec);
	vec.clear();

	tree.PreTravel3(root, vec);
	PrintVec(vec);
	vec.clear();

	tree.PostTraversal(root, vec);
	PrintVec(vec);
	vec.clear();

	tree.PostTravel(root, vec);
	PrintVec(vec);
	vec.clear();

	tree.PostTravel3(root, vec);
	PrintVec(vec);
	vec.clear();

	tree.InorderTraversal(root, vec);
	PrintVec(vec);
	vec.clear();

	tree.InorderTravel(root, vec);
	PrintVec(vec);
	vec.clear();

	tree.InorderTravel3(root, vec);
	PrintVec(vec);
	vec.clear();


	tree.LevelTraversal(root, vec);
	PrintVec(vec);
	vec.clear();

	return 0;
}