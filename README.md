# Settlers of Catan
This is a Settlers of Catan game implemented in C using Ncurses.

## System Requirements
- Linux, x64 recommended
- Single core CPU, with 5% usage available.
- 8 MB RAM available.
- 64 KB disk space available.
- At least 100 x 50 size terminal or CLI.

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

## How to Play
**Please don't change the resolution of terminal or CLI while gaming. It may cause to blank window.**  
### After launched the game
- press [s] to start the game
- press [o] for setting options
- press [q] to quit. 
- or use arrow keys to select options, and press [enter] 
### While gaming
#### In your turn
- press [r] to roll dice
- press [2] to build settlement or city
- press [3] to build roads
- press [e] to end your turn
  
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
