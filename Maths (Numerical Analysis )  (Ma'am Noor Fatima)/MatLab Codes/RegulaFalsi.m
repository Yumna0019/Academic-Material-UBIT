function RegulaFalsi(f,a,b,n,tol)
if f(a)*f(b)<0 && a<b
    for i=1:n
        c = (a*f(b)-b*f(a))/(f(b)-f(a));
        % printing the value of root on each iteration
        fprintf('X%d = %.9f\n',i,c);
        % setting stopping criteria
        if abs(f(c))<tol
            fprintf('Converged after %d iterations.\n', i);
            break
        end
        % if f(c) is negative
        if f(a)*f(c)<0
            b = c;
        % if f(c) is positive
        elseif f(b)*f(c)<0
            a = c;
        end
    end
else 
    disp('No root lies between the interval.')
end


