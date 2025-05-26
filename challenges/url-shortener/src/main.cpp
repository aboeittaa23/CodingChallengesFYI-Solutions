#include "url_shortener.h"

using namespace std;

int main()
{
    string testUrl = "https://example.com";
    UrlShortener urlShortner_obj;

    string shortUrl = urlShortner_obj.shortenUrl(testUrl);
    urlShortner_obj.expandUrl(shortUrl);

    return 0;
}