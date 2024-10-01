f = @(x) x * exp(x) - 2;
df = @(x) (x + 1) * exp(x);
dff = @(x) (exp(x))*(x+2);

x0 = input('Initial guess: ');
tol = input('Enter tolerance: ');
n = input('Number of iterations: ');

if df(x0) ~= 0
    fprintf('i\t\t xi\t\t\t xi+1\t\t\t delx\n');
    
    for i = 1:n
        x1 = x0 - (f(x0)*df(x0)) / (((df(x0))^2 - f(x0)*dff(x0)));
        error = x1 - x0;
        fprintf('%d\t%.6f\t%.6f\t%.6f\n', i-1, x0, x1, error);
        
        if abs(error) < tol
            break;
        end
        
        if (((df(x0))^2 - f(x0)*dff(x0))) == 0
            disp('Failed!');
            break;
        end
        x0 = x1;
    end
else
    disp('Division by zero');
end
