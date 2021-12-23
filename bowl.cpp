//
//  bowl.cpp
//  bug-cup-draw
//
//  Created by Eduardo Castro on 22/12/21.
//

#ifndef BOWL_CPP
#define BOWL_CPP

#include <iostream>
#include <cstdlib>
#include <time.h>

#include "list.cpp"

using namespace std;

template<class T>
class Bowl {
    
    private:
        List<T> *bowl1;
        List<T> *bowl2;
        List<T> *bowl3;
        List<T> *bowl4;
        List<T> *bowl5;
    
    public:
        Bowl(){
            this->bowl1 = new List<T>();
            this->bowl2 = new List<T>();
            this->bowl3 = new List<T>();
            this->bowl4 = new List<T>();
            this->bowl5 = new List<T>();
        }
    
        void setBowl1(T *data){
            this->bowl1->addLast(data);
        }
        
        void setBowl2(T *data){
            this->bowl2->addLast(data);
        }

        void setBowl3(T *data){
            this->bowl3->addLast(data);
        }

        void setBowl4(T *data){
            this->bowl4->addLast(data);
        }

        void setBowl5(T *data){
            this->bowl5->addLast(data);
        }
    
        int getCount(){
            return bowl1->getCount() + bowl2->getCount() + bowl3->getCount() + bowl4->getCount() + bowl5->getCount();
        }
    
        int getCountBowl1(){
            return bowl1->getCount();
        }
    
        int getCountBowl2(){
            return bowl2->getCount();
        }
    
        int getCountBowl3(){
            return bowl3->getCount();
        }
    
        int getCountBowl4(){
            return bowl4->getCount();
        }
    
        int getCountBowl5(){
            return bowl5->getCount();
        }
    
        T *sortData(int bowl){
            int number;
            
            srand(time(0));
            
            switch (bowl) {
                case 1:
                    number = rand() % getCountBowl1();
                    return this->bowl1->removeAt(number);
                case 2:
                    number = rand() % getCountBowl2();
                    return this->bowl2->removeAt(number);
                case 3:
                    number = rand() % getCountBowl3();
                    return this->bowl3->removeAt(number);
                case 4:
                    number = rand() % getCountBowl4();
                    return this->bowl4->removeAt(number);
                default:
                    number = rand() % getCountBowl5();
                    return this->bowl5->removeAt(number);
            }
        }

};

#endif
