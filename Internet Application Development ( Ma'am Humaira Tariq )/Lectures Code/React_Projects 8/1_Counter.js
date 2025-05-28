import React, { useState,useEffect } from 'react';

function Counter() {
  const [count,setCount] = useState(0);
  
  return (
    <div>
      <button onClick = {() => setCount(count+1)}>Increment</button>
      <p>Count: {count}</p>
    </div>
  );
}

export default Counter;





/////////////////////////////////////////////////////////////////////////////////////


// // using handleIncrement function

// import React, { useState,useEffect } from 'react';

// function Counter() {
//   const [count,setCount] = useState(0);
//   function handleIncrement(){
//     setCount(count +1);
//   }
//   return (
//     <div>
//       <button onClick = {handleIncrement}>Increment</button>
//       <p>Count: {count}</p>
//     </div>
//   );
// }

// export default Counter;
