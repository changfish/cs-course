#include <iostream>
using namespace std; 

int main(){
	for(int i=9;i>=1;i--){
		for(int j=9;j>=1;j--){
			printf("%dx%d=%d\t",j,i,i*j);
		}
		printf("\n");
	}
}


