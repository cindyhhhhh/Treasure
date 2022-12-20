#include <stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <stdint.h>
#include <iostream> 
#include <inttypes.h>
#include<string.h>
#include<vector>
#include <list> 
#include <stack> 

using namespace std;

struct edge
{
	long long v;
	long long w;
};

void createEdge(long long a, long long b, long long c, vector<vector<edge> >&graph)
{
	edge temp;

	temp.v = b-1;
	temp.w = c;//value of edge

    graph[a-1].push_back(temp);
}

void dfs1(long long u, vector<long long>&visit, stack<long long>&Stack, vector<vector<edge> >&graph)
{
	visit[u] = 1;

	if(graph[u].size() > 0)
	{	
		for(long long j = 0; j < graph[u].size(); j++)
		{
			if(visit[graph[u][j].v] == 0)
			{
				dfs1(graph[u][j].v, visit, Stack, graph);
			}
		}
	}

	Stack.push(u);
}

void dfs2(long long u, vector<long long>&visit, stack<long long>&Stack, vector<vector<edge> >&graphT, long long&W, vector<long long>&cityw, vector<long long>&group, long long&node, vector<vector<edge> >&graphDAG)
{
	// if(visit2[u] != 1)
	// {
	// 	W += cityw[u];
	// }
	// else
	// {
	// 	return;
	// }
	visit[u] = 1;
	W += cityw[u];
	group[u] = node;

	if(graphT[u].size() > 0)
	{
		for(long long j = 0; j < graphT[u].size(); j++)
		{
			if(visit[graphT[u][j].v] == 0)
			{
				W += graphT[u][j].w;
				dfs2(graphT[u][j].v, visit, Stack, graphT, W, cityw, group, node, graphDAG);
			}
			else
			{
				edge temp;
				temp.v = group[u]-1;
				temp.w = graphT[u][j].w;
				if(group[graphT[u][j].v]-1 < group[u]-1)
				{
					graphDAG[group[graphT[u][j].v]-1].push_back(temp);
				}
				else if (group[graphT[u][j].v]-1 == group[u]-1)
				{
					W += graphT[u][j].w;
				}
			}
		}
	}
}

int main()
{
	long long N,M,u,v,s,w;
	cin >> N >> M;

	vector<long long> cityw;
	vector<vector<edge> > graph(N);
	vector<vector<edge> > graphT(N);

	stack<long long> Stack;
	vector<long long> visit(N,0);
	// vector<long long> visit2(N,0);
	vector<long long> group(N,-1);
	vector<long long> weight;

	for(long long i = 0; i < N; i++)
	{
		cin >> s;
		cityw.push_back(s);
	}
	for(long long i = 0; i < M; i++)
	{
		cin >> u >> v >> w;
		createEdge(u, v, w, graph);
		createEdge(v, u, w, graphT);
	}

	for(long long i = 0; i < N; i++)
	{
		if(visit[i] == 0)
		{
			dfs1(i, visit, Stack, graph);
		}
	}

	visit.assign(N,0);
	vector<vector<edge> > graphDAG(N);

	long long node = 1;
	while (Stack.empty() == false) 
	{ 
		// Pop a vertex from stack 
		long long v = Stack.top(); 
		Stack.pop(); 
		long long W = 0;
		// Print Strongly connected component of the popped vertex 
		if (visit[v] == 0) 
		{
			dfs2(v, visit, Stack, graphT, W, cityw, group, node, graphDAG);
			node++;
			weight.push_back(W);
			// visit = visit2;
		}
	} 

	// for(long long i = 0; i < graph.size(); i++)
	// {
	// 	if(graph[i].size() > 0)
	// 	{
	// 		for(long long j = 0; j < graph[i].size(); j++)
	// 		{
	// 			if(group[i] != group[graph[i][j].v])
	// 			{
	// 				createEdge(group[i], group[graph[i][j].v], graph[i][j].w, graphDAG);
	// 			}
	// 		}
	// 	}
	// }


	// vector<vector<edge> > graphDAG(node-1);

	// for(long long i = 0; i < graph.size(); i++)
	// {
	// 	if(graph[i].size() > 0)
	// 	{
	// 		for(long long j = 0; j < graph[i].size(); j++)
	// 		{
	// 			if(group[i] != group[graph[i][j].v])
	// 			{
	// 				createEdge(group[i], group[graph[i][j].v], graph[i][j].w, graphDAG);
	// 			}
	// 		}
	// 	}
	// }

	long long max = 0;
	vector<long long> ans(node-1, -1);
	for(long long i = 0; i < weight.size(); i++)
	{
		ans[i] = weight[i];
		if(ans[i] > max)
		{
			max = ans[i];
		}
	}


	for(long long i = 0; i < graphDAG.size(); i++)
	{
		if(graphDAG[i].size() > 0)
		{
			for(long long j = 0; j < graphDAG[i].size(); j++)
			{
				if(ans[graphDAG[i][j].v] < ans[i] + graphDAG[i][j].w + weight[graphDAG[i][j].v])
				{
					ans[graphDAG[i][j].v] = ans[i] + graphDAG[i][j].w + weight[graphDAG[i][j].v];
				}
				if(ans[graphDAG[i][j].v] > max)
				{
					max = ans[graphDAG[i][j].v];
				}
			}
		}
	}

	// for(long long i = 0; i < group.size(); i++)
	// {
	// 	printf("%lld ", group[i]); 
	// }

	// for(long long i = 0; i < weight.size(); i++)
	// {
	// 	printf("%lld ", weight[i]); 
	// }

	// sort(ans.begin(),ans.end());

	// for(long long i = 0; i < ans.size(); i++)
	// {
	// 	printf("%lld ", ans[i]);  
	// }

	printf("%lld ", max); 
	

	return 0;


}