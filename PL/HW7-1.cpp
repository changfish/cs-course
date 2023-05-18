#include <iostream>
#include <vector>
using namespace std;

int bit=0;	//record the log(n)

int pow(int x,int y){
	int sum=1;
	while(y--)	sum*=x;
	return sum;
}

int Armstrong(int n){
	int tem=n,sum=0;
	while(tem){
		sum+=pow(tem%10,bit);
		tem/=10;
	}
	return sum==n;
}	

int main(){
	int l,u,tem;	//l is  lower, u is upper, lower be stored by tem
	vector<int> ans;
	cout<<"Input lower limit: ";
	cin>>l;
	tem = l;
	cout<<"Input upper limit: ";
	cin>>u; 
	while(tem){		//To record log(lower)
		bit++;
		tem/=10;
	}
	tem = pow(10,bit);
	cout<<"Armstrong numbers between "<<l<<" to "<<u<<" are: " ;
	while(l<=u){
		if(l >= tem){		//bit+=1 as soon as the next lv 
			bit++;
			tem = pow(10,bit);
		}
		if(Armstrong(l)) ans.push_back(l);	//stroed by STL's vector
		l++;
	}
	for(vector<int>::iterator it=ans.begin();it!=ans.end()-1;it++){
		cout<<*it<<",";	//use iterator to show
	}
	cout<<*(ans.end()-1);	//',' can't be demostrate at end of vector
}




