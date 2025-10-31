#!/usr/bin/env python3

import sys
from os import path, makedirs
from subprocess import check_call

assert "/" in sys.argv[0]

SCRIPTS_DIR = path.dirname(path.abspath(sys.argv[0]))
PROJECT_DIR = path.dirname(SCRIPTS_DIR)
GENERATED_DIR = path.join(PROJECT_DIR, "gen")


def gen(name: str):
    script_path = path.join(SCRIPTS_DIR, f"gen-{name}.py")
    check_call([sys.executable, script_path, GENERATED_DIR])


def main():
    makedirs(GENERATED_DIR, exist_ok=True)
    gen("sprites")
    gen("font")
    gen("cos-table")
    pass


if __name__ == "__main__":
    main()
