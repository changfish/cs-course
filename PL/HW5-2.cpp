#include <iostream>
using namespace std;

#define ll long long	//simple slove big num

ll pow(ll a, int n){
	if(n==1)
		return a;
	else
		return pow(a,n-1)*a;	//recursive
}

int main(){
	int a,n;
	cout<<"Input base number:";
	while(cin>>a){	//keep typing until ztrl+z
		cout<<"Input exponet:";
		cin>>n;
		cout<<a<<"^"<<n<<" = "<<pow(a,n)<<endl;
		cout<<"Input base number:";	//loop again
	}
}
