function varTest() {
  var x = 1;
  {
    var x = 2;
    console.log(x); // 2
  }
  console.log(x); // 2
}

function letTest() {
  let x = 1;
  {
    let x = 2; // different variable
    console.log(x); // 2
  }
  console.log(x); // 1
}

varTest();
letTest();

// var is more like 전역변수, let is more like 지역변수
