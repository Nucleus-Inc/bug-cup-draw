//
//  list.cpp
//  bug-cup-draw
//
//  Created by Eduardo Castro on 22/12/21.
//

#ifndef LIST_CPP
#define LIST_CPP

#include <iostream>
#include "node.cpp"

using namespace std;

template<class T>
class List{
    
    private:
        Node<T> *head;
        Node<T> *tail;
        int count;
    public:
        List(){
            setHead(NULL);
            setTail(NULL);
            setCount(0);
        }
        
        void setHead(Node<T> *head){
            this->head = head;
        }
        void setTail(Node<T> *tail){
            this->tail = tail;
        }
        void setCount(int count){
            this->count = count;
        }
        
        Node<T> *getHead(){
            return (head);
        }
        Node<T> *getTail(){
            return (tail);
        }
        int getCount(){
            return (count);
        }
        
        bool isEmpty(){
            return (getHead()==NULL);
        }
        
        void addLast(T *data){
            Node<T> *newNode = new Node<T>(data);
            if(isEmpty()){
                setHead(newNode);
                setTail(newNode);
            }else{
                newNode->setPrevious(getTail());
                getTail()->setNext(newNode);
                setTail(getTail()->getNext());
            }
            setCount(getCount()+1);
        }
    
        void removeFirstNode(Node<T> *node){
            setHead(node->getNext());
            setCount(getCount()-1);
        }
        
        void removeLastNode(Node<T> *node){
            setTail(node->getPrevious());
            setCount(getCount()-1);
        }
    
        T *removeAt(int position){
            if(isEmpty() || position < 0 || position >= getCount())
                return NULL;
            
            Node<T> *node;
            if(position == 0){
                node = getHead();
                removeFirstNode(getHead());
            } else if (position == getCount() - 1) {
                node = getTail();
                removeLastNode(getTail());
            } else {
                node = getHead();
                for(int i = 0; i < position; i++){
                    node = node->getNext();
                }
                
                node->getPrevious()->setNext(node->getNext());
                node->getNext()->setPrevious(node->getPrevious());
                
                setCount(getCount()-1);
            }
            
            return node->getData();
        }
        
        void print(){
            for(Node<T> *t = getHead();t!=NULL;t=t->getNext()){
                t->getData()->toString();
                cout<<" ";
            }
        }
};

#endif
