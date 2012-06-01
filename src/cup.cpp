/*
Groups
    team_slot[4]
    Schedule[6]  

Teams

Matches
    home (team)
    away (team)
    extra_time
*/
#include <iostream>
#include <ctime>
#include "tournament.h"

class Match;
void clear_screen();

int main(int argc, char **argv)
{
    srand((unsigned)time(0));
    Tournament world_cup(8);
    char option = 'x';
    int counter = 0;
    do
    {
        clear_screen();
        std::cout << counter++ << "\nMenu\n";
        std::cout << "E[x]it - [G]roups - [C]ountries\n";
        std::cin.get(option);
        std::cin.ignore(1,'\n');
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
        std::cin.ignore(1,'\n');
        
    } while(option != 'x');
}

void clear_screen()
{
    #ifdef WINDOWS 
    std::system ( "CLS" ); 
    #else 
    // Assume POSIX 
    std::system ( "clear" ); 
    #endif
}

