/*
һЩ���֣�
1.���㣺����Ԫ��
2.�ߣ���������������
3.��������֮�����������
4.����ͼ
5.����ͼ
6.��ͼ��û�д��Լ����Լ��ıߣ�û���ظ��ı�
7.�ڽӵ㣺һ�������ӵĵ�
8.��ȫ����ͼ�����ж���֮�䶼������
9.��ȫ����ͼ
10.������Ȩ��ͼ
11.��ͼ��ͼ���Ӽ�
12.·����һ����������
13.·�����ȣ�·���Ͼ����ߵ���Ŀ
14.��ͨͼ��������������֮�䶼����·��
15.��ͨ������������ͨ��ͼ
16.����������ͨͼ�ļ�С��ͨ��ͼ
17.����ɭ�֣�
*/
//ͼ�Ĵ洢���ڽӾ���
const int MAXSIZE = 10;
template<class T> class MGraph {
public:
	// Some methods...
private:
	T vertex[MAXSIZE];
	int arc[MAXSIZE][MAXSIZE;
	int vNum, arcNum;
};
//ͼ�Ĵ洢���ڽӱ�
//������
struct VertexNode {
	char vertex;
	ArcNode* firstarc;
};
//�����
struct ArcNode {
	int adjvex;//�ڽӶ�����±�
	ArcNode* nextarc;
};
const int MAXSIZE = 10;
template<class T>class ALGraph {
public:
	// A few methods...
private:
	VertexNode adjlist[MAXSIZE];
	int vNum, arcNum;
};
//Dijkstra�㷨

