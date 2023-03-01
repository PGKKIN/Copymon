#include "h.cpp"

int main(){  
    Unit poke1 ("Charizard","Fire",200,50,50,"Daimonji","Fire",75,"Dragon Claw","Dragon",50,"Brick Break","Fighting",50,"Protect",false);
	Unit poke2 ("Blastoise","Water",200,25,75,"Hydro Pump","Water",75,"Dark Paluse","Dark",50,,"Ice Beam",50,"Protect",false);
	Unit poke3 ("Venusaur","Grass",200,25,75,"Solar Beam","Grass",75,"Seed Bomb","Grass",65,"Doube-Edge","Normal",60,"Protect",false);
	Unit poke4 ("Snorlax","Normal",400,10,30,"Hyper Beam","Normal",90,"Crunch","Dark",50,"Hammer Arm","Grass,"50,"Protect",false);
	Unit poke5 ("Lucario","Fighting",175,75,50,"Close Combat","Fighting",75,"Dragon Paluse","Dragon",50,"Extream Speed","Normal",60,"Protect",false);
	Unit poke6 ("Gengar","Ghost",200,75,25,"Destiny Bond","Ghost",75,"Suker Punch","Dark",50,"Fire Punch","Fire",50,"Protect",false);
	Unit poke7 ("Gardevoir","Fairy",200,75,25,"Moonblast","Fairy",75,"Mystical Fire","Fire",50,"Grass Knot","Grass",50,"Protect",false);
	Unit poke8 ("Garchomp","Dragon",200,50,50,"Dragon Rush","Dragon",75,"Brick Break","Fighting",50,"Fire Fang","Fire",50,"Protect",false);
	Unit poke9 ("Abomasnow","Ice",300,30,30,"Blizzard","Ice",75,"Wood Hammer","Grass",60,"Ice Punch","Ice",50,"Protect",false);
	Unit poke10 ("Absol","Dark",200,60,40,"Night Slash","Dark",75,"Curse","Ghost",50,"Fire Blast",50,"Rock Smash","Fighting",50,"Protect",false);


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
		for(int l = 0 ; j < 7 ;j++){
        	vector<string> stat = allpoke[i].getSelect3();
        	cout  << stat[j]<< " ";
        }
        cout<<endl;
	}
