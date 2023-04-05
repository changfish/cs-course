#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool upper(int a,int b){	//sort by upper
	return a<b;
}
bool lower(int a,int b){ 	//sort by lower
	return a>b;
}

int main(){
	cin.tie(0);
	string cmd;	//我很抱歉 我不知道step是什麼意思
	int tem,n=4;//tem用來輸入，然後丟進去vector
	vector<int>	 v;
	cin>>cmd;
	while(n--&&cin>>tem){	//理論上可以輸入至ctrl+z(結束)，但這邊用4個資料來演示 
		v.push_back(tem);
	}
	if(cmd == "lower")					//我還是很抱歉 我看不懂step或是我就在瞎搞 
		sort(v.begin(),v.end(),lower);	//STL sort
	else
		sort(v.begin(),v.end(),upper);	//using iterator to operate
	
	printf("Celsius\t\t|\tFahrenheit\n");
 	for(int i=0;i<4;i++){
 		for(int j=0;j<9;j++)
			cout<<"-";
	}
	for(vector<int>::iterator it = v.begin();it!=v.end();it++)
		printf("\n%d\t\t|\t%.2f",*it,(*it)*1.8+32.0);
}
