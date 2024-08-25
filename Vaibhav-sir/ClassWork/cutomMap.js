Array.prototype.mapCustom = function(callbackFunc) {
  let res = [];
  for (let i = 0; i < this.length; i++) {
    res.push(callbackFunc(this[i]));
  }
  return res;
};

call1 = val => {
  return val * 2;
};

let arr = [1, 2, 3];
let res = arr.mapCustom(call1);

console.log(res);
