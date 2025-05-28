// Global's Scope
var globalVar = 'abc';

function a() {
  // testClosures's Scope
  console.log(globalVar);
}

a(); // logs "abc"

// Scope Chain
// Inside a function perspective
// a's scope -> global's scope 






const a = 'Jonas';
first();

function first() {
  const b = 'Hello!';
  second();
  
  function second() {
    const c = 'Hi!';
    third();
  }
}
function third() {
  const d = 'Hey!';
  console.log(d + c + b + a);
}
// Output: ReferenceError: c is not defined


// solution :
const a = 'Jonas';
first();

function first() {
  const b = 'Hello!';
  second();
  
  function second() {
    const c = 'Hi!';
    
    function third() {
      const d = 'Hey!';
      console.log(d + c + b + a); // All variables are accessible
    }

    third(); // Call third inside second
  }
}        // Output:Hey!Hi!Hello!Jonas



function outer() {
    var a = 10;
  
    function inner() {
      var b = 20;
  
      console.log(a); // ✅ Finds "a" in outer(), prints 10
      console.log(b); // ✅ Finds "b" in inner(), prints 20
    }
    inner();  
    // console.log(b); ❌ Error! "b" is not found here
}
outer();
  // Output: 10
  //         20






const cars = [
    { make: 'Toyota', model: 'Corolla' },
    { make: 'Honda', model: 'Civic' },
    { make: 'Toyota', model: 'Camry' },
    { make: 'Ford', model: 'Focus' }
];

// Function to get cars by their make
function getCarsBymake(make) {
    return cars.filter(x => x.make === make); // use the parameter make
}

// Example usage
const toyotaCars = getCarsBymake('Toyota');
console.log(toyotaCars);

const hondaCars = getCarsBymake('Honda');
console.log(hondaCars);
