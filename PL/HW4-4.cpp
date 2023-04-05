#include <iostream>
#include <algorithm>
using namespace std;


int main(){
	string num,renum;
	cout<<"Enter any number: ";
	cin>>num;
	renum = num;	//將num複製給renum 
	reverse(renum.begin(),renum.end());	//將renum反轉，此時renum即num的反轉 
	if(num == renum)  //一個字串 反轉後跟原來一樣 那就是迴文
		cout<<"Given number is a palindromic number";
	else
		cout<<"Given number is not a palindromic number";
}
