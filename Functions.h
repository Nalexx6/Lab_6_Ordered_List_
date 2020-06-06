//
// Created by Win10Pro on 23.05.2020.
//

#ifndef LAB_6_ORDERED_LIST__FUNCTIONS_H
#define LAB_6_ORDERED_LIST__FUNCTIONS_H

#include "Ord_list structures/Ord_list.h"
#include "Ord_list structures/Ord_array.h"
#include "Ord_list structures/Ord_bst.h"
#include "Ord_list structures/Ord_avl.h"
#include "Ord_list structures/Ord_23.h"
#include "Random.h"

class Functions {

public:
    //Linked list
    static void list_push_N_random(int& N, Ord_list <Point>& ordList, bool benchmark);
    static void ord_list_interactive();

    //Array list
    static void array_push_N_random(int& N, Ord_array <Point>& ordArray, bool benchmark);
    static void ord_array_interactive();

    //Bst list
    static void bst_push_N_random(int& N, Ord_bst <Point>& ordBst, bool benchmark);
    static void ord_bst_interactive();

    //AVL tree list
    static void avl_push_N_random(int& N, Ord_avl <Point>& ordAvl, bool benchmark);
    static void ord_avl_interactive();

    //2-3 tree list
    static void two_three_push_N_random(int& N , Ord_23 <Point>& ord23, bool benchmark);
    static void ord_23_interactive();

    //Demo
    static void ord_list_demo();
    static void ord_array_demo();
    static void ord_bst_demo();
    static void ord_avl_demo();
    static void ord_23_demo();

    //Benchmark

    void comparison_benchmark(Point* array, std::ofstream& f, int sorted);



};


#endif //LAB_6_ORDERED_LIST__FUNCTIONS_H
