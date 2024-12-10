<div align="center">
	<h1>42-cub3D</h1>
</div>

![Gameplay Demo](https://github.com/user-attachments/assets/6c0a9dda-04c4-4b79-89df-dab8e27967e3)

### About
**42-cub3D** is a project developed as part of the 42 Network curriculum. It recreates a simple 3D game using raycasting, inspired by the classic *Wolfenstein 3D*. This project focuses on building a basic graphics engine in C, following the strict [Norminette](https://github.com/42School/norminette) coding style.

---

## Installation

### Dependencies
To compile and run cub3D, you need the following dependencies:
- **required packages** (install via terminal):
    ```bash
    sudo apt-get install gcc make libxext-dev libx11-dev libbsd-dev libxrandr-dev libxi-dev libxinerama-dev
    ```

### How to Compile
1. Clone this repository:
    ```bash
    git clone https://github.com/YourUsername/42-cub3D.git
    cd 42-cub3D
    ```

2. Compile the project:
    ```bash
    make
    - **Make download**: To download the mlx library.
    ```

3. To clean object files:
    ```bash
    make clean
    ```

4. To clean everything, including the binary:
    ```bash
    make fclean
    ```

---

## How to Play

1. Run the game with the command:
    ```bash
    ./cub3D [map.cub]
    ```
    Replace `[map.cub]` with a valid map configuration file.

2. Use the following keys to control the player:

    | Key         | Action              |
    |-------------|---------------------|
    | `W`         | Move forward        |
    | `S`         | Move backward       |
    | `A`         | Strafe left         |
    | `D`         | Strafe right        |
    | `← / →`     | Rotate camera       |
    | `ESC`       | Exit the game       |

---

## Subject Documentation
You can access the project subject [here](https://dot99.github.io/42-cub3D/).

---

<div align="center">
	<h3>Developed as part of the <a href="https://www.42.fr/">42 Network</a> curriculum.</h3>
</div>
