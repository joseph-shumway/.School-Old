
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
    int x = sb.get_color();
    int y = sb.get_size();

    return o << "(" << color_list[x] << ", " << size_list[y] << ")";
}

Stress_ball_colors Stress_ball::get_color() const{
    return color;
}

Stress_ball_sizes Stress_ball::get_size() const{
    return size;
}

// int main(int argc, char const *argv[])
// {   
//     // parameterized stress balls
//     Stress_ball ball_1 = Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::small);
//     Stress_ball ball_2 = Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::large);
//     Stress_ball ball_3 = Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::medium);
//     Stress_ball ball_4 = Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::medium);
    
//     // random stress balls
//     Stress_ball ball_5;
//     Stress_ball ball_6;

//     // test if stress balls are equal
//     bool x = false;
//     bool y = false;
//     x = (ball_1 == ball_2);
//     y = (ball_3 == ball_4);

//     // output statements
//     cout << "Ball_1: " << ball_1 << endl << endl;
//     cout << "Ball_2: " << ball_2 << endl << endl;
//     cout << "Ball_3: " << ball_3 << endl << endl;
//     cout << "Ball_4: " << ball_4 << endl << endl;
//     cout << "Ball_5: " << ball_5 << endl << endl;
//     cout << "Ball_6: " << ball_6 << endl << endl;

//     cout << "Ball_1 == Ball_2: " << x << endl << endl;
//     cout << "Ball_3 == Ball_4: " << y << endl << endl;

//     // exit
//     return 0;
// }
