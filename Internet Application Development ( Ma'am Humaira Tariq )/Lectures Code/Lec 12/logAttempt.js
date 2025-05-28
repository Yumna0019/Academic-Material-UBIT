function createLoginAttemptTracker() {
    let attempts = 0;
    return function() {
        attempts++;
        if (attempts > 3) {
            console.log('Account locked!');
        } else {
            console.log(`Attempt ${attempts}`);
        }
    };
}

const loginAttempt = createLoginAttemptTracker();
loginAttempt(); // 1st attempt
loginAttempt(); // 2nd attempt
loginAttempt(); // 3rd attempt
loginAttempt(); // 4th attempt
//  Output: 
// Attempt 1
// Attempt 2
// Attempt 3
// Account locked!



function createMemoizedSquare() {
    const cache = {};
    return function(n) {
        if (cache[n]) {
            console.log('From cache:', cache[n]);
            return cache[n];
        }
        const result = n * n;
        cache[n] = result;
        console.log('Calculated:', result);
        return result;
    };
}

const square = createMemoizedSquare();
square(4); // Calculated
square(4); // From cache
square(5); // Calculated

// Output:
// Calculated: 16
// From cache: 16
// Calculated: 25