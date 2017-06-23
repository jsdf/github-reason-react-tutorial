# bs-director

[BuckleScript](https://github.com/bloomberg/bucklescript) bindings to the [Director](https://github.com/flatiron/director) router.

```
npm i bs-director
```

## Usage

```reason
let router =
  DirectorRe.makeRouter {
    "/": fun () => Js.log "Navitaged to tasks list",
    "/active": fun () => Js.log "Navitaged active tasks list",
    "/completed": fun () => Js.log "Completed a task"
  };

DirectorRe.init router "/";
```
