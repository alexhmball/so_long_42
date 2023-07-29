# so_long





![so_long_bonus](https://user-images.githubusercontent.com/26721576/197516954-6826c22b-95e6-4c52-9dad-d74c4f0a8bd3.gif)


So Long was my first graphical project, which provided an excellent opportunity to enhance my skills in window management, event handling, colors, textures, and other graphics-related concepts. The primary objective of this project was to create a basic 2D game using the MiniLibX, a graphical library developed internally by the school. The game involved a character, collectibles, and an exit, where the player's goal was to collect all the items and then find the shortest route to escape.

## Learning Goals
So Long allowed me to achieve the following learning goals:

1. **Graphics Programming:** I learned the basics of graphics programming by using the MiniLibX to manage windows, display images, and handle user input (keyboard and mouse events).

2. **Map Parsing and Validation:** I implemented a map parser to read the map description from a file with the .ber extension. The parser validated the map's structure, ensuring it contained walls, collectibles, and free spaces arranged in a rectangular shape with an exit and a starting position.

3. **Smooth Window Management:** I focused on ensuring smooth window management, allowing users to switch between windows, minimize, and close the window cleanly. The ESC key and the close button on the window frame were used to exit the program.

4. **User Movement:** I implemented character movement using the W, A, S, and D keys, allowing players to move up, down, left, and right on the map.

5. **Error Handling:** I implemented comprehensive error handling to deal with misconfigurations or invalid maps gracefully. If the map had duplicate characters for the exit and starting position or failed to meet other rules, the program displayed an appropriate error message and exited cleanly.

## Details
The mandatory part of the So Long project required the following:

Program Name: so_long
Turn in Files: Makefile, *.h, *.c, maps, textures
Arguments: NAME, all, clean, fclean, re
The project used the MiniLibX library for window management, image display, and event handling. The map file (*.ber) provided as a parameter to the program was parsed and validated for the game to run correctly.

The main features of the game included:

 - Gameplay: The player aimed to collect all the collectibles on the map and find the shortest path to the exit to win the game.

 - Character Movement: The player could move the main character using the W, A, S, and D keys (or ZQSD/arrow keys).

 - 2D View: The game utilized a top-down or profile view to present the 2D environment to the player.

 - Window Management: Smooth window management allowed users to interact with the game seamlessly.

 - Exit Mechanism: The game could be closed cleanly by pressing the ESC key or clicking the close button on the window frame.

## Reflection
So Long was an exciting and rewarding project that introduced me to the world of graphics programming. Implementing a basic 2D game from scratch, including map parsing, character movement, and error handling, was both challenging and fulfilling.

I appreciated the opportunity to work with the MiniLibX, as it allowed me to gain a deeper understanding of window management, event handling, and graphics display. Additionally, the project emphasized the importance of proper memory management and error handling, ensuring a smooth and reliable user experience.

Overall, So Long was a fantastic learning experience, and I look forward to exploring more complex graphical projects in the future. The project not only improved my C programming skills but also sparked my interest in game development and graphical applications.
