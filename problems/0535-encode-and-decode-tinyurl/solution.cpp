class Solution {
private:
    string current_key;
    unordered_map<string, string> mp;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(current_key.empty() || *current_key.rend() == 127)
            current_key+='0';
        else
            ++*current_key.rend();
        
        mp[current_key] = longUrl;
        return current_key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
