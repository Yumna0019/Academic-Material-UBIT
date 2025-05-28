// // syn for loop
// for (let i = 1 ; i <= 10 ; i++){
//     console.log(i);
// }

// // while loop
// sum =0
// i =0
// while (i<=10){
//     sum+=i;
//     i++
// }
// console.log(sum);

// // asyn for loop
// setTimeout(() => {
//     for (let i = 1; i <= 10; i++) {
//       console.log(i);
//     }
//   }, 1000);

// // asyn
// for (var i =1;i<=10;i++){
//     setTimeout(function() {
//     console.log(i);
//     },1000)
// }

// // do-while loop
// let i = 1 ;
// sum = 0
// do {
//     sum+=i;
//     i++
// } while (i<=5)
// console.log(sum);

// // for...of: Loops through values (used for arrays, strings, etc.)
// const fruits = ["apple","banana","mango"]
// for(const fruit of fruits){
//     console.log(fruit);
// }
// // output :
// // apple
// // banana
// // mango

// // Or with arrays (but usually for...of is better for arrays):
// const nums = [1,2,3]
// for (const index in nums){
//     console.log(index,nums[index]);
// }

// // for...in: Loops through keys/indexes (used for objects or array indexes)
// const person = { name: "Yumna", age: 22, country: "Pakistan" };

// for (const key in person) {
//   console.log(`${key}: ${person[key]}`);
// }
// // Output:
// // name: Yumna
// // age: 22
// // country: Pakistan

// // string methods
// let str = "zeosh khan";
// let str1 = "Kainat";

// console.log(str.concat(str1));
// console.log(str.length);
// console.log(str.toLowerCase());
// console.log(str.toUpperCase());
// console.log(str.slice(2));
// console.log(str[0]);
// console.log(str[str.length - 1]);
// console.log(str.slice(0, -1));
// console.log(str.replace("zeo", "leo"));
// console.log(str.includes("e"));
// console.log(str.startsWith("l"));


// // array methods
// let arr = [1, 2, 3, 4, 5];

// console.log(arr.length);
// console.log(arr.pop()); // returns the popped element from the last// updates the array
// console.log(arr.push(3)); // returns the length of the array // updates the array
// console.log(arr); // to print the array
// console.log(arr.shift()); // returns the removed element from the start
// console.log(arr);
// console.log(arr.unshift(2)); // returns the length of the array after adding an element at the start of the array
// console.log(arr);
// console.log(arr.join("-")); // returns an string
// console.log(arr.concat("Hello")); // returns a new array
// console.log(arr);



// // forEach() – Loop through items
// let nums = [1, 2, 3];
// nums.forEach(num => console.log(num));

// let zems = ['def', 'dede', 'dfv']
// zems.forEach(zem => console.log(zem));



// // map() – Transform items (returns new array)
// let doubledmap = nums.map(num => num * 2);
// console.log(doubledmap);

// let mapmap = zems.map(zem => zem + 3);
// console.log(mapmap);




// // filter() – Keep items that match condition
// let even = nums.filter(num => num % 2 === 0);
// console.log(even); 

// let evens = zems.filter(zem => zem.length % 2 === 0)
// console.log("filter", evens);




// // reduce() – Combine items to a single value
// const numbers = [1, 2, 3, 4];
// const sum = numbers.reduce((acc, curr) => acc + curr, 0);
// console.log(sum); // 10
// // Explanation:
// // acc → accumulator (total so far)
// // curr → current item in the array
// // 0 → starting value of acc
// // It's like doing: (((0 + 1) + 2) + 3) + 4 = 10



// // find() – Find first match
// let found = nums.find(num => num < 5);
// console.log("found",found); 
// // OUTPUT:   found 1


// let foundout1st = nums.find(num => num > 5);
// console.log("found",foundout1st);
// // If no match, it returns undefined.
// // What happens:
// // find() checks each number:
// // Is 1 > 5? ❌
// // Is 2 > 5? ❌
// // Is 3 > 5? ❌
// // No match found, so find() returns undefined.



// // let nums = [1, 2, 3]

// // indexOf() – Get index of item
// let fruits = ["apple", "banana", "cherry"];
// console.log(fruits.indexOf("banana"));    

// // push() – Add to end
// nums.push(7);
// console.log(nums);

// // pop() – Remove from end
// nums.pop();
// console.log(nums);

// //  slice() – Get portion (doesn’t change original)
// console.log(nums.slice(1, 4));

// // splice() – Add/remove items (mutates)
// nums.splice(1,1,9); // Remove 1 item at index 1, insert 9
// console.log("slice",nums); 

// // includes()	Checks if value exists
// console.log(nums.includes(3))            
// console.log(nums.shift())          // shift()	Removes from start
// console.log(nums);

// nums.unshift(6)          // unshift() 	Adds to start
// console.log(nums)






// // Sorting
// let arr = [1,2,3,4,7]
// console.log(arr.sort()); // by defualt it sorts alphabetically
// let compare = (a, b) => {
//     return b-a; // for descending 
//     // for ascending use a-b
// }
// console.log(arr.sort(compare))



// // Spread Operator (`...`)
// // > Used to expand elements of an array/object.

// // Example 1: Spreading Arrays
// const arr1 = [1, 2, 3];
// const arr2 = [4, 5, 6];

// const combined = [...arr1, ...arr2];
// console.log(combined); // [1, 2, 3, 4, 5, 6]


// // Example 2: Copying Arrays
// const original = [10, 20, 30];
// const copy = [...original];

// copy.push(40);
// console.log(original); // [10, 20, 30]
// console.log(copy);     // [10, 20, 30, 40]


// // Example 3: Spreading Objects
// const user = { name: 'zeas', age: 12 };
// const newUser = { ...user, country: 'Pakistan' };

// console.log(newUser); // { name: 'zeas', age: 12, country: 'Pakistan' }



// // Rest Operator (`...`)
// // > Used to collect multiple elements into a single parameter.

// // Example 1: Function Parameters
// function sum(...numbers) {
//     // return numbers.reduce((acc, curr) => acc + curr, 0);
//     return numbers.reduce((a, b) => a + b, 0);
// }

// console.log(sum(1, 2, 3));       // 6
// console.log(sum(5, 10, 15, 20)); // 50


// // Example 2: Destructuring Arrays
// const [first, ...rest] = [100, 200, 300, 400];
// console.log(first); // 100
// console.log(rest);  // [200, 300, 400]


// // Example 3: Destructuring Objects
// const { name, ...others } = { name: 'zea', age: 12, city: 'Lahore' };
// console.log(name);   // 'zea'
// console.log(others); // { age: 12, city: 'Lahore' }

// // Spread        => Expands arrays/objects into items     
// // Rest          => Collects items into a single variable 


// //  practice  
// // spread
// let ar2 = ['dce','dwc', 'decdx']
// let ar3 = ['gb','vgb0','btrn']

// const com = [...ar2,...ar3]
// console.log("com = ",com);

// // rest
// const { names,...users} = {sa:'dch',sadj:'dcdh', ta:'dwcv', names:'djcfv'}
// console.log(users);
// console.log(names);



// // setInterval (Keeps running):
// setInterval(() => {
//     console.log("🔁 This runs every 2 seconds.");
// }, 2000);
// // OUTPUT:
// // 🔁 This runs every 2 seconds.
// // 🔁 This runs every 2 seconds.
// // 🔁 This runs every 2 seconds.
// // 🔁 This runs every 2 seconds.
// // ^C  


// // Stopping setInterval with clearInterval
// let count = 0;

// const timer = setInterval(() => {
//   count++;
//   console.log("Count:", count);

//   if (count === 5) {
//     clearInterval(timer); // stop after 5 times
//     console.log("✅ Stopped!");
//   }
// }, 1000);


// // setTimeout (Runs once):
// setTimeout(() => {
//     console.log("⏰ This runs after 2 seconds, one time.");
// }, 2000);
// // OUTPUT:
// // ⏰ This runs after 2 seconds, one time.

// // Stopping with setTimeout
// let count = 0;
// function repeat() {
//   count++;
//   console.log("Count:", count);
//   if (count < 5) {
//     setTimeout(repeat, 1000); // Keep calling again
//   } else {
//     console.log("✅ Stopped!");
//   }
// }
// setTimeout(repeat, 1000);




// // asyn
// for (let i =1;i<=10;i++){       // X => (var i =1;i<=10;i++)
//     setTimeout(function() {
//     console.log(i);
//     },1000)
// }

// // Because var is function-scoped, and by the time the setInterval runs, the loop is already finished, and i is 11 for all of them.
// // ✅ let creates a new i for every loop iteration, so it prints:
// // 1 2 3 4 5 6 7 8 9 10 every second.



// // Callback:
// function greet(name, callback) {
//     console.log("Hi " + name);
//     callback(); // call the other function after
//   }
  
//   function sayBye() {
//     console.log("Bye!");
//   }
  
//   greet("zae", sayBye);
  


// //  Promise
// let promise = new Promise((resolve, reject) => {
//     let success = true;
  
//     if (success) {
//       resolve("✅ It worked!");
//     } else {
//       reject("❌ Something went wrong.");
//     }
// });
  
// promise
//     .then((result) => console.log(result))
//     .catch((error) => console.log(error));
  

// // Asyn / Await 
// function getMessage() {
//     return new Promise((resolve) => {
//     setTimeout(()=>{resolve("Hello from asyn/await! 😎");},1000)
// })}
// async function showMessage() {
//     let msg = await getMessage();
//     console.log(msg);
// }
// showMessage();
  
// // Callback
// function work(callback) {
//     console.log("Doing work...");
//     callback(); // call back when done
//   }
  
//   work(() => {
//     console.log("✔ Callback done!");
//   });



// // Promise
// let promise = new Promise((resolve, reject) => {
// resolve("✔ Promise complete!");
// });
// promise.then((msg) => {
// console.log(msg);
// });
  

// //asyn/await
// async function getData() {
//     let result = await Promise.resolve("✔ Got it!");
//     console.log(result);
// }
// getData();
  
  


// // Promise API
// const p1 = new Promise((resolve) => setTimeout(() => resolve("✅ p1 resolved"), 1000));
// const p2 = new Promise((resolve) => setTimeout(() => resolve("✅ p2 resolved"), 2000));
// const p3 = new Promise((_, reject) => setTimeout(() => reject("❌ p3 rejected"), 1500));

// // Promise.all - all must resolve
// Promise.all([p1, p2])
//   .then(results => console.log("Promise.all results:", results))
//   .catch(error => console.log("Promise.all error:", error));

// // Promise.race - first to settle (resolve or reject)
// Promise.race([p1, p2, p3])
//   .then(result => console.log("Promise.race result:", result))
//   .catch(error => console.log("Promise.race error:", error));

// // Promise.allSettled - all results regardless of resolve/reject
// Promise.allSettled([p1, p2, p3])
//   .then(results => {
//     console.log("Promise.allSettled results:");
//     results.forEach((res, i) => console.log(`  p${i + 1}:`, res));
//   });

// // Promise.any - first to resolve (ignores rejections)
// Promise.any([p3, p2])
//   .then(result => console.log("Promise.any result:", result))
//   .catch(error => console.log("Promise.any error:", error));




