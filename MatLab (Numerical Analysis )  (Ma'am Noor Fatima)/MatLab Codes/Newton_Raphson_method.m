% %Newton Raphson Method :
% % f = @ (x) x*exp(x) - 2;
% % df = @ (x) (x+1)*exp(x) ;
% f = @(x) -1 + 5.5*x - 4*x^2 + 0.5*x^3;
% df = @(x) 5.5 -8*x + 1.5*x^2;
% x0 = input('Initial guess: ');
% tol = input('enter tolerance: ');
% n = input('number of iteration: ');
% if (df(x0) ~= 0)
%     for i =1:n
%         x1 = x0 - (f(x0)/df(x0));
%         fprintf('x%d = %.10f\n' , i ,x1);
%         if abs(x1 - x0) < tol
%             break
%         end
%         if df(x1) == 0
%             disp('Failed!');
%         end
%         x0 = x1;
%     end
% else
%    disp('Division by zero');
% end
% 




% f = @(x) x * exp(x) - 2;
% df = @(x) (x + 1) * exp(x);
% f = @(x) -1 + 5.5*x - 4*x^2 + 0.5*x^3;
% df = @(x) 5.5 -8*x + 1.5*x^2;
% f = @(x) -12 - 21*x + 18*x^2 - 2.4*x^3;
% df = @(x) -21 + 32*x - 7.2*x^2;
% f = @(x) x^3 - 6*x^2 + 11*x - 6.1;
% df = @(x) 3*x^2 -12*x + 11;
% f = @(x) -2 + 6*x - 4*x^2 + 0.5*x^3;
% df = @(x) 6 - 8*x + 1.5*x^2;
f = @(x) x^3 - 2*x^2 - 4*x + 8;
df = @(x) 3*x^2 - 4*x - 4;
x0 = input('Initial guess: ');
tol = input('Enter tolerance: ');
n = input('Number of iterations: ');

if df(x0) ~= 0
    fprintf('i\t\t xi\t\t\t xi+1\t\t\t delx\n');
    fprintf('%d\t%.6f\t%.6f\t%.6f\n', 0, x0, x0, 0);
    
    for i = 1:n
        x1 = x0 - (f(x0) / df(x0));
        error = x1 - x0;
        fprintf('%d\t%.6f\t%.6f\t%.6f\n', i, x0, x1, error);
        
        if abs(error) < tol
            break;
        end
        
        if df(x1) == 0
            disp('Failed!');
            break;
        end
        x0 = x1;
    end
else
    disp('Division by zero');
end
