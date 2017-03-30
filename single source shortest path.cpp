#include<iostream>
using namespace std;
void Dijkstra(int n, int u, float *dist, int *p, float **c);
int main() {
	int n, u;
	cout << "输入顶点个数:";
	cin >> n;
	float *dist = new float[n];//记录源点到其他顶点的距离；
	int *p = new int[n];//记录最短路径
	float **c;
	c = new float*[n];
	for (int i = 0; i < n; i++)
		c[i] = new float[n];
	cout << "输入源点U：";
	cin >> u;
	for (int i = 0; i < n; i++)
		cout << "   " << i + 1;
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << "  ";
		for (int j = 0; j < n; j++)
			cin >> c[i][j];
	}
	Dijkstra(n, u, dist, p, c);
	return 0;
}
void Dijkstra(int n, int u, float *dist, int *p, float **c) {
	bool *s = new bool[n];//相当于集合S，s[i]如果等于true,说明i已经加入集合S；否则，顶点i属于集合V-S
	for (int i = 1; i < n; i++) {//注意此处i=1
		dist[i] = c[u][i];    //初始化源点到其他各顶点的最短距离
		s[i] = false;//s[i]全部初始化为FALSE，在之后可以更改
		if (dist[i] == 10000)
			p[i] = -1;         //满足条件说明源点和顶点i不相邻
		else         //满足条件源点和顶点i相邻，设置p[i]=u;
			p[i] = u;
	}
	dist[u] = 0;
	s[u] = true;
	for (int i = 1; i < n; i++) {
		float temp = 10000;
		int t = u;
		for (int j = 1; j < n; j++) {
			if ((!s[j]) && (dist[j] < temp))//在集合S-V中寻找离源点最近的顶点t
			{
				temp = dist[j];
				t = j;
			}
			if (t == u) break;            //找不到t，跳出循环
			s[t] = true;                  //否则，将t加入集合S
			for (j = 1; j < n; j++)       //更新与t相邻的顶点到原点u的距离
				if ((!s[j]) && (c[t][j])) {
					dist[j] = dist[t] + c[t][j];
					p[j] = t;
				}
		}
	}
}