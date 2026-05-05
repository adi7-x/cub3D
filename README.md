<p align="center">
  <img src="https://img.shields.io/badge/Score-115%2F100-brightgreen?style=for-the-badge" />
    <img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white" />
      <img src="https://img.shields.io/badge/42_Network-000000?style=for-the-badge&logo=42&logoColor=white" />
        <img src="https://img.shields.io/badge/Raycasting-Engine-ff6b35?style=for-the-badge" />
</p>p>

<h1 align="center">cub3D</h1>h1>

<p align="center">
  <i>My first RayCaster with miniLibX.</i>i>
    <br><br>
      A Wolfenstein 3D-inspired raycasting engine built from scratch in C.<br>
        Renders a 3D perspective view from a 2D map using the <b>DDA algorithm</b>b>.
</p>p>

---

## Table of Contents

- [About](#about)
- - [How Raycasting Works](#how-raycasting-works)
  - - [Features](#features)
    - - [Map Format](#map-format)
      - - [Controls](#controls)
        - - [Getting Started](#getting-started)
          - - [Technical Details](#technical-details)
            - - [Project Structure](#project-structure)
              - - [Author](#author)
                -
                - ---
                -
                - ## About
                -
                - **cub3D** is a 42 School graphics project inspired by Wolfenstein 3D (1992). Using raycasting, we create a 3D perspective illusion from a 2D grid map. One ray per screen column makes it fast enough for real-time rendering.
                -
                - ---
                -
                - ## How Raycasting Works
                -
                - For each vertical column, a ray is cast from the player. The **DDA (Digital Differential Analyzer)** steps through grid cells to find the first wall hit. Wall height on screen = SCREEN_HEIGHT / perpendicular_distance.
                -
                - ### Fisheye Correction
                -
                - Raw ray distances create fisheye distortion. Fixed by using perpendicular distance:
                - ```c
                  perp_dist = ray_dist * cos(ray_angle - player_angle);
                  ```

                  ---

                  ## Features

                  - Real-time 3D rendering via raycasting
                  - - Textured walls (North, South, East, West)
                    - - Configurable floor and ceiling colors
                      - - Smooth player movement (WASD)
                        - - Camera rotation (arrow keys)
                          - - `.cub` map file parser with validation
                            - - Collision detection
                              - - Minimap overlay (bonus)
                                -
                                - ---
                                -
                                - ## Map Format
                                -
                                - Maps are `.cub` files with texture paths, colors, and a grid:
                                -
                                - ```
                                  NO ./textures/north.xpm
                                  SO ./textures/south.xpm
                                  WE ./textures/west.xpm
                                  EA ./textures/east.xpm

                                  F 220,100,0
                                  C 135,206,235

                                  1111111111
                                  1000000001
                                  10100N0001
                                  1000000001
                                  1111111111
                                  ```

                                  | Symbol | Meaning |
                                  |:------:|:--------|
                                  | `0` | Walkable space |
                                  | `1` | Wall |
                                  | `N/S/E/W` | Player start + direction |

                                  ---

                                  ## Controls

                                  | Key | Action |
                                  |:---:|:-------|
                                  | W | Move forward |
                                  | S | Move backward |
                                  | A | Strafe left |
                                  | D | Strafe right |
                                  | Left/Right arrows | Rotate camera |
                                  | ESC | Exit game |

                                  ---

                                  ## Getting Started

                                  ### Prerequisites

                                  ```bash
                                  # Linux
                                  sudo apt-get install libx11-dev libxext-dev libbsd-dev
                                  ```

                                  ### Compilation

                                  ```bash
                                  make
                                  ./cub3D maps/map.cub

                                  make clean    # Remove .o
                                  make fclean   # Full clean
                                  make re       # Rebuild
                                  ```

                                  ---

                                  ## Technical Details

                                  | Aspect | Detail |
                                  |:-------|:-------|
                                  | **Algorithm** | DDA raycasting |
                                  | **Rendering** | Column-by-column pixel buffer |
                                  | **Textures** | XPM format |
                                  | **Collision** | Grid-based |
                                  | **FOV** | 60 degrees |

                                  ---

                                  ## Project Structure

                                  ```
                                  cub3D/
                                  |-- includes/
                                  |-- src/
                                  |-- assets/
                                  |-- libft/
                                  |-- get_next_line/
                                  |-- Makefile
                                  |-- map.cub
                                  \-- README.md
                                  ```

                                  ---

                                  ## Author

                                  **Adil Bourji** -- [@adi7-x](https://github.com/adi7-x)

                                  <p align="center">
                                    <a href="https://github.com/adi7-x"><img src="https://img.shields.io/badge/GitHub-adi7--x-181717?style=flat-square&logo=github" /></a>a>
                                      <a href="https://linkedin.com/in/adil-bourji"><img src="https://img.shields.io/badge/LinkedIn-Adil_Bourji-0A66C2?style=flat-square&logo=linkedin" /></a>a>
                                  </p>p>
                                  
                                  <p align="center"><sub>42 School - Common Core - Computer Graphics</sub>sub></p>p>
                                  </b></i>
