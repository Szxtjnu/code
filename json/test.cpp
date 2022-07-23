/* 
By:咕
问题：TSP问题
算法：蛮力法（顺序查找）分治法（快速排序）贪心法（求上界）
近似算法（贪心+寻找最优贪心值）分支限界法（多城市）动态规划法（少城市）
回溯法（中等规模城市数量）Sherwood概率算法改进版（随机第一个城市）共8种算法
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cmath>
#include<ctime>
const int INF = 100000;//自身到自身的一个无穷大数
using namespace std;
int n, res = INF, All_upper_bound, first_city = 0,num=0;
//城市数量，结果距离，全局上界，第一个城市编号
clock_t start_time;//用于计算时间
int** CITYS;//城市邻接矩阵
int** CITYS_sort;//经过排序后的矩阵
int** dist;//近似算法邻接矩阵
int* city_res;//保存计算好的城市序列
int* city_approximate;//近似算法城市序列
int* city_back_track;//用于回溯法城市序列
int path_length_back_track = 0;//用于回溯法记录路径长度
/* 近似算法所用Prim结构体，前者为生成树，后者为代价序列 */
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
class City//城市类，对应每个城市
{
public:
    /* 这里用两个动态数组的原因是因为更灵活，更节省空间 */
    /* try用来catch住内存超量的错误，catch后直接找近似最优 */
    int* city_array;//用于记录已经走过的序列
    bool* city_visit;//用于记录每个城市是否到达过
    int path_length;//路径长度
    int upper_bound;//该城市上界
    int lower_bound;//该城市下界
    int amount_citys;//已走过的城市数
    /* 初始化城市节点 */
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
    /* 析构函数，释放分配的空间 */
    ~City()
    {
        delete []city_array;
        delete []city_visit;
    }
    /* 拷贝上一个城市的参数 */
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
    /* 加入新的城市节点 */
    void Insert_City(int current_city)
    {
        try
        {
            if (current_city != first_city)//如果加入的不是第一个城市就计算路径
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
    /* 上界计算，近似算法（贪心法），用于剪枝和求内存超量的最优近似 */
    int Get_Upper_Bound(int cur_city, City& greedy_city_path)
    {
        try 
        {
            if (greedy_city_path.amount_citys == n)//如果访问完所有城市，就返回最后一个城市和第一个城市的闭环长度
                return greedy_city_path.path_length + CITYS[cur_city][greedy_city_path.city_array[0]];
            int i, min = INF;
            int next_city = n - 1;
            /* 贪心法利用最近邻点 ，求当前已经过城市和未经过城市的最小距离，然后将该未经过城市放入已经过城市集合内
            重复调用最终求得一个最小生成树，距离就是值+尾和头的距离*/
            for (i = 0; i < n; i++)
            {
                if (!greedy_city_path.city_visit[i] && min > CITYS[cur_city][i])//如果是未经过城市，且距离已经过城市更近
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
    /* 下界计算，用于剪枝 */
    void Get_Lower_Bound()
    {
        try
        {
            lower_bound = path_length * 2;//已走过路径的两倍
            int min = INF, mmin = INF;
            for (int i = 0; i < n; i++)
            {
                if (!city_visit[i])
                {
                    /* 首城市和尾城市对应的邻接矩阵行上不在路径上的最小值 */
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
    /* 计算上下界，并且在已有的贪心值中寻找最优,如果有更好的就更新最优近似 */
    void Get_Upper_Lower()
    {
        try 
        {
            City* greedy_City = new City();
            greedy_City->City_Copy(*this);
            upper_bound = Get_Upper_Bound(city_array[amount_citys - 1], *greedy_City);
            if (upper_bound < res)//更新最优近似
            {
                /* 这里更新最优近似的目的是，在内存超量时，可以直接用近似解
            并且这种近似解，比直接贪心求到的近似解距离更短（因为经过一部分的分支限界求距离） */
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
/* 优先序列排序运算符 */
struct cmp
{
    /* 用于优先队列根据下界排序 */
    bool operator()(City*& p1, City*& p2)const
    {
        return p1->lower_bound > p2->lower_bound;
    }
};
priority_queue<City*, vector<City*>, cmp>City_Array;//基于下界排序的优先队列
static int seed = (int)time(NULL);//基于当前时间的秒的随机数种子
/*Sherwood概率算法（不用于消除时间复杂性与算法联系），用于得到第一个城市节点
虽然原本的Sherwood定义是用于消除时间复杂性与算法联系，但这里我认为当内存不够只能得最优近似时，
多次执行程序，因为无法遍历全部解，所以第一个城市的随机得到的不同结果可以得出最优近似中的最优
（所以命名为Sherwood_Size）*/
int Sherwood_Size(int min, int max)//[min,max]区间内的随机数
{
    srand(seed);
    seed = rand();
    return (min + rand() % (max - min + 1));
}
/* 快速排序（分治法），排序城市邻接矩阵用于下界函数中求行最小的两个元素 */
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
/* 分支限界法，用于城市较多的情况，在内存过高时会使用优化过的贪心法做近似*/
void Branch_And_Bound()
{
    City* Begin_City = new City();
    //first_city = Sherwood_Size(0, n - 1);//随机第一个城市节点
    /* 这里并未调用是因为算法本身适用于多次执行程序，但是考试系统只能执行一次 */
    first_city = 0;
    Begin_City->Insert_City(first_city);
    Begin_City->Get_Upper_Lower();
    /* 把第一个城市的上界作为全局上界 */
    All_upper_bound = Begin_City->upper_bound;
    City_Array.push(Begin_City);
    /* 不断从PT表中找节点 */
    while (City_Array.size())
    {
        /* 超过55分钟就直接找近似最优 */
        if ((clock() - start_time) * 1.0 / CLOCKS_PER_SEC >= 3300)
        {
            break;
        }
        /*if (City_Array.size()>4000000)
        {
            break;
        }*/
        /* try用来catch住内存超量的错误，catch后直接找近似最优 */
        try
        {
            City* current = City_Array.top();//得到下界小的城市优先搜索
            City_Array.pop();
            /* 如果距离解只差一个城市，求解 */
            if (current->amount_citys == n - 1)
            {
                /* 找到剩下的那个城市，计算路径（包含返回开头的路径） */
                for (int i = 0; i < n; i++)
                {
                    if (!current->city_visit[i])
                    {
                        current->city_array[current->amount_citys++] = i;
                        current->path_length += (CITYS[current->city_array[current->amount_citys - 2]][i] + CITYS[i][current->city_array[0]]);
                        break;
                    }
                }
                All_upper_bound = min(All_upper_bound, current->path_length);//更新全局上界函数值
                res = min(res, current->path_length);//和已有的解比较谁更优
                if (res == current->path_length)//如果这个解更好，那么结果为这个解
                {
                    for (int i = 0; i < n; i++)
                    {
                        city_res[i] = current->city_array[i];
                    }
                }
                delete current;
                continue;
            }
            /* 算法核心，寻找下一个城市 */
            for (int i = 0; i < n; i++)
            {
                if (!current->city_visit[i])//如果没到过这个城市就可以算一算
                {
                    City* next_city = new City();
                    next_city->City_Copy(*current);
                    next_city->Insert_City(i);
                    next_city->Get_Upper_Lower();
                    if (next_city->lower_bound > All_upper_bound)//该城市下界比全局上界大，丢弃
                    {
                        delete next_city;
                        continue;
                    }
                    else//加入PT表
                    {
                        City_Array.push(next_city);
                    }
                }
            }
            delete current;
        }
        /* catch到错误后，直接找近似最优 */
        catch (exception e)
        {
            break;
        }
    }
}
/* 动态规划法，利用二进制优化所以速度快，但正因为用了二进制所以内存占用更高，且没法求最优近似，用于城市较少的情况 */
void Dynamic_Programming()
{
    /*
    用二进制表示集合，第x位为1代表x在集合中
    例如1表示为001，2表示为010，{1，2}表示为011
     */
    int i, j, k, temp;
    int** d = new int* [n];//动态规划路径
    int** path = new int* [n];//记录最优路径
    int amount_aggregation = (int)pow(2, n - 1);	//集合数量，n个城市就有2的n-1次方个集合
    for (i = 0; i < n; i++)
    {
        d[i] = new int[amount_aggregation];
        path[i] = new int[amount_aggregation];
    }
    /* 初始化第0列 */
    for (i = 0; i < n; i++)
        d[i][0] = CITYS[i][0];
    /* 算法核心，求最优路径 */
    for (i = 1; i < amount_aggregation - 1; i++)//对应一个集合
    {
        for (j = 1; j < n; j++)//对应每个点
        {
            if (((int)pow(2, j - 1) & i) == 0)//如果城市j不在集合中 
            {
                d[j][i] = INF;
                for (k = 1; k < n; k++)
                {
                    if ((int)pow(2, k - 1) & i)//如果k在集合中
                    {
                        temp = CITYS[j][k] + d[k][i - (int)pow(2, k - 1)]; //那么就求这个距离
                        if (temp < d[j][i])//如果更小就更新该城市到集合城市的最优距离
                        {
                            d[j][i] = temp;
                            path[j][i] = k;//记录最短路径
                        }
                    }
                }
            }
        }
    }
    /* 寻找第一个城市到其余全部城市组成集合的最短路径 */
    d[0][amount_aggregation - 1] = INF;
    for (i = 1; i < n; i++)
    {
        temp = CITYS[0][i] + d[i][amount_aggregation - 1 - (int)pow(2, i - 1)];
        if (temp < d[0][amount_aggregation - 1])
        {
            d[0][amount_aggregation - 1] = temp;//最短路径长度
            path[0][amount_aggregation - 1] = i;//更新第一个城市到哪个城市最短（路径中的第二个城市）
        }
    }
    /* 利用算好的表求最优解 */
    res = d[0][amount_aggregation - 1];//最短路径长度
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
/* 近似算法所用Prim求最小生成树 */
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
        /* 寻找代价序列中最低的节点，加入生成树 */
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
        /* 因为加入了新结点，所以更新代价序列 */
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
/* 近似算法所用，前序遍历最小生成树 */
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
/* 优化后的近似算法，对于多个城市，尝试计算不同起始点的贪心值 */
void Mult_Approximate()
{
    int length_approximate;
    city_approximate=new int[n];
    tree=new Prim_Tree[n];
    lowcost=new Prim_Cost[n];
    /* 以每个城市作为头结点求最小生成树 */
    for (int i = 0; i < n; i++)
    {  
        first_city = i;
        num=0;
        Approximate_Prim();
	    Approximate_DFS(-1);
        /* 如果比之前的近似解更好就更新近似解 */
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
/* 回溯法，用于城市数中等，经测试13-16这个区间是普遍比分支限界法快的 */
void Back_Track_DFS(int depth)
{
    if (depth > n - 1)//如果已经到了底层
    {
        /* 如果该结果比最优好，那么就更新最优 */
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
            /* 把序列剩余的点分别尝试交换到这个点后，进行递归求解 */
            if ((CITYS[city_back_track[depth - 1]][city_back_track[i]] < INF) && (CITYS[city_back_track[depth - 1]][city_back_track[i]] + path_length_back_track < res))
            {
                swap(city_back_track[depth], city_back_track[i]);
                path_length_back_track += CITYS[city_back_track[depth - 1]][city_back_track[depth]];
                Back_Track_DFS(depth + 1);
                /* 算完了再换回来 */
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
/* 输入函数，输入城市数量n和城市间的邻接矩阵 */
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
/* 输出函数，可输出结果、路径，以及算法用时 */
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
/* 随机数测试函数 */
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
        Dynamic_Programming();//少于13个城市调用动态规划法
    else if (n > 12 && n <= 15)
        Back_Track();
    else
    {
        Mult_Approximate();//不同起点的Prim求近似
        Branch_And_Bound();//13个或多于13个调用分支限界法
    }
    Output();
    return 0;
}
/* 
更多测试用例（比较大的，写不进去，后续可以用文件上传）
5
100000 3 1 5 8
3 100000 6 7 9
1 6 100000 4 2
5 7 4 100000 3
8 9 2 3 100000
16
*/
