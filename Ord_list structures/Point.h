//
// Created by Win10Pro on 23.05.2020.
//

#ifndef LAB_6_ORDERED_LIST__POINT_H
#define LAB_6_ORDERED_LIST__POINT_H

#include <vector>
#include <iostream>

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

bool operator > (Point& a, Point& b){
    if(a.x_cor > b.x_cor)
        return true;
    if(a.x_cor < b.x_cor)
        return false;
    if(a.y_cor > b.y_cor)
        return true;
    if(a.y_cor < b.y_cor)
        return false;
    if(a.z_cor > b.z_cor)
        return true;
    if(a.z_cor < b.z_cor)
        return false;
    return false;
}
bool operator < (Point& a, Point& b){
    if(a.x_cor < b.x_cor)
        return true;
    if(a.x_cor > b.x_cor)
        return false;
    if(a.y_cor < b.y_cor)
        return true;
    if(a.y_cor > b.y_cor)
        return false;
    if(a.z_cor < b.z_cor)
        return true;
    if(a.z_cor > b.z_cor)
        return false;
    return false;
}
bool operator >= (Point& a, Point& b){
    if(a.x_cor > b.x_cor)
        return true;
    if(a.x_cor < b.x_cor)
        return false;
    if(a.y_cor > b.y_cor)
        return true;
    if(a.y_cor < b.y_cor)
        return false;
    if(a.z_cor > b.z_cor)
        return true;
    return a.z_cor >= b.z_cor;
}
bool operator <= (Point& a, Point& b){
    if(a.x_cor < b.x_cor)
        return true;
    if(a.x_cor > b.x_cor)
        return false;
    if(a.y_cor < b.y_cor)
        return true;
    if(a.y_cor > b.y_cor)
        return false;
    if(a.z_cor < b.z_cor)
        return true;
    return a.z_cor <= b.z_cor;
}
bool operator == (Point& a, Point& b){
    return a.x_cor == b.x_cor && a.y_cor == b.y_cor && a.z_cor == b.z_cor;
}
bool operator != (Point& a, Point& b){
    return a.x_cor != b.x_cor || a.y_cor != b.y_cor || a.z_cor != b.z_cor;
}
std::ostream& operator <<(std::ostream& os, Point& a){
    return  os << a.x_cor <<"\t"<< a.y_cor <<"\t"<< a.z_cor;
}



#endif //LAB_6_ORDERED_LIST__POINT_H
