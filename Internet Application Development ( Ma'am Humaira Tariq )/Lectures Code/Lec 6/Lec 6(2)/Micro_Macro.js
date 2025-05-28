console.log('stack [1]');
setTimeout(() => console.log("macro [2]"), 0);
setTimeout(() => console.log("macro [3]"), 1);

const p = Promise.resolve();
p.then(() => {
setTimeout(() => {
console.log('stack [4]')
setTimeout(() => console.log("macro [5]"), 0);
p.then(() => console.log('micro [6]'));
}, 0);
console.log("stack [7]");
});

console.log("macro [8]");

// OUTPUT:
// stack [1]
// macro [8]
// stack [7]
// macro [2]
// macro [3]
// stack [4]
// micro [6]
// macro [5]