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
};

#endif