
function SecantMethod(f,X0,X1,n,tol)
for i = 1:n
    X2 =  (X0*f(X1)-X1*f(X0))/(f(X1)-f(X0));
    fprintf('x%d = %.9f\n',i,X2)
    if abs(X2-X1)<tol
        break
    end
    X0 = X1;
    X1 = X2;
end