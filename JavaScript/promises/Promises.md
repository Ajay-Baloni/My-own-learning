## what is promise

A Promise is a special JavaScript object. It produces a value after an asynchronous (aka, async) operation completes successfully, or an error if it does not complete successfully due to time out, network error, and so on.

Successful call completions are indicated by the resolve function call, and errors are indicated by the reject function call.

You can create a promise using the promise constructor like this:

```js
const promiseOne = new Promise(function (resolve, reject) {
  // Make an asynchronous call and either resolve or reject
  // DB calls, cryptography, network
  setTimeout(function () {
    console.log("Async task is compelete");
    resolve();
  }, 1000);
});
```

In most cases, a promise may be used for an asynchronous operation. However, technically, you can resolve/reject on both synchronous and asynchronous operations.

## why promise don't we have callback functions for async operations?

That's right. We have callback functions in JavaScript. But, a callback is not a special thing in JavaScript. It is a regular function that produces results after an asynchronous call completes (with success/error).

The word 'asynchronous' means that something happens in the future, not right now. Usually, callbacks are only used when doing things like network calls, or uploading/downloading things, talking to databases, and so on.

While callbacks are helpful, there is a huge downside to them as well. At times, we may have one callback inside another callback that's in yet another callback and so on.know as **callback-hell**

## Understanding Promise States

The executor function takes two arguments, resolve and reject. These are the callbacks provided by the JavaScript language. Your logic goes inside the executor function that runs automatically when a new Promise is created.For the promise to be effective, the executor function should call either of the callback functions, resolve or reject.

A promise's state can be pending, fulfilled or rejected. A promise that is either resolved or rejected is called **settled.**

## How promises are resolved and rejected

```js
let promise = new Promise(function (resolve, reject) {
  resolve("I am done");
});
```

rejected

```js
let promise = new Promise(function (resolve, reject) {
  reject(new Error("Something is not right!"));
});
```

#### An important point to note:

A Promise executor should call only one resolve or one reject. Once one state is changed (pending => fulfilled or pending => rejected), that's all. Any further calls to resolve or reject will be ignored.

```js
let promise = new Promise(function (resolve, reject) {
  resolve("I am surely going to get resolved!");

  reject(new Error("Will this be ignored?")); // ignored
  resolve("Ignored?"); // ignored
});
```

## How to handle a Promise once you've created it

A Promise uses an executor function to complete a task (mostly asynchronously). A consumer function (that uses an outcome of the promise) should get notified when the executor function is done with either resolving (success) or rejecting (error).

The handler methods, .then(), .catch() and .finally(), help to create the link between the executor and the consumer functions so that they can be in sync when a promise resolves or rejects.

```js
const promiseOne = new Promise(function (resolve, reject) {
  //Do an async task
  // DB calls, cryptography, network
  setTimeout(function () {
    console.log("Async task is compelete");
    resolve();
  }, 1000);
});

promiseOne.then(function () {
  console.log("Promise consumed");
});

new Promise(function (resolve, reject) {
  setTimeout(function () {
    console.log("Async task 2");
    resolve();
  }, 1000);
}).then(function () {
  console.log("Async 2 resolved");
});

const promiseThree = new Promise(function (resolve, reject) {
  setTimeout(function () {
    resolve({ username: "ajay", email: "hi@example.com" });
  }, 1000);
});

promiseThree.then(function (user) {
  console.log(user);
});

const promiseFour = new Promise(function (resolve, reject) {
  setTimeout(function () {
    let error = false;
    if (!error) {
      resolve({ username: "ajay", password: "123" });
    } else {
      reject("ERROR: Something went wrong");
    }
  }, 1000);
});

promiseFour
  .then((user) => {
    console.log(user);
    return user.username;
  })
  .then((username) => {
    console.log(username);
  })
  .catch(function (error) {
    console.log(error);
  })
  .finally(() => console.log("The promise is either resolved or rejected"));

const promiseFive = new Promise(function (resolve, reject) {
  setTimeout(function () {
    let error = false;
    if (!error) {
      resolve({ username: "javascript", password: "123" });
    } else {
      reject("ERROR: JS went wrong");
    }
  }, 1000);
});

async function consumePromiseFive() {
  try {
    const response = await promiseFive;
    console.log(response);
  } catch (error) {
    console.log(error);
  }
}

consumePromiseFive();

async function getAllUsers() {
  try {
    const response = await fetch("https://jsonplaceholder.typicode.com/users");

    const data = await response.json();
    console.log(data);
  } catch (error) {
    console.log("E: ", error);
  }
}

getAllUsers();

fetch("https://api.github.com/users/hiteshchoudhary")
  .then((response) => {
    return response.json();
  })
  .then((data) => {
    console.log(data);
  })
  .catch((error) => console.log(error));
```
