#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <typeinfo>

int ipaddress[3] = {};

int input_fnc(std::string ip)
{
	std::vector<int> vect;
	std::stringstream ss(ip);

    int i;
	//dzieli stringa na elementy oddzielone ,, . ''
    while (ss >> i)
    {
        vect.push_back(i);

        if (ss.peek() == '.')
            ss.ignore();
    }
	
 	ipaddress[0] = vect.at(0);
	ipaddress[1] = vect.at(1);
	ipaddress[2] = vect.at(2);
	ipaddress[3] = vect.at(3);
	
	std::cout <<"Oktet 1= "<< ipaddress[0] << std::endl;
    std::cout <<"Oktet 2= "<< ipaddress[1] << std::endl;
    std::cout <<"Oktet 3= "<< ipaddress[2] << std::endl;
    std::cout <<"Oktet 4= "<< ipaddress[3] << std::endl;
    	    
}

int DecToBin_fnc(int oktet)
{
	for(int number=1; number<=4; number ++){
		if (oktet % 2 == 0){
			std::cout<<"0";
		}
		else{
			std::cout<<"1";
		}
	}

}

int main()
{	
	std::cout<<"Podaj adres IP: ";
	std::string ip;
	std::cin>>ip;
	
	input_fnc(ip);
	
	std::cout<<ipaddress[0]<<'.'<<ipaddress[1]<<'.'<<ipaddress[2]<<'.'<<ipaddress[3]<<std::endl;
	
	DecToBin_fnc(ipaddress[0]);

}











