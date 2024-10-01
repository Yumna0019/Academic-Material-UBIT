% f = @(x) x*exp(x) - 2;
% df = @(x) (x+1)*exp(x);

f = @(x) x * exp(x) - 2;
df = @(x) (x + 1) * exp(x);
x0 = 1; % initial guess
x1 = x0 - 1; % Initialize x1 as x0 - 1
tol = 10^-5;

fprintf("i\t | x(i-1)\t | x(i)\t\t | x(i+1)\n");
% x will be the answer
for i = 1:10
    a = (x0 - x1) * f(x0) * (df(x1));
    b = (df(x1) * f(x0)) - (f(x1) * df(x0));
    x = x0 - (a / b);
     error = x - x0;
    fprintf("%d\t | %.6f\t | %.6f\t | %.6f\n", i-1, x1, x0, x); % Print the result for the current iteration

    if abs(error) < tol
        break;
    end
    x1 = x0;
    x0 = x;
end
