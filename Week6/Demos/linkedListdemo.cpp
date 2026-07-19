 #include<iostream>

struct Node{
    std::string name = {};
    Node* next_node = nullptr; //read struct declaration

    //constructor: tells the computer how to build your custom data type
    Node(std::string user_data){ 
        //DEFAULT CONSTRUCTOR; make the computer figure it out
        this -> name = user_data;
    }
};
int main(){

    Node head("start");//creating a node object called head; where head is storing start
    Node* current_node = &head; //Stack and heap are constantly fighting for space so you need to 
//stack is space given to yeah and the heap is trying its best
    int user_input = 0;
// "->" helps deref values like *() 
    while (std::cin >> user_input){
        if (std::cin.fail()){
            break;
        }
        current_node -> next_node -> new Node(user_input);
        current_node = current_node -> next_node;
    }

    current_node = &head;
    while (current_node){
        std::cout << current_node-> name << " -> ";
        current_node = current_node->new_node;
    }

}