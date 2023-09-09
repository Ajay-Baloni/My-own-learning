```js
name: {
    $regex: this.queryStr.keyword,
    $options: "i",
     },

```

# What is MongoDB Regular Expression?

MongoDB regular expression are use for matching different patterns. This is useful for finding strings within documents.

It may happen sometime that you may not know what field value you should search for in documents for a specific collection. Hence, we can use regular expression in MongoDB for finding out some unique matches for any document.

## MongoDB $regex

MongoDB regex operator is used to search for strings in collection

> Employee_name : abc, abc, ghi, jkl, mno, pqr

Now we will write the code to find “Employee_name” with initials as “ab”.

```js
db.Employee.find({ Employee_name: { $regex: "ab" } }).forEach(printjson);
```

Here, printjson is used to print each document which is returned by the query in a better way.

If suppose your collection has documents with Employee_name as “abc123”. If you entered the search criteria as “abc12”, it will also return all documents with name as “abc123”.
So if you just wanted to make a query to search for “abc12” then we have to use exact pattern matching.

For doing exact pattern matching we use `^` and $ character. We will add `^ character at the beginning and `$ at the end of the string

```js
db.Employee.find({ Employee_name: { $regex: "^abc12$" } }).forEach(printjson);
```

Here ^ is used to denote that a string starts with a certain character and $ is used to ensure that a string ends with a certain character.

## MongoDB $options

When you want to provide some additional options in regex operator then you will use $options keyword. Suppose you want to search all documents which are having “ab” in their Employee_name, irrespective of whether it is case sensitive or insensitive

```js
db.Employee.find({ Employee_name: { $regex: "ab", $options: "i" } }).forEach(
  printjson
);
```
