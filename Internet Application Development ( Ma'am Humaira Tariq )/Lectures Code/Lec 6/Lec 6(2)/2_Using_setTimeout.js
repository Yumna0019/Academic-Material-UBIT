// Second Version (Using setTimeout() for Results Display):

// function startTest() {
//     if (testActive) return;
//     testActive = true;
//     startTime = Date.now();
//     clickCount = 0;
//     while (Date.now() - startTime < 10000) {
//       alert(`Alert ${clickCount + 1}`);
//       clickCount++;
//     }
//     const average = (clickCount / 10).toFixed(2);
//     startTimeDisplay.textContent = new Date(startTime).toLocaleTimeString();
//     averageDisplay.textContent = average;
//     setTimeout(function resultShow() {
//       const resultsStart = Date.now();
//       while (Date.now() - resultsStart < 2000) {
//         alert(`Average speed: ${average} alerts/sec`);
//       }
//       testActive = false;
//     }, 0);
//   }
  


// Second Version (Using setTimeout() for Results Display):
let testActive = false;
let startTime;
let clickCount = 0;

function startTest() {
  if (testActive) return;
  testActive = true;
  startTime = Date.now();
  clickCount = 0;

  while (Date.now() - startTime < 10000) {
    console.log(`Alert ${clickCount + 1}`);
    clickCount++;
  }

  const average = (clickCount / 10).toFixed(2);
  console.log(`Start Time: ${new Date(startTime).toLocaleTimeString()}`);
  console.log(`Average Speed: ${average} alerts/sec`);

  setTimeout(function resultShow() {
    const resultsStart = Date.now();
    while (Date.now() - resultsStart < 2000) {
      console.log(`Average speed: ${average} alerts/sec`);
    }
    testActive = false;
  }, 0);
}

startTest();
