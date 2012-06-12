#ifndef TOURNAMENT_H
#define TOURNAMENT_H
#include <vector>
#include "team.h"
#include "group.h"

class Team;

/*!
 * This is a test comment for doxygen 
 * and the class tournament
 */
class Tournament
{
private:
    TeamContainer teams;
    GroupContainer groups;
    int num_groups;
public:
    Tournament(int ng, int tpg);
    void print_team_list();
    void print_group_list();
};
#endif
