cmake_minimum_required(VERSION 3.15)
project(Lab_6_Ordered_List_)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab_6_Ordered_List_ main.cpp Mode.cpp Mode.h Functions.cpp Functions.h "Ord_list structures/Point.h" "Ord_list structures/Ord_list.h" Random.cpp Random.h "Ord_list structures/Point.cpp" "Ord_list structures/Point.h" "Ord_list structures/Ord_array.h" "Ord_list structures/Ord_bst.h" "Ord_list structures/Ord_avl.h")