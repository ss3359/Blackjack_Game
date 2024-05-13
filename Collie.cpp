//
//  Collie.cpp
//  DogProject
//
//  Created by Owner on 5/6/24.
//

#include "Collie.hpp"
#include <iostream>
#include <thread>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <time.h>
#include <stdio.h>
#include "Maltese.hpp"
#include "Bloodhound.hpp"
#include "CockerSpaniel.hpp"
#include "Berneese.hpp"
#include "Sheepdog.hpp"
using namespace std;


int Blackjack:: AddNumbers(string ValueOfCard, int total){
    int ValueOne=1, ValueTwo=11;
    if(ValueOfCard=="K"||ValueOfCard=="Q"||ValueOfCard=="J"){
        total+=10;
    }
    else if(ValueOfCard=="A"){
        
        if(total+ValueTwo>21)
            total+=ValueOne;
    
        total+=ValueTwo;
    }

    else{
        total+=stoi(ValueOfCard);
    }
    return total;
}

void Blackjack::PlayerTurn(double PlayerBet, int PlayerTotal){
    
    char decision='0';
    string AddCard[2];
    
    while(decision!='S'){
        cout<<endl;
        cout<<"Updated Player Total: "<<PlayerTotal<<endl;
        if(PlayerTotal>21){
            cout<<"\n";
            cout<<"Player Busts! So Sorry \n\n"<<endl;
            break;
        }
        else if(PlayerTotal==21){
            cout<<"Blackjack. Player Wins! \n\n"<<endl;
            PlayerTotal+= 2*(PlayerTotal);
            break;
        }
        cout<<"Hit(H), Stand(S), DoubleDown(D) \n\n"<<endl;
        cin>>decision;

        if(decision=='H' || decision=='h'){
            AddCard[0]=CardValue[rand()%13];
            AddCard[1]=suit[rand()%4];
            
            cout<<AddCard[0]+AddCard[1]<<"\n\n"; 
            PlayerTotal=AddNumbers(AddCard[0], PlayerTotal);
            continue;
        }
        else if (decision=='D'||decision=='d'){
            string FinalCard[2]={CardValue[rand()%13],suit[rand()%4]};
            PlayerTotal=AddNumbers(FinalCard[0], PlayerTotal);
            cout<<"\n Player New Card: "<<FinalCard[0]+FinalCard[1]<<endl;
            cout<<"Player Total: "<<PlayerTotal<<endl;
            cout<<"Turn is Over! "<<endl;
            break;
        }
        else if(decision=='S'||decision=='s'){
            PlayerTotal=PlayerTotal; 
            cout<<"Player Stays on: "<<PlayerTotal<<endl;
            break;
        }
    }
    return;
}

void Blackjack::DealerTurn(int DealerTotal, int PlayerTotal,double PlayerBet){
    srand(time(NULL));
    
    while(DealerTotal <=21){
        if(PlayerTotal==21)
            break;
        if(PlayerBet>21){
            cout<<"Dealer Takes Players Money! "<<endl;
            break;
        }
        else if(DealerTotal>=17&& DealerTotal<=21){
            cout<<"Dealer Stands on "<<DealerTotal<<endl;
            break;
        }
        else{
            string AddCard[2]={CardValue[rand()%13],suit[rand()%4]};
            cout<<AddCard[0]+AddCard[1]<<"\t";
            DealerTotal=AddNumbers(AddCard[0], DealerTotal);
            cout<<"Dealer Total: "<<DealerTotal<<"\n\n";
        }
    }
    CompareTotals(DealerTotal, PlayerTotal, PlayerBet);
    return;
}


double Blackjack::CompareTotals(int DealerTotal, int PlayerTotal, double PlayerBet){
    cout<<"\n\n";
    if(((PlayerTotal<21)&&(DealerTotal<21)&&(DealerTotal<PlayerTotal))){
        cout<<"Player Wins! "<<endl;
        PlayerBet+=PlayerBet;
    }
    else if((PlayerTotal<21)&&DealerTotal>21){
        cout<<"Player Wins! "<<endl;
        PlayerBet+=PlayerBet;
    }
    else if(PlayerTotal>21)
        cout<<"Dealer Wins"<<endl;
    else if((PlayerTotal<21)&&(DealerTotal<21)&&(DealerTotal>PlayerTotal)){
        cout<<"Dealer Wins! "<<endl;
        
    }
    else if(DealerTotal==PlayerTotal){
        cout<<"Dealer and Player pushes! "<<endl;
    }
    cout<<"\n\n";
    return PlayerBet;
}


void Blackjack::PlayTheGame(double PlayerBet, int PlayerTotal, int DealerTotal){
    srand(time(0));
    string Card1[2]={CardValue[rand()%13],suit[rand()%4]},
           Card2[2]={CardValue[rand()%13], suit[rand()%4]},
           Card3[2]={CardValue[rand()%13], suit[rand()%4]},
           Card4[2]={CardValue[rand()%13], suit[rand()%4]};
    cout<<"Player Cards: "<<Card1[0]+Card1[1]<<"\t"<<Card3[0]+Card3[1]<<endl;
    PlayerTotal+=AddNumbers(Card1[0],PlayerTotal)+AddNumbers(Card3[0],PlayerTotal);
    cout<<"Player Total: "<<PlayerTotal<<endl;
    cout<<"\n\n";
    cout<<"Dealer Show Card: "<<Card4[0]+Card4[1]<<"\n\n";
    PlayerTurn(PlayerBet,PlayerTotal);
    
    if(Card1[0]==Card3[0]){
        
    }
    
    
    if(PlayerTotal>21||DealerTotal==21)
        cout<<"Dealer Automatic Win. "<<endl;
    else if(PlayerTotal==21)
    {
        cout<<"Player Automatic Win! "<<endl;
    }
    else{
        cout<<"Dealer Full Hand: "<<Card4[0]+Card4[1]<<"\t"<<Card2[0]+Card2[1]<<endl;
        DealerTotal+=AddNumbers(Card2[0], DealerTotal)+AddNumbers(Card4[0], DealerTotal);
        
        cout<<"Dealer Total: "<<DealerTotal<<endl;
        
        
        DealerTurn(DealerTotal,PlayerTotal,PlayerBet);
       
    }
}

void Blackjack::split(double PlayerBet, string CardValueOne, string CardValueTwo){
    string AddCard1[2]={CardValue[rand()%13],suit[rand()%4]};
    string AddCard2[2]={CardValue[rand()%13],suit[rand()%4]};
    char decision='0';
    
    int PlayerTotalOne=0, PlayerTotalTwo=0;
    
    cout<<"Split Cards (Z)?  \n\n"<<endl;
    cin>>decision;
    
    if(decision=='Z'){
        
        
        PlayerTotalOne=AddNumbers(AddCard1[0], PlayerTotalOne);
        PlayerTotalTwo=AddNumbers(AddCard2[0], PlayerTotalTwo);
        
        PlayerTurn(PlayerBet, PlayerTotalOne);
    }
    else{
        
    }
    
}

