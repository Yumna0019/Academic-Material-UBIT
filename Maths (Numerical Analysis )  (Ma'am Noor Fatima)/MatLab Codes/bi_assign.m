f = input('Enter your function as @(x): '); % e.g., @(x) x^3 - 4*x - 9

% Input initial guesses, interval, and tolerance
a = input('Enter left side of interval: '); 
b = input('Enter right side of interval: ');
tol = input('Enter the tolerance: ');

% Create a table header
fprintf('%5s | %15s | %15s | %15s | %15s | %15s | %15s | %15s | %15s\n', ...
    'Step', 'a', 'b', 'f(a)', 'f(b)', 'x', 'f(x)', 'Tolerance', 'Interval Width');
fprintf('----------------------------------------------------------------------------------------\n');

if f(a)*f(b) < 0
    n = -log(tol) / log((b-a)*2);
    
    for i = 1:n
        c = (a + b) / 2;
        f_c = f(c);
        
        % Print table row
        fprintf('%5d | %15.9f | %15.9f | %15.9f | %15.9f | %15.9f | %15.9f | %15.9f | %15.9f\n', ...
            i, a, b, f(a), f(b), c, f_c, tol, b - a);
        
        if abs(f_c) < tol
            fprintf('Root found after %d iterations.\n', i);
            break;
        end
        
        if f(a)*f(c) < 0
            b = c;
        elseif f(b)*f(c) < 0
            a = c;
        end
    end
else
    disp('No root between the brackets');
end
