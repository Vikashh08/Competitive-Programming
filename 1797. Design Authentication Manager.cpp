class AuthenticationManager {
    unordered_map<string, int> expiry;
    int ttl;

public:
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }

    void generate(string tokenId, int currentTime) {
        expiry[tokenId] = currentTime + ttl;
    }

    void renew(string tokenId, int currentTime) {
        if (expiry.count(tokenId) && expiry[tokenId] > currentTime) {
            expiry[tokenId] = currentTime + ttl;
        }
    }

    int countUnexpiredTokens(int currentTime) {
        int cnt = 0;

        for (auto &it : expiry) {
            if (it.second > currentTime)
                cnt++;
        }

        return cnt;
    }
};