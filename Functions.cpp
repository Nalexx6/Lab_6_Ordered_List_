//
// Created by Win10Pro on 23.05.2020.
//

#include "Functions.h"

void Functions::list_push_N_random(int &N, Ord_list<Point> &ordList, bool benchmark) {

    Point* point;
    for(int i = 0; i < N; i++){
        point = new Point(Random::double_rand(N, 2*N), Random::double_rand(N, 2*N),
                                 Random::double_rand(N, 2*N));
        if(!benchmark)
            std::cout<<*point<<"\n";
        ordList.push(*point);
    }

}

void Functions::array_push_N_random(int &N, Ord_array<Point> &ordArray, bool benchmark) {

    Point* point;
    for(int i = 0; i < N; i++){
        point = new Point(Random::double_rand(N, 2*N), Random::double_rand(N, 2*N),
                          Random::double_rand(N, 2*N));
        if(!benchmark)
            std::cout<<*point<<"\n";
        ordArray.push(*point);
    }

}

void Functions::bst_push_N_random(int &N, Ord_bst<Point> &ordBst, bool benchmark) {

    Point* point;
    for(int i = 0; i < N; i++){
        point = new Point(Random::double_rand(N, 2*N), Random::double_rand(N, 2*N),
                          Random::double_rand(N, 2*N));
        if(!benchmark)
            std::cout<<*point<<"\n";
        ordBst.push(*point);
    }

}

void Functions::avl_push_N_random(int &N, Ord_avl<Point> &ordAvl, bool benchmark){


    Point* point;
    for(int i = 0; i < N; i++){
        point = new Point(Random::double_rand(N, 2*N), Random::double_rand(N, 2*N),
                          Random::double_rand(N, 2*N));
        if(!benchmark)
            std::cout<<*point<<"\n";
        ordAvl.push(*point);
    }

}

void Functions::two_three_push_N_random(int &N, Ord_23<Point> &ord23, bool benchmark) {

    Point* point;
    for(int i = 0; i < N; i++){
        point = new Point(Random::double_rand(N, 2*N), Random::double_rand(N, 2*N),
                          Random::double_rand(N, 2*N));
        if(!benchmark)
            std::cout<<*point<<"\n";
        ord23.push(*point);
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
            list_push_N_random(N, ordList, false);
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
            array_push_N_random(N, ordArray, false);
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
            bst_push_N_random(N, ordBst, false);
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
            ordBst.output();
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
            avl_push_N_random(N, ordAvl, false);
        }
        if(key == 1){
            std::cout<<"Please enter coordinates of new point(3 double numbers):\n";
            double x_cor_1, y_cor_1, z_cor_1;
            std::cin>>x_cor_1>>y_cor_1>>z_cor_1;
            auto* point = new Point(x_cor_1, y_cor_1, z_cor_1);
            ordAvl.push(*point);
        }
        if(key == 2){
            int index = 0;
            ordAvl.output(index, ordAvl.root);
            std::cout<<"Please enter the index of element, which you want to delete\n";
            std::cin>>index;
            ordAvl.erase(index);
        }
        if(key == 3){
            ordAvl.output();
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

void Functions::ord_23_interactive() {

    Ord_23 <Point> ord23;
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
            two_three_push_N_random(N, ord23, false);
        }
        if(key == 1){
            std::cout<<"Please enter coordinates of new point(3 double numbers):\n";
            double x_cor_1, y_cor_1, z_cor_1;
            std::cin>>x_cor_1>>y_cor_1>>z_cor_1;
            auto* point = new Point(x_cor_1, y_cor_1, z_cor_1);
            ord23.push(*point);
        }
        if(key == 2){
            int index = 0;
            ord23.output(index, ord23.root);
            std::cout<<"Please enter the index of element, which you want to delete\n";
            std::cin>>index;
            ord23.erase(index);
        }
        if(key == 3){
            ord23.output();
        }
        if(key == 4) {
            std::cout << "Please enter values of point, which you want to search(3 double numbers):\n";
            double x_cor_1, y_cor_1, z_cor_1;
            std::cin >> x_cor_1 >> y_cor_1 >> z_cor_1;
            auto *point = new Point(x_cor_1, y_cor_1, z_cor_1);
            std::vector<Point> res = ord23.search(*point);
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
            std::vector<Point> res = ord23.search(*point1, *point2);
            for (int i = 0; i < res.size(); i++) {
                std::cout << i << ":\t" << res[i] << "\n";
            }
        }

        std::cout<<"If you want to do anything else with this list press 'y', press 'n', if you don`t\n";
        std::cin>>response;

    }

}

void Functions::ord_list_demo() {

    Ord_list <Point> ordList;
    int N = 10, index1 = 4, index2 = 6;
    std::string breakpoint;
    std::cout<<"Firstly, we will push "<< N <<" random points to our list\n"
                "cin anything to continue\n";
    std::cin>>breakpoint;
    list_push_N_random(N, ordList, false);
    std::cout<<"This is our points in order they were pushed\n";
    std::cout<<"Now we will output the list to show, that order in list is correct\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    ordList.output();
    std::cout<<"This is our list, now we will delete point with "<< index1 <<" index\n"
                "cin anything to continue\n";
    std::cin>>breakpoint;
    ordList.erase(index1);
    ordList.output();
    std::cout<<"This is our list, now we will delete point with "<< index2 <<" index\n"
                "cin anything to continue\n";
    std::cin>>breakpoint;
    ordList.erase(index2);
    ordList.output();
    std::cout<<"This is our list, now we will execute search with bottom limit: " << N*5/4 <<", 0, 0\n"
                "and top limit: "<< N*7/4 <<", 0, 0\n"
              "cin anything to continue\n";
    std::cin>>breakpoint;
    auto* lo = new Point(N*5/4, 0 ,0);
    auto* hi = new Point(N*7/4, 0 ,0);
    std::vector <Point> res = ordList.search(*lo, *hi);
    for(int i = 0; i < res.size(); i++){
        std::cout<<i<<":\t"<<res[i]<<"\n";
    }
    std::cout<<"This is result of the search\n"
                "cin anything to continue\n";
    std::cin>>breakpoint;
    std::cout<<"This is the end of demo mode\n";
}

void Functions::ord_array_demo() {

    Ord_array <Point> ordArray;
    int N = 10, index1 = 4, index2 = 6;
    std::string breakpoint;
    std::cout<<"Firstly, we will push "<< N <<" random points to our list\n"
                                              "cin anything to continue\n";
    std::cin>>breakpoint;
    array_push_N_random(N, ordArray, false);
    std::cout<<"This is our points in order they were pushed\n";
    std::cout<<"Now we will output the list to show, that order in list is correct\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    ordArray.output();
    std::cout<<"This is our list, now we will delete point with "<< index1 <<" index\n"
                 "cin anything to continue\n";
    std::cin>>breakpoint;
    ordArray.erase(index1);
    ordArray.output();
    std::cout<<"This is our list, now we will delete point with "<< index2 <<" index\n"
                "cin anything to continue\n";
    std::cin>>breakpoint;
    ordArray.erase(index2);
    ordArray.output();
    std::cout<<"This is our list, now we will execute search with bottom limit: " << N*5/4 <<", 0, 0\n"
                 "and top limit: "<< N*7/4 <<", 0, 0\n"
                 "cin anything to continue\n";
    std::cin>>breakpoint;
    auto* lo = new Point(N*5/4, 0 ,0);
    auto* hi = new Point(N*7/4, 0 ,0);
    std::vector <Point> res = ordArray.search(*lo, *hi);
    for(int i = 0; i < res.size(); i++){
        std::cout<<i<<":\t"<<res[i]<<"\n";
    }
    std::cout<<"This is result of the search\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    std::cout<<"This is the end of demo mode\n";
}

void Functions::ord_bst_demo() {

    Ord_bst <Point> ordBst;
    int N = 10, index1 = 4, index2 = 6;
    std::string breakpoint;
    std::cout<<"Firstly, we will push "<< N <<" random points to our list\n"
                                              "cin anything to continue\n";
    std::cin>>breakpoint;
    bst_push_N_random(N, ordBst, false);
    std::cout<<"This is our points in order they were pushed\n";
    std::cout<<"Now we will output the list to show, that order in list is correct\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    ordBst.output();
    std::cout<<"This is our list, now we will delete point with "<< index1 <<" index\n"
                 "cin anything to continue\n";
    std::cin>>breakpoint;
    ordBst.erase(index1);
    ordBst.output();
    std::cout<<"This is our list, now we will delete point with "<< index2 <<" index\n"
                 "cin anything to continue\n";
    std::cin>>breakpoint;
    ordBst.erase(index2);
    ordBst.output();
    std::cout<<"This is our list, now we will execute search with bottom limit: " << N*5/4 <<", 0, 0\n"
                 "and top limit: "<< N*7/4 <<", 0, 0\n"
                 "cin anything to continue\n";
    std::cin>>breakpoint;
    auto* lo = new Point(N*5/4, 0 ,0);
    auto* hi = new Point(N*7/4, 0 ,0);
    std::vector <Point> res = ordBst.search(*lo, *hi);
    for(int i = 0; i < res.size(); i++){
        std::cout<<i<<":\t"<<res[i]<<"\n";
    }
    std::cout<<"This is result of the search\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    std::cout<<"This is the end of demo mode\n";

}

void Functions::ord_avl_demo() {

    Ord_avl <Point> ordAvl;
    int N = 10, index1 = 4, index2 = 6;
    std::string breakpoint;
    std::cout<<"Firstly, we will push "<< N <<" random points to our list\n"
                "cin anything to continue\n";
    std::cin>>breakpoint;
    avl_push_N_random(N, ordAvl, false);
    std::cout<<"This is our points in order they were pushed\n";
    std::cout<<"Now we will output the list to show, that order in list is correct\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    ordAvl.output();
    std::cout<<"This is our list, now we will delete point with "<< index1 <<" index\n"
                "cin anything to continue\n";
    std::cin>>breakpoint;
    ordAvl.erase(index1);
    ordAvl.output();
    std::cout<<"This is our list, now we will delete point with "<< index2 <<" index\n"
                 "cin anything to continue\n";
    std::cin>>breakpoint;
    ordAvl.erase(index2);
    ordAvl.output();
    std::cout<<"This is our list, now we will execute search with bottom limit: " << N*5/4 <<", 0, 0\n"
                 "and top limit: "<< N*7/4 <<", 0, 0\n"
                    "cin anything to continue\n";
    std::cin>>breakpoint;
    auto* lo = new Point(N*5/4, 0 ,0);
    auto* hi = new Point(N*7/4, 0 ,0);
    std::vector <Point> res = ordAvl.search(*lo, *hi);
    for(int i = 0; i < res.size(); i++){
        std::cout<<i<<":\t"<<res[i]<<"\n";
    }
    std::cout<<"This is result of the search\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    std::cout<<"This is the end of demo mode\n";

}

void Functions::ord_23_demo() {

    Ord_23 <Point> ord23;
    int N = 10, index1 = 4, index2 = 6;
    std::string breakpoint;
    std::cout<<"Firstly, we will push "<< N <<" random points to our list\n"
                                              "cin anything to continue\n";
    std::cin>>breakpoint;
    two_three_push_N_random(N, ord23, false);
    std::cout<<"This is our points in order they were pushed\n";
    std::cout<<"Now we will output the list to show, that order in list is correct\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    ord23.output();
    std::cout<<"This is our list, now we will delete point with "<< index1 <<" index\n"
                 "cin anything to continue\n";
    std::cin>>breakpoint;
    ord23.erase(index1);
    ord23.output();
    std::cout<<"This is our list, now we will delete point with "<< index2 <<" index\n"
                "cin anything to continue\n";
    std::cin>>breakpoint;
    ord23.erase(index2);
    ord23.output();
    std::cout<<"This is our list, now we will execute search with bottom limit: " << N*5/4 <<", 0, 0\n"
                "and top limit: "<< N*7/4 <<", 0, 0\n"
                "cin anything to continue\n";
    std::cin>>breakpoint;
    auto* lo = new Point(N*5/4, 0 ,0);
    auto* hi = new Point(N*7/4, 0 ,0);
    std::vector <Point> res = ord23.search(*lo, *hi);
    for(int i = 0; i < res.size(); i++){
        std::cout<<i<<":\t"<<res[i]<<"\n";
    }
    std::cout<<"This is result of the search\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    std::cout<<"This is the end of demo mode\n";

}


