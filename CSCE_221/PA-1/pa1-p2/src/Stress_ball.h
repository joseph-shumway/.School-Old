 #ifndef STRESSBALL_H
#define STRESSBALL_H

#include <iostream>
#include <string>

using std::string;

enum Stress_ball_colors{
    red = 0,
    blue = 1,
    green = 2,
    yellow = 3,
};

static string color_list[4] = {"red", "blue", "green", "yellow"};
static string size_list[3] = {"small", "medium", "large"};

enum Stress_ball_sizes{
    small = 0,
    medium = 1,
    large = 2,
};

class Stress_ball {
    public:
        Stress_ball();
        Stress_ball(Stress_ball_colors color, Stress_ball_sizes size);
        Stress_ball_colors get_color() const;
        Stress_ball_sizes get_size() const;
        bool operator==(const Stress_ball &sb) const;
    private:
        Stress_ball_colors color;
        Stress_ball_sizes size;

    friend std::istream& operator>>(std::istream &o, Stress_ball & sb);
};

std::ostream & operator<<(std::ostream &o, const Stress_ball &sb);
std::istream& operator>>(std::istream &o, Stress_ball & sb);

#endif