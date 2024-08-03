/*
树的特点：
1.每个结点有零个或多个子节点
2.每个子节点只有一个父节点
3.根节点是没有前驱的结点
（前驱就是它的上次层的结点）
4.除了根节点，树可以被分为多个子树
*/
/*
节点的度：结点含有子树的个数
树的度：哪个结点的度最大，那么这个树的结点的度就和这个结点的度相同
叶结点：最底层的结点（度为0）
分支结点：不在最底层（度不为0）
孩子节点：就是这个结点的下面一层的结点
双亲结点：就是一个结点的上面一层
兄弟节点：这俩节点的上面一层是一个结点
祖先节点：从这个结点开始向上到根节点的全部结点
子孙结点：某节点的子树中的全部结点
结点的层次，从根节点开始一层层...
树的高度：树中结点的最大层次
路径：从根节点到某一结点
路径长度：路径经过的边的个数
*/
/*
二叉树：每个结点最多有两个子树
Note：
（1）任何树都可以转换成二叉树
（2）二叉树的结点个数可以是0
（3）二叉树的度为2
分类：
（1）满二叉树：叶子节点在最后一层，其他结点的度都为2
（2）完全二叉树：不管最深的那一层，完全二叉树就是满二叉树；最后一层的结点都靠拢在左边
note：完全二叉树和满二叉树的编号对应位置相同（从上到下，从左到右编号）
*/
/*
二叉树的数学性质：
1.第n层，至多有2^(n-1)个结点
2.高度为h，至多有2^h-1个结点
3.有n2个结点的度为2，则终端节点数为n2+1
4.节点数为n，则完全二叉树的深度log2(n)
5.对完全二叉树按照从上到下从左到右的顺序编号：
则编号为i的结点的双亲结点的编号为i/2，左孩子为2i，右孩子为2i+1
*/
/*
森林：多棵树构成它
*/
/*
树的遍历：
基本操作为 遍历根节点，左子树，右子树
1.前序遍历：先根节点，再左子树，后右子树
2.后序遍历：先左子树，再右子树，最后根节点
3.中序遍历：先左子树，后根节点，最后右节点
4.层序遍历
Note:
前序/中序/后序遍历的序列只要知其二，就可以唯一确定一颗二叉树
*/
/*
How to convert a tree into a binary tree?
1.Root of binary tree = Root of general tree
2.Left child of node in binary tree = Leftmost child of the node in general tree
3.Right child of node in binary tree = Right sibling of the node in general tree

How to convert a forest into a binary tree?
先把所有树变成二叉树，在把各个二叉树的根节点从左上到右下连起来
*/
/*
前序遍历树 就是 前序遍历其二叉树
后续遍历树 就是 中序遍历二叉树
前序遍历森林就是 前序遍历其二叉树
后续遍历森林 就是中序遍历其二叉树
*/
/*
二叉树的存储结构：
（1）：顺序存储结构：将二叉树按照满二叉树编号，用一维数组存储，数组index即为结点编号，数组数据为结点数据
（2）二叉链表：对于每个结点，数数据域存储数据，左指针域存储左孩子结点，右指针域存储右孩子结点。
*/
//二叉链表的一个结点
#include<iostream>
using namespace std;
template<typename T>struct BiNode
{
	T data;
	BiNode<T>* lchild;
	BiNode<T>* rchild;
};

template<class T>class BiTree {
private:
	//一个指针的引用
	void Create(BiNode<T>*& R, T data[], int i);
	void Release(BiNode<T>* R);
public:
	BiNode<T>* root;
	BiTree(T data[]);
	void PreOrder(BiNode<T>* R);
	~BiTree();
};
template<class T>
void BiTree<T>::Create(BiNode<T>*& R, T data[], int i) {
	if (data[i - 1] == 0) {
		R = nullptr;
		return;
	}
	R = new Node<T>;
	R->data = data[i - 1];
	R->lchild = R->rchild = NULL;
	Create(R->lchild, data, 2 * i);
	Create(R->rchild, data, 2 * i + 1);
}
template<class T> BiTree<T>::BiTree(T data[]) {
	Create(root, data, 1);
}

template<class T>
void BiTree<T>::PreOrder(BiNode<T>* R) {
	if (R != NULL) {
		cout << R->data;
		PreOrder(R->lchild);
		PreOrder(R->rchild);
	}
}

//析构函数释放结点时，先释放其左右子树，再释放该节点。
template<class T>
void BiTree<T>::Release(BiNode<T>* R) {
	if (R != NULL) {
		Release(R->lchild);
		Release(R->rchild);
		delete R;
	}
}
template<class T> BiTree<T>::~BiTree() {
	Release(root);
}

// 测试程序
int main() {
	// 使用0表示空节点
	int data[] = { 1, 2, 3, 4, 5, 0, 7 };
	BiTree<int> tree(data);

	cout << "PreOrder Traversal: ";
	tree.PreOrder(tree.root);
	cout << endl;

	return 0;
}