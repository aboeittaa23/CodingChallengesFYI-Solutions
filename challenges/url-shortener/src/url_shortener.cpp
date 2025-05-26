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
    int hashValue = hasher(longUrl);

    // Convert to 8-char base36
    string shortUrl = toBase36(hashValue).substr(0, 8);

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

string UrlShortener::toBase36(int hashValue)
{
    // TODO: Implement hash function
    return "01234567";
}