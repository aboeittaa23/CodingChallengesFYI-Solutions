#ifndef URL_SHORTENER_H
#define URL_SHORTENER_H

#include <string>

using namespace std;

class UrlShortener
{
public:
    UrlShortener();

    // Create short URL from long URL
    string shortenUrl();

    // Get long URL from short code
    string expandUrl();

private:
    // Convert number to base36 string
    string toBase36(int num);

    // Storage for URL mappings
    unordered_map<string, string> urlMap;
};

#endif