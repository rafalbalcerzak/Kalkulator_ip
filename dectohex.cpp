#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <typeinfo>


int main(){
	int oktet = 192;
	int oktetc;
	int x=0;
	std::string hex;
	while (oktet >0){
		if (oktet % 16== 0){
			hex.replace(x,1,"0");
		}
		if (oktet % 16== 1){
			hex.replace(x,1,"1");
		}
		if (oktet % 16== 2){
			hex.replace(x,1,"2");
		}
		if (oktet % 16== 3){
			hex.replace(x,1,"3");
		}
		if (oktet % 16== 4){
			hex.replace(x,1,"4");
		}
		if (oktet % 16== 5){
			hex.replace(x,1,"5");
		}
		if (oktet % 16== 6){
			hex.replace(x,1,"6");
		}
		if (oktet % 16== 7){
			hex.replace(x,1,"7");
		}
		if (oktet % 16== 8){
			hex.replace(x,1,"8");
		}
		if (oktet % 16== 9){
			hex.replace(x,1,"9");
		}
		if (oktet % 16== 10){
			hex.replace(x,1,"A");
		}
		if (oktet % 16== 11){
			hex.replace(x,1,"B");
		}
		if (oktet % 16== 12){
			hex.replace(x,1,"C");
		}
		if (oktet % 16== 13){
			hex.replace(x,1,"D");
		}
		if (oktet % 16== 14){
			hex.replace(x,1,"E");
		}
		if (oktet % 16== 15){
			hex.replace(x,1,"F");
		}
		oktetc = oktet/16;
		oktet = oktetc;
		x++;
		
	}
	int dlugosc = hex.length();
	int i = dlugosc -1;
	
	for(i; i>=0; i--){
		std::cout<<hex[i];
	}
}



