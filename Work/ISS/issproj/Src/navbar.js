// var navbarhighlights = document.getElementById("navbar");
// navbarhighlights.addEventListener("mouseover", function(){
//     navbarhighlights.style.backgroundColor="plum";
// });

// var navbarhighlights = document.getElementById("navbar");
// navbarhighlights.addEventListener("mouseout", function(){
//     navbarhighlights.style.backgroundColor="black";
// });

// var navbarhighlight = document.getElementById("navbar1");
// navbarhighlight.addEventListener("mouseover", function(){
//     navbarhighlight.style.backgroundColor="plum";
// });

// var navbarhighlight = document.getElementById("navbar1");
// navbarhighlight.addEventListener("mouseout", function(){
//     navbarhighlight.style.backgroundColor="black";
// });

// var navbarhighligh = document.getElementById("navbar2");
// navbarhighligh.addEventListener("mouseover", function(){
//     navbarhighligh.style.backgroundColor="plum";
// });

// var navbarhighligh = document.getElementById("navbar2");
// navbarhighligh.addEventListener("mouseout", function(){
//     navbarhighligh.style.backgroundColor="black";
// });

// var navbarhigh = document.getElementById("navbar3");
// navbarhigh.addEventListener("mouseover", function(){
//     navbarhigh.style.backgroundColor="plum";
// });

// var navbarhigh = document.getElementById("navbar3");
// navbarhigh.addEventListener("mouseout", function(){
//     navbarhigh.style.backgroundColor="black";
// });

// var navi = document.getElementById("navbar4");
// navbarhigh.addEventListener("mouseover", function(){
//     navbarhigh.style.backgroundColor="plum";
// });

// var navi = document.getElementById("navbar4");
// navbarhigh.addEventListener("mouseout", function(){
//     navbarhigh.style.backgroundColor="black";
// });


var currentUrl = window.location.href;
var navLinks = document.getElementsByClassName('navbar')[0].getElementsByTagName('a');

for (var i = 0; i < navLinks.length; i++) {
    if (navLinks[i].href === currentUrl) {
        navLinks[i].style.backgroundColor = 'purple';
    }
}
for (var i = 0; i < navLinks.length; i++) {
    navLinks[i].addEventListener('mouseover', function () {
        this.style.backgroundColor = 'plum';
        this.style.color = 'black';

    });
    navLinks[i].addEventListener('mouseout', function () {
        this.style.backgroundColor = '';
        this.style.color = '';
        if (this.href === currentUrl) {
            this.style.backgroundColor = 'purple';
        }

    });

}



