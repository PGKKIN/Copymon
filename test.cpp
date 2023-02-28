#include <iostream>
using namespace std;

int main(){
	Unit poke1{"Charizard","Fire",200,200,50,50,false};
	Unit poke2{"Blastoise","Water",200,200,25,75,false};
	Unit poke3{"Venusaur","Grass",200,200,25,75,false};
	Unit poke4{"Snorlax","Normal",400,200,10,30,false};
	Unit poke5{"Lucario","Fighting",175,200,75,50,false};
	Unit poke6{"Gengar","Ghost",200,200,75,25,false};
	Unit poke7{"Gardevoir","Fairy",200,200,75,25,false};
	Unit poke8{"Garchomp","Dragon",200,200,50,50,false};
	Unit poke9{"Abomasnow","Ice",300,200,30,30,false};
	Unit poke10{"Absol","Dark",200,200,60,40,false};
	player1_team[] = {poke1,poke2,poke3};
	player2_team[] = {poke3,poke4,poke5};
	int turn_count = 1;
	char player1_action = '\0',player2_action = '\0';
	int p1 = 0, p2 = 0;
	while(true){
		player1.newTurn();	
		player2.newTurn();			
		player2team[0].showStatus();
		drawScene(player1_action,p1,player2_action,p2);
		player2.showStatus();		
		cout << "[A] Attack [H] Heal [S] Switch [E] Exit";
		cout << "\n[Player1 turn " << turn_count << "] Enter your action: ";
		cin >> player1_action;
		player_action = toupper(player1_action);
		if(player1_action == 'E') break; 
		
		cout << "\n[Player2 turn " << turn_count << "] Enter your action: ";
		cin >> player2_action;
		player2_action = toupper(player2_action);
		
		if(player1_action == 'S') hero.guard();
		if(player2_action == 'S') mons.guard();
		
		if(player1_action == 'H') p1 = hero.heal();
		if(player2_action == 'H') p2 = hero.heal();
		
		if(player_action == 'A') p = hero.attack(mons); 
		if(monster_action == 'A') m = mons.attack(hero); 
		
		if(hero.isDead()){
			drawScene(player_action,p,monster_action,m);
			playerLose();
			break; 
		}
		
		if(mons.isDead()){
			drawScene(player_action,p,monster_action,m);
			playerWin();
			break; 
		}
		
		turn_count++;
	}
	return 0;
}