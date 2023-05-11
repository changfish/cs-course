#include <iostream>
using namespace std;

#define ll long long

//stack and recursion
ll ans(ll n){
	int sum=0;
	if(!n)	//n=0
		return n;//a1
	else
		sum += ans(n/10)+n%10;	//(a1a2a3a4...an-1)+an
	return sum;
}

int main(){
	ll n;
	cout<<"Input number: ";
	cin>>n;
	cout<<"Sum of digits: ";
	cout<<ans(n);
}
