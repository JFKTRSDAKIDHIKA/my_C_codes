/*
一些名字：
1.顶点：数据元素
2.边：顶点间的无向连线
3.弧：顶点之间的有向连线
4.无向图
5.有向图
6.简单图：没有从自己到自己的边；没有重复的边
7.邻接点：一条边连接的点
8.完全无向图：所有顶点之间都有连线
9.完全有向图
10.网：带权的图
11.子图：图的子集
12.路径：一个顶点序列
13.路径长度：路径上经过边的数目
14.连通图：任意两个顶点之间都存在路径
15.连通分量：极大连通子图
16.生成树：连通图的极小连通子图
17.生成森林：
*/
//图的存储：邻接矩阵
const int MAXSIZE = 10;
template<class T> class MGraph {
public:
	// Some methods...
private:
	T vertex[MAXSIZE];
	int arc[MAXSIZE][MAXSIZE;
	int vNum, arcNum;
};
//图的存储：邻接表
//顶点结点
struct VertexNode {
	char vertex;
	ArcNode* firstarc;
};
//弧结点
struct ArcNode {
	int adjvex;//邻接顶点的下标
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
//Dijkstra算法

