#ifndef TOURNAMENT_H
#define TOURNAMENT_H
#include <vector>
#include "team.h"
#include "group.h"

class Team;
class Tournament
{
private:
    TeamContainer teams;
    GroupContainer groups;
    int num_groups;
public:
    Tournament(int);
    void print_team_list();
    void print_group_list();
};
#endif
