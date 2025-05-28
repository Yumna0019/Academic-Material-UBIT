// Third Version (Using async/await and requestIdleCallback()):

// async function startTest() {
//     if (testActive) return;
//     testActive = true;
//     startTime = Date.now();
//     clickCount = 0;
//     while (Date.now() - startTime < 2000) {
//       alert(`Alert ${clickCount + 1}`);
//       clickCount++;
//     }
//     const average = (clickCount / 10).toFixed(2);
//     startTimeDisplay.textContent = new Date(startTime).toLocaleTimeString();
//     averageDisplay.textContent = average;
//     await new Promise((resolve) => requestIdleCallback(resolve));
//     const resultsStart = Date.now();
//     while (Date.now() - resultsStart < 2000) {
//       alert(`Average speed: ${average} alerts/sec`);
//     }
//     testActive = false;
//   }
  


// Third Version (Using async/await and setTimeout() for Simulating Idle Time):
let testActive = false;
let startTime;
let clickCount = 0;

async function startTest() {
  if (testActive) return;
  testActive = true;
  startTime = Date.now();
  clickCount = 0;

  while (Date.now() - startTime < 2000) {
    console.log(`Alert ${clickCount + 1}`);
    clickCount++;
  }

  const average = (clickCount / 10).toFixed(2);
  console.log(`Start Time: ${new Date(startTime).toLocaleTimeString()}`);
  console.log(`Average Speed: ${average} alerts/sec`);

  // Simulating idle time with setTimeout()
  await new Promise(resolve => setTimeout(resolve, 0));

  const resultsStart = Date.now();
  while (Date.now() - resultsStart < 2000) {
    console.log(`Average speed: ${average} alerts/sec`);
  }

  testActive = false;
}

startTest();
