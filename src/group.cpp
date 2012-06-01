#include <iostream>
#include "group.h"

Group::Group(std::vector<int> ids)
{
    team_slot = ids;
}

    std::vector<int> Group::Team_slot(){return team_slot;}
