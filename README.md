# Settlers of Catan
This is a Settlers of Catan game implemented in C using Ncurses.

## Dependencies
If you want to **play the game, please install the ncurses binary**.

- Ubuntu
```
sudo apt install ncurses-bin ncurses-base
```
- Fedora
```
sudo dnf install ncurses
```
- Arch
```
sudo pacamn -S ncurses
```

If you want to **compile the game by yourself, please install the ncurses library**.

- Ubuntu
```
sudo apt install libncurses5-dev
```
- Fedora
```
sudo dnf install ncurses-devel
```
- Arch
```
sudo pacamn -S ncurses
```
**After compilation, don't forget to install the ncurses binary to run the game.**

## System Requirements
- Linux, x64 recommended
- Single core CPU, with 10% usage available.
- 8 MB RAM available.
- 64 KB disk space available.
- At least 80 x 24 size terminal or CLI.

## How to Play
After launched the game, press [s] to start the game, [o] for setting options, and [q] to quit.  
While gaming:  
In your turn: press [r] to roll dice, press [e] to end your turn.
**To be added**

## Documentation
### main.c
This is where you call functions from different files to run the game.   

### tool.c
This is where you include the necessary header files for main.c.   
All functions unrelated to game board, menu, or player goes here.   

### startup.c
This is where all functions related to the startup screen should go.   

### board.c
This is where all functions for the game board and movement should go.   

### menu.c
This is where the option menu/menubar functions should go
