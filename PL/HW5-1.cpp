#include <iostream>
using namespace std;

const float pi = 3.14159;

int main(){
	int r;
	cout<<"Input radius:";
	while(cin>>r){
		cout<<"Diameter = "<<2*r<<" units\n";
		cout<<"Diameter = "<<2*r*pi<<" units\n";
		cout<<"Area = "<<r*r*pi<<" sq. units\n";
		cout<<"Input radius:";
	}
}
