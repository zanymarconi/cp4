#define CATCH_CONFIG_MAIN
#include "agent_rating_system.cpp"

#include <catch.hpp>
using namespace std;

TEST_CASE("AverageRatingEmpty", "[AverageRating][NoAgent]") {
    AgentRatingSytem test;
    vector<pair<string, double>> averageAgentsRating = test.getAgentsRating();
    printf("Empty agents rating size: %d\n", averageAgentsRating.size());
    REQUIRE(averageAgentsRating.size() == 0);
}

TEST_CASE("AverageRatingSingleAgent", "[AverageRating][SingleAgent]") {
    AgentRatingSytem test;
    test.acceptRating("agent1", /* rating= */ 2);
    test.acceptRating("agent1", /* rating= */ 4);
    vector<pair<string, double>> averageAgentsRating = test.getAgentsRating();
    printf("Single Agent rating: %f\n", averageAgentsRating[0].second);
    REQUIRE(averageAgentsRating.size() == 1);
    REQUIRE(averageAgentsRating[0].second == 3.0);
}

TEST_CASE("AverageRatingMultipleAgents", "[AverageRating][MultipleAgents]") {
    AgentRatingSytem test;
    test.acceptRating("agent1", /* rating= */ 2);
    test.acceptRating("agent1", /* rating= */ 4);
    test.acceptRating("agent2", /* rating= */ 4);
    vector<pair<string, double>> averageAgentsRating = test.getAgentsRating();
    printf("First Agent rating: %f\n", averageAgentsRating[0].second);
    REQUIRE(averageAgentsRating.size() == 2);
    REQUIRE(averageAgentsRating[0].second == 4);
}

TEST_CASE("AceeptRating", "[AceeptRating][MultipleAgents]") {
    AgentRatingSytem test;
    test.acceptRating("agent1", /* rating= */ 2);
    test.acceptRating("agent1", /* rating= */ 4);
    test.acceptRating("agent2", /* rating= */ 4);
}
