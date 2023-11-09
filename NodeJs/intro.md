## Differences Between the Browser and Node.js Runtime Environments

#### Access to the DOM APIs

With the browser runtime, you can access the Document Object Model (DOM). And you can perform all the DOM operations. But Node.js does not have access to the DOM.

Node.js exposes almost all the system resources to your programs. This means you can interact with the operating system, access the file systems, and read and write to the files. But, you do not have access to operating systems and file systems from the browser.

#### Window vs Global object

JavaScript has a built-in global object. The JavaScript global object for the browser is called the window object. In Node.js, the global object goes by the name global.

The window object contains methods and properties available only in the browser environment.

#### Control over runtime versions

With Node.js, you can choose which version to run your server-side application on. As a result, you can use modern JavaScript features without worrying about any version-specific inconsistencies.

Contrast this to the browser runtime environment. As a developer, you have no control over the version of browsers your clients use to access your app.
