// JavaScript Document

(function ($) {
	$(function() {
			
    var nav = $('#nav-wrapper');
	var pixels = 49;
    $(window).scroll(function () {
		if ($('body').hasClass('front')) {
			pixels = 294;
		}
		if ($(this).scrollTop() > pixels) {
			nav.addClass("fixed");
		} else {
			nav.removeClass("fixed");
		}
    });
	
});

}(jQuery));
