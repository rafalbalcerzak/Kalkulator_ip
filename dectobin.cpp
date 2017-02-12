#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <typeinfo>
int ip;
int ipc;
int x = 0;
std::string bin="00000000";
using namespace std;
int main(){
	
	cout<<"Podaj ip"<<endl;
	cin>>ip;
	while(ip > 0){
		
		if (ip % 2 !=0){
			bin.replace(x,1,"1");
		}
		ipc = ip/2;
		ip =ipc;
		x ++;	
	}
	for(int i=7; i>=0; i--){
		cout<<bin[i];
	}
}
