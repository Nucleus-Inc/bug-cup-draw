//
//  clan.cpp
//  bug-cup-draw
//
//  Created by Eduardo Castro on 22/12/21.
//

#ifndef CLAN_CPP
#define CLAN_CPP

#include <iostream>
#include <sstream>

#include "list.cpp"
#include "node.cpp"

using namespace std;

template<class T>
class Clan {
    
    private:
    List<T> *players;
    
    public:
        Clan(){
            this->players = new List<T>();
        }
    
        void setPlayer(T *data){
            this->players->addLast(data);
        }
    
        List<T> getPlayers(){
            return this->players;
        }
    
        int getCount(){
            return players->getCount();
        }
    
        void toString(){
            for(Node<T> *node = players->getHead(); node!=NULL; node = node->getNext()){
                node->getData()->toString();
            }
        }

};

#endif

