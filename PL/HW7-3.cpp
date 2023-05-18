#include <iostream>
#include <cmath>

using namespace std;


int main(){
	float a,b,c,s;
	cout<<"Enter the length of three sides of triangle\n";
	cin>>a>>b>>c;
	cout<<"Area of trangle : ";
	s = a+b+c;
	s/=2.0;		//half
	cout<< sqrt(s * (s-a) * (s-b) * (s-c));		//Heron¡¦s formula
}




