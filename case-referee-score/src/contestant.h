#include <iostream>
#include <algorithm>
#include <deque>

// 选手
class Contestant
{
private:
    std::deque<double> score; 
public:
    Contestant();
    void add_score(const double &val);
    void view_score();
    double get_average_score();
    ~Contestant();
};