import React, { useState, useEffect } from 'react';

const items = ['Apple', 'Banana', 'Carrot', 'Date', 'Eggplant', 'Fig', 'Grape'];

function SearchFilter() {
  const [search, setSearch] = useState(''); // Declare search state

  const filteredItems = items.filter(item =>
    item.toLowerCase().includes(search.toLowerCase())
  );

  return (
    <div>
      <input 
        type="text" 
        value={search} 
        onChange={(e) => setSearch(e.target.value)} // Update search state on input change
      />
      <ul>
        {filteredItems.map((item, index) => (
          <li key={index}>{item}</li>
        ))}
      </ul>
    </div>
  );
}

export default SearchFilter;
