//
// Created by Win10Pro on 23.05.2020.
//

#include "Functions.h"

void Functions::list_push_N_random(int &N, Ord_list<Point> &ordList) {

    Point* point;
    for(int i = 0; i < N; i++){
        point = new Point(Random::double_rand(N, 2*N), Random::double_rand(N, 2*N),
                                 Random::double_rand(N, 2*N));
        std::cout<<*point<<"\n";
        ordList.push(*point);
    }

}

void Functions::array_push_N_random(int &N, Ord_array<Point> &ordArray) {

    Point* point;
    for(int i = 0; i < N; i++){
        point = new Point(Random::double_rand(N, 2*N), Random::double_rand(N, 2*N),
                          Random::double_rand(N, 2*N));
        std::cout<<*point<<"\n";
        ordArray.push(*point);
    }

}

void Functions::bst_push_N_random(int &N, Ord_bst<Point> &ordBst) {

    Point* point;
    for(int i = 0; i < N; i++){
        point = new Point(Random::double_rand(N, 2*N), Random::double_rand(N, 2*N),
                          Random::double_rand(N, 2*N));
        std::cout<<*point<<"\n";
        ordBst.push(*point);
    }

}

void Functions::avl_push_N_random(int &N, Ord_avl<Point> &ordAvl){


    Point* point;
    for(int i = 0; i < N; i++){
        point = new Point(Random::double_rand(N, 2*N), Random::double_rand(N, 2*N),
                          Random::double_rand(N, 2*N));
        std::cout<<*point<<"\n";
        ordAvl.push(*point);
    }

}

void Functions::ord_list_interactive() {
    Ord_list <Point> ordList;
    char response = 'y';
    while(response == 'y') {

        std::cout<<"Please, choose what you want to do with your Ordlist\n"
                   "0 - Push N random elements to list\n"
                   "1 - Push new element\n"
                   "2 - Delete element by index\n"
                   "3 - Print all data from list\n"
                   "4 - Search by exact value\n"
                   "5 - Search by exact range of values\n";
        int key;
        std::cin>>key;
        if(key == 0){
            std::cout<<"Please enter the amount of random elements, which you want to push\n";
            int N;
            std::cin>>N;
            list_push_N_random(N, ordList);
        }
        if(key == 1){
            std::cout<<"Please enter coordinates of new point(3 double numbers):\n";
            double x_cor_1, y_cor_1, z_cor_1;
            std::cin>>x_cor_1>>y_cor_1>>z_cor_1;
            auto* point = new Point(x_cor_1, y_cor_1, z_cor_1);
            ordList.push(*point);
        }
        if(key == 2){
            ordList.output();
            std::cout<<"Please enter the index of element, which you want to delete\n";
            int index;
            std::cin>>index;
            ordList.erase(index);
        }
        if(key == 3){
            ordList.output();
        }
        if(key == 4) {
            std::cout << "Please enter values of point, which you want to search(3 double numbers):\n";
            double x_cor_1, y_cor_1, z_cor_1;
            std::cin >> x_cor_1 >> y_cor_1 >> z_cor_1;
            auto *point = new Point(x_cor_1, y_cor_1, z_cor_1);
            std::vector<Point> res = ordList.search(*point);
            for (int i = 0; i < res.size(); i++) {
                std::cout << i << ":\t" << res[i] << "\n";
            }
        }
        if(key == 5){
            std::cout << "Please enter values of point, which you want is low limit of your range(3 double numbers):\n";
            double x_cor_1, y_cor_1, z_cor_1;
            std::cin >> x_cor_1 >> y_cor_1 >> z_cor_1;
            auto *point1 = new Point(x_cor_1, y_cor_1, z_cor_1);
            std::cout << "Please enter values of point, which you want is high limit of your range(3 double numbers):\n";
            std::cin >> x_cor_1 >> y_cor_1 >> z_cor_1;
            auto *point2 = new Point(x_cor_1, y_cor_1, z_cor_1);
            std::vector<Point> res = ordList.search(*point1, *point2);
            for (int i = 0; i < res.size(); i++) {
                std::cout << i << ":\t" << res[i] << "\n";
            }
        }

        std::cout<<"If you want to do anything else with this list press 'y', press 'n', if you don`t\n";
        std::cin>>response;

    }

}

void Functions::ord_array_interactive() {
    Ord_array <Point> ordArray;
    char response = 'y';
    while(response == 'y') {

        std::cout << "Please, choose what you want to do with your Ordlist\n"
                     "0 - Push N random elements to list\n"
                     "1 - Push new element\n"
                     "2 - Delete element by index\n"
                     "3 - Print all data from list\n"
                     "4 - Search by exact value\n"
                     "5 - Search by exact range of values\n";
        int key;
        std::cin >> key;
        if (key == 0) {
            std::cout << "Please enter the amount of random elements, which you want to push\n";
            int N;
            std::cin >> N;
            array_push_N_random(N, ordArray);
        }
        if (key == 1) {
            std::cout << "Please enter coordinates of new point(3 double numbers):\n";
            double x_cor_1, y_cor_1, z_cor_1;
            std::cin >> x_cor_1 >> y_cor_1 >> z_cor_1;
            auto *point = new Point(x_cor_1, y_cor_1, z_cor_1);
            ordArray.push(*point);
        }
        if (key == 2) {
            ordArray.output();
            std::cout << "Please enter the index of element, which you want to delete\n";
            int index;
            std::cin >> index;
            ordArray.erase(index);
        }
        if (key == 3) {
            ordArray.output();
        }
        if (key == 4) {
            std::cout << "Please enter values of point, which you want to search(3 double numbers):\n";
            double x_cor_1, y_cor_1, z_cor_1;
            std::cin >> x_cor_1 >> y_cor_1 >> z_cor_1;
            auto *point = new Point(x_cor_1, y_cor_1, z_cor_1);
            std::vector<Point> res = ordArray.search(*point);
            for (int i = 0; i < res.size(); i++) {
                std::cout << i << ":\t" << res[i] << "\n";
            }
        }
        if (key == 5) {
            std::cout << "Please enter values of point, which you want is low limit of your range(3 double numbers):\n";
            double x_cor_1, y_cor_1, z_cor_1;
            std::cin >> x_cor_1 >> y_cor_1 >> z_cor_1;
            auto *point1 = new Point(x_cor_1, y_cor_1, z_cor_1);
            std::cout
                    << "Please enter values of point, which you want is high limit of your range(3 double numbers):\n";
            std::cin >> x_cor_1 >> y_cor_1 >> z_cor_1;
            auto *point2 = new Point(x_cor_1, y_cor_1, z_cor_1);
            std::vector<Point> res = ordArray.search(*point1, *point2);
            for (int i = 0; i < res.size(); i++) {
                std::cout << i << ":\t" << res[i] << "\n";
            }
        }

        std::cout << "If you want to do anything else with this list press 'y', press 'n', if you don`t\n";
        std::cin >> response;
    }

}

void Functions::ord_bst_interactive() {
    Ord_bst <Point> ordBst;
    char response = 'y';
    while(response == 'y') {

        std::cout<<"Please, choose what you want to do with your Ordlist\n"
                   "0 - Push N random elements to list\n"
                   "1 - Push new element\n"
                   "2 - Delete element by index\n"
                   "3 - Print all data from list\n"
                   "4 - Search by exact value\n"
                   "5 - Search by exact range of values\n";
        int key;
        std::cin>>key;
        if(key == 0){
            std::cout<<"Please enter the amount of random elements, which you want to push\n";
            int N;
            std::cin>>N;
            bst_push_N_random(N, ordBst);
        }
        if(key == 1){
            std::cout<<"Please enter coordinates of new point(3 double numbers):\n";
            double x_cor_1, y_cor_1, z_cor_1;
            std::cin>>x_cor_1>>y_cor_1>>z_cor_1;
            auto* point = new Point(x_cor_1, y_cor_1, z_cor_1);
            ordBst.push(*point);
        }
        if(key == 2){
            int index = 0;
            ordBst.output(index, ordBst.root);
            std::cout<<"Please enter the index of element, which you want to delete\n";
            std::cin>>index;
            ordBst.erase(index);
        }
        if(key == 3){
            int index = 0;
            ordBst.output(index, ordBst.root);
        }
        if(key == 4) {
            std::cout << "Please enter values of point, which you want to search(3 double numbers):\n";
            double x_cor_1, y_cor_1, z_cor_1;
            std::cin >> x_cor_1 >> y_cor_1 >> z_cor_1;
            auto *point = new Point(x_cor_1, y_cor_1, z_cor_1);
            std::vector<Point> res = ordBst.search(*point);
            for (int i = 0; i < res.size(); i++) {
                std::cout << i << ":\t" << res[i] << "\n";
            }
        }
        if(key == 5){
            std::cout << "Please enter values of point, which you want is low limit of your range(3 double numbers):\n";
            double x_cor_1, y_cor_1, z_cor_1;
            std::cin >> x_cor_1 >> y_cor_1 >> z_cor_1;
            auto *point1 = new Point(x_cor_1, y_cor_1, z_cor_1);
            std::cout << "Please enter values of point, which you want is high limit of your range(3 double numbers):\n";
            std::cin >> x_cor_1 >> y_cor_1 >> z_cor_1;
            auto *point2 = new Point(x_cor_1, y_cor_1, z_cor_1);
            std::vector<Point> res = ordBst.search(*point1, *point2);
            for (int i = 0; i < res.size(); i++) {
                std::cout << i << ":\t" << res[i] << "\n";
            }
        }

        std::cout<<"If you want to do anything else with this list press 'y', press 'n', if you don`t\n";
        std::cin>>response;

    }

}

void Functions::ord_avl_interactive() {

    Ord_avl <Point> ordAvl;
    char response = 'y';
    while(response == 'y') {

        std::cout<<"Please, choose what you want to do with your Ordlist\n"
                   "0 - Push N random elements to list\n"
                   "1 - Push new element\n"
                   "2 - Delete element by index\n"
                   "3 - Print all data from list\n"
                   "4 - Search by exact value\n"
                   "5 - Search by exact range of values\n";
        int key;
        std::cin>>key;
        if(key == 0){
            std::cout<<"Please enter the amount of random elements, which you want to push\n";
            int N;
            std::cin>>N;
            avl_push_N_random(N, ordAvl);
        }
        if(key == 1){
            std::cout<<"Please enter coordinates of new point(3 double numbers):\n";
            double x_cor_1, y_cor_1, z_cor_1;
            std::cin>>x_cor_1>>y_cor_1>>z_cor_1;
            auto* point = new Point(x_cor_1, y_cor_1, z_cor_1);
            ordAvl.push(*point);
        }
//        if(key == 2){
//            int index = 0;
//            ordAvl.output(index, ordAvl.root);
//            std::cout<<"Please enter the index of element, which you want to delete\n";
//            std::cin>>index;
//            ordAvl.erase(index);
//        }
        if(key == 3){
            int index = 0;
            ordAvl.output(index, ordAvl.root);
        }
        if(key == 4) {
            std::cout << "Please enter values of point, which you want to search(3 double numbers):\n";
            double x_cor_1, y_cor_1, z_cor_1;
            std::cin >> x_cor_1 >> y_cor_1 >> z_cor_1;
            auto *point = new Point(x_cor_1, y_cor_1, z_cor_1);
            std::vector<Point> res = ordAvl.search(*point);
            for (int i = 0; i < res.size(); i++) {
                std::cout << i << ":\t" << res[i] << "\n";
            }
        }
        if(key == 5){
            std::cout << "Please enter values of point, which you want is low limit of your range(3 double numbers):\n";
            double x_cor_1, y_cor_1, z_cor_1;
            std::cin >> x_cor_1 >> y_cor_1 >> z_cor_1;
            auto *point1 = new Point(x_cor_1, y_cor_1, z_cor_1);
            std::cout << "Please enter values of point, which you want is high limit of your range(3 double numbers):\n";
            std::cin >> x_cor_1 >> y_cor_1 >> z_cor_1;
            auto *point2 = new Point(x_cor_1, y_cor_1, z_cor_1);
            std::vector<Point> res = ordAvl.search(*point1, *point2);
            for (int i = 0; i < res.size(); i++) {
                std::cout << i << ":\t" << res[i] << "\n";
            }
        }

        std::cout<<"If you want to do anything else with this list press 'y', press 'n', if you don`t\n";
        std::cin>>response;

    }

}



