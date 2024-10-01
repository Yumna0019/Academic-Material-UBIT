function [x,y] = EulerMethod(f,h,x0,y0,endpoint)
while x0 < endpoint
    y1 = y0+h*f(x0,y0);
    x1 = x0 + h;
    fprintf('x = %.2f, y = %.6f\n', x1, y1);
    
    % Update x0 and y0 for the next iteration
    x0 = x1;
    y0 = y1;
end
end