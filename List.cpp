#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<iomanip>

using namespace std;

class choosePK{
    public:
        int P1[3];
        int P2[3];
};

class Unit{
        string name;
        string type;
        int hp;
        int hpmax;
        int atk;
        int def;
    public:
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

// void Unit::choose(Unit *a){
//     P1[1] +=  ;

// }
// void POKEMON::switchPosition(int a , int c[])
// {
//         for(int i = 0 ; i < 2 ;i++)
//         {
//             if(a == c[i])
//             {
//                 int temp = c[1];
//                 c[1] = c[i];
//                 c[i] = temp ;

//             }
//         }
// }

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

    choosePK P1 ;
    choosePK P2 ;

    // for(int i = 0 ; i < 3 ;i++){
    //     cout << "Please choose your pokemon " <<i+1 <<": " ;
    //     cin >> P1.P1[i];
    // }
    // for(int i = 0 ; i < 3 ;i++){
    //     cout<< P1.P1[i] << " ";
    // }
    // for(int i = 0 ; i < 3 ;i++){
    //     for(int j = 0 ; j < 2 ;j++){
    //     vector<string> stat = Pokeall[i].getSelect2();
    //     cout << stat[j]<< " ";
    //     }
    //     for(int k = 0 ; k < 3 ;k++){
    //        vector<int> stat2 = Pokeall[i].getSelect();
    //         cout << stat2[i]<< " "; 
    //     }

    // }



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




    
    
}