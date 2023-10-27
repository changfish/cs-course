#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include<Windows.h>
using namespace std;


//delta x = dir[3 + dir[n]*2 + 1], delta y = dir[3 + dir[n]*2 + 2]
const int dir[32] = {0,1,2,3,4,5,6,7,-1,0,1,0,0,-1,0,1,-1,-1,1,-1,-1,1,1,1};	//top down lift right , (top x,y), (down x,y),...


int m,n;	//the maze size


//to store node
vector< vector< vector< pair<int,int> > > > graph;	//use vector to store maze data and use map to store nearby node
//to store initial and final point
pair<int,int> start,end;

map< pair<int,int>,vector< pair<int,int> > >ans;
map< pair<int,int>,int> node;

vector< pair<int,int> > min_path(vector< pair<int,int> > a,vector< pair<int,int> > b){
	if(a.size()<b.size())	return a;
	else return b;
}

int next_x,next_y;
void delete_path(int x,int y){
	vector< pair<int,int> > ::iterator it;
	it = graph[next_y][next_x].begin();
	while(it->first != x || it->second != y){
		it++;
	}
	graph[next_y][next_x].erase(it);
}

queue< pair<int,int> >q;
void BFS(int x,int y){
	node[make_pair(x,y)]=1;
	int sz=q.size();
	for(int i=0;i<graph[y][x].size();i++){
		next_x = graph[y][x][i].first,next_y = graph[y][x][i].second;
		vector< pair<int,int> > tem = ans[make_pair(x,y)];
		tem.push_back(make_pair(x,y));
		if(ans[make_pair(next_x,next_y)].size()){
			ans[make_pair(next_x,next_y)] = min_path(tem,ans[make_pair(next_x,next_y)]);
		}else{
			ans[make_pair(next_x,next_y)] = tem;	
		}
		delete_path(x,y);
		q.push(make_pair(next_x,next_y));
	}
	q.pop();
	pair<int,int> p = q.front();
	if(!node[make_pair(p.first,p.second)]){
		BFS(p.first,p.second);
	}
}



int main() {
	int sur_x,sur_y;
	//initial color is white
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	cin>>m>>n;
	int maze[m][n];	//store maze
	cout<<"the maze is:\n";
		
	//fectch maze
	for(int i=0;i<m;i++){
		vector< vector< pair<int,int> > > tem_i;
		graph.push_back(tem_i);
		for(int j=0;j<n;j++){
			node[make_pair(j,i)]=0;
			//input the maze data
			cin>>maze[i][j];
			vector< pair<int,int> > tem_f;
			graph[i].push_back(tem_f);
			if(!maze[i][j]){
				if(!j) start = make_pair(j,i); //the initial point alwas be lift side
				if((j==n-1 || i==m-1 || !i))	end = make_pair(j,i);	//set the final point
				for(int k=0;k<4;k+=2){
					int sur_x = j+dir[7 + dir[k]*2 + 2], sur_y = i+dir[7 + dir[k]*2 + 1];
					if(sur_x<n&&sur_x>=0 && sur_y>=0 && !maze[sur_y][sur_x]){
						graph[i][j].push_back(make_pair(sur_x,sur_y));	//order:up(y up) lift down(y down) right(algorithm cause)
						graph[sur_y][sur_x].push_back(make_pair(j,i));	
					}
				}
			}
		}
	}
	q.push(make_pair(start.first,start.second));
	BFS(start.first,start.second);
	cout<<"------------------\n";
	cout<<"the result is:\n";
//	for(int i=0;i<m;i++){
//		for(int j=0;j<n;j++){
//			if(ans[make_pair(j,i)].size()){
//			printf("(%d,%d)=>",j,i);
//				for(int k=0;k<ans[make_pair(j,i)].size();k++){
//					printf("(%d,%d) ",ans[make_pair(j,i)][k].first,ans[make_pair(j,i)][k].second);
//				}
//				cout<<endl;
//			}
//		}
//	}
	for(int i=0;i<ans[make_pair(end.first,end.second)].size();i++){
		maze[ans[make_pair(end.first,end.second)][i].second][ans[make_pair(end.first,end.second)][i].first]=2;
	}
	maze[end.second][end.first]=2;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(maze[i][j]==2){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
				cout<<'*';
			}
			else{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
				cout<<maze[i][j];
			}
			cout<<' ';
		}
		cout<<endl;
	} 	
}
