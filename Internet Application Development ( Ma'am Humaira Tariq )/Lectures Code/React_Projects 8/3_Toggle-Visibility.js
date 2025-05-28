import React,{useState, useEffect} from 'react';

function ToggleVisibility() {
  const [isVisible, setISVisible] = useState(false);

  function handleToggleVisibility() {
    setISVisible(!isVisible);
  }
  
  return (
    <div>
      <button onClick={handleToggleVisibility}>Show/Hide Text</button>
      {isVisible && <p>Toggle me!</p>}
    </div>
  );
}

export default ToggleVisibility;
