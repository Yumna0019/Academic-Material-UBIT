class Game {
  constructor(n) {
    this.name = n;
  }
  printName() {
    console.log(this.name);
  }
}
let g1 = new Game("Chess");
let g2 = new Game("Football");
console.log(g1.printName === g2.printName);
// Output: true   (bcz same method g1 and g2 have printName )



// // Prototype:
// class Game {
//   constructor(n) {
//     console.log("g method call")
//     this.name = n;
//   }
//   printName() {
//     console.log(this.name);
//   }
// }
// console.log(typeof Game);
// console.log(Game.prototype.printName);
//  Output: function
//          [Function: printName]




// // Game is a constructor 
// class Game {
//   Game(n) {
//     console.log("g method call")
//     this.name = n;
//   }
//   printName() {
//     console.log(this.name);
//   }
// }
// let g1 = new Game("Chess");
// g1.printName();

// Output : undefined           //  =>  In a JS class, the constructor must be named constructor — not the same as the class name (like Java, C++).



// // Prototypes: 
// console.log(String.prototype);
// console.log(Array.prototype);
// console.log(Number.prototype);
// console.log(Boolean.prototype);
// console.log(Function.prototype);




// shared function :  incorrect
// function Game(n) {
//     this.name = n;
//     this.printName = function () {
//         console.log(this.name);
//     };
// }

// let g1 = new Game("Chess");
// let g2 = new Game("Football");

// console.log(g1.printName === g2.printName);
// Output : false





// shared function :  correct
// function Game(n) {
//   this.name = n;
// }
// Game.prototype.printName = function () {
//   console.log(this.name);
// };


// let g1 = new Game("Chess");
// let g2 = new Game("Football");

// console.log(g1.printName === g2.printName);
// Output : true
