//  CommonJS
function add(a, b) {
    return a + b;
}

function subtract(a, b) {
    return a - b;
}

module.exports = { add, subtract };  // Exporting



// ES Modules (ESM)
export function add(a, b) {
    return a + b;
}

export function subtract(a, b) {
    return a - b;
}

const { add, subtract } = require('./math');  // Importing

console.log(add(5, 3));       // Output: 8
console.log(subtract(10, 4)); // Output: 6

