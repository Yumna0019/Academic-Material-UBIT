function [x,y] = RKmethod(f,h,x0,y0,endpoint)
while x0 < endpoint
    k1 = f(x0, y0);
    k2 = f(x0 + (h / 2), y0 + (k1 / 2));
    k3 = f(x0 + (h / 2), y0 + (k2 / 2));
    k4 = f(x0 + h, y0 + k3);
    y1 = y0 + ((h / 6) * (k1 + 2 * k2 + 2 * k3 + k4));
    x1 = x0 + h;
    fprintf('x = %.2f, y = %.6f\n', x1, y1);
    % Update x0 and y0 for the next iteration
    x0 = x1;
    y0 = y1;
end
end

