#include "url_shortener.h"
#include <iostream>
#include <functional>

UrlShortener::UrlShortener() {}

string UrlShortener::shortenUrl(string longUrl)
{
    // Generate Hash
    hash<string> hasher;
    size_t hashVal = hasher(longUrl);

    // Convert to 8-char base36
    string shortUrl = toBase36(hashVal).substr(0, 8);

    urlMap[shortUrl] = longUrl;

    cout << "Shortened: " << longUrl << " -> " << shortUrl << endl;
    return shortUrl;
}

string UrlShortener::expandUrl(string shortUrl)
{
    string longUrl = urlMap[shortUrl];
    cout << "expandUrl: " << longUrl << endl;
    return longUrl;
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