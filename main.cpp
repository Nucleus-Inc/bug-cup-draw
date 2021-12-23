//
//  main.cpp
//  bug-cup-draw
//
//  Created by Eduardo Castro on 22/12/21.
//

#include <iostream>
#include <unistd.h>

#include "player.cpp"
#include "bowl.cpp"
#include "clan.cpp"

using namespace std;

void sortPlayers(Bowl<Player> *bowl, Clan<Player> clan[], int size, int bowlNumber){
    int control = 0;
    int count = 0;
    
    cout<<"\n Sorteio do Pote "<<bowlNumber<<endl;
    cout<<"==============================="<<endl;
    do {
        Player *player = bowl->sortData(bowlNumber);
        if (player!=NULL) {
            cout<<"\n " << player->getName() << " sorteado para o time " << (control % size) + 1 << "\n" <<endl;
            
            clan[control % size].setPlayer(player);
            control++;
        } else {
            cout<<"\n Não temos participantes nesse pote. \n"<<endl;
        }
        
        switch (bowlNumber) {
            case 1:
                count = bowl->getCountBowl1();
                break;
            case 2:
                count = bowl->getCountBowl2();
                break;
            case 3:
                count = bowl->getCountBowl3();
                break;
            case 4:
                count = bowl->getCountBowl4();
                break;
            case 5:
                count = bowl->getCountBowl5();
                break;
        }
        
        sleep(2);
    } while(count > 0);
}

int main(int argc, char** argv) {
    
    //Variables
    Bowl<Player> *bowl = new Bowl<Player>();
    
    int resp, star, players, size;
    string name;
    
    //Players
    do {
        
        do{
            cout<<"\n Digite o nome do participante: ";
            cin>>name;
            
            if(name.empty())
                cout<<"\n O nome não pode ser vazio."<<endl;
        }while(name.empty());
        
        do{
            cout<<"\n Digite a quantidade de estrela dele [1-5]: ";
            cin>>star;
            
            if(star<1||star>5)
                cout<<"\n A quantidade de estrela deve ser maior que 0 e menor que 5."<<endl;
        }while(star<1||star>5);
        
        Player *player = new Player(name, star);
        
        switch (star) {
            case 1:
                bowl->setBowl1(player);
                break;
            case 2:
                bowl->setBowl2(player);
                break;
            case 3:
                bowl->setBowl3(player);
                break;
            case 4:
                bowl->setBowl4(player);
                break;
            case 5:
                bowl->setBowl5(player);
                break;
        }
        
        do{
            cout<<"\n Deseja adicionar outro participante? (1-Sim 2-Nao): ";
            cin>>resp;
            
            if(resp<1||resp>2)
                cout<<"\n Opção digitada é inválida."<<endl;
        }while(resp<1||resp>2);
        
    } while(resp == 1);
    
    //Sort
    do{
        cout<<"\n Digite a quantidade de participantes por time: ";
        cin>>players;
        
        if(players<0)
            cout<<"\n A quantidade de participantes por time tem que ser maior que zero."<<endl;
    }while(players<0);
    
    size = (bowl->getCount() / players);
    Clan<Player> clan[size];
    
    for(int i = 5; i > 0; i--){
        sortPlayers(bowl, clan, size, i);
    }
    
    //Clan
    cout<<"==============================="<<endl;
    for(int i = 0; i < size; i++){
        cout<<"\n TIME #"<<(i+1)<<endl;
        
        clan[i].toString();
        cout<<"==============================="<<endl;
    }
    
    cout<<endl;
    
    return 0;
}
