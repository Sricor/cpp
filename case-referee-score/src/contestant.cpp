#include "contestant.h"

Contestant::Contestant()
{

}

void Contestant::add_score(const double &val)
{
    this->score.push_back(val);
}

void Contestant::view_score()
{
    for (int i = 0; i < this->score.size(); i++)
    {
        std::cout << this->score[i] << "  ";
    }
    std::cout << std::endl;
}

double Contestant::get_average_score()
{
    double average_score = 0;
    std::sort(this->score.begin(), this->score.end());  // 排序
    this->score.pop_back();     // 去除最高分
    this->score.pop_front();    // 去除最低分

    for (std::deque<double>::iterator iv = this->score.begin(); iv != this->score.end(); iv++)
    {
        average_score += *iv;
    }

    average_score /= this->score.size();
    return average_score;
}

Contestant::~Contestant()
{

}