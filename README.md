# Rustic Scene – OpenGL 3D Graphics Project

This project is a 3D graphical simulation of a **rural environment** developed using **OpenGL** and the **GLM** mathematics library. The application demonstrates various computer graphics concepts, including camera navigation, fog effects, texture mapping, and shadow generation.

---

## 📌 Overview

The main goal of this project is to build a visually rich and interactive rustic landscape by combining advanced OpenGL features with structured object-oriented programming. The scene simulates a peaceful countryside area with hills, rivers, forests, rustic houses, and other nature-inspired elements.

---

## 🌄 Scene Description

The 3D environment includes:

- Rolling hills of various sizes
- A flowing river splitting across the terrain
- Forests, bushes, flowers, and trees of diverse colors
- Rustic houses scattered near the lake or on the hills
- A windmill on a hill surrounded by horses
- A church on the highest hill with rocks and vegetation
- Stone bridges connecting elevated terrain
- A central barn and a rustic park with ducks, benches, a cabin, and outdoor seating

Images of the rendered scene in multiple modes can be found in the [`scene_screenshots/`](./scene_screenshots) folder.

---

## 🔧 Implemented Features

- **Camera system**: Move forward, backward, left, right; rotate view via mouse
- **Rendering modes**:
  - Solid (`Z` key)
  - Wireframe (`X` key)
  - Point (`C` key)
- **Texture mapping** on imported Blender models
- **Fog effect** implemented in the fragment shader
- **Shadow generation** using shadow mapping technique
- **Directional light rotation** via `J` and `L` keys

---

## 🎮 Controls

| Key | Action |
|-----|--------|
| `W` | Move camera forward |
| `S` | Move camera backward |
| `A` | Move camera left |
| `D` | Move camera right |
| Move mouse | Rotate camera view |
| `Z` | Switch to Solid mode |
| `X` | Switch to Wireframe mode |
| `C` | Switch to Point mode |
| `J` / `L` | Rotate directional light source (shifts shadows) |

---

## 🧱 Technologies Used

- **OpenGL**
- **GLM (OpenGL Mathematics)**
- **C++**
- **Blender** for modeling and exporting `.obj` files
- **Custom shaders** for rendering, fog, lighting, and shadows

---

## 📷 Scene Snapshots

The folder [`scene_screenshots/`](./scene_screenshots) contains:
- Rendered images of the environment in:
  - **Solid mode**
  - **Wireframe mode**
  - **Point mode**

---

## 🚀 Future Improvements

- Add point lights (e.g., lanterns for a night scene)
- Implement dynamic weather: rain, lightning
- Expand the interactive elements within the scene
- Switch between day and night modes

---
