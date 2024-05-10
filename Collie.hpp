//
//  Collie.hpp
//  DogProject
//
//  Created by Owner on 5/6/24.
//

#ifndef Collie_hpp
#define Collie_hpp

#include <stdio.h>
#include <iostream>
#include <thread>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <time.h>
#include "Maltese.hpp"
#include "Bloodhound.hpp"
#include "CockerSpaniel.hpp"
#include "Berneese.hpp"
#include "Sheepdog.hpp"
using namespace std;

class Blackjack{
    
    string suit[4]={"H", "S", "C", "D"};
    string CardValue[13]={"A","2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    

public:
    int PlayerTotal=0;
    int DealerTotal=0;
    
    
    
    void PlayTheGame(double bet, int PlayerTotal,int DealerTotal);
    void PlayerTurn(double PlayerBet, int PlayerTotal);
    void DealerTurn(int DealerTotal, int PlayerTotal,double PlayerBet);
    
    int AddNumbers(string ValueOfCard, int total);
    void split(string CardValueOne, string CardValueTwo);
    double CompareTotals(int DealerTotal, int PlayerTotal, double PlayerBet);
};


//
//    bool IsInsurance(string DealerCardValue){
//        if(DealerCardValue=="A")
//            return true;
//        return false;
//    };
#endif /* Collie_hpp */
