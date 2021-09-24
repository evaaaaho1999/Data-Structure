#include<iostream>
#define n 1000
using namespace std;
int d[n];
int w[n];
bool w_visit[n];
bool visit[n];
int building;
int lategraph[n][n];//紀錄late的graph 
int widthgraph[n][n];//紀錄width的graph 
int choose(int c)
{
	int min=-1, tmp=999;
	for(int i=0;i<c;i++)
	{
		if(!visit[i]&&d[i]<tmp)
		{
			tmp=d[i];
			min=i;
		}
	}
	return min;
}
void dijkstra(int v,int graph[n][n],int c)
{
	for(int i=0;i<c;i++)
		visit[i]=false;
	for(int i=0;i<c;i++)
		d[i]=graph[v][i];
	
	visit[v]=true;	
	d[v]=0;
	for(int k=0;k<c-1;k++)
	{
		int min=choose(c);
		if(min==-1)
			break;
		visit[min]=true;
		for(int b=0;b<c;b++)
		{
			if(!visit[b]&&d[min]+graph[min][b]<d[b])
			{
				d[b]=d[min]+graph[min][b];
			}
		}	
	}
}
int w_choose(int c)
{
	int min=-1, tmp=0;
	for(int i=0;i<c;i++)
	{
		if(!w_visit[i]&&w[i]>tmp)
		{
			tmp=w[i];
			min=i;
		}
	}
	return min;
}
void dijkstra_width(int v,int graph[n][n],int c)
{
	for(int i=0;i<c;i++)
	{
		w_visit[i]=false;
		w[i]=graph[v][i];
	}
		
	w_visit[v]=true;	
	w[v]=0;
	
	for(int k=0;k<c-1;k++)
	{
		int min=w_choose(c);
		if(min==-1)
			break;
		w_visit[min]=true;
		for(int b=0;b<c;b++)
		{
			if(graph[min][b]>0&&!w_visit[b])
			{
				int tmp=w[b];
				w[b]=(graph[min][b]>w[min])?w[min]:graph[min][b];
				w[b]=(tmp>w[b])?tmp:w[b];
			}
		}	
	}	
}

int main()
{
	int edge, late, width;
	cin>>building>>edge;
	
	for(int i=0;i<building;i++)
	{
		for(int j=0;j<building;j++)
		{
			if(i==j)
				lategraph[i][j]=0;
			else
				lategraph[i][j]=9999;
		}
	}//矩陣內一開始為0 
	for(int i=0;i<edge;i++)
	{
		int src,dest;
		cin>>src>>dest>>late>>width;
		lategraph[src][dest]=late;//創建一個adjacency graph(late) 
		widthgraph[src][dest]=width;//創建一個adjacency graph(width) 
	}
	dijkstra(0,lategraph,building);
	dijkstra_width(0,widthgraph,building);
	for(int i=1;i<building;i++)
	{
		cout<<i<<" ";
		if(d[i]!=9999)
			cout<<d[i]<<" "<<w[i]<<endl;
		else
			cout<<"inf "<<w[i]<<endl;
	}
	
	return 0;
}


