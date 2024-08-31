// class objectTemplate {
//   constructor(params) {
//     this.val = params;
//   }
//   func = function() {
//     console.log(this.val);
//   };
// }

// const obj1 = new objectTemplate(23);
// obj1.func();

function execPromise() {
    console.log("inside");
}

var p1 = new Promise(execPromise);
console.log(p1.constructor.name);


// var p2 = new Promise();