m = menu('choose any method:','Euler Method' ,' Improved Euler Method', ...
    'RK-4 Method');
f = input('Enter your function: ');
h = input('Enter your step size: ');
x0 = input('Enter value of x0: ');
y0 = input('Enter value of y0: ');
endpoint = input('Enter how many times loop should iterate: ');
switch m
    case 1
        EulerMethod(f,h,x0,y0,endpoint);
    case 2
        ImprovedEulerMethod(f,h,x0,y0,endpoint);
    case 3
        RKmethod(f,h,x0,y0,endpoint);
end