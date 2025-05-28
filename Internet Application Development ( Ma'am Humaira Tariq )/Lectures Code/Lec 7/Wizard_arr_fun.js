const wizardss = {
    magicNumber: 50,

    castSpell: () => {       //function(){}
        console.log( this.magicNumber);  
    }
};

wizardss.castSpell();            // Output:  undefined     ( bcz not define in regular function : castSpell: function() {  
//                                                                                               console.log( this.magicNumber);  
//                                                                                            })


// //////////////////////////////////////////////////////////



const hero = {
  name: "Thor",
  greet: function () {
    const inner = function() {             // = () =>{}
      console.log(`Hello, I am ${this.name}`);
    };
    inner();
  }
};

hero.greet();  // Output: Hello, I am undefined      (bcz inner  => instead of regular function it should be arrow function)


//////////////////////////////////////////////////////////////////////


const wizard = {
    magicNumber: 42,

    // Define spell as regular function inside wizard
    spell: function(a, b) {  // Regular function
        console.log(`Magic boost: ${this.magicNumber}`);
        return a + b + this.magicNumber;
    }
};

// Call spell function with wizard's 'this'
console.log(wizard.spell(10, 5));


// Output: Magic boost: 42
//         57


