#include "url_shortener.h"
#include <iostream>
#include <functional>

UrlShortener::UrlShortener()
{
    // Constructor - initialize any member variables here
}

string UrlShortener::shortenUrl()
{
    string longUrl = "https://example.com";

    // Generate Hash
    hash<string> hasher;
    int hashVal = hasher(longUrl);

    // Convert to 8-char base36
    string shortUrl = toBase36(hashVal).substr(0, 8);

    urlMap[shortUrl] = longUrl;

    cout << "Shortened: " << longUrl << " -> " << shortUrl << endl;
    return shortUrl;
}

string UrlShortener::expandUrl()
{
    // TODO: Implement URL expansion logic
    cout << "expandUrl called" << endl;
    return "https://example.com"; // Stub return
}

string UrlShortener::toBase36(size_t hashVal)
{

    string result = "";
    string chars = "0123456789abcdefghijklmnopqrstuvwxyz";

    while (hashVal > 0)
    {
        int remainder = hashVal % 36;
        result = chars[remainder] + result;
        hashVal /= 36;
    }

    if (result.empty())
    {
        result = "0";
    }

    while (result.length() < 8)
    {
        result = "0" + result;
    }

    return result;
}