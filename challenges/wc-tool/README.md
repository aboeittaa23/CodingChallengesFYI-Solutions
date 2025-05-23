# Build Your Own wc Tool

A C++ implementation of the Unix `wc` (word count) command line tool.

This challenge is from [Coding Challenges](https://codingchallenges.fyi/challenges/challenge-wc).

## Build

```bash
make
make clean    # Remove build files
```

## Usage

```bash
./ccwc [OPTIONS] [FILE]
```

Options:

- `-l` : Count lines
- `-w` : Count words
- `-c` : Count bytes
- `-m` : Count characters (UTF-8)

Examples:

```bash
./ccwc test.txt              # Default: lines, words, bytes
./ccwc -l test.txt           # Count lines only
cat test.txt | ./ccwc -w     # Count words from stdin
```

## Test

Run the test script to compare with system `wc`:

```bash
chmod +x test_ccwc.sh
./test_ccwc.sh test.txt
```
