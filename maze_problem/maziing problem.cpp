#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//delta x = dir[3 + dir[n]*2 + 1], delta y = dir[3 + dir[n]*2 + 2]
const int dir[12] = {0,1,2,3,-1,0,1,0,0,-1,0,1};	//top down lift right , (top x,y), (down x,y),...


int m,n;	//the maze size


//to store node
vector< vector< vector< pair<int,int> > > > graph;	//use vector to store map data and use map to store nearby node
//to store initial and final point
pair<int,int> start,end;

//這邊要寫dir trans func 或是直接用dir來表示 

vector< pair<int,int> > ans;
vector< pair<int,int> >::iterator it;

int find(int x,int y){
	it = ans.end()-1;
	while(it-ans.begin()>=0){
		if(x==it->first && y==it->second)	return it-ans.begin();
		it--;
	}
	return -1;	
}



void delete_path(int x,int y,int next_x,int next_y){
	vector< pair<int,int> > ::iterator it;
	it = graph[next_y][next_x].begin();
	while(it->first != x && it->second != y){
		it++;
	}
	graph[next_y][next_x].erase(it);
}

int flag = 1;

int next_x,next_y;

void DFS(int x,int y){
	ans.push_back(make_pair(x,y));
	
	if(flag){
		if(graph[y][x].size()==1 &&x){
			printf("這裡是死路%d,%d=>",x,y);
			for(int i=0;i<ans.size();i++){
				printf("(%d,%d)",ans[i].first,ans[i].second);
			}
			cout<<endl;
			it = ans.end()-1;
			while(graph[it->second][it->first].size()<=2){
				it--;
				ans.pop_back();
//				cout<<ans.size()<<endl;
			}
			printf("更新後：",x,y);
			for(int i=0;i<ans.size();i++){
				printf("(%d,%d)",ans[i].first,ans[i].second);
			}
			cout<<endl;
		}
		else{
			for(int i=0;i<graph[y][x].size();i++){
				next_x = graph[y][x][i].first,next_y = graph[y][x][i].second;
				if(find(next_x,next_y)==-1&&flag){	//only passing havn't been(ul4e93)
					if(next_x==end.first&&next_y==end.second)	flag=0;
					DFS(next_x,next_y);
				}
			}
		}
		if(!x)	DFS(graph[y][x][0].first,graph[y][x][0].second);
	}
}



//還沒把連通的道路串起來(還沒實作next)，需要先寫好dir transform function 

int main() {
	cin>>m>>n;
	int maze[m][n];	//store maze
	// 要初始化maze to 1 
	cout<<"the maze is:\n";
		
	//fectch maze(要邊輸入 邊fetch to node)
	for(int i=0;i<m;i++){
		vector< vector< pair<int,int> > > tem_i;
		graph.push_back(tem_i);
		for(int j=0;j<n;j++){
			//input the maze data
			cin>>maze[i][j];
			vector< pair<int,int> > tem_f;
			graph[i].push_back(tem_f);
			if(!maze[i][j]){
				if(!j) start = make_pair(j,i); //the initial point alwas be lift side
				if((j==n-1 || i==m-1 || !i))	end = make_pair(j,i);	//set the final point
				for(int k=0;k<4;k+=2){
					int sur_x = j+dir[3 + dir[k]*2 + 2], sur_y = i+dir[3 + dir[k]*2 + 1];
					if(sur_x>=0 && sur_y>=0 && !maze[sur_y][sur_x]){
						graph[i][j].push_back(make_pair(sur_x,sur_y));	//order:top lift down right(algorithm cause)
						graph[sur_y][sur_x].push_back(make_pair(j,i));	
					}
				}
			}
		}
	}
	cout<<"------------------\n";
	cout<<"the result is:\n";
//	show link
//	for(int i=0;i<m;i++){
//		for(int j=0;j<n;j++){
//			if(graph[i][j].size()){
//				cout<<"x,y = "<<j<<","<<i<<" =>";
//				for(int k=0;k<graph[i][j].size();k++){
//					cout<<"("<<graph[i][j][k].first<<","<<graph[i][j][k].second<<") ";
//				}
//				cout<<endl;
//			}
//		}
//		cout<<endl;
//	}
	DFS(start.first,start.second);
	ans.push_back(end);
	for(int i=0;i<ans.size();i++){
		maze[ans[i].second][ans[i].first] = 2;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(maze[i][j]==2)	cout<<'*';
			else cout<<maze[i][j];
			cout<<' ';
		}
		cout<<endl;
	} 
	
	
}
