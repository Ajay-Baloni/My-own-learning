## Why do we need Callback Functions?

JavaScript runs code sequentially in top-down order. However, there are some cases that code runs (or must run) after something else happens and also not sequentially. This is called asynchronous programming.

Callbacks make sure that a function is not going to run before a task is completed but will run right after the task has completed. It helps us develop asynchronous JavaScript code and keeps us safe from problems and errors.

In JavaScript, the way to create a callback function is to pass it as a parameter to another function, and then to call it back right after something has happened or some task is completed.

## How to create a Callback

````js
 const message = function() {
    console.log("This message is shown after 3 seconds");
}

setTimeout(message, 3000);```
````

There is a built-in method in JavaScript called “setTimeout”, which calls a function or evaluates an expression after a given period of time (in milliseconds). So here, the “message” function is being called after 3 seconds have passed.

## What is an Anonymous Function?

Alternatively, we can define a function directly inside another function, instead of calling it. It will look like this:

```js
setTimeout(function () {
  console.log("This message is shown after 3 seconds");
}, 3000);
```

the callback function here has no name and a function definition without a name in JavaScript is called as an “anonymous function”.
