//  debouncning
function debounce(func, delay) {
    let timer;
    return function () {
    clearTimeout(timer);
    timer = setTimeout(func, delay);
    };
}

const log1 = () => console.log("Debounced!");
const debouncedLog = debounce(log1, 1000);

// Call multiple times quickly
debouncedLog();
debouncedLog();
debouncedLog(); // Only this one runs after 1 second


// throttling
function throttle(func, limit) {
    let inThrottle;
    return function () {
    if (!inThrottle) {
        func();
        inThrottle = true;
        setTimeout(() => inThrottle = false, limit);
    }
    };
}

const log = () => console.log("Throttled!");
const throttledLog = throttle(log, 2000);

// Call multiple times
throttledLog(); // ✅ Runs immediately
throttledLog(); // ❌ Ignored
throttledLog(); // ❌ Ignored (until 2 sec passed)
