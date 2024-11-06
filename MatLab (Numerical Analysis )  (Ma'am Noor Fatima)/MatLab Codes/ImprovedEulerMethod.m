function [x,y] = ImprovedEulerMethod(f,h,x0,y0,endpoint)
while x0 < endpoint
    k1 = h * f(x0, y0);
    k2 = h * f(x0 + h, y0 + k1);
    y1 = y0 + (1/2) * (k1 + k2);
    x1 = x0 + h;
    fprintf('x = %.2f, y = %.6f\n', x1, y1);
    
    % Update x0 and y0 for the next iteration
    x0 = x1;
    y0 = y1;
end
end