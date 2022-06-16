#include "reservation.h"

Reservation::Reservation()
{
    this->p_manger = NULL;
}

Reservation::~Reservation()
{
    if (this->p_manger != NULL)
    {
        delete this->p_manger;
        this->p_manger = NULL;
    }
}
void StudentIdentityManager()
{

}

void TeacherIdentityManager()
{

}

void Reservation::AdminIdentityManager()
{
    AdminManager m;
    this->p_manger = &m;
    this->p_manger->Menu();
}


void Reservation::ReservationManager()
{
    int comd;
    while (true)
    {
        std::cout << std::endl;
        std::cout << "      Reservation Manager      " << std::endl;
        std::cout << "       ------------------      " << std::endl;
        std::cout << "      |  1: Student      |     " << std::endl;
        std::cout << "      |  2: Teacher      |     " << std::endl;
        std::cout << "      |  3: Admin        |     " << std::endl;
        std::cout << "      |  0: Exit         |     " << std::endl;
        std::cout << "       ------------------      " << std::endl;
        std::cout << std::endl;

        std::cout << "Please select your identity: ";
        std::cin  >> comd;

        switch (comd)
        {
        case 1:  //this->StudentIdentityManager(); break;
        case 2:  //this->TeacherIdentityManager(); break;
        case 3:  this->AdminIdentityManager();   break;
        case 0:  exit(0);
        default: break;
        }
    }
}