# Sokoban duel
Sokoban is a game where you need to push crates on specific locations, this verison of the game is graphical and it includes a 1v1 game mode where you need to finish before you oponent.

## Install
This game uses CSFML as graphical library, you need install it compile the game. You can find a install_csfml.sh file that will install everything for you
simply run the script like so:
```bash
./install_csfml.sh
```

## Compile
Once the CSFML installed on you machine you can compile the game. The program compiles with a makefile so you can use the rules `make`, `make clean`, `make fclean` and `make re`.
To compile simply run this command:
```bash
make
```

## Run
Once it is compiled you can run the game by running the binary that was created, so run the command:
```bash
./SOKOBAN
```
## How to play
This game is incomplete and suffered from lost files with the years, you will find that there is no tutorial on how to play the game.

### Gale rules
The rules are simple:
- Push the crates with your character on the desired locations (the yellow dots), you cannot pull them.
- If you pushed all the crates on the desired locations you successfully finished the map
- If one crate is stuck, push all the other crates on the desired location or stuck them in a corner as well. The game will exit by itself, but you can also exit the level anytime with the escape key.

### Controls
To navigate back it is always the escape button
#### 1 Player controls
If you play the solo version use the arrow keys to control your character

#### 2 Player controls
If you play the duel version of the game the player 1 (on the left) uses the ZQSD key (I know french layout 🤷‍♂️) to control its player, the player 2 (on the right) uses the arrow keys to its player.

## Last disclaimer
The game is not finished, it was made during the holidays between my first and second year and was never really finished, there are no credits and no options. There are very few maps but if you want you can create yours in a text file like the ones in the folder `assets/test_maps`. Don't forget to add them in the array `level_filepaths` located in the file `include/level.h`

# Have fun!

