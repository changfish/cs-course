#include<iostream>
using namespace std;


int main(){
	int N,x,y;	// odd;
	cin>>N;
	int A[N+1][N+1];	//從1 1當作最左上	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			A[i][j]=0;			//歸零糕 
		}
	}
	x=N/2+1;		//x的位置初始化 
	y=1;			//y的位置初始化
	for(int i=1;i<=N*N;i++){
		A[y][x]=i;
		x++;			//向右一格									
		if(x>N)	x=1;	//超過範圍就變成第一格 
		y--;			//向上一格(y-1向上 y+1向下)	座標在第四象限 
		if(!y)	y=N;	//y如果等於0 也就是超過範圍就讓y到最底下 
		while(A[y][x]){	//如果那格有住人了 就做底下那些操作 
			if(y==N)	y=2; //因為要先回到原本的位置 又要向下一格 所以超過範圍 就要設y=2 
			else y+=2;		//同理 回到位置+向下一格 y = y+2 
			x--;			//x只要往回就好 
			if(!x)	x=N;	//超過範圍就 N
		}
		
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout<<A[i][j]<<"\t";
		}
		cout<<endl;
	}
}
