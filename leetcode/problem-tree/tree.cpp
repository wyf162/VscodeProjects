#include<iostream>
#include<vector>
#include<queue>
using namespace std;



template <typename T>
struct BinaryTreeNode
{
public:
	BinaryTreeNode(const T &data)//构造函数
		:_left(NULL)
		,_right(NULL)
		,_data(data)
	{}
public:
	BinaryTreeNode<T> * _left;//左子树
	BinaryTreeNode<T> * _right;//右子树
	T _data;//数据项
};

template <typename T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;//重命名struct结构
public:
	BinaryTree()//无参的构造函数
		:_root(NULL)
	{}

	BinaryTree(const T* a, size_t size, const T& invalid)//有参构造函数
		:_root(NULL)
	{
		size_t index = 0;
		_root = _CreatBinaryTree(a, size, invalid, index);
	}

	BinaryTree(const BinaryTree<T> & t)//拷贝构造
		:_root(NULL)
	{
		_root = _Copy(t._root);
	}

	BinaryTree<T>& operator=(BinaryTree<T> t)//赋值运算符的重载
	{
		if (this != &t)//防止自赋值
		{
			swap(_root, t._root);
		}
		return *this;
	}

	~BinaryTree()//析构函数
	{
		if (_root)
		{
			_Delete(_root);
		}
	}

	void PrevOrder()//前序遍历
	{
		_PrevOrder(_root);
		cout << "over"<<endl;
	}

	void InOrder()//中序遍历
	{
		_InOrder(_root);
		cout << "over" << endl;
	}

	void PostOrder()//后序遍历
	{
		_PostOrder(_root);
		cout << "over" << endl;
	}

	void LevelOredr()//层次遍历
	{
		_LevelOrder(_root);
		cout << "over" << endl;
	}

	size_t Size()//节点数
	{
		return _Size(_root);
	}

	size_t Depth()//深度
	{
		return _Depth(_root);
	}

	size_t LeafSize()//叶子节点数
	{
		return _LeafSize(_root);
	}

protected:
	//创建二叉树
	Node* _CreatBinaryTree(const T *a, size_t size, const T& invalid,size_t& index)
	{
		Node * cur = NULL;
		if (index < size&&a[index] != invalid)//不能越界
		{
			cur = new Node(a[index]);//开辟节点
			cur->_left = _CreatBinaryTree(a, size, invalid, ++index);//递归创建左子树
			cur->_right = _CreatBinaryTree(a, size, invalid, ++index);//递归创建右子树
		}
		return cur;
	}
	//复制二叉树
	Node* _Copy(Node * root)
	{
		Node * cur = NULL;
		if (root == NULL)
		{
			return NULL;
		}

		cur = new Node(root->_data);//创建该节点

		cur->_left = _Copy(root->_left);
		cur->_right = _Copy(root->_right);
		return cur;
	}
	//删除
	void _Delete(Node * &root)
	{
		if (root == NULL)
		{
			return;
		}
		if (root->_left == NULL && root->_right == NULL)//该节点没有左右孩子
		{
			delete root;//释放该节点
			root = NULL;
			return;
		}
		_Delete(root->_left);
		_Delete(root->_right);
	}
	//前序遍历：根节点--左子树--右子树
	void _PrevOrder(Node * root)
	{
		if (root == NULL)
		{
			return;
		}

		cout << root->_data << "->";
		_PrevOrder(root->_left);
		_PrevOrder(root->_right);
	}
	//中序遍历：左子树--根节点--右子树
	void _InOrder(Node * root)
	{
		
		if (root == NULL)
		{
			return;
		}
		
		_PrevOrder(root->_left);
		cout << root->_data << "->";
		_PrevOrder(root->_right);
	}
	//后序遍历：左子树--右子树--根节点
	void _PostOrder(Node * root)
	{
		if (root == NULL)
		{
			return;
		}

		_PrevOrder(root->_left);
		_PrevOrder(root->_right);
		cout << root->_data << "->";
	}
	//层次遍历
	void _LevelOrder(Node* root)
	{
		queue<Node*> q;
		if (root == NULL)
		{
			return;
		}
		q.push(root);
		while (!q.empty())
		{
			if (q.front()->_left != NULL)
			{
				q.push(q.front()->_left);
			}
			if (q.front()->_right != NULL)
			{
				q.push(q.front()->_right);
			}
			cout << q.front()->_data << "->";
			q.pop();
		}
	}
	//节点个数
	size_t _Size(Node * root)
	{
		if (root == NULL)
		{
			return 0;
		}
		return _Size(root->_left) + _Size(root->_right) + 1;//当左子树或者右子树不为空时，该节点有数据
	}
	//二叉树的深度
	size_t _Depth(Node * root)
	{
		if (root==NULL)
		{
			return 0;
		}
		size_t leftDepth = _Depth(root->_left);
		size_t rightDepth = _Depth(root->_right);
		/*if (leftDepth >= rightDepth)
		{
			return leftDepth + 1;
		}
		else
			return rightDepth + 1;*/
		return leftDepth > rightDepth?leftDepth + 1 : rightDepth+1;
	}
	//叶子节点个数
	size_t _LeafSize(Node * root)
	{
		size_t size = 0;
		if (root == NULL)
		{
			return size;
		}
		if (root->_left == NULL&&root->_right == NULL)
		{
			size++;
			return size;
		}
		
		return _LeafSize(root->_left)+_LeafSize(root->_right);
	}


private:
	Node * _root;//根节点
};


int main(){
	int array1[10] = { 1, 2, 3, '#', '#', 4, '#' , '#', 5, 6 };
	BinaryTree<int> b1(array1, 10, '#');
	cout << "前序遍历：";
	b1.PrevOrder();

}