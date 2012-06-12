#ifndef TEAM_H
#define TEAM_H
#include <string>
#include <vector>

class Team
{
private:
    std::string name;
public: 
    Team(std::string nam);
    std::string Name() const {return name;}
};

typedef std::vector<Team> TeamContainer;
typedef TeamContainer::iterator TCIterator;

TeamContainer debug_give_teams();
#endif
