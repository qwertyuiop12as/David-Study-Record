const todoInput = document.querySelector(".todo-input");
const todoButton = document.querySelector(".todo-button");
const todoList = document.querySelector(".todo-list");
const filterTodo = document.querySelector(".filter-todo");

document.addEventListener("DOMContentLoaded", printTodos);
todoButton.addEventListener("click", addTodo);
todoList.addEventListener("click", itemChange);
filterTodo.addEventListener("click", filterChange);

function addTodo(e) {
  e.preventDefault();

  // check if input value is empty or not
  if (todoInput.value === "") return;

  // create Div
  let newDiv = document.createElement("div");
  newDiv.classList.add("todo");

  // create li
  let newContent = document.createElement("li");
  newContent.classList.add("todo--para");
  newContent.innerText = todoInput.value;
  newDiv.appendChild(newContent);

  // create Check Button
  let newCheckButton = document.createElement("button");
  newCheckButton.classList.add("check-btn");
  newCheckButton.innerHTML = `<i class="fas fa-check"></i>`;
  newDiv.appendChild(newCheckButton);

  // create Delete Button
  let newDeleteButton = document.createElement("button");
  newDeleteButton.classList.add("trash-btn");
  newDeleteButton.innerHTML = `<i class="fas fa-trash"></i>`;
  newDiv.appendChild(newDeleteButton);

  // add NewDiv into Todo List
  todoList.appendChild(newDiv);

  // update Localstorage
  updateLocal(todoInput.value);

  // reset Input
  todoInput.value = "";
}

function updateLocal(todo) {
  let todoItems = [];

  if (localStorage.getItem("todoItems") === null) {
    todoItems = [];
  } else {
    todoItems = JSON.parse(localStorage.getItem("todoItems"));
  }

  todoItems.push(todo);
  localStorage.setItem("todoItems", JSON.stringify(todoItems));
}

function itemChange(e) {
  clickedItem = e.target;

  if (clickedItem.classList[0] === "check-btn") {
    clickedItem.parentElement.classList.toggle("check");
  } else if (clickedItem.classList[0] === "trash-btn") {
    let item = clickedItem.parentElement;

    item.classList.add("trash");
    item.addEventListener("transitionend", (e) => {
      item.remove();
    });

    deleteLocal(item);
  }
}

function deleteLocal(item) {
  let todoItems = [];
  let todoText = item.children[0].innerText;

  if (localStorage.getItem("todoItems") === null) {
    todoItems = [];
  } else {
    todoItems = JSON.parse(localStorage.getItem("todoItems"));
  }

  todoItems.splice(todoItems.indexOf(todoText), 1);
  localStorage.setItem("todoItems", JSON.stringify(todoItems));
}

function printTodos(e) {
  e.preventDefault();

  todoItems = [];

  if (localStorage.getItem("todoItems") === null) {
    todoItems = [];
  } else {
    todoItems = JSON.parse(localStorage.getItem("todoItems"));
  }

  todoItems.forEach((todoItem) => {
    // create Div
    let newDiv = document.createElement("div");
    newDiv.classList.add("todo");

    // create li
    let newContent = document.createElement("li");
    newContent.classList.add("todo--para");
    newContent.innerText = todoItem;
    newDiv.appendChild(newContent);

    // create Check Button
    let newCheckButton = document.createElement("button");
    newCheckButton.classList.add("check-btn");
    newCheckButton.innerHTML = `<i class="fas fa-check"></i>`;
    newDiv.appendChild(newCheckButton);

    // create Delete Button
    let newDeleteButton = document.createElement("button");
    newDeleteButton.classList.add("trash-btn");
    newDeleteButton.innerHTML = `<i class="fas fa-trash"></i>`;
    newDiv.appendChild(newDeleteButton);

    // add NewDiv into Todo List
    todoList.appendChild(newDiv);
  });
}

// function filterChange(e) {
//   e.preventDefault();

//   let todos = todoList.children;
//   let filterValue = e.target.value;

//   console.log("todos", todos);

//   for (let i = 0; i < todos.length; i++) {
//     switch (filterValue) {
//       case "all":
//         todos[i].style.display = "flex";
//         break;
//       case "completed":
//         if (todos[i].classList.contains("check")) {
//           todos[i].style.display = "flex";
//         } else {
//           todos[i].style.display = "none";
//         }
//         break;
//       case "uncompleted":
//         if (!todos[i].classList.contains("check")) {
//           todos[i].style.display = "flex";
//         } else {
//           todos[i].style.display = "none";
//         }
//         break;
//     }
//   }
// todos.forEach((todo) => {
//   switch (filterValue) {
//     case "all":
//       todo.style.display = "flex";
//       break;
//     case "completed":
//       if (todo.classList.contains("completed")) {
//         todo.style.display = "flex";
//       } else {
//         todo.style.display = "none";
//       }
//       break;
//     case "uncompleted":
//       if (!todo.classList.contains("completed")) {
//         todo.style.display = "flex";
//       } else {
//         todo.style.display = "none";
//       }
//       break;
//   }
// });
//}

function filterChange(e) {
  e.preventDefault();

  let todos = todoList.childNodes;
  let filterValue = e.target.value;

  console.log("todos", todos[0]);

  todos.forEach((todo) => {
    switch (filterValue) {
      case "all":
        todo.style.display = "flex";
        break;
      case "completed":
        if (todo.classList.contains("check")) {
          todo.style.display = "flex";
        } else {
          todo.style.display = "none";
        }
        break;
      case "uncompleted":
        if (!todo.classList.contains("check")) {
          todo.style.display = "flex";
        } else {
          todo.style.display = "none";
        }
        break;
    }
  });
}
