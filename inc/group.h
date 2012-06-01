#ifndef GROUP_H
#define GROUP_H
#include <vector>
#include "team.h"

class Team;
class Group
{
// private:
    // std::vector<&Team> team_slot;
    std::vector<int> team_slot;
public:
    Group(std::vector<int> ids);
    std::vector<int> Team_slot();
    // void print_team_list();
};
#endif
