#include <iostream>
using namespace std; 

int main(){
	for(int i=1;i<=9;i++){
		for(int j=9;j>=1;j--){
			printf("%dx%d=%d\t",j,i,i*j);
		}
		printf("\n");
	}
}
