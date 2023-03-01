#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;

class Unit{
        string name;
        string type;
        int hp;
        int hpmax;
        int atk;
        int def;
        string move1;
        string move1type;
        int move1atk;
        string move2;
        string move2type;
        int move2atk;
        string move3;
        string move3type;
        int move3atk;
        string move4;//protect
        bool protect_on;
    public:
        Unit(string,string,int,int,int,string,string,int,string,string,int,string,string,int,string,bool);
		vector<int> getSelect();
        vector<string> getSelect2();
        vector<string> getSelect3();

};
Unit::Unit(string a,string b,int c,int d,int e,string f,string g,int h,string i,string j,int k,string l,string m,int n,string o,bool p){
    name = a;
    type = b;
    hpmax = c;
    atk = d;
    def = e;
    move1 =f;
    move1type =g;
    move1atk =h;
    move2 = i;
    move2type = j;
    move2atk = k;
    move3 = l;
    move3type = m;
    move3atk = n;
    move4 = o;
    protect_on = p;
}

vector<string> Unit::getSelect2(){
    vector<string> s;
     s.push_back(name);
     s.push_back(type);
     return s;
}
vector<int> Unit::getSelect(){
    vector<int> x;
     x.push_back(hpmax);
     x.push_back(atk);
     x.push_back(def);
     return x;
}
vector<string> Unit::getSelect3(){
    vector<string> s;
     s.push_back(move1);
     s.push_back(move1type);
     s.push_back(move2);
     s.push_back(move2type);
     s.push_back(move3);
     s.push_back(move3type);
     s.push_back(move4);
     return s;
}

int main(){  
    Unit poke1 ("Charizard","Fire",200,50,50,"Daimonji","Fire",75,"DragonClaw","Dragon",50,"BrickBreak","Fighting",50,"Protect",false);
	Unit poke2 ("Blastoise","Water",200,25,75,"HydroPump","Water",75,"DarkPaluse","Dark",50,"IceBeam","Ice",50,"Protect",false);
	Unit poke3 ("Venusaur","Grass",200,25,75,"SolarBeam","Grass",75,"SeedBomb","Grass",65,"Doube-Edge","Normal",60,"Protect",false);
	Unit poke4 ("Snorlax","Normal",400,10,30,"HyperBeam","Normal",90,"Crunch","Dark",50,"HammerArm","Fighting",50,"Protect",false);
	Unit poke5 ("Lucario","Fighting",175,75,50,"CloseCombat","Fighting",75,"DragonPaluse","Dragon",50,"ExtreamSpeed","Normal",60,"Protect",false);
	Unit poke6 ("Gengar","Ghost",200,75,25,"DestinyBond","Ghost",75,"SukerPunch","Dark",50,"FirePunch","Fire",50,"Protect",false);
	Unit poke7 ("Gardevoir","Fairy",200,75,25,"Moonblast","Fairy",75,"MysticalFire","Fire",50,"GrassKnot","Grass",50,"Protect",false);
	Unit poke8 ("Garchomp","Dragon",200,50,50,"DragonRush","Dragon",75,"BrickBreak","Fighting",50,"FireFang","Fire",50,"Protect",false);
	Unit poke9 ("Abomasnow","Ice",300,30,30,"Blizzard","Ice",75,"WoodHammer","Grass",60,"IcePunch","Ice",50,"Protect",false);
	Unit poke10 ("Absol","Dark",200,60,40,"NightSlash","Dark",75,"Curse","Ghost",50,"RockSmash","Fighting",50,"Protect",false);

    vector<Unit> player1_pokemon = {poke1, poke2, poke3};
    vector<Unit> allpoke = {poke1, poke2, poke3,poke4,poke5,poke6,poke7,poke8,poke9,poke10};
    for(int i = 0 ; i < 10  ;i++){
        cout << i+1<<".";
        for(int j = 0 ; j < 2 ;j++){
        	vector<string> stat = allpoke[i].getSelect2();
        	cout  << stat[j]<< " ";
        }
        cout<<" ";
        for(int k = 0 ; k < 1 ;k++){
           vector<int> stat2 = allpoke[i].getSelect();
            cout << "HP" <<stat2[k]<< " "<< "ATK" <<stat2[k+1]<< " "<< "DEF"<< stat2[k+2]<< " "; 
        }
		for(int l = 0 ; l < 7 ;l+=2){
        	vector<string> stat3 = allpoke[i].getSelect3();
        	cout  << stat3[l];
        	if(l<6) cout<<" Type:"<<stat3[l+1]<<" ";
        }
        cout<<endl;
    }
}
