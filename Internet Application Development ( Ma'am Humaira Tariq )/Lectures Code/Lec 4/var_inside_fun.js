function f() {  
    a = 5;  
    b = 3;  
    var a, b; //variable declaration  
}  
f();  
console.log(a);  
console.log(b);

//  Output: ReferenceError: a is not defined


function f() {  
    a = 5;  
    b = 3;    
}  
f();  
console.log(a);  
console.log(b);

// Output: 5
//         3



//  var scope declare
var a = 10;

function print() {
    console.log(a);  // 1
    var a = 20;
    console.log(a);  // 2
}

print();

//  what happening in above var a 
function print() {
    var a;              // hoisted declaration
    console.log(a);     // logs: undefined (since only declaration is hoisted, not the assignment)
    a = 20;
    console.log(a);     // logs: 20
}



//  to solve it, declare var one time outside 
var a = 10;

function print() {
    console.log(a);  // will print 10
    a = 20;
    console.log(a);  // will print 20
}

print();




setTimeout(function greet(){
    console.log("welcome!");
},2000);

console.log("hi!");

//  Output : hi!
//           welcome!