#ifndef URL_SHORTENER_H
#define URL_SHORTENER_H

#include <string>
#include <unordered_map>

using namespace std;

class UrlShortener
{
public:
    UrlShortener();

    // Create short URL from long URL
    string shortenUrl(string longUrl);

    // Get long URL from short code
    string expandUrl(string shortUrl);

private:
    string dataFilePath;

    // Convert number to base36 string
    string toBase36(size_t hashVal);

    // Storage for URL mappings
    unordered_map<string, string> urlMap;

    void saveToFile(string longUrl, string shortUrl);

    bool loadFromFile();
};

#endif