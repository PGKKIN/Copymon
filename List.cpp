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

void ChoosePokemon(vector<Unit> &y,string x[],Unit a,Unit b,Unit c,Unit d,Unit e,Unit f,Unit g,Unit h,Unit i,Unit j){
    cout<<"-----Choose your first pokemon----- " <<endl;
    cout<<"Input Number to choose : ";
    while (y.size() < 3) {
        int pokemonIndex;
        cin >> pokemonIndex;

    bool alreadyChosen = false;
    for (int i = 0; i < y.size(); i++) {
        if (y[i].name == x[pokemonIndex-1]) {
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
            y.push_back(a);
            break;
        case 2:
            y.push_back(b);
            break;
        case 3:
            y.push_back(c);
            break;
        case 4:
            y.push_back(d);
            break;
        case 5:
            y.push_back(e);
            break;
        case 6:
            y.push_back(f);
            break;
        case 7:
            y.push_back(g);
            break;
        case 8:
            y.push_back(h);
            break;
        case 9:
            y.push_back(i);
            break;
        case 10:
            y.push_back(j);
            break;
        
        default:
            cout << "Invalid Pokemon selection. Please choose a valid option." << endl;
            continue;
    }
//     if (y.size() < 3) {
//         cout << "Please select your next Pokemon: " ;
//     } else {
//         break;
//     }
    
//    }
//    cout << "-----You have selected the following Pokemon----- " << endl;
//         for (int i = 0; i < y.size(); i++) {
//    cout <<i+1 <<"."<< y[i].name<< endl;
    }
}

void P1_Team(vector<Unit> &x){
    cout<<"Your first Pokemon : " <<"1." <<x[0].name <<endl;
    cout<<"Your Other Pokemon : " ;
    for(int i = 0 ; i < 3 ; i++){
        if(x[i].name != x[0].name){
            cout<<i+1<<"." <<x[i].name <<" ";
        }
   }
   cout<<endl;
}

void Switch(vector<Unit> &x){
    cout<<"Switch The First Pokemon : "  ;
    int Switch_Number ;
    cin >> Switch_Number ;
    string temp = x[0].name ;
    x[0].name = x[Switch_Number-1].name ;
    x[Switch_Number-1].name = temp;
    
    

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

    ////////////////////////////////////////////////////
    vector<Unit> selected_pokemon1; //Arrey โปเกมอน;
    ////////////////////////////////////////////////////
    ChoosePokemon(selected_pokemon1,pokemonNames,poke1,poke2,poke3,poke4,poke5,poke6,poke7,poke8,poke9,poke10);
    
    cout<<"---------------------------------------\n";

    P1_Team(selected_pokemon1);
    cout<<"---------------------------------------\n";
    Switch(selected_pokemon1); 
    cout<<"---------------------------------------\n";
    P1_Team(selected_pokemon1);
    cout<<"---------------------------------------\n";
    Switch(selected_pokemon1); 
    cout<<"---------------------------------------\n";
    P1_Team(selected_pokemon1);

  





   
    
    
}
