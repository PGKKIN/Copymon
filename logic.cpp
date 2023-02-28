#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Pokemon{
        string name;
        string type;
        int hp;
        int hpmax;
        int atk;
        int def;
        bool protect;
    public:
        void create(string);
		void showStatus();
		void newTurn();
		void att(string,string);
		int attack(Unit &);
		int beAttacked(int);
		int heal();	
		void guard();
		bool isDead();	
};

void Pokemon::att(string move,string poke){
    if(move == "Fire"){
        if(poke == "Grass"){
            atk *= 2;    
        }else if (poke == "Water"){
            atk /= 2;
        }

    }
     if(move == "Grass"){
        if(poke == "Water"){
            atk *= 2;    
        }else if (poke == "Ice"){
            atk /= 2;
        }

    }
     if(move == "Water"){
        if(poke == "Fire"){
            atk *= 2;    
        }else if (poke == "Grass"){
            atk /= 2;
        }

    }
     if(move == "Fighting"){
        if(poke == "Normal"){
            atk *= 2;    
        }else if (poke == "Ghost"){
            atk = 0;
        }

    }
     if(move == "Dragon"){
        if(poke == "Dragon"){
            atk *= 2;    
        }else if (poke == "Fairy"){
            atk = 0;
        }

    }
}

void Unit::create(string t){ 
	if(t == "Hero"){
		type = "Hero";
		cout << "Please input your name: ";
		getline(cin,name);
		hpmax = rand()%20+90;
		atk = rand()%5+14;
		def = rand()%3+9;
	}else if(t == "Monster"){
		type = "Monster";
		name = "Kraken";
		hpmax = rand()%20+200;
		atk = rand()%5+25;
		def = rand()%3+5;
	}
	hp = hpmax;
	protect = false;
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
	protect = false;
}

bool Unit::isDead(){
	if(hp <= 0){
		return true;
	}else{
		return false;
	}

}

void Unit::guard(){
 	guard_on = true;	
}

int Unit::beAttacked(int oppatk){
	double dmg;
	if(guard_on == true){
		dmg = (oppatk-def)/3;
		hp -= dmg;
		return dmg;
		
	}else{
		dmg = (oppatk-def);
		hp -= dmg;
		return dmg;
    }
}

int Unit::attack(Unit &x){
	return x.beAttacked(atk);
}

int Unit::heal(){
	int x = rand()%21+10;
	if((hp += x) > hpmax){
		x -= hp - hpmax;
		hp = hpmax;
	}
	
	return x;
}	




