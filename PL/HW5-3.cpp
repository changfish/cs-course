#include <iostream>
using namespace std;

int main(){
	float w,h,BMI;
	cout<<"Enter your weight in kilograms： ";
	while(cin>>w){		//cin util ctrl+z
		cout<<"Enter your height in meter： ";
		cin>>h;
		BMI = w/(h*h);
		cout<<"Your BMI is: "<<BMI<<endl<<"You are ";
		if(BMI<18.5)	cout<<"Underweight";		//nested if and let it be clean
		else if(BMI<=24.9)	cout<<"Normal weight";
		else if(BMI<=29.9)	cout<<"Overweight";
		else cout<<"Obese";
		cout<<"\nEnter your weight in kilograms： ";
	}
}
