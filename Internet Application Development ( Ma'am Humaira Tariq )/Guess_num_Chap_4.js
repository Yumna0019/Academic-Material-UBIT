// Guessing game using window.alert
// let thinkingOf, guess;
// thinkingOf = Math.ceil(Math.random() * 1000);
// guess = window.prompt("I'm thinking of a number between 1 and 1000." + " What is it?", "");
// while (guess != thinkingOf) {
//   // Evaluate the user's guess
//   if (guess < thinkingOf) {
//     guess = window.prompt("Your guess of " + guess + " was too low. Guess again.", "");
//   } else {
//     guess = window.prompt("Your guess of " + guess + " was too high. Guess again.", "");
//   }
// }
// // Game over; congratulate the user
// window.alert(guess + " is correct!");

// Guessing game with readline
const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const thinkingOf = Math.ceil(Math.random() * 1000);

function askGuess() {
  rl.question(
    "I'm thinking of a number between 1 and 1000. What is it? ",
    function handleGuess(answer) {
      const guess = Number(answer);
      if (guess < thinkingOf) {
        rl.question(
          `Your guess of ${guess} was too low. Guess again: `,
          handleGuess
        );
      } else if (guess > thinkingOf) {
        rl.question(
          `Your guess of ${guess} was too high. Guess again: `,
          handleGuess
        );
      } else {
        console.log(`${guess} is correct!`);
        rl.close();
      }
    }
  );
}

askGuess();

// TypeOf.js
var i;
var j;
j = "Not a number";
console.log("i is " + typeof i + "\n" + "j is " + typeof j);

// Output:  i is undefined
//          j is string

// Enumerating Properties :Enumerating properties means listing all the keys (property names) of an object — usually with a loop — to see what data it contains.
// Inspect all properties of an object.
// Loop through them to display, modify, or copy.

var hash = new Object();
hash.kim = "85";
hash.sam = "92";
hash.lynn = "78";
for (var aName in hash) {
  window.alert(aName + " is a property of hash.");
}
// OUTPUT:
//  kim is a property of hash.
//  sam is a property of hash.
//  lynn is a property of hash.

// Array Notation
var hash = new Object();
hash.kim = "85";
hash.sam = "92";
hash.lynn = "78";
for (var aName in hash) {
  window.alert(aName + " scored " + hash[aName]);
}

// Output:
//  kim scored 85
//  sam scored 92
//  lynn scored 78

// Object References  :In JavaScript, objects are assigned and passed by reference, not by value.
// ObjRef.js
var o1 = new Object();
o1.data = "Hello";
var o2 = o1;
o2.data += " World!";
window.alert(o1.data);

// Output: Hello World!

// ObjArg.js
function objArgs(param1, param2) {
  // Change the data in param1 and its argument
  param1.data = "changed";
  // Change the object referenced by param2, but not its argument
  param2 = param1;
  window.alert("param1 is " + param1.data + "\n" + "param2 is " + param2.data);
  return;
}
// Create two different objects with identical data
var o1 = new Object();
o1.data = "original";
var o2 = new Object();
o2.data = "original";
// Call the function on these objects and display the results
objArgs(o1, o2);
window.alert("o1 is " + o1.data + "\n" + "o2 is " + o2.data);

// Output :
// o1 is original
// o2 is original

// o1 is changed
// o2 is original

// Array
// ArrayMethods.js
var numArray = [1, 3, 8, 4, 9, 7, 6, 2, 5];
// Sort in ascending order
numArray.sort(function compare(first, second) {
  return first - second;
});
// numArray.toString(): 1,2,3,4,5,6,7,8,9
numArray.splice(2, 0, 2.5);
// numArray.toString(): 1,2,2.5,3,4,5,6,7,8,9
// output of following: 5,6,7
window.alert(numArray.splice(5, 3).toString());
// numArray.toString(): 1,2,2.5,3,4,8,9
window.alert(numArray.toString());

// stack.js
var stack = new Array();
stack.push("H");
stack.push("i");
stack.push("!");
var c3 = stack.pop(); // pops '!'
var c2 = stack.pop(); // pops 'i'
var c1 = stack.pop(); // pops 'H'
window.alert(c1 + c2 + c3); // displays "Hi!"






// 4.11 drawGrid() 
let grid = [
  ["X", 0, 0],
  [0, "X", 0],
  [0, "X", 0],
];

function drawGrid(arr) {
  let result = "";
  for (let i = 0; i < arr.length; i++) {
    result += arr[i].join(" | ") + "\n";
  }
  alert(result);
}

drawGrid(grid);

//  Output: 
// X | 0 | 0
// 0 | X | 0
// 0 | X | 0

