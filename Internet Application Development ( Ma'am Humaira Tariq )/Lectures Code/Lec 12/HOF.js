var f = function(x) {
  return function(y) {
    return y - x;
  };
};

var g = f(7);
console.log(g(5));
// -2




var b = 6;

var foo = function(a) {
  a = b + a;
  return function() {
    return a;
  };
};

b = 2;

var bar = function() {
  var b = 3;
  return foo(b);
};
// 5





var b = 6;

var foo = function(a) {
  a = b + a;
  return function() { return a; };
};

b = 2;

var bar = function() {
  var b = 3;
  return foo(b);
};
// Final Answer: 6 (Option B) if JavaScript were dynamically scoped.