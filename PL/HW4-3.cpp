#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
	int lower,upper,step;
	cout<<"A program print the conversion of Celsius-Fahrenheit\n\n";
	cout<<"lower value:\t";
	cin>>lower;
	cout<<"upper value:\t";
	cin>>upper;
	cout<<"step value:\t";
	cin>>step;
	cout<<"Celsius\t\t|\tFahrenheit\n";
	for(int i=0;i<4;i++){
 		for(int j=0;j<9;j++)
			cout<<"-";
	}
	for(int i=lower;i<=upper;i+=step){
		printf("\n%d\t\t|\t%.2f",i,i*1.8+32.0);
	}
}
