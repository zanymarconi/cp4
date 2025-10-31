#include "agent_rating_system.h"
using namespace std;

AgentRatingSytem::AgentRatingSytem() {
    agentsRatingSum.clear();
    agentsRatingCount.clear();
}

// Time: O(1)
void AgentRatingSytem::acceptRating(string agentId, int rating) {
    if (agentsRatingSum.find(agentId) == agentsRatingSum.end()) {
        agentsRatingSum[agentId] = rating;
        agentsRatingCount[agentId] = 1;
        return;
    }
    agentsRatingSum[agentId] += rating;
    agentsRatingCount[agentId] += 1;
};

// Number of Agents = N
// Time = O(N * LogN)
vector<pair<string, double>> AgentRatingSytem::getAgentsRating() {
    vector<pair<string, double>> averageAgentsRating;
    for (auto [agentId, ratingSum]: agentsRatingSum) {
        averageAgentsRating.push_back(
            {agentId, (double)ratingSum/agentsRatingCount[agentId]});
    }
    // Sort rating by decreasing order (Introsort)
    sort(averageAgentsRating.begin(), averageAgentsRating.end(), 
        [](const auto& a, const auto& b) {
            return a.second > b.second;
        });
    return averageAgentsRating;
}