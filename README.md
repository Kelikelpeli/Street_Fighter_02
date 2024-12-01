# Street Fighter: Bonus Car

## Description

This project recreates a simplified version of the **Street Fighter Bonus Car Stage**, using the **Raylib** library and an object-oriented architecture in **C++**. The goal is to relive this iconic stage while improving graphics and sounds for an engaging gaming experience.

## Running the Game

To run the `.exe` file of the game outside of Visual Studio, make sure that the resources (images, sounds, textures) are in the same relative directory as the executable, as they are necessary for the correct functioning of the game. You can find the executables in the `bin` folder (both in Debug and Release mode).

## Instructions to Play

- **Arrow Keys**: Move the character.
- **Space**: Jump.
- **Q**: Perform a light punch.
- **T**: Perform a strong punch.
- Destroy the car before the timer reaches zero to win.

## Project Structure

- **`Game` Folder**: Contains the main classes of the game, such as `Ken`, `Car`, and `CharacterState`. These classes handle the logic and behavior of the game mechanics.
- **`Menu` Folder**: Includes the scripts for the menu screens, such as the title screen, options, and the end game screen.
- **`States` Folder**: Contains scripts for managing the different states of the game, such as `IdleState`, `WalkForwardState`, and `JumpUpState`.
- **`Managers` Folder**: Includes classes for managing game elements like `GameManager`, `AudioManager`, and `TextureManager`.

## Implemented Features

- State-based screen navigation (TITLE, INTRO, GAMEPLAY, ENDING).
- Character movement, attacks, and collision detection with the car.
- Timer and score system.
- Visual effects for the destruction of the car.

## Additional Improvements

1. **Sound and Effects**: Added background music during the gameplay and menus.
2. **Automatic Restart Screen**: At the end of the game, an option was added to automatically return to the title screen and enhanced the "WIN" or "LOSE" screens with animations and sound effects for a polished ending.
3. **Dynamic Counter**: A visual countdown timer implemented using sprite maps for added visual appeal.

## References

- **Sprites**. Retrieved from: https://www.spriters-resource.com/arcade/streetfighter2
-**Soundtrack**. Retrieved from: https://downloads.khinsider.com/game-soundtracks/album/street-fighter-ii-the-definitive-soundtrack
- **Gameday Font**. Retrieved from: https://www.dafont.com/es/gameday.font
- **Sound, Image, and Texture Resources**: Material provided by the professor through the ZIP file InitialSource.zip

## Credits

Developed by: **Raquel López Barceló**