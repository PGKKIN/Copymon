#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<iomanip>

using namespace std;



class Unit{
    public:
        string name;
        string type;
        int hp;
        int hpmax;
        int atk;
        int def;
    
		Unit(string,string,int,int,int);
		vector<int> getSelect();
        vector<string> getSelect2();
        void choose(Unit *);  
};

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

int main(){ 
    Unit poke1 ("Charizard","Fire",200,50,50);
	Unit poke2 ("Blastoise","Water",200,25,75);
	Unit poke3 ("Venusaur","Grass",200,25,75);
	Unit poke4 ("Snorlax","Normal",400,10,30);
	Unit poke5 ("Lucario","Fighting",175,75,50);
	Unit poke6 ("Gengar","Ghost",200,75,25);
	Unit poke7 ("Gardevoir","Fairy",200,75,25);
	Unit poke8 ("Garchomp","Dragon",200,50,50);
	Unit poke9 ("Abomasnow","Ice",300,30,30);
	Unit poke10 ("Absol","Dark",200,60,40);
    string pokemonNames[] = {"Charizard","Blastoise","Venusaur","Snorlax","Lucario","Gengar","Gardevoir","Garchomp","Abomasnow","Absol",};
    
    cout<<"---------------------------------------\n";//แสดง list pokemon
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
        cout<<endl; 
    }
    cout<<"---------------------------------------\n";//เลือกโปรแกมอน

    cout<<"Input Number to choose : ";
    ////////////////////////////////////////////////////
    vector<Unit> selected_pokemon1; //Arrey โปเกมอน;
    ////////////////////////////////////////////////////

   while (selected_pokemon1.size() < 3) {
    int pokemonIndex;
    cin >> pokemonIndex;

    bool alreadyChosen = false;
    for (int i = 0; i < selected_pokemon1.size(); i++) {
        if (selected_pokemon1[i].name == pokemonNames[pokemonIndex-1]) {
            alreadyChosen = true;
            break;
        }
    }
    if (alreadyChosen) {
        cout << "That Pokemon has already been selected. Please choose a different one." << endl ;
        cout << "Please select your next Pokemon agian: " ;
        continue;
    }
    
        switch (pokemonIndex) {
        case 1:
            selected_pokemon1.push_back(poke1);
            break;
        case 2:
            selected_pokemon1.push_back(poke2);
            break;
        case 3:
            selected_pokemon1.push_back(poke3);
            break;
        case 4:
            selected_pokemon1.push_back(poke4);
            break;
        case 5:
            selected_pokemon1.push_back(poke5);
            break;
        case 6:
            selected_pokemon1.push_back(poke6);
            break;
        case 7:
            selected_pokemon1.push_back(poke7);
            break;
        case 8:
            selected_pokemon1.push_back(poke8);
            break;
        case 9:
            selected_pokemon1.push_back(poke9);
            break;
        case 10:
            selected_pokemon1.push_back(poke10);
            break;
        
        default:
            cout << "Invalid Pokemon selection. Please choose a valid option." << endl;
            continue;
    }
    if (selected_pokemon1.size() < 3) {
        cout << "Please select your next Pokemon: " ;
    } else {
        break;
    }
   }

   cout<<"---------------------------------------\n";//แสดงโปรแกมอน
   cout << "You have selected the following Pokemon: " << endl;
        for (int i = 0; i < selected_pokemon1.size(); i++) {
   cout <<i+1 <<"."<< selected_pokemon1[i].name<< endl;
    }
   
   cout<<"---------------------------------------\n"; // เลือกโปรแกม่อนตัวแรก
   cout<<"Choose your first Pokemon : ";
   int c ;
   cin >> c ;

   cout<<"Your first Pokemon : " <<"1." <<selected_pokemon1[c-1].name <<endl;
   cout<<"Your Other Pokemon : " ;
   for(int i = 0 ; i < 3 ; i++){
        if(i != c-1){
           cout<<i+1 <<"."<<selected_pokemon1[i].name <<" ";
        }
   }
    cout<<"---------------------------------------\n";
    cout<<"Switch The First Pokemon : "  ;
    int s ;
    cin >> s ;
    for(int j = 0 ; j < 3 ; j++){
        if(s == c-1){
            cout<<"Agian" ;
            continue;
        }if(s != c-1){
            cout<<selected_pokemon1[s-1].name;
            break;
        }
    }

   //j


   
    
    
}
