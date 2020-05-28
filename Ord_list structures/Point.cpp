//
// Created by Win10Pro on 25.05.2020.
//

#include "Point.h"
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