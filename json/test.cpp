/* 
By:��
���⣺TSP����
�㷨����������˳����ң����η�����������̰�ķ������Ͻ磩
�����㷨��̰��+Ѱ������̰��ֵ����֧�޽編������У���̬�滮�����ٳ��У�
���ݷ����еȹ�ģ����������Sherwood�����㷨�Ľ��棨�����һ�����У���8���㷨
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cmath>
#include<ctime>
const int INF = 100000;//���������һ���������
using namespace std;
int n, res = INF, All_upper_bound, first_city = 0,num=0;
//����������������룬ȫ���Ͻ磬��һ�����б��
clock_t start_time;//���ڼ���ʱ��
int** CITYS;//�����ڽӾ���
int** CITYS_sort;//���������ľ���
int** dist;//�����㷨�ڽӾ���
int* city_res;//�������õĳ�������
int* city_approximate;//�����㷨��������
int* city_back_track;//���ڻ��ݷ���������
int path_length_back_track = 0;//���ڻ��ݷ���¼·������
/* �����㷨����Prim�ṹ�壬ǰ��Ϊ������������Ϊ�������� */
struct Prim_Tree
{
    int cur_point;
	int up_point;
};
struct Prim_Cost
{
    double cost;
	int from;
};
Prim_Tree *tree;
Prim_Cost *lowcost;
class City//�����࣬��Ӧÿ������
{
public:
    /* ������������̬�����ԭ������Ϊ��������ʡ�ռ� */
    /* try����catchס�ڴ泬���Ĵ���catch��ֱ���ҽ������� */
    int* city_array;//���ڼ�¼�Ѿ��߹�������
    bool* city_visit;//���ڼ�¼ÿ�������Ƿ񵽴��
    int path_length;//·������
    int upper_bound;//�ó����Ͻ�
    int lower_bound;//�ó����½�
    int amount_citys;//���߹��ĳ�����
    /* ��ʼ�����нڵ� */
    City()
    {
        try 
        {
            city_array = new int[n];
            city_visit = new bool[n];
            path_length = 0;
            amount_citys = 0;
            for (int i = 0; i < n; i++)
            {
                city_visit[i] = 0;
            }
        }
        catch (exception e)
        {
            throw;
        }  
    }
    /* �����������ͷŷ���Ŀռ� */
    ~City()
    {
        delete []city_array;
        delete []city_visit;
    }
    /* ������һ�����еĲ��� */
    void City_Copy(const City& pre_city)
    {
        try 
        {
            amount_citys = pre_city.amount_citys;
            for (int i = 0; i < n; i++)
            {
                city_visit[i] = pre_city.city_visit[i];
                city_array[i] = pre_city.city_array[i];
            }
            path_length = pre_city.path_length;
        }
        catch (exception e)
        {
            throw;
        }
    }
    /* �����µĳ��нڵ� */
    void Insert_City(int current_city)
    {
        try
        {
            if (current_city != first_city)//�������Ĳ��ǵ�һ�����оͼ���·��
                path_length += CITYS[city_array[amount_citys - 1]][current_city];
            amount_citys++;
            city_array[amount_citys - 1] = current_city;
            city_visit[current_city] = 1;
        }
        catch (exception e)
        {
            throw;
        }
    }
    /* �Ͻ���㣬�����㷨��̰�ķ��������ڼ�֦�����ڴ泬�������Ž��� */
    int Get_Upper_Bound(int cur_city, City& greedy_city_path)
    {
        try 
        {
            if (greedy_city_path.amount_citys == n)//������������г��У��ͷ������һ�����к͵�һ�����еıջ�����
                return greedy_city_path.path_length + CITYS[cur_city][greedy_city_path.city_array[0]];
            int i, min = INF;
            int next_city = n - 1;
            /* ̰�ķ���������ڵ� ����ǰ�Ѿ������к�δ�������е���С���룬Ȼ�󽫸�δ�������з����Ѿ������м�����
            �ظ������������һ����С���������������ֵ+β��ͷ�ľ���*/
            for (i = 0; i < n; i++)
            {
                if (!greedy_city_path.city_visit[i] && min > CITYS[cur_city][i])//�����δ�������У��Ҿ����Ѿ������и���
                {
                    min = CITYS[cur_city][i];
                    next_city = i;
                }
            }
            greedy_city_path.path_length += min;
            greedy_city_path.city_visit[next_city] = 1;
            greedy_city_path.city_array[greedy_city_path.amount_citys++] = next_city;
            return Get_Upper_Bound(next_city, greedy_city_path);
        }
        catch (exception e)
        {
            throw;
        }
    }
    /* �½���㣬���ڼ�֦ */
    void Get_Lower_Bound()
    {
        try
        {
            lower_bound = path_length * 2;//���߹�·��������
            int min = INF, mmin = INF;
            for (int i = 0; i < n; i++)
            {
                if (!city_visit[i])
                {
                    /* �׳��к�β���ж�Ӧ���ڽӾ������ϲ���·���ϵ���Сֵ */
                    if (mmin > CITYS[city_array[amount_citys - 1]][i])
                        mmin = CITYS[city_array[amount_citys - 1]][i];
                    if (min > CITYS[city_array[0]][i])
                        min = CITYS[city_array[0]][i];
                    lower_bound += (CITYS_sort[i][0] + CITYS_sort[i][1]);
                }
            }
            lower_bound += (mmin + min);
            lower_bound = int(ceil(lower_bound * 1.0 / 2));
        }
        catch (exception e)
        {
            throw;
        }
    }
    /* �������½磬���������е�̰��ֵ��Ѱ������,����и��õľ͸������Ž��� */
    void Get_Upper_Lower()
    {
        try 
        {
            City* greedy_City = new City();
            greedy_City->City_Copy(*this);
            upper_bound = Get_Upper_Bound(city_array[amount_citys - 1], *greedy_City);
            if (upper_bound < res)//�������Ž���
            {
                /* ����������Ž��Ƶ�Ŀ���ǣ����ڴ泬��ʱ������ֱ���ý��ƽ�
            �������ֽ��ƽ⣬��ֱ��̰���󵽵Ľ��ƽ������̣���Ϊ����һ���ֵķ�֧�޽�����룩 */
                res = upper_bound;
                for (int i = 0; i < n; i++)
                {
                    city_res[i] = greedy_City->city_array[i];
                }
            }
            delete greedy_City;
            this->Get_Lower_Bound();
        }
        catch (exception e)
        {
            throw;
        }
    }
};
/* ����������������� */
struct cmp
{
    /* �������ȶ��и����½����� */
    bool operator()(City*& p1, City*& p2)const
    {
        return p1->lower_bound > p2->lower_bound;
    }
};
priority_queue<City*, vector<City*>, cmp>City_Array;//�����½���������ȶ���
static int seed = (int)time(NULL);//���ڵ�ǰʱ���������������
/*Sherwood�����㷨������������ʱ�临�������㷨��ϵ�������ڵõ���һ�����нڵ�
��Ȼԭ����Sherwood��������������ʱ�临�������㷨��ϵ������������Ϊ���ڴ治��ֻ�ܵ����Ž���ʱ��
���ִ�г�����Ϊ�޷�����ȫ���⣬���Ե�һ�����е�����õ��Ĳ�ͬ������Եó����Ž����е�����
����������ΪSherwood_Size��*/
int Sherwood_Size(int min, int max)//[min,max]�����ڵ������
{
    srand(seed);
    seed = rand();
    return (min + rand() % (max - min + 1));
}
/* �������򣨷��η�������������ڽӾ��������½纯����������С������Ԫ�� */
void Quick_Sort(int arr[], int pos1, int pos2)
{
    if (pos1 < pos2)
    {
        int i = pos1, j = pos2, x = arr[pos1];
        while (i != j)
        {
            while (i != j && arr[j] >= x)
                j--;
            if (i < j)
                arr[i++] = arr[j];
            while (i != j && arr[i] < x)
                i++;
            if (i < j)
                arr[j--] = arr[i];
        }
        arr[i] = x;
        Quick_Sort(arr, pos1, i - 1);
        Quick_Sort(arr, i + 1, pos2);
    }

}
/* ��֧�޽編�����ڳ��н϶����������ڴ����ʱ��ʹ���Ż�����̰�ķ�������*/
void Branch_And_Bound()
{
    City* Begin_City = new City();
    //first_city = Sherwood_Size(0, n - 1);//�����һ�����нڵ�
    /* ���ﲢδ��������Ϊ�㷨���������ڶ��ִ�г��򣬵��ǿ���ϵͳֻ��ִ��һ�� */
    first_city = 0;
    Begin_City->Insert_City(first_city);
    Begin_City->Get_Upper_Lower();
    /* �ѵ�һ�����е��Ͻ���Ϊȫ���Ͻ� */
    All_upper_bound = Begin_City->upper_bound;
    City_Array.push(Begin_City);
    /* ���ϴ�PT�����ҽڵ� */
    while (City_Array.size())
    {
        /* ����55���Ӿ�ֱ���ҽ������� */
        if ((clock() - start_time) * 1.0 / CLOCKS_PER_SEC >= 3300)
        {
            break;
        }
        /*if (City_Array.size()>4000000)
        {
            break;
        }*/
        /* try����catchס�ڴ泬���Ĵ���catch��ֱ���ҽ������� */
        try
        {
            City* current = City_Array.top();//�õ��½�С�ĳ�����������
            City_Array.pop();
            /* ��������ֻ��һ�����У���� */
            if (current->amount_citys == n - 1)
            {
                /* �ҵ�ʣ�µ��Ǹ����У�����·�����������ؿ�ͷ��·���� */
                for (int i = 0; i < n; i++)
                {
                    if (!current->city_visit[i])
                    {
                        current->city_array[current->amount_citys++] = i;
                        current->path_length += (CITYS[current->city_array[current->amount_citys - 2]][i] + CITYS[i][current->city_array[0]]);
                        break;
                    }
                }
                All_upper_bound = min(All_upper_bound, current->path_length);//����ȫ���Ͻ纯��ֵ
                res = min(res, current->path_length);//�����еĽ�Ƚ�˭����
                if (res == current->path_length)//����������ã���ô���Ϊ�����
                {
                    for (int i = 0; i < n; i++)
                    {
                        city_res[i] = current->city_array[i];
                    }
                }
                delete current;
                continue;
            }
            /* �㷨���ģ�Ѱ����һ������ */
            for (int i = 0; i < n; i++)
            {
                if (!current->city_visit[i])//���û����������оͿ�����һ��
                {
                    City* next_city = new City();
                    next_city->City_Copy(*current);
                    next_city->Insert_City(i);
                    next_city->Get_Upper_Lower();
                    if (next_city->lower_bound > All_upper_bound)//�ó����½��ȫ���Ͻ�󣬶���
                    {
                        delete next_city;
                        continue;
                    }
                    else//����PT��
                    {
                        City_Array.push(next_city);
                    }
                }
            }
            delete current;
        }
        /* catch�������ֱ���ҽ������� */
        catch (exception e)
        {
            break;
        }
    }
}
/* ��̬�滮�������ö������Ż������ٶȿ죬������Ϊ���˶����������ڴ�ռ�ø��ߣ���û�������Ž��ƣ����ڳ��н��ٵ���� */
void Dynamic_Programming()
{
    /*
    �ö����Ʊ�ʾ���ϣ���xλΪ1����x�ڼ�����
    ����1��ʾΪ001��2��ʾΪ010��{1��2}��ʾΪ011
     */
    int i, j, k, temp;
    int** d = new int* [n];//��̬�滮·��
    int** path = new int* [n];//��¼����·��
    int amount_aggregation = (int)pow(2, n - 1);	//����������n�����о���2��n-1�η�������
    for (i = 0; i < n; i++)
    {
        d[i] = new int[amount_aggregation];
        path[i] = new int[amount_aggregation];
    }
    /* ��ʼ����0�� */
    for (i = 0; i < n; i++)
        d[i][0] = CITYS[i][0];
    /* �㷨���ģ�������·�� */
    for (i = 1; i < amount_aggregation - 1; i++)//��Ӧһ������
    {
        for (j = 1; j < n; j++)//��Ӧÿ����
        {
            if (((int)pow(2, j - 1) & i) == 0)//�������j���ڼ����� 
            {
                d[j][i] = INF;
                for (k = 1; k < n; k++)
                {
                    if ((int)pow(2, k - 1) & i)//���k�ڼ�����
                    {
                        temp = CITYS[j][k] + d[k][i - (int)pow(2, k - 1)]; //��ô�����������
                        if (temp < d[j][i])//�����С�͸��¸ó��е����ϳ��е����ž���
                        {
                            d[j][i] = temp;
                            path[j][i] = k;//��¼���·��
                        }
                    }
                }
            }
        }
    }
    /* Ѱ�ҵ�һ�����е�����ȫ��������ɼ��ϵ����·�� */
    d[0][amount_aggregation - 1] = INF;
    for (i = 1; i < n; i++)
    {
        temp = CITYS[0][i] + d[i][amount_aggregation - 1 - (int)pow(2, i - 1)];
        if (temp < d[0][amount_aggregation - 1])
        {
            d[0][amount_aggregation - 1] = temp;//���·������
            path[0][amount_aggregation - 1] = i;//���µ�һ�����е��ĸ�������̣�·���еĵڶ������У�
        }
    }
    /* ������õı������Ž� */
    res = d[0][amount_aggregation - 1];//���·������
    i = 0; j = amount_aggregation - 1; k = 0;
    city_res[k++] = 0;
    while (j > 0)
    {
        i = path[i][j];
        j = j - (int)pow(2, i - 1);
        city_res[k++] = i;
    }
    delete[]d;
    delete[]path;
}
int Get_Length(int *arr)
{
    int len=0;
    for(int i=0;i<n;i++)
    {
        if(i!=n-1)
            len += CITYS[arr[i]][arr[i + 1]];
        else
            len += CITYS[arr[i]][arr[0]];
    }
    return len;
}
/* �����㷨����Prim����С������ */
void Approximate_Prim()
{
	int i, j, p = first_city;
	double  minp = INF;
	tree[0].up_point = -1;
	tree[0].cur_point = first_city;
	for (j = 0; j < n; j++)		
	{
		lowcost[j].cost = dist[p][j];
		lowcost[j].from = first_city;
	}
	for (i = 1; i < n; i++)
	{
        /* Ѱ�Ҵ�����������͵Ľڵ㣬���������� */
		for (j = 0; j < n; j++)
		{
			if (lowcost[j].cost > 0 && lowcost[j].cost < minp&&j!=first_city)
			{
				p = j;
				minp = lowcost[j].cost;
			}
		}
		lowcost[p].cost = 0;
		minp = INF;
		tree[i].cur_point = p;
		tree[i].up_point = lowcost[p].from;
        /* ��Ϊ�������½�㣬���Ը��´������� */
		for (j = 0; j < n; j++)
		{
			if (lowcost[j].cost > 0 && lowcost[j].cost > dist[p][j]&&j!=first_city)
			{
				lowcost[j].cost = dist[p][j];
				lowcost[j].from = p;
			}
		}
	}
}
/* �����㷨���ã�ǰ�������С������ */
void Approximate_DFS(int find)
{
	for (int i = 0; i < n; i++)
	{
		if (tree[i].up_point == find)
		{
			city_approximate[num++] = tree[i].cur_point;
			Approximate_DFS(tree[i].cur_point);
		}
	}
}
/* �Ż���Ľ����㷨�����ڶ�����У����Լ��㲻ͬ��ʼ���̰��ֵ */
void Mult_Approximate()
{
    int length_approximate;
    city_approximate=new int[n];
    tree=new Prim_Tree[n];
    lowcost=new Prim_Cost[n];
    /* ��ÿ��������Ϊͷ�������С������ */
    for (int i = 0; i < n; i++)
    {  
        first_city = i;
        num=0;
        Approximate_Prim();
	    Approximate_DFS(-1);
        /* �����֮ǰ�Ľ��ƽ���þ͸��½��ƽ� */
        length_approximate=Get_Length(city_approximate);
        if(length_approximate<res)
        {
            res=length_approximate;
            for(int j=0;j<n;j++)
                city_res[j]=city_approximate[j];
        }
    }
        delete []tree;
        delete []lowcost;
        delete []city_approximate;
}
/* ���ݷ������ڳ������еȣ�������13-16����������ձ�ȷ�֧�޽編��� */
void Back_Track_DFS(int depth)
{
    if (depth > n - 1)//����Ѿ����˵ײ�
    {
        /* ����ý�������źã���ô�͸������� */
        if ((CITYS[city_back_track[n - 1]][0] < INF) && (CITYS[city_back_track[n - 1]][0] + path_length_back_track < res))
        {
            res = CITYS[city_back_track[n - 1]][0] + path_length_back_track;
            for (int i = 0; i < n; i++)
            {
                city_res[i] = city_back_track[i];
            }
        }
    }
    else
    {
        for (int i = depth; i < n; i++)
        {
            /* ������ʣ��ĵ�ֱ��Խ����������󣬽��еݹ���� */
            if ((CITYS[city_back_track[depth - 1]][city_back_track[i]] < INF) && (CITYS[city_back_track[depth - 1]][city_back_track[i]] + path_length_back_track < res))
            {
                swap(city_back_track[depth], city_back_track[i]);
                path_length_back_track += CITYS[city_back_track[depth - 1]][city_back_track[depth]];
                Back_Track_DFS(depth + 1);
                /* �������ٻ����� */
                path_length_back_track -= CITYS[city_back_track[depth - 1]][city_back_track[depth]];
                swap(city_back_track[depth], city_back_track[i]);
            }
        }
    }
}
void Back_Track()
{
    city_back_track = new int[n];
    city_res[0] = 0;
    for (int i = 0; i < n; i++)
    {
        city_back_track[i] = i;
    }
    Back_Track_DFS(1);
}
/* ���뺯���������������n�ͳ��м���ڽӾ��� */
void Input()
{
    int i, j;
    cin >> n;
    city_res = new int[n];
    CITYS = new int* [n];
    dist = new int* [n];
    CITYS_sort = new int* [n];
    for (i = 0; i < n; i++)
    {
        CITYS[i] = new int[n];
        CITYS_sort[i] = new int[n];
        dist[i]=new int[n];
    }
    res = INF;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> CITYS[i][j];
            dist[i][j]=CITYS[i][j];
            if (i == j)
            {
                CITYS[i][j] = INF;
                dist[i][j]=0;
            }
            CITYS_sort[i][j] = CITYS[i][j];

        }
        Quick_Sort(CITYS_sort[i], 0, n - 1);
    }
}
/* �������������������·�����Լ��㷨��ʱ */
void Output()
{
    //cout << "res:" << res << endl << "Path:";
    for (int i = 0; i < n; i++)
    {
        cout << city_res[i];
        if (i != n - 1)
            cout <<" ";
    }
    // cout << endl << "Path length:" << Get_Length(city_res) << endl;
    // start_time = clock() - start_time;
    // printf("It took me %d clicks (%f seconds).\n", start_time, ((float)start_time) / CLOCKS_PER_SEC);
}
/* ��������Ժ��� */
void Test()
{
    int i, j;
    n = Sherwood_Size(25, 30);
    city_res = new int[n];
    CITYS = new int* [n];
    dist = new int* [n];
    CITYS_sort = new int* [n];
    for (i = 0; i < n; i++)
    {
        CITYS[i] = new int[n];
        CITYS_sort[i] = new int[n];
        dist[i]=new int[n];
    }
    res = INF;
    for (i = 0; i < n; i++)
    {

        for (j = 0; j < n; j++)
        {
            CITYS[i][j] = Sherwood_Size(1, 1000);
            dist[i][j] = CITYS[i][j];
            if (i == j)
            {
                CITYS[i][j] = INF;
                dist[i][j]=0;
            }
            CITYS_sort[i][j] = CITYS[i][j];
        }
        Quick_Sort(CITYS_sort[i], 0, n - 1);
    }
    cout << n << endl;
    /*for (i = 0; i < n; i++)
    {

        for (j = 0; j < n; j++)
        {
            cout << CITYS[i][j] << " ";
        }
        cout << endl;
    }*/
}
int main()
{
    Input();
    //Test();
    start_time = clock();
    if (n <= 12)
        Dynamic_Programming();//����13�����е��ö�̬�滮��
    else if (n > 12 && n <= 15)
        Back_Track();
    else
    {
        Mult_Approximate();//��ͬ����Prim�����
        Branch_And_Bound();//13�������13�����÷�֧�޽編
    }
    Output();
    return 0;
}
/* 
��������������Ƚϴ�ģ�д����ȥ�������������ļ��ϴ���
5
100000 3 1 5 8
3 100000 6 7 9
1 6 100000 4 2
5 7 4 100000 3
8 9 2 3 100000
16
*/
