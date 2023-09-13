class Solution {
    unordered_map<string, string> umap;
public:
    string makeid(int length) {
    string result = "";
    const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int charactersLength = characters.length();
    
    srand(time(0)); // Seed the random number generator with the current time

    for (int i = 0; i < length; i++) {
        int randomIndex = rand() % charactersLength;
        result += characters[randomIndex];
    }
    
    return result;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string base = "http://tinyurl.com/";
        string urlCode = makeid(6);
        string url = base + urlCode;
        umap[url] = longUrl;
        return url;

        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return umap[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));