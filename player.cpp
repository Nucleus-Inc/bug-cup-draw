//
//  player.cpp
//  bug-cup-draw
//
//  Created by Eduardo Castro on 22/12/21.
//

#ifndef PLAYER_CPP
#define PLAYER_CPP

#include <iostream>
#include <sstream>

using namespace std;

class Player {
    
    private:
        string name;
        int star;
    public:
        Player(string name, int star){
            setName(name);
            setStar(star);
        }
    
        void setName(string name){
            this->name = name;
        }
        void setStar(int star){
            this->star = star;
        }
    
        string getName(){
            return this->name;
        }
        int getStar(){
            return this->star;
        }
    
        void toString(){
            stringstream data;
            
            data << "\n Name: " << getName() << " Level: ";
            
            for(int i = 0; i < star; i++){
                data << "*";
            }
            
            data << endl;
            
            cout<<data.str();
        }
};

#endif
