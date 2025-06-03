# Build Your Own URL Shortener

A TypeScript/Node.js implementation of a URL shortening service with REST API endpoints and file-based persistence.

This challenge is from [Coding Challenges](https://codingchallenges.fyi/challenges/challenge-url-shortener).

## Build

```bash
make install  # Install dependencies and TypeScript
make build    # Compile TypeScript to JavaScript
make clean    # Remove build files and dependencies
```

## Usage

```bash
make dev      # Run in development mode with hot reload
# or
make start    # Build and run production version
```

## API Endpoints

The server runs on `http://localhost:8080`

### Shorten a URL

```bash
POST /api/shorten
Content-Type: application/json

{
  "url": "https://www.example.com"
}

Response:
{
  "key":"e149be13",
  "long_url":"https://www.example.com",
  "short_url":"http://localhost:8080/e149be13"
}
```

### Expand a short URL

```bash

```

## Example

```bash
# Start the server
make dev

# In another terminal, shorten a URL
curl -X POST http://localhost:8080/ \
     -H "Content-Type: application/json" \
     -d '{"url": "https://www.example.com"}'

# Expand the short URL
curl http://localhost:8080/e149be13
```
