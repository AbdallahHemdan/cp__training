## Design Patterns
- Design patterns are not a silver bullet to all your problems
- Do not try to force them; bad things are supposed to happen, if done so


## Types of Design Patterns
- Creational => 💍 Singleton
- Structural => 🔌 Adapter
- Behavioral => 😎 Observer



## 💍 Singleton
Real world example

> There can only be **one president of a country** at a time. The same president has to be brought to action, whenever duty calls,**President here is singleton.**

In plain words

> Ensures that **only one object** of a particular class **is ever created**.

Wikipedia says

> In software engineering, the singleton pattern is a software design pattern that **restricts the instantiation of a class to one object**, This is useful when exactly **one object is needed** to coordinate actions across the system




### Sample code in JavaScript
- The Singleton object is implemented as an **immediate anonymous function**
- The function **executes immediately** by wrapping it in brackets followed by two additional brackets
- It is called **anonymous** because it **doesn't have a name**

```js
let Singleton = (function () {
    let instance;

    function createInstance() {
        let object = new Object("I am the instance");
        return object;
    }
 
    return {
        getInstance: function () {
            if (!instance) {
                instance = createInstance();
            }

            return instance;
        }
    };
})();
 
function run() {
 
    let instance1 = Singleton.getInstance();
    let instance2 = Singleton.getInstance();
 
    alert("Same instance? " + (instance1 === instance2));  
}
```
