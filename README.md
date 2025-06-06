# 🎮 Hangman Game in C

A simple console-based Hangman game written in C. One player enters a secret word, and another tries to guess it letter by letter before running out of attempts. The game displays a visual representation of the hangman as incorrect guesses accumulate.

---

## ✨ Features

- 👥 Two-player gameplay: one sets the word, the other guesses.
- 🎨 ASCII-art hangman drawing updates with each incorrect guess.
- 🔠 Tracks and displays guessed letters.
- 🔁 Allows replay without restarting the program.
- 📝 Supports words with spaces.

---

## 🚀 Getting Started

**Requirements:**

- 💻 C compiler (such as GCC)
- 🪟 Windows environment (`conio.h` and `system("cls")` for screen clearing and input)

**How to Compile:**
   ```bash
  gcc hangman.c -o hangman
```

**How to Run:**
```bash
    ./hangman
```


---

## 🕹️ Gameplay Instructions

1. 🧑‍💻 **Challenger**: Enter a word or phrase (spaces allowed). This will be hidden from the guesser.
2. 🧑‍🎤 **Guesser**: Enter one uppercase letter at a time to guess the word.
3. ❌ Each wrong guess draws more of the hangman.
4. 🏆 The game ends when:
   - The word is guessed correctly (**you win!**).
   - The hangman is fully drawn after 8 incorrect guesses (**you lose**).
5. 🔄 Choose to play again or exit.

---

## 🎮 Controls

- Enter guesses as **single uppercase letters**.
- Duplicate guesses are not counted.
- After each round, press `Y` or `y` to play again.

---

## 🗂️ Code Structure

- `main()`: Handles game loop and replay logic.
- `DrawTitle()`: Prints the game title.
- `ScreenToGetChallenge()`: Gets the challenge word from player one.
- `GetPlayerInput()`: Gets a single character guess from the player.
- `insertchoice()`: Records guessed letters.
- `checkthechoice()`: Checks if guess is in the word.
- `isrepeated()`: Prevents duplicate guesses.
- `PrintAcceptedWord()`: Displays the current state of the guessed word.
- `ScreenToPopupFail()`: Draws the hangman based on failed attempts.
- `rest()`: Resets game state for replay.

---

## ⚠️ Limitations

- Only supports uppercase letter guesses.
- Uses non-standard headers (`conio.h`) and `system("cls")`, so may not work on Linux/Mac without modification.
- No input validation for special characters or lowercase letters.

---

## 📺 Example
                              
                              ***********************************************************************************
                              *                                 HANGMAN  GAME                                   *
                              ***********************************************************************************
                                
                                               ____________________ 
                                              |                    |
                                              |                    |
                                              |                    |
                                              |               
                                              |               
                                              |               
                                              |               
                                              |                
                                              |
                                              |
                                              |
                                              |
                                              |
                                              |
                                              |
                                              |
                                              |
                                              |
                                              |
                                              |
                              
                                              
                              Enter Challenge : GITHUB
                              
                              
                              ***********************************************************************************
                              *                         HANGMAN GAME                                            *
                              ***********************************************************************************
                              
                                               _  _  _  _  _  _
                              
                                               ____________________
                                              |                    |
                                              |                    |
                                              |                    |
                                              |               
                                              |               
                                              |               
                                              |               
                                              |                
                                              |
                                              |
                                              |
                                              |
                                              |
                                              |
                                              |
                                              |
                                              |
                                              |
                                              |
                                              |
                              
                              
                              
                              Enter Alphabet (CAPITAL ALPHABET ONLY): Q
                              
                              ***********************************************************************************
                              *                         HANGMAN GAME                                            *
                              ***********************************************************************************
                              
                                               _  _  _  _  _  _
                              
                                               ____________________
                                              |                    |
                                              |                    |
                                              |                    |
                                              |                ----------
                                              |               |  ^    ^ |
                                              |               |    |    |
                                              |               |  -===-  |
                                              |                ---------
                                              |
                                              |
                                              |
                                              |
                                              |
                                              |
                                              |
                                              |
                                              |
                                              |
                                              |
                                              |
                              
                              
                              
                              Enter Alphabet (CAPITAL ALPHABET ONLY): G I T H U B
                              
                              ***********************************************************************************
                              *                         HANGMAN GAME                                            *
                              ***********************************************************************************
                              
                                               G  I  T  H  U  B
                              
                                               ____________________
                                              |                    |
                                              |                    |
                                              |                    |
                                              |                ----------
                                              |               |  ^    ^ |
                                              |               |    |    |
                                              |               |  -===-  |
                                              |                ---------
                                              |
                                              |
                                              |
                                              |
                                              |
                                              |
                                              |
                                              |
                                              |
                                              |
                                              |
                                              |
                              
                              
                              Congratulation....Man is alive.
                              
                              Do you want to play it again : ( y / n )


## 📝 License

This project is open-source and free to use for educational purposes.

---

## 👤 Author

- Garv Patel

---

⭐️ Feel free to fork, modify, and improve!

