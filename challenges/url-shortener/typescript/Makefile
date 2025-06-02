.PHONY: install dev build clean

install:
	npm init -y
	npm install express
	npm install -D typescript @types/node @types/express
	npm install -D ts-node nodemon
	npm install -D tsx
	npx tsc --init

dev:
	npx nodemon src/server.ts

build:
	npx tsc

clean:
	rm -rf dist node_modules

start: build
	node dist/server.js