#include <iostream>
using namespace std;
 
int main(){
	int x,y;
	cin>>x>>y;	//input
	cout<<"X\tY\tX+Y\tX-Y\tX*Y\n";
 	for(int i=0;i<4;i++){
 		for(int j=0;j<9;j++)
 			cout<<"-";
 	}
 	cout<<endl;
 	for(int i=x;i<=x+4;i++){
 		printf("%d\t%d\t%d\t%d\t%d\n",i,y,i+y,i-y,i*y);
 		y++;
	}
 }
 
