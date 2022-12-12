#include <iostream>
using namespace std;
int a[7];
int main(){
	for(int i=0;i<7;i++){
		cin>>a[i];
	}
	for(int i=6;i>0;i--){
		for(int j=0;j<i;j++){
			if(a[j]>a[j+1]){
				int tmp=a[j];
					a[j]=a[j+1];
					a[j+1]=tmp;
	for(int i=0;i<7;i++){
		cout<<a[i]<<" ";
	    }
	for(int i=0;i<6;i++){
		for(int j=6;j>i;j--){
			if(a[j]<a[j-1]){
				int tmp=a[j];
					a[j]=a[j-1];
					a[j-1]=tmp;
		for(int i=0;i<7;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
			}
			
		}
	}
}
