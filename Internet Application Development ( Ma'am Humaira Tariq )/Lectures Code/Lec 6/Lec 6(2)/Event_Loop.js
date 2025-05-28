// function startTest() {
//     if (testActive) return;
//     testActive = true;
//     resetTest();
//     startTime = Date.now();
//     clickCount = 0;
//     while (Date.now() - startTime < 10000) {
//     alert(`Alert ${clickCount + 1}`);
//     clickCount++;
//     }
//     const average = (clickCount / 10).toFixed(2);
//     startTimeDisplay.textContent = new
    
//     Date(startTime).toLocaleTimeString();
    
//     averageDisplay.textContent = average;
//     const resultsStart = Date.now();
//     while (Date.now() - resultsStart < 2000) {
//     alert(`Average speed: ${average} alerts/sec`);
//     }
//     testActive = false;
//     }


let testActive = false;
let startTime;
let clickCount = 0;

function startTest() {
  if (testActive) return;
  testActive = true;
  resetTest();
  
  startTime = Date.now();
  clickCount = 0;

  // Using setInterval to simulate the alerts in the terminal and count clicks.
  const intervalId = setInterval(() => {
    console.log(`Alert ${clickCount + 1}`);
    clickCount++;

    if (Date.now() - startTime >= 10000) {
      clearInterval(intervalId); // Stop after 10 seconds
      const average = (clickCount / 10).toFixed(2);
      console.log(`Test started at: ${new Date(startTime).toLocaleTimeString()}`);
      console.log(`Average speed: ${average} alerts/sec`);

      // Show average speed output
      const resultsStart = Date.now();
      const resultIntervalId = setInterval(() => {
        console.log(`Average speed: ${average} alerts/sec`);
        if (Date.now() - resultsStart >= 2000) {
          clearInterval(resultIntervalId); // Stop after 2 seconds
          testActive = false;
        }
      }, 1000); // Log every second during results phase
    }
  }, 1000); // Log every second during the test phase
}

function resetTest() {
  // Your resetTest function logic here if any
}

// Call the startTest function to run the test
startTest();
