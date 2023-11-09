## async/await

The word “async” before a function means one simple thing: a function always returns a promise. Other values are wrapped in a resolved promise automatically.

```js
async function f() {
  return 1;
}

f().then(alert); // 1
```

…We could explicitly return a promise

```js
async function f() {
  return Promise.resolve(1);
}

f().then(alert); // 1
```

The keyword await makes JavaScript wait until that promise settles and returns its result.

Adding “await” before a promise makes the execution thread to wait for asynchronous task/promise to resolve before proceeding further. When we are adding the “await” keyword, we are introducing synchronous behavior to the application. Even the promises will be executed synchronously.

```

```
