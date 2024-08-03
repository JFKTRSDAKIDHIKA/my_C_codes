/*
�����ص㣺
1.ÿ���������������ӽڵ�
2.ÿ���ӽڵ�ֻ��һ�����ڵ�
3.���ڵ���û��ǰ���Ľ��
��ǰ�����������ϴβ�Ľ�㣩
4.���˸��ڵ㣬�����Ա���Ϊ�������
*/
/*
�ڵ�Ķȣ���㺬�������ĸ���
���Ķȣ��ĸ����Ķ������ô������Ľ��ĶȾͺ�������Ķ���ͬ
Ҷ��㣺��ײ�Ľ�㣨��Ϊ0��
��֧��㣺������ײ㣨�Ȳ�Ϊ0��
���ӽڵ㣺���������������һ��Ľ��
˫�׽�㣺����һ����������һ��
�ֵܽڵ㣺�����ڵ������һ����һ�����
���Ƚڵ㣺�������㿪ʼ���ϵ����ڵ��ȫ�����
�����㣺ĳ�ڵ�������е�ȫ�����
���Ĳ�Σ��Ӹ��ڵ㿪ʼһ���...
���ĸ߶ȣ����н��������
·�����Ӹ��ڵ㵽ĳһ���
·�����ȣ�·�������ıߵĸ���
*/
/*
��������ÿ������������������
Note��
��1���κ���������ת���ɶ�����
��2���������Ľ�����������0
��3���������Ķ�Ϊ2
���ࣺ
��1������������Ҷ�ӽڵ������һ�㣬�������Ķȶ�Ϊ2
��2����ȫ�������������������һ�㣬��ȫ�����������������������һ��Ľ�㶼��£�����
note����ȫ�����������������ı�Ŷ�Ӧλ����ͬ�����ϵ��£������ұ�ţ�
*/
/*
����������ѧ���ʣ�
1.��n�㣬������2^(n-1)�����
2.�߶�Ϊh��������2^h-1�����
3.��n2�����Ķ�Ϊ2�����ն˽ڵ���Ϊn2+1
4.�ڵ���Ϊn������ȫ�����������log2(n)
5.����ȫ���������մ��ϵ��´����ҵ�˳���ţ�
����Ϊi�Ľ���˫�׽��ı��Ϊi/2������Ϊ2i���Һ���Ϊ2i+1
*/
/*
ɭ�֣������������
*/
/*
���ı�����
��������Ϊ �������ڵ㣬��������������
1.ǰ��������ȸ��ڵ㣬������������������
2.����������������������������������ڵ�
3.�����������������������ڵ㣬����ҽڵ�
4.�������
Note:
ǰ��/����/�������������ֻҪ֪������Ϳ���Ψһȷ��һ�Ŷ�����
*/
/*
How to convert a tree into a binary tree?
1.Root of binary tree = Root of general tree
2.Left child of node in binary tree = Leftmost child of the node in general tree
3.Right child of node in binary tree = Right sibling of the node in general tree

How to convert a forest into a binary tree?
�Ȱ���������ɶ��������ڰѸ����������ĸ��ڵ�����ϵ�����������
*/
/*
ǰ������� ���� ǰ������������
���������� ���� �������������
ǰ�����ɭ�־��� ǰ������������
��������ɭ�� ������������������
*/
/*
�������Ĵ洢�ṹ��
��1����˳��洢�ṹ������������������������ţ���һά����洢������index��Ϊ����ţ���������Ϊ�������
��2��������������ÿ����㣬��������洢���ݣ���ָ����洢���ӽ�㣬��ָ����洢�Һ��ӽ�㡣
*/
//���������һ�����
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
	//һ��ָ�������
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

//���������ͷŽ��ʱ�����ͷ����������������ͷŸýڵ㡣
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

// ���Գ���
int main() {
	// ʹ��0��ʾ�սڵ�
	int data[] = { 1, 2, 3, 4, 5, 0, 7 };
	BiTree<int> tree(data);

	cout << "PreOrder Traversal: ";
	tree.PreOrder(tree.root);
	cout << endl;

	return 0;
}