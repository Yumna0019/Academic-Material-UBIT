function BisectionMethod(f, a, b, tol) 
if f(a)*f(b)<0 
    % calculating the number of iterations 
    n = -log(tol)/log((b-a)*2);
    disp(n);
    for i=1:n
        c = (a+b)/2; %calculating midpoint
        %printing the value of root on each iteration
        fprintf('X%d = %.9f\n',i,c); 
        % if f(c) is negative
        if f(a)*f(c)<0
            b=c;
        % if f(c) is positive
        elseif f(b)*f(c)<0
            a=c;
        end
    end 
else 
    disp('No root between the brackets')
end