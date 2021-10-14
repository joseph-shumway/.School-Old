#ifndef JEANS_H
#define JEANS_H

#include <iostream>
#include <string>
using std:: string;

enum class Jeans_colors : int
{
    white = 0,
    black = 1,
    blue = 2,
    grey = 3
};

enum class Jeans_sizes : int
{
    small = 0,
    medium = 1,
    large = 2,
    xlarge = 3
};



class Jeans
{
private:
    Jeans_colors color;
    Jeans_sizes size;
public:
    Jeans();
    Jeans(Jeans_colors color, Jeans_sizes size);
    Jeans_colors get_color() const;
    Jeans_sizes get_size() const;
    bool operator==(const Jeans &j) const;
    string color_list[4] = {"white", "black", "blue", "grey"};
    string size_list[4] = {"small", "medium", "large", "xlarge"};
    
    friend std::istream &operator>>(std::istream &is, Jeans &j);
};

std::ostream &operator<<(std::ostream &os, const Jeans &j);
std::istream &operator>>(std::istream &is, Jeans &j);

#endif