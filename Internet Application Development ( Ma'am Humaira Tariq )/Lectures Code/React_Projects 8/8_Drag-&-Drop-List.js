import React, { useState } from 'react';

const initialItems = ['Item 1', 'Item 2', 'Item 3', 'Item 4', 'Item 5'];

function DragDropList() {
  const [items, setItems] = useState(initialItems);
  const [draggingItem, setDraggingItem] = useState(null);

  function handleDragStart(index) {
    setDraggingItem(index);
  }

  function handleDragOver(index) {
    if (draggingItem === null || draggingItem === index) return;

    const newItems = [...items];
    const draggingItemValue = newItems[draggingItem];
    newItems.splice(draggingItem, 1);
    newItems.splice(index, 0, draggingItemValue);

    setDraggingItem(index);
    setItems(newItems);
  }

  function handleDragEnd() {
    setDraggingItem(null);
  }

  return (
    <div>
      <ul>
        {items.map((item, index) => (
          <li
            key={index}
            draggable
            onDragStart={() => handleDragStart(index)}
            onDragOver={(e) => {
              e.preventDefault(); // Needed to allow dropping
              handleDragOver(index);
            }}
            onDragEnd={handleDragEnd}
            style={{
              padding: '8px',
              border: '1px solid #ccc',
              margin: '4px',
              cursor: 'move',
              backgroundColor: draggingItem === index ? '#f0f0f0' : 'white',
            }}
          >
            {item}
          </li>
        ))}
      </ul>
    </div>
  );
}

export default DragDropList;
