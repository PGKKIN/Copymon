#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


int main(){
    int N = 5;
    int S ;
    int Swap;
    int player_1Team[N] = {1,2,3,8,6};
    int player_2Team[N] = {4,5,6};
    cout<<"Your 1 Poke : " << player_1Team[0] <<endl;
    cout<<"Poke deck : ";
    for(int i = 1 ; i<N;i++){
        cout<<player_1Team[i] << " ";
    }
    cout <<endl;
    cout<<"SwithPoke : ";
    cin >>S;
    for(int i = 0 ; i < N ; i++){
        if(S == player_1Team[i]){
            Swap = player_1Team[0];
            player_1Team[0] = player_1Team[i] ;
            player_1Team[i] = Swap ;
            break;
        }
    }
    cout<<"Your 1 Poke : " << player_1Team[0] <<endl;
    cout<<"Poke deck : ";
    for(int i = 1 ; i<N;i++){
        cout<<player_1Team[i] << " ";
    }

}