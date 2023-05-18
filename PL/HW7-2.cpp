#include <iostream>
#include <vector>

using namespace std;

vector<int> stoi(string s){		//separate num by space  
	int i=0,tem=0;
	vector<int> ans;
	while(i <= s.size() ){
		if(s[i]==' ' || i==s.size()){
			ans.push_back(tem);
			tem=0;
			i++;
		}
		tem*=10;
		tem+= int(s[i]-'0');
		i++;
	}
	return ans;		//return a vector
}

int main(){
	string tem;
	vector< vector<int> > v;
	cout<<"input the matrix until ctrl+z\n";
	while(getline(cin,tem)){		//input until '^Z'
		v.push_back(stoi(tem));		//push a list by trans from string
	}
	for(int i=0;i<v[0].size();i++){		//trans
		for(int j=0;j<v.size();j++){
			cout<<v[j][i]<<" ";
		}
		cout<<endl;
	}
}




