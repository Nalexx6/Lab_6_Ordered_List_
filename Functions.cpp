//
// Created by Win10Pro on 23.05.2020.
//

#include "Functions.h"

void Functions::ord_list_interactive() {
    Ord_list <Point> ordList;
    char response = 'y';
    while(response == 'y') {

        std::cout<<"Please, choose what you want to do with your Ordlist\n"
                   "1 - Push new element\n"
                   "2 - Delete element by index\n"
                   "3 - \n";
        int key;
        std::cin>>key;
        if(key == 1)
        if(key == 2)
        if(key == 3)

        std::cout<<"If you want to execute another mode press 'y', press 'n', if you don`t\n";
        std::cin>>response;

    }

}
