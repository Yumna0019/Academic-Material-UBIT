// great that you're exploring this JavaScript quiz app! Let's go through how **closures**, **scoping**, **arrow functions**, **HOFs (higher-order functions)**, and **inheritance** relate to this code — or if they don’t appear directly.

// ---

// ### 🔒 **Closure**

// A **closure** happens when an inner function remembers variables from its outer function even after the outer function has finished executing.

// ➡️ **Is closure used?**
// Not explicitly. However, the `setInterval` callback **closes over** the `timeLeft` variable:

const timer = setInterval(() => {
    timeLeft--;

}, 1000);


// This is a **closure** because the arrow function retains access to `timeLeft`, `timer`, and `timeDisplay` from the outer scope.

// ---

// ### 📦 **Scoping**

// Scoping determines where variables are accessible.

// ➡️ **Where is scoping used?**

// * Variables like `questions`, `currentQuestionIndex`, and `correctAnswers` are declared in the `DOMContentLoaded` callback and used by multiple nested functions.
// * Each `let` inside the `for` loop has **block scope** (e.g., `num1`, `op1`, etc.).

// **Example:**


let num1 = getRandomInt(-10, 10);

// This `num1` exists **only** inside that iteration block due to `let`.

// ---

// ### ⚡ **Arrow Functions**

// Arrow functions are used for concise function expressions and they don’t bind their own `this`.

// ➡️ **Where are they used?**


const timer = setInterval(() => {
    timeLeft--;
    
}, 1000);


// This arrow function is used as a callback for `setInterval`.

// ✅ Good use: Arrow functions are concise and perfect for small callbacks like this.

// ---

// ### 🧠 **Higher-Order Functions (HOF)**

// A HOF is a function that either:

// * Takes another function as an argument, or
// * Returns another function.

// ➡️ **Any HOFs here?**
// Yes — `setInterval` and `addEventListener` are both **HOFs** because they take **callback functions** as arguments.

// **Example:**


nextButton.addEventListener("click", checkAnswer);


// `addEventListener` is a HOF.

// ---

// ### 🧬 **Inheritance**

// JavaScript supports inheritance via prototypes and ES6 `class` syntax.

// ➡️ **Is inheritance used here?**
// ❌ No, there's no use of classes or object inheritance in this code. It’s all function-based and procedural.

// ---

// ### Summary Table

// | Concept                | Used? | Where / How                                                 |
// | ---------------------- | ----- | ----------------------------------------------------------- |
// | **Closure**            | ✅     | In the `setInterval` arrow function using outer `timeLeft`  |
// | **Scoping**            | ✅     | Through `let` and nesting functions inside DOMContentLoaded |
// | **Arrow Function**     | ✅     | Used in `setInterval`                                       |
// | **HOF (Higher-Order)** | ✅     | `setInterval`, `addEventListener`                           |
// | **Inheritance**        | ❌     | Not used — no classes or prototype chains involved          |

// Let me know if you want to **add arrow functions or closures more clearly** to this code — I can help refactor!





function getRandomInt(min, max) {
return Math.floor(Math.random() * (max - min + 1)) + min;
}
function getRandomOperator() {
const operators = ['+', '-', '*', '%'];
return operators[Math.floor(Math.random() * operators.length)];
}
document.addEventListener("DOMContentLoaded", function() {
const quizContainer = document.getElementById("quiz");
const nextButton = document.getElementById("next");
const timeDisplay = document.getElementById("time");
let questions = [];
let currentQuestionIndex = 0;
let correctAnswers = 0;
let timeLeft = 15;
for (let i = 0; i < 10; i++) {
let num1 = getRandomInt(-10, 10);
let num2 = getRandomInt(-10, 10);
let num3 = getRandomInt(-10, 10);
let op1 = getRandomOperator();
let op2 = getRandomOperator();
if (op1 === '%') {
while (num2 === 0) {
num2 = getRandomInt(-10, 10);
}
}
// Ensure num3 is not zero if op2 is '%'
if (op2 === '%') {
while (num3 === 0) {
num3 = getRandomInt(-10, 10);
}
}
let expression = `(${num1}) ${op1} (${num2}) ${op2} (${num3})`;
let correctResult = eval(expression);
questions.push({ expression, correctResult });
}
function showQuestion(index) {
quizContainer.innerHTML = `
<div class="question">
<p>${questions[index].expression} = ?</p>
<input type="number" id="answer" class="answer"/>
</div>
`;
}
function checkAnswer() {
let input = document.getElementById("answer");
let userAnswer = parseInt(input.value);
if (userAnswer === questions[currentQuestionIndex].correctResult) {
correctAnswers++;
}
currentQuestionIndex++;
if (currentQuestionIndex < 10) {
showQuestion(currentQuestionIndex);
} else {
displayFinalResult();
}
}
function displayFinalResult() {
clearInterval(timer);
quizContainer.innerHTML = "";
nextButton.style.display = "none";
let resultDiv = document.getElementById("result");
resultDiv.innerText = `You got ${correctAnswers} out of 10 correct!`;
resultDiv.style.display = "block";
if (correctAnswers >= 0) confetti();
}
const timer = setInterval(() => {
timeLeft--;
timeDisplay.textContent = timeLeft;
if (timeLeft <= 0) {
clearInterval(timer);
displayFinalResult();
}
}, 1000);
nextButton.addEventListener("click", checkAnswer);
showQuestion(0);
});