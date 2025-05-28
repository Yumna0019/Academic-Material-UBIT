// The question is: **Which of the two counter implementations is correct, and why?**

// Let’s analyze both.

// ---

// ### 🟥 **Left Side:**


let count = 0; // Global

function increment() {
  count++;
  return count;
}


// #### ❌ **Why it’s not ideal:**

// * Uses **global variable** `count`.
// * Any code outside can **modify it directly**, like:

//   ```js
//   count = 999;
//   ```
// * Breaks the counter logic. It’s not **encapsulated** or **protected**.

// #### 🔴 Problem:

// Not safe or reusable. Shared global state is bad practice.

// ---

// ### ✅ **Right Side:**


function createCounter() {
  let count = 0; // Local, private

  return function() {
    count++;
    return count;
  };
}
const counter = createCounter();


// #### ✅ **Why this is correct:**

// * Uses **closure** to keep `count` **private** inside `createCounter()`.
// * No one outside can change `count` directly.
// * Each `createCounter()` call creates a **new independent counter**.

// ---

// ### ✅ Final Answer:

// > ✔️ **The right-side implementation is correct**
// > Because it uses a **closure to encapsulate state**, avoids global variables, and is reusable and safe.
