# Routing

Routing refers to determining how an application responds to a client request to a particular endpoint, which is a URI (or path) and a specific HTTP request method (GET, POST, and so on).

```js
const express = require("express");
const app = express();

// respond with "hello world" when a GET request is made to the homepage
app.get("/", (req, res) => {
  res.send("hello world");
});
```

# Response methods

````res.download() Prompt a file to be downloaded.
res.end()            End the response process.
res.json()           Send a JSON response.
res.jsonp()          Send a JSON response with JSONP support.
res.redirect()       Redirect a request.
res.render()         Render a view template.
res.send()           Send a response of various types.
res.sendFile()       Send a file as an octet stream.
res.sendStatus()     Set the response status code and send its string    representation as the response body.```
````

## app.route()

```js
app
  .route("/book")
  .get((req, res) => {
    res.send("Get a random book");
  })
  .post((req, res) => {
    res.send("Add a book");
  })
  .put((req, res) => {
    res.send("Update the book");
  });
```

## express.Router

Express Routers are a way to organize your Express application such that your primary app.js file does not become bloated and difficult to reason about. As you’re building an Express application or API, you’ll soon notice that the routes continue to pile up in app.js. This makes the file quite long and hard to read. As we add functionality to an application, this file would get long and cumbersome. The solution to this in Express is Routers. Routers are like mini versions of Express applications.

#### This file will now contain all the /hello specific code. To use this router in another file, there needs to be a module.exports so that other files can access helloRouter.

```js
const express = require("express");

names = { 1: "John", 2: "Jane", 3: "Jack" };

helloRouter = express.Router();

// Get all names
helloRouter.get("/", (req, res) => {
  res.json(names);
  console.log(names);
});

// Get a single name
helloRouter.get("/:id", (req, res) => {
  res.json(names[req.params.id]);
  console.log(names[req.params.id]);
});

// Update a single name
helloRouter.put("/:id", (req, res, next) => {
  names[req.params.id] = req.body.name;
  res.json(names[req.params.id]);
  console.log(names);
});

// Add a new name
helloRouter.post("/", (req, res) => {
  names[req.body.id] = req.body.name;
  res.json(names[req.body.id]);
  console.log(names);
});

// Delete a name
helloRouter.delete("/:id", (req, res) => {
  delete names[req.params.id];
  res.json(names);
  console.log(names);
});

module.exports = helloRouter;
```

#### Our app.js file could then be refactored to import the helloRouter:

```js
const express = require("express");
const app = express();
app.use(express.json());
const PORT = process.env.PORT || 4001;

const helloRouter = require("./hello.js");
app.use("/hello", helloRouter);

app.listen(PORT, () => {
  console.log(`Server is listening on ${PORT}`);
});
```
