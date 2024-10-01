% Fixed Point Iteration Method : 
syms f(x)
f(x) =  -2*sin(pi*x);
%-2.5 / (-0.9*x + 1.7);
%5/(2*x^2 - 11.7*x + 17.7);
%2 / (6 - 4*x + 0.5*x^2);
%2*sin(sqrt(x));
%(1/4) - exp(-x);
% exp(-x);                    
% cos(x);
%1 + exp(-x); 
%(cos(x)+1)/3;
df = diff(f,x);
x0 = input('Initial guess');
e = input('enter tolerance');
n = input('number of iteration: ');
for i =1: n
    x1=f(x0);
    fprintf('x%d=%.6f\n', i , x1);
    if abs(x1-x0)<e
        break
    end
    x0 = x1;
end