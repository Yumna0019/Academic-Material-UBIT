// Code : 1
function foo(b) {
    let a = 10;
    return a + b + 11;
}
function bar(x) {
    let y = 3;
    return foo(x * y);
}

console.log(bar(7)); 
// Output: 42  



// Code : 2
const name1 = "Ali";
function first() {
  const lastname = "Ahmed";
  second();
}
function second() {
  const age = 25;
  third();
}
function third() {
  const color = "blue";
  console.log(name1, lastname, age, color);
}
first();
// Variables lastname and age are not in scope inside third() due to block scope, so this code will throw a ReferenceError.
// ReferenceError: lastname is not defined


// Solution : 
const name = "ani";
function first() {
  const lastname = "akgunes";
  second(lastname);
}
function second(lastname) {
  const age = 25;
  third(lastname, age);
}
function third(lastname, age) {
  const color = "blue";
  console.log(name, lastname, age, color);
}
first();
