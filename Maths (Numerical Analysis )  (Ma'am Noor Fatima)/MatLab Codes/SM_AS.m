f = input('Enter your function: '); % @(x) (x*sin(x))-1
% inputting first initial guess
X0 = input('Enter left side of interval: '); 
%\ inputting second initial guess
X1 = input('Enter right side of interval: ');
%inputting number of iteration
n = input('Enter the number of iteration: ');
% inputting tolerance
tol = input('Enter the tolerance: ');

fprintf('%5s | %15s | %15s | %15s | %15s | %15s | %15s\n', ...
    'Step', 'X0', 'X1', 'f(X0)', 'f(X1)', 'X2', 'f(X2)');
fprintf('------------------------------------------------------------\n');

for i = 1:n
    X2 = (X0*f(X1)-X1*f(X0))/(f(X1)-f(X0));
    f_X0 = f(X0);
    f_X1 = f(X1);
    f_X2 = f(X2);
    
    % Print table row
    fprintf('%5d | %15.9f | %15.9f | %15.9f | %15.9f | %15.9f | %15.9f\n', ...
        i, X0, X1, f_X0, f_X1, X2, f_X2);

    if abs(X2 - X1) < tol
        fprintf('Converged after %d iterations.\n', i);
        break;
    end
    
    X0 = X1;
    X1 = X2;
end
