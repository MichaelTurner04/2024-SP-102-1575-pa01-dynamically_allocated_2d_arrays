#!/bin/bash
# Execute this whenever you want to work on the assignment,
# and run grade.sh

# sudo docker run --interactive --tty --mount type=bind,source="$(pwd)"/,target=/your_code "$(basename "$(pwd)")" fish
sudo docker run --interactive --tty --mount type=bind,source="$(pwd)"/,target=/your_code --name pa01_container dynamic_arrays fish

