#include<iostream>
#include<cstdio>
#include<cstdlib>
typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 65535
#define TURE 1
#define FALSE 0
typedef int Boolean;
Boolean visited[MAXVEX];

#define MAXSIZE 100
typedef int QElemType;
typedef int Status;
#define OK 1
#define ERROR 0

typedef struct{
	QElemType data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

Status InitQue(SqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

Status EnQueue(SqQueue *Q, QElemType e)
{
	if((Q->rear + 1) % MAXSIZE == Q->front)
		return ERROR;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return OK;
}

Status DeQueue(SqQueue *Q, QElemType *e)
{
	if(Q->front == Q->rear)
		return ERROR;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return OK;
}

int LengthQue(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

typedef struct
{
	VertexType adList[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVerexes, numEdges;
}Graph;

typedef struct EdgeNode
{
	int adjSub;
	EdgeType weight;
	struct EdgeNode * next;
}EdgeNode;

typedef struct VertexNode
{
	VertexType data;
	EdgeNode * firstEdge;
}GraphList[MAXVEX];

typedef struct
{
	GraphList graphlist;
	int numVerexes, numEdges;
}AjaGraph;

typedef struct Orthogonal
{
	int tailVex;
	int headVex;
	struct Orthogonal *tailLink;
	struct Orthogonal *headLink;
}Orthogonal;

typedef struct
{
	VertexType data;
	Orthogonal *firstin;
	Orthogonal *firstout;
}Orthogonal_Node[MAXVEX];

typedef struct
{
	Orthogonal_Node orth_Node;
	int numVertexes,numEdges;
}OrthGraph;

typedef struct
{
	int jVex;
	int iVex;
	EdgeType weight;
}EdgeArray[MAXVEX];

typedef struct
{
	VertexType VexterList[MAXVEX];
	EdgeArray EdgeList;
	int numVexteres, numEdges;
}EdgeListArray;

typedef struct EdgeList_multiple
{
	int iVex;
	int jVex;
	struct EdgeList_multiple *iLink;
	struct EdgeList_multiple *jLink;
}EdgeList_mulitiple;

typedef struct
{
	VertexType data;
	EdgeList_multiple *firstEdge;
}Vexs;

typedef struct
{
	Vexs vexs[MAXVEX];
	int numVexes;
	int numEdges;
}MultipleGraph;

int CreatGraphMultiple(MultipleGraph *G)
{
	int i,j,k;
	cout << "���붥��i�ͱ�j��������" << endl;
	cin >> G->numVexes << G->numEdges;
	EdgeList_multiple *em;
	getchar();
	for(i=0; i<G->numVexes; i++){
		cout << "�������" << i << "���ڵ�:" ;
		cin >> G->vexs[i].data;
		getchar();
	}
	for(k=0; k<G->numEdges; k++){
		cout << "������ߵ����i���յ�j���±꣺";
		cin >> i >> j;
		em = (EdgeList_multiple *)malloc(sizof(EdgeList_multiple));
		em->iVex = i;
		em->jVex = j;
		em->iLink = G->vexs[i].firstEdge;
		G->vexs[i].firstEdge = em;
		em->jLink = G->vexs[j].firstEdge;
		G->vexs[j].firstEdge = em;
	}
	return 1;
}

int CreatGraph(Graph *G)
{
	int i, j, k, w;
	cout << "������ڵ���i������j" << endl;
	cin >> G->numVerexes >> G->numEdges;
	for (i = 0; i<G->numVerexesl ++i)
	{
		cout << "�������" << i << "���ڵ�:";
		cin >> G->adList[i];
		getchar();
	}
	for ( i = 0; i < G->numVerexes; i++)
	{
		for (  j = 0; j < G->numVerexes; j++)
		{
			G->arc[i][j] = INFINITY;
		}
	}
	for (  k = 0; k < G->numEdges; k++)
	{
		cout << "��������Ҫ���Ȩֵ���±�i���±�j,����Ȩֵw:";
		cin >> i >> j >> w;
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];
	}
	return 1;
}

int CreatAjaGraph(AjaGraph *G)
{
	int i, j, k;
	char a;
	EdgeNode *e;
	cout << "�����붥��i�ͱ���j:";
	cin >> G->numVerexes >> G->numEdges;
	getchar();
	for (i = 0; i < G->numVerexes; ++i){
		cout << "�������" << i << "���ڵ�:";
		cin >> G->graphlist[i].data;
		getchar();
		cout << a;
		G->graphlist[i].firstEdge = NULL;
	}
	for (k = 0; k < G->numEdges; ++k){
		cout << "�������ڽӵ�Vi��Vj���±꣺";
		cin >> i >> j;
		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjSub = j;
		e->next = G->graphlist[j].firstEdge;
		G->graphlist[j].firstEdge = e;

		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjSub = i;
		e->next = G->graphlist[j].firstEdge;
		G->graphlist[j].firstEdge = e;
	}
	return 1;
}

int CreatOrthGraph(OrthGraph *G)
{
	int i, j, k;
	Orthogonal *e;
	cout << "�����붨������i�ͱ�����j��";
	cin >> G->numVertexes >> G->numEdges;
	for (i = 0; i < G->numVertexes; ++i){
		cout << "�������" << i << "���ڵ�:";
		cin >> G->orth_Node[i].data;
		getchar();
		G->orth_Node[i].firstin = NULL;
		G->orth_Node[i].firstout = NULL;
	}
	for (k = 0; k < G->numEdges; k++){
		cout << "���������i���յ�j���±꣺";
		cin >> i >> j;
		e = (Orthogonal*)malloc(sizeof(Orthogonal));
		e->tailVex = i;
		e->headVex = j;
		e->tailLink = G->orth_Node[i].firstout;
		G->orth_Node[i].firstout = e;
		e->headLink = G->orth_Node[j].firstin;
		G->orth_Node[j].firstin = e;
	}
	return 1;
}

int CreatGraph(EdgeListArray *G)
{
	int i, j, w;
	cout << "�����붨������i�ͱ�����j��";
	cin >> G->numVexteres >> G->numEdges;
	for (i = 0; i < G->numVexteres; ++i)
	{
		cout << "�������" << i << "���ڵ�";
		cin >> G->VexterList[i];
	}
	for (i = 0; i < G->numEdges; ++i)
	{
		cout << "�����붥��i�붥��j����Ȩ��w��";
		cin >> i >> j >> w;
		G->EdgeList[i].iVex = i;
		G->EdgeList[i].jVex = j;
		G->EdgeList[i].weight = w;
	}
	return 1;
}

void PrintfGraph(Graph G)
{
	int i, j;
	for (i = 0; i < G.numVerexes; ++i)
		for (j = 0; j < G.numVerexes; ++j)
			if(G.arc[i][j] != INFINITY && i<j)
				printf("����:  %d  ,  Ȩ��:  %d\n", i, j, G.arc[i][j]);
}

void PrintDeepthAjaGraph(AjaGraph G, int i)
{
	visited[i] = TRUE;
	cout << G.graphlist[i].data;
	EdgeNode *ag;
	ag = G.graphlist[i].firstEdge;
	while(ag){
		if(!visited[ag->adjSub])
			PrintDeepthAjaGraph(G, ag->adjSub);
		ag = ag->next;
	}
}

void Depth_first(AjaGraph G)
{
	int j;
	for (  j = 0; j < G.numVerexes; j++)
	{
		visited[j] = FALSE;
	}
	for (j = 0; j < G.numVerexes; j++)
	{
		if(!visited[j])
			PrintDeepthAjaGraph(G, j);
	}
}

void BFs(AjaGraph G)
{
	int j;
	SqQueue Q;
	InitQue(&Q);
	for (j = 0; j < G.numVerexes; ++j)
		visited[j] = FALSE;
	EdgeNode *ag;
	visited[0] = TURE;
	cout << G.graphlist[0].data;
	EnQueue(&Q, 0);
	while(Q.front != Q.rear){
		DeQueue(&Q, &j);
		ag = G.graphlist[j].firstEdge;
		while(ag && !visited[ag->adjSub]){
			visited[ag->adjSub] = TURE;
			cout << G.graphlist[ag->adjSub].data;
			EnQueue(&Q, ag->adjSub);
			ag = ag->next;
		}
	}
}

int main()
{
	Graph G1;
	AjaGraph G2;
	OrthGraph G3;
	MultipleGraph G4;
	EdgeListArray G5;
	while(true){
		int flag = 0;
		printf("��ѡ���ͼ�Ĳ�����\n");
		printf("1.�ڽӾ���洢����\n");
        printf("2.�ڽӱ�洢����\n");
        printf("3.ʮ������洢����\n");
        printf("4.�ڽӶ��ر���\n");
        printf("5.�߼����鴴��\n");
        printf("6.�����ڽӾ���ͼ�ṹ\n");
        printf("7.�ڽӱ�������ȱ���\n");
        printf("8.����������������\n");
        printf("9.�˳�\n");
		int a;
		cin >> a;
		switch (a)
		{
		case 1:
			flag = 0;
			flag = CreatGraph(&G1);
			if(flag)
				cout << "�����ɹ�";
			else
				cout << "����ʧ��";
			break;
		
		default:
			break;
		}
	}
}