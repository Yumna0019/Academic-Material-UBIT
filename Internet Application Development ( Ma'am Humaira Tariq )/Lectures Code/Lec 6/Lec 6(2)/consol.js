// console.log("Start");
// setTimeout(function a() {
// console.log("Macrotask: Timeout");
// }, 0);
// Promise.resolve().then(function b() {
// console.log("Microtask: Promise");
// });
// requestAnimationFrame(function c() {
// console.log("Rendering Task: Animation Frame");
// });
// console.log("End");

// OUTPUT:
//  requestAnimationFrame()Start
//  End
//  Microtask: Promise
//  Macrotask: Timeout
//  Rendering Task: Animation Frame
 

//Explaination why requestAnimationFrame() runs last::: because it is categorized as a rendering task, which is designed to run just before the browser reflows and repaints the UI. By ensuring that requestAnimationFrame() is processed after all other asynchronous tasks (macrotasks and microtasks), the browser can smoothly handle animation frames without interruption or delay from other background tasks.


console.log("Start");

setTimeout(function a() {
  console.log("Macrotask: Timeout");
}, 0);

Promise.resolve().then(function b() {
  console.log("Microtask: Promise");
});

// Commenting out requestAnimationFrame() since it's not available in Node.js
// requestAnimationFrame(function c() {
//   console.log("Rendering Task: Animation Frame");
// });

console.log("End");
