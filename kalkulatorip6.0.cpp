#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <typeinfo>
//zmienne globalne
int ipaddress[4] = {};
int maska_split[4]={};
int binip[4]={};
int oktetlicz=1;

std::string oktetbin1="00000000";
std::string oktetbin2="00000000";
std::string oktetbin3="00000000";
std::string oktetbin4="00000000";

//funkcja rysujaca pasek 
int pasek_fnc(){
	
	std::cout << std::string(40,* "=") << std::endl;
		
}

//funkcja dzieli ip na oktety i nadpisuje zmienn¹ globaln¹
int inputip_fnc(std::string ip)
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
	
	//nadpisuje zmienn¹ globaln¹ wartosciami wpisanymi przez user'a        
 	ipaddress[0] = vect.at(0);
	ipaddress[1] = vect.at(1);
	ipaddress[2] = vect.at(2);
	ipaddress[3] = vect.at(3);
}
int inputmaska_fnc(std::string maska)
{
	std::vector<int> vect;
	std::stringstream ss(maska);

    int i;
	//dzieli stringa na elementy oddzielone ,, . ''
    while (ss >> i)
    {
        vect.push_back(i);

        if (ss.peek() == '.')
            ss.ignore();
    }
	
	//nadpisuje zmienn¹ globaln¹ wartosciami wpisanymi przez user'a        
  	maska_split[0] = vect.at(0);
	maska_split[1] = vect.at(1);
	maska_split[2] = vect.at(2);
	maska_split[3] = vect.at(3);    
}

//funkcja sprawdzajaca poprawnoœæ adresu ip
int correctip_fnc(int oktet1, int oktet2, int oktet3, int oktet4)
{ 
	std::cout <<"Poprawnosc zapisu IP:" <<std::endl;
	if(ipaddress[0] > 255 || ipaddress[0]<0 || ipaddress[1] > 255 || ipaddress[1]<0 || ipaddress[2] > 255 || ipaddress[2]<0 || ipaddress[3] > 255 || ipaddress[3]<0){
		if(ipaddress[0] > 255 || ipaddress[0]<0){
			std::cout<<"1 oktet bledny"<< std::endl;	
		}
		if(ipaddress[1] > 255 || ipaddress[1]<0){
			std::cout<<"2 oktet bledny"<< std::endl;
		}
		if(ipaddress[2] > 255 || ipaddress[2]<0){
			std::cout<<"3 oktet bledny"<< std::endl;
		}
		if(ipaddress[3] > 255 || ipaddress[3]<0){
			std::cout<<"4 oktet bledny"<< std::endl;
		}
		std::cout<<"Zamykam program"<<std::endl;
		exit(0);
	}

	else{
		std::cout<<"Wszystkie oktety poprawne"<<std::endl;
		
		}		
	
}

//funkcja sprawdzajaca poprawnoœæ maski
int correctmaska_fnc(int oktet1, int oktet2, int oktet3, int oktet4)
{ 
	int blad=0;
	std::cout <<"Poprawnosc zapisu maski:" <<std::endl;
	if(oktet1 == 128 ||oktet1 ==192 ||oktet1 ==224 ||oktet1 ==240 ||oktet1 ==248 ||oktet1 ==252 ||oktet1 ==254 ||oktet1 ==255 ||oktet1 == 0){
	}
	else{
		std::cout<<"1 oktet bledny"<<std::endl;
		blad ++;
	}
	if(oktet2 == 128 ||oktet2 ==192 ||oktet2 ==224 ||oktet2 ==240 ||oktet2 ==248 ||oktet2 ==252 ||oktet2 ==254 ||oktet2 ==255 ||oktet2 == 0){
	}
	else{
		std::cout<<"2 oktet bledny"<<std::endl;
		blad ++;
	}
	if(oktet3 == 128 ||oktet3 ==192 ||oktet3 ==224 ||oktet3 ==240 ||oktet3 ==248 ||oktet3 ==252 ||oktet3 ==254 ||oktet3 ==255 ||oktet3 == 0){
	}
	else{
		std::cout<<"3 oktet bledny"<<std::endl;
		blad ++;
	}
	if(oktet4 == 128 ||oktet4 ==192 ||oktet4 ==224 ||oktet4 ==240 ||oktet4 ==248 ||oktet4 ==252 ||oktet4 ==254 ||oktet4 ==255 ||oktet4 == 0){
	}
	else{
		std::cout<<"4 oktet bledny"<<std::endl;
		blad ++;
	}
	if(oktet2 > oktet1){
		std::cout<<"oktet 2 wiekszy niz oktet 1"<<std::endl;
		blad++;
	}
	if(oktet3 > oktet2){
		std::cout<<"oktet 3 wiekszy niz oktet 2"<<std::endl;
		blad++;
	}
	if(oktet4 > oktet3){
		std::cout<<"oktet 4 wiekszy niz oktet 3"<<std::endl;
		blad++;
	}
	if(blad > 0){
		std::cout<<"Zamykam program"<<std::endl;
		exit(0);
	}
	else{
		std::cout<<"Maska poprawna"<<std::endl;
	}
}

//funkcja sprawdzania klas
int klasy_fnc(int a){
	
	std::cout << "Klasa adresu IP:" <<std::endl;
	if (a >=0 && a <127){
		std::cout <<"Klasa A"<<std::endl;	}
		
	else if (a >127 && a <192){
		std::cout <<"Klasa B"<<std::endl;	}
		
	else if (a >=192 && a <224){
		std::cout <<"Klasa C"<<std::endl;	}
		
	else if (a >=224 && a <240){
		std::cout <<"Klasa D"<<std::endl;	}
		
	else if (a >=240 && a <249){
		std::cout <<"Klasa E"<<std::endl;	}
		
	else if (a >=249 && a <256){
		std::cout <<"Klasa F"<<std::endl;	}
	
	else if (a ==127){
		std::cout<< "Petal zwrotna"<<std::endl;	}

	return 0;
}

//funkcja konwrtuj¹ca na sysytem binarny
int dectobin_fnc(int oktet)
{
	int ip;
	int x = 0;
	int y = 7;
	while(oktet > 0){
		
		if (oktet % 2 !=0){
			if(oktetlicz ==1){
				oktetbin1.replace(y,1,"1");
			}
			if(oktetlicz ==2){
				oktetbin2.replace(y,1,"1");
			}
			if(oktetlicz ==3){
				oktetbin3.replace(y,1,"1");
			}
			if(oktetlicz ==4){
				oktetbin4.replace(y,1,"1");
			}
		}
		ip = oktet/2;
		oktet=ip;
		x ++;	
		y --;
	}

	x=0;
	y=7;

	
	
}

//funkcja dec do hex
int dectohex_fnc(int oktet){
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



//funkcja dec do oct
int dectooct_fnc(int oktet){
	int oktetc;
	int x=0;
	std::string oct;
	while (oktet >0){
		if (oktet % 8== 0){
			oct.replace(x,1,"0");
		}
		if (oktet % 8== 1){
			oct.replace(x,1,"1");
		}
		if (oktet % 8== 2){
			oct.replace(x,1,"2");
		}
		if (oktet % 8== 3){
			oct.replace(x,1,"3");
		}
		if (oktet % 8== 4){
			oct.replace(x,1,"4");
		}
		if (oktet % 8== 5){
			oct.replace(x,1,"5");
		}
		if (oktet % 8== 6){
			oct.replace(x,1,"6");
		}
		if (oktet % 8== 7){
			oct.replace(x,1,"7");
		}
		oktetc = oktet/8;
		oktet = oktetc;
		x++;
		
	}
	int dlugosc = oct.length();
	int i = dlugosc -1;
	
	for(i; i>=0; i--){
		std::cout<<oct[i];
	}
}


int main()
{	
	std::cout<<"Podaj adres IP: ";
	std::string ip;
	std::cin>>ip;
	std::cout<<"Podaj maske: ";
	std::string maska;
	std::cin>>maska;
	pasek_fnc();
	
	//funkcja dzielanie podanego adresu na czesci(nic nie wyœwietla)
	inputip_fnc(ip);
	
	//funkcja dzielanie podanej maski na czesci(nic nie wyœwietla)
	inputmaska_fnc(maska);
		
	//funkcja sprawdzaj¹ca poprawnoœæ oktetów
	correctip_fnc(ipaddress[0],ipaddress[1],ipaddress[2],ipaddress[3]);
	pasek_fnc();
	
	//funkcja sprawdzaj¹ca poprawnoœæ maski
	correctmaska_fnc(maska_split[0],maska_split[1],maska_split[2],maska_split[3]);
	pasek_fnc();
	
	//funkcja sprawdzajaca klase adresu ip
	klasy_fnc(ipaddress[0]);
	pasek_fnc();
	
	//funkcja konwertujaca z decymalnego na binarny
	std::cout<<"Adres IP w systemie binarnym:"<<std::endl;
	dectobin_fnc(ipaddress[0]);
	oktetlicz ++;
	dectobin_fnc(ipaddress[1]);
	oktetlicz ++;
	dectobin_fnc(ipaddress[2]);
	oktetlicz ++;
	dectobin_fnc(ipaddress[3]);
	oktetlicz ++;
	std::cout<<oktetbin1<<"."<<oktetbin2<<"."<<oktetbin3<<"."<<oktetbin4<<std::endl;
	pasek_fnc();
	
	//funkcja konwertujaca z decymalnego na hexadecymalny
	std::cout<<"Adres IP w systemie hexadecymalnym:"<<std::endl;
	dectohex_fnc(ipaddress[0]);
	std::cout<<'.';
	dectohex_fnc(ipaddress[1]);
	std::cout<<'.';
	dectohex_fnc(ipaddress[2]);
	std::cout<<'.';
	dectohex_fnc(ipaddress[3]);
	std::cout<< std::endl;
	pasek_fnc();
	
	//funkcja konwertujaca z decymalnego na octalny
	std::cout<<"Adres IP w systemie octalnym:"<<std::endl;
	dectooct_fnc(ipaddress[0]);
	std::cout<<'.';
	dectooct_fnc(ipaddress[1]);
	std::cout<<'.';
	dectooct_fnc(ipaddress[2]);
	std::cout<<'.';
	dectooct_fnc(ipaddress[3]);
	std::cout<< std::endl;
	pasek_fnc();

	
	//a tu Work in progress
	std::cout<<"work in inprogress"<<std::endl;	
	pasek_fnc(); 
	
}

