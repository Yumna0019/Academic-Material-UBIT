
function [] = Scaling_Power(A,x0,tol)
    for i = 0:100
        x = A*x0;
        j = max(x);
        x = x/j;
        if(abs(x-x0)<tol)
            break
        end
        x0 = x;
        lambda = ((A*x0).*x0)/(x0.*x0);
    end
    fprintf('The eigen vector is: %.4f \n');
    x
    fprintf('The eigen value is: %.4f \n' , lambda);
end