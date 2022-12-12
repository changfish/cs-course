#include <iostream>
using namespace std;

const int maxsize = 7;	//陣列大小設7 
int count=1;

void printarray(int A[]){
	cout<<"round "<<count++<<":";
	for(int i=0;i<maxsize;i++){
		cout<<"\t"<<A[i];
	}
	cout<<endl;
}
int test(int A[],int recall[],int l,int r){					//簡單判斷是否提早排序完 如果是就回傳 0 不是就回傳 1
	for(int i=l;i<r;i++){
			if(A[i]!=recall[i])	return 1;		//只要排序前和排序後長一樣 那就代表提早排序完了 
	}
	return 0;		
}

void rbubblesort(int* ,int, int);		//int* 傳的是pointer 
void lbubblesort(int* ,int, int);

int main(){
	int A[maxsize];
	for(int i=0;i<maxsize;i++)
		cin>>A[i];		
	rbubblesort(A,0,maxsize);
	printarray(A);
}

void rbubblesort(int A[], int l, int r){		//向右的bubble sort
	int recall[maxsize];
	if(l>=r)	return;				//最左大於或等於最右 就結束 且不回傳值 
	for(int i=l;i<r-1;i++){
		recall[i]=A[i];
		if(A[i]>A[i+1]){
			A[i] ^= A[i+1];		//從這裡 
			A[i+1] ^= A[i];
			A[i] ^= A[i+1];		//到這裡 是位元運算 就是讓A[i]和A[i+1]交換而已(位元運算跑比較快) 
		}
	}
	if(test(A,recall,l,r))			//還沒排序完 才要排序 
		lbubblesort(A,l,r-1);
}

void lbubblesort(int A[], int l, int r){		//向左的bubble sort 
	int recall[maxsize];
	if(l>=r)	return;
	for(int i=r-1;i>0;i--){
		recall[i]=A[i];
		if(A[i]<A[i-1]){
			A[i] ^= A[i-1];		//從這裡 
			A[i-1] ^= A[i];
			A[i] ^= A[i-1];		//到這裡 是位元運算 就是讓A[i]和A[i-1]交換而已(位元運算跑比較快) 
		}
	}
	printarray(A);
	if(test(A,recall,l,r))
		rbubblesort(A,l+1,r);
}
