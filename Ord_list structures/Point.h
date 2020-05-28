//
// Created by Win10Pro on 25.05.2020.
//

#ifndef LAB_6_ORDERED_LIST__POINT_H
#define LAB_6_ORDERED_LIST__POINT_H

#include <iostream>
#include <vector>

class Point {
//Variables
public:
    double x_cor;
    double y_cor;
    double z_cor;

    Point (double x_cor, double y_cor, double z_cor){
        this->x_cor = x_cor;
        this->y_cor = y_cor;
        this->z_cor = z_cor;
    }
    Point () = default;

};
bool operator > (Point& a, Point& b);
bool operator < (Point& a, Point& b);
bool operator >= (Point& a, Point& b);
bool operator <= (Point& a, Point& b);
bool operator == (Point& a, Point& b);
bool operator != (Point& a, Point& b);
std::ostream& operator <<(std::ostream& os, Point& a);




#endif //LAB_6_ORDERED_LIST__POINT_H
