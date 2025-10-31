## Agent Reporting System

Support agent rating System
1/5

Function accepts the rating for agent.
Average of rating of agents (Sorted by Decreasing Order).
Follow-up: Best agents for each month.

### Class Diagram

```plantuml
@startuml
class AgentRatingSytem {
 - unordered_map<string, int> agentsRatingSum;
 - unordered_map<string, int> agentsRatingCount;
 + acceptRating(string agentId, int rating);
 + vector<pair<string, double>> getAgentsRating();
 }
 @enduml