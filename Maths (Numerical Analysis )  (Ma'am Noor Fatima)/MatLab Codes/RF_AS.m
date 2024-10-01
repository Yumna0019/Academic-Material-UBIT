% f = input('Enter your function: '); % @(x) (x*sin(x))-1
% % inputting first initial guess
% a = input('Enter left side of interval: '); 
% % inputting second initial guess
% b = input('Enter right side of interval: ');
% %inputting number of iteration
% n = input('Enter the number of iteration: ');
% % inputting tolerance
% tol = input('Enter the tolerance: ');
% 
% fprintf('%5s | %15s | %15s | %15s | %15s | %15s | %15s\n', ...
%     'Step', 'a', 'b', 'f(a)', 'f(b)', 'x', 'f(x)');
% fprintf('------------------------------------------------------------\n');
% 
% if f(a)*f(b)<0 && a<b
%     for i=1:n
%         c = (a*f(b)-b*f(a))/(f(b)-f(a));
%         f_c = f(c);
% 
%         % Print table row
%         fprintf('%5d | %15.9f | %15.9f | %15.9f | %15.9f | %15.9f | %15.9f\n', ...
%             i, a, b, f(a), f(b), c, f_c);
% 
%         % setting stopping criteria
%         if abs(f_c) < tol
%             fprintf('Converged after %d iterations.\n', i);
%             break;
%         end
% 
%         % if f(c) is negative
%         if f(a)*f_c < 0
%             b = c;
%         % if f(c) is positive
%         elseif f(b)*f_c < 0
%             a = c;
%         end
%     end
% else 
%     disp('No root lies between the interval.');
% end









% Input the function f(x) as a string and convert it to a function handle
func_str = input('Enter your function (e.g., @(x) (x*sin(x))-1): ', 's');
f = str2func(func_str);

a = input('Enter left side of interval a: ');
b = input('Enter right side of interval b: ');

n = input('Enter the number of iterations: ');
tol = input('Enter the tolerance: ');

fprintf('%5s | %15s | %15s | %15s | %15s | %15s | %15s\n', ...
    'Step', 'a', 'b', 'f(a)', 'f(b)', 'x', 'f(x)');
fprintf('------------------------------------------------------------\n');

if f(a) * f(b) < 0 && a < b
    for i = 1:n
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        fc = f(c);
        
        fprintf('%5d | %15.9f | %15.9f | %15.9f | %15.9f | %15.9f | %15.9f\n', ...
            i, a, b, f(a), f(b), c, fc);

        if abs(fc) < tol
            fprintf('Converged after %d iterations.\n', i);
            break;
        end

        if f(a) * fc < 0
            b = c;
        elseif f(b) * fc < 0
            a = c;
        end
    end
else 
    disp('No root lies between the interval.');
end
