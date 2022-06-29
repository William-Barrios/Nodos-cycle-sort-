#include <iostream>
using namespace std;

class Node
{
    public:
    int data;//el dato
    Node* next;//puntero al siguiente nodo
    Node(int d, Node* n=NULL){//constructor del nodo
        data = d;//va el dato
        next = n;//puntero a siguiente nodo
    }
    void print(){
      cout<<data;
    }
};

class List
{
    public:
    Node* head;
    Node* end;
    List(){//por default
        head = NULL;
        end = NULL;
    }
    ~List(){
        cout<<"Destruyendo lista"<<"\n";
        Node* p = head;
        while(p){
            p = p->next;
            delete head;
            head = p;
        }
    }
    void add(int d){
        Node* new_node = new Node(d);
        if(head)// No vacia
            end->next = new_node;
        else//vacia
            head = new_node;
        end = new_node; 
    }
    void print(){
        Node* p = head;
        while(p){
            if (p->next != nullptr)
                cout<<p->data<<",";
            else
                cout<<p->data;
            p=p->next;
        }
        cout<<"\n";
    }
    void Cycle_Sort(){
        int conta= 0;
        int actual = 0;
        
        for (Node* contador=head; contador; contador = contador->next)
            conta++;

        Node* Circle=head;
        while( actual < conta){
            bool run = true;
            int cont = 0;
            while (run){
                Node* base = Circle;
                if (cont = 0)
                    Node* ostrinal = Circle;
                Node* pos = Circle;
                for (Node* Comparador = Circle->next; Comparador; Comparador=Comparador->next){
                    if (Comparador->data <  base->data){
                        cont ++; 
                        
                    }
                }
                if (cont == 0){
                    run = false;
                    if (actual==0)
                        head = Circle;
                    continue;
                }

                int x = 0;
                
                while (x < cont){
                    pos = pos->next;
                    x++; 
                }
                while (Circle->data == pos->data)
                {
                    pos = pos->next;
                }
                
                
                
                if(actual == 0){
                    Node* temp=Circle;
                    Node* temp2=Circle->next;
                    Node* temp_posprev=Circle;
                    Node* temp_pospos=NULL;
                    if(pos->next!=NULL){
                        temp_pospos=pos->next;
                    }
                    for(;temp_posprev!=NULL;temp_posprev=temp_posprev->next){
                        if(temp_posprev->next==pos){
                            break;
                        }
                    }
                    if (temp_posprev == Circle){                  
                        Circle->next = Circle->next->next;
                        pos->next = Circle;
                        Circle = pos;
                        continue;

                    }
                    temp_posprev->next=temp;
                    temp->next=temp_pospos;
                    Circle=pos;
                    Circle->next=temp2;
                    head = Circle;
                }
                else{
                    Node* temp=Circle;
                    Node* temp2=Circle->next;
                    Node* temp_posprev=Circle;
                    Node* temp_pospos=NULL;
                    if(pos->next!=NULL){
                        temp_pospos=pos->next;
                    }
                    Node*head_temp=head;
                    for(;head_temp!=NULL;head_temp=head_temp->next){
                        if(head_temp->next==base){
                            break;
                        }
                    }
                    for(;temp_posprev!=NULL;temp_posprev=temp_posprev->next){
                        if(temp_posprev->next==pos){
                            break;
                        }
                    }
                    if (temp_posprev == Circle){
                        Node* temp_head = head;
                        while (temp_head->next!=Circle)
                            temp_head=temp_head->next;
                        Circle->next = Circle->next->next;
                        temp_head->next=pos;
                        pos->next = Circle;
                        Circle = pos;
                        continue;
                    }
            
                    temp_posprev->next=temp;
                    temp->next=temp_pospos;
                    Circle=pos;
                    Circle->next=temp2;
                        

                }
                

            }
            int o = 0;
            Node* temp_head = head;
            if (actual != 0){
                while (o < actual-1){
                    temp_head=temp_head->next;
                    o++;
                }
                temp_head->next= Circle;
            }
            Circle = Circle->next;
            actual++;
            Node* Juanito = head;

            
        } 
    }
};

int main() {
  List l;
  l.add(7);
  l.add(6);
  l.add(5);
  l.add(700);
  l.add(3);
  l.add(2);
  l.add(1);
  l.print();
  cout<<"\n"<<"Aqui comienza el cicle sort"<<"\n";
  l.Cycle_Sort();
  l.print(); 
}