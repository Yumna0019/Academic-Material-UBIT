// //  Code : 1
// const x = 1;
// const inner = () => {
//     console.log(x);    // Output: 1 
// };

// const outer = () => {
//     const x = 2;
//     inner(); 
// };

// outer();



// //  Code : 2
// const x = 1;
// const outer = () => {
//     const x = 2;

//     const inner = () => {
//         console.log(x);    // Output: 2
//         }
//         return inner(); 
// };

// outer();



// // Code : 3
// let a = 10;

// function foo() {
//     console.log(a);    // 10
// }

// function bar() {
//     let a = 20;
//     foo();
// }

// bar();


// Code : 4
const outer = () => {
    const x = 2;
    const y = 1;
    const HUGE = { one: 1, two: 2 }; // typo, assuming "HUGE"

    const bar = () => {
    console.log(HUGE);
};  
const inner = () => {
    debugger;
    bar();                     // for printing (huge) ,if bar() not call here then huge will not print
    console.log(x);
};
return inner;
};

const foo = outer(); // returns inner function
foo(); // calls inner
