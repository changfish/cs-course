#include <iostream>
using namespace std;

const float minn = 0.00001;

int dp[10];
int DP(int i){
	if(dp[i])	return dp[i];
	else{
		dp[i] = DP(i-1)*i;
		return dp[i];
	}
}
float pow(float x,int y){
	float ans=1;
	for(int i=0;i<y;i++){
		ans*=x;
	}
	return ans;
}
int main(){
	for(int i=0;i<10;i++)	dp[i]=0;	//reset the array
	dp[0]=1;
	dp[1]=1;
	float x,e=1,lnn=0,lnp=0,tem=1;	//e is e^x(and start to 1),lnn is ln(1-x),lnp is ln(1+x)
	cin>>x;
	int i=1;	//e's Maclaurin series start to 1
	while(tem>minn){
		tem = pow(x,i)/DP(i);
		e+=tem;
		i++;
	}
	cout<<"e^"<<x<<" \t\t= "<<e<<endl;
	tem = 1,i = 1;	//avoid stoping program
	while(tem>minn){
		tem = pow(x,i)/i;
		lnn-=tem;
		i++;
	}
	cout<<"ln(1-"<<x<<") \t= "<<lnn<<endl;
	tem = 1,i = 1;
	while(tem>minn){
		if((i+1)&1)	//(i+1) and 1 等價 (i+1) mod 2
			tem = (-1)*pow(x,i)/i;
		else
			tem = pow(x,i)/i;
		lnp+=tem;
		i++;
		tem = tem>0? tem:(-1)*tem;
	}
	cout<<"ln(1+"<<x<<")\t= "<<lnp;
}
