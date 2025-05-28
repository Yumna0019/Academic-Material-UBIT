// syn for loop
for (var i = 1 ; i <= 10 ; i++){
    console.log(i);
}
// Output:
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// 10



// asyn
for (var i =1;i<=10;i++){
    setTimeout(function() {
    console.log(i);
    },1000)
}
// Output: 
// 11
// 11
// 11
// 11
// 11
// 11
// 11
// 11
// 11
// 11


// solve asyn issue : 
for (let  i =1;i<=10;i++){    // let istead of var
    setTimeout(function() {
    console.log(i);
    },1000*i)               // 1000*i
}
// Output :
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// 10


// asyn for loop (or this solution)
setTimeout(() => {
    for (let i = 1; i <= 10; i++) {
      console.log(i);
    }
  }, 1000);
