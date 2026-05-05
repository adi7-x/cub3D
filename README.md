# cub3D - A First-Person Raycaster

<p align="center">
  <img src="https://img.shields.io/badge/C-A8B9CC?style=for-the-badge&logo=c&logoColor=black" />
    <img src="https://img.shields.io/badge/miniLibX-000000?style=for-the-badge" />
      <img src="https://img.shields.io/badge/Raycasting-FF6F00?style=for-the-badge" />
        <img src="https://img.shields.io/badge/Graphics-00C853?style=for-the-badge" />
</p>p>

## Overview
**cub3D** is a project from the 42 School curriculum that challenges students to create a first-person 3D graphical representation of a maze using the **Raycasting** technique - the same technology that powered legendary games like Wolfenstein 3D.

The project is built entirely in **C** using the **miniLibX** graphics library, focusing on geometric calculations, performance optimization, and memory management.

---

## Key Features
- **Smooth Movement**: Responsive controls with collision detection.
- - **Dynamic Texturing**: Wall textures that change based on orientation (North, South, East, West).
  - - **Floor and Ceiling**: Customizable colors for the environment.
    - - **Parsing**: Robust .cub file parser for maps and configuration.
      - - **Efficient Engine**: Optimized raycasting loop for consistent frame rates.
       
        - ---

        ## Controls
        | Key | Action |
        | :--- | :--- |
        | W / S | Move Forward / Backward |
        | A / D | Strafe Left / Right |
        | Left / Right Arrows | Rotate Camera |
        | ESC | Exit Game |

        ---

        ## Usage

        ### Compilation
        ```bash
        make
        ```

        ### Execution
        ```bash
        ./cub3D maps/map.cub
        ```

        ---

        ## Technical Details
        - **Algorithm**: DDA (Digital Differential Analyzer) for wall intersection.
        - - **Rendering**: Column-by-column pixel rendering based on perpendicular wall distance.
          - - **Memory**: Strict adherence to no leaks policy.
           
            - ---

            ## Author
            **Adil Bourji (adi7-x)**
            - GitHub: [@adi7-x](https://github.com/adi7-x)
            - - LinkedIn: [Adil Bourji](https://linkedin.com/in/adil-bourji)
             
              - ---
              <p align="center">Made for the 42 Network</p>p>
              
