#include <iostream>
#include <map>
using namespace std;
int main(){
 	int a[3];
 	/*原本想優化IO*/
 //	cin.tie(0);
 //	ios_base::sync_with_stdio(false);
 	cout<<"Input three sides of triangle: ";
 	while(cin>>a[0]>>a[1]>>a[2]){
 		map<int,int> ans;
 		for(int i=0;i<3;i++) ans[a[i]]++;	//利用STL的map當作hash table 
 		cout<<"This is an ";
 		switch(ans.size()){		//ans的size就是邊長種類的數量 
 			case 1:
 				cout<<"Equilateral";
 				break;
 			case 2:
 				cout<<"Isosceles";
 				break;
 			case 3:
 				cout<<"Scalene";
 				break;
 		}
 		cout<<" Triangle\nInput three sides of triangle: ";
 	}
 }
