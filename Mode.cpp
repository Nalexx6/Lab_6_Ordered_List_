//
// Created by Win10Pro on 23.05.2020.
//

#include "Mode.h"

void Mode::interactive() {

    char response = 'y';
    while(response == 'y') {

        std::cout<<"Hello, please choose the mode\n"
                   "1 - Linked list\n"
                   "2 - Array list\n"
                   "3 - Binary search tree\n"
                   "4 - AVL tree\n"
                   "5 - 2-3 tree\n";
        int key;
        std::cin>>key;
        if(key == 1)
            Functions::ord_list_interactive();
        if(key == 2)
            Functions::ord_array_interactive();
        if(key == 3)
            Functions::ord_bst_interactive();

        std::cout<<"If you want to execute interactive for another type of structure press 'y', press 'n', if you don`t\n";
        std::cin>>response;

    }

}

void Mode::demo() {

}

void Mode::benchmark() {

}
