// Method-Chaining
class AsyncChain {
  constructor() {
    this.callbackQueue = [];
    this.errorOccured = null;
  }

  then(success) {
    this.callbackQueue.push({ type: "then", callback: success });
    return this;
  }
  catch(failure) {
    this.callbackQueue.push({ type: "catch", callback: failure });
    return this;
  }
  finally(finalCallback) {
    this.callbackQueue.push({ type: "finally", callback: finalCallback });
    return this;
  }

  execute(intialValue) {
    let currValue = intialValue;
    for (const CB of this.callbackQueue) {
      try {
        if (CB.type == "then") {
          currValue = CB.callback(currValue);
        } else if (CB.type == "catch") {
          if (this.errorOccured) {
            currValue = CB.callback(this.errorOccured);
            this.errorOccured = null;
          }
        } else if (CB.type == "finally") {
          CB.callback();
        }
      } catch (executionError) {
        this.errorOccured = executionError;
      }
    }
    return currValue;
  }
}

const asyncChain = new AsyncChain();
const result = asyncChain
  .then(value => {
    console.log(`Received value: ${value}`);
    return value.toUpperCase();
  })
  .then(upperCaseValue => {
    console.log(`Upper case value: ${upperCaseValue}`);
    return upperCaseValue;
  })
  .catch(error => {
    console.error(`Error: ${error}`);
  })
  .finally(() => {
    console.log("Finally Block Execution");
  })
  .execute("Hello, World!");
// console.log(result);

// // Recursive method ( not method chaining)
// class AsyncChain {
//     constructor() {
//       this.callbacks = []; // storing callbacks
//       this.value = null;
//       this.error = null;
//     }

//     then(callback) {
//       console.log("Adding then callback");
//       console.log("Initial value:", this.value); // print initial value
//       console.log("Initial error:", this.error); // print initial error
//       this.callbacks.push(callback);
//       return this;
//     }

//     catch(errorHandler) {
//       console.log("Adding catch callback");
//       console.log("Initial value:", this.value); // print initial value
//       console.log("Initial error:", this.error); // print initial error
//       errorHandler.isErrorHandler = true;
//       this.callbacks.push(errorHandler);
//       return this;
//     }

//     execute(value) {
//       console.log("Executing with value:", value);
//       this.value = value;
//       this._executeNextCallback();
//     //   return this;
//     }

//     _executeNextCallback() {
//       const callback = this.callbacks.shift(); // 1st callback from callbacks (popping)
//       if (callback) {
//         try {
//           const result = callback(this.value); // callback is an asyncChain object -> asyncChain(this.value)
//           this.value = result;
//           this._executeNextCallback();
//         } catch (error) {
//           this.error = error;
//           this._executeErrorHandler();
//         }
//       }
//     }

//     _executeErrorHandler() {
//       const errorHandler = this.callbacks.find(
//         callback => callback.isErrorHandler
//       );
//       if (errorHandler) {
//         errorHandler(this.error);
//       } else {
//         throw this.error;
//       }
//     }
//   }

//   const asyncChain = new AsyncChain();

//   asyncChain
//     .then(value => {
//       console.log(`Received value: ${value}`);
//       return value.toUpperCase();
//     })
//     .then(upperCaseValue => {
//       console.log(`Upper case value: ${upperCaseValue}`);
//     })
//     .catch(error => {
//       console.error(`Error: ${error}`);
//     });

//   console.log("Callbacks before execute:", asyncChain.callbacks);

//   asyncChain.execute("Hello, World!");
