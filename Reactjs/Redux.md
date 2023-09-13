## Why redux

## Action and Reducer

1. acton is a plain object that describes the intention to cause change
2. a reducer is a function that determines changes to an application's state.return the new state and tell the store how to do.
3. it uses the action it receives to determine this change.

### Creating reducer

```js
import { createReducer } from "@reduxjs/toolkit";

const initialState = {
  c: 0,
};

export const customReducer = createReducer(initialState, {
  increment: (state) => {
    state.c += 1;
  },

  incrementByValue: (state, action) => {
    state.c += action.payload;
  },

  decrement: (state) => {
    state.c -= 1;
  },
});
```

### Creating Store

```js
import { configureStore } from "@reduxjs/toolkit";
import { customReducer } from "./Reducer";

const store = configureStore({
  reducer: {
    custom: customReducer,
  },
});

export default store;
```

```jsx
import React from "react";
import { useDispatch, useSelector } from "react-redux";

const Home = () => {
  const dispatch = useDispatch();
  const { c } = useSelector((state) => state.custom);

  const add = () => {
    dispatch({
      type: "increment",
    });
  };

  const sub = () => {
    dispatch({
      type: "decrement",
    });
  };

  const addvalue = () => {
    dispatch({
      type: "incrementByValue",
      payload: 25,
    });
  };

  return (
    <div>
      <h2>{c}</h2>

      <button onClick={add}>increment</button>
      <button onClick={addvalue}>increment by 25</button>
      <button onClick={sub}> decrement</button>
    </div>
  );
};

export default Home;
```

```js
import { useDispatch, useSelector } from "react-redux";
```

we can access the value of state in any component
