/**
 * In this file, implement the methods from Jeans.h
 * The implementation is identical to Stress_ball 
 */ 

#include "Jeans.h"
using std::cout;
using std::endl;



Jeans::Jeans()
{
    color = Jeans_colors(rand() % 4);
    size = Jeans_sizes(rand() % 3);
}

Jeans::Jeans(Jeans_colors c, Jeans_sizes s) {
    color = c;
    size = s;
}

bool Jeans::operator==(const Jeans &j) const{
    if (this->color == j.color) {
        if (this->size == j.size) {
            return true;
        }
    }

    return false;
}

std::ostream& operator<<(std::ostream& o, const Jeans& j) {
    int x = (int) j.get_color();
    int y = (int) j.get_size();

    cout  << "(" << j.color_list[x] << ", " << j.size_list[y] << ")";

    return o << "(" << j.color_list[x] << ", " << j.size_list[y] << ")";
}

Jeans_colors Jeans::get_color() const{
    return color;
}

Jeans_sizes Jeans::get_size() const{
    return size;
}


std::istream &operator>>(std::istream &is, Jeans &j) {
    string color_t = "";
    string size_temp = "";
    
    is >> color_t >> size_temp;

    if (color_t.empty() || size_temp.empty()) {return is;}

    Jeans_sizes s1;
    Jeans_colors c1;

    for (unsigned int i = 0; i < 5; i++) {
        if (color_t == j.color_list[i]) {c1 = Jeans_colors(i);}
    }

    for (unsigned int i = 0; i < j.size_list->size(); i++) {
        if (size_temp == j.size_list[i]) {s1 = Jeans_sizes(i);}
    }

    j.color = c1;
    j.size = s1;

    int x = (int) j.get_color();
    int y = (int) j.get_size();

    cout  << "(" << j.color_list[x] << ", " << j.size_list[y] << ")";

    return is;

}