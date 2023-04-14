#include <iostream>
using namespace std;

const float pi = 3.14159;

class circle{	//use class for realize object
	public:
		int radius;
		float Diameter(){	//public function
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
	circle A;	//create a object of circle
	cout<<"Input radius:";
	while(cin>>r){		//keep typing until ctrl+z
		A.radius = r;	//public var
		cout<<"Diameter = "<<A.Diameter()<<" units\n";	//call public functon
		cout<<"Circumference = "<<A.Circumference()<<" units\n";
		cout<<"Area = "<<A.Area()<<" sq. units\n";
		cout<<"Input radius:";
	}
}
