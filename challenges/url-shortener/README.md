# Build Your Own URL Shortener

A C++ implementation of a URL shortening service with file-based persistence.

This challenge is from [Coding Challenges](https://codingchallenges.fyi/challenges/challenge-url-shortener).

## Build

```bash
make          # Build the project
make clean    # Remove build files
```

## Usage

```bash
./shortlink
```

## Example

```bash
./shortlink
> shorten
Enter URL to shorten: https://github.com/torvalds/linux
Short URL: 2gp88xdr

> expand
Enter short code: 2gp88xdr
Original URL: https://github.com/torvalds/linux

> quit
```
