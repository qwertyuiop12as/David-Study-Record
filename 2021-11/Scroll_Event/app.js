window.addEventListener("scroll", reveal);

function reveal() {
    console.log("Hello World");

    let reveals = document.querySelectorAll(".reveal");
    
    for (let i = 0; i < reveals.length; i++) {
        // 100vh = window.innerheight
        let windowheight = window.innerHeight;
        let revealtop = reveals[i].getBoundingClientRect().top;
        // let revealbottom = reveals[i].getBoundingClientRect().bottom;
        let revealPoint = 200;

        if (i == 0) {
            console.log("top : ", Math.round(revealtop));
            console.log("bottom : ", Math.round(revealbottom));
        }
        // 630 - 150 = 480
        if(revealtop < windowheight - revealPoint) {
            reveals[i].classList.add("active");
        } else {
            reveals[i].classList.remove("active");
        }
    }
}