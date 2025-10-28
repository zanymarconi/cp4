#include<bits/stdc++.h>
using namespace std;

class AuthenticationManager {
private:
    int timeToLive;
    list<pair<int, string>> tokensExpiryList;
    unordered_map<string, list<pair<int, string>>::iterator> tokenLocator;

    void evictExpiredTokens(int currentTime) {
        while(!tokensExpiryList.empty() && tokensExpiryList.front().first <= currentTime) {
            tokenLocator.erase(tokensExpiryList.front().second);
            tokensExpiryList.pop_front();
        }
    }

    void addNewToken(string tokenId, int currentTime) {
        tokensExpiryList.push_back({currentTime + timeToLive, tokenId});
        tokenLocator[tokenId] = prev(tokensExpiryList.end());
    }

public:
    AuthenticationManager(int timeToLive): timeToLive(timeToLive) {}
    
    void generate(string tokenId, int currentTime) {
        evictExpiredTokens(currentTime);
        addNewToken(tokenId, currentTime);    
    }
    
    void renew(string tokenId, int currentTime) {
        evictExpiredTokens(currentTime);
        if (tokenLocator.find(tokenId) != tokenLocator.end()) {
            tokensExpiryList.erase(tokenLocator[tokenId]);
            tokenLocator.erase(tokenId);
            addNewToken(tokenId, currentTime);
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        evictExpiredTokens(currentTime);
        return tokensExpiryList.size();
    }
};