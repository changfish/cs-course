#include <iostream>
using namespace std;

int main(){
	int l=1,r=100,ans=0;
	while(l<r){
		for(int i=l;i<=r;i++){
			ans+=i;
		}
		l++;
		r--;
	}
	cout<<"The total is "<<ans;
}
