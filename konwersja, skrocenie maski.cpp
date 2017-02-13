#include <iostream>

using namespace std; 
//zmienne globalne
int ip[4]= {192,168,33, 1};
int maska[4]={255,255,252,0};
int symbol;//funkcja symbol_fnc, s³u¿aca do konwersji na skrócon¹ forme maski (Rafa³ Balcerzak, Dawid Ratajczyk)
int oktetlicz=1;//funkcja dec_to_bin_fnc, s³ó¿¹ca do konwersji na system dwójkowy (Rafa³ Balcerzak, Dawid Ratajczyk)
string oktetbin1="00000000";//funkcja dec_to_bin_fnc, s³ó¿¹ca do konwercji na system dwójkowy, wartoœæ zostaje potem nadpisana i mo¿na jej u¿yæ w innej czêœci programu(Rafa³ Balcerzak, Dawid Ratajczyk)
string oktetbin2="00000000";//funkcja dec_to_bin_fnc, s³ó¿¹ca do konwercji na system dwójkowy, wartoœæ zostaje potem nadpisana i mo¿na jej u¿yæ w innej czêœci programu(Rafa³ Balcerzak, Dawid Ratajczyk)
string oktetbin3="00000000";//funkcja dec_to_bin_fnc, s³ó¿¹ca do konwercji na system dwójkowy, wartoœæ zostaje potem nadpisana i mo¿na jej u¿yæ w innej czêœci programu(Rafa³ Balcerzak, Dawid Ratajczyk)
string oktetbin4="00000000";//funkcja dec_to_bin_fnc, s³ó¿¹ca do konwercji na system dwójkowy, wartoœæ zostaje potem nadpisana i mo¿na jej u¿yæ w innej czêœci programu(Rafa³ Balcerzak, Dawid Ratajczyk)

//funkcja konwertuj¹ca na skrócon¹ forme maski (Rafa³ Balcerzak, Dawid Ratajczyk)
int symbol_fnc(int oktet){
	if(oktet == 255){
		symbol += 8;
	}
	if(oktet ==254){
		symbol +=7;
	}
	if(oktet ==252){
		symbol +=6;
	}
	if(oktet ==248){
		symbol +=5;
	}
	if(oktet ==240){
		symbol +=4;
	}
	if(oktet ==224){
		symbol +=3;
	}
	if(oktet ==192){
		symbol +=2;
	}
	if(oktet ==128){
		symbol +=1;
	}
	
}

//funkcja konwertujaca z systemu decymalnego na system binarny (Rafa³ Balcerzak, Dawid Ratajczyk)
int dec_to_bin_fnc(int oktet)
{
	int ip1;
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
		ip1 = oktet/2;
		oktet=ip1;
		x ++;	
		y --;
	}

	x=0;
	y=7;	
}


int dec_to_hex_fnc(int oktet){

	int x=0;
	string hex;
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
		oktet /=16;
		x++;
	}
	int dlugosc = hex.length();
	int i = dlugosc -1;
	
	for(i; i>=0; i--){
		cout<<hex[i];
	}
}


int main(){
	//funkcja konwertuj¹ca na skrócon¹ forme maski (Rafa³ Balcerzak, Dawid Ratajczyk)
	symbol_fnc(maska[0]);
	symbol_fnc(maska[1]);
	symbol_fnc(maska[2]);
	symbol_fnc(maska[3]);
	cout<<"maska: "<<maska[0]<<"."<<maska[1]<<"."<<maska[2]<<"."<<maska[3]<<endl;
	cout<<"Skrocona forma maski: /"<<symbol<<endl;
	cout<<"ip: "<<ip[0]<<'.'<<ip[1]<<'.'<<ip[2]<<'.'<<ip[3]<<endl;
	
	//funkcja konwertujaca z systemu decymalnego na system binarny (Rafa³ Balcerzak, Dawid Ratajczyk)
	cout<<"Adres IP w systemie binarnym:"<<endl;
	dec_to_bin_fnc(ip[0]);//po zmienienu ip[x] na maska[x] mo¿emy tak¿e przekonwertowac maske
	oktetlicz ++;
	dec_to_bin_fnc(ip[1]);
	oktetlicz ++;
	dec_to_bin_fnc(ip[2]);
	oktetlicz ++;
	dec_to_bin_fnc(ip[3]);
	oktetlicz ++;
	cout<<oktetbin1<<"."<<oktetbin2<<"."<<oktetbin3<<"."<<oktetbin4<<endl;

	//funkcja konwertujaca z systemu decymalnego na system hexadecymalny (Rafa³ Balcerzak, Dawid Ratajczyk)
	cout<<"Adres IP w systemie hexadecymalnym:"<<endl;
	dec_to_hex_fnc(ip[0]);//po zmienienu ip[x] na maska[x] mo¿emy tak¿e przekonwertowac maske
	cout<<'.';
	dec_to_hex_fnc(ip[1]);
	cout<<'.';
	dec_to_hex_fnc(ip[2]);
	cout<<'.';
	dec_to_hex_fnc(ip[3]);
}
