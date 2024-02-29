
#include <string>
class BST
{
	class TreeNode {

	public:
		int key;
		std::string value{};
		TreeNode* left{ nullptr }, * right{ nullptr };
		int N{0};

		TreeNode(int k, std::string val, int n = 1, TreeNode* l = nullptr, TreeNode* r = nullptr) :
			key{ k }, value{ val }, N{ n } , left{l}, right {r}
		{}
	};

	TreeNode *root{nullptr};

	TreeNode* put(TreeNode* node, int key, std::string val)
	{
		if (!node) return new TreeNode(key, val);

		if (key < node->key) return put(node->left, key, val);
		else if (key > node->key) return put(node->right, key, val);
		else node->value = val;

		node->N = node->left->N + node->right->N + 1;
	}

	std::string get(TreeNode* node, int key)
	{
		if (key < node->key) return get(node->left, key);
		else if (key > node->key) return get(node->right, key);
		else return node->value;
	}

	int size(TreeNode* node)
	{
		if (node == nullptr) return 0;
		else return node->N;
	}

	TreeNode* deleteMin(TreeNode* node)
	{
		if (!(node->left)) { auto ret = node->right; delete node; return ret; }
		node->left = deleteMin(node->left);

		node->N = size(node->left) + size(node->right) + 1;
	}

	TreeNode* deleteKey(TreeNode* node, int key)
	{
		if (node == nullptr) return nullptr;
		if (key < node->key) { auto ret = node->left; delete node; return ret;}
		else if (key > node->key) { auto ret = node->right; delete node; return ret; }
		else
		{
			if(node->right == nullptr) { auto ret = node->left; delete node; return ret; }
			else if(node->left == nullptr) { auto ret = node->right; delete node; return ret; }
			else
			{

				//:start Here 
			}
		}
	}
public:
	void put(int key, std::string val)
	{
		put(root, key, val);
	}

	std::string get(int key, std::string val)
	{
		return get(root, key);
	}

	int size()
	{
		return size(root);
	}

	void deleteMin()
	{
		if(root) root = deleteMin(root);
	}

	void deleteKey(int key)
	{
		if (root) root = deleteKey(root, key);
	}
};