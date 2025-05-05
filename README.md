# Mythical Battle Game (C Language)

A simple text-based battle game in C where the player chooses a legendary weapon, armor, and companion to face a randomly selected mythical enemy. The goal is to defeat the enemy by combining your power-ups strategically!

## 🛡️ Game Concept

The player chooses:
- One **weapon** (e.g., Excalibur, Vijaya)
- One **armor** (e.g., Armor of Achilles, Srivatsa)
- One **companion** (e.g., Cerberus, Pegasus)

The game randomly selects an enemy such as **Dracula**, **Yeti**, **Chimera**, or even the deadly **Grandpa Peter**. Each choice contributes power points. If the combined total of your power-ups exceeds the enemy's power, you win!

## 🎮 How to Play

1. Run the program.
2. Select your weapon, armor, and companion by typing the corresponding letter (a, b, c, or d).
3. The game will reveal your enemy and calculate your total power.
4. Find out if you win or lose based on your power versus the enemy’s!

## 🖥️ Compilation and Running

This game is written in **C** and uses **Windows-specific** headers like `windows.h`. To compile and run it on Windows:

### Using GCC (MinGW):

```bash
gcc game.c -o game.exe
./game.exe
