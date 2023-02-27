var Hapi = require("hapi");

const server = new Hapi.Server({
  port: 8000,
  host: "localhost",
});

let todolist = [
  {
    todo: "ginasio",
    time: "09h00",
  },
  {
    todo: "biologico",
    time: "10h00",
  },
];

server.route([
  {
    method: "GET",
    path: "/v1/todolist",
    handler: function (request, reply) {
      return todolist;
    },
  },
  {
    method: "POST",
    path: "/v1/todolist",
    handler: function (request, reply) {
      novoTodo = { todo: request.payload.todo, time: request.payload.time };
      todolist.push(novoTodo);
      return todolist;
    },
  },
  {
    method: "PUT",
    path: "/v1/todolist/{index}",
    handler: function (request, reply) {
      novoTodo = { todo: request.payload.todo, time: request.payload.time };
      todolist[request.params.index - 1] = novoTodo;
      return todolist;
    },
  },
  {
    method: "DELETE",
    path: "/v1/todolist/{index}",
    handler: function (request, reply) {
      delete todolist[request.params.index - 1];
      return todolist;
    },
  },
]);

const init = async () => {
  await server.start();
  console.log(`Server running at: ${server.info.uri}`);
};

process.on("unhandledRejection", (err) => {
  console.log(err);
  process.exit(1);
});

init();

//HTTPIE
//GET
//Remember que hapi reponse em json por defeito
//http http://localhost:8000/app/todolist

//http POST http://localhost:8000/app/todolist todo='comprar benuron' time='20h00'

//http  http://localhost:8000/app/todolist/1

//http PUT http://localhost:8000/app/todolist/1 todo='comprar benuron' time='22h00'

//http DELETE http://localhost:8000/app/todolist/1

// curl -d "todo=vbenuron&time=23h00" -H "Content-Type: application/x-www-form-urlencoded" -X POST http://localhost:8000/v1/todolist
