#include <cstdlib>
#include <iostream>
#include <ctime>
#include "tournament.h"

class Match;
void clear_screen();

int main(int argc, char **argv)
{
    try
    {
    srand((unsigned)time(0));
    Tournament world_cup(4,4);
    char option = 'x';
    int counter = 0;
    do
    {
        clear_screen();
        std::cout << counter++ << "\nMenu\n";
        std::cout << "E[x]it - [G]roups - [C]ountries\n";
        std::cin.get(option);
        std::cin.ignore(256,'\n');
        switch(option)
        {
            case 'G':
            case 'g':
                world_cup.print_group_list();
                break;
            case 'C':
            case 'c':
                world_cup.print_team_list();
                break;
        }
        char temp='.';
        std::cin.get(temp);
        std::cin.ignore(256,'\n');
        
    } while(option != 'x');
    }
    // This guarantees that anything constructed inside that block 
    // will be deconstructed in case of an exception. 
    // TODO: Place proper custom Exceptions.  This won't allow me to
    // differentiate between errors.
    catch ( ... )
    {
        
    }
}

void clear_screen()
{
    #ifdef _WIN32 
    system ( "cls" ); 
    #else 
    // Assume POSIX 
    system ( "clear" ); 
    #endif
}

