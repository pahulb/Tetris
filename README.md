# Tetris

Tetris is a C++ implementation of the classic Tetris game. With a codebase of 2097 lines, this project utilizes C++ to create a fully playable Tetris game. It requires the use of graphics libraries to render the game, specifically `winbgim.h` and `graphics.h`.

## Features

- Classic Tetris gameplay, including line-clearing mechanics and increasing difficulty.
- Keyboard controls for intuitive gameplay.
- Visual and interactive interface rendered using `winbgim.h` and `graphics.h`.

## Prerequisites

To compile and run Tetis, ensure you have the following:

- A C++ compiler (e.g., Code Blocks).
- The `winbgim.h` and `graphics.h` libraries for graphics rendering. Download and set them up before building the project.

## Setup and Installation

1. Download the winbgim.h and graphics.h files that are located in my repository and copy the code and paste it into the main.cpp part in the software.

2. Ensure `winbgim.h` and `graphics.h` are in the appropriate directories for your compiler. For example, with Codeblocks:
   - Place `winbgim.h` in the `include` directory.
   - Place `graphics.h` in the `include` directory.
   - insert the files that you downloaded by clicking projects and adding the files.
   - By adding these files the source code will allow the software to identify where graphics.h and winbgim.h is located and what it does.

3. Compile and Run the code:
   - Compile the program by clicking on the yellow gear on the top of the program.
   - Run the program by clicking on the green play button on the top of the program aswell.
   - TIP: You can Compile and Run at the same time by press the icon with the yellow gear and green play button.
   

## Controls

| Key         | Action            |
|-------------|-------------------|
| Left Arrow  | Move left         |
| Right Arrow | Move right        |
| Down Arrow  | Hard Drop         |
| Space       | Rotate piece      |
| Escape      | Pause/Quit        |

## Gameplay

The game begins with an empty grid. Tetriminoes fall from the top of the screen, and the goal is to arrange them to form complete horizontal lines, which will then be cleared from the grid. As lines are cleared, the game increases in speed, adding to the challenge.

### Scoring System
- **Single Line Clear:** 1 points
- **Double Line Clear:** 2 points
- **Triple Line Clear:** 3 points
- **Tetris (4 Lines):**  4 points

## Technical Details

The game is built with a modular structure and employs fundamental C++ programming principles:
- **Game Mechanics:** Handles the logic for piece movement, rotation, collision detection, and line clearing.
- **Graphics:** Rendered using `winbgim.h` and `graphics.h`, creating a classic retro aesthetic.

## Future Enhancements

- **Leaderboard:** Implement a system to save high scores.
- **Sound Effects:** Integrate basic audio feedback for actions like line clears and game over.

## Contributions

Contributions, bug reports, and feature requests are welcome! Please fork the repository and submit a pull request or open an issue.

## Game preview:

https://github.com/user-attachments/assets/adce6457-9d8a-4392-9440-45b658ae3f52

## This video shows the pausing and playing feature which you can reconize on the right hand side, shows the graphics, shows the score and levels feature and lastly at the end what happens if the blocks reach the top (GAME OVER)

---

Enjoy playing Tetis! 🎮
