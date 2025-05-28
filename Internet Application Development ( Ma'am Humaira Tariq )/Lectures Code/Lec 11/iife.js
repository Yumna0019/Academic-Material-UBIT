const arrFuncs1 = []; 
for(var i = 0; i < 5; i++){ 
    arrFuncs1.push(function(){
    return i;
    });
}
console.log(i); // what will be the value of 'I' and why

for (let i = 0; i < arrFuncs1.length; i++) { 
    console.log(arrFuncs1[i]()); // what will be the value 
}

// Output:
// 5
// 5
// 5
// 5
// 5
// 5





const arrFuncs = []; 
for(var i = 0; i < 5; i++){ 
    (function (j){
        arrFuncs.push(function(){
        return j;
    });
    })(i);
}
console.log(i); 

for (let i = 0; i < arrFuncs.length; i++) { 
    console.log(arrFuncs[i]()); // what will be the value 
}

// Output: 
// 5
// 0
// 1
// 2
// 3
// 4