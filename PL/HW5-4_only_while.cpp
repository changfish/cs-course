#include <iostream>
using namespace std;

int main(){
	int l=1,r=100,n=100,ans=0;
	while(l<r){
		ans+=(l+r)*n/2;	//sum formular
		l++;
		r--;
		n-=2;
	}
	cout<<"The total is "<<ans;
}
