#include "url_shortener.h"
#include "httplib.h"

using namespace std;

int main()
{
    httplib::Server server;
    UrlShortener shortener;

    // POST /shorten - Create short URL
    server.Post("/shorten", [&](const httplib::Request &req, httplib::Response &res)
                {
                    string longUrl = req.body;
                    string shortUrl = shortener.shortenUrl(longUrl);
                    
                    if (shortUrl.empty()) {
                        res.set_content("Error: Hash collision", "text/plain");
                        res.status = 500;
                    } else {
                        res.set_content(shortUrl, "text/plain");
                    } });

    // GET /{shortCode} - Redirect to long URL
    server.Get(R"(/(\w{8}))", [&](const httplib::Request &req, httplib::Response &res)
               {
                    string shortCode = req.matches[1];
                    string longUrl = shortener.expandUrl(shortCode);
                    
                    if (longUrl.empty()) {
                        res.set_content("Short URL not found", "text/plain");
                        res.status = 404;
                    } else {
                        res.set_redirect(longUrl);
                    } });

    cout << "Server starting on http://localhost:8080" << endl;
    server.listen("localhost", 8080);
    // string shortUrl = urlShortner_obj.shortenUrl(testUrl);
    // urlShortner_obj.expandUrl(shortUrl);

    return 0;
}