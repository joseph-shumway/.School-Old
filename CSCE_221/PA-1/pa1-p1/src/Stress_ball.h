#include <iostream>
#include <string>

using std::string;

/* CREATE: enum Stress_ball_colors */
/* CREATE: enum Stress_ball_sizes */

// enum Stress_ball_colors : int {red, blue, yellow, green};
// enum Stress_ball_sizes : int {small, medium, large};
enum Stress_ball_colors {red, blue, yellow, green};
enum Stress_ball_sizes {small, medium, large};

class Stress_ball {
    public:
        Stress_ball();
        Stress_ball(Stress_ball_colors color, Stress_ball_sizes size);
        Stress_ball_colors get_color();
        Stress_ball_sizes get_size();
        bool operator==(const Stress_ball &sb);
        string color_list[4] = {"red", "blue", "yellow", "green"};
        string size_list[3] = {"small", "medium", "large"};
    private:
        Stress_ball_colors color;
        Stress_ball_sizes size;
};

std::ostream & operator <<(std::ostream &o, Stress_ball &sb);
