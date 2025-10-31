#ifndef AGENT_RATING_SYSTEM
#define AGENT_RATING_SYSTEM

#include <bits/stdc++.h>
using namespace std;

class AgentRatingSytem {
public:
    explicit AgentRatingSytem();
    void acceptRating(string agentId, int rating);
    vector<pair<string, double>> getAgentsRating();

private:
    // Map of all the ratings
    unordered_map<string, int> agentsRatingSum;
    unordered_map<string, int> agentsRatingCount;


    /*
    * Follow-up: If needed by Month
    * Sample
    * "agent1" "dec-2025" 3
    * agentsRatingMonthlySum["agent1"]["dec-2025"] = 3
    * 
    * O( N log N ) 
    * unordered_map<string, unordered_map<string, int>> agentsRatingMonthlySum;
    * unordered_map<string, unordered_set<string>> agentsRecievedMonthlyRating;
    */
};

#endif