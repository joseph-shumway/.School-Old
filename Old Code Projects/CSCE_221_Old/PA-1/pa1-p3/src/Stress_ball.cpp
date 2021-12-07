
#include "Stress_ball.h"
using std::cout;
using std::endl;



Stress_ball::Stress_ball()
{
    color = Stress_ball_colors(rand() % 4);
    size = Stress_ball_sizes(rand() % 3);
}

Stress_ball::Stress_ball(Stress_ball_colors c, Stress_ball_sizes s) {
    color = c;
    size = s;
}

bool Stress_ball::operator==(const Stress_ball &sb) const{
    if (this->color == sb.color) {
        if (this->size == sb.size) {
            return true;
        }
    }

    return false;
}

std::ostream& operator<<(std::ostream& o, const Stress_ball& sb) {
    int x = (int) sb.get_color();
    int y = (int) sb.get_size();

    cout << "(" << sb.color_list[x] << ", " << sb.size_list[y] << ")";
    return o << "(" << sb.color_list[x] << ", " << sb.size_list[y] << ")";
}

Stress_ball_colors Stress_ball::get_color() const{
    return color;
}

Stress_ball_sizes Stress_ball::get_size() const{
    return size;
}


std::istream &operator>>(std::istream &is, Stress_ball &sb) {
    string color_t = "";
    string size_temp = "";

    is >> color_t >> size_temp;

    if (color_t.empty() || size_temp.empty()) {return is;}

    Stress_ball_sizes s1;
    Stress_ball_colors c1;

    for (unsigned int i = 0; i < 4; i++) {
        if (color_t == sb.color_list[i]) {c1 = Stress_ball_colors(i);}
    }

    for (unsigned int i = 0; i < sb.size_list->size(); i++) {
        if (size_temp == sb.size_list[i]) {s1 = Stress_ball_sizes(i);}
    }

    sb.color = c1;
    sb.size = s1;

    int x = (int) sb.get_color();
    int y = (int) sb.get_size();

    cout << "(" << sb.color_list[x] << ", " << sb.size_list[y] << ")";

    return is;

}