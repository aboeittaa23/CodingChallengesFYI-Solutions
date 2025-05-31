#include "url_shortener.h"
#include <iostream>
#include <functional>
#include <fstream>
#include <ostream>

UrlShortener::UrlShortener()
{
    dataFilePath = "urls.csv";
    loadUrls();
}

string UrlShortener::shortenUrl(string longUrl)
{
    // Generate Hash
    hash<string> hasher;
    size_t hashVal = hasher(longUrl);

    // Convert to 8-char base36
    string shortUrl = toBase36(hashVal).substr(0, 8);

    // Store URL
    if (urlMap.find(shortUrl) != urlMap.end())
    {
        cerr << "Url already exists!" << endl;
    }
    else
    {
        urlMap[shortUrl] = longUrl;
        saveUrl(longUrl, shortUrl);
    }

    return shortUrl;
}

string UrlShortener::expandUrl(string shortUrl)
{
    if (urlMap.count(shortUrl) == 0)
    {
        return "";
    }
    return urlMap[shortUrl];
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

void UrlShortener::saveUrl(string longUrl, string shortUrl)
{
    ofstream file(dataFilePath, ios::app);

    if (!file.is_open())
    {
        cerr << "Error: Could not append to file " << dataFilePath << endl;
    }

    file << shortUrl << "," << longUrl << endl;
    file.close();
}

void UrlShortener::loadUrls()
{
    ifstream file(dataFilePath);

    if (!file.is_open())
    {
        cerr << "Error: Could not append to file " << dataFilePath << endl;
    }

    string line;
    while (getline(file, line))
    {
        size_t pos = line.find(',');
        if (pos != string::npos)
        {
            string shortUrl = line.substr(0, pos);
            string longUrl = line.substr(pos + 1);
            urlMap[shortUrl] = longUrl;
        }
    }
    file.close();
}