(function (document) {
  console.log("function");
  let itemClassName = "carousel__photo";
  let items = document.getElementsByClassName(itemClassName);
  let totalItems = items.length;
  let slide = 0;
  let moving = true;

  // Set classes (start)
  function setInitialCalsses() {
    items[totalItems - 1].classList.add("prev");
    items[0].classList.add("active");
    items[1].classList.add("next");
  }

  // Set EventListeners
  function setEventListeners() {
    let prevButton = document.getElementsByClassName(
      "carousel__button--prev"
    )[0];
    let nextButton = document.getElementsByClassName(
      "carousel__button--next"
    )[0];
    prevButton.addEventListener("click", movePrev);
    nextButton.addEventListener("click", moveNext);
  }

  // When Prev Button Clicked
  function movePrev() {
    console.log("prev");
    if (!moving) {
      console.log("prev");
      if (slide === 0) {
        slide = totalItems - 1;
      } else {
        slide--;
      }
    }
    showItem(slide);
  }

  // When Next Button Clicked
  function moveNext() {
    console.log("next");
    if (!moving) {
      console.log("next");
      if (slide === totalItems - 1) {
        slide = 0;
      } else {
        slide++;
      }
    }
    showItem(slide);
  }

  function disableInteraction() {
    moving = true;
    setTimeout(function () {
      moving = false;
    }, 500);
  }

  function showItem(slide) {
    if (!moving) {
      disableInteraction();
      var newPrevious = slide - 1,
        newNext = slide + 1,
        oldPrevious = slide - 2,
        oldNext = slide + 2;

      if (totalItems - 1 > 3) {
        if (newPrevious <= 0) {
          oldPrevious = totalItems - 1;
        } else if (newNext >= totalItems - 1) {
          oldNext = 0;
        }

        if (slide === 0) {
          newPrevious = totalItems - 1;
          oldPrevious = totalItems - 2;
          oldNext = slide + 1;
        } else if (slide === totalItems - 1) {
          newPrevious = slide - 1;
          newNext = 0;
          oldNext = 1;
        }
      }

      console.log(items, oldPrevious);

      items[oldPrevious].className = itemClassName;
      items[oldNext].className = itemClassName;

      items[newPrevious].className = itemClassName + " prev";
      items[slide].className = itemClassName + " active";
      items[newNext].className = itemClassName + " next";
    }
  }

  function initCarousel() {
    moving = false;

    setInitialCalsses();
    setEventListeners();
  }

  initCarousel();
})(document);
