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

The server runs on `http://localhost:3000`

### Shorten a URL

```bash
POST /api/shorten
Content-Type: application/json

{
  "url": "https://github.com/torvalds/linux"
}

Response:
{
  "Long Url": "https://github.com/torvalds/linux",
  "Short Url": "17fcd025"
}
```

### Expand a short URL

```bash
GET /api/expand/17fcd025

Response:
{
  "Short Url": "17fcd025",
  "Long Url": "https://github.com/torvalds/linux"
}
```

## Example

```bash
# Start the server
make dev

# In another terminal, shorten a URL
curl -X POST http://localhost:3000/api/shorten \
  -H "Content-Type: application/json" \
  -d '{"url": "https://github.com/torvalds/linux"}'

# Expand the short URL
curl http://localhost:3000/api/expand/17fcd025
```
