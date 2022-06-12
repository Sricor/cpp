#include <iostream>
#include <algorithm>
#include <vector>

#include "contestant.h"

int main()
{
    Contestant c1, c2, c3, c4, c5;
    std::vector<Contestant> game{c1, c2, c3, c4, c5};
    
    c1.add_score(4.5);
    c1.add_score(2.5);
    c1.add_score(3.8);
    c1.add_score(5.1);
    c1.add_score(3);
    c1.view_score();
    std::cout << c1.get_average_score() << std::endl;
    return 0;
}