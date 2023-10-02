#!/bin/bash
cd "$(git rev-parse --show-toplevel)" && git ls-files -o -i --exclude-from=.gitignore
