#include <iostream>
#include <string>
#include <cstdlib>
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
        int move3atk
        string move4;//protect
        bool protect_on;
    public:
        Unit(string,string,int,int,int);
		vector<int> getSelect();
        vector<string> getSelect2();
        void choose(Unit *);
		void showStatus();
		void newTurn();
		int attack(Unit &);
		int beAttacked(int,string,string);
		int heal();	
		bool isDead();	
        class move();
};

int Unit::beAttacked(int oppatk,string movetype,int moveatk){
    double dmg;
    if(movetype == "Fire"){
        if(type == "Grass") dmg = (moveatk+oppatk-def)*2;
        else if (type == "Ice") dmg = (moveatk+oppatk-def)*2;
        else if (type == "Fire") dmg = (moveatk+oppatk-def)/2;
        else if (type == "Water") dmg = (moveatk+oppatk-def)/2;
    }
    else if(movetype == "Grass"){
        if(type == "Water") dmg = (moveatk+oppatk-def)*2;    
        else if (type == "Ice") dmg = (moveatk+oppatk-def)/2;
        else if (type == "Grass") dmg = (moveatk+oppatk-def)/2;
        else if (type == "Fire") dmg = (moveatk+oppatk-def)/2;
        else if (type == "Fairy") dmg = (moveatk+oppatk-def)*2;
        else if (type == "Fighting") dmg = (moveatk+oppatk-def)*2;
    }
    else if(movetype == "Water"){
        if(type == "Fire") dmg = (moveatk+oppatk-def)*2;    
        else if (type == "Grass") dmg = (moveatk+oppatk-def)/2;
        else if (type == "Water") dmg = (moveatk+oppatk-def)/2;
    }
    else if(movetype == "Fighting"){
        if(type == "Normal") dmg = (moveatk+oppatk-def)*2;    
        else if (type == "Ghost") dmg = 0;
        else if (type == "Ice") dmg = (moveatk+oppatk-def)*2;
        else if (type == "Dark") dmg = (moveatk+oppatk-def)*2;
        else if (type == "Fighting") dmg = (moveatk+oppatk-def)/2;
        else if (type == "Grass") dmg = (moveatk+oppatk-def)/2;
        else if (type == "Fairy") dmg = (moveatk+oppatk-def)/2;
    }
    else if(movetype == "Dragon"){
        if(type == "Dragon") dmg = (moveatk+oppatk-def)*2;    
        else if (type == "Fairy") dmg = 0;
    }
    else if(movetype == "Ice"){
        if(type == "Dragon") dmg = (moveatk+oppatk-def)*2;
        else if (type == "Grass") dmg = (moveatk+oppatk-def)*2;
        else if (type == "Water") dmg = (moveatk+oppatk-def)/2;
        else if (type == "Fire") dmg = (moveatk+oppatk-def)/2;
        else if (type == "Ice") dmg = (moveatk+oppatk-def)/2;
    }
    else if(movetype == "Dark"){
        if(type == "Ghost") dmg = (moveatk+oppatk-def)*2;    
        else if (type == "Fighting") dmg = (moveatk+oppatk-def)/2;
    }
    else if(movetype == "Ghost"){
        if(type == "Ghost") dmg = (moveatk+oppatk-def)*2;    
        else if (type == "Normal") dmg =0;
        else if (type == "Dark") dmg = (moveatk+oppatk-def)/2;
    }
    else if(movetype == "Fairy"){
        if(type == "Fighting") dmg = (moveatk+oppatk-def)*2;    
        else if (type == "Dark") dmg = (moveatk+oppatk-def)*2;
        else if (type == "Dragon") dmg = (moveatk+oppatk-def)*2;
        else if (type == "Fire") dmg = (moveatk+oppatk-def)/2;
        else if (type == "Grass") dmg = (moveatk+oppatk-def)/2;
    }
    else if(movetype == "Normal"){
        if(type == "Ghost") dmg = 0;    
    }
    
    hp -= dmg;
	if(hp <= 0) hp = 0;
	
	return dmg;	
}

void Unit::showStatus(){
	if(type == "Hero"){
		cout << "---------------------------------------\n"; 
		cout << name << "\n"; 
		cout << "HP: " << hp << "/" << hpmax << "\tATK: "<< atk << "\t\tDEF: "<< def;		
		cout << "\n---------------------------------------\n";
	}	
	else if(type == "Monster"){
		cout << "\t\t\t\t---------------------------------------\n"; 
		cout << "\t\t\t\t" << name << "\n"; 
		cout << "\t\t\t\tHP: " << hp << "\t\tATK: "<< atk << "\t\tDEF: "<< def;
		cout << "\n\t\t\t\t---------------------------------------\n";
	}
}

void Unit::newTurn(){
}

bool Unit::isDead(){
	if(hp <= 0){
		return true;
	}else{
		return false;
	}
}


int Unit::attack(Unit &x){
	return x.beAttacked(atk,movetype,moveatk);
}

int Unit::heal(){
    int h=60;
	if(hp + h > hpmax) h = hpmax - hp;
	hp = hp + h;
	return h;
}	
Unit::Unit(string x,string y,int a,int b,int c){
    name = x;
    type = y;
    hpmax = a;
    atk = b;
    def = c;
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

