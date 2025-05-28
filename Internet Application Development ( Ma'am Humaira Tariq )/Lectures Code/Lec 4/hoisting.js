// 1. Hoisting Example (Functions)
Code:
var x = six(); //CASE 1: function declaration  
function six() { return 6; }  
var y = seven(); //CASE 2: function expression  
var seven = function () { return 7; };  
console.log(x+y);

// OUTPUT: TypeError: seven is not a function




// correct :
var x = six();           //CASE 1: function declaration  
function six() { return 6; }  
var y = seven();
function seven() { return 7; }
console.log(x + y);

// 13 (output)