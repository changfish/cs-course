#include <iostream>
using namespace std;

const float pi = 3.14159;

class circle{
	public:
		int radius;
		float Diameter(){
			return 2*radius;
		}
		float Circumference(){
			return 2*radius*pi;
		}
		float Area(){
			return radius*radius*pi;
		}
};

int main(){
	int r;
	circle A;
	cout<<"Input radius:";
	while(cin>>r){
		A.radius = r;
		cout<<"Diameter = "<<A.Diameter()<<" units\n";
		cout<<"Circumference = "<<A.Circumference()<<" units\n";
		cout<<"Area = "<<A.Area()<<" sq. units\n";
		cout<<"Input radius:";
	}
}
