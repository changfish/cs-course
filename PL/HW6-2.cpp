#include <iostream>
#define ll long long

ll pow(int x,int y){
	ll sum=1;
	for(int i=0;i<y;i++)	sum*=x;
	return sum;	
}

int main(){
	printf("\tN");
	for(int i=3;i<=9;i+=2){
		printf("\t\tN^%d",i);
	}
	printf("\n");
	for(int i=1;i<=10;i++){
		for(int j=1;j<=9;j+=2){
			printf("%9ld\t",pow(i,j));
		}
		printf("\n");
	}
}

