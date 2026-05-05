<p align="center">
  <img src="https://img.shields.io/badge/Score-115%2F100-brightgreen?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white" />
  <img src="https://img.shields.io/badge/42_Network-000000?style=for-the-badge&logo=42&logoColor=white" />
  <img src="https://img.shields.io/badge/Raycasting-Engine-ff6b35?style=for-the-badge" />
</p>

<h1 align="center">🎮 cub3D</h1>

<p align="center">
  <i>My first RayCaster with miniLibX.</i>
  <br><br>
  A Wolfenstein 3D-inspired raycasting engine built from scratch in C.<br>
  Renders a 3D perspective view from a 2D map using the <b>DDA algorithm</b>,<br>
  with textured walls, floor/ceiling colors, and real-time player movement.
</p>

---

## 📋 Table of Contents

- [About](#-about)
- [How Raycasting Works](#-how-raycasting-works)
- [Features](#-features)
- [Map Format](#-map-format)
- [Controls](#-controls)
- [Getting Started](#-getting-started)
- [Technical Details](#-technical-details)
- [Project Structure](#-project-structure)
- [Author](#-author)

---

## 💡 About

**cub3D** is a 42 School graphics project inspired by the legendary [Wolfenstein 3D](https://en.wikipedia.org/wiki/Wolfenstein_3D) (1992) — the game that pioneered the first-person shooter genre. Using the **raycasting** technique, we create a 3D perspective illusion from a 2D grid map.

> Raycasting is not raytracing — it's a clever 2D trick that casts one ray per screen column, making it fast enough to run in real-time even on early 90s hardware.

---

## 🔦 How Raycasting Works

For each vertical column of the screen, a ray is cast from the player's position:

```
              Player's FOV (60°)
                    
         ╱‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾╲
        ╱                     ╲
       ╱    Ray 0   Ray N      ╲
      ╱      ↗      ↗          ╲
     ╱     ↗      ↗              ╲
    ╱    ↗      ↗                 ╲
   [P] ↗     ↗    ← one ray per   ╲
    ╲       ↗        screen column  ╱
     ╲    ↗                        ╱
      ╲ ↗                         ╱
       ╲─────────────────────────╱
```

### The DDA Algorithm

**Digital Differential Analyzer** — steps through the grid cell by cell along the ray direction to find the first wall hit:

```
  ┌───┬───┬───┬───┬───┐
  │   │   │ W │ W │ W │    W = Wall
  ├───┼───┼───┼───┼───┤    P = Player
  │   │   │   │   │ W │    · = Ray path
  ├───┼───┼───┼───┼───┤
  │   │ · │ · │ · │HIT│ ← Ray hits wall here
  ├───┼───┼───┼───┼───┤
  │ P │ · │   │   │ W │    Distance determines
  ├───┼───┼───┼───┼───┤    wall height on screen
  │   │   │   │   │ W │
  └───┴───┴───┴───┴───┘
```

### Wall Height Calculation

```
wall_height_on_screen = SCREEN_HEIGHT / perpendicular_distance

Closer walls → taller on screen
Farther walls → shorter on screen
```

---

## ✨ Features

- ✅ Real-time 3D rendering via raycasting
- ✅ Textured walls (North, South, East, West)
- ✅ Configurable floor and ceiling colors
- ✅ Smooth player movement (WASD)
- ✅ Camera rotation (arrow keys / mouse)
- ✅ `.cub` map file parser with full validation
- ✅ Collision detection (can't walk through walls)
- ✅ Minimap overlay (bonus)

---

## 🗺️ Map Format

Maps are `.cub` files with texture paths, colors, and a grid:

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 135,206,235

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

| Symbol | Meaning |
|:------:|:--------|
| `0` | Empty space (walkable) |
| `1` | Wall |
| `N/S/E/W` | Player start position + facing direction |
| Spaces | Void (outside map) |

### Validation Rules

- Map must be enclosed by walls (`1`)
- Exactly one player spawn point
- Only valid characters: `0`, `1`, `N`, `S`, `E`, `W`, spaces
- All textures must be valid `.xpm` files
- Colors must be valid RGB (0-255)

---

## 🎮 Controls

| Key | Action |
|:---:|:-------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` | Rotate camera left |
| `→` | Rotate camera right |
| `ESC` | Exit game |

---

## 🚀 Getting Started

### Prerequisites

- GCC, GNU Make
- MiniLibX + X11 libraries (Linux)

```bash
# Linux
sudo apt-get install libx11-dev libxext-dev libbsd-dev
```

### Compilation & Execution

```bash
make                    # Build cub3D
./cub3D maps/map.cub    # Run with a map

make clean              # Remove .o files
make fclean             # Full clean
make re                 # Rebuild
```

---

## 🔧 Technical Details

| Aspect | Detail |
|:-------|:-------|
| **Algorithm** | DDA raycasting |
| **Rendering** | Column-by-column, pixel buffer |
| **Textures** | XPM format, mapped via wall hit position |
| **Collision** | Grid-based boundary checking |
| **FOV** | 60 degrees |
| **Performance** | O(width × grid_size) per frame |

### Fisheye Correction

Raw ray distances create a fisheye distortion. We fix this by using **perpendicular distance** instead:

```c
perp_dist = ray_dist * cos(ray_angle - player_angle);
```

---

## 📁 Project Structure

```
cub3D/
├── includes/       # Headers
├── src/            # Source files
│   ├── main.c
│   ├── parser.c
│   ├── raycaster.c
│   ├── render.c
│   ├── movement.c
│   └── textures.c
├── assets/         # Texture files (.xpm)
├── libft/          # Custom C library
├── get_next_line/  # GNL implementation
├── Makefile
├── map.cub         # Default map
└── README.md
```

---

## 👤 Author

**Adil Bourji** — [@adi7-x](https://github.com/adi7-x)

<p align="center">
  <a href="https://github.com/adi7-x"><img src="https://img.shields.io/badge/GitHub-adi7--x-181717?style=flat-square&logo=github" /></a>
  <a href="https://linkedin.com/in/adil-bourji"><img src="https://img.shields.io/badge/LinkedIn-Adil_Bourji-0A66C2?style=flat-square&logo=linkedin" /></a>
</p>

<p align="center"><sub>42 School · Common Core · Computer Graphics</sub></p>
