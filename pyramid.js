// Proper square pyramid (apex + square base)
// y is "up"
const vs = [
  // apex (centered over base)
  { x: 0.0,  y: 0.5,  z: 0.0 },     // 0

  // base (square, y = 0)
  { x: 0.25, y: 0.0,  z: 0.25 },    // 1  front-right
  { x: -0.25,y: 0.0,  z: 0.25 },    // 2  front-left
  { x: 0.25, y: 0.0,  z: -0.25 },   // 3  back-right
  { x: -0.25,y: 0.0,  z: -0.25 },   // 4  back-left
];

// If your renderer treats fs as:
// - [a,b] = edge
// - [a,b,c,...] = polygon face
const fs = [
  // edges from apex to base corners (4 side "ribs")
  [0, 1],
  [0, 2],
  [0, 3],
  [0, 4],

  // base perimeter edges (optional, but makes it look like a real pyramid in wireframe)
  [1, 2],
  [2, 4],
  [4, 3],
  [3, 1],

  // base face (quad)
  [1, 2, 4, 3],
];

