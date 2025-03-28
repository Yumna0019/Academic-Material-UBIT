
function [result_vec, iter] = Gauss_Seidal(a, b, tol)
fprintf("sNo\t | x1\t\t | x2\t\t | x3\n")
x = [0; 0; 0];
iter = 0;   
% Checking for dominant diagnol condtion
if all(abs(diag(a)) > sum(abs(a)) - abs(diag(a)))
    for i = 1:100
        x1 = (b(1) - a(1,2)*x(2) - a(1,3)*x(3)) / a(1,1);
        x2 = (b(2) - a(2,1)*x1 - a(2,3)*x(3)) / a(2,2);
        x3 = (b(3) - a(3,1)*x1 - a(3,2)*x2) / a(3,3);
        fprintf("%d\t | %.8f\t | %.8f | %.8f \n" ,iter,x(1),x(2),x(3));
        result_vec= [x1;x2;x3];
        % Checking for convergence using the specified tolerance
        if max(abs(result_vec - x)) < tol
            break;
        end
        x = result_vec;
        iter = iter + 1;
    end
else
    fprintf("Rule of dominant diagnol not satisfied");
end
end


% a = [10 3 1 ; 3 10 2; 1 2 10];
% b = [19;29;35];
% tol = 1e-4;
% [x,iter] = Gauss_Seidal(a,b,tol); 

