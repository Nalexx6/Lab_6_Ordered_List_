//
// Created by Win10Pro on 23.05.2020.
//

#include "Mode.h"

void Mode::interactive() {

    char response = 'y';
    while(response == 'y') {

        std::cout<<"Hello, please choose the type of structure\n"
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
        if(key == 4)
            Functions::ord_avl_interactive();
        if(key == 5)
            Functions::ord_23_interactive();

        std::cout<<"If you want to execute interactive for another type of structure press 'y', press 'n', if you don`t\n";
        std::cin>>response;

    }

}

void Mode::demo() {

    char response = 'y';
    while(response == 'y') {

        std::cout<<"Hello, please choose the type of structure\n"
                   "1 - Linked list\n"
                   "2 - Array list\n"
                   "3 - Binary search tree\n"
                   "4 - AVL tree\n"
                   "5 - 2-3 tree\n";
        int key;
        std::cin>>key;
        if(key == 1)
            Functions::ord_list_demo();
        if(key == 2)
            Functions::ord_array_demo();
        if(key == 3)
            Functions::ord_bst_demo();
        if(key == 4)
            Functions::ord_avl_demo();
        if(key == 5)
            Functions::ord_23_demo();

        std::cout<<"If you want to execute interactive for another type of structure press 'y', press 'n', if you don`t\n";
        std::cin>>response;

    }

}

void Mode::benchmark() {

    std::ofstream f("../Files/Benchmark data.txt", std::ios::trunc);
    int N = 100000;
    std::string breakpoint;
    Point* array = new Point[N];
//    double x_cor, y_cor, z_cor;
    for(int i = 0; i < N; i++){
        auto* point = new Point(Random::double_rand(0, N), Random::double_rand(0, N),
                          Random::double_rand(0, N));
        array[i] = *point;
    }
    std::cout<<"There will be 3 different benchmarks for all type of lists\n"
               "1 - randomly sorted data\n"
               "2 - almost sorted data\n"
               "3 - almost sorted data, but in reverse order\n";
    std::cout<<"Firstly we will execute benchmark for randomly sorted data,\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    for(int i = 0; i < N; i++){
        auto* point = new Point(Random::double_rand(N, 2*N), Random::double_rand(N, 2*N),
                                Random::double_rand(N, 2*N));
        array[i] = *point;
    }
    f << "Data for random sorted array\n";
    Functions::comparison_benchmark(array, f, 0);

//    std::cout<<"Now we will execute benchmark for almost sorted array,\n"
//               "cin anything to continue\n";
//    std::cin>>breakpoint;
//    f << "\n\nData for almost sorted array\n";
//    Functions::comparison_benchmark(array, f, 1);
//
//    std::cout<<"Firstly we will execute benchmark for almost sorted array, but in reverse order,\n"
//               "cin anything to continue\n";
//    std::cin>>breakpoint;
//    f << "\n\nData for almost sorted array, but in reverse order\n";
//
//    Functions::comparison_benchmark(array, f, 2);
//    std::cout<<"Results of benchmark are accessible in file: Benchmark data(3a_c).txt\n";
    f.close();
}
