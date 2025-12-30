<img width="700" height="699" alt="screenshot-2025-12-29_00-54-51" src="https://github.com/user-attachments/assets/c53213e2-dde9-41df-bd89-b5a34c90a194" />

# 3DRen 🧊✨  
*A tiny 3D wireframe renderer (C++ ➜ Python ➜ JavaScript)*

This is a **learning project**, not a game engine 😄  
The goal is to understand **3D math + rendering from scratch**, without WebGL, Three.js, or magic.

---

## What this project does 🧠

- Take **3D points** from a C++ program
- Convert them into JavaScript automatically
- Render them as a **rotating wireframe** on an HTML canvas
- Uses only:
  - basic math 📐
  - Canvas 2D 🎨
  - zero external libraries 🚫

---

## Folder structure 📁
.
├── main.cpp # take 3D points (C++)
├── points.json # intermediate data
├── generator.py # JSON → JS converter
├── curr.js # auto-generated (DO NOT EDIT)
├── index.js # renderer + math
└── main.html # opens the canvas


---

## How the pipeline works 🔄

### 1️⃣ C++ (`main.cpp`)
- You enter 3D points `(x, y, z)`
- They are written to `points.json`

👉 C++ **does NOT render anything**

---

### 2️⃣ Python (`generator.py`)
- Reads `points.json`
- Generates:
  - `vs` → vertices
  - `fs` → edges (all possible pairs)
- Injects them into `curr.js`


---

### 3️⃣ JavaScript (`index.js`)

Each frame:
1. Rotate points 🔄
2. Push them forward (+z) 📦
3. Project 3D → 2D 👀
4. Draw lines on canvas ✏️

No matrices yet — everything is explicit so it’s easy to debug.

---

## How to run ▶️

### Step 1: Compile & run C++
g++ main.cpp -o main.exe
./main.exe

### Step 2: Run HTML file
xdg-open main.html

## Important rules ⚠️

z must be > 0 (no division by zero ❌)

This is wireframe only

No clipping, no depth buffer



```

